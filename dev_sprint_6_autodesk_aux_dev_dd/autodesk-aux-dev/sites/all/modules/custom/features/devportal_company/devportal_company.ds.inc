<?php
/**
 * @file
 * devportal_company.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function devportal_company_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'user|user|default';
  $ds_layout->entity_type = 'user';
  $ds_layout->bundle = 'user';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
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
  $export['user|user|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'user|user|form';
  $ds_layout->entity_type = 'user';
  $ds_layout->bundle = 'user';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col_wrapper';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_user_account_types',
        1 => 'field_ref_company_name',
        2 => 'field_company_partner_type',
        3 => 'field_company_csn_no',
        4 => 'field_sales_org_no',
        5 => 'field_first_name',
        6 => 'field_last_name',
        7 => 'account',
        8 => 'password_policy',
        9 => 'timezone',
        10 => 'ckeditor',
        11 => 'redirect',
      ),
      'hidden' => array(
        12 => 'mimemail',
        13 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'field_user_account_types' => 'ds_content',
      'field_ref_company_name' => 'ds_content',
      'field_company_partner_type' => 'ds_content',
      'field_company_csn_no' => 'ds_content',
      'field_sales_org_no' => 'ds_content',
      'field_first_name' => 'ds_content',
      'field_last_name' => 'ds_content',
      'account' => 'ds_content',
      'password_policy' => 'ds_content',
      'timezone' => 'ds_content',
      'ckeditor' => 'ds_content',
      'redirect' => 'ds_content',
      'mimemail' => 'hidden',
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
  $export['user|user|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'user|user|full';
  $ds_layout->entity_type = 'user';
  $ds_layout->bundle = 'user';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_company_csn_no',
        1 => 'field_company_partner_type',
      ),
    ),
    'fields' => array(
      'field_company_csn_no' => 'ds_content',
      'field_company_partner_type' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['user|user|full'] = $ds_layout;

  return $export;
}
