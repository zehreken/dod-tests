A project for inspecting the memory when Object Oriented vs Data Oriented methodologies are used.

###### Compiling the program
```clang++ -g -o p main.cpp```

###### Loading the program into lldb
```lldb p```

###### Running the program
```(lldb) run```

###### Dumping line tables in lldb
```(lldb) image dump line-table main.cpp```

###### Setting breakpoints at lines

```(lldb) b main.cpp:4```
The program uses pointer to get the address of the array.

###### Reading memory
* This reads 32 bytes of memory
```(lldb) memory read [address]```
* This reads n bytes of memory
```(lldb) memory read [address] [address+n]```
* This reads memory in hex format
```(lldb) memory read -fx [address]```
* Play with this
```(lldb) memory read -fx -s4 -c4 [address]```
