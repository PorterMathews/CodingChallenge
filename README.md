# CodingChallenge

The program is meant to be run from the command line. All you will need is an IDE that compiles and runs C++ code.

I uploaded a PDF of my initial thoughts and pseudocode. I started with this rough outline, jotting down some edge cases to consider after writing the first draft of my code. I completed the first draft and most of the edge case management between 2.5 and 3 hours in. My goal was to create robust code that wouldn't break due to user input. I then went back through the code to clarify comments and check for efficiency. I suspect there are faster ways to achieve what I did, and while I'm not yet familiar with the best practices for writing fast code, I am keen on learning. Reviewing my code and playing the game took the full 4 hours allotted.

I also realized that I didn't read item 4b closely enough and missed what it was asking me to do. I already had a vector tracking guessed letters. I could have created a new one for missed letters and had it displayed with every guess.

Here is a link to CLion in case you need a IDE https://www.jetbrains.com/clion/download/#section=windows. I'll put the steps bellow to get g++ working. I don't think you'll need this, but I do want to give you everything you'll need to compile and run the code.

How to get g++ working with CLion (if you don't have a C++ compiler for some reason)
1. Navigate to your CLion installation folder. If you didn’t change it, it is probably in “C:\Program Files\JetBrains\CLion <version number>”.
2. From there, open the “bin” folder, then the “mingw” folder, and then the “bin” folder. You should see a file called “g++.exe” in this folder.
3. Copy the path to the bin folder. It should look something like this: “C:\Program Files\JetBrains\CLion<version number>\bin\mingw\bin”
4. In the Windows search bar, search “Edit the system environment variables”.
5. Click “Environment Variables…”. In the list of User variables, click “Path” and then “Edit…”.
6. Click “New” and paste the file path you copied earlier.
7. Close and re-open the terminal.
8. Open a new terminal and type: "g++ --version"
9. You should see a message with the version of g++ you have installed!

Once you have that navagate to the .cpp file and compile it with "g++ main.cpp". You can than run the program is "./a.out".
Have fun!
