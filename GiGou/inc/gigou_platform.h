#ifndef GIGOU_PLATFORM_H
#define GIGOU_PLATFORM_H

#define GIGOU_ARCH_PLATFORM_32      1
#define GIGOU_ARCH_PLATFORM_64      2

#define GIGOU_PLATFORM_WINDOWS      1
#define GIGOU_PLATFORM_LINUX        2
#define GIGOU_PLATFORM_MACOS        3
#define GIGOU_PLATFORM_SOLARIS      4
#define GIGOU_PLATFORM_ANDROID      5
#define GIGOU_PLATFORM_CYGWIN       6
#define GIGOU_PLATFORM_DS           7
#define GIGOU_PLATFORM_PSP          8
#define GIGOU_PLATFORM_XBOX         9
#define GIGOU_PLATFORM_XBOX360      10
#define GIGOU_PLATFORM_PS3          11
#define GIGOU_PLATFORM_PS4          12
#define GIGOU_PLATFORM_AIX          13
#define GIGOU_PLATFORM_DRAGONFLY    14
#define GIGOU_PLATFORM_FREEBSD      15
#define GIGOU_PLATFORM_NETBSD       16
#define GIGOU_PLATFORM_OPENBSD      17
#define GIGOU_PLATFORM_HPUX         18
#define GIGOU_PLATFORM_IPHONE       19
#define GIGOU_PLATFORM_IPHONESIM    20

#if defined(_AIX)
#   define GIGOU_PLATFORM GIGOU_PLATFORM_AIX
#elif defined(__unix__) || (defined(__APPLE__) && defined(__MACH__))
#   include <sys/param.h>
#   if defined(BSD)
#       if defined(__DragonFly__)
#           define GIGOU_PLATFORM GIGOU_PLATFORM_DRAGONFLY
#       elif defined(__FreeBSD__)
#           define GIGOU_PLATFORM GIGOU_PLATFORM_FREEBSD
#       elif defined(__NetBSD__)
#           define GIGOU_PLATFORM GIGOU_PLATFORM_NETBSD
#       elif defined(__OpenBSD__)
#           define GIGOU_PLATFORM GIGOU_PLATFORM_OPENBSD
#       elif (defined(__APPLE__) && defined(__MACH__))
#           include <TargetConditionals.h>
#           if TARGET_IPHONE_SIMULATOR == 1
#               define GIGOU_PLATFORM GIGOU_PLATFORM_IPHONESIM
#           elif TARGET_OS_IPHONE == 1
#               define GIGOU_PLATFORM GIGOU_PLATFORM_IPHONE
#           elif TARGET_OS_MAC == 1
#               if defined(__LP64__)
#                   define GIGOU_ARCH_PLATFORM GIGOU_ARCH_PLATFORM_64
#               else
#                   define GIGOU_ARCH_PLATFORM GIGOU_ARCH_PLATFORM_32
#               endif
#               define GIGOU_PLATFORM GIGOU_PLATFORM_OSX
#           endif
#       endif
#   elif (defined(__APPLE__) && defined(__MACH__))
#       include <TargetConditionals.h>
#       if TARGET_IPHONE_SIMULATOR == 1
#           define GIGOU_PLATFORM GIGOU_PLATFORM_IPHONESIM
#       elif TARGET_OS_IPHONE == 1
#           define GIGOU_PLATFORM GIGOU_PLATFORM_IPHONE
#       elif TARGET_OS_MAC == 1
#           if defined(__LP64__)
#               define GIGOU_ARCH_PLATFORM GIGOU_ARCH_PLATFORM_64
#           else
#               define GIGOU_ARCH_PLATFORM GIGOU_ARCH_PLATFORM_32
#           endif
#           define GIGOU_PLATFORM GIGOU_PLATFORM_OSX
#       endif
#   endif
#elif defined(__hpux)
#   define GIGOU_PLATFORM GIGOU_PLATFORM_HPUX
#elif defined(__linux__)
#   define GIGOU_PLATFORM GIGOU_PLATFORM_LINUX
#include <stdint.h>
#if UINTPTR_MAX == 0xffffffff
#   define GIGOU_ARCH_PLATFORM GIGOU_ARCH_PLATFORM_32
#elif UINTPTR_MAX == 0xffffffffffffffff
#   define GIGOU_ARCH_PLATFORM GIGOU_ARCH_PLATFORM_64
#   endif
#elif defined(__sun) && defined(__SVR4)
#   define GIGOU_PLATFORM GIGOU_PLATFORM_SOLARIS
#elif defined(__CYGWIN__) && !defined(_WIN32)
#   define GIGOU_PLATFORM GIGOU_PLATFORM_CYGWIN
#   define GIGOU_ARCH_PLATFORM GIGOU_ARCH_PLATFORM_32
#elif defined(_WIN64)
#   define GIGOU_PLATFORM GIGOU_PLATFORM_WINDOWS
#   define GIGOU_ARCH_PLATFORM GIGOU_ARCH_PLATFORM_64
#elif defined(_WIN32)
#   define GIGOU_PLATFORM GIGOU_PLATFORM_WINDOWS
#   define GIGOU_ARCH_PLATFORM GIGOU_ARCH_PLATFORM_32
#endif

#endif