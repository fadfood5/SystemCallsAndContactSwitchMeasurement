all: runsc runcs
        
runsc: sys_call.c
        gcc -std=c99 -o runsc sys_call.c

runcs: context_switch.c
        gcc -std=c99 -D _GNU_SOURCE -o runcs context_switch.c
