<?php
/**
 * @file
 * fq_private_upload.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function fq_private_upload_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-private_upload-body'
  $field_instances['node-private_upload-body'] = array(
    'bundle' => 'private_upload',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'trim_length' => 600,
        ),
        'type' => 'text_summary_or_trimmed',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'fences_wrapper' => 'div',
    'field_name' => 'body',
    'label' => 'Description',
    'required' => 0,
    'settings' => array(
      'display_summary' => 1,
      'field_confirmation' => array(
        'enabled' => 0,
        'message' => '',
      ),
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-private_upload-field_attachment'
  $field_instances['node-private_upload-field_attachment'] = array(
    'bundle' => 'private_upload',
    'deleted' => 0,
    'description' => 'Important! Remember to press Start Upload after selecting files. Files must be fully uploaded before saving this content.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'fences_wrapper' => 'div',
    'field_name' => 'field_attachment',
    'label' => 'Download attachment',
    'required' => 1,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => '',
      'file_extensions' => 'txt rdf doc docx pdf ppt pptx ppsx xls xlsx png jpg tif tiff jpeg',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'filefield_sources' => array(
          'filefield_sources' => array(
            'attach' => 0,
            'clipboard' => 0,
            'plupload' => 'plupload',
            'reference' => 0,
            'remote' => 0,
            'upload' => 0,
          ),
          'source_attach' => array(
            'absolute' => 0,
            'attach_mode' => 'move',
            'path' => 'file_attach',
          ),
          'source_imce' => array(
            'imce_mode' => 0,
          ),
          'source_reference' => array(
            'autocomplete' => 0,
          ),
        ),
        'insert' => 0,
        'insert_absolute' => 0,
        'insert_class' => '',
        'insert_default' => 'auto',
        'insert_styles' => array(
          'auto' => 'auto',
          'colorbox__110x146' => 0,
          'colorbox__920x180' => 0,
          'colorbox__large' => 0,
          'colorbox__medium' => 0,
          'colorbox__resp_breakpoints_theme_fq_mobile_1x' => 0,
          'colorbox__resp_breakpoints_theme_fq_narrow_1x' => 0,
          'colorbox__resp_breakpoints_theme_fq_tv_1x' => 0,
          'colorbox__resp_breakpoints_theme_fq_wide_1x' => 0,
          'colorbox__thumbnail' => 0,
          'colorbox__tour' => 0,
          'colorbox__wide' => 0,
          'icon_link' => 0,
          'image' => 0,
          'image_110x146' => 0,
          'image_920x180' => 0,
          'image_large' => 0,
          'image_medium' => 0,
          'image_resp_breakpoints_theme_fq_mobile_1x' => 0,
          'image_resp_breakpoints_theme_fq_narrow_1x' => 0,
          'image_resp_breakpoints_theme_fq_tv_1x' => 0,
          'image_resp_breakpoints_theme_fq_wide_1x' => 0,
          'image_thumbnail' => 0,
          'image_tour' => 0,
          'image_wide' => 0,
          'link' => 0,
        ),
        'insert_width' => '',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-private_upload-field_file_date'
  $field_instances['node-private_upload-field_file_date'] = array(
    'bundle' => 'private_upload',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
        ),
        'type' => 'date_default',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_file_date',
    'label' => 'File date',
    'required' => 0,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 15,
        'input_format' => 'm/d/Y - H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'text_parts' => array(),
        'year_range' => '1999:+0',
      ),
      'type' => 'date_select',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'node-private_upload-field_group_access'
  $field_instances['node-private_upload-field_group_access'] = array(
    'bundle' => 'private_upload',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_group_access',
    'label' => 'Group access',
    'required' => 0,
    'settings' => array(
      'field_confirmation' => array(
        'empty_message' => 'Please select a value for Group access',
        'enabled' => 1,
        'message' => 'Are you sure you want to give access to the following group?',
      ),
      'nodeaccess_nodereference' => array(
        'all' => array(
          'view' => 0,
        ),
        'all_published' => 0,
        'author' => array(
          'delete' => 0,
          'update' => 0,
          'view' => 0,
        ),
        'author_published' => 0,
        'priority' => 0,
        'referenced' => array(
          'delete' => array(
            'delete' => 'delete',
            'update' => 0,
            'view' => 0,
          ),
          'published' => 0,
          'update' => array(
            'delete' => 0,
            'update' => 'update',
            'view' => 0,
          ),
          'view' => array(
            'delete' => 0,
            'update' => 0,
            'view' => 'view',
          ),
        ),
        'unused' => 1,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-private_upload-field_pu_category'
  $field_instances['node-private_upload-field_pu_category'] = array(
    'bundle' => 'private_upload',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pu_category',
    'label' => 'Category',
    'required' => 0,
    'settings' => array(
      'field_confirmation' => array(
        'empty_message' => 'Please select a value before submitting.',
        'enabled' => 0,
        'message' => 'Confirm the values below before submitting.',
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'node-private_upload-field_user_access'
  $field_instances['node-private_upload-field_user_access'] = array(
    'bundle' => 'private_upload',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Grant access to view this content and the attached file.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'fences_wrapper' => 'div',
    'field_name' => 'field_user_access',
    'label' => 'User access',
    'required' => 0,
    'settings' => array(
      'field_confirmation' => array(
        'empty_message' => 'Please select a value for User access',
        'enabled' => 1,
        'message' => 'Are you sure you want to give access to the following user?',
      ),
      'nodeaccess_userreference' => array(
        'all' => array(
          'view' => 0,
        ),
        'all_published' => 0,
        'author' => array(
          'delete' => 0,
          'update' => 0,
          'view' => 0,
        ),
        'author_published' => 0,
        'create' => array(
          'article' => 0,
          'attribution' => 0,
          'background_homepage_slider' => 0,
          'background_image' => 0,
          'blog' => 0,
          'careers' => 0,
          'faq' => 0,
          'featured_insights' => 0,
          'feed' => 0,
          'feed_item' => 0,
          'firm_tour' => 0,
          'fq_article' => 0,
          'fq_in_the_news' => 0,
          'group' => 0,
          'industry_resources' => 0,
          'news' => 0,
          'page' => 0,
          'partner' => 0,
          'people' => 0,
          'private_upload' => 0,
          'product_distinction' => 0,
          'product_summary' => 0,
          'quarterly_video_updates' => 0,
          'research_ideas' => 0,
          'strategy' => 0,
          'team_member' => 0,
          'team_overview' => 0,
          'teams' => 0,
          'testimonial' => 0,
          'tutorial_videos' => 0,
          'video_commentary' => 0,
          'webform' => 0,
          'webinar_replay' => 0,
          'webinars' => 0,
          'white_paper_factsheet' => 0,
        ),
        'priority' => 0,
        'referenced' => array(
          'delete' => 0,
          'deny_delete' => 0,
          'deny_update' => 0,
          'deny_view' => 0,
          'update' => 0,
          'view' => 'view',
        ),
        'referenced_published' => 0,
        'unused' => 1,
        'views' => array(
          'view' => '',
          'view_args' => '',
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 5,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Category');
  t('Description');
  t('Download attachment');
  t('File date');
  t('Grant access to view this content and the attached file.');
  t('Group access');
  t('Important! Remember to press Start Upload after selecting files. Files must be fully uploaded before saving this content.');
  t('User access');

  return $field_instances;
}
