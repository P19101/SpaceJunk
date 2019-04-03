READ ME

Welcome to the P1x101 project team!!!
This file's job is to help you get all the software and files needed to run the project as expected.
Specific help files exist throughout the project which have greater detail than this file.
Below there is a list of  requirements and furtheron there will be specfic instilation help for each one. 

Requirements:
    Python 3.x (I used version 3.7 so would recommend something at least that new)
        https://www.python.org/downloads/
        
    TI Code Composer (this is what i used and its not a great IDE, but idk what else might work. There are others out there if you feel it nessisary)
        http://processors.wiki.ti.com/index.php/Download_CCS
        
    GIT 
        https://git-scm.com/downloads
        
    If using windows then you should also get a terminal emulator. I used
    Cygwin
        https://www.cygwin.com/
        
        
        
Python 3.x
    If you download the installer from the link I put in, there will be a very simple GUI to bring you through the instilation process. 
    On Windows:
        -select a custom instilation on the first page.
        -On the page titled Optional Features, Ensure that "pip" is checked.
         This will ensure that pip is installed which is a usefull package installer.
        -on the page titled Advanced Options select "Add Python to environment variables" VERY IMPORTANT
        -choose where you want to install it (probably just the default location) and wait for it to finish. 
        -you should be able to search for python and the python terminal will come up to let you know its installed. 
        
    On linux:
    
    On MAC:
        -No idea sorry macs are lame :P (but seriously you should easily be able to look it up and just look at
        the windows settings to check the things you want, its probably similar.)

TI Code Composer
    
    Once installed:
        -Create a new project by going to file->New->Project
        -On the next page, go to C/C++ and select C Project and hit next
        -name the project something easy to remember
        -uncheck "Use default location" and put the project somewhere easy to get to
         (i found the default location to be a pain to get working correctly)
        -under the 'Project type:' window go to executable and select "empty project"
        -skip through the rest of the installer with default settings
        -After the project is open, go to Project->Properties (if the option is greyed out, right click the project on the left side and choose properties there)
        -set the target device to the MSP430FR5969
        -manually add the files from the project once they are downloaded by right clicking the project and selecting "Add Files..."
         at first only add all the .c files to the project. when asked, select to Link to files, instead of Copy
         Then follow the same steps to add all the .h files. when doing so, CCS should give the option to add the files as an include, say yes.
         Once the headers are set as includes, when new .h files are made they dont have to be added to the project.

Git

    -Download the installer for your operating system.
    -click next until getting to the page titled Adjusting your PATH environment,
     and select Git from the command line and also 3rd party software. 
    -select all default settings otherwise and install
    
Cygwin
    -Select Install from internet on the first page
    -Install in a place where you will find it and for All Users
    -Use the default settings untill getting to the Choose A Download Site page
     You can just select one of the first two options in the list, its
     just a bunch of places that have the source code
    -There is a ton of options for packages you can install. The only key ones I would grab are gcc and make
     find them by searching gcc and selecting gcc-core and then search for libgcc1 and ensure that is also selected
     Also search for make and there should be a gnumake or something similar, select that. 
     I would search for git and unselect it if checked because you should have installed it stand alone previously.
    -wait for the install to finish. 
    