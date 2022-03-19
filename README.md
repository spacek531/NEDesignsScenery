# NEDesigns Custom Scenery Patch Project
It is obvious to all NEDesigns users that custom scenery is a wild west. There are no standards for object design, and this is most clear in the realm of quarter tile scenery, in particular trims and other decorative elements.

Trims and decorative elements often do not take up a full quarter tile, and thus are less-than-quarter-tile scenery. They are often biased to one edge or corner of the quarter tile, which causes problems when objects are constructed improperly. The same idea applies to scenery that occupies a whole tile - they too can be biased to one corner or edge and brings with it the same problems for less-than-full-tile scenery.

OpenRCT2 gives us the opportunity to fix these issues with objects editable in plaintext and the promise of versioned objects.

The improper construction of objects is not the fault of the creator. Without the knowledge of the best practices for scenery creation, creators were left to their own devices and the overall experience of using custom scenery is impacted.

The primary places the user is impacted is in non-standard rotations, improper flag setting, and wrong offsets. Non-standard rotation affects less-than-quarter-tile scenery in that variants of the same scenery, such as different heights of corner pole, must be rotated to connect to each other. Improper flag setting affects how mirror code works, and custom scenery users are limited by the scenery being improperly mirrored. Improper offsets are a major source of scenery versioning, and having a definitive good version prevents the accidental use of known bad versions.

Along with fixing the rotation and flags of objects so they mirror properly, this project has the opportunity to tweak other aspects of custom scenery:
- Standardize placement cursor
- Reduce glitching of less-than-quarter tile and less-than-full-tile scenery
- Standardize naming
- Add translations
- Standardize cost of scenery objects
- Fix zoomed-in scenery previews
- Fix glitching of multi-tile scenery
- Fix ugly slope sprites for walls

Old scenery should be cleanly replaced with the appropriate new versions, without changing the aesthetics of parks using older objects. This will occur when loading, and the colors, rotation, and other parameters as necessary will be modified in each occurrence of the scenery in the map to keep the looks the same. This is not imperative for the success of the project, but it will help cement it as the definitive custom scenery repository.
## Scope
This project should be limited to custom scenery objects that are common across many parks, following the community-accepted conventions for aesthetics. Base blocks, trims, walls, fences, and roofs are the primary targets for this project. The scope is subject to change as the creators deem it necessary.
## Missing Features
Some features necessary for full completion of this project are not yet implemented, both on the pipeline side and the game side.

- A simple method to convert .DAT objects to json does not yet exist. There does exist code to make a program to do this, but it does not work.
- Extracting sprites does exist, and OpenRCT2 will extract all the sprites from a .DAT file and put them in a folder, but there are some issues with the printed offsets that must be manually corrected when using windows.
- OpenRCT2 does not yet reliably replace custom scenery .DATs with updated json versions when the OriginalId matches.
- OpenRCT2 does not yet have any mechanism to modify existing objects when replacing them with newer versions.
## Current Pipeline
Despite some pipeline tools being incomplete or missing, it is possible to create json scenery that can replace .DAT scenery. The process is fine for scenery whose main differences are the sprites, such as base blocks.

The following steps demonstrate how to convert a scenery using current tools:

1. Find the .DAT identifier you want to use. This can be found in the object selection window.
2. Use the command line to extract all the .DAT sprites.
3. Copy an object in the same category and name the folder with the new object’s name.
4. Move the images into the object’s images folder.
5. Modify the json to suit the scenery object.
6. If the scenery is rotated the wrong way, reorder the sprites until it is the correct rotation.
7. Credit the author of the scenery
8. Get the original id identifier from the .DAT using the datnameformatter program.
9. Put the original id in the json.
    a. If the original object requires rotation, use the currently-ignored replacement field to store this information.
10. Remove the .DAT from the object folder (I put it in a ‘done’ folder outside of the object folder).
11. Test the scenery ingame.
## Pipeline enhancements
Things that would be helpful to streamline the object conversion process
- The object identifier is listed in the scenery selection window
- The game itself can export a specific object to json and sprites in the desired format into a specific folder

With these improvements, the pipeline can look like this:

1. Load up a workbench with the desired scenery in it
2. Use the pipette tool to find a piece of scenery or find it in the scenery window
3. Use the command line to export the scenery to the appropriate folder
4. Tweak the json to suit project standards
    a. Fix rotation issues
    b. Fix other sprite issues like zoomed-in preview
5. Test scenery ingame

I’m open to any other pipeline suggestions.
## How you can help

I have started by converting the scenery found in Xtreme 2017 bench. If you want to help, you can fork this repository to your own github account, download the repository, and start converting changes and making commits.
