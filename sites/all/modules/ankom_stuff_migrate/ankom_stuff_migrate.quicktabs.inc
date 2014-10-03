<?php
/**
 * @file
 * ankom_stuff_migrate.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function ankom_stuff_migrate_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'faq_subtypes';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = TRUE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Tech Support - FAQ Subtypes';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'product_faq',
      'display' => 'block_1',
      'args' => '13/%1',
      'title' => 'Instrument Troubleshooting',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'product_faq',
      'display' => 'block_1',
      'args' => '14/%1',
      'title' => 'Analytical/Results Troubleshooting',
      'weight' => '-99',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'quicktabs';
  $quicktabs->style = 'Sky';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Analytical/Results Troubleshooting');
  t('Instrument Troubleshooting');
  t('Tech Support - FAQ Subtypes');

  $export['faq_subtypes'] = $quicktabs;

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'tech_support_service_procedures';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = TRUE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Tech Support - Service Procedures';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'product_faq',
      'display' => 'block_2',
      'args' => '16/%1',
      'title' => 'Documents',
      'weight' => '-100',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'quicktabs';
  $quicktabs->style = 'Sky';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Documents');
  t('Tech Support - Service Procedures');

  $export['tech_support_service_procedures'] = $quicktabs;

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'tech_support_tab_group';
  $quicktabs->ajax = 1;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Tech Support Tab Group';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'tech_support_tabs',
      'display' => 'block',
      'args' => '%1',
      'title' => 'Technical FAQ\'s',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'tech_support_tabs',
      'display' => 'block_3',
      'args' => '%1',
      'title' => 'Service Procedures',
      'weight' => '-99',
      'type' => 'view',
    ),
    2 => array(
      'vid' => 'tech_support_tabs',
      'display' => 'block_2',
      'args' => '%1',
      'title' => 'Operator\'s Manual',
      'weight' => '-98',
      'type' => 'view',
    ),
    3 => array(
      'vid' => 'tech_support_tabs',
      'display' => 'block_4',
      'args' => '%1',
      'title' => 'Video Library',
      'weight' => '-97',
      'type' => 'view',
    ),
    4 => array(
      'vid' => 'tech_support_tabs',
      'display' => 'block_1',
      'args' => '%1',
      'title' => 'Filter Bags',
      'weight' => '-96',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'quicktabs';
  $quicktabs->style = 'Zen';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Filter Bags');
  t('Operator\'s Manual');
  t('Service Procedures');
  t('Tech Support Tab Group');
  t('Technical FAQ\'s');
  t('Video Library');

  $export['tech_support_tab_group'] = $quicktabs;

  return $export;
}
