#include "../../inc/gigou_kernel.h"


__GigouWinAPI gigou_Kernel * __GigouUnixAPI gigou_kernel_startKernel(gigou_InfosKernel * infos){
    
    int i =0;
    
    if(infos == NULL){
        
        __GigouError("Invalid informations given")
        return NULL;
        
    }
    
    __GigouLogArg("START: Creating kernel id: %d",__GigouCastInt infos->v_indentityKernel)
    
    
    gigou_Kernel * buffer = NULL;
    
    
    __GigouLogArg("Allocating memory for kernel id: %d",__GigouCastInt infos->v_indentityKernel)
    
    
    buffer = (gigou_Kernel*)malloc(sizeof(gigou_Kernel));
    
    if(buffer == NULL){
        
        __GigouErrorArg("Can't allocate memory for kernel id: %d",__GigouCastInt infos->v_indentityKernel)
        
        exit(EXIT_FAILURE);
        
    }
    
    buffer->v_maxSizePool = infos->v_maxSizePool;
    
    buffer->v_nbrPool = infos->v_nbrPool;
    
    buffer->v_indentityKernel = infos->v_indentityKernel;
    
    buffer->da_childKernel = NULL;
    
    buffer->v_nbrChildKernel = 0;
    
    
    buffer->da_stackPool = (gigou_MemoryPool**)malloc(infos->v_nbrPool * sizeof(gigou_MemoryPool*));
    
    if(buffer->da_stackPool == NULL){
        
        __GigouErrorArg("Can't allocate memory for kernel id: %d",__GigouCastInt infos->v_indentityKernel)
        
        exit(EXIT_FAILURE);
        
    }
    
    __GigouLogArg("Initialisatoin memory pool for kernel id: %d",__GigouCastInt infos->v_indentityKernel)
    
    __GigouLogArg("There are %d pool in this kernel",__GigouCastInt infos->v_nbrPool)
    
    for(i=0;i< __GigouCastInt infos->v_nbrPool;i++){
        
        __GigouLogArg("Creating pool %d",__GigouCastInt i)
        
        *(buffer->da_stackPool + i) = gigou_kernel_mem_pool_createPool();
        
        gigou_kernel_mem_pool_setMaxSize(*(buffer->da_stackPool + i),infos->v_maxSizePool);
        
        gigou_kernel_mem_pool_initPool(*(buffer->da_stackPool + i));
        
    }
    
    __GigouLogArg("END: Creating kernel id: %d",__GigouCastInt infos->v_indentityKernel)
    
    return buffer;
    
}


__GigouWinAPI void __GigouUnixAPI gigou_kernel_endKernel(gigou_Kernel * kernel){
    
    __GigouLog("Arret du kernel")
    
    int i = 0;
    
    if(kernel != NULL){
        
        for(i=0;i< __GigouCastInt kernel->v_nbrPool;i++){
            
            gigou_kernel_mem_pool_destroyPool(*(kernel->da_stackPool + i));
            
        }
        
        free(kernel->da_stackPool);
        
        free(kernel);
        
    }else{
        
        __GigouLog("ERREUR le kernel n'existe pas")
        
    }
    
}


__GigouWinAPI gigou_InfosKernel * __GigouUnixAPI gigou_kernel_getBasicInfosKernel(){
    
    gigou_InfosKernel * buffer = NULL;
    
    buffer = (gigou_InfosKernel*)malloc(sizeof(gigou_InfosKernel));
    
    if(buffer == NULL){
        
        __GigouLog("Impossible d'allouer de la memoire pour creer les infos du kernel")
        
        exit(EXIT_FAILURE);
        
    }
    
    buffer->v_nbrPool = 1;
    
    buffer->v_maxSizePool = 1024;
    
    buffer->v_indentityKernel = 0;
    
    return buffer;
    
}


__GigouWinAPI void __GigouUnixAPI gigou_kernel_destroyBasicInfosKernel(gigou_InfosKernel * infos){
    
    __GigouLog("Suppression des infos kernel")
    
    if(infos != NULL){
        
        free(infos);
        
    }else{
        
        __GigouLog("ERREUR les infos n'existent pas")
        
    }
    
}