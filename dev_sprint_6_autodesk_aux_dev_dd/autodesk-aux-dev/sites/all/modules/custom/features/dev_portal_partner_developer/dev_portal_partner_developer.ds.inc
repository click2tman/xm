<?php
/**
 * @file
 * dev_portal_partner_developer.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function dev_portal_partner_developer_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'partner_developers|developers|default';
  $ds_layout->entity_type = 'partner_developers';
  $ds_layout->bundle = 'developers';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col_wrapper';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_first_name',
        1 => 'field_last_name',
        2 => 'field_email',
        3 => 'rules_links_disable_developer_account',
        4 => 'field_related_developer_user_acc',
        5 => 'field_account_status',
        6 => 'field_developer_uiid',
      ),
    ),
    'fields' => array(
      'field_first_name' => 'ds_content',
      'field_last_name' => 'ds_content',
      'field_email' => 'ds_content',
      'rules_links_disable_developer_account' => 'ds_content',
      'field_related_developer_user_acc' => 'ds_content',
      'field_account_status' => 'ds_content',
      'field_developer_uiid' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['partner_developers|developers|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'partner_developers|developers|form';
  $ds_layout->entity_type = 'partner_developers';
  $ds_layout->bundle = 'developers';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col_wrapper';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_first_name',
        1 => 'field_last_name',
        2 => 'field_email',
      ),
      'hidden' => array(
        3 => 'redirect',
        4 => 'field_developer_uiid',
        5 => 'field_account_status',
        6 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'field_first_name' => 'ds_content',
      'field_last_name' => 'ds_content',
      'field_email' => 'ds_content',
      'redirect' => 'hidden',
      'field_developer_uiid' => 'hidden',
      'field_account_status' => 'hidden',
      '_add_existing_field' => 'hidden',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['partner_developers|developers|form'] = $ds_layout;

  return $export;
}
