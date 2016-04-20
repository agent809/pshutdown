# pshutdown
This program is to help mange installed programs at shut the time of shut down. When you shut
down this program will show you all the installed and removed programs that were installed/
removed during your current session. It also gives you the option to reinstall or remove the
programs. Good for keeping clutter out of your system. The default package manager is pacman
however you can change this in the config.

INSTALL
(note python3 must be installed and run when the python command is called, code
can easily be changed to fix this however)
(I am adding an installer in a later update, however for now this is required)
To install this program correctly you must add the two files contained within the download
to "your home folder/pshutdown" and  add that folder to your bash path. Then you have to add
the command "pshutdown -su" to run at startup or in your .bash_profile. Then you
are all set to use pshutdown!. simply run the program pshutdown when you want to sutdown your
computer instead of the regular shutdown command.
