<?php
// $Id: template.php,v 1.10 2011/01/14 02:57:57 jmburnz Exp $

/**
 * Preprocess and Process Functions SEE: http://drupal.org/node/254940#variables-processor
 * 1. Rename each function to match your subthemes name,
 *    e.g. if you name your theme "themeName" then the function
 *    name will be "themeName_preprocess_hook". Tip - you can
 *    search/replace on "genesis_SUBTHEME".
 * 2. Uncomment the required function to use.

 */

/**
 * Override or insert variables into all templates.
 */

/*
function genesis_cgr_preprocess(&$vars, $hook) {
}
*/

/*
function genesis_SUBTHEME_process(&$vars, $hook) {
}
// */

/*
 * Add unique ID's to menu items.  Problem: ID's seem to change a lot.
 *
function genesis_cgr_menu_link($variables) {
  $element = $variables['element'];
  $sub_menu = '';

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }
  static $item_id = 0;
  $output = l($element['#title'], $element['#href'], $element['#localized_options']); 
  return '<li id="custom-menu-item-id-' . (++$item_id) . '"' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

	echo '<pre>';
	print_r($element);
	echo '</pre>';

*/

function bwc_custom_preprocess_menu_tree(&$variables) {
	
	$classes_start = stripos($variables['tree'], 'class="') + 7;
  $classes_end = stripos($variables['tree'], '"', $classes_start);
  $classes_length = $classes_end - $classes_start;
  $first_child_classes = substr($variables['tree'], $classes_start, $classes_length);
  $variables['first_child_classes'] = $first_child_classes;
}

function bwc_custom_menu_link(array $variables) {
  $element = $variables['element'];
  //Remove the HTML title attribute
	$element['#localized_options']['attributes']['title'] = ' ';
  $sub_menu = '';
  
  //add depth count to each menu link. 
  $element['#attributes']['class'][] = 'depth-' . $element['#original_link']['depth'];

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }

	/* add semi-unique class names to each menu item, 
	derived from the menu link title. */  
 	$new_class = $element['#title'];
	$new_class = strtolower( preg_replace("/[^0-9a-zA-Z-]/", '-', strip_tags($new_class) ) );
	$class_count = count($element['#attributes']['class']) + 1;
	$element['#attributes']['class'][$class_count] = $new_class;
 
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

function bwc_custom_menu_tree($variables) {
  return '<ul class="menu ' .  $variables['first_child_classes'] . '">' . $variables['tree'] . '</ul>';
}


//*/
/**
 * Override or insert variables into the html templates.
 */

/* 
function genesis_SUBTHEME_process_html(&$vars) {
}
// */

/**
 * Override or insert variables into the page templates.
 */

function bwc_custom_preprocess_page(&$variables) {
// Compile a list of classes that are going to be applied to the body element.
  // This allows advanced theming based on context (home page, node of certain type, etc.).
  // Add a class that tells us whether we're on the front page or not.
  $variables['classes_array'][] = $variables['is_front'] ? 'front' : 'not-front';
  // Add a class that tells us whether the page is viewed by an authenticated user or not.
  $variables['classes_array'][] = $variables['logged_in'] ? 'logged-in' : 'not-logged-in';

  // Add information about the number of sidebars.
  if (!empty($variables['page']['sidebar_first']) && !empty($variables['page']['sidebar_second'])) {
    $variables['classes_array'][] = 'two-sidebars';
  }
  elseif (!empty($variables['page']['sidebar_first'])) {
    $variables['classes_array'][] = 'one-sidebar sidebar-first';
  }
  elseif (!empty($variables['page']['sidebar_second'])) {
    $variables['classes_array'][] = 'one-sidebar sidebar-second';
  }
  else {
    $variables['classes_array'][] = 'no-sidebars';
  }

  if (!$variables['is_front']) {
    // Add unique class for each page.
    $path = drupal_get_path_alias($_GET['q']);
    // Add unique class for each website section.
    list($section, ) = explode('/', $path, 2);
    if (arg(0) == 'node') {
      if (arg(1) == 'add') {
        $section = 'page-node-add';
      }
      elseif (is_numeric(arg(1)) && (arg(2) == 'edit' || arg(2) == 'delete')) {
        $section = 'page-node-' . arg(2);
      }
    }
    $vars['classes_array'][] = drupal_html_class('section-' . $section);
	}

  // Populate the body classes.
  if ($suggestions = theme_get_suggestions(arg(), 'page', '-')) {
    foreach ($suggestions as $suggestion) {
      if ($suggestion != 'page-front') {
        // Add current suggestion to page classes to make it possible to theme
        // the page depending on the current page type (e.g. node, admin, user,
        // etc.) as well as more specific data like node-12 or node-edit.
        $variables['classes_array'][] = drupal_html_class($suggestion);
      }
    }
  }
  
  //Css classes by path alias
  $page_path_classes = request_uri();
  $page_path_classes = ' ' . str_replace('/', ' path-css-', $page_path_classes);
  $variables['classes_array'][] = $page_path_classes;

  if (isset($variables['node']->type)) {
    // If the content type's machine name is "my_machine_name" the file
    // name will be "page--my-machine-name.tpl.php".
    $variables['theme_hook_suggestions'][] = 'page__' . $variables['node']->type;
  }

  
}

/* 
takes a menu array and returns only the elements on the 
top menu, without metadata entries. 
*/
function isolate_menu_links($unsorted_array) {
	$menu_links = array();
	foreach ($unsorted_array as $menu_array_entry) {
		if (isset($menu_array_entry['#href'])) {
			array_push($menu_links, $menu_array_entry);
		}
	}
	return $menu_links;
}

