<?php
/**
 * @file
 * fq_user_profile.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function fq_user_profile_user_default_roles() {
  $roles = array();

  // Exported role: unverified user.
  $roles['unverified user'] = array(
    'name' => 'unverified user',
    'weight' => 1,
  );

  return $roles;
}
