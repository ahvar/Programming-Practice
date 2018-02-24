# File Reading
Contains programs demonstrating common operations for reading/writing to file streams. Programs are organized into directories focusing on a particular topic. This document contains summaries, excerpts, and notes taken from chapters 10, *Input and Output Streams* and 11, *Customizing Input and Output*, of *Programming: Principles and Practice Using C++ (2nd Edition)* by Bjarne Stroustrup.

## 1.0 The I/O Stream Model

The I/O library provides an abstraction of I/O so that input and output can be seen as streams of bytes (characters) handled by the I/O library. Different forms of I/O include data items (to/from files, network connections, recording devices, display devices, etc.), interactions with the keyboard, interactions with user via a GUI. C++ standard library provides the type **istream** to deal with streams of input and type **ostream** to deal with streams of output. Both types use a buffer to communicate with the operating system. An **fstream** is an **iostream** that can be used for both reading and writing.

## 1.1 Files

A the most basic level, a file is simply a sequence of bytes numbered 0 upward. The file format helps us make sense of the bits in a file. The role of the file format is comparable to the way an object's type determines how the bits composing that object are represented in main memory.

## 1.2 File Opening and Positioning

Defining an **ifstream**/**ofstream** with a name string opens the file for reading/writing. The file associated with a file steram can be closed explicitly or when it goes out of scope. 

## 1.3 Binary Files

A file can be opened in one of several modes. It is possible to request **istream** and **ostream** to simply copy bytes to and from files. That's called *binary I/O* and is requested by opening a file with the mode **ios_base::binary**. When we move from character-oriented I/O to binary I/O, we give up our usual >> and << operators. Those operators specifically turn values into character sequences using default conventions

## 1.4 Positioning in Files

Basically, every file that is open for reading or writing has a "read/get position" and every file that is open for writing has a "write/put position." Note that **seekg()** and **seekp()** can be used to move to the "get position" or "put position" and both increment their respective positions. So, for example, **fsname.seekg(5)** (where fsname is a file stream) would move the reading position to 5. After it returns the character at index 5, the reading position is incremented and now points to the character at index 6. If you seek beyond the end of the file, the results are undefined and will likely differ between operating systems.

## 1.5 String Streams

An **istream** that reads from a string is an **istringstream** and an **ostream** that stores characters written to it in a **string** is called an **ostringstream**. Reading beyond the end of an **istringstream** will trigger the **eof()** state. The **str()** member function of **ostringstream** returns the **string** composed by output operations to an **ostringstream**. The **c_str()** is a member function of **string** that returns a C-style string that may be required by some system interfaces. **stringstreams** can be seen as a mechanism for tailoring I/O to special needs and tastes.

 - **istringstream** can be initialized with a string and the characters from the string read using input operations.
 - **ostringstream** can be initialized with an empty string and then filled using output operations.
 - **ss.str()** returns a copy of ss's string
 - **ss.str(s)** sets **ss's** string to a copy of **s**

## 1.6 Line-Oriented Input

When reading into a **string**, **>>** will read until it encounters whitespace.

 - **getline(cin,name)**: reads everything on the line from standard input at once

## 1.7 Character Classification

 - The **istream::get()** function reads a single character into its argument. It does not skip whitespace and it returns a reference to its **istream** so that the caller can test the stream's state. 
 - There are many standard library functions for classifying characters (**isspace(c), isalpha(c), isdigit(c), isupper(c), etc.**)





## Contents

###### **Stream States**

good() means the operations succeeded, eof() means we hit the end of the input(), fail() means something unexpected happened, bad() something unexpected and serious happened.

In the errorHandling2 program, since we cleared the stream state in fillVector after a fail(), we have to set it back to fail(). We stil return the failed state in case the caller can recover from the error. clear(), with an argument, sets the stream state flags (bits) mentioned and only clears flags not mentioned: ist.clear(ios_base::fail-bit). Put the last character read back into the stream before returning. The caller may be able to do something with it. ios_base is part of the iostream that holds constants such as badbit, failbit, exceptions such as failure.

###### **User-Defined Operators**

The right shift operator skips whitespace. Whitespace includes newline '\n', tabline '\t', and space ' ' characters. So the input loop in openFile reads text into contents and then the next line of code prints the contents of "contents" to the output file. The result is a line without the newline characters contained in input.txt.

###### **Chaining Output with the >> Operator** 

Note how overloaded right shift operator '<<' returns a reference to ostream 'ostream &'. this allows you to chain together the results of output operations. output streams are passed along so that you can "chain" output operations. That is, first output this object and the output second object to the output stream that is the result of the first output operation

###### **Handling Errors**
If an input operation encounters a simple format error, it lets the stream fail(), assuming it can be recovered by the user. If the problem is more serious (such as a bad disk read) the input operation lets the stream go bad(), assuming the user can't recover it. A stream that is bad() is also a fail().

We define a structure to contain the hour and temperature data for a single reading and then create a list to hold all the readings. Declare variables to hold time and temp data and use a loop to read data into variables. Iinside the loop, check for an invalid time and insert a new Reading struct into the list. The output loop writes the data for each struct contained in the Reading vector to the output file.

In almost all cases the only thing we want to do if we encounter bad() is to throw an exception.

## Directory Structure

|-- ERROR_LOG.md
|-- dates and temperatures
  |-- dateAndTemps.txt
  |-- datesAndTemps2.txt
  |-- tempReader.cpp
  |-- tempReader2.cpp
  |-- timeAndTemps.txt
|--handling errors
  |-- errorHandling.cpp
  |-- errorHandling2.cpp
|-- open files
  |-- input.txt
  |-- openFile.cpp
  |-- openFile2.cpp
|-- reading price data
  |-- filereader.h
  |-- filereader.cpp

 - **openFile**: 
 - **openFile2**: 
 
###### Programs
 - **tempReader**:
 - **tempReader2**:
 - **printObjects**: 


###### Programs
 - **errorHandling**: 

 - **errorHandling2**: 

## Resources and References

 - *The C++ Programming Language (Stroustrup)*
 - *C++ IOStreams and Locales (Langer)*
 - *Programming: Principles and Practice Using C++ (2nd Edition) (Stroustrup)*



