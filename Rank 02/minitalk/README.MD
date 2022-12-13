# Minitalk  
In this project you have to create a client that sends a string to a server using only UNIX signals.  

-The server and the client must be compiled by the Makefile and should be called "server" and "client" respectively.
-You can only use one global variable for the server and one for the client, and you must justify their use (You don't need to create one at all if you feel like it is unecessary).  
-The server must print its PID (Process ID) upon running and should be able to recieve strings from multiple clients (This means it won't stop running after recieving a string from a client, and must be always ready to recieve another string).  
-The client sends a string using UNIX signals to the server and ther server should print the string **after** (Not character by character) recieving it.  
-You are only allowed to use the signals SIGUSR1 and SIGUSR2.  
