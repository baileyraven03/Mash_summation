# Mash_summation
This is a very basic program written in C that allows the user to input a random assortment of numbers and letters, without spaces.

Firstly the file associated witht his is opened, and  check to enusre it opens properly.
This is then scanned through and any inputs are written onto the file, regardless of what they are. This goes on until the program encounters a space.

Following this file is closed before being re-opened in 'read' mode. 
This is again checked to have opened properly.

Using a while loop, to ensure the file is not at it's end, the text is looped through and the number is both added to the total and the count is updated accordingly. 
Then the corresponding message and values are printed to the user, depending on the ammount of nubers they've inputted, before the file is closed.

Finally the file is closed and the user is asked if they would like to go again. 
