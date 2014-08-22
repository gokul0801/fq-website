<?php

$options['shell-aliases']['pull-stage'] = '!echo "Pulling FROM: {{#stage}} \n          TO: {{@target}}" && drush {{@target}} ard --description="pull-stage backup" && drush {{#stage}} ard --description="pull-stage backup" && drush -yv sql-drop {{@target}} && drush -yv sql-sync {{#stage}} {{@target}} && drush -yv rsync {{#stage}}:%files {{@target}}:%files && drush -yv rsync {{#stage}}:%files_private {{@target}}:%files_private';
$options['shell-aliases']['pull-stage-files'] = '!drush -yv rsync {{#stage}}:%files {{@target}}:%files && drush -yv rsync {{#stage}}:%files_private {{@target}}:%files_private && drush -yv rsync {{#stage}}:%css {{@target}}:%css';
$options['shell-aliases']['push-stage-files'] = '!drush -yv rsync {{@target}}:%files {{#stage}}:%files && drush -yv rsync {{@target}}:%files_private {{#stage}}:%files_private && drush -yv rsync {{@target}}:%css {{#stage}}:%css';
$options['shell-aliases']['push-stage-css'] = '!drush -yv rsync {{@target}}:%css {{#stage}}:%css';
