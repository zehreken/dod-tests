A project for inspecting the memory when Object Oriented vs Data Oriented methodologies are used.

* Compiling the program using
$ clang++ -g -o p main.cpp

* Loading the program to lldb
$ lldb p

* Running the program
(lldb) run

* Dumping line tables in lldb
(lldb) image dump line-table main.cpp

* Setting breakpoints at lines
(lldb) b main.cpp:4

* 
