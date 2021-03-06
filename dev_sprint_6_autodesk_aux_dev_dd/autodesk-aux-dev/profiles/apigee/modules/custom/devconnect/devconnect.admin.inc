<?php

use Apigee\Exceptions\ResponseException;
use Apigee\Util\OrgConfig;
use Apigee\ManagementAPI\Organization;

define('DEVCONNECT_SHOW_CONFIG_FIELDS', FALSE);

function devconnect_admin_form($form, &$form_state) {
  $original_org_settings = devconnect_get_org_settings();
  if (isset($form_state['input']['org_settings'])) {
    $org_settings = $form_state['input']['org_settings'][0];
    if (empty($org_settings['user']) && !empty($original_org_settings['user'])) {
      $org_settings['user'] = $original_org_settings['user'];
    }
    if (empty($org_settings['pass']) && !empty($original_org_settings['pass'])) {
      $org_settings['pass'] = $original_org_settings['pass'];
    }
  }
  else {
    $org_settings = $original_org_settings;
  }

  $form['original_org_settings'] = array(
    '#type' => 'value',
    '#value' => $org_settings
  );

  $form['connection_config_container'] = array(
    '#title' => t('Connection Configuration'),
    '#type' => 'fieldset',
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
    '#id' => 'edit-connection-config-container',
    'org_settings' => array(
      '#tree' => TRUE,
    )
  );
  $element =& $form['connection_config_container']['org_settings'][0];
  if (DEVCONNECT_SHOW_CONFIG_FIELDS || empty($org_settings['org']) || isset($form_state['input']['org_settings'])) {
    $element['org'] = array(
      '#type' => 'textfield',
      '#title' => t('Management API Organization'),
      '#required' => TRUE,
      '#default_value' => $org_settings['org'],
      '#description' => t('The v4 product organization name. Changing this value could make your site not work.'),
      '#weight' => -6
    );
    $element['endpoint'] = array(
      '#type' => 'textfield',
      '#title' => t('Management API Endpoint URL'),
      '#required' => TRUE,
      '#default_value' => $org_settings['endpoint'],
      '#description' => t('URL to which to make Edge REST calls.'),
      '#weight' => -5
    );

    $element['user'] = array(
      '#type' => 'textfield',
      '#title' => t('Endpoint Authenticated User'),
      '#required' => FALSE,
      '#default_value' => '',
      '#description' => t('User name used when authenticating with the endpoint. Generally this takes the form of an email address.  (Only enter it if you want to change the existing user.)'),
      '#weight' => -4,
      '#attributes' => array('autocomplete' => 'off'),
    );

    $element['pass'] = array(
      '#type' => 'textfield',
      '#title' => t('Authenticated User’s Password'),
      '#required' => FALSE,
      '#default_value' => '',
      '#description' => t('Password used when authenticating with the endpoint. (Only enter it if you want to change the existing password.)'),
      '#weight' => -3,
      '#post_render' => array('devconnect_password_post_render'),
      '#attributes' => array('autocomplete' => 'off'),
    );
  }
  else {
    $element['org'] = array(
      '#type' => 'item',
      '#title' => t('Management API Organization'),
      '#markup' => (empty($org_settings['org']) ? '<span style="color:red">' . t('No value') . '</span>' : $org_settings['org']),
    );
    $element['endpoint'] = array(
      '#type' => 'item',
      '#title' => t('Management API Endpoint URL'),
      '#markup' => (empty($org_settings['endpoint']) ? '<span style="color:red">' . t('No value') . '</span>' : $org_settings['endpoint']),
    );
    if (empty($org_settings['user'])) {
      $element['user'] = array(
        '#type' => 'item',
        '#title' => t('Endpoint Authenticated User'),
        '#markup' => '<span style="color:red">' . t('No value') . '</span>',
      );
    }
    if (empty($org_settings['pass'])) {
      $element['user'] = array(
        '#type' => 'item',
        '#title' => t('Authenticated User’s Password'),
        '#markup' => '<span style="color:red">' . t('No value') . '</span>',
      );
    }
  }

  if (array_key_exists('connection_timeout', $org_settings)) {
    $conn_timeout = intval($org_settings['connection_timeout']);
    if ($conn_timeout < 1) {
      $conn_timeout = 8;
    }
  }
  else {
    $conn_timeout = 4;
  }
  if (array_key_exists('request_timeout', $org_settings)) {
    $req_timeout = intval($org_settings['request_timeout']);
    if ($req_timeout < 1) {
      $req_timeout = 8;
    }
  }
  else {
    $req_timeout = 4;
  }

  $form['connection_config_container']['connection_timeout'] = array(
    '#type' => 'textfield',
    '#title' => t('Connection Timeout'),
    '#required' => TRUE,
    '#default_value' => $conn_timeout,
    '#description' => t('Number of seconds before an HTTP connection to Edge is assumed to have timed out.'),
    '#weight' => 10,
    '#post_render' => array('devconnect_number_post_render')
  );

  $form['connection_config_container']['request_timeout'] = array(
    '#type' => 'textfield',
    '#title' => t('Request Timeout'),
    '#required' => TRUE,
    '#default_value' => $req_timeout,
    '#description' => t('Number of seconds before an HTTP response from Edge is assumed to have timed out.'),
    '#weight' => 11,
    '#post_render' => array('devconnect_number_post_render')
  );

  $default_log_threshold = (array_key_exists('log_threshold', $org_settings) ? intval($org_settings['log_threshold']) : WATCHDOG_WARNING);

  $form['connection_config_container']['log_threshold'] = array(
    '#type' => 'radios',
    '#title' => t('Edge logging threshold'),
    '#description' => t('Controls what baseline level of Edge output should be written to the logs.'),
    '#required' => TRUE,
    '#default_value' => $default_log_threshold,
    '#options' => array(
      WATCHDOG_DEBUG => 'Debug',
      WATCHDOG_INFO => 'Info',
      WATCHDOG_NOTICE => 'Notice',
      WATCHDOG_WARNING => 'Warning',
      WATCHDOG_ERROR => 'Error',
      WATCHDOG_CRITICAL => 'Critical',
      WATCHDOG_ALERT => 'Alert',
      WATCHDOG_EMERGENCY => 'Emergency'
    ),
    '#weight' => 12
  );

  if (empty($org_settings['org'])) {
    $status = '';
  }
  else {
    $status = _devconnect_test_kms_connection($org_settings['org'], $org_settings['endpoint'], $org_settings['user'], $org_settings['pass'], $conn_timeout);
  }

  if (DEVCONNECT_SHOW_CONFIG_FIELDS || empty($org_settings['org']) || isset($form_state['input']['org_settings'])) {
    $form['connection_config_container']['connect_test'] = array(
      '#type' => 'fieldset',
      '#title' => t('Test Configuration'),
      '#weight' => 9,
      '#prefix' => '<br><br>',
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );

    $form['connection_config_container']['connect_test']['test_connection'] = array(
      '#name' => 'test_connection',
      '#type' => 'button',
      '#limit_validation_errors' => array(),
      '#value' => t('Test Connection'),
      '#ajax' => array(
        'callback' => '_devconnect_test_management_connection_ajax',
        'wrapper' => 'test-connect-result',
        'method' => 'replace',
        'effect' => 'fade',
      ),
      '#states' => array(
        'disabled' => array(
          ':input[name="org_settings[0][org]"]' => array('empty' => TRUE),
        ),
      ),
    );
    $form['connection_config_container']['connect_test']['test_connection_status'] = array(
      '#prefix' => '<div id="test-connect-result"><br>',
      '#suffix' => '</div>',
      '#markup' => $status,
    );
  }
  else {
    $form['connection_config_container']['test_connection_status'] = array(
      '#weight' => 9,
      '#type' => 'item',
      '#title' => t('Connection Status'),
      '#markup' => $status
    );
  }

  $modules = module_implements('variable_info');
  sort($modules); // sort by name.
  $my_variables = array();
  foreach ($modules as $module) {
    if (substr($module, 0, 10) == 'devconnect') {
      $my_variables += call_user_func($module . '_variable_info');
    }
  }

  $weight = 0;

  $form['devconnect_config_container'] = array(
    '#title' => t('Dev Portal Configuration'),
    '#type' => 'fieldset',
  );

  foreach ($my_variables as $name => $info) {
    $default = (isset($info['default'])) ? $info['default'] : '';
    $default_value = variable_get($name, $default);
    $form_element = array();
    if ($info['type'] == 'boolean') {
      $form_element['#type'] = 'checkbox';
      $form_element['#default_value'] = intval($default_value);
      $form_element['#return_value'] = 1;
    }
    elseif ($info['type'] == 'select') {
      $form_element['#default_value'] = $default_value;
      if ((!isset($info['options']) || !is_array($info['options'])) && (isset($info['options callback']) && is_callable($info['options callback']))) {
        $form_element['#options'] = call_user_func($info['options callback']);
      }
      else {
        $form_element['#options'] = $info['options'];
      }
      // If configured default value is not a valid option, but the
      // hook_variable_info default is, use the hook_variable_info value.
      if (!array_key_exists($default_value, $form_element['#options'])) {
        if (array_key_exists($default, $form_element['#options'])) {
          $form_element['#default_value'] = $default;
        }
        else {
          // Choose the first option as a default.
          $option_values = array_keys($form_element['#options']);
          if (count($option_values) > 0) {
            $form_element['#default_value'] = $option_values[0];
          }
        }
      }
      if (count($form_element['#options']) < 7) {
        $form_element['#type'] = 'radios';
      }
      else {
        $form_element['#type'] = 'select';
      }
    }
    else {
      $form_element['#type'] = 'textfield';
      $form_element['#default_value'] = $default_value;
    }
    $form_element['#title'] = $info['title'];
    if (isset($info['description'])) {
      $form_element['#description'] = $info['description'];
    }
    if (isset($info['required'])) {
      $form_element['#required'] = $info['required'];
    }
    $form_element['#weight'] = $weight++;
    $form_element['#suffix'] = '<br/>';

    if (strpos($name, 'monetization') !== FALSE) {
      $set = 'monetization_config';
    }
    else {
      $set = 'devconnect_config';
    }
    $form[$set . '_container'][$name] = $form_element;
  }

  $form = system_settings_form($form);
  $form['#submit'] = array('devconnect_admin_form_submit');
  return $form;
}

