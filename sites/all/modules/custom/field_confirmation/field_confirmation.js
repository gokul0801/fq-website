(function($) {
  Drupal.behaviors.fieldConfirmation = {
    attach: function(context, settings) {
      if (settings.field_confirmation !== undefined) {
        $('.form-submit[value="Save"]', context).once('field-confirmation').click(function(e) {
          var message = '';
          var block_submit = false;
          $.each(settings.field_confirmation, function(i, item) {
            var $element;
            if ($(item.selector).is('textfield, textarea')) {
              $element = $(item.selector);
            }
            else if ($(item.selector).find(':checked, :selected')) {
              $element = $(item.selector).find(':checked, :selected');
            }
            else {
              // Unsupported type
              return;
            }

            // @todo: figure out how to render field values, including selects, textfields, etc
            var form_value = '';
            $element.each(function(i, item) {
              if ($(this).val() != '_none' || !$(this).val()) {
                form_value += $(this).text().trim() + "\n";
              }
            });

            if (form_value) {
              message += item.message + "\n\n" + form_value + "\n";
            }
            else if (item.required) {
              message += item.empty_message + "\n";
              block_submit = true;
            }
          });
          if (message) {
            return confirm(message) && !block_submit;
          }
          else {
            return true;
          }
        });
      }
    }
  };
})(jQuery);
