make: runsc runcs

runsc: system_call.c
	gcc -std=c99 -o runsc system_call.c

runcs: context_switch.c
	gcc -std=c99 -D _GNU_SOURCE -o runcs context_switch.c

clean:
	rm runsc
	rm runcs
	rm pipe.txt
