#include "../inc/gigou.h"

/*void init_pool(gigou_MemoryPool * pool){
    
    UINT32 tabSizeMax[3];
    tabSizeMax[0] = 32;
    tabSizeMax[1] = 64;
    tabSizeMax[2] = 128;
    
    gigou_kernel_mem_pool_initArrayTas(pool,tabSizeMax,4);
    
}*/

int main (void){
    
    gigou_InfosKernel * infos = gigou_kernel_getBasicInfosKernel();
    
    gigou_Kernel * kernel = gigou_kernel_startKernel(infos);
    
    gigou_kernel_destroyBasicInfosKernel(infos);
    
    gigou_kernel_endKernel(kernel);
    
    /*gigou_MemoryPool * pool;
    
    pool = gigou_kernel_mem_pool_createPool();
    
    gigou_kernel_mem_pool_setMaxSize(pool,1024);
    
    gigou_kernel_mem_pool_initPool(pool);
    
    gigou_kernel_mem_pool_destroyPool(pool);*/
    
    return 0;
}
