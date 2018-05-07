dnl $Id$
dnl config.m4 for extension to_china_capitals

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

PHP_ARG_WITH(to_china_capitals, for to_china_capitals support,
Make sure that the comment is aligned:
[  --with-to_china_capitals             Include to_china_capitals support])

dnl Otherwise use enable:

dnl PHP_ARG_ENABLE(to_china_capitals, whether to enable to_china_capitals support,
dnl Make sure that the comment is aligned:
dnl [  --enable-to_china_capitals           Enable to_china_capitals support])

if test "$PHP_TO_CHINA_CAPITALS" != "no"; then
  dnl Write more examples of tests here...

  dnl # get library FOO build options from pkg-config output
  dnl AC_PATH_PROG(PKG_CONFIG, pkg-config, no)
  dnl AC_MSG_CHECKING(for libfoo)
  dnl if test -x "$PKG_CONFIG" && $PKG_CONFIG --exists foo; then
  dnl   if $PKG_CONFIG foo --atleast-version 1.2.3; then
  dnl     LIBFOO_CFLAGS=`$PKG_CONFIG foo --cflags`
  dnl     LIBFOO_LIBDIR=`$PKG_CONFIG foo --libs`
  dnl     LIBFOO_VERSON=`$PKG_CONFIG foo --modversion`
  dnl     AC_MSG_RESULT(from pkgconfig: version $LIBFOO_VERSON)
  dnl   else
  dnl     AC_MSG_ERROR(system libfoo is too old: version 1.2.3 required)
  dnl   fi
  dnl else
  dnl   AC_MSG_ERROR(pkg-config not found)
  dnl fi
  dnl PHP_EVAL_LIBLINE($LIBFOO_LIBDIR, TO_CHINA_CAPITALS_SHARED_LIBADD)
  dnl PHP_EVAL_INCLINE($LIBFOO_CFLAGS)

  dnl # --with-to_china_capitals -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/to_china_capitals.h"  # you most likely want to change this
  dnl if test -r $PHP_TO_CHINA_CAPITALS/$SEARCH_FOR; then # path given as parameter
  dnl   TO_CHINA_CAPITALS_DIR=$PHP_TO_CHINA_CAPITALS
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for to_china_capitals files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       TO_CHINA_CAPITALS_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$TO_CHINA_CAPITALS_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the to_china_capitals distribution])
  dnl fi

  dnl # --with-to_china_capitals -> add include path
  dnl PHP_ADD_INCLUDE($TO_CHINA_CAPITALS_DIR/include)

  dnl # --with-to_china_capitals -> check for lib and symbol presence
  dnl LIBNAME=to_china_capitals # you may want to change this
  dnl LIBSYMBOL=to_china_capitals # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $TO_CHINA_CAPITALS_DIR/$PHP_LIBDIR, TO_CHINA_CAPITALS_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_TO_CHINA_CAPITALSLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong to_china_capitals lib version or lib not found])
  dnl ],[
  dnl   -L$TO_CHINA_CAPITALS_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(TO_CHINA_CAPITALS_SHARED_LIBADD)

  PHP_NEW_EXTENSION(to_china_capitals, to_china_capitals.c, $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)
fi
