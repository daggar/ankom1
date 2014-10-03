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
$processed_content = isolate_menu_links($content);
$menu_links = "<ul class=\"menu\">\n";
foreach($processed_content as $link) {
		$anchor_link_url = '/' . drupal_get_path_alias($link['#href']);
		$anchor_link_title = $link['#title'];
		$image_uri = file_load($link['#localized_options']['content']['image'])->uri;
		$anchor_link_image = image_style_url('secondary_menu_icon', $image_uri); //file_create_url($image_uri);
		$anchor_link_classes = implode(' ', $link['#attributes']['class']);
		$menu_links .= '<li class="bwc-secondary-menu-item ' . $anchor_link_classes . '"><a class="bwc-secondary-menu-link" href="' . $anchor_link_url . '">'
			. '<div class="bwc-secondary-menu-text">' . $anchor_link_title . '</div>' 
			. '<img class="bwc-secondary-menu-image" src="' . $anchor_link_image  . '" />'
			. "</a></li>\n";
}
$menu_links .= "\n</ul>\n";
?><div class="<?php print $classes; ?> . bwc-secondary-menu-outerwrap"><div class="bwc-secondary-menu-innerwrap">
<?php print ($menu_links); ?>
</div></div>