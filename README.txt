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
    IMPORTANT:
        if you use Cygwin, it comes prepackaged with python 2. You can uncheck to install simply by searching for python.
        There is a workaround I found for running the python 3 based ground software in Cygwin which will not conflict with the 2 install.
        If you navigate in Cygwin to where your root is (cd ~) and run the ls -a command you will see a file called .bash_profile.
        Open this file with any text editor and add the line alias python3=location/of/python/install.exe pointing to wherever the python 3 .exe file is
        (by default it should be in C:/Users/usernam/AppData/Local/Programs/Python/Python37/python.exe)
        Doing this will allow you to essentailly pipe the ground software into the python interpreter by calling the command: python3 groundControl.py
        which can also easily be made into a script to open with one click.
        
        
        
Software segments:

    Flight Code:
        The flight code references all code which will be on board the actual sat. For now this only counts the code on the MSP430FR5969 main controller.
        There are a few key things to know about the flight code which will make development easier
        
        Navigating the code base - The code base can be a bit intense because of the many layers that I added. The intent of that is so that there isnt a great
        need to always go to the manual to understand how different modules work. It is also designed to make the code portable. Ideally, most of the code in application.c,
        messageHandler.c, and commandHandler.c would not have to change at all even if a completely different micro controller were to be selected. To navigate the code successfully,
        The two most important files to look at are likely pinUsage.h and commandHandler.h/.c.
        
        pinUsage.h - the intent of this file is to list all the pins on the chip (no so portable i know) and there for all the possible usages of the chip. To this effect
        I have listed all 48 pins on the MSP430FR5969 and a few have other #defines next to them. The point of these is to only need to reference the def when wanting to
        use the pin. for example, if the nichrome deployment is on P1.0 (its not just example), but all of the sudden that pin is needed for some other function, instead
        of having to find every place that pin is used in the code, the def NICHROME_ON_OFF can simply be moved to the new pin and assigned the corret pin value. In addition
        if the port changes, at the top of the file, each module has the associated port. When wanting to use the nichrome, one can simply call NICHROME_CONTROL_PORT, NICHROME_ON_OFF
        
        commandHandler - This file holds the entry for each of the commands which can be given to the system. In addition it will have the function calls which are made for each command
        allowing easy exploration of what each command is doing on a lower level. In addition, the file messageHandler.h holds a group of command structures. These structures are the
        way that new commands can be easily added. As an example, we can look at the input structures. There is one main input struct called inputMsg which holds 3 things: 
        1. the message length, every message must have a message length which includes the lenght of this data itself (2 bytes). 
        2. the opcode, every message also has one of these which is how the command handler chooses which function set to call. This single byte must also be included in the msg length
        3. the payload, this can be empty and is actually a union of other structs. 
        The purpose of the union within the payload is so that one inputMsg can represent all commands and this inputMsg can be passed through functions by pointer.
        When making a new command the different parts of the payload for that command are specified, and the command should then be added to the union. with just those two steps
        the new command can be transfered to the command handler. 
        
    Ground Software:
        The ground software is a Python 3 program whcih is pretty simple. It can be run with any python interpreter, but for safty its best to use a version newer than
        python 3.4 for all the packages to be fully functional. The program itself is essentially a while loop which reads user input for which command to run, and then sends
        the needed data to the sat. Each command has access to the send_msg and read_rsp functions which can be used to send and read all the data. Seperately the data can
        be decoded and determined to be correct/usefull. 