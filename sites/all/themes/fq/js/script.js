var IE = (function () {
  "use strict";

  var ret, isTheBrowser,
    actualVersion,
    jscriptMap, jscriptVersion;

  isTheBrowser = false;
  jscriptMap = {
    "5.5": "5.5",
    "5.6": "6",
    "5.7": "7",
    "5.8": "8",
    "9": "9",
    "10": "10"
  };
  jscriptVersion = new Function("/*@cc_on return @_jscript_version; @*/")();

  if (jscriptVersion !== undefined) {
    isTheBrowser = true;
    actualVersion = jscriptMap[jscriptVersion];
  }

  ret = {
    isTheBrowser: isTheBrowser,
    actualVersion: actualVersion
  };

  return ret;
}());

/**
* @file
* A JavaScript file for the theme.
*
* In order for this JavaScript to be loaded on pages, see the instructions in
* the README.txt next to this file.
*/

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - http://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {
  //menu drop downs
  function hamburger(state){
    $('.submenu').removeClass('submenu-open');
    $('label[for="people_radio"], label[for="strategy_radio"]').removeClass('active_menu');
    if(state == false){
      $('.hamburger-wrapper').addClass('hamburger-open');
      $('.custom-hamburger-section').addClass('active_menu');
    }else{
      $('.hamburger-wrapper').removeClass('hamburger-open');
      $('.custom-hamburger-section').removeClass('active_menu');
    }
  }

  function people_hover(state){
    $('.submenu').removeClass('submenu-open');
    $('.hamburger-wrapper').removeClass('hamburger-open');
    $('label[for="strategy_radio"], .custom-hamburger-section, #user_login').removeClass('active_menu');
    $('.people_submenu').addClass('submenu-open');
    $('label[for="people_radio"]').addClass('active_menu');
  }

  function people_click(state){
    if(state == false){
      $('.submenu').removeClass('submenu-open');
      $('.hamburger-wrapper').removeClass('hamburger-open');
      $('label[for="strategy_radio"], .custom-hamburger-section, #user_login').removeClass('active_menu');
      $('.people_submenu').addClass('submenu-open');
      $('label[for="people_radio"]').addClass('active_menu');
    }else{
      $('.people_submenu').removeClass('submenu-open');
      $('label[for="people_radio"], .custom-hamburger-section, #user_login').removeClass('active_menu');
    }
  }

  function strategy_hover(state){
    $('.submenu').removeClass('submenu-open');
    $('.hamburger-wrapper').removeClass('hamburger-open');
    $('label[for="people_radio"], .custom-hamburger-section, #user_login').removeClass('active_menu');
    $('.strategy_submenu').addClass('submenu-open');
    $('label[for="strategy_radio"]').addClass('active_menu');
  }

  function strategy_click(state){
    if(state == false){
      $('.submenu').removeClass('submenu-open');
      $('.hamburger-wrapper').removeClass('hamburger-open');
      $('label[for="people_radio"], .custom-hamburger-section, #user_login').removeClass('active_menu');
      $('.strategy_submenu').addClass('submenu-open');
      $('label[for="strategy_radio"]').addClass('active_menu');
    }else{
      $('.strategy_submenu').removeClass('submenu-open');
      $('label[for="strategy_radio"], .custom-hamburger-section, #user_login').removeClass('active_menu');
    }
  }

  function user_login_hover(state){
    $('.submenu').removeClass('submenu-open');
    $('.hamburger-wrapper').removeClass('hamburger-open');
    $('label[for="people_radio"], label[for="strategy_radio"]').removeClass('active_menu');
    $('#user_login').addClass('active_menu');
  }


  function insights(insights_closed){
    console.log(insights_closed);
    if(insights_closed == true){
      $('.bigger_on_the_inside').removeClass('insights-closed');
    }else{
      $('.bigger_on_the_inside').addClass('insights-closed');
    }
  }

  //close open menu
  function close_menu(){
    $('.submenu').removeClass('submenu-open');
    $('.hamburger-wrapper').removeClass('hamburger-open');
    $('label[for="strategy_radio"], .custom-hamburger-section, label[for="people_radio"]').removeClass('active_menu');
  }

  /*
      Background slider
   */
  var i_slide = 0;
  function slider(direction){
    if(i_slide == 0){
      $('#prev').removeClass('terminus');
      i_slide++
    }
    var $c = $('.view-homepage .view-content')[0];
    if($c==undefined) return;
    position_before = $c.style.left;
    var position = parseInt(position_before.replace('%',''));
    if(direction == 'next'){// removed && position > '-200'
      new_position = position - 100;
      $('.view-homepage .view-content').css('left', new_position + '%');
    }else if(direction == 'prev' && position < 0){
      new_position = position + 100;
      $('.view-homepage .view-content').css('left', new_position + '%');
    }else if(direction == 'first'){
      $('.view-homepage .view-content').css('left','0%');
    }
    slider_button_hider();
  }
  
  var autoscrolldirection = 'next'; //set default autoscroll direction
  
  function slider_button_hider(){
    var $c = $('.view-homepage .view-content')[0];
    if($c==undefined) return;
    position_after = $c.style.left;
    var position = parseInt(position_after.replace('%',''));
    var slides = $('.slideshow-wrapper .view-content').children().size();
    var far_right = -((slides*100)-100);
    if(position == far_right){
      $('#next:not(.terminus)').addClass('terminus');
      autoscrolldirection = 'first'; //auto scroll return to first slide from last
    }else{
      $('#next').removeClass('terminus');
      autoscrolldirection = 'next'; //keep original auto scroll direction
    }
    if(position == '0'){
      $('#prev:not(.terminus)').addClass('terminus');
    }else{
      $('#prev').removeClass('terminus');
    }
  }

  //auto scroll
  function makeScroll() {
    var direction = autoscrolldirection;
	  slider(direction);
  }
  function slider_timer() { 
    slider_timer_interval = setInterval(makeScroll, 8000); //auto scroll interval, disabled on slider button click
    }

  jQuery(function(){
    if(jQuery('.slideshow-wrapper').length > 0) slider_timer();
  });




  //strategy/attribution#page
  function scrollTo(hash) {
      //location.hash = hash;
      console.log(hash);
  }

  window.newUrl     = false;
  window.nextHash   = false;
  window.scrollToId = function(){};

  //-- Begin custom hash scroll hook --//
  (function($,scope,win,Drupal){

    //$(win).scroll(function(){
    //  lastWinPos = $(win).scrollTop();
    //});
    var lastWinPos = 0;

    var lastHash = false;
    window.scrolling = false;

    window.scrollToId = function(ol){

      if(window.scrolling) return;
      var id = window.location.hash.substring(1);
      window.scrolling = true;

      var $tag = $("#"+id);
      if($tag.length > 0) {
        var dest=0;
        if($tag.offset().top > $(scope).height()-$(win).height()){
          dest=$(scope).height()-$(win).height();
        }else{
          dest=$tag.offset().top;
        }

        var scrollTop = $(win).scrollTop();
        var timing = (dest>scrollTop) ? (dest - scrollTop) : (scrollTop - dest);
        timing *= 1.25;

        setTimeout(function(){
          scrolling=false;
        },timing+250);

        if(ol) $(win).scrollTop(0);
        //else $(win).scrollTop(lastWinPos);

        jQuery('body').trigger('click');
        dest = (dest-160<0) ? dest : dest-160;

        if( id=="top" ) dest = 0;

        $('body').animate({scrollTop:dest}, timing,function(){
          lastHash = id;
          setTimeout(function(){
            window.nextHash = false;
            window.scrolling = false;
          },50);
        });
      }
    };


    $(win).bind('hashchange', function(event){
      $('html,body').stop();
      event.preventDefault();
      if(!scrolling) {
        scrollToId();
      } else {
        $('html, body').stop();
        window.scrolling = false;
        scrollToId();
      }
    });

    $(function(){

      function resizeBackground() {
        var $bg = $('.background-image img');

        var h,w;
        if( $(win).height()>$(win).width() ){
          w = 'auto';
          h = '100%';
        }
        else {
          h = 'auto';
          w = '100%';
        }
        $bg.css({
          width:w,
          height:h,
          display:'block',
          position:'fixed',
          top:'0px',
          left:'0px'
        });
      };

      if(IE.isTheBrowser){
        resizeBackground();
        $(document).ajaxComplete(function(){
          resizeBackground();
        });
      }

      jQuery(window).scrollTop(0);
      if(win.location.hash){
        scrollToId(true);
      }
    });


  }(jQuery,document,window,Drupal));


  //lastHash = win.location.hash;
  if(document && document.body)
    jQuery(window).scrollTop(0);
  else
  $(function(){
    jQuery(window).scrollTop(0);
  });
  //-- End custom hash scroll hook --//


