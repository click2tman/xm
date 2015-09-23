<?php
/**
 * @file
 * dev_portal_my_apps.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function dev_portal_my_apps_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'my_apps';
  $context->description = '';
  $context->tag = 'My Apps';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'user/me/apps' => 'user/me/apps',
        'user/*/apps' => 'user/*/apps',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-c76d403db743932e70b9f4b8edb4e579' => array(
          'module' => 'views',
          'delta' => 'c76d403db743932e70b9f4b8edb4e579',
          'region' => 'content',
          'weight' => '5',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('My Apps');
  $export['my_apps'] = $context;

  return $export;
}
