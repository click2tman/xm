/*
  This is the javascript file that will contain all the custom javascript code that you will be writing to customize the interactivity of the Apigee developer portal.
*/

jQuery(document).ready(function($) {
    jQuery('#api_product input[type="radio"]:checked').next().addClass('checked');
    
    // Radio Checked
    jQuery('#api_product label').mousedown(function(){
        $(this).parent().parent().children('div').children('label').each(function(){
            $(this).removeClass('checked');
            jQuery('#api_product input[type="radio"]').attr('checked',false);
        });
        $(this).prev().attr('checked',true)
        $(this).addClass('checked');
    });
  
  jQuery('#api_product > div').matchHeight({
        byRow: false,
        property: 'height',
        target: null,
        remove: false
    });
  
  jQuery('.view-display-id-block_1 .col-lg-4 > div').matchHeight({
        byRow: false,
        property: 'height',
        target: null,
        remove: false
    });
  
});
