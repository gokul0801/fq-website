<?php

/**
 *   + Put groups of aliases into files called GROUPNAME.aliases.drushrc.php
 */

# Then the following special aliases are defined:
#
#   @zafe              An alias named after the groupname
#                      may be used to reference all of the
#                      aliases in the group (e.g. drush @mydrupalsite status)
#
#   @zafe.local      A copy of @dev
#
#   @zafe.stage       A copy of @stage


$aliases['kh'] = array(
  # alias for Kevin
  'parent' => '@base',
  'root' => '/var/www/virtual_hosts/fq/htdocs',
  'uri' => 'fq',
  'path-aliases' => array(
    '%files' => 'sites/default/files',
     '%dump' => "/var/www/virtual_hosts/fq/fq.sql",
  ),
);
//this is the alias for the remote QA site
$aliases['qa'] = array(
  'parent' => '@base,@login-qa',
  'root' => '/srv/www-data/fqqa/staging',
  'uri' => 'http://fq-qa.z-w.us',
  'path-aliases' => array(
    '%dump-dir' => '/srv/www-data/fqqa/.drush',
  ),
  'command-specific' => array (
  'sql-dump' => array (
    'result-file' => '/srv/www-data/fq/.drush/back-fqqa-stage-sql-dump'.date(Ymd_Hi).'.sql',
    ),
  ),
);
//this is the alias for the zweb.co remote site
$aliases['zweb'] = array(
  'parent' => '@base,@login-zweb',
  'root' => '/var/www-data/fq-oi/staging',
  'uri' => 'http://fqbeta.com',
  'path-aliases' => array(
    '%dump-dir' => '/var/www-data/fq-oi/.drush',
  ),
  'command-specific' => array (
  'sql-dump' => array (
    'result-file' => '/var/www-data/fq-oi/.drush/back-fq-stage-sql-dump'.date(Ymd_Hi).'.sql',
    ),
  ),
);
//this is the alias for live
$aliases['live'] = array(
  'parent' => '@base,@login-live',
  'root' => '/srv/www-data/fq/prod',
  'rsync' => array (
    # set mode to mirror source (by deleting any files not on source)
    'mode' => 'akz --no-p --no-g -E',
    ),
  'uri' => 'http://fq.com',
  'path-aliases' => array(
    '%dump-dir' => '/srv/www-data/fq/.drush/cache',
  ),
  'command-specific' => array (
  'sql-dump' => array (
    'result-file' => '/srv/www-data/fq/.drush/back-fq-live-sql-dump'.date(Ymd_Hi).'.sql',
    ),
  ),
);
$aliases['live-mirror'] = array(
  'parent' => '@base,@login-live,@live',
  'command-specific' => array (
    'rsync' => array (
      # set mode to mirror source (by deleting any files not on source)
      'mode' => '-del -akz --no-p --no-g -E',
      ),
    ),
);

$aliases['base'] = array(
    '#live' => '@fq.live',
    '#stage' => '@fq.stage',
    '#branch' => 'master',
    '#repo' => 'development',
    'path-aliases' => array(
      '%css' => 'sites/all/themes/fq/css',
      '%theme' => 'sites/all/themes/fq',
      '%files' => 'sites/default/files',
      '%files_private' => 'sites/default/files_private',
      ),
    'target-command-specific' => array (
      'rsync' => array (
        # set mode to mirror source (by deleting any files not on source)
        'mode' => '-del -akz --no-p --no-g -E',
        ),
      ),
    'command-specific' => array (
      'rsync' => array (
        'exclude-paths' => '.*:sites/*/files/xmlsitemap:sites/*/files/ctools:sites/*/files/imagecache:sites/*/files/imagefield_thumbs:sites/*/files/tmp:sites/*/files/js:sites/*/files/css:sites/*/files/styles',
        ),
      'sql-dump' => array (
        'no-cache' => TRUE,
        'show-passwords' => FALSE,
        'ordered-dump' => TRUE,
        #'structure-tables-key' => 'common',
        'structure-tables-key' => 'fq_cache',
        'structure-tables' => array('fq_cache' => array('cache', 'cache_admin_menu','cache_block', 'cache_bootstrap', 'cache_field', 'cache_filter', 'cache_form', 'cache_image', 'cache_libraries', 'cache_media_xml', 'cache_menu', 'cache_page', 'cache_path', 'cache_token', 'cache_update', 'cache_views', 'cache_views_data', 'flood', 'sessions'),),
        ),
      'sql-sync' => array (
        'show-passwords' => FALSE,
        'no-cache' => TRUE,
        #'structure-tables-key' => 'common',
        'structure-tables-key' => 'fq_cache',
        'structure-tables' => array('fq_cache' => array('cache', 'cache_admin_menu','cache_block', 'cache_bootstrap', 'cache_field', 'cache_filter', 'cache_form', 'cache_image', 'cache_libraries', 'cache_media_xml', 'cache_menu', 'cache_page', 'cache_path', 'cache_token', 'cache_update', 'cache_views', 'cache_views_data', 'flood', 'sessions'),),
        ),
      ),
);

$aliases['login-zweb'] = array(
  'remote-host' => 'fqbeta.com',
  'remote-user' => 'fq-oi',
  'ssh-options' => '-p 32415',
);
$aliases['login-live'] = array(
  'remote-host' => 'z-w.us',
  'remote-user' => 'fq',
  'ssh-options' => '-p 32415',
);

