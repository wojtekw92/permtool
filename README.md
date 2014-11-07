Permission Tool
===============
It is a tool that makes scritpting in bash easier, it convert ls permission to number and can convert number to ls style permission view.


How to use
----------

Permtool with -b will convert ls style to number
> :-$ permtool -b rwxrwxrwx
> 777

Permtool with -d will convert number to ls style
> :-$ permtool -d 777
> rwxrwxrwx


How to make and install 
-----------------------

Just clone it from github and run make
> :-$ make all
if you want install it just for you
> :-$ cp permtool ~/bin

