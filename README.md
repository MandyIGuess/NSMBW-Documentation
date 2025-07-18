# NSMBW-Documentation
Documentation and stuff for various parts of NSMBW.<br>
This will mainly contain documentation for game classes for layouts, as well as other things.


Feel free to use any of this stuff in your own projects!!!

## Info
All addresses are based off the PALv1 version of the game.

Feel free to remove any comments, they're just present to help explain what does what.

## Documented Classes
- `dCyuukan_c`: Contains temporary level data that gets used when starting a level from a checkpoint
- `dInfo_c`: Contains information and data used throughout the game
- `dStageTimer_c`: Manages the level clock/timer
- `dStartInfo_c`: Stores info when the level starts
- `PauseManager_c`: Manages the stage Pause Menu

### Layouts
- `dContinue_c`: Player Continues screen
- `dCourseSelectMenu_c`: Pause menu for the World Map
- `dInfoWindow_c`: Savefile copy/deletion confirmation window
- `dLetterWindow_c`: Bowser Jr.'s letter
- `dModelPlayGuide_c`: Frame shown on-screen during Hint Movies
- `dOtasukeInfo_c`: Prompt for starting or ending Super Guide Replays, as well as exiting Hint Movies
- `dSequenceBG_c`: Screen background for the Main Menu/Game Setup sequence
- `dStockItemShadow_c`: Item counts and button "shadows" for the Stocked Items/Powerup screen
- `dWorldSelectGuide_c`: Title and button prompts for the World Selection screen
- `Pausewindow_c`: Pause menu for levels

### Scenes
- `dScRestartCrsin_c`: Used to start certain levels, such as the titlescreen, Super Guide replays, and Hint Movies

### Utility
- `dHeapAllocator_c`: Heap allocator for loading models or other resources

## Other Files
- `general.h`: Contains general/non-specific functions from the game

## TODO
- Classes todo:
  - `EGG::Heap`, needed for dStageTimer_c::createInstance()
- Add symbols for functions
- Add cleaned up and improved Newer headers(?)