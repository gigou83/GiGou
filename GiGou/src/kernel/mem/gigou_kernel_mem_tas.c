#include "../../../inc/gigou_kernel_mem_tas.h"

__GigouWinAPI gigou_MemoryTas * __GigouUnixAPI gigou_kernel_mem_tas_createTas(){
    
    gigou_MemoryTas * buffer = (gigou_MemoryTas*)malloc(sizeof(gigou_MemoryTas));
    
    if(buffer == NULL){
        
        __GigouLog("Impossible d'allouer la memoire pour ce tas")
        exit(EXIT_FAILURE);
        
    }
    
    buffer->v_val = 0;
    
    buffer->p_pile = gigou_kernel_mem_pile_createPile();
    
    return buffer;
    
}


__GigouWinAPI void __GigouUnixAPI gigou_kernel_mem_tas_destroyTas(gigou_MemoryTas * tas){
    
    gigou_kernel_mem_pile_destroyPile(tas->p_pile);
    
    free(tas);
    
    tas = NULL;
    
}


__GigouWinAPI void __GigouUnixAPI __gigou_kernel_mem_tas_stackMemoryAligned(gigou_MemoryTas * tas){
    
    gigou_kernel_mem_pile_AllocPile(tas->p_pile,GIGOU_STACK_MEM,tas->v_val);
    
}