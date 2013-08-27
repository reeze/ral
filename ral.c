/*
  +----------------------------------------------------------------------+
  | RAL                                                                  |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2012 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: Reeze Xia <reeze@php.net>                                    |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_ral.h"

/* If you declare any globals in php_ral.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(ral)
*/

/* True global resources - no need for thread safety here */
static int le_ral;

/* {{{ ral_functions[]
 */
const zend_function_entry ral_functions[] = {
	PHP_FE_END
};
/* }}} */

/* {{{ ral_module_entry
 */
zend_module_entry ral_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"ral",
	ral_functions,
	PHP_MINIT(ral),
	PHP_MSHUTDOWN(ral),
	PHP_RINIT(ral),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(ral),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(ral),
#if ZEND_MODULE_API_NO >= 20010901
	RAL_VERSION,
#endif
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_RAL
ZEND_GET_MODULE(ral)
#endif

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("ral.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_ral_globals, ral_globals)
    STD_PHP_INI_ENTRY("ral.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_ral_globals, ral_globals)
PHP_INI_END()
*/
/* }}} */

/* {{{ php_ral_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_ral_init_globals(zend_ral_globals *ral_globals)
{
	ral_globals->global_value = 0;
	ral_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(ral)
{
	REGISTER_INI_ENTRIES();
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(ral)
{
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(ral)
{
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(ral)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(ral)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "ral support", "enabled");
	php_info_print_table_header(2, "ral extension version", RAL_VERSION);
	php_info_print_table_end();

	DISPLAY_INI_ENTRIES();
}
/* }}} */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
