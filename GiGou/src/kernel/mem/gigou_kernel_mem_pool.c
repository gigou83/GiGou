#include "../../../inc/gigou_kernel_mem_pool.h"


/*
 ******************************************************
 ******************* PUBLIC FONCTION ******************
 ******************************************************
 */



__GigouWinAPI gigou_MemoryPool * __GigouUnixAPI gigou_kernel_mem_pool_createPool(UINT32 index){
    
    __GigouLogArg("START: Creating memory pool at index %d",__GigouCastInt index)
    
    gigou_MemoryPool * buffer = (gigou_MemoryPool*)malloc(sizeof(gigou_MemoryPool));
    
    if(buffer == NULL){
        __GigouErrorArg("Can't allocate memory to create this memory pool id: %d", __GigouCastInt index)
        exit(EXIT_FAILURE);
    }
    
    buffer->v_nbrTas = 1;
    buffer->da_maxSizeTas = NULL;
    buffer->da_tas = NULL;
    buffer->p_tas = NULL;
    buffer->v_identity = index;
    
    __GigouLogArg("END: Creating memory pool at index %d",__GigouCastInt index)
    
    return buffer;
    
}


__GigouWinAPI void __GigouUnixAPI gigou_kernel_mem_pool_setMaxSize(gigou_MemoryPool * pool,
                                                                   UINT32 size){
    
    
    __GigouLogArg("Configure maxSize for pool id: %d", __GigouCastInt pool->v_identity)
    
    if(size > 0){
        
        if(size % GIGOU_ALIGNEMENT == 0){
            
            __GigouLogArg("maxSize is : %d", __GigouCastInt size);
            
            pool->maxSize = size;
            
        }else{
            
            __GigouErrorArg("Size have to be an alignement multiple in pool id: %d", __GigouCastInt pool->v_identity)
        }
        
    }else{
        
        __GigouErrorArg("Size have to be positive in pool id: %d", __GigouCastInt pool->v_identity)
        
    }
    
}



__GigouWinAPI void __GigouUnixAPI gigou_kernel_mem_pool_initPool(gigou_MemoryPool * pool){
    
    UINT32 * buffer;
    
    if(pool != NULL){
        
        if(pool->maxSize > 0 && pool->maxSize%GIGOU_ALIGNEMENT == 0){
            
            buffer = __gigou_kernel_mem_pool_generateArrayTasMaxSize(pool->maxSize,
                                                                     &(pool->v_nbrTas));
            
            __gigou_kernel_mem_pool_initArrayTas(pool,buffer,pool->v_nbrTas);
            
            free(buffer);
            
            buffer = NULL;
            
        }else{
            
            __GigouLog("ERREUR dans la taille maximale du pool")
            
        }
        
    }else{
        
        __GigouLog("ERREUR le pool n'existe pas")
        
    }
    
}



__GigouWinAPI UINT32 __GigouUnixAPI gigou_kernel_mem_pool_getMemoryUsed(gigou_MemoryPool*pool){
    
    UINT32 size = 0;
    
    int i = 0;
    
    if(pool != NULL){
        
        for(i=0;i< __GigouCastInt pool->v_nbrTas;i++){
            
            size += (*(pool->da_tas + i))->v_val * (*(pool->da_tas + i))->p_pile->v_nbrElement;
            
        }
        
        
    }else{
        
        __GigouError("Invalid memory pool")
        
    }
    
    return size;
    
}



__GigouWinAPI void __GigouUnixAPI gigou_kernel_mem_pool_destroyPool(gigou_MemoryPool * pool){
    
    __GigouLog("Liberation du pool memoire")
    
    int i = 0;
    
    if(pool->v_nbrTas > 0 && pool->da_tas != NULL){
        
        __GigouLog("Liberation des tas ")
        
        for(i=0;i< __GigouCastInt pool->v_nbrTas;i++){
            
            gigou_kernel_mem_tas_destroyTas(*(pool->da_tas + i));
            
        }
        
        free(pool->da_tas);
        
    }
    
    if(pool->da_maxSizeTas != NULL){
        
        free(pool->da_maxSizeTas);
        
        pool->da_maxSizeTas = NULL;
        
    }
    
    free(pool);
    
    pool = NULL;
    
    __GigouLog("Pool freed !")
}




/*
 *******************************************************
 ******************* PRIVATE FONCTION ******************
 *******************************************************
 */


__GigouWinAPI void __GigouUnixAPI __gigou_kernel_mem_pool_initArrayTas(gigou_MemoryPool * pool,
                                                                     UINT32 * listeSize,
                                                                     UINT8 nbr){
    
    int i = 0;
    
    if(nbr > 0 && pool != NULL){
        
        __GigouLog("Initialisation des tas du pool")
        __GigouLogArg("Nombre de tas dans le pool : %d",nbr)
        
        __GigouLog("Allocation memoire da_maxSizeTas")
        
        pool->da_maxSizeTas = (UINT32*)malloc(nbr*sizeof(UINT32));
        
        if(pool->da_maxSizeTas == NULL){
            
            __GigouLog("Echec d'allocation memoire pour da_maxSizeTas")
            exit(EXIT_FAILURE);
            
        }
        
        __GigouLog("Allocation memoire da_tas")
        
        pool->da_tas = (gigou_MemoryTas**)malloc(nbr*sizeof(gigou_MemoryTas*));
        
        if(pool->da_tas == NULL){
            
            __GigouLog("Echec d'allocation memoire pour da_tas")
            exit(EXIT_FAILURE);
            
        }
        
        pool->v_nbrTas = nbr;
        
        for(i=0;i<nbr;i++){
            
            *(pool->da_maxSizeTas + i) = *(listeSize + i);
            
            *(pool->da_tas + i) = gigou_kernel_mem_tas_createTas();
            
            (*(pool->da_tas + i))->v_val = *(listeSize + i);
            
            __gigou_kernel_mem_tas_stackMemoryAligned(*(pool->da_tas + i));
            
        }
        
    }
    
}


__GigouWinAPI UINT32 * __GigouUnixAPI __gigou_kernel_mem_pool_generateArrayTasMaxSize(UINT32 size,
                                                                                      UINT32 * nbr){
    
    __GigouLog("Generation du tableau de taille max du pool")
    
    UINT32 longueur = 0;
    
    int i = 0;
    
    int k = 0;
    
    
    UINT32 * buffer = NULL;
    
    if(size > 0  && size%GIGOU_ALIGNEMENT == 0){
        
        while(longueur != size){
            
            longueur += GIGOU_ALIGNEMENT;
            
            i++;
            
        }
                
        buffer = (UINT32*)malloc(i*sizeof(UINT32));
        
        
        for(k=0;k<i;k++){
            
            *(buffer + k) = (k+1)*GIGOU_ALIGNEMENT;
            
        }
        
    }else{
        
        __GigouLog("ERREUR taille maximale invalide")
        
    }
    
    *nbr = i;
    
    return buffer;
    
}





