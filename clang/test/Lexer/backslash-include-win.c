// REQUIRES: system-windows
// RUN: mkdir -p %t/backslash
// RUN: cp %S/Inputs/case-insensitive-include.h %t/backslash/case-insensitive-include.h
// RUN: %clang -fsyntax-only -Wnonportable-include-path-separator -I%t %s 2>&1 | FileCheck %s

#include "backslash\case-insensitive-include.h"
// CHECK: non-portable path to file
// CHECK: specified path contains backslashes
// CHECK: "backslash/case-insensitive-include.h"

#include "backslash\CASE-insensitive-include.h"
// CHECK: non-portable path to file
// CHECK: specified path contains backslashes and differs in case from file name on disk
// CHECK: "backslash/case-insensitive-include.h"
