#include "../../../inc/gigou_uuid.h"

#if (GIGOU_PLATFORM == GIGOU_PLATFORM_LINUX) || (GIGOU_PLATFORM == GIGOU_PLATFORM_MACOS)

__GigouWinAPI GIGOU_UUID __GigouUnixAPI gigou_getUUID(){
    
    char * buffer = NULL;
    
    int i = 0;
    
    uuid_t uuid;
    
    uuid_generate_random(uuid);
    
    char s[37];
    
    uuid_unparse(uuid,s);
    
    buffer = (char*)malloc(37*sizeof(char));
    
    for(i=0;i<37;i++){
        
        *(buffer + i) = s[i];
        
    }
    
    return buffer;
    
}

__GigouWinAPI void __GigouUnixAPI gigou_freeUUID(GIGOU_UUID * s){
    
    free(s);
    
}

#endif