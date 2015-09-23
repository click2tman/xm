<?php
/**
 * @file
 * devportal_company.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function devportal_company_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'company_users';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Company Users';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Company Users';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Account Type (field_user_account_types) */
  $handler->display->display_options['filters']['field_user_account_types_value_1']['id'] = 'field_user_account_types_value_1';
  $handler->display->display_options['filters']['field_user_account_types_value_1']['table'] = 'field_data_field_user_account_types';
  $handler->display->display_options['filters']['field_user_account_types_value_1']['field'] = 'field_user_account_types_value';
  $handler->display->display_options['filters']['field_user_account_types_value_1']['value'] = array(
    'Company' => 'Company',
  );
  $handler->display->display_options['filters']['field_user_account_types_value_1']['group'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'company-users';

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'name' => 'name',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['company_users'] = $view;

  $view = new view();
  $view->name = 'dev_portal_companies';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Dev Portal Companies';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Autodesk Partner Developer Portal Developers and Associated Companies Page';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    5 => '5',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_table_plugin_style';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_first_name_1' => 'field_first_name_1',
    'field_last_name' => 'field_last_name',
    'name' => 'name',
    'field_first_name' => 'field_first_name',
    'field_company_csn_no' => 'field_company_csn_no',
    'field_company_partner_type' => 'field_company_partner_type',
    'view_user' => 'view_user',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_first_name_1' => array(
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
    'name' => array(
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
    'field_company_csn_no' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_company_partner_type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_user' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['bootstrap_styles'] = array(
    'striped' => 0,
    'bordered' => 0,
    'hover' => 0,
    'condensed' => 0,
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_ref_company_name_target_id']['id'] = 'field_ref_company_name_target_id';
  $handler->display->display_options['relationships']['field_ref_company_name_target_id']['table'] = 'field_data_field_ref_company_name';
  $handler->display->display_options['relationships']['field_ref_company_name_target_id']['field'] = 'field_ref_company_name_target_id';
  $handler->display->display_options['relationships']['field_ref_company_name_target_id']['required'] = TRUE;
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name_1']['id'] = 'field_first_name_1';
  $handler->display->display_options['fields']['field_first_name_1']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name_1']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name_1']['label'] = '';
  $handler->display->display_options['fields']['field_first_name_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_first_name_1']['element_label_colon'] = FALSE;
  /* Field: Field: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = '[field_first_name_1] [field_last_name]';
  $handler->display->display_options['fields']['name']['alter']['path'] = '[view_user]';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'field_ref_company_name_target_id';
  $handler->display->display_options['fields']['field_first_name']['label'] = 'Company Name';
  /* Field: User: Company CSN No(s) */
  $handler->display->display_options['fields']['field_company_csn_no']['id'] = 'field_company_csn_no';
  $handler->display->display_options['fields']['field_company_csn_no']['table'] = 'field_data_field_company_csn_no';
  $handler->display->display_options['fields']['field_company_csn_no']['field'] = 'field_company_csn_no';
  $handler->display->display_options['fields']['field_company_csn_no']['relationship'] = 'field_ref_company_name_target_id';
  $handler->display->display_options['fields']['field_company_csn_no']['label'] = 'CSN No(s)';
  $handler->display->display_options['fields']['field_company_csn_no']['delta_offset'] = '0';
  /* Field: User: Partner Type */
  $handler->display->display_options['fields']['field_company_partner_type']['id'] = 'field_company_partner_type';
  $handler->display->display_options['fields']['field_company_partner_type']['table'] = 'field_data_field_company_partner_type';
  $handler->display->display_options['fields']['field_company_partner_type']['field'] = 'field_company_partner_type';
  $handler->display->display_options['fields']['field_company_partner_type']['relationship'] = 'field_ref_company_name_target_id';
  /* Field: User: Link */
  $handler->display->display_options['fields']['view_user']['id'] = 'view_user';
  $handler->display->display_options['fields']['view_user']['table'] = 'users';
  $handler->display->display_options['fields']['view_user']['field'] = 'view_user';
  $handler->display->display_options['fields']['view_user']['label'] = '';
  $handler->display->display_options['fields']['view_user']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_user']['element_label_colon'] = FALSE;
  /* Field: User: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'users';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Actions';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '[edit_node] | [view_user] ';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Portal Developers and Associated Companies Page';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['empty'] = TRUE;
  $handler->display->display_options['header']['result']['content'] = '<div><a href="/admin/people/create">Create a new Developer/Partner Admin/Company</a></div>
<div>Displaying @start - @end of @total Partner Developers</div>
';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p>There are no partner developers to display. Please add at least one developer, partner admin and associated company</p>
<div><a href="/admin/people/create">Create a new Developer/Partner Admin/Company</a></div>
';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name_1']['id'] = 'field_first_name_1';
  $handler->display->display_options['fields']['field_first_name_1']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name_1']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name_1']['label'] = '';
  $handler->display->display_options['fields']['field_first_name_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_first_name_1']['element_label_colon'] = FALSE;
  /* Field: Field: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = '[field_first_name_1] [field_last_name]';
  $handler->display->display_options['fields']['name']['alter']['path'] = '[view_user]';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'field_ref_company_name_target_id';
  $handler->display->display_options['fields']['field_first_name']['label'] = 'Company Name';
  /* Field: User: Company CSN No(s) */
  $handler->display->display_options['fields']['field_company_csn_no']['id'] = 'field_company_csn_no';
  $handler->display->display_options['fields']['field_company_csn_no']['table'] = 'field_data_field_company_csn_no';
  $handler->display->display_options['fields']['field_company_csn_no']['field'] = 'field_company_csn_no';
  $handler->display->display_options['fields']['field_company_csn_no']['relationship'] = 'field_ref_company_name_target_id';
  $handler->display->display_options['fields']['field_company_csn_no']['label'] = 'CSN No(s)';
  $handler->display->display_options['fields']['field_company_csn_no']['delta_offset'] = '0';
  /* Field: User: Sales Org No(s) */
  $handler->display->display_options['fields']['field_sales_org_no']['id'] = 'field_sales_org_no';
  $handler->display->display_options['fields']['field_sales_org_no']['table'] = 'field_data_field_sales_org_no';
  $handler->display->display_options['fields']['field_sales_org_no']['field'] = 'field_sales_org_no';
  $handler->display->display_options['fields']['field_sales_org_no']['relationship'] = 'field_ref_company_name_target_id';
  /* Field: User: Partner Type */
  $handler->display->display_options['fields']['field_company_partner_type']['id'] = 'field_company_partner_type';
  $handler->display->display_options['fields']['field_company_partner_type']['table'] = 'field_data_field_company_partner_type';
  $handler->display->display_options['fields']['field_company_partner_type']['field'] = 'field_company_partner_type';
  $handler->display->display_options['fields']['field_company_partner_type']['relationship'] = 'field_ref_company_name_target_id';
  /* Field: User: Link */
  $handler->display->display_options['fields']['view_user']['id'] = 'view_user';
  $handler->display->display_options['fields']['view_user']['table'] = 'users';
  $handler->display->display_options['fields']['view_user']['field'] = 'view_user';
  $handler->display->display_options['fields']['view_user']['label'] = '';
  $handler->display->display_options['fields']['view_user']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_user']['element_label_colon'] = FALSE;
  /* Field: User: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'users';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Actions';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '[edit_node] | [view_user] ';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['path'] = 'admin/workbench/developers-and-associated-companies';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Partner Developers';
  $handler->display->display_options['menu']['description'] = 'Partner Developers';
  $handler->display->display_options['menu']['weight'] = '-10';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: My company details Block */
  $handler = $view->new_display('block', 'My company details Block', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    8 => '8',
    9 => '9',
    10 => '10',
    11 => '11',
  );
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Your account is not associated to a company';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'field_ref_company_name_target_id';
  $handler->display->display_options['fields']['field_first_name']['label'] = 'Company Name';
  /* Field: User: Company CSN No(s) */
  $handler->display->display_options['fields']['field_company_csn_no']['id'] = 'field_company_csn_no';
  $handler->display->display_options['fields']['field_company_csn_no']['table'] = 'field_data_field_company_csn_no';
  $handler->display->display_options['fields']['field_company_csn_no']['field'] = 'field_company_csn_no';
  $handler->display->display_options['fields']['field_company_csn_no']['relationship'] = 'field_ref_company_name_target_id';
  $handler->display->display_options['fields']['field_company_csn_no']['label'] = 'CSN No(s)';
  $handler->display->display_options['fields']['field_company_csn_no']['delta_offset'] = '0';
  /* Field: User: Sales Org No(s) */
  $handler->display->display_options['fields']['field_sales_org_no']['id'] = 'field_sales_org_no';
  $handler->display->display_options['fields']['field_sales_org_no']['table'] = 'field_data_field_sales_org_no';
  $handler->display->display_options['fields']['field_sales_org_no']['field'] = 'field_sales_org_no';
  $handler->display->display_options['fields']['field_sales_org_no']['relationship'] = 'field_ref_company_name_target_id';
  /* Field: User: Partner Type */
  $handler->display->display_options['fields']['field_company_partner_type']['id'] = 'field_company_partner_type';
  $handler->display->display_options['fields']['field_company_partner_type']['table'] = 'field_data_field_company_partner_type';
  $handler->display->display_options['fields']['field_company_partner_type']['field'] = 'field_company_partner_type';
  $handler->display->display_options['fields']['field_company_partner_type']['relationship'] = 'field_ref_company_name_target_id';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['uid']['validate']['type'] = 'me';
  $handler->display->display_options['arguments']['uid']['validate_options']['type'] = 'either';
  $handler->display->display_options['block_description'] = 'My Company Details';

  /* Display: Company details Block */
  $handler = $view->new_display('block', 'Company details Block', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Your account is not associated to a company';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'field_ref_company_name_target_id';
  $handler->display->display_options['fields']['field_first_name']['label'] = 'Company Name';
  /* Field: User: Company CSN No(s) */
  $handler->display->display_options['fields']['field_company_csn_no']['id'] = 'field_company_csn_no';
  $handler->display->display_options['fields']['field_company_csn_no']['table'] = 'field_data_field_company_csn_no';
  $handler->display->display_options['fields']['field_company_csn_no']['field'] = 'field_company_csn_no';
  $handler->display->display_options['fields']['field_company_csn_no']['relationship'] = 'field_ref_company_name_target_id';
  $handler->display->display_options['fields']['field_company_csn_no']['label'] = 'CSN No(s)';
  $handler->display->display_options['fields']['field_company_csn_no']['delta_offset'] = '0';
  /* Field: User: Sales Org No(s) */
  $handler->display->display_options['fields']['field_sales_org_no']['id'] = 'field_sales_org_no';
  $handler->display->display_options['fields']['field_sales_org_no']['table'] = 'field_data_field_sales_org_no';
  $handler->display->display_options['fields']['field_sales_org_no']['field'] = 'field_sales_org_no';
  $handler->display->display_options['fields']['field_sales_org_no']['relationship'] = 'field_ref_company_name_target_id';
  /* Field: User: Partner Type */
  $handler->display->display_options['fields']['field_company_partner_type']['id'] = 'field_company_partner_type';
  $handler->display->display_options['fields']['field_company_partner_type']['table'] = 'field_data_field_company_partner_type';
  $handler->display->display_options['fields']['field_company_partner_type']['field'] = 'field_company_partner_type';
  $handler->display->display_options['fields']['field_company_partner_type']['relationship'] = 'field_ref_company_name_target_id';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['validate']['type'] = 'user';
  $handler->display->display_options['arguments']['uid']['validate_options']['type'] = 'either';
  $handler->display->display_options['block_description'] = 'Company Details';
  $export['dev_portal_companies'] = $view;

  return $export;
}
