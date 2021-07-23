#define _CRT_SECURE_NO_WARNINGS

#define height 10
#define width height
#define debug debug_state
#define global_amount 8

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct object
{
	int xpos;
	int ypos;
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
	int warp[3];
};

void load_settings(FILE* settings);
void init_screen(char array[60][30]);
void print_screen(char array[60][30], int pos[2], struct tile* local_tiles, int tile_ids[width][height], int loaded_tile_ids[8]);
int col_check(int array[width][height], int ref[width][height], int pos[2], char input, struct tile* local_tiles, int loaded_tile_ids[8], struct asset* scenes, int tile_ids[width][height], int tile_frequency[100], struct tile* Tiles, int warp_def[3]);
void update_location(int array[width][height], int ref[width][height], int pos[2], char input, struct tile* local_tiles, int loaded_tile_ids[8], struct asset* scenes, int tile_ids[width][height], int tile_frequency[100], struct tile* Tiles, int warp_def[3]);
void load_scene(struct asset* scenes, int tile_ids[width][height], int ref[width][height], int tile_frequency[100], int pos[2], int warppos[3]);
void print_menu(char text[]);
void init_tile_pointer(struct tile* tile);
void init_tile(struct tile* tile);
void init_tiles(struct tile* local_tiles);
void print_tile(struct tile* tile);
void print_tile_ids(int tile_ids[width][height]);
void get_frequency(int tile_ids[width][height], int tile_frequency[100]);
void print_frequency(int tile_frequency[100]);
void load_tiles(int tile_frequency[100], int tile_ids[width][height], int loaded_tile_ids[8], struct tile* local_tiles, struct tile* Tiles);
void init_local_tiles(struct tile* local_tiles, int tile_frequency[100]);
int unique_local_tile_count(int tile_frequency[100]);
void change_scene(struct asset* scenes, int tile_ids[width][height], int ref[width][height], int tile_frequency[100], int pos[2], int warppos[3], int loaded_tile_ids[8], int warp_def[3], struct tile* Tiles, struct tile* local_tiles);
