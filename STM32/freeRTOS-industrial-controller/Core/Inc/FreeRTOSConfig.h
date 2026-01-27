#define configSUPPORT_STATIC_ALLOCATION     1
#define configSUPPORT_DYNAMIC_ALLOCATION   0

#define configCPU_CLOCK_HZ        ( SystemCoreClock )
#define configTICK_RATE_HZ       ( 1000 )
#define configMAX_PRIORITIES     ( 5 )
#define configMINIMAL_STACK_SIZE ( 128 )

#define configCHECK_FOR_STACK_OVERFLOW     2
#define configUSE_MALLOC_FAILED_HOOK       1

#define configUSE_TRACE_FACILITY           1
#define configGENERATE_RUN_TIME_STATS      1

#define configPRIO_BITS                    4
#define configLIBRARY_LOWEST_INTERRUPT_PRIORITY         15
#define configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY    5

#define configASSERT(x) if((x)==0) BSP_ErrorHandler()
