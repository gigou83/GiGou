#ifndef GIGOU_UUID_H
#define GIGOU_UUID_H

#include "gigou_init.h"


#if GIGOU_PLATFORM == GIGOU_PLATFORM_WINDOWS
#   include <Rpc.h>

typedef unsigned char * GIGOU_UUID;

#elif (GIGOU_PLATFORM == GIGOU_PLATFORM_LINUX) || (GIGOU_PLATFORM == GIGOU_PLATFORM_MACOS)
#   include <uuid/uuid.h>

typedef char * GIGOU_UUID;

#else

#   error "GiGou doesn't not support this platform"

#endif

__GigouWinAPI GIGOU_UUID __GigouUnixAPI gigou_getUUID();

__GigouWinAPI void __GigouUnixAPI gigou_printUUID(GIGOU_UUID s);

__GigouWinAPI void __GigouUnixAPI gigou_freeUUID(GIGOU_UUID * s);

#endif