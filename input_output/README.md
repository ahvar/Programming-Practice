###### Created: 12-03-17


# Topics

#### I/O Error Handling
 - there are four possible stream states: good() means the operations succeeded, eof() means we hit the end of the input(), fail() means something unexpected happened, bad() something expected and serious happened
 - 


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