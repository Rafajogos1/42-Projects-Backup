# libft

In this project you will you create your own C library.   
-You will recreate various existing C functions and some new ones.  

*Bonus includes creating a struct and functions that work with that type of struct you created.*  

There isn't much to say about this project as the functions are fairly simple and there are a lot of them. One thing I want to say, though, is that it is important to to start optimizing your code, as it will be extremly important later, specially due to the *norminette*.  
It is also important that you **always** protect your memory alloactions.  
Here is an example:  
```
void  *mallloc_with_len(int len)  
{
  char  *str;  
  
  str = malloc(sizeof(char *) * len);  
  if (!str)  
    return (NULL);  
  return ((void *)str);  
}
```
The tricky part is making a Makefile for the first time. A Makefile, makes it much easier to do commands that you would've made one by one in the terminal. You will notice that your Makefile will compile your files into objects so they can be used later. If a `main` is included, it will be able to compilate a program. Essentially, the Makefile is doing the `gcc` part for you and the resulting program will be in a exportable case (This last part refers to the Makefiles you will use in 42, not Makefiles in general).  
After validating this project, you will be able to use it on the projects it is allowed to be used, however, you may not need many of them, and you may need to modify them. You can and should add new functions that you may find necessary.  
