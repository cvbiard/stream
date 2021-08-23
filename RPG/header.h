#define _CRT_SECURE_NO_WARNINGS

#define height 10
#define width 10
#define tile_width 2
#define tile_height 2
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
 * Currently, tile sizes can be completely customized to any dimention, but due to movement anything different than a 10x10 screen breaks, you can walk out of bounds
 */
int calc_screen_size(int border);
void map_pos(int linear_pos[(height*width)][2]);
void print_screen_map();
void mapping(int tile_map[(height*width)][(tile_height*tile_width)], int screen_size);
void screen_manager(int *scrstr, int *bgmap, int tile_map[(height*width)][(tile_height*tile_width)], struct tile* Tiles, int tile_ids[width][height], int tile_frequency[100], int *linear_ids, int pos, char player_tile[18], int screen_size);
void print_screen(int *scrstr, int screen_size);
void load_scene(struct asset* scenes, int tile_ids[width][height], int tile_frequency[100]);
int move(int *scrstr, int *bgmap, int tile_map[(height*width)][(tile_height*tile_width)], char input, char player_tile[18], int *linear_ids, int linear_pos[(height*width)][2], struct tile* Tiles, struct asset* scenes, int tile_ids[width][height], int tile_frequency[100], struct object *player, int screen_size);
void print_menu(char text[]);
void get_frequency(int tile_ids[width][height], int tile_frequency[100]);
void debug_printer(int number);