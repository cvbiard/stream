#define _CRT_SECURE_NO_WARNINGS

#define height 10
#define width height
#define debug 't'
#define global_amount_tiles 11
#define global_amount_scenes 2
#define trans_symbol 'X'
#define blank_symbol 'x'

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct object
{
	int pos;
};
struct asset
{
	FILE* visual_asset;
	char* file;
};
struct tile
{
	int id;
	char** layout;
	FILE* asset;
	char flags[2];
	char* file;
	int warp[2];
};

/*NOTES
 * As a next step I want to rework the tile system to be scalable with a resolution. Right now all tiles are 6x3 and the screen is 10x10. I want to make both customizable, with the purpose of making the engine usable beyond
 * just this project.
 */
void map_pos();
void print_screen_map();
void tile_mapping(int tile_map[100][18], int screen_mapping[1984]);
void screen_manager(int scrstr[1984], int bgmap[1984], int tile_map[100][18], struct tile* Tiles, int tile_ids[width][height], int tile_frequency[100], int linear_ids[100], int pos, char player_tile[18]);
void print_screen(int scrstr[1984]);
void load_scene(struct asset* scenes, int tile_ids[width][height], int tile_frequency[100]);
int move(int scrstr[1984], int bgmap[1984], int tile_map[100][18], char input, char player_tile[18], int linear_ids[100], int linear_pos[100][2], struct tile* Tiles, struct asset* scenes, int tile_ids[width][height], int tile_frequency[100], struct object *player);
void print_menu(char text[]);
void get_frequency(int tile_ids[width][height], int tile_frequency[100]);