Drupal.behaviors.FQ = {
  attach: function(context, settings) {
    //hide header close button
    $("label[for='close_radio']").css('display','none');
    //menu listeners
    $("label[for='hamburger_radio']").bind('click touchstart', function(){hamburger($('.hamburger-wrapper').hasClass('hamburger-open')); return false;});
    $("label[for='people_radio']").bind('mouseover', function(){people_hover($('.people_submenu').hasClass('submenu-open')); return false;});
    $("label[for='strategy_radio']").bind('mouseover', function(){strategy_hover($('.strategy_submenu').hasClass('submenu-open')); return false;});
    $("#user_login").bind('mouseover', function(){user_login_hover(); return false;});
    $("label[for='people_radio']").bind('click touchstart', function(){people_click($('.people_submenu').hasClass('submenu-open')); return false;});
    $("label[for='strategy_radio']").bind('click touchstart', function(){strategy_click($('.strategy_submenu').hasClass('submenu-open')); return false;});
    //slider buttons
    //$('#prev').bind('click', function(){ var direction = 'first'; slider(direction); clearInterval(slider_timer_interval); return false; });
    $('#prev').bind('click', function(){ var direction = 'prev'; slider(direction); clearInterval(slider_timer_interval); return false; });
    $('#next').bind('click', function(){ var direction = 'next'; slider(direction); clearInterval(slider_timer_interval); return false; });
    //insights pop up
    $('#insights').bind('click', function(){ insights($('.bigger_on_the_inside').hasClass('insights-closed')); return false; });
    //click outside menu closes
    $('html').click(function() {close_menu();});
    $('.custom-menu-section, .custom-hamburger-section').click(function(event){event.stopPropagation();});
    //load slider images
    $(".slideshow-wrapper .view-content").load("/home-slideshow .slideshow-wrapper .view-content > *", function() {
      $('#progress-indicator').hide();
      //how many slides?
      var slides = $('.slideshow-wrapper .view-content').children().size();
      if(slides > 3){
        $('.slideshow-wrapper .view-content').css('width', slides*100+'%');
        $('.slideshow-wrapper .view-content').children().css('width', 100/slides +'%');
      }
    });//end load slider
    //strategy/attribution#page
    var href = window.location.pathname;
    if(href.indexOf("summaries-attribution") >= 0){scrollTo(window.location.hash); }
  }
};
})(jQuery, Drupal, this, this.document);