function devconnect_admin_form_submit($form, &$form_state) {
  $changes = array();
  // Read existing settings. These are our comparison baseline.
  $existing_config = devconnect_get_org_settings();
  // Prepare for new configuration.
  // Make sure we have some default values present.
  $form_state['values'] += array('connection_timeout' => 8, 'request_timeout' => 8, 'log_threshold' => 3);
  $new_config = array(
    'connection_timeout' => intval($form_state['values']['connection_timeout']),
    'request_timeout' => intval($form_state['values']['request_timeout']),
    'log_threshold' => intval($form_state['values']['log_threshold'])
  );

  // Set default org settings
  if (isset($form_state['values']['org_settings'][0])) {
    $default_org = $form_state['values']['org_settings'][0];
  }
  else {
    // This should never happen!
    $default_org = array();
  }
  foreach (array('org', 'endpoint', 'user', 'pass') as $field) {
    $hide_field_in_log = FALSE;
    if ($form['connection_config_container']['org_settings'][0]['org']['#type'] == 'textfield') {
      // Pull user/pass values from existing config if fields are empty.
      if (($field == 'user' || $field == 'pass') && empty($default_org[$field])) {
        $new_config[$field] = $existing_config[$field];
      }
      // Use value from $form_state only if non-blank
      elseif (array_key_exists($field, $default_org) && !empty($default_org[$field])) {
        $new_config[$field] = $default_org[$field];
      }
      // Otherwise, pull from existing config.
      else {
        $new_config[$field] = $existing_config[$field];
      }
      if ($field == 'pass' || $field == 'user') {
        $hide_field_in_log = TRUE;
      }
    }
    else {
      $new_config[$field] = $existing_config[$field];
      $hide_field_in_log = TRUE;
    }

    if ($new_config[$field] != $existing_config[$field]) {
      $old_value = (empty($existing_config[$field]) ? '*empty*' : ($hide_field_in_log ? '*hidden*' : $existing_config[$field]));
      $new_value = (empty($new_config[$field]) ? '*empty*' : ($hide_field_in_log ? '*hidden*' : $new_config[$field]));
      $changes["Default Connection: $field"] = array($old_value, $new_value);
    }
  }

  $default_private_dir = variable_get('file_private_path', 'sites/default/files/private');
  $private_dir = variable_get('apigee_credential_dir', $default_private_dir);

  if(substr($private_dir,0,1) == '/') {
    $config_file = $private_dir . '/.apigee';
  } else {
    $config_file = DRUPAL_ROOT . '/' . $private_dir . '/.apigee';
  }

  $settings_success = file_put_contents($config_file, Drupal\devconnect\Crypto::encrypt(serialize($new_config)));
  @chmod($config_file, 0666);

  if (isset($form_state['values']['devconnect_user_tnc_url'])) {
    $old_url = _devconnect_user_get_tnc_url();
    $new_url = $form_state['values']['devconnect_user_tnc_url'];
    if ($new_url != $old_url) {
      $changes['Terms & Conditions URL'] = array($old_url, $new_url);
      variable_set('devconnect_user_tnc_url', $new_url);
      // Refresh the footer block, since it contains a link to this URI.
      cache_clear_all('devconnect_default_structure:footer', 'cache_block', TRUE);
    }
  }
  if (!$settings_success) {
    drupal_set_message(t('An error occurred, and your connection settings were not saved.'), 'error');
    watchdog('devconnect', 'Failed to write connection settings to file :file', array(':file' => $config_file), WATCHDOG_ERROR);
  }

  if (!empty($changes)) {
    $change_items = array();
    foreach ($changes as $key => $values) {
      $change_items[] = "$key was changed from “" . $values[0] . '” to “' . $values[1] . '”';
    }
    $message = 'The following authentication configuration items were changed: ' . join(',', $change_items);
    watchdog('devconnect', $message, array(), WATCHDOG_INFO);

    try {
      $org = new Organization(devconnect_default_org_config());
      $org->load($new_config['org']);
      $is_paging_enabled = ($org->getProperty('features.isCpsEnabled') === 'true');
      variable_set('devconnect_paging_enabled', $is_paging_enabled);
    }
    catch (Exception $e) {
    }
  }

  drupal_set_message(t('Your changes have been saved.'), 'status');
}

