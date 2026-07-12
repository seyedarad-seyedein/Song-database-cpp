Song Database Project — Explanation
PAGE 1 — Song.h (Design of the Base Class)

This file defines the main abstraction of the whole program: the Song class. It represents a single music record with its basic properties such as title, artist, album, year, duration, and genre. The Genre enum is also defined here, which is a simple way to restrict genre values to a fixed set. This is a good use of enumeration in C++, which improves safety and readability compared to using plain integers.

The class follows encapsulation, one of the core principles of object-oriented programming. All data members are declared as private, which means they cannot be accessed directly from outside the class. Instead, the program uses public setter methods (makeTitle, makeArtist, etc.) and getter methods (getTitle, getArtist, etc.) to control access. This ensures that invalid data (like empty titles or invalid years) can be prevented.

The constructor is overloaded, meaning there is both a default constructor and a parameterized constructor. This demonstrates constructor overloading, allowing flexible object creation. The validation logic (like Validyear) shows an example of data validation inside a class.

A very important feature here is the virtual print function. This introduces polymorphism. It allows derived classes to override this function and change how a song is displayed. Also, the destructor is declared as virtual, which is necessary when working with inheritance and dynamic memory.

Additionally, the file includes static methods (genreBystring, stringBygenre), which are used for converting between enum values and strings. This is a good example of utility functions inside a class.

---

###  PAGE 2 — song.cpp (Implementation of Song Behavior)

\\\\\\\\\\\\\\\\\\\\\\\\\

This file contains the implementation of all methods declared in Song.h. It shows how the class actually behaves.

The constructors initialize the object safely using setter functions instead of assigning values directly. This ensures that validation rules are applied consistently. For example, makeYear checks if the year is valid before assigning it.

Each setter method demonstrates defensive programming, where invalid inputs are ignored instead of breaking the program. Getter methods simply return values, following the principle of controlled access.

The print method outputs all song information in a structured way. This function is important because it is later overridden in derived classes, showing runtime polymorphism.

The conversion functions (genreBystring and stringBygenre) show how data can be translated between different formats. This is especially useful for file handling.

Overall, this file demonstrates: .Function implementation . Encapsulation . Basic validation logic . Polymorphic function definition

PAGE 3 — Polysong.h (Inheritance and Polymorphism)


This file introduces inheritance, which is one of the most important OOP concepts used in your project.

class PolySong : public Song

This means that PolySong is a specialized version of Song. It inherits all properties and behaviors but adds a new field: id.

The constructor uses an initializer list, which is the correct way to call the base class constructor.

This ensures that the base part of the object is initialized properly before the derived part.

The print function is overridden. This is a direct use of polymorphism, where the same function name behaves differently depending on the object type. The derived version first calls the base class print, then adds extra information (ID).

This file clearly demonstrates:
- Inheritance (IS-A relationship)
- Function overriding
- Code reuse
- Extension of functionality

---

## PAGE 4 — Helper.h (Exception Handling and Input System)

"Saving your program from bad inputs!"


This file centralizes input handling and exceptions, which is a very good design decision.

Two custom exception classes are defined:
- BacktoMenuException
- InputExecption

These are used to control program flow instead of relying on simple conditional checks. This shows a basic but effective use of exception handling in C++.

The input functions get_int_input and get_string_input are declared as inline, which allows them to be defined in a header file safely. These functions validate input, handle invalid input using exceptions, and support navigation using -9.

This design prevents repeated code and ensures consistency across the program.

This file demonstrates:
- Custom exceptions
- Input validation
- Inline functions
- Separation of concerns

---

##  PAGE 5 — SongDatabase.h (Structure and Templates)



This file defines the songDatabase class, which manages a collection of songs.

The most important change here is the use of Song** data. This means the database stores pointers to Song objects, enabling polymorphism. It allows the program to store both Song and PolySong objects in the same structure.

The file also introduces a template function advancedSongs. This is one of the most advanced parts of your project. It allows flexible filtering of songs using lambda functions. Instead of writing multiple loops, you reuse one generic function.

This demonstrates:
- Templates
- Generic programming
- Lambda compatibility
- Code reuse

---

## PAGE 6 — SongDatabase.cpp (Core Logic and Memory Management)

This is the main logic file of the program.

It demonstrates dynamic memory allocation using new and delete, the Rule of Three, array resizing, searching, and editing.

The destructor ensures no memory leaks occur by deleting each dynamically allocated song and then the array itself.

The file also uses dynamic_cast to detect if a song is a PolySong. This is used during file saving to store additional data (ID). This is an advanced feature of runtime type identification.

File handling is done using ofstream for saving and ifstream and stringstream for loading.

The template function is used in filtering methods like listByartist, listByyear, and search.

This file demonstrates: . Dynamic memory .Polymorphism in practice . File I/O .Templates in action

PAGE 7 — main.cpp (User Interface and Control Flow)

This file controls the entire program.

It uses a loop to continuously display a menu and process user input. The program uses exception handling to manage invalid input and navigation.

The switch statement controls different operations such as listing songs, adding songs, editing, removing, and saving/loading.

Polymorphism is clearly visible in the add section where both Song and PolySong objects are created dynamically and stored in the same database.

The program uses:
- Exception handling
- Dynamic allocation
- Polymorphism
- Menu-driven logic

---

##  FINAL SUMMARY

This project combines multiple important C++ concepts into one system.

It includes classes Song, PolySong, and songDatabase, with over 30 methods across the system.

It uses object-oriented programming principles such as encapsulation, inheritance, and polymorphism.

It uses dynamic memory management with new and delete, template programming for flexible filtering, exception handling for safe input, and file handling for persistence.

Advanced features such as dynamic_cast, function overriding, and inline functions are also used.

This project is a complete C++ system demonstrating data management, object relationships, runtime flexibility, and safe input handling.
