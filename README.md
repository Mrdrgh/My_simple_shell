# Simple Shell Program Documentation

The `simple_shell` is a minimalistic command-line interpreter program that allows users to execute commands in interactive mode or by using the pipe operator.

## Author
- Mrdrgh

## Features

### Interactive Mode
The `simple_shell` supports interactive mode, where users can input commands directly in the terminal and receive output accordingly.

### Piped Command Usage
Users can use the pipe operator (`|`) to feed the output of one command as input to another command. For example:

```sh
echo "command" | program_name
```

### Non Piped Command Usage
or we can use the program in interactive mode, just like sh or born_again_sh ,to start using it run the program and then do your commands just like a normal shell :
```./hsh
$ (command) 
(prompt)
$ ...
```

### standart functions used 
- ```execve```
- ```fork```
- ```isatty```
- ```perror```
- ```stat && access```
- all the other function are manually made by me
