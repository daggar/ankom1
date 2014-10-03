<?php
/**
 * @file
 * ankom_stuff_migrate.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ankom_stuff_migrate_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "quicktabs" && $api == "quicktabs") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ankom_stuff_migrate_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function ankom_stuff_migrate_node_info() {
  $items = array(
    'downloadable_document' => array(
      'name' => t('Downloadable Document'),
      'base' => 'node_content',
      'description' => t('A single PDF with tagging options to specify where it will be listed on the site.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'frequently_asked_question' => array(
      'name' => t('Frequently Asked Question'),
      'base' => 'node_content',
      'description' => t('A single Frequently Asked Question'),
      'has_title' => '1',
      'title_label' => t('Question'),
      'help' => '',
    ),
    'technical_support_individual_tab' => array(
      'name' => t('Technical Support Individual Tab'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'technical_support_product_page' => array(
      'name' => t('Technical Support Product Page'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
