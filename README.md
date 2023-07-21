# Watopoly
Watopoly is an exciting variant of the classic Monopoly game, tailored to the University of Waterloo campus. In this game, players move around the campus board, and various actions take place based on the squares they land on. The ultimate goal is to stay in the university by managing finances wisely and outlasting your opponents without declaring bankruptcy.

This project implements Watopoly using the C programming language with a focus on Object-Oriented Programming (OOP) principles. It utilizes the observer pattern with the publish-subscribe model to manage events and interactions between game components.

# Features
* Custom University of Waterloo campus-themed game board with 40 squares.
* Players can move around the board and trigger actions based on the squares they land on.
* Property acquisition and management, similar to Monopoly's property buying and rent-paying mechanics.
* Special squares with unique events, such as "Co-op Work Term" or "Hackathon."
* Ability to save and load the game state to continue playing later.
* Intelligent computer-controlled players for single-player mode.
* Multiplayer support for up to 8 players (8 determined during game setup).
* Command-line interface for user interaction.

# How to Play
1. Choose the number of players and their names at the start of the game.
2. Players take turns in order, rolling the dice and moving around the board.
3. When a player lands on a square, the corresponding action occurs, such as purchasing property, paying rent, or drawing a card.
4. Use the command-line interface to manage property, view player stats, save/load the game, etc.
5. The game continues until all players except one have declared bankruptcy.

# Observer Pattern with Publish-Subscribe Model

Watopoly uses the Observer Pattern to handle events and interactions between game components. The Publish-Subscribe Model enables loose coupling between objects, allowing the game to efficiently manage and respond to various events.

In the context of Watopoly, different components like the board, players, and cards act as both observers and publishers. For example, when a player lands on a square, the square notifies the player about the action, and the player's status may update accordingly.

UML Diagram
![Watopoly UML Diagram](https://github.com/KokYenZein/Watopoly/blob/main/watopolyDD2UML.drawio.png?raw=true)

The UML diagram above illustrates the class hierarchy and relationships in the Watopoly project. It showcases the objects and their interactions in the Observer Pattern implementation.
