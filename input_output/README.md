###### Created: 12-03-17


# Topics

#### I/O Error Handling
 - there are four possible stream states: good() means the operations succeeded, eof() means we hit the end of the input(), fail() means something unexpected happened, bad() something expected and serious happened
 - good books for exploring details of iostreams, *The C++ Programming Language* (Stroustrup) and *C++ IOStreams and Locales* (Langer)


# Practice Programs

#### openFile
 - The right shift operator skips whitespace. Whitespace includes newline '\n', tabline '\t', and space ' ' characters. So the input loop in openFile reads text into contents and then the next line of code prints the contents of "contents" to the output file. The result is a line without the newline characters contained in input.txt. 

#### openFile2
 - We define a structure to contain the hour and tempature data for a single reading and then create a list to hold all the readings. 
 - Declare to variables to hold time and temp data. And use a for loop to read data into variables.
 - Inside the input loop, check for an invalid time and insert a new Reading struct into the list
 - The output loop writes the data for each struct contained in the Reading vector to the output file

#### streamState
 - If an input operation encounters a simple format error, it lets the stream fail(), assuming it can be recovered by the user.
 - If the problem is more serious (such as a bad disk read) the input operation lets the stream go bad(), assuming the user can't recover it.
 - A stream that is bad() is also a fail()

#### errorHandling2
 - Since we cleared the stream state in fillVector() after a fail(), we have to set it back to fail(). We still return the failed state in case the caller can recover from the error.
 - clear(), with an argument, sets the stream state flags (bits) mentioned and only clears flags not mentioned: ist.clear(ios_base::fail-bit)
 - Don't forget to put the last character read back into the stream before returning. The caller may be able to do something with it.
 - if you call fillVector() and want to know how it went, you can test for eof() or fail() or catch the exception thrown by error 
 - ios_base is part of the iostream that holds constants such as badbit, failbit, exceptions such as failure

#### readUserData
 - a first iteration of a program promting a user for a number betwee 1 and 10 (inclusive)
 - the program doesn't check for non-numeric entries

#### readUserData2
 - conditional logic evaluates stream state
 - separation of concerns would make the program clearer

#### printObjects
 - note how overloaded right shift operator '<<' returns a reference to ostream 'ostream &'. this allows you to chain together the results of output operations
 - output streams are passed along so that you can "chain" output operations. That is, first output this object and the output second object to the output stream that is the result of the first output operation
 - 
 
