## Live to-do list for bug and feature tracking
This document was created to help us informally track low to medium priority bugs, features, or code change requests.

- In Room1 (garden) the player can climb the tree (feature2) and interact with the gravestone (feature1) to grab the knife (object 5) before climbing down.
- There is a trailing "and" printed after each room description. This is a result of the current string concatenation setup, so we'll have to find a cleaner way to do this once we figure out how we will deal with description changes throughout the game.
- For Room1 (garden), event_one() should be tied to the object (dagger) so that this description will replay if the player drops the dagger in another room and picks it up again.