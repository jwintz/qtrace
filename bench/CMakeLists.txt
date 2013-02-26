### CMakeLists.txt --- 
## 
## Author: Julien Wintz
## Copyright (C) 2008-2011 - Julien Wintz, Inria.
## Created: Sat Jan 26 00:17:41 2013 (+0100)
## Version: $Id$
## Last-Updated: Sat Jan 26 00:18:45 2013 (+0100)
##           By: Julien Wintz
##     Update #: 2
######################################################################
## 
### Commentary: 
## 
######################################################################
## 
### Change log:
## 
######################################################################

configure_file(
  ${CMAKE_SOURCE_DIR}/bench/qtrNewton.rb.in
  ${CMAKE_SOURCE_DIR}/bench/qtrNewton.rb
  IMMEDIATE @ONLY)
