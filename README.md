# CSMP-TSCVideosTools
A set of tools to make easier to play videos on Cave Story Multiplayer using TSC scripts

For the time being, These are only compatible with Windows 8.1 or later

**You can find the instructions on how to use it on the Manual-Instructions.txt file included in the release downloads, Or get it manually on the Docs,Textfiles folder from Github**

## Programs featured :
### renameToDoukutsu.exe
Batch renames your files to be read by Cave story
You can also set an offset to the files, so their name can start in a specific number, allowing for multiple videos in a single mod
### createTSC.exe
Creates a TSC script ready to just be pasted into your game for your video to play!
Allows configuration for 3 supported framerates (10,12,15) and as well several options to configure and allow almost full control of the generation of the script
### PrepareFiles.exe
Messed up one of the steps and want to rename your files again?, This tool will help you to rename all again so you can change your mind if you need a specific ID free!

## Building
You can build it on your preffered c Compiler, for this case, we'll use gcc
Currently is only supported on **Windows 8.1 or newer**
1 - You will need to install gcc (https://github.com/msys2/msys2-installer/releases/download/2024-12-08/msys2-x86_64-20241208.exe)

2 - afterwards run in the MSYS2 terminal `pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain` and accept all the packages in there

3 - You will need to add the file path of the MinGW-64 bin folder in your Environtment variables (If used the default folder, Should be `C:\msys64\ucrt64\bin`

4 - Save the configurations and open CMD

5 - If done correctly, You should be able to run the command gcc --version

6 - To compile your source files, Go to the src folder, and run the following : 

```
gcc renameToDoukutsu.c -o renameToDoukutsu.exe
gcc createTSC.c -o createTSC.exe
gcc prepareFiles.c -o prepareFiles.exe
```

7 - Afterwards,just create a folder named `dropImagesHere` and if desired, drop in there the contents of the `Docs,Textfiles` folder
