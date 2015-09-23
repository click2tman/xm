<?php
/**
 * @file
 * devportal_company.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function devportal_company_default_rules_configuration() {
  $items = array();
  $items['rules_always_redirect_to_list_of_developers_view_after_creation'] = entity_import('rules_config', '{ "rules_always_redirect_to_list_of_developers_view_after_creation" : {
      "LABEL" : "Always Redirect to list of developers view after creation",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Company" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_insert" : [] },
      "IF" : [
        { "user_has_role" : {
            "account" : [ "account" ],
            "roles" : { "value" : { "5" : "5" } },
            "operation" : "OR"
          }
        }
      ],
      "DO" : [
        { "redirect" : { "url" : "\\/admin\\/workbench\\/developers-and-associated-companies" } }
      ]
    }
  }');
  $items['rules_assign_company_role'] = entity_import('rules_config', '{ "rules_assign_company_role" : {
      "LABEL" : "Assign Company Role",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Company" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_insert" : [] },
      "IF" : [
        { "user_has_role" : {
            "account" : [ "site:current-user" ],
            "roles" : { "value" : { "5" : "5" } },
            "operation" : "OR"
          }
        },
        { "data_is" : { "data" : [ "account:field-user-account-types" ], "value" : "Company" } }
      ],
      "DO" : [
        { "user_add_role" : { "account" : [ "account" ], "roles" : { "value" : { "4" : "4" } } } }
      ]
    }
  }');
  $items['rules_assign_developer_role'] = entity_import('rules_config', '{ "rules_assign_developer_role" : {
      "LABEL" : "Assign External Direct Developer Role",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Company" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_insert" : [] },
      "IF" : [
        { "user_has_role" : {
            "account" : [ "site:current-user" ],
            "roles" : { "value" : { "5" : "5" } },
            "operation" : "OR"
          }
        },
        { "data_is" : {
            "data" : [ "account:field-user-account-types" ],
            "value" : "Partner Developer"
          }
        },
        { "data_is" : {
            "data" : [ "account:field-ref-company-name:field-company-partner-type" ],
            "value" : "Direct"
          }
        }
      ],
      "DO" : [
        { "user_add_role" : { "account" : [ "account" ], "roles" : { "value" : { "8" : "8" } } } }
      ]
    }
  }');
  $items['rules_assign_external_indirect_developer_role'] = entity_import('rules_config', '{ "rules_assign_external_indirect_developer_role" : {
      "LABEL" : "Assign External Indirect Developer Role",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Company" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_insert" : [] },
      "IF" : [
        { "user_has_role" : {
            "account" : [ "site:current-user" ],
            "roles" : { "value" : { "5" : "5" } },
            "operation" : "OR"
          }
        },
        { "data_is" : {
            "data" : [ "account:field-user-account-types" ],
            "value" : "Partner Developer"
          }
        },
        { "data_is" : {
            "data" : [ "account:field-ref-company-name:field-company-partner-type" ],
            "value" : "Indirect"
          }
        }
      ],
      "DO" : [
        { "user_add_role" : { "account" : [ "account" ], "roles" : { "value" : { "9" : "9" } } } }
      ]
    }
  }');
  $items['rules_assign_partner_admin_role'] = entity_import('rules_config', '{ "rules_assign_partner_admin_role" : {
      "LABEL" : "Assign Partner Admin Role",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Company" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_insert" : [] },
      "IF" : [
        { "user_has_role" : {
            "account" : [ "site:current-user" ],
            "roles" : { "value" : { "5" : "5" } },
            "operation" : "OR"
          }
        },
        { "data_is" : {
            "data" : [ "account:field-user-account-types" ],
            "value" : "Partner Admin"
          }
        }
      ],
      "DO" : [
        { "user_add_role" : { "account" : [ "account" ], "roles" : { "value" : { "11" : "11" } } } },
        { "mail" : {
            "to" : "[account:mail]",
            "subject" : "Autodesk has created an account for you at [site:name]",
            "message" : "\\u003Cp\\u003E[account:name-raw],\\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003EAn Autodesk Partner Development Portal administrator has created an account for you. \\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EYou may now log in by clicking this link or copying and pasting it to your browser:\\r\\n[user:one-time-login-url]\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EThis link can only be used once to log in and will lead you to a page where you can set your password. \\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EAfter setting your password, you will be able to log in at [site:login-url] in the future using:\\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003Eusername: [user:name]\\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003Epassword: Your password\\u003C\\/p\\u003E",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  return $items;
}
