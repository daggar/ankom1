<?php
/**
 * @file
 * ankom_product_import.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ankom_product_import_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
}
