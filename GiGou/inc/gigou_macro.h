#ifndef GIGOU_MACRO_H
#define GIGOU_MACRO_H

#include "gigou_platform.h"
#include "gigou_compiler.h"

#define __GigouStringize( L )     #L
#define __GigouMakeString( M, L ) M(L)
#define __GigouLine __GigouMakeString( __GigouStringize, __LINE__ )
#define __GigouWARNING __FILE__ "(" __GigouLine ") : Warning: "
#define __GigouERROR __FILE__ "(" __GigouLine ") : Error: "
#define __GigouTODO __FILE__ "(" __GigouLine ") : TODO: "

#define __GigouCastInt (int)

#if defined(GIGOU_DEBUG)
#   define __GigouLog(msg) printf("GiGou[%s](%d) \t=> ",__FILE__,__LINE__); printf(msg); printf("\n");
#   define __GigouLogArg(msg,arg) printf("GiGou[%s](%d)\t=> ",__FILE__,__LINE__); printf(msg,arg); printf("\n");
#   define __GigouError(msg) printf("ERROR[%s](%d) \t=> ",__FILE__,__LINE__); printf(msg); printf("\n");
#   define __GigouErrorArg(msg,arg) printf("ERROR[%s](%d)\t=> ",__FILE__,__LINE__); printf(msg,arg); printf("\n");
#   define __GigouWarning(msg) printf("WARNING[%s](%d) \t=> ",__FILE__,__LINE__); printf(msg); printf("\n");
#   define __GigouWarningArg(msg,arg) printf("WARNING[%s](%d)\t=> ",__FILE__,__LINE__); printf(msg,arg); printf("\n");
#else
#   define __GigouLog(msg)
#   define __GigouLogArg(msg,arg)
#   define __GigouError(msg) printf("ERROR[%s](%d) \t=> ",__FILE__,__LINE__); printf(msg); printf("\n");
#   define __GigouErrorArg(msg,arg) printf("ERROR[%s](%d)\t=> ",__FILE__,__LINE__); printf(msg,arg); printf("\n");
#   define __GigouWarning(msg) printf("WARNING[%s](%d) \t=> ",__FILE__,__LINE__); printf(msg); printf("\n");
#   define __GigouWarningArg(msg,arg) printf("WARNING[%s](%d)\t=> ",__FILE__,__LINE__); printf(msg,arg); printf("\n");
#endif

#if defined(__GIGOU_EXPORT__)
#   if GIGOU_PLATFORM == GIGOU_WINDOWS
#       define __GigouExport __declspec( dllexport )
#   else
#       define __GigouExport
#   endif
#elif defined(__GIGOU_IMPORT__)
#   if GIGOU_PLATFORM == GIGOU_WINDOWS
#       define __GigouExport __declspec( dllimport )
#   else
#       define __GigouExport
#   endif
#else
#   define __GigouExport
#endif

#if GIGOU_COMPILER == GIGOU_COMPILER_GNUC

#   define __GigouAlign8bits aligned(8)
#   define __GigouAlign16bits aligned(16)
#   define __GigouAlign32bits aligned(32)

#   ifndef GIGOU_FORCE_ALIGN
#       if GIGOU_ARCH_PLATFORM == GIGOU_ARCH_PLATFORM_32
#           define __GigouAlign __attribute__((__GigouAlign16bits))
#           define GIGOU_ALIGNEMENT 16
#       elif GIGOU_ARCH_PLATFORM == GIGOU_ARCH_PLATFORM_64
#           define __GigouAlign __attribute__((__GigouAlign16bits))
#           define GIGOU_ALIGNEMENT 16
#       else /* WTF */
#           define __GigouAlign __attribute__((__GigouAlign16bits))
#           define GIGOU_ALIGNEMENT 16
#   endif
#   ifdef GIGOU_FORCE_ALIGN
#       define __GigouAlign __attribute__((aligned(GIGOU_FORCE_ALIGN)))
#       define GIGOU_ALIGNEMENT GIGOU_FORCE_ALIGN
#   endif

#   define __GigouUnixAPI __GigouExport __GigouAlign
#   define __GigouWinAPI

#endif

#elif GIGOU_COMPILER == GIGOU_COMPILER_MSVC

#   define __GigouAlign8bits align(8)
#   define __GigouAlign16bits align(16)
#   define __GigouAlign32bits align(32)

#   ifndef GIGOU_FORCE_ALIGN
#       if GIGOU_ARCH_PLATFORM == GIGOU_ARCH_PLATFORM_32
#           define __GigouAlign __declspec(__GigouAlign16bits)
#           define GIGOU_ALIGNEMENT 16
#       elif GIGOU_ARCH_PLATFORM == GIGOU_ARCH_PLATFORM_64
#           define __GigouAlign __declspec(__GigouAlign16bits)
#           define GIGOU_ALIGNEMENT 16
#       endif
#   endif
#   ifdef GIGOU_FORCE_ALIGN
#       define __GigouAlign __declspec(align(GIGOU_FORCE_ALIGN))
#       define GIGOU_ALIGNEMENT GIGOU_FORCE_ALIGN
#   endif

#   define __GigouWinAPI __GigouAlign __GigouExport
#   define __GigouUnixAPI

#else
#   define __GigouAlign8bits
#   define __GigouAlign16bits
#   define __GigouAlign32bits
#   define __GigouAlign
#   define __GigouUnixAPI
#   define __GigouWinAPI


#endif

#endif