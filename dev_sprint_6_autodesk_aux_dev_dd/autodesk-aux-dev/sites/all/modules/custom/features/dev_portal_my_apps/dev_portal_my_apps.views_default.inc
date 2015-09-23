<?php
/**
 * @file
 * dev_portal_my_apps.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dev_portal_my_apps_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'dev_portal_developer_apps';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'dc_dev_app';
  $view->human_name = 'Dev Portal Developer Apps';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = 40;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'uid' => 'uid',
    'field_first_name' => 'field_first_name',
    'field_last_name' => 'field_last_name',
    'app_name' => 'app_name',
    'username' => 'username',
    'api_key' => 'api_key',
    'api_product' => 'api_product',
    'status' => 'status',
    'edit_link' => 'edit_link',
    'delete_link' => 'delete_link',
  );
  $handler->display->display_options['style_options']['default'] = 'username';
  $handler->display->display_options['style_options']['info'] = array(
    'uid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_first_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_last_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'app_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'username' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'api_key' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'api_product' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_link' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_link' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Broken/missing handler */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'dc_dev_app';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'dc_dev_app';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  /* Field: Field: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['app_name']['id'] = 'app_name';
  $handler->display->display_options['fields']['app_name']['table'] = 'dc_dev_app';
  $handler->display->display_options['fields']['app_name']['field'] = 'name';
  $handler->display->display_options['fields']['app_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['app_name']['alter']['path'] = 'user/[uid]/apps/[app_name]';
  /* Field: User: Name */
  $handler->display->display_options['fields']['username']['id'] = 'username';
  $handler->display->display_options['fields']['username']['table'] = 'users';
  $handler->display->display_options['fields']['username']['field'] = 'name';
  $handler->display->display_options['fields']['username']['relationship'] = 'uid';
  $handler->display->display_options['fields']['username']['label'] = 'Developer';
  $handler->display->display_options['fields']['username']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['username']['alter']['text'] = '[username] ([field_first_name] [field_last_name])';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['api_key']['id'] = 'api_key';
  $handler->display->display_options['fields']['api_key']['table'] = 'dc_dev_app';
  $handler->display->display_options['fields']['api_key']['field'] = 'consumer_key';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['api_product']['id'] = 'api_product';
  $handler->display->display_options['fields']['api_product']['table'] = 'dc_api_product';
  $handler->display->display_options['fields']['api_product']['field'] = 'api_product_display_name';
  $handler->display->display_options['fields']['api_product']['label'] = 'API Products';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'dc_dev_app';
  $handler->display->display_options['fields']['status']['field'] = 'overall_status';
  $handler->display->display_options['fields']['status']['label'] = 'Status';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['edit_link']['id'] = 'edit_link';
  $handler->display->display_options['fields']['edit_link']['table'] = 'views';
  $handler->display->display_options['fields']['edit_link']['field'] = 'nothing';
  $handler->display->display_options['fields']['edit_link']['label'] = '';
  $handler->display->display_options['fields']['edit_link']['alter']['text'] = 'Edit';
  $handler->display->display_options['fields']['edit_link']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['edit_link']['alter']['path'] = 'user/[uid]/apps/[app_name]/edit-app';
  $handler->display->display_options['fields']['edit_link']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['delete_link']['id'] = 'delete_link';
  $handler->display->display_options['fields']['delete_link']['table'] = 'views';
  $handler->display->display_options['fields']['delete_link']['field'] = 'nothing';
  $handler->display->display_options['fields']['delete_link']['label'] = '';
  $handler->display->display_options['fields']['delete_link']['alter']['text'] = 'Delete';
  $handler->display->display_options['fields']['delete_link']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['delete_link']['alter']['path'] = 'user/[uid]/apps/[app_name]/delete';
  $handler->display->display_options['fields']['delete_link']['element_label_colon'] = FALSE;
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Developer Apps';
  $handler->display->display_options['path'] = 'admin/dev/reports/developer-apps';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Developer Apps';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['uid']['validate']['type'] = 'me';
  $handler->display->display_options['arguments']['uid']['validate_options']['type'] = 'either';
  $handler->display->display_options['block_description'] = 'Developer Apps';
  $export['dev_portal_developer_apps'] = $view;

  return $export;
}
