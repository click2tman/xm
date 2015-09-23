<?php
/**
 * @file
 * dev_portal_blog.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function dev_portal_blog_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Tutorials',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => 'b8e3cd15-adf3-4ea9-835a-62100affa052',
    'vocabulary_machine_name' => 'blog',
  );
  $terms[] = array(
    'name' => 'Portal',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => 'cfe63e20-1407-42e8-b0f2-df5632514f61',
    'vocabulary_machine_name' => 'blog',
  );
  $terms[] = array(
    'name' => 'test',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => 'd006a7ae-a749-4df9-8dfc-5483b2fa45d7',
    'vocabulary_machine_name' => 'blog',
  );
  $terms[] = array(
    'name' => 'IOT',
    'description' => NULL,
    'format' => NULL,
    'weight' => 0,
    'uuid' => 'dab83a8e-194c-4822-ac6a-dd8af6ea2215',
    'vocabulary_machine_name' => 'blog',
  );
  return $terms;
}
