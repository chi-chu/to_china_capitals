/*
  +----------------------------------------------------------------------+
  | PHP Version 7                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2018 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_to_china_capitals.h"

#include <wchar.h>
#include <locale.h>

/* If you declare any globals in php_to_china_capitals.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(to_china_capitals)
*/

/* True global resources - no need for thread safety here */
static int le_to_china_capitals;

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("to_china_capitals.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_to_china_capitals_globals, to_china_capitals_globals)
    STD_PHP_INI_ENTRY("to_china_capitals.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_to_china_capitals_globals, to_china_capitals_globals)
PHP_INI_END()
*/
/* }}} */

/* Remove the following function when you have successfully modified config.m4
   so that your module can be compiled into PHP, it exists only for testing
   purposes. */

/* Every user-visible function in PHP should document itself in the source */
/* {{{ proto string confirm_to_china_capitals_compiled(string arg)
   Return a string to confirm that the module is compiled in */
PHP_FUNCTION(to_china_capitals)
{	
	double innum;
	zend_string *strg;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "d", &innum) == FAILURE) {
		RETURN_FALSE;
	}
	int numcount = 0,flag = 0;
        unsigned long long_innum, temp_long_innum;
        double tempdouble = 1.0;
        wchar_t cstrs[] = {0x96F6,0x58F9,0x8D30,0x53C4,0x8086,0x4F0D,0x9678,0x67D2,0x634C,0x7396};
        wchar_t bit[] = {0x5706,0x62FE,0x4F70,0x4EDF,0x842C,0x62FE,0x4F70,0x4EDF,0x5104,0x62FE,0x4F70,0x4EDF,0x842C,0x62FE};
        setlocale(LC_ALL, "");
        if(innum >= 1){
            while(tempdouble < innum){
                tempdouble *= 10;
                numcount++;
            }
            tempdouble /= 10;
            long_innum = (unsigned long)innum;
            while(tempdouble >= 1){
                temp_long_innum = (unsigned long)long_innum / tempdouble;
                flag = temp_long_innum % 10;
                printf("%lc", cstrs[flag]);
                --numcount;
                if(flag != 0){
                    printf("%lc", bit[numcount]);
                }
                tempdouble = tempdouble/10;
            }
        }
        printf("%lc%lc", cstrs[(long int)(innum*10)%10], 0x89D2);
        printf("%lc%lc", cstrs[(long int)(innum*10)%10], 0x5206);
}
/* }}} */
/* The previous line is meant for vim and emacs, so it can correctly fold and
   unfold functions in source code. See the corresponding marks just before
   function definition, where the functions purpose is also documented. Please
   follow this convention for the convenience of others editing your code.
*/


/* {{{ php_to_china_capitals_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_to_china_capitals_init_globals(zend_to_china_capitals_globals *to_china_capitals_globals)
{
	to_china_capitals_globals->global_value = 0;
	to_china_capitals_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(to_china_capitals)
{
	/* If you have INI entries, uncomment these lines
	REGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(to_china_capitals)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(to_china_capitals)
{
#if defined(COMPILE_DL_TO_CHINA_CAPITALS) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(to_china_capitals)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(to_china_capitals)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "to_china_capitals support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */

/* {{{ to_china_capitals_functions[]
 *
 * Every user visible function must have an entry in to_china_capitals_functions[].
 */
const zend_function_entry to_china_capitals_functions[] = {
	PHP_FE(to_china_capitals,	NULL)		/* For testing, remove later. */
	PHP_FE_END	/* Must be the last line in to_china_capitals_functions[] */
};
/* }}} */

/* {{{ to_china_capitals_module_entry
 */
zend_module_entry to_china_capitals_module_entry = {
	STANDARD_MODULE_HEADER,
	"to_china_capitals",
	to_china_capitals_functions,
	PHP_MINIT(to_china_capitals),
	PHP_MSHUTDOWN(to_china_capitals),
	PHP_RINIT(to_china_capitals),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(to_china_capitals),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(to_china_capitals),
	PHP_TO_CHINA_CAPITALS_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_TO_CHINA_CAPITALS
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(to_china_capitals)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
