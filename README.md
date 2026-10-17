# rpg-combat-engine
Readme.md
C++ Console RPG Combat & Inventory Engine (V2)

A lightweight, turn-based console RPG combat engine written in modern C++ following the Google C++ Style Guide. 

This project demonstrates core software engineering principles, structured control flow, modular architecture, and stack recursion for combo-damage calculation.


Key Features & Gameplay Mechanics

Turn-Based Combat Loop: Fully controlled battle cycle driven by while logic and clean switch-case flow control.

Dynamic Armor Penetration: Realistic damage mitigation algorithm — incoming attacks strip armor first before reducing player health.

Inventory & Item Management: Static array-based potion system allowing consumable health recovery during battle.

Recursive Combo Engine: A recursive CalculateComboDamage function that processes multi-strike berserk attacks directly on the call stack.

Real-Time Battle Feedback: Sequential state updates showing status before and after enemy counter-attacks.

Software Architecture & Code Quality

Modular Structure: Pure function separation (TakeDamage, HealHero, DisplayStatus, CalculateComboDamage) to avoid code duplication (DRY principle).

Google C++ Style Guide: Strictly formatted using clean naming conventions, explicit scoping, and explicit namespace qualification (no using namespace std;).
White-Box Tested: Manually tested and debugged for edge cases, loop boundaries, and infinite resource bugs.


How to Run:

 Requirements
Any standard C++ compiler (g++, clang++, or MSVC) supporting C++17 or higher.

Compilation & Execution (Terminal / Command Line)

bash
Compile the project
g++ -std=c++17 rpg_combat_engine.cpp -o rpg_engine

Run the executable
./rpg_engine
