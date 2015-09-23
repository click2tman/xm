#!/usr/bin/env drush
<?php

#Disable Apigee Context

$apigee_base_theme_blocks = variable_get('context_status', array());
$apigee_base_theme_blocks['apigee_base_theme_blocks'] = TRUE;
variable_set('context_status', $apigee_base_theme_blocks);

$blog = variable_get('context_status', array());
$blog['blog'] = TRUE;
variable_set('context_status', $blog);

$home = variable_get('context_status', array());
$home['home'] = TRUE;
variable_set('context_status', $home);

$signin = variable_get('context_status', array());
$signin['signin'] = TRUE;
variable_set('context_status', $signin);

$sitewide = variable_get('context_status', array());
$sitewide['sitewide'] = TRUE;
variable_set('context_status', $sitewide);

$smartdocs_sidebar_toc = variable_get('context_status', array());
$smartdocs_sidebar_toc['smartdocs_sidebar_toc'] = TRUE;
variable_set('context_status', $smartdocs_sidebar_toc);



    
    
    
    