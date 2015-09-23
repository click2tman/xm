<?php
/**
 * @file
 * dev_portal_forums.features.workbench_moderation_transitions.inc
 */

/**
 * Implements hook_workbench_moderation_export_transitions().
 */
function dev_portal_forums_workbench_moderation_export_transitions() {
  $items = array(
    'published:unpublished' => array(
      'from_name' => 'published',
      'to_name' => 'unpublished',
      'name' => 'Unpublish',
    ),
  );
  return $items;
}
