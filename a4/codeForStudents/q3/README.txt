The code in this directory will not build a complete program.  You will need to
use your solution for Q2 as a starting point i.e. add in the AsciiArt class as well
as the Decorator class and its subclasses.

This directory includes:

* an updated main.cc, with a test harness that recognizes the command set
  for this problem
* the files window.h and window.cc for creating XWindows graphics
* the files subject.h and observer.h, which define the public interface
  for subjects and observers; you will need to supply a subject.cc file
  that completes the implementation of subject.h (observer.cc isn't required
  since all of the methods are either pure virtual or default)

You will need to modify the Studio class, such that it becomes a subclass
of Subject, and such that its printing responsibilities are now delegated
to Observer objects.  **Your updated Studio class should not print anything.**
This means the functioning of Studio::render will change.

Also remember to add the -X11 linking flag to the linking portion of your
Makefile.

Tip: You can do:

	cat sample.in - | ./a4q3 

to stop the window from closing when you read in from a file. Just press Ctrl-d to
simulate EOF to stop the program.

See the handouts "Setting up X11.pdf" and "Setting up X forwarding for Windows.pdf"
in your repository's handouts folder.
