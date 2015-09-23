<?php
/**
 * @file
 * dev_portal_theme_settings.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function dev_portal_theme_settings_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'adsk_home';
  $context->description = 'Delta of Apigee Home page';
  $context->tag = 'Blocks';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'home' => 'home',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-api_reference_docs-block_1' => array(
          'module' => 'views',
          'delta' => 'api_reference_docs-block_1',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-dev_portal_blog_content-block_2' => array(
          'module' => 'views',
          'delta' => 'dev_portal_blog_content-block_2',
          'region' => 'content',
          'weight' => '-9',
        ),
        'bean-building-an-app-home' => array(
          'module' => 'bean',
          'delta' => 'building-an-app-home',
          'region' => 'content',
          'weight' => '-8',
        ),
        'bean-dev-homepage-header' => array(
          'module' => 'bean',
          'delta' => 'dev-homepage-header',
          'region' => 'homepage_header',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks');
  t('Delta of Apigee Home page');
  $export['adsk_home'] = $context;

  return $export;
}
