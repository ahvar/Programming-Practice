# File Reading
Contains programs demonstrating common operations for reading/writing to file streams. Programs are organized into directories focusing on a particular topic.

## Topics

### Open Files
 There are four possible stream states: good() means the operations succeeded, eof() means we hit the end of the input(), fail() means something unexpected happened, bad() something unexpected and serious happened.

###### Programs
 - **openFile**: 
 - **openFile2**: 

### Dates and Temperatures
 - The right shift operator skips whitespace. Whitespace includes newline '\n', tabline '\t', and space ' ' characters. So the input loop in openFile reads text into contents and then the next line of code prints the contents of "contents" to the output file. The result is a line without the newline characters contained in input.txt. 

###### Programs
 - **tempReader**:
 - **tempReader2**:
 - **printObjects**: note how overloaded right shift operator '<<' returns a reference to ostream 'ostream &'. this allows you to chain together the results of output operations. output streams are passed along so that you can "chain" output operations. That is, first output this object and the output second object to the output stream that is the result of the first output operation

### Handling Errors
If an input operation encounters a simple format error, it lets the stream fail(), assuming it can be recovered by the user.
If the problem is more serious (such as a bad disk read) the input operation lets the stream go bad(), assuming the user can't recover it. A stream that is bad() is also a fail().

###### Programs
 - **errorHandling**: We define a structure to contain the hour and temperature data for a single reading and then create a list to hold all the readings. Declare variables to hold time and temp data and use a loop to read data into variables. Iinside the loop, check for an invalid time and insert a new Reading struct into the list. The output loop writes the data for each struct contained in the Reading vector to the output file.

 - **errorHandling2**: Since we cleared the stream state in fillVector after a fail(), we have to set it back to fail(). We stil return the failed state in case the caller can recover from the error. clear(), with an argument, sets the stream state flags (bits) mentioned and only clears flags not mentioned: ist.clear(ios_base::fail-bit). Put the last character read back into the stream before returning. The caller may be able to do something with it. ios_base is part of the iostream that holds constants such as badbit, failbit, exceptions such as failure.

## Resources and References

 - *The C++ Programming Language* (Stroustrup)
 - *C++ IOStreams and Locales* (Langer)



