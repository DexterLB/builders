set remotetimeout 1
target remote localhost:3333
mon reset halt
load
break main
continue
