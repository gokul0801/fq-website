////////////////////////////////////////////
//
//  jQuery Multi
//
////////////////////////////////////////////

Features:
  - run a newer version of jQuery in parallel to Drupal's without interfering with things
    that use the default jQuery version, using jQuery's built in noConflict mode
  - use the newer version of jQuery in custom scripts using the provided alias
  - configure specific libraries to use the newer jQuery
  - configure any JS file in the system to load using the newer jQuery

Installation:
  - You must place a version of the minified jQuery library in the libraries folder, so that
    the path to the actual jQuery library will be: sites/all/libraries/jquery/jquery-<version>.min.js

Usage:
  1. Enable the module
  2. Ensure you have a version of jQuery in the libraries folder
  3. Navigate to the settings page at admin/settings/jqmulti
  4. Select any libraries you want to load with the selected jQuery
  
  You can also use this module in the following ways:

  - Use the provided hooks to add files or libraries to load with jQuery Multi (see jqmulti.api.php)
  - Use the automatically provided jQuery alias in your custom scripts:
  
      Use the version of jQuery loaded by jQuery Multi in your custom scripts by referencing
      the automatically provided alias in your script closure. The alias names are
      generated using the jQuery version number, with the periods removed.
  
      For instance, if you're loading jQuery-1.7.1, the alias will be jq171, and you can
      use it in your scripts by wrapping your code as follows:
  
      (function($){
        // your code here, using jQuery 1.7.1
      })(jq171)
  
  
  NOTE: loading libraries with Jquery Multi will only load the JS files within the library. You must
  call drupal_add_css() separately to load any included CSS files that may be in the library.


TODO:
  - Add CDN support
  - Add targeting for modules and themes
  - Theme js files currently won't work at all, even using jqueries_add_file(). This needs to change
  - UI for targeting files?