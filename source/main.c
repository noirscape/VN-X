// VN-X - VNDS interpreter for the Nintendo Switch
// Copyright (C) 2018  Valentijn "noirscape" V.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.
#include <stdio.h>
#include <stdlib.h>
#include <switch.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "struct.h"

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Surface *window_surface;
char current_string[8192];

void init_sdl()
{
    //Setting up SDL
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_CreateWindowAndRenderer(1270, 720, 0, &window, &renderer);
    window_surface = SDL_GetWindowSurface(window);

    IMG_Init(IMG_INIT_JPG | IMG_INIT_JPG);    
}

CurrentStatus process_line(char* current_string)
{
    char* text_compare = "text";
    if (strstr(current_string, text_compare) == text_compare)
        return {};

}

void draw_updates(CurrentStatus* current_status, CurrentStatus* previous_status)
{
    // Draw background

    // Draw foreground

    // Draw text
}

void start_vn(char* path)
{
    // Check for save data (prompt if found, and if so load it)

    // Open main file
    FILE *current_file = fopen(strcat(path, "/script/main.scr"), "r");

    // Line counting
    int lines_read = 0;
    CurrentStatus previous_status = {"", "", "", false};

    // Play lines up until input
    while(fgets(current_string, 8192, current_file) != NULL) {
        CurrentStatus current_status = process_line(current_string);
        draw_updates(&current_status, &previous_status);
        // Await key inputs
        if (current_status.user_input == true)
        {

        }
    }
}

int main(int argc, char **argv)
{
    init_sdl();
    open_vn("sdmc:/test-vn");
    return 0;
}

