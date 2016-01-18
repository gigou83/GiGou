#include "../../../inc/gigou_uuid.h"

#if GIGOU_PLATFORM == GIGOU_PLATFORM_WINDOWS

__GigouWinAPI GIGOU_UUID __GigouUnixAPI gigou_getUUID(){
    
    UUID uuid;
    UuidCreate(&uuid);
    
    unsigned char * str;
    
    UuidToStringA(&uuid,&str);
    
    return str;
    
}

__GigouWinAPI void __GigouUnixAPI gigou_freeUUID(GIGOU_UUID * s){
    
    RpcStringFreeA(&s);
    
}

#endif