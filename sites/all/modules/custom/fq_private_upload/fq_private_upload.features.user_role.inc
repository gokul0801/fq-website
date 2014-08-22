<?php
/**
 * @file
 * fq_private_upload.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function fq_private_upload_user_default_roles() {
  $roles = array();

  // Exported role: special user.
  $roles['special user'] = array(
    'name' => 'special user',
    'weight' => 3,
  );

  return $roles;
}
