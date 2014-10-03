<?php
/**
 * @file
 * ankom_product_import.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function ankom_product_import_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'product_import';
  $feeds_importer->config = array(
    'name' => 'Ankom Product Import',
    'description' => 'Turns CSV rows into Commerce Products at ankom.com',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsCommerceProductProcessor',
      'config' => array(
        'product_type' => 'product',
        'author' => '1',
        'tax_rate' => TRUE,
        'mappings' => array(
          0 => array(
            'source' => 'GUID',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'SKU',
            'target' => 'sku',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Name',
            'target' => 'title',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Status',
            'target' => 'status',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Currency',
            'target' => 'commerce_price:currency_code',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'Price',
            'target' => 'commerce_price:amount',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'product',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '1800',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['product_import'] = $feeds_importer;

  return $export;
}
