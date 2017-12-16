###### Created: 12-15-17


# Why Create an Error Log?
 This is a log of compiler errors encountered while writing and debugging the programs contained in this directory. The below list outlines the rationale for keeping a log:
 1.) Documentation of error messages can be referenced when those same, or similar, errors are seen in future work. 
 2.) As an exercise, explaining the causes or mechanisms behind error messages in my own words requires research and work to fully understand what happened. 
 3.) Modular writing that is clear, concise, and easy to read/scan is important for documentation and content. Creating this log is another way to practice this skill.


# Programs

#### tempReader and tempReader2
- compiler output: "invalid initialization of non-const reference type...from an rvalue of type..."
- problem code: ofstream &ost{"filename.txt"}
- problem code: 

ofstream ost{"datesAndTemps2.txt"};
  ...

generateData(&ost);


- explanation: from ofstream documentation for initialization constructor: "internally, its ostream base constructor is passed a pointer to a newly constructed filebuf object (the internal file stream buffer)."
 


