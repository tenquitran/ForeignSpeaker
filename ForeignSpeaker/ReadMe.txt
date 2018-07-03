ForeignSpeaker - a WinAPI application used as an aid in learning foreign languages (currently, only English).
Simulates another participant in a pre-defined dialog.

Created: June 27, 2018 (based on an older project)

---------------------------------------------------------

Dialogs are read from plain text files stored in the specified directory. Recursive searching of files is supported.
In each file, dialogs should be separated by lines with three asterisks as shown below.

NOTE: the "content" subdirectory containing sample dialogs is suitable only for testing.
Files are supposed to be created by the user according to his/her needs.

---------------------------------------------------------

A sample file containing two dialogs:

***

A: Hello, Robert!
B: Hello, Stanley!
A: How are you?
B: Fine, thanks! And you?

***

A: Hello, Sarah!
B: Hello, Will!
A: How are you?
B: Fine, thanks! And you?

***

---------------------------------------------------------

TODO:
- add speech synthesis
- add random dialog selection
- add logging of major successful events (the end of files parsing, etc.)
