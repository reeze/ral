dnl $Id$
dnl config.m4 for extension ral

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(ral, for ral support,
dnl Make sure that the comment is aligned:
dnl [  --with-ral             Include ral support])

dnl Otherwise use enable:

dnl PHP_ARG_ENABLE(ral, whether to enable ral support,
dnl Make sure that the comment is aligned:
dnl [  --enable-ral           Enable ral support])

if test "$PHP_RAL" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-ral -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/ral.h"  # you most likely want to change this
  dnl if test -r $PHP_RAL/$SEARCH_FOR; then # path given as parameter
  dnl   RAL_DIR=$PHP_RAL
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for ral files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       RAL_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$RAL_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the ral distribution])
  dnl fi

  dnl # --with-ral -> add include path
  dnl PHP_ADD_INCLUDE($RAL_DIR/include)

  dnl # --with-ral -> check for lib and symbol presence
  dnl LIBNAME=ral # you may want to change this
  dnl LIBSYMBOL=ral # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $RAL_DIR/lib, RAL_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_RALLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong ral lib version or lib not found])
  dnl ],[
  dnl   -L$RAL_DIR/lib -lm
  dnl ])
  dnl
  dnl PHP_SUBST(RAL_SHARED_LIBADD)

  PHP_NEW_EXTENSION(ral, ral.c, $ext_shared)
fi
