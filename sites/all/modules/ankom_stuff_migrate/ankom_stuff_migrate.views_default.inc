<?php
/**
 * @file
 * ankom_stuff_migrate.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ankom_stuff_migrate_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'product_faq';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Technical Support Subtabs';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Product faq';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'faq-expansion-row';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: term from field_product_tag */
  $handler->display->display_options['relationships']['field_product_tag_tid']['id'] = 'field_product_tag_tid';
  $handler->display->display_options['relationships']['field_product_tag_tid']['table'] = 'field_data_field_product_tag';
  $handler->display->display_options['relationships']['field_product_tag_tid']['field'] = 'field_product_tag_tid';
  $handler->display->display_options['relationships']['field_product_tag_tid']['ui_name'] = 'term from field_product_tag';
  /* Relationship: field_product_tag */
  $handler->display->display_options['relationships']['reverse_field_product_tag_node']['id'] = 'reverse_field_product_tag_node';
  $handler->display->display_options['relationships']['reverse_field_product_tag_node']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['reverse_field_product_tag_node']['field'] = 'reverse_field_product_tag_node';
  $handler->display->display_options['relationships']['reverse_field_product_tag_node']['relationship'] = 'field_product_tag_tid';
  $handler->display->display_options['relationships']['reverse_field_product_tag_node']['ui_name'] = 'field_product_tag';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = '[Edit this Question]';
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['exclude'] = TRUE;
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[counter]. [title] <span class="bwc-edit-link">[edit_node]</span>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'faq-list-question';
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_wrapper_class'] = 'faq-list-answer';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'reverse_field_product_tag_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'frequently_asked_question' => 'frequently_asked_question',
  );

  /* Display: FAQ's */
  $handler = $view->new_display('block', 'FAQ\'s', 'block');

  /* Display: faq-subtypes */
  $handler = $view->new_display('block', 'faq-subtypes', 'block_1');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Question Subtype (field_question_subtype) */
  $handler->display->display_options['arguments']['field_question_subtype_tid']['id'] = 'field_question_subtype_tid';
  $handler->display->display_options['arguments']['field_question_subtype_tid']['table'] = 'field_data_field_question_subtype';
  $handler->display->display_options['arguments']['field_question_subtype_tid']['field'] = 'field_question_subtype_tid';
  $handler->display->display_options['arguments']['field_question_subtype_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_question_subtype_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_question_subtype_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_question_subtype_tid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'reverse_field_product_tag_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';

  /* Display: Service Procedures */
  $handler = $view->new_display('block', 'Service Procedures', 'block_2');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'edit_node' => 'title',
    'field_document_file' => 'field_document_file',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => ' ',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_document_file' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title] <span class="bwc-edit-link">[edit_node]</span>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'faq-list-question';
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = '[Edit this Document]';
  /* Field: Content: Document File */
  $handler->display->display_options['fields']['field_document_file']['id'] = 'field_document_file';
  $handler->display->display_options['fields']['field_document_file']['table'] = 'field_data_field_document_file';
  $handler->display->display_options['fields']['field_document_file']['field'] = 'field_document_file';
  $handler->display->display_options['fields']['field_document_file']['label'] = '';
  $handler->display->display_options['fields']['field_document_file']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_document_file']['alter']['text'] = '<a href="[field_document_file]" class="bwc-pdf-link">View PDF</a>';
  $handler->display->display_options['fields']['field_document_file']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_document_file']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_document_file']['type'] = 'file_url_plain';
  $handler->display->display_options['fields']['field_document_file']['settings'] = array(
    'field_formatter_class' => '',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'downloadable_document' => 'downloadable_document',
  );
  /* Filter criterion: Content: Document Type (field_site_section) */
  $handler->display->display_options['filters']['field_site_section_tid']['id'] = 'field_site_section_tid';
  $handler->display->display_options['filters']['field_site_section_tid']['table'] = 'field_data_field_site_section';
  $handler->display->display_options['filters']['field_site_section_tid']['field'] = 'field_site_section_tid';
  $handler->display->display_options['filters']['field_site_section_tid']['value'] = array(
    16 => '16',
  );
  $handler->display->display_options['filters']['field_site_section_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_site_section_tid']['vocabulary'] = 'technical_support_categories';
  $handler->display->display_options['filters']['field_site_section_tid']['hierarchy'] = 1;
  $export['product_faq'] = $view;

  $view = new view();
  $view->name = 'stacked_content';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Stacked Content';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'move-contextuals';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Content: Rendered Content */
  $handler->display->display_options['fields']['rendered_entity']['id'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['rendered_entity']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['label'] = '';
  $handler->display->display_options['fields']['rendered_entity']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['display'] = 'view';
  $handler->display->display_options['fields']['rendered_entity']['view_mode'] = 'full';
  $handler->display->display_options['fields']['rendered_entity']['bypass_access'] = 0;
  /* Field: Content: Weight (order) */
  $handler->display->display_options['fields']['field_weight_order_']['id'] = 'field_weight_order_';
  $handler->display->display_options['fields']['field_weight_order_']['table'] = 'field_data_field_weight_order_';
  $handler->display->display_options['fields']['field_weight_order_']['field'] = 'field_weight_order_';
  $handler->display->display_options['fields']['field_weight_order_']['label'] = '';
  $handler->display->display_options['fields']['field_weight_order_']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_weight_order_']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_weight_order_']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
    'field_formatter_class' => '',
  );
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '(Weight: [field_weight_order_]) [edit_node]';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit this Section';
  /* Field: Global: Contextual Links */
  $handler->display->display_options['fields']['contextual_links']['id'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['table'] = 'views';
  $handler->display->display_options['fields']['contextual_links']['field'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['label'] = '';
  $handler->display->display_options['fields']['contextual_links']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['contextual_links']['fields'] = array(
    'field_weight_order_' => 'field_weight_order_',
    'edit_node' => 'edit_node',
    'rendered_entity' => 0,
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Show on this page (field_target_page) */
  $handler->display->display_options['arguments']['field_target_page_target_id']['id'] = 'field_target_page_target_id';
  $handler->display->display_options['arguments']['field_target_page_target_id']['table'] = 'field_data_field_target_page';
  $handler->display->display_options['arguments']['field_target_page_target_id']['field'] = 'field_target_page_target_id';
  $handler->display->display_options['arguments']['field_target_page_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_target_page_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_target_page_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_target_page_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_target_page_target_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'two_column_page_section' => 'two_column_page_section',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['stacked_content'] = $view;

  $view = new view();
  $view->name = 'tech_support_tabs';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Tech Support Tabs';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: term from field_product_tag */
  $handler->display->display_options['relationships']['field_product_tag_tid']['id'] = 'field_product_tag_tid';
  $handler->display->display_options['relationships']['field_product_tag_tid']['table'] = 'field_data_field_product_tag';
  $handler->display->display_options['relationships']['field_product_tag_tid']['field'] = 'field_product_tag_tid';
  $handler->display->display_options['relationships']['field_product_tag_tid']['ui_name'] = 'term from field_product_tag';
  /* Relationship: field_product_tag */
  $handler->display->display_options['relationships']['reverse_field_product_tag_node']['id'] = 'reverse_field_product_tag_node';
  $handler->display->display_options['relationships']['reverse_field_product_tag_node']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['reverse_field_product_tag_node']['field'] = 'reverse_field_product_tag_node';
  $handler->display->display_options['relationships']['reverse_field_product_tag_node']['relationship'] = 'field_product_tag_tid';
  $handler->display->display_options['relationships']['reverse_field_product_tag_node']['ui_name'] = 'field_product_tag';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_class'] = 'bwc-edit-link';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = '[Edit this tab]';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Advanced Content */
  $handler->display->display_options['fields']['field_advanced_content']['id'] = 'field_advanced_content';
  $handler->display->display_options['fields']['field_advanced_content']['table'] = 'field_data_field_advanced_content';
  $handler->display->display_options['fields']['field_advanced_content']['field'] = 'field_advanced_content';
  $handler->display->display_options['fields']['field_advanced_content']['label'] = '';
  $handler->display->display_options['fields']['field_advanced_content']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_advanced_content']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'reverse_field_product_tag_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'technical_support_individual_tab' => 'technical_support_individual_tab',
  );
  /* Filter criterion: Content: Document Type (field_site_section) */
  $handler->display->display_options['filters']['field_site_section_tid']['id'] = 'field_site_section_tid';
  $handler->display->display_options['filters']['field_site_section_tid']['table'] = 'field_data_field_site_section';
  $handler->display->display_options['filters']['field_site_section_tid']['field'] = 'field_site_section_tid';
  $handler->display->display_options['filters']['field_site_section_tid']['value'] = array(
    15 => '15',
  );
  $handler->display->display_options['filters']['field_site_section_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_site_section_tid']['vocabulary'] = 'technical_support_categories';

  /* Display: FAQ */
  $handler = $view->new_display('block', 'FAQ', 'block');

  /* Display: Filter Bags */
  $handler = $view->new_display('block', 'Filter Bags', 'block_1');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'technical_support_individual_tab' => 'technical_support_individual_tab',
  );
  /* Filter criterion: Content: Document Type (field_site_section) */
  $handler->display->display_options['filters']['field_site_section_tid']['id'] = 'field_site_section_tid';
  $handler->display->display_options['filters']['field_site_section_tid']['table'] = 'field_data_field_site_section';
  $handler->display->display_options['filters']['field_site_section_tid']['field'] = 'field_site_section_tid';
  $handler->display->display_options['filters']['field_site_section_tid']['value'] = array(
    20 => '20',
  );
  $handler->display->display_options['filters']['field_site_section_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_site_section_tid']['vocabulary'] = 'technical_support_categories';

  /* Display: Operators Manual */
  $handler = $view->new_display('block', 'Operators Manual', 'block_2');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'technical_support_individual_tab' => 'technical_support_individual_tab',
  );
  /* Filter criterion: Content: Document Type (field_site_section) */
  $handler->display->display_options['filters']['field_site_section_tid']['id'] = 'field_site_section_tid';
  $handler->display->display_options['filters']['field_site_section_tid']['table'] = 'field_data_field_site_section';
  $handler->display->display_options['filters']['field_site_section_tid']['field'] = 'field_site_section_tid';
  $handler->display->display_options['filters']['field_site_section_tid']['value'] = array(
    17 => '17',
  );
  $handler->display->display_options['filters']['field_site_section_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_site_section_tid']['vocabulary'] = 'technical_support_categories';

  /* Display: Service Procedures */
  $handler = $view->new_display('block', 'Service Procedures', 'block_3');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'technical_support_individual_tab' => 'technical_support_individual_tab',
  );
  /* Filter criterion: Content: Document Type (field_site_section) */
  $handler->display->display_options['filters']['field_site_section_tid']['id'] = 'field_site_section_tid';
  $handler->display->display_options['filters']['field_site_section_tid']['table'] = 'field_data_field_site_section';
  $handler->display->display_options['filters']['field_site_section_tid']['field'] = 'field_site_section_tid';
  $handler->display->display_options['filters']['field_site_section_tid']['value'] = array(
    16 => '16',
  );
  $handler->display->display_options['filters']['field_site_section_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_site_section_tid']['vocabulary'] = 'technical_support_categories';

  /* Display: Video Library */
  $handler = $view->new_display('block', 'Video Library', 'block_4');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'technical_support_individual_tab' => 'technical_support_individual_tab',
  );
  /* Filter criterion: Content: Document Type (field_site_section) */
  $handler->display->display_options['filters']['field_site_section_tid']['id'] = 'field_site_section_tid';
  $handler->display->display_options['filters']['field_site_section_tid']['table'] = 'field_data_field_site_section';
  $handler->display->display_options['filters']['field_site_section_tid']['field'] = 'field_site_section_tid';
  $handler->display->display_options['filters']['field_site_section_tid']['value'] = array(
    18 => '18',
  );
  $handler->display->display_options['filters']['field_site_section_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_site_section_tid']['vocabulary'] = 'technical_support_categories';
  $export['tech_support_tabs'] = $view;

  return $export;
}
