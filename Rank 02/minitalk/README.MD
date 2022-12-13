# Minitalk  
In this project you have to create a client that sends a string to a server using only UNIX signals.  

-The server and the client must be compiled by the Makefile and should be called "server" and "client" respectively.  
-You can (but you aren't forced to) only use one global variable for the server and one for the client, and you must justify their use.  
-The server must print its PID (Process ID) upon running and should be able to recieve strings from multiple clients (This means it won't stop running after recieving a string from a client, and must be always ready to recieve another string).  
-The client sends a string using UNIX signals to the server and ther server should print the string **after** recieving it.  
-You are only allowed to use the signals `SIGUSR1` and `SIGUSR2`.  

*Bonus include giving Unicode character support and making the server aknowledge the recieval of the string by sending a signal back to the client.*  

The best approach is to convert and send the length of the string first so you can allocate the necessary memmory in the server and then send the characters one by one and storing it in a `char *str` inside the server. To do this, you can check the bits of the length and the character and sending one of the signals for each 0 and the other signal for each 1 (Essentially you'll be converting a decimal value to a binnary one).  
On the server side, you can make both signals call the same function, but make the function do different things depending on the singal. In my case, both signals call the function, but only one of them is used for the conversion back to decimal. You should, then allocate a `char *str` using the length you sent, and the save each character to this variable. After having the string ready, you should print it followed by a newline.
