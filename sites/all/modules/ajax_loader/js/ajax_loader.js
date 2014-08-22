(function($,window) {
  window.initialUrl = window.location.href.split("#")[0];
  var popping = false;
  window.onpopstate = function (event) {
    var state = event.state;
    if( window.location.href.split("#")[0] == window.initialUrl){
      //history.pushState(null, null, window.location.href);
      return;
    }
    var onloadPop = !Drupal.settings.ajax_loader.pushed && window.location.href.split("#")[0] == window.initialUrl;
    if(onloadPop || popping) return;
    popping = true;
    window.history.go(0);
  };

  Drupal.behaviors.ajax_loader = {
    attach: function(context) {
      if(Drupal.settings.ajax_loader.ajax_nav && history && history.pushState!==undefined) {
        var newUrl = (window.nextHash) ? Drupal.settings.ajax_loader.path + '#' + window.nextHash : Drupal.settings.ajax_loader.path;
        history.pushState(null, null, newUrl);
        Drupal.settings.ajax_loader.ajax_nav = false;
        window.initialUrl = window.location.href.split("#")[0];
        popping = false;
        if( window.nextHash && window.scrollToId)
          setTimeout(function(){
            if(window.scrolling) {
              $('body').stop();
              window.scrolling=false;
            }
            window.scrollToId();
          },50);
      }
    }
  };
})(jQuery,window);