<?php
/**
 * @file
 * dev_portal_partner_developer.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dev_portal_partner_developer_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'partner_developers';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_partner_developers';
  $view->human_name = 'Partner Developers';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Partner Developers';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    11 => '11',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_table_plugin_style';
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['header']['area_text_custom']['content'] = '<a href="/admin/structure/entity-type/partner_developers/developers/add">Invite a Developer</a>';
  /* Relationship: Partner Developers: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'eck_partner_developers';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_ref_company_name_target_id']['id'] = 'field_ref_company_name_target_id';
  $handler->display->display_options['relationships']['field_ref_company_name_target_id']['table'] = 'field_data_field_ref_company_name';
  $handler->display->display_options['relationships']['field_ref_company_name_target_id']['field'] = 'field_ref_company_name_target_id';
  $handler->display->display_options['relationships']['field_ref_company_name_target_id']['relationship'] = 'uid';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_related_developer_user_acc_target_id']['id'] = 'field_related_developer_user_acc_target_id';
  $handler->display->display_options['relationships']['field_related_developer_user_acc_target_id']['table'] = 'field_data_field_related_developer_user_acc';
  $handler->display->display_options['relationships']['field_related_developer_user_acc_target_id']['field'] = 'field_related_developer_user_acc_target_id';
  /* Field: Partner Developers: Developer UID */
  $handler->display->display_options['fields']['field_developer_uiid']['id'] = 'field_developer_uiid';
  $handler->display->display_options['fields']['field_developer_uiid']['table'] = 'field_data_field_developer_uiid';
  $handler->display->display_options['fields']['field_developer_uiid']['field'] = 'field_developer_uiid';
  $handler->display->display_options['fields']['field_developer_uiid']['label'] = 'Developer UIID';
  $handler->display->display_options['fields']['field_developer_uiid']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Partner Developers: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'eck_partner_developers';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  /* Field: Partner Developers: Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'field_ref_company_name_target_id';
  $handler->display->display_options['fields']['field_first_name']['label'] = 'Company';
  /* Field: Field: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'field_ref_company_name_target_id';
  $handler->display->display_options['fields']['field_last_name']['label'] = 'ShortName';
  /* Field: User: Company CSN No(s) */
  $handler->display->display_options['fields']['field_company_csn_no']['id'] = 'field_company_csn_no';
  $handler->display->display_options['fields']['field_company_csn_no']['table'] = 'field_data_field_company_csn_no';
  $handler->display->display_options['fields']['field_company_csn_no']['field'] = 'field_company_csn_no';
  $handler->display->display_options['fields']['field_company_csn_no']['relationship'] = 'field_ref_company_name_target_id';
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
  /* Field: Partner Developers: Disable Developer Account */
  $handler->display->display_options['fields']['disable_developer_account']['id'] = 'disable_developer_account';
  $handler->display->display_options['fields']['disable_developer_account']['table'] = 'views_entity_partner_developers';
  $handler->display->display_options['fields']['disable_developer_account']['field'] = 'disable_developer_account';
  $handler->display->display_options['fields']['disable_developer_account']['label'] = '';
  $handler->display->display_options['fields']['disable_developer_account']['exclude'] = TRUE;
  $handler->display->display_options['fields']['disable_developer_account']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['disable_developer_account']['rules_link'] = array(
    'rules_link_parameters' => '',
    'rules_link_rewrite' => '',
  );
  /* Field: Partner Developers: Enable Developer Account */
  $handler->display->display_options['fields']['enable_developer_account']['id'] = 'enable_developer_account';
  $handler->display->display_options['fields']['enable_developer_account']['table'] = 'views_entity_partner_developers';
  $handler->display->display_options['fields']['enable_developer_account']['field'] = 'enable_developer_account';
  $handler->display->display_options['fields']['enable_developer_account']['label'] = '';
  $handler->display->display_options['fields']['enable_developer_account']['exclude'] = TRUE;
  $handler->display->display_options['fields']['enable_developer_account']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['enable_developer_account']['rules_link'] = array(
    'rules_link_parameters' => '',
    'rules_link_rewrite' => '',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Action';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[disable_developer_account] [enable_developer_account] ';
  /* Contextual filter: Partner Developers: Author */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'eck_partner_developers';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['uid']['validate']['type'] = 'user';
  $handler->display->display_options['arguments']['uid']['validate_options']['type'] = 'either';
  /* Filter criterion: Partner Developers: partner_developers type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_partner_developers';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'developers' => 'developers',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'partner-developers';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';

  /* Display: My Developers Page */
  $handler = $view->new_display('page', 'My Developers Page', 'page_1');
  $handler->display->display_options['path'] = 'admin/workbench/my-developers';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'My Developers';
  $handler->display->display_options['menu']['description'] = 'My Developers';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['partner_developers'] = $view;

  return $export;
}
