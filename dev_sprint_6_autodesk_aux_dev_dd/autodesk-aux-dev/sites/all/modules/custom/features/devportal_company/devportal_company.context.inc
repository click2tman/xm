<?php
/**
 * @file
 * devportal_company.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function devportal_company_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'developer_company_info';
  $context->description = 'csn, partner type and company ';
  $context->tag = 'Company';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'apiconsole' => 'apiconsole',
        'user/me/apps' => 'user/me/apps',
        'user/me' => 'user/me',
        'user' => 'user',
        'apis' => 'apis',
      ),
    ),
    'theme' => array(
      'values' => array(
        'autodesk' => 'autodesk',
      ),
    ),
    'user' => array(
      'values' => array(
        'External Direct Developer' => 'External Direct Developer',
        'External Indirect Developer' => 'External Indirect Developer',
        'Internal Developer' => 'Internal Developer',
        'Partner Admin' => 'Partner Admin',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-dev_portal_companies-block' => array(
          'module' => 'views',
          'delta' => 'dev_portal_companies-block',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Company');
  t('csn, partner type and company ');
  $export['developer_company_info'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'display_company_details';
  $context->description = 'Display associated company details on users/* pages';
  $context->tag = 'Company';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'users' => 'users',
        'users/' => 'users/',
        'users/*' => 'users/*',
      ),
    ),
    'theme' => array(
      'values' => array(
        'autodesk' => 'autodesk',
      ),
    ),
    'user' => array(
      'values' => array(
        'Configuration Manager' => 'Configuration Manager',
        'Content Provider' => 'Content Provider',
        'Content Publisher' => 'Content Publisher',
        'administrator' => 'administrator',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-dev_portal_companies-block_2' => array(
          'module' => 'views',
          'delta' => 'dev_portal_companies-block_2',
          'region' => 'content',
          'weight' => '5',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Company');
  t('Display associated company details on users/* pages');
  $export['display_company_details'] = $context;

  return $export;
}
