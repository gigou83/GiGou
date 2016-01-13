#ifndef GIGOU_COMPILER_H
#define GIGOU_COMPILER_H

#define GIGOU_COMPILER_GNUC     1
#define GIGOU_COMPILER_WINSCW   2
#define GIGOU_COMPILER_MSVC     3
#define GIGOU_COMPILER_BORLAND  4
#define GIGOU_COMPILER_CLANG    5
#define GIGOU_COMPILER_INTEL    6
#define GIGOU_COMPILER_HP       7
#define GIGOU_COMPILER_IBM      8
#define GIGOU_COMPILER_PORTLAND 9
#define GIGOU_COMPILER_ORACLE   10


#if defined(__GNUC__)
#   define GIGOU_COMPILER GIGOU_COMPILER_GNUC
#   define GIGOU_COMPILER_MAJOR __GNUC__
#   define GIGOU_COMPILER_MINOR __GNUC_MINOR__
#   define GIGOU_COMPILER_PATCHLEVEL __GNUC_PATCHLEVEL__
#   define GIGOU_COMPILER_VERSION __VERSION__
#elif defined(__WINSCW__)
#   define GIGOU_COMPILER GIGOU_COMPILER_WINSCW
#   error "Do not support this builder"
#elif defined(_MSC_VER)
#   define GIGOU_COMPILER GIGOU_COMPILER_MSVC
#   define GIGOU_COMPILER_MAJOR _MSC_VER
#   define GIGOU_COMPILER_MINOR _MSC_VER
#   define GIGOU_COMPILER_PATCHLEVEL _MSC_VER
#   define GIGOU_COMPILER_VERSION _MSC_BUILD
#elif defined(__BORLANDC__)
#   define GIGOU_COMPILER GIGOU_COMPILER_BORLAND
#   error "Do not support this builder"
#elif defined(__clang__)
#   define GIGOU_COMPILER GIGOU_COMPILER_CLANG
#   define GIGOU_COMPILER_MAJOR __clang_major__
#   define GIGOU_COMPILER_MINOR __clang_minor__
#   define GIGOU_COMPILER_PATCHLEVEL __clang_patchlevel__
#   define GIGOU_COMPILER_VERSION __VERSION__
#   error "Do not support this builder"
#elif defined(__ICC) || defined(__INTEL_COMPILER)
#   define GIGOU_COMPILER GIGOU_COMPILER_INTEL
#   define GIGOU_COMPILER_MAJOR __INTEL_COMPILER
#   define GIGOU_COMPILER_MINOR __INTEL_COMPILER
#   define GIGOU_COMPILER_PATCHLEVEL __INTEL_COMPILER
#   define GIGOU_COMPILER_VERSION __VERSION__
#   error "Do not support this builder"
#elif defined(__HP_cc) || defined(__HP_aCC)
#   define GIGOU_COMPILER GIGOU_COMPILER_HP
#   define GIGOU_COMPILER_MAJOR __HP_aCC
#   define GIGOU_COMPILER_MINOR __HP_cc
#   define GIGOU_COMPILER_PATCHLEVEL __HP_aCC
#   define GIGOU_COMPILER_VERSION __HP_aCC
#   error "Do not support this builder"
#elif defined(__IBMC__) || defined(__IBMCPP__)
#   define GIGOU_COMPILER GIGOU_COMPILER_IBM
#   define GIGOU_COMPILER_MAJOR __xlC__
#   define GIGOU_COMPILER_MINOR __xlC_ver__
#   define GIGOU_COMPILER_PATCHLEVEL __xlC_ver__
#   define GIGOU_COMPILER_VERSION __xlc__
#   error "Do not support this builder"
#elif defined(__PGI)
#   define GIGOU_COMPILER GIGOU_COMPILER_PORTLAND
#   define GIGOU_COMPILER_MAJOR __PGIC__
#   define GIGOU_COMPILER_MINOR __PGIC_MINOR
#   define GIGOU_COMPILER_PATCHLEVEL __PGIC_PATCHLEVEL__
#   define GIGOU_COMPILER_VERSION __PGIC__
#   error "Do not support this builder"
#elif defined(__SUNPRO_C) || defined(__SUNPRO_CC)s
#   define GIGOU_COMPILER GIGOU_COMPILER_ORACLE
#   define GIGOU_COMPILER_MAJOR __SUNPRO_CC
#   define GIGOU_COMPILER_MINOR __SUNPRO_CC
#   define GIGOU_COMPILER_PATCHLEVEL __SUNPRO_CC
#   define GIGOU_COMPILER_VERSION __SUNPRO_CC
#   error "Do not support this builder"
#endif


#endif