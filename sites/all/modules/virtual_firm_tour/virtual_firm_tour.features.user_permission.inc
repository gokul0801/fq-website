<?php
/**
 * @file
 * virtual_firm_tour.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function virtual_firm_tour_user_default_permissions() {
  $permissions = array();

  // Exported permission: create firm_tour content.
  $permissions['create firm_tour content'] = array(
    'name' => 'create firm_tour content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any firm_tour content.
  $permissions['delete any firm_tour content'] = array(
    'name' => 'delete any firm_tour content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own firm_tour content.
  $permissions['delete own firm_tour content'] = array(
    'name' => 'delete own firm_tour content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any firm_tour content.
  $permissions['edit any firm_tour content'] = array(
    'name' => 'edit any firm_tour content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own firm_tour content.
  $permissions['edit own firm_tour content'] = array(
    'name' => 'edit own firm_tour content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
