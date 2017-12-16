###### Created: 12-03-17


# Questions
1.) If a method A() accepts a reference to filestream, modifies its stream state, and doesn't return the filestream to the calling method B(), will the changes made by A() show up when control returns to B()? Because we pass by reference not by value, B() should still see whatever changes A() made.   

