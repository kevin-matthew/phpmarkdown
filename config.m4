dnl $Id$
dnl config.m4 for extension libmarkdown

PHP_ARG_ENABLE(markdown, whether to enable markdown support,
[  --disable-markdown          Disable markdown support], yes)

if test "$PHP_MARKDOWN" != "no";
then
    LIBNAME=markdown
    LIBSYMBOL=mkd_string
	PHP_SUBST(INSTALL_ROOT)
    PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
    [
        PHP_ADD_LIBRARY($LIBNAME, 1, EXTRA_CFLAGS)
        PHP_SUBST(EXTRA_CFLAGS)
        AC_DEFINE([MARKDOWN],1 ,[whether to enable MARKDOWN support])
		
        AC_HEADER_STDC
    ],[
        AC_MSG_ERROR([NIGGERS])
    ],[-l$LIBNAME])

    
  
    PHP_NEW_EXTENSION(markdown,
	      markdown.c,
	      $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)
    PHP_INSTALL_HEADERS([php_markdown.h])
fi


