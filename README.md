# MineSweeper
minesweeper made with c++ and sdl





## How to play

1. clone all of files in this repo

2. make an empty project in visual studio

3. goto folder which has project file(.vcxproj) and then paste all of files we cloned

4. add source files and header files

5. In visual studio, go to Project -> properties -> Linker -> Input -> Additional dependencies

6. add SDL2_ttf.lib , SDL2_image.lib , SDL2main.lib , SDL2_mixer.lib , SDL2.lib

7. go to Configuration Properties -> Include Directories 

8. add **SDL2_mixer-devel-2.0.2-VC/include** , **SDL2_ttf-devel-2.0.14-VC/include** ,  **SDL2_image-2.0.1/include** , **SDL2-devel-2.0.7-VC/include**

9. go to Configuration Properties -> Library Directories
 
10. add **SDL2_mixer-devel-2.0.2-VC/lib/x86**, **SDL2_mixer-devel-2.0.2-VC/lib/x86**,  **SDL2_image-2.0.1/lib/x86**,  **SDL2-devel-2.0.7-VC/lib/x86**


11. after finishing all of these processes , then build and play it! 
