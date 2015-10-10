# CPlusPlusRPG
This is a text-based role-playing game using C++ 11.  As this project is a work-in progress, much of the functionality has not yet been developed, but this readMe file details what I aim to accomplish.
Object attributes (ex. Location descriptions, weapon min and max damage) are stored in text files. 

The world:
The player explores a 2-dimensional map.  Characters on the map represent different location types:
V – Village.  Player may encounter non-player characters (NPCs).  NPCs may give the player quests or hints about where to find special items, monsters, etc.
T – Trees.  Player can move on these cells.
M – Monster lairs.  Here the player will encounter monsters to fight
R – Rocks.  The player cannot move on these locations
C – Caves.  These places are locked by default.  The player must complete certain tasks in order to unlock these locations.
W – Water.  These locations are also locked by default.  
P – Represents the player.

Inventory:
The player has an inventory and can pick things up and drop them.  Dropped items remain where they were dropped.  The player can also buy and sell things from merchants (special NPCs).  Some items can also be used (as with potions) or equipped (as with weapons).  Using or equipping item effect player attributes (ex. equipping a waraxe increases min and max damage).

Quests:
At present, I have not yet begun developing the storyline or quests.  But I have found this post that has some great ideas that I will use: http://www.gamedev.net/topic/652095-help-on-how-to-implement-stories-and-quests-on-an-rpg/


