<?php
/**
 * @file
 * dev_portal_apiproducts_by_role.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function dev_portal_apiproducts_by_role_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apiproduct_role_CEP DEV';
  $strongarm->value = '';
  $export['apiproduct_role_CEP DEV'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apiproduct_role_CEP STG';
  $strongarm->value = '';
  $export['apiproduct_role_CEP STG'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apiproduct_role_ddws-enabled-products';
  $strongarm->value = '';
  $export['apiproduct_role_ddws-enabled-products'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apiproduct_role_ddws-get-invoices';
  $strongarm->value = '8,10,11,3';
  $export['apiproduct_role_ddws-get-invoices'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apiproduct_role_ddws-get-license';
  $strongarm->value = '9,8,10,11,4,3';
  $export['apiproduct_role_ddws-get-license'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apiproduct_role_ddws-get-orderDetailsAndList';
  $strongarm->value = '8,10,11,3';
  $export['apiproduct_role_ddws-get-orderDetailsAndList'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apiproduct_role_ddws-get-orders';
  $strongarm->value = '';
  $export['apiproduct_role_ddws-get-orders'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apiproduct_role_ddws-invoice';
  $strongarm->value = '8,10,11,3';
  $export['apiproduct_role_ddws-invoice'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apiproduct_role_ddws-oauth';
  $strongarm->value = '';
  $export['apiproduct_role_ddws-oauth'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apiproduct_role_DDWS-STG';
  $strongarm->value = '';
  $export['apiproduct_role_DDWS-STG'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apiproduct_role_dev-ddws-invoice';
  $strongarm->value = '3';
  $export['apiproduct_role_dev-ddws-invoice'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apiproduct_role_JacobsWeatherOauth2';
  $strongarm->value = '';
  $export['apiproduct_role_JacobsWeatherOauth2'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apiproduct_role_Legacy_APIs';
  $strongarm->value = '';
  $export['apiproduct_role_Legacy_APIs'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apiproduct_role_MojoProduct-Dev';
  $strongarm->value = '';
  $export['apiproduct_role_MojoProduct-Dev'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apiproduct_role_MojoProduct-STG';
  $strongarm->value = '';
  $export['apiproduct_role_MojoProduct-STG'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apiproduct_role_oawss';
  $strongarm->value = '';
  $export['apiproduct_role_oawss'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apiproduct_role_OrderService_Product';
  $strongarm->value = '';
  $export['apiproduct_role_OrderService_Product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apiproduct_role_PersonMaster-Dev';
  $strongarm->value = '';
  $export['apiproduct_role_PersonMaster-Dev'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apiproduct_role_sampleProductStg';
  $strongarm->value = '';
  $export['apiproduct_role_sampleProductStg'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apiproduct_role_Service-api';
  $strongarm->value = '';
  $export['apiproduct_role_Service-api'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apiproduct_role_Service-API-Product';
  $strongarm->value = '';
  $export['apiproduct_role_Service-API-Product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apiproduct_role_stg-ddws-invoice';
  $strongarm->value = '';
  $export['apiproduct_role_stg-ddws-invoice'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apiproduct_role_submitOrder_OrderService_Product';
  $strongarm->value = '';
  $export['apiproduct_role_submitOrder_OrderService_Product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apiproduct_role_Tamba Testing Prod';
  $strongarm->value = '';
  $export['apiproduct_role_Tamba Testing Prod'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apiproduct_role_testpocsfdcoauth';
  $strongarm->value = '';
  $export['apiproduct_role_testpocsfdcoauth'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apiproduct_role_Testprdod';
  $strongarm->value = '';
  $export['apiproduct_role_Testprdod'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apiproduct_role_Tibco_SOAP_APIs';
  $strongarm->value = '';
  $export['apiproduct_role_Tibco_SOAP_APIs'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apiproduct_role_UnitTestProduct';
  $strongarm->value = '';
  $export['apiproduct_role_UnitTestProduct'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apiproduct_role_UserService Dev';
  $strongarm->value = '';
  $export['apiproduct_role_UserService Dev'] = $strongarm;

  return $export;
}