function devconnect_password_post_render($content, $element) {
  return str_replace('type="text"', 'type="password"', $content);
}

function devconnect_number_post_render($content, $element) {
  return str_replace('type="text"', 'type="number" style="width:3em !important"', $content);
}


/**
 * Ajax Callback for Testing the Edge Connection
 */
function _devconnect_test_management_connection_ajax($form, &$form_state) {
  return $form['connection_config_container']['connect_test']['test_connection_status'];
}


/**
 * Test connection with the Management server
 *
 * @param string $org - Organization that user has supplied
 * @param string $endpoint - Endpoint that user has supplied
 * @param string $user - Username that the user has supplied
 * @param string $pass - Password (unencrypted) that the user has supplied
 * @param int $timeout - Number of seconds until connection timeout, or zero for infinite
 * @return string
 */
function _devconnect_test_kms_connection($org, $endpoint, $user, $pass, $timeout = 4) {
  if (!valid_url($endpoint)) {
    return '<span style="color:red">' . t('Invalid endpoint') . '</span>';
  }
  // Make sure timeout does not exceed 8 seconds, or failure ensues.
  $timeout = intval(min($timeout, 8));
  // Zero timeout is infinite; big problem.
  if ($timeout < 1) {
    $timeout = 4;
  }

  $options = array(
    'http_options' => array(
      'connection_timeout' => $timeout,
      'follow_location' => FALSE,
    )
  );

  $config = new OrgConfig($org, $endpoint, $user, $pass, $options);
  $org = new Organization($config);

  try {
    $org->load();
    return '<span style="color:green">' . t('Connection Successful') . '</span>';
  } catch (ResponseException $e) {
    // Give a nicer message if the user/pass is incorrect.
    if ($e->getCode() == 401) {
      $message = t('Edge Endpoint responded with 401 Unauthorized. Check the username and password.');
      return '<span style="color:red">' . $message . '</span>';
    }

    // If the user put in a non HTTPS endpoint, give them a hint that they may
    // want to use HTTPS instead.
    if(substr($endpoint, 0, 5) != 'https') {
      $message_try_ssl = t('DevPortal Endpoint may be SSL enabled. Try using <strong><em>@endpoint</em></strong> instead.',
        array('@endpoint' => str_replace('http', 'https', $endpoint))
      );
    }

    // See if we get a response from server to get a better idea what happened.
    $response_text = $e->getResponse();
    if (!empty($response_text)) {
      $message = t('Edge connection unsuccessful. HTTP code: %error_code, server response: %server_response',
        array(
          '%error_code' => $e->getCode(),
          '%server_response' => $e->getResponse(),
        )
      );
      return '<span style="color:red">' . $message . '</span> ' . $message_try_ssl;
    }

    // We have no response, show the error code.
    $message = t('Edge connection unsuccessful. HTTP code: %error_code',
      array(
        '%error_code' => $e->getCode(),
      )
    );
    return '<span style="color:red">' . $message . '</span> ' . $message_try_ssl;
  }
}
