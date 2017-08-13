/* __header_here__ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <mkdio.h>

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_markdown.h"

//#include <mkdio.h> /* Markdown library. We re-use and re-cycle here in *NIX.*/





/* If you declare any globals in php_extname.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(extname)
*/

/* True global resources - no need for thread safety here */
static int le_markdown;

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("extname.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_extname_globals, extname_globals)
    STD_PHP_INI_ENTRY("extname.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_extname_globals, extname_globals)
PHP_INI_END()
*/
/* }}} */

/* Remove the following function when you have successfully modified config.m4
   so that your module can be compiled into PHP, it exists only for testing
   purposes. */






/**
 * Returns the nessacary amount of bytes needed to hold a parsed (html) copy of the markdown.
 * Good to use with parse_md.
 */
size_t md_html_buffsize(const char *md, size_t md_len)
{
	
}

/**
 * Prases the markdown into html, then places it into buffer. Returns 1 on success, -1 on parse error,
 * Or, if buffer was not large enough to hold the output then 0 is returned.
 */

int parse_md(char *md, size_t md_len, char *buffer, size_t bufflen)
{
	/*MMIOT *doc = mkd_string(md, strlen(md)+1, 0);
	mkd_compile(doc, 0);
	mkd_document(doc, &text);
	mkd_cleanup(doc);*/
	
}

//markdown_tohtml(string $markdown)
PHP_FUNCTION(markdown_tohtml)
{
	char *arg = NULL;
	size_t arglen;
	char *buffer;
	size_t buflen;
	if(zend_parse_parameters(ZEND_NUM_ARGS(), "s", &arg, &arglen) == FAILURE)
		return;

	char *html;
	MMIOT *doc = mkd_string(arg, arglen, 0);
	mkd_compile(doc, 0);
	int html_size = mkd_document(doc, &html);
    
    zend_string *strg = zend_string_init(html, html_size, 0);
    mkd_cleanup(doc);
	RETURN_STR(strg); // wait shit
	return;
	
}


/* Every user-visible function in PHP should document itself in the source */
/* {{{ proto string confirm_extname_compiled(string arg)
   Return a string to confirm that the module is compiled in */
PHP_FUNCTION(confirm_markdown_compiled)
{
	char *arg = NULL;
	size_t arg_len, len;
	zend_string *strg;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "s", &arg, &arg_len) == FAILURE) {
		return;
	}

	strg = strpprintf(0, "Congratulations! You have successfully modified ext/%.78s/config.m4. Module %.78s is now compiled into PHP.", "markdown", arg);

	RETURN_STR(strg);
}
/* }}} */
/* The previous line is meant for vim and emacs, so it can correctly fold and
   unfold functions in source code. See the corresponding marks just before
   function definition, where the functions purpose is also documented. Please
   follow this convention for the convenience of others editing your code.
*/

/* __function_stubs_here__ */

/* {{{ php_extname_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_extname_init_globals(zend_extname_globals *extname_globals)
{
	extname_globals->global_value = 0;
	extname_globals->global_string = NULL;
}
*/



/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(markdown)
{
	/* If you have INI entries, uncomment these lines
	REGISTER_INI_ENTRIES();
	*/
	
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(markdown)
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
PHP_RINIT_FUNCTION(markdown)
{
#if defined(COMPILE_DL_MARKDOWN) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(markdown)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(markdown)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "markdown support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */

/* {{{ extname_functions[]
 *
 * Every user visible function must have an entry in extname_functions[].
 */
const zend_function_entry markdown_functions[] = {
	PHP_FE(confirm_markdown_compiled,	NULL)		/* For testing, remove later. */
	PHP_FE(markdown_tohtml, NULL)
	/* __function_entries_here__ */
	PHP_FE_END	/* Must be the last line in extname_functions[] */
};
/* }}} */

/* {{{ extname_module_entry
 */
zend_module_entry markdown_module_entry = {
	STANDARD_MODULE_HEADER,
	"markdown",
	markdown_functions,
	PHP_MINIT(markdown),
	PHP_MSHUTDOWN(markdown),
	PHP_RINIT(markdown),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(markdown),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(markdown),
	PHP_MARKDOWN_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_MARKDOWN
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE();
#endif
ZEND_GET_MODULE(markdown)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
