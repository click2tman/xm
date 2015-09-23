<?php
/**
 * @file
 * dev_portal_workkbench.features.workbench_moderation_transitions.inc
 */

/**
 * Implements hook_workbench_moderation_export_transitions().
 */
function dev_portal_workkbench_workbench_moderation_export_transitions() {
  $items = array(
    'draft:needs_review' => array(
      'from_name' => 'draft',
      'to_name' => 'needs_review',
      'name' => 'Submit for Review',
    ),
    'needs_review:draft' => array(
      'from_name' => 'needs_review',
      'to_name' => 'draft',
      'name' => 'Reject',
    ),
    'needs_review:published' => array(
      'from_name' => 'needs_review',
      'to_name' => 'published',
      'name' => 'Publish',
    ),
    'published:unpublished' => array(
      'from_name' => 'published',
      'to_name' => 'unpublished',
      'name' => 'Unpublish',
    ),
  );
  return $items;
}
