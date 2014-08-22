<?php
/**
 * @file
 * fq_private_upload.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function fq_private_upload_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'private_uploads';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Private uploads';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Secure Client Access';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_pu_category',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<h2>Hello, [field_name]</h2>
<p>Your documents are listed below. Please contact help@firstquadrant.com or 626-000-0000 for additional support or answered questions.</p>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  /* Relationship: Content: Category (field_pu_category) */
  $handler->display->display_options['relationships']['field_pu_category_tid']['id'] = 'field_pu_category_tid';
  $handler->display->display_options['relationships']['field_pu_category_tid']['table'] = 'field_data_field_pu_category';
  $handler->display->display_options['relationships']['field_pu_category_tid']['field'] = 'field_pu_category_tid';
  /* Field: Content: Category */
  $handler->display->display_options['fields']['field_pu_category']['id'] = 'field_pu_category';
  $handler->display->display_options['fields']['field_pu_category']['table'] = 'field_data_field_pu_category';
  $handler->display->display_options['fields']['field_pu_category']['field'] = 'field_pu_category';
  $handler->display->display_options['fields']['field_pu_category']['label'] = '';
  $handler->display->display_options['fields']['field_pu_category']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_pu_category']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pu_category']['empty'] = 'Uncategorized';
  $handler->display->display_options['fields']['field_pu_category']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: File date */
  $handler->display->display_options['fields']['field_file_date']['id'] = 'field_file_date';
  $handler->display->display_options['fields']['field_file_date']['table'] = 'field_data_field_file_date';
  $handler->display->display_options['fields']['field_file_date']['field'] = 'field_file_date';
  $handler->display->display_options['fields']['field_file_date']['label'] = '';
  $handler->display->display_options['fields']['field_file_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_file_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Group access */
  $handler->display->display_options['fields']['field_group_access']['id'] = 'field_group_access';
  $handler->display->display_options['fields']['field_group_access']['table'] = 'field_data_field_group_access';
  $handler->display->display_options['fields']['field_group_access']['field'] = 'field_group_access';
  $handler->display->display_options['fields']['field_group_access']['label'] = '';
  $handler->display->display_options['fields']['field_group_access']['element_class'] = 'group-label';
  $handler->display->display_options['fields']['field_group_access']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_group_access']['settings'] = array(
    'link' => 0,
  );
  /* Field: download [filename] */
  $handler->display->display_options['fields']['field_attachment']['id'] = 'field_attachment';
  $handler->display->display_options['fields']['field_attachment']['table'] = 'field_data_field_attachment';
  $handler->display->display_options['fields']['field_attachment']['field'] = 'field_attachment';
  $handler->display->display_options['fields']['field_attachment']['ui_name'] = 'download [filename]';
  $handler->display->display_options['fields']['field_attachment']['label'] = '';
  $handler->display->display_options['fields']['field_attachment']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_attachment']['alter']['text'] = '[field_attachment]';
  $handler->display->display_options['fields']['field_attachment']['alter']['path'] = '[field_attachment]';
  $handler->display->display_options['fields']['field_attachment']['element_type'] = '0';
  $handler->display->display_options['fields']['field_attachment']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_attachment']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_attachment']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_attachment']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_attachment']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_attachment']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_attachment']['separator'] = '<br><br>';
  $handler->display->display_options['fields']['field_attachment']['field_api_classes'] = TRUE;
  /* Field: Download file */
  $handler->display->display_options['fields']['field_attachment_1']['id'] = 'field_attachment_1';
  $handler->display->display_options['fields']['field_attachment_1']['table'] = 'field_data_field_attachment';
  $handler->display->display_options['fields']['field_attachment_1']['field'] = 'field_attachment';
  $handler->display->display_options['fields']['field_attachment_1']['ui_name'] = 'Download file';
  $handler->display->display_options['fields']['field_attachment_1']['label'] = '';
  $handler->display->display_options['fields']['field_attachment_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_attachment_1']['alter']['text'] = 'DOWNLOAD FILE >';
  $handler->display->display_options['fields']['field_attachment_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_attachment_1']['alter']['path'] = '[field_attachment_1]';
  $handler->display->display_options['fields']['field_attachment_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_attachment_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_attachment_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_attachment_1']['type'] = 'file_url_plain';
  $handler->display->display_options['fields']['field_attachment_1']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_attachment_1']['delta_offset'] = '0';
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['relationship'] = 'field_pu_category_tid';
  /* Sort criterion: Content: File date (field_file_date) */
  $handler->display->display_options['sorts']['field_file_date_value']['id'] = 'field_file_date_value';
  $handler->display->display_options['sorts']['field_file_date_value']['table'] = 'field_data_field_file_date';
  $handler->display->display_options['sorts']['field_file_date_value']['field'] = 'field_file_date_value';
  $handler->display->display_options['sorts']['field_file_date_value']['order'] = 'DESC';
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
    'private_upload' => 'private_upload',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['group'] = 1;
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Filter by Date';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'year';
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    4 => 0,
    3 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['date_filter']['group_info']['label'] = 'Date (node)';
  $handler->display->display_options['filters']['date_filter']['group_info']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['date_filter']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $handler->display->display_options['filters']['date_filter']['granularity'] = 'year';
  $handler->display->display_options['filters']['date_filter']['year_range'] = '1999:+0';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'field_data_field_file_date.field_file_date_value' => 'field_data_field_file_date.field_file_date_value',
  );
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter_1']['id'] = 'date_filter_1';
  $handler->display->display_options['filters']['date_filter_1']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter_1']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter_1']['group'] = 1;
  $handler->display->display_options['filters']['date_filter_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator_id'] = 'date_filter_1_op';
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator'] = 'date_filter_1_op';
  $handler->display->display_options['filters']['date_filter_1']['expose']['identifier'] = 'month';
  $handler->display->display_options['filters']['date_filter_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    4 => 0,
    3 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['date_filter_1']['granularity'] = 'month';
  $handler->display->display_options['filters']['date_filter_1']['year_range'] = '1999:+0';
  $handler->display->display_options['filters']['date_filter_1']['date_fields'] = array(
    'field_data_field_file_date.field_file_date_value' => 'field_data_field_file_date.field_file_date_value',
  );
  /* Filter criterion: Content: Category (field_pu_category) */
  $handler->display->display_options['filters']['field_pu_category_tid']['id'] = 'field_pu_category_tid';
  $handler->display->display_options['filters']['field_pu_category_tid']['table'] = 'field_data_field_pu_category';
  $handler->display->display_options['filters']['field_pu_category_tid']['field'] = 'field_pu_category_tid';
  $handler->display->display_options['filters']['field_pu_category_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_pu_category_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_pu_category_tid']['expose']['operator_id'] = 'field_pu_category_tid_op';
  $handler->display->display_options['filters']['field_pu_category_tid']['expose']['label'] = 'Filter by Labels';
  $handler->display->display_options['filters']['field_pu_category_tid']['expose']['operator'] = 'field_pu_category_tid_op';
  $handler->display->display_options['filters']['field_pu_category_tid']['expose']['identifier'] = 'category';
  $handler->display->display_options['filters']['field_pu_category_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    4 => 0,
    3 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['field_pu_category_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_pu_category_tid']['vocabulary'] = 'private_upload_category';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'private-uploads';

  /* Display: Attachment */
  $handler = $view->new_display('attachment', 'Attachment', 'category_list');
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Category */
  $handler->display->display_options['fields']['field_pu_category']['id'] = 'field_pu_category';
  $handler->display->display_options['fields']['field_pu_category']['table'] = 'field_data_field_pu_category';
  $handler->display->display_options['fields']['field_pu_category']['field'] = 'field_pu_category';
  $handler->display->display_options['fields']['field_pu_category']['label'] = '';
  $handler->display->display_options['fields']['field_pu_category']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pu_category']['empty'] = 'Uncategorized';
  $handler->display->display_options['fields']['field_pu_category']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Category (field_pu_category) */
  $handler->display->display_options['sorts']['field_pu_category_tid']['id'] = 'field_pu_category_tid';
  $handler->display->display_options['sorts']['field_pu_category_tid']['table'] = 'field_data_field_pu_category';
  $handler->display->display_options['sorts']['field_pu_category_tid']['field'] = 'field_pu_category_tid';
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
    'private_upload' => 'private_upload',
  );
  $export['private_uploads'] = $view;

  $view = new view();
  $view->name = 'special_users';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Special users';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Sort criterion: User: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'users';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  $handler->display->display_options['sorts']['name']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['name']['expose']['label'] = 'Name';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    4 => '4',
  );

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'name' => 'name',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['special_users'] = $view;

  return $export;
}
