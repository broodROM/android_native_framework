android_native_framework
========================

A modular native framework for handling low level stuff in android

It was first written to be used inside broodrom then it has been extended into a global project which will let every one to use it.

It's modular, this means that you can add new switches to anf without having to mess codes.

adding new swithces and their callback function is pretty simple :

    1- open builtin_modules.c and write your module function (e.g. "helloworld()")
        // void helloworld(anf_stat *a) { puts("hello world"); }
    2- open anf.h , declare your new function
        // void helloworld(anf_stat *);
    3- go down and add a new switch which uses your module as callback function
        // SWITCH('w',helloworld)
    4- done. now you can test your new function with "anf -w" and it will helloworld for you !
    
