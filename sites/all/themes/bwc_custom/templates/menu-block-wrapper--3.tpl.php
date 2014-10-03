<?php
/**
 * @file
 * Default theme implementation to wrap menu blocks.
 *
 * Available variables:
 * - $content: The renderable array containing the menu.
 * - $classes: A string containing the CSS classes for the DIV tag. Includes:
 *   menu-block-DELTA, menu-name-NAME, parent-mlid-MLID, and menu-level-LEVEL.
 * - $classes_array: An array containing each of the CSS classes.
 *
 * The following variables are provided for contextual information.
 * - $delta: (string) The menu_block's block delta.
 * - $config: An array of the block's configuration settings. Includes
 *   menu_name, parent_mlid, title_link, admin_title, level, follow, depth,
 *   expanded, and sort.
 *
 * @see template_preprocess_menu_block_wrapper()
 */

//Copy $content so the original is available later.
$processed_content = $content;

//Set the supermenus.  Use the MLID of the parent item.
$supermenu_ids = array(1502, 1504, 1505);

/*
	<li class="depth-1 bwc-supermenu supermenu-parent product-catalog inactive-menu"><a href="/placeholder" class="bwc-supermenu anchor-link">Product Catalog</a>
		<div class="bwc-supermenu box-wrap product-catalog">
			<div class="bwc-suppermenu box-wrap-inner product-catalog">
				<h1 class="bwc-supermenu title product-catalog">Our Product Catalog<div class="bwc-supermenu-close-icon"></div></h1>
				<ul class="menu bwc-supermenu product-catalog depth-2">
*/

function convert_expanded_menu(&$processed_content, $supermenu_ids) {
	$menu_complete = '';
	foreach($processed_content as $mlid=>$menuitem) {
		if(in_array($mlid, $supermenu_ids)) {
			if (isset($menuitem['#localized_options']['attributes']['title'])) {
				$section_title = $menuitem['#localized_options']['attributes']['title'];
			} else $section_title = '';
			$anchor_link_url = '/' . drupal_get_path_alias($menuitem['#href']);
			$anchor_link_title = $menuitem['#title'];
			$css_classes = 'bwc-expanded-mlid-' . $mlid;
			$menu_complete .= '<li class="depth-1 bwc-supermenu supermenu-parent inactive-menu ' . $css_classes .'"><a href="' . $anchor_link_url . '" class="bwc-supermenu anchor-link">' . $anchor_link_title . '</a>'
			 	. '<div class="bwc-supermenu box-wrap ' . $css_classes .'"><div class="bwc-suppermenu box-wrap-inner ' . $css_classes .'">'
			 	. '<h1 class="bwc-supermenu title ' . $css_classes .'">' . $section_title . '<div class="bwc-supermenu-close-icon"></div></h1>'
				. '<ul class="menu bwc-supermenu depth-2 ' . $css_classes . '">' . "\n";
			$menu_complete .= process_menu($menuitem['#below'], $css_classes) . "\n";
			$menu_complete .= '</ul></div></div></li>' . "\n";
		} //if(stripos($section_title, 'expanded menu'))
	}//foreach($processed_content as $menuitem)
	return $menu_complete;
} //function convert_expanded_menu($processed_content) 

function process_menu($menu_array, $css_classes) {
	$theme_path = path_to_theme(); 
	$processed_links = isolate_menu_links($menu_array);
	$item_count = count($processed_links);
	$break_point = ceil($item_count / 2);
	$menu_block = '';
	if(count($processed_links) < 1) return '';
	$row_count = 1;
	foreach($processed_links as $mlid=>$menuitem) {
		$anchor_link_url = '/' . drupal_get_path_alias($menuitem['#href']);
		$anchor_link_title = $menuitem['#title'];
		if (isset($menuitem['#localized_options']['content']['image'])) {
			$image_uri = file_load($menuitem['#localized_options']['content']['image'])->uri;
		} else {
			$image_uri = $theme_path . '/images/blank.png';
		}
		$anchor_link_image = file_create_url($image_uri);
		$secondary_links = process_sublinks($menuitem['#below']);
		$menu_block .= bwc_menu_item($anchor_link_title, $anchor_link_url, $anchor_link_image, $css_classes, $secondary_links);		
		if($row_count >= $break_point) {
			 $menu_block .= '<br />';
			 $row_count = 1;
		} else { //if($row_count > $break_point)
			$row_count++;
		} //else //if($row_count > $break_point)
	} //foreach($menu_array as $mlid=>$menuitem)
	return $menu_block;
}

