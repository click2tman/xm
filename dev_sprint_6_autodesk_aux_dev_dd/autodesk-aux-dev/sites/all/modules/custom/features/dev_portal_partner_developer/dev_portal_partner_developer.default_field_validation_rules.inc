<?php
/**
 * @file
 * dev_portal_partner_developer.default_field_validation_rules.inc
 */

/**
 * Implements hook_default_field_validation_rule().
 */
function dev_portal_partner_developer_default_field_validation_rule() {
  $export = array();

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'Email address should be unique';
  $rule->name = 'email_address_should_be_unique';
  $rule->field_name = 'field_email';
  $rule->col = 'email';
  $rule->entity_type = 'partner_developers';
  $rule->bundle = 'developers';
  $rule->validator = 'field_validation_unique_validator';
  $rule->settings = array(
    'data' => 'global',
    'per_user' => 0,
    'bypass' => 0,
    'roles' => array(
      1 => 0,
      2 => 0,
      9 => 0,
      8 => 0,
      10 => 0,
      11 => 0,
      4 => 0,
      6 => 0,
      7 => 0,
      5 => 0,
      3 => 0,
    ),
    'errors' => 1,
    'condition' => 0,
    'condition_wrapper' => array(
      'condition_field' => '',
      'condition_operator' => 'equals',
      'condition_value' => '',
    ),
  );
  $rule->error_message = 'There is a developer using this email already';
  $export['email_address_should_be_unique'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'uid must be unique';
  $rule->name = 'uid_must_be_unique';
  $rule->field_name = 'field_developer_uiid';
  $rule->col = 'value';
  $rule->entity_type = 'partner_developers';
  $rule->bundle = 'developers';
  $rule->validator = 'field_validation_unique_validator';
  $rule->settings = array(
    'data' => 'global',
    'per_user' => 0,
    'bypass' => 0,
    'roles' => array(
      1 => 0,
      2 => 0,
      9 => 0,
      8 => 0,
      10 => 0,
      11 => 0,
      4 => 0,
      6 => 0,
      7 => 0,
      5 => 0,
      3 => 0,
    ),
    'errors' => 1,
    'condition' => 0,
    'condition_wrapper' => array(
      'condition_field' => '',
      'condition_operator' => 'equals',
      'condition_value' => '',
    ),
  );
  $rule->error_message = 'uid must be unique';
  $export['uid_must_be_unique'] = $rule;

  return $export;
}
