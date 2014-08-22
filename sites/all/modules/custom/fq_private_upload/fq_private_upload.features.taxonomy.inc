<?php
/**
 * @file
 * fq_private_upload.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function fq_private_upload_taxonomy_default_vocabularies() {
  return array(
    'private_upload_category' => array(
      'name' => 'Private Upload Category',
      'machine_name' => 'private_upload_category',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
