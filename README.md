# Qt Tic-Tac-Toe Game

This is a simple Tic-Tac-Toe game implemented using Qt and C++. It features a graphical user interface and an AI opponent.

## Building the Game

1. Ensure you have Qt 6 and a compatible C++ compiler installed.
2. Clone this repository
3. Open the project in Qt Creator.
4. Build and run the project using Qt Creator's build system.

## C++ Concepts Used

This project demonstrates several C++ and Qt concepts:

1. **Classes and Objects**: The `MainWindow` class encapsulates the game logic and UI.

2. **Inheritance**: `MainWindow` inherits from `QMainWindow`.

3. **Function Overriding**: We override virtual functions from the base class.

4. **Pointers**: Used extensively with Qt widgets and for the game board.

5. **2D Arrays**: The game board is represented as a 2D array of buttons.

6. **Enums**: Used for representing player turns and game states.

7. **Loops**: For iterating over the game board.

8. **Conditionals**: Used in game logic for checking wins and moves.

9. **Signal-Slot Mechanism**: Qt's event handling system for button clicks.

10. **Lambda Functions**: Used in some event connections.

11. **Memory Management**: Proper cleanup in the destructor.

12. **Header and Source File Separation**: Demonstrating good code organization.

13. **QString and QFont**: Qt's string and font classes for text handling.

14. **QGridLayout and QVBoxLayout**: For organizing the UI elements.

15. **Custom Slots**: For handling game logic like button clicks and AI moves.

This project is my first attempt in learning QT, its something one can knockout in an afternoon
