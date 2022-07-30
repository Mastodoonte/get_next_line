# <!--libft-->
<div align="center">
  <img src="src/school_42_logo.jpeg" height="128px" alt="badge de 42" >
  <h1>Get_next_line</h1>
  <p>🚀 Because reading from a fd is not exciting</p>
  <img src="src/grade.png" alt="grade of the get_next_line project">
<pr> 
</div>

## 👀 Preview
Whether it's a file, stdin, or even later a network connection, We had always needed a way to read the content line by line. It was time to start working on this feature, which were essential for our future projects. 

![forthebadge](https://forthebadge.com/images/badges/made-with-c-sharp.svg)
![forthebadge](https://forthebadge.com/images/badges/check-it-out.svg)



## 👀 Rules

- Successive calls to your get_next_line() function should allow you to read the entire text file referenced by the file descriptor, one line at a time.
- Your function should return the line that has just been read.
If there is nothing left to read, or if there is an error, it must return NULL.
- Make sure your function behaves correctly whether it reads a file or reads from standard input.
- Important: You must always return the line that was read followed by the ending \n, except in the case where you have reached the end of the file and the file does not end with an \n.
- The get_next_line.h header file must contain at least the prototype of the function.
- The file get_next_line_utils.c will be used to add additional functions necessary for the execution of your get_next_line().
Your program must compile with the option: -D BUFFER_SIZE=n
This macro defined at the compiler invocation will be used to specify the buffer size when you call read() in your get_next_line() function.
This value will be modified during the peer-evaluation and by the Moulinette in order to test your rendering.
- Your program will be compiled as follows (example below with a buffer size of 42):
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c
- We consider that get_next_line() has an undetermined behavior if, between two calls, the file pointed to by the file descriptor has been modified, while the first file has not been read in full.
- We also consider that get_next_line() has an undetermined behavior if a binary file is read. However, if you wish, you can make this behavior consistent.

## 👀 What is not allowed
- Libft is not allowed for this project.
- The lseek() function is not allowed.
- Global variables are not allowed.

<!--badges : https://badge42.vercel.app-->