function process_sublinks($sublinks) {
	$processed_links = isolate_menu_links($sublinks);
	if(count($processed_links) < 1) return '';
	$secondary_links = array();
	foreach($processed_links as $mlid=>$menuitem) {
		$newlink = array( 'text'=> $menuitem['#title'] , 'url' => '/' . drupal_get_path_alias($menuitem['#href']) );
		array_push($secondary_links, $newlink);
	}
	return $secondary_links;
}

/*
function bwc_menu_item($section_title, $main_link, $main_image, $secondary_links = '', $css_classes = '')
$section title = String.  Plain text.  No HTML except character entities.

$main_link = String. URL.  
	$section_title = "Dietary Fiber"

$main_image = String. URL to an image.  
	$main_image = "/images/menu/item.jpg"

$secondary_links = array of arrays.  Each subarray consists of text 
and a url
	$secondary_links = array( 
		array(text => 'XT 15', url => '/products/xt-15' ),
		array(text => 'XT 10', url => '/products/xt-10' )
	)

$css_classes = string. Additional CSS classes, will be added to the 
top-level wrap.
	$css_clases = 'first highlighted large-text'
*/
function bwc_menu_item($section_title, $main_link, $main_image, $css_classes = '', $secondary_links = '') {
	
	$title_link = '<a class="bwc-supermenu title-link ' . $css_classes .'" href="' .  $main_link
			. '"><div class="bwc-supermenu title-text-wrap">'
			.	$section_title . '</div></a>';
	$image_link = '<a class="bwc_supermenu image-link ' . $css_classes .'" href="' . $main_link
			. '"><img class="bwc-supermenu menu-image" src="' . $main_image
			. '" /></a>';
			
	//Add secondary links if they're present; otherwise add placeholder.
	if ($secondary_links != '' && count($secondary_links) > 1) {
		$bottom_fill = '';
		$separator = '';
		foreach($secondary_links as $link) {
			$bottom_fill .= $separator . '<li class="bwc-supermenu secondary-link depth-3"><a href="' . $link['url'] 
				. '">' . $link['text'] . '</a></li>';
			$separator = ' | ';
		} //foreach($secondary_links as $link)
		$bottom_fill = '<div class="bwc-supermenu box-bottom ' . $css_classes .'"><ul class="menu bwc-supermenu depth-3">' . $bottom_fill . '</ul></div>';
	} else { //if ($secondary_links != '')
		$bottom_fill = '<div class="bwc-supermenu box-bottom"></div>';
	} //} else { //if ($secondary_links != '')
	$menu_item = '<li class="menu-item bwc-supermenu-item menu-box depth-2 ' . $css_classes . '">' . $title_link . $image_link . $bottom_fill . '</li>';
	return $menu_item;
	//*/
} //function bwc_menu_item($section_title, $main_link, $main_image, $css_classes = '', $secondary_links = '')

// pull the existing menu apart to add the existing menus.
$expanded_menus = convert_expanded_menu($processed_content, $supermenu_ids); 
foreach ($supermenu_ids as $removeindex) {
	unset($processed_content[$removeindex]);
}
$menu_raw = render($processed_content);
$first_tag = stripos($menu_raw, '>') + 1; 
//$list_start = substr($menu_raw, 0, $first_tag);
$list_start = '<ul class="menu first depth-0 bwc-supermenu-outerwrap menu-mlid-handmade-01">';
$list_end = substr($menu_raw, $first_tag);
$imagepath = '/sites/all/themes/bwc_custom/images/supermenu-pictures/';
?> 


<div class="<?php print $classes; ?>">
	<!-- BLARG: <?php print_r($list_start); ?> -->
	<?php print $list_start; ?>
	<?php print $expanded_menus; ?>
	<?php print $list_end; ?>
</div>