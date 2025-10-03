# Minesweeper

A classic Minesweeper game implementation written in C++ using EasyX Graphics Library. Experience the timeless puzzle game with a graphical interface, featuring intuitive mouse controls and challenging logic.

Features
Graphical Interface: Built with EasyX Graphics Library for Windows

Classic Gameplay: Faithful to the original Minesweeper rules and mechanics

Customizable Difficulty: Choose the number of mines (from 1 to 400)

Smart Expansion: Automatic expansion when clicking on empty cells

Multiple Mouse Controls:

Left click: Reveal cell

Right click: Place/remove flag

Middle click: Mark with question mark

Win/Lose Conditions: Clear visual feedback for game outcomes

Prerequisites
Windows OS

Visual Studio with EasyX Graphics Library installed

C++ compiler

Installation & Setup
Step 1: Install EasyX Library
Download EasyX from official website

Install it for your Visual Studio version

Step 2: Prepare Image Resources
Create a folder structure:

text
Minesweeper/
├── src/
│   └── main.cpp (this code)
└── images/
    ├── 0.gif
    ├── 1.gif
    ├── 2.gif
    ├── 3.gif
    ├── 4.gif
    ├── 5.gif
    ├── 6.gif
    ├── 7.gif
    ├── 8.gif
    ├── 9.gif
    ├── 10.gif
    ├── 11.gif
    ├── 12.gif
    ├── 13.gif
    ├── 14.gif
    └── win.jpg
Step 3: Update Image Paths
Modify the image loading paths in the code:

cpp
// Change this line and similar ones:
loadimage(&img[0], "D:\\程序\\vs cpp\\扫雷\\扫雷\\扫雷图片素材\\image\\0.gif");
// To your actual image path, for example:
loadimage(&img[0], "images/0.gif");
Step 4: Compile and Run
Open the project in Visual Studio

Build and run the solution

How to Play
Start the Game: Run the executable

Set Difficulty: Enter the number of mines when prompted

Game Controls:

Left Click: Reveal a cell

Right Click: Place/remove a flag on suspected mines

Middle Click: Place/remove a question mark for uncertain cells

Game Rules:

Numbers indicate how many mines are in adjacent cells

Use logic to deduce safe cells and mine locations

Clear all non-mine cells to win!

Clicking on a mine ends the game

Code Structure
The main logic includes:

Mine Generation: Random placement of mines across the 20×20 grid

Number Calculation: Counting adjacent mines for each cell

Flood Fill Algorithm: Automatic expansion when clicking empty cells

Mouse Event Handling: Processing left/right/middle clicks

Game State Management: Tracking revealed cells and game status

Game Images Reference
0-8.gif: Number of adjacent mines

9.gif: Unrevealed cell

10.gif: Flag

11.gif: Question mark (unused in current code)

12.gif: Question mark (used for middle click)

13.gif: Mine (revealed when game over)

14.gif: Unknown (unused in current code)

win.jpg: Victory screen

Possible Improvements
Add timer functionality

Implement classic difficulty presets (Beginner, Intermediate, Expert)

Add sound effects

Create a restart button

Add high score tracking

License
This project is provided for educational purposes. Feel free to modify and distribute.

Challenge yourself to clear the board with maximum mines! 💣

