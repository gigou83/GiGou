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
        
        *(buffer->da_stackPool + i) = gigou_kernel_mem_pool_createPool(i);
        
        gigou_kernel_mem_pool_setMaxSize(*(buffer->da_stackPool + i),infos->v_maxSizePool);
        
        gigou_kernel_mem_pool_initPool(*(buffer->da_stackPool + i));
        
    }
    
    __GigouLogArg("END: Creating kernel id: %d",__GigouCastInt infos->v_indentityKernel)
    
    return buffer;
    
}


__GigouWinAPI void __GigouUnixAPI gigou_kernel_endKernel(gigou_Kernel * kernel){
    
    __GigouLog("START : Stopping kernel")
    
    int i = 0;
    
    if(kernel != NULL){
        
        for(i=0;i< __GigouCastInt kernel->v_nbrPool;i++){
            
            gigou_kernel_mem_pool_destroyPool(*(kernel->da_stackPool + i));
            
        }
        
        free(kernel->da_stackPool);
        
        free(kernel);
        
    }else{
        
        __GigouError("This kernel doesn't exist")
        
    }
    
    __GigouLog("END : Stopping kernel")
    
}


__GigouWinAPI gigou_InfosKernel * __GigouUnixAPI gigou_kernel_getBasicInfosKernel(){
    
    gigou_InfosKernel * buffer = NULL;
    
    buffer = (gigou_InfosKernel*)malloc(sizeof(gigou_InfosKernel));
    
    if(buffer == NULL){
        
        __GigouLog("Impossible d'allouer de la memoire pour creer les infos du kernel")
        
        exit(EXIT_FAILURE);
        
    }
    
    buffer->v_nbrPool = 1;
    
    buffer->v_maxSizePool = GIGOU_DEFAULT_SIZEPOOL;
    
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


__GigouWinAPI void * __GigouUnixAPI gigou_kernel_alloc(gigou_Kernel * kernel,size_t size){
    
    return gigou_kernel_allocInPool(kernel,0,size);
    
}



__GigouWinAPI void * __GigouUnixAPI gigou_kernel_allocInPool(gigou_Kernel * kernel,
                                                                     UINT32 identity,
                                                                     size_t size){
    
    void * buffer = NULL;
    
    int indice = 0;
    
    UINT32 c_size = (UINT32) size;
    
    if(kernel != NULL){
        
        
        if(c_size < kernel->v_maxSizePool){
            
            indice = c_size/GIGOU_ALIGNEMENT - 1;
            
            /*__gigou_kernel_mem_pile_display((*((*(kernel->da_stackPool + identity))->da_tas + indice))->p_pile);*/
            
            buffer = __gigou_kernel_mem_pile_popElement((*((*(kernel->da_stackPool + identity))->da_tas + indice))->p_pile );
            
            /*__gigou_kernel_mem_pile_display((*((*(kernel->da_stackPool + identity))->da_tas + indice))->p_pile);*/
            
        }else{
            
            return malloc(size*sizeof(char));
            
        }
        
        
    }else{
        
        __GigouError("Invalid kernel")
        
    }
    
    
    return buffer;
    
    
}


__GigouWinAPI UINT32 __GigouUnixAPI gigou_kernel_preAlloc(gigou_Kernel * kernel,
                                                          size_t size,
                                                          UINT32 nbr){
    
    
    return gigou_kernel_preAllocInPool(kernel,0,size,nbr);
    
}



__GigouWinAPI UINT32 __GigouUnixAPI gigou_kernel_preAllocInPool(gigou_Kernel * kernel,
                                                                UINT32 identity,
                                                                size_t size,
                                                                UINT32 nbr){
    UINT32 c_size = (UINT32) size;
    
    int indice = 0;
    
    int buffer = 0;
    
    if(kernel != NULL){
        
        if(c_size > 0  && nbr > 0){
            
            indice = c_size/GIGOU_ALIGNEMENT - 1;
            
            /*__gigou_kernel_mem_pile_display((*((*(kernel->da_stackPool + identity))->da_tas + indice))->p_pile);*/
            
            buffer =  __gigou_kernel_mem_pile_preAlloc((*((*(kernel->da_stackPool + identity))->da_tas + indice))->p_pile,nbr);
            
            /*__gigou_kernel_mem_pile_display((*((*(kernel->da_stackPool + identity))->da_tas + indice))->p_pile);*/
            
            return buffer;
            
        }else{
            
            __GigouError("Invalid argument")
            
        }
        
        
    }else{
        
        __GigouError("This kernel doesn't exist")
        
    }
    
    
    return 0;
    
}


__GigouWinAPI void __GigouUnixAPI gigou_kernel_free(gigou_Kernel * kernel, void * addr, size_t size){
    
    gigou_kernel_freeInPool(kernel,0,addr,size);
    
}


__GigouWinAPI void __GigouUnixAPI gigou_kernel_freeInPool(gigou_Kernel * kernel,
                                                          UINT32 identity,
                                                          void * addr,
                                                          size_t size){
    
    UINT32 c_size = (UINT32) size;
    
    int indice = 0;
    
    if(kernel != NULL){
        
        if(c_size < kernel->v_maxSizePool){
            
            indice = c_size/GIGOU_ALIGNEMENT - 1;
            
            /*__gigou_kernel_mem_pile_display((*((*(kernel->da_stackPool + identity))->da_tas + indice))->p_pile);*/
            
            __gigou_kernel_mem_pile_pushElement((*((*(kernel->da_stackPool + identity))->da_tas + indice))->p_pile,addr);
            
            /*__gigou_kernel_mem_pile_display((*((*(kernel->da_stackPool + identity))->da_tas + indice))->p_pile);*/
            
            addr = NULL;
            
        }else{
            
            free(addr);
            
        }
        
    }else{
        
        __GigouError("Invalid kernel")
        
    }

    
    
}

