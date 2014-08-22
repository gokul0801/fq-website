<?php
/**
 * @file
 * Rules integration for private uploads.
 *
 */

/**
 * Implements hook_rules_action_info().
 */
function fq_private_upload_rules_action_info() {
  $actions = array();

  $actions['fq_private_uploads_get_notification_users'] = array(
    'label' => t('Get list of user to be notified by email when a private upload is published'),
    'parameter' => array(
      'user_access' => array(
        'type' => 'user',
        'label' => t('User Access'),
        'optional' => TRUE,
        'allow null' => TRUE,
      ),
      'group_access' => array(
        'type' => 'node',
        'label' => t('Group Access'),
        'optional' => TRUE,
        'allow null' => TRUE,
      ),
    ),
    'provides' => array(
      'users' => array(
        'label' => t('User to notify'),
        'type' => 'list<user>',
      ),
    ),
    'group' => t('Private Uploads'),
    'callbacks' => array(
      'execute' => 'fq_private_upload_get_notification_users',
    ),
  );

  return $actions;
}

/**
 * Return the recurring products present inside an order.
 */
function fq_private_upload_get_notification_users($user_access = NULL, $group_access = NULL) {
  if (isset($group_access)) {
    $users = fq_private_upload_get_group_users($group_access->nid);
  } else {
    $users = array();
  }
  
  if (isset($user_access)) {
    $users[] = $user_access;
  }
  
  return array('users' => $users);
}

function fq_private_upload_get_group_users($gid) {
  $users = array();
  $result = db_select('og_membership', 'ogm')
    ->fields('ogm', array('etid'))
    ->condition('entity_type', 'user', '=')
    ->condition('gid', $gid, '=')
    ->execute();
  
  foreach($result as $uid) {
    $user = user_load($uid->etid);
    if($user) {
      $users[] = $user;
    }
  }
  
  return $users;
}