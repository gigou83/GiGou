#include "../inc/gigou.h"

#include <time.h>

#define N 10000

typedef struct vertex vertex;

__GigouWinAPI struct __GigouUnixAPI vertex{
    int a,b,c,d,e,f;
    double g,h;
};

int main (void){
    
    gigou_InfosKernel * infos = gigou_kernel_getBasicInfosKernel();
    
    gigou_Kernel * kernel = gigou_kernel_startKernel(infos);
    
    gigou_kernel_destroyBasicInfosKernel(infos);
    
    int i = 0;
    
    vertex ** liste_point = (vertex**)gigou_kernel_alloc(kernel,N*sizeof(vertex*));
    
    gigou_kernel_preAlloc(kernel,sizeof(vertex),N);
    
    for(i=0;i<N;i++){
        *(liste_point + i) = (vertex*)gigou_kernel_alloc(kernel,sizeof(vertex));
    }
    
    
    for(i=0;i<N;i++){
        gigou_kernel_free(kernel,*(liste_point + i),sizeof(vertex));
    }
    
    gigou_kernel_free(kernel,liste_point,N*sizeof(vertex*));
    
    gigou_kernel_endKernel(kernel);
    
    return 0;
}
