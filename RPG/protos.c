#include "header.h"

/* I would like to load the background to a string. I would like the string to be able to be printed as is, instead of having to jump around during printing.
 * Define the string location for each tile, then load tiles as needed into those locations
 *
*/

void map_pos()
{
    FILE* linear_pos = fopen("linear_pos.txt", "w");
    int tick = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            fprintf(linear_pos, "{%d, %d},", i, j);
            tick = tick + 1;
        }
    }
    fclose(linear_pos);
}
void print_screen_map()
{
    int screen_map[1984] = {0};
    int count = 0;
    FILE* outfile = fopen("screen_map.txt", "w");
    for (int i = 0; i < 62; i++)
    {
        //printf("#");
        screen_map[count] = 102;
        count = count + 1;
    }
    for(int l = 0; l <10; l++)
    {
        for (int k = 0; k < 3; k++) {
            //printf("#");
            screen_map[count] = 102;
            count = count + 1;
            for (int i = 0 + (l*10); i < 10+(l*10); i++) {

                for (int j = 0; j < 6; j++) {
                    //printf("%d", i);
                    screen_map[count] = i;
                    count = count+1;
                }
            }
            screen_map[count] = 102;
            count = count+1;
            //printf("#");
        }
    }
    for (int i = 1922; i < 1984; i++)
    {
        //printf("#");
        screen_map[count] = 102;
        count = count + 1;
    }
    for (int i = 0; i<1984; i++)
    {
        fprintf(outfile, "%d, ", screen_map[i]);
    }
    fclose(outfile);
    print_screen(screen_map);
}
void tile_mapping(int tile_map[100][18], int screen_mapping[1984])
{
    for(int i = 0; i <100; i++)
    {
        for (int j = 0; j <18; j++)
        {
            tile_map[i][j] = 0;
        }
    }

    for (int i = 0; i<1984; i++)
    {
        for(int j = 0; j<18; j++)
        {
            if (tile_map[screen_mapping[i]][j] == 0)
            {
                tile_map[screen_mapping[i]][j] = i;
                break;
            }
        }

    }

    for(int j = 0; j <100; j++)
    {
        for (int i = 0; i <18; i++)
        {
            if (i == 17)
            {
                printf("%d}, ", tile_map[j][i]);
            }
            else if (i == 0)
            {
                printf("{%d, ", tile_map[j][i]);
            }
            else
            {
                printf("%d, ", tile_map[j][i]);
            }

        }
        printf("\n");
    }


}
void screen_manager(int scrstr[1984], int bgmap[1984], int tile_map[100][18], struct tile* Tiles, int tile_ids[width][height], int loaded_tile_ids[8], int tile_frequency[100], int linear_ids[100])
{
    int unique_count = 0;
    int used_tiles[100] = {0};
    int tick = 0;

    //Transforms tile_ids from 10x10 grid to a linear 100
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            linear_ids[tick] = tile_ids[j][i];
            tick = tick+1;
        }
    }

    //system("PAUSE");

    //Sets the whole screen to # (35). If overwriting works, this should just leave a border of #
    for(int i = 0; i<1984; i++)
    {
        scrstr[i] = 35;
    }

    //Log the ID of each unique tile that will need to be loaded, as well as count how many
    for(int i = 0; i<100; i++)
    {
        if(tile_frequency[i]>0)
        {
            for(int j = 0; j<100; j++)
            {
                if(used_tiles[j] == 0)
                {
                    unique_count = unique_count + 1;
                    used_tiles[j] = i;
                    break;
                }
            }
        }
    }

    //Opens the file for the current tile being loaded, and loads it into a linear array while eating newlines
    for(int i = 0; i<unique_count; i++)
    {
        FILE* loaded = fopen((Tiles+used_tiles[i])->file, "r");
        char current[18];
        for(int n = 0; n < 18; n++)
        {

            fscanf(loaded, "%c", &current[n]);
            //printf("%c", current[n]);
            if(n == 5 || n == 11 || n == 17)
            {
                fscanf(loaded, "%*c");
                //printf("\n");
            }
        }
        fclose(loaded);

        //Scrubs through tile ids in order, and if any of them match ids with the currently loaded tile, uses the tile_map to write each line of the tile to the right position in the screen string.
       for (int m = 0; m <100; m++)
       {
           if(linear_ids[m] == (Tiles+used_tiles[i])->id)
           {
               for(int p = 0; p<18; p++)
               {
                   scrstr[tile_map[m][p]] = (int)current[p];
               }
           }

       }
    }

    //Updates the background map for future use to restore a tile on the screen that gets changed from moving tiles
    for (int i =0; i<1984; i++)
    {
        bgmap[i] = scrstr[i];
    }

}
void print_screen(int scrstr[1984])
{

    int line_pos = 0;
    for(int i = 0; i<1984;i++)
    {
        printf("%c", (char)scrstr[i]);
        if(line_pos == 61)
        {
            printf("\n");
            line_pos = -1;

        }
        line_pos = line_pos+1;
    }
}
/*void create_screen(char array[60][30])
{
    //Populates the screen character array so memory is allocated for the correct amount of characters
	for (int i = 0; i < height*3; i++)
	{
		for (int j = 0; j < width*6; j++)
		{
			array[j][i] = '-';
		}
	}
}*/
void init_screen(char array[60][30], struct tile* local_tiles, int tile_ids[width][height], int loaded_tile_ids[8])
{
    //Loads static background tiles so they don't need to be reloaded every screen print
    for (int i = 0; i < height * 3; i = i + 3)
    {
        for (int j = 0; j < width * 6; j = j + 6)
        {
            for (int k = 0; k < 6; k++)
            {
                for (int l = 0; l < 3; l++)
                {
                    for(int m = 0; m < 8; m++)
                    {
                        if(loaded_tile_ids[m] == tile_ids[j / 6][i / 3])
                        {
                            array[k + j][i + l] = (local_tiles+m)->layout[k][l];
                        }
                    }
                }
            }
        }
    }
}
/*void print_screen(char array[60][30], int pos[2], struct tile* local_tiles, int tile_ids[width][height], int loaded_tile_ids[8])
{
	printf(" ");
	for (int i = 0; i < width*6; i++)
	{
		printf("#");
	}
	printf("\n");
	for (int i = 0; i < height*3; i++)
	{
		printf("#");
		for (int j = 0; j < width*6; j++)
		{
			if (array[j][i] == 'x')
			{
				printf(" ");
			}
			else
			{
				printf("%c", array[j][i]);
			}

		}
		printf("#");
		printf("\n");
	}
	printf(" ");
	for (int i = 0; i < width * 6; i++)
	{
		printf("#");
	}
	printf("\n");
}*/
int col_check(int array[width][height], int ref[width][height], int pos[2], char input, struct tile* local_tiles, int loaded_tile_ids[8], struct asset* scenes, int tile_ids[width][height], int tile_frequency[100], struct tile* Tiles, int warp_def[3])
{
    int test[3] = {0, 0, 0};
	if (input == 'w')
	{
	    for (int i = 0; i < 8; i++)
        {
	        if (ref[pos[1]][pos[0] - 1] == loaded_tile_ids[i])
            {
                if ((local_tiles + i)->flags[0] == 'c')
                {
                    return 0;
                }
                if((local_tiles + i)->flags[1] == 'd')
                {
                    return 2;
                }
                else
                {
                    return 1;
                }
            }

        }
	}
	if (input == 's')
	{
        for (int i = 0; i < 8; i++)
        {
            if (ref[pos[1]][pos[0] + 1] == loaded_tile_ids[i])
            {
                if ((local_tiles + i)->flags[0] == 'c')
                {
                    return 0;
                }
                if((local_tiles + i)->flags[1] == 'd')
                {
                    return 2;
                }
                else
                {
                    return 1;
                }
            }

        }
	}
	if (input == 'a')
	{
        for (int i = 0; i < 8; i++)
        {
            if (ref[pos[1]-1][pos[0]] == loaded_tile_ids[i])
            {
                if ((local_tiles + i)->flags[0] == 'c')
                {
                    return 0;
                }
                if((local_tiles + i)->flags[1] == 'd')
                {
                    return 2;
                }
                else
                {
                    return 1;
                }
            }

        }
	}
	if (input == 'd')
	{
        for (int i = 0; i < 8; i++)
        {
            if (ref[pos[1]+1][pos[0]] == loaded_tile_ids[i])
            {
                if ((local_tiles + i)->flags[0] == 'c')
                {
                    return 0;
                }
                if((local_tiles + i)->flags[1] == 'd')
                {
                    return 2;
                }
                else
                {
                    return 1;
                }
            }

        }
	}
	return 0;
}
void update_location(int array[width][height], int ref[width][height], int pos[2], char input, struct tile* local_tiles, int loaded_tile_ids[8], struct asset* scenes, int tile_ids[width][height], int tile_frequency[100], struct tile* Tiles, int warp_def[3])
{
    int col = 0;
    int dest[3] = {1, 5, 5};
	if (input == 'w')
	{
		if (pos[0] - 1 >= 0 && pos[0] - 1 <= height - 1)
		{
		    col = col_check(array, ref, pos, input, local_tiles, loaded_tile_ids, scenes, tile_ids, tile_frequency, Tiles, warp_def);
		    if(col == 2)
            {
                for (int i = 0; i < 8; i++)
                {
                    if (ref[pos[1]][pos[0] - 1] == loaded_tile_ids[i])
                    {
                        dest[0] = (local_tiles+i)->warp[0];
                        dest[1] = (local_tiles+i)->warp[1];
                        dest[2] = (local_tiles+i)->warp[2];
                        change_scene(scenes, tile_ids, ref, tile_frequency, pos, dest, loaded_tile_ids, warp_def, Tiles, local_tiles);
                    }
                }

            }
		if (col == 1)
        {
            pos[0] = pos[0] - col;
		    array[pos[1]][pos[0]+1] = ref[pos[1]][pos[0]+1];

        }
		array[pos[1]][pos[0]] = 1;
			
		}
	}
	if (input == 's')
	{
		if (pos[0] + 1 >= 0 && pos[0] + 1 <= height - 1)
		{
			col = col_check(array, ref, pos, input, local_tiles, loaded_tile_ids, scenes, tile_ids, tile_frequency, Tiles, warp_def);
            if(col == 2)
            {
                for (int i = 0; i < 8; i++)
                {
                    if (ref[pos[1]][pos[0] + 1] == loaded_tile_ids[i])
                    {
                        dest[0] = (local_tiles+i)->warp[0];
                        dest[1] = (local_tiles+i)->warp[1];
                        dest[2] = (local_tiles+i)->warp[2];
                        change_scene(scenes, tile_ids, ref, tile_frequency, pos, dest, loaded_tile_ids, warp_def, Tiles, local_tiles);
                    }
                }
            }
            if (col == 1)
            {
                pos[0] = pos[0] + col;
                array[pos[1]][pos[0]-1] = ref[pos[1]][pos[0]-1];

            }
		array[pos[1]][pos[0]] = 1;
			
		}
	}
	if (input == 'a')
	{
		if (pos[1] - 1 >= 0 && pos[1] - 1 <= width - 1)
		{
          col = col_check(array, ref, pos, input, local_tiles, loaded_tile_ids, scenes, tile_ids, tile_frequency, Tiles, warp_def);
            if(col == 2)
            {
                for (int i = 0; i < 8; i++)
                {
                    if (ref[pos[1]-1][pos[0]] == loaded_tile_ids[i])
                    {
                        dest[0] = (local_tiles+i)->warp[0];
                        dest[1] = (local_tiles+i)->warp[1];
                        dest[2] = (local_tiles+i)->warp[2];
                        change_scene(scenes, tile_ids, ref, tile_frequency, pos, dest, loaded_tile_ids, warp_def, Tiles, local_tiles);
                    }
                }
            }
            if (col == 1)
            {
                pos[1] = pos[1] - col;
                array[pos[1]+1][pos[0]] = ref[pos[1]+1][pos[0]];
            }
		array[pos[1]][pos[0]] = 1;
			
		}
	}
	if (input == 'd')
	{
		if (pos[1] + 1 >= 0 && pos[1] + 1 <= width - 1)
		{
         col = col_check(array, ref, pos, input, local_tiles, loaded_tile_ids, scenes, tile_ids, tile_frequency, Tiles, warp_def);
            if(col == 2)
            {
                for (int i = 0; i < 8; i++)
                {
                    if (ref[pos[1]][pos[0] + 1] == loaded_tile_ids[i])
                    {
                        dest[0] = (local_tiles+i)->warp[0];
                        dest[1] = (local_tiles+i)->warp[1];
                        dest[2] = (local_tiles+i)->warp[2];
                        change_scene(scenes, tile_ids, ref, tile_frequency, pos, dest, loaded_tile_ids, warp_def, Tiles, local_tiles);
                    }
                }
            }
            if (col == 1)
            {
                pos[1] = pos[1] + col;
                array[pos[1]-1][pos[0]] = ref[pos[1]-1][pos[0]];
            }
		array[pos[1]][pos[0]] = 1;
			
		}
	}

}
void load_scene(struct asset* scenes, int tile_ids[width][height], int ref[width][height], int tile_frequency[100])
{

    FILE *scene_file = fopen((scenes+0)->file, "r");
    if (scene_file != NULL) {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                fscanf(scene_file, "%d", &tile_ids[j][i]);
                ref[j][i] = tile_ids[j][i];
            }
        }
    }
	fclose(scene_file);
    //tile_ids[pos[1]][pos[0]] = 1;
}
int move(int scrstr[1984], int bgmap[1984], int tile_map[100][18], int pos, char input, char player_tile[18], int linear_ids[100], int linear_pos[100][2])
{
    //Linear movement to a 2D space
    //One space down is +10
    //One space up is -10
    //One space right is +1
    //One left is -1

    for(int i = 0; i < 18; i++)
    {
        if(player_tile[i] == trans_symbol)
        {
            scrstr[tile_map[pos][i]] = bgmap[tile_map[pos][i]];
        }
        else if (player_tile[i] == blank_symbol)
        {
            scrstr[tile_map[pos][i]] = 32;
        }
        else
        {
            scrstr[tile_map[pos][i]] = (int) player_tile[i];
        }
    }


    if (input == 'w' || input == 'W')
    {
        if (pos - 10 >= 0)
        {
            for(int i = 0; i < 18; i++)
            {
                scrstr[tile_map[pos][i]] = bgmap[tile_map[pos][i]];
                if(player_tile[i] == trans_symbol)
                {
                    scrstr[tile_map[pos - 10][i]] = bgmap[tile_map[pos -10][i]];
                }
                else if (player_tile[i] == blank_symbol)
                {
                    scrstr[tile_map[pos - 10][i]] = 32;
                }
                else
                {
                    scrstr[tile_map[pos -10][i]] = (int) player_tile[i];
                }
            }
            return pos - 10;
        }

    }
    if (input == 's' || input == 'S')
    {
        if (pos + 10 <= 99)
        {
            for(int i = 0; i < 18; i++)
            {
                scrstr[tile_map[pos][i]] = bgmap[tile_map[pos][i]];
                if(player_tile[i] == trans_symbol)
                {
                    scrstr[tile_map[pos + 10][i]] = bgmap[tile_map[pos + 10][i]];
                }
                else if (player_tile[i] == blank_symbol)
                {
                    scrstr[tile_map[pos + 10][i]] = 32;
                }
                else
                {
                    scrstr[tile_map[pos + 10][i]] = (int) player_tile[i];
                }
            }
            return pos + 10;
        }
    }
    if (input == 'a' || input == 'A')
    {
        if (pos - 1 >= 0 && pos%10 != 0)
        {
            for(int i = 0; i < 18; i++)
            {
                scrstr[tile_map[pos][i]] = bgmap[tile_map[pos][i]];
                if(player_tile[i] == trans_symbol)
                {
                    scrstr[tile_map[pos - 1][i]] = bgmap[tile_map[pos - 1][i]];
                }
                else if (player_tile[i] == blank_symbol)
                {
                    scrstr[tile_map[pos - 1][i]] = 32;
                }
                else
                {
                    scrstr[tile_map[pos -1][i]] = (int) player_tile[i];
                }
            }
            return pos - 1;
        }
    }
    if (input == 'd' || input == 'D')
    {
        if (pos + 1 >= 0 && pos%10 != 9)
        {
            for(int i = 0; i < 18; i++)
            {
                scrstr[tile_map[pos][i]] = bgmap[tile_map[pos][i]];
                if(player_tile[i] == trans_symbol)
                {
                    scrstr[tile_map[pos + 1][i]] = bgmap[tile_map[pos + 1][i]];
                }
                else if (player_tile[i] == blank_symbol)
                {
                    scrstr[tile_map[pos + 1][i]] = 32;
                }
                else
                {
                    scrstr[tile_map[pos + 1][i]] = (int) player_tile[i];
                }
            }
            return pos + 1;
        }
    }

    return pos;

}
void print_menu(char text[])
{
	int textdone = 0, textcounter = 0;
	printf(" ");
	for (int i = 0; i < width*6; i++)
	{
		if (i == 0 || i == width*6 - 1)
		{
			printf(" ");
		}
		else
		{
			printf("_");
		}
	}
	printf("\n");

	for (int l = 0; l < height*3 / 3; l++)
	{
		printf(" ");
		for (int j = 0; j <= width*6 - 1; j++)
		{
			if (j == 0 || j == width*6 - 1)
			{
				printf("|");
			}
			else
			{
				if (text[textcounter] > 0 && text[textcounter] <= 127)
				{
					if (textdone == 0)
					{
						printf("%c", text[textcounter]);
						textcounter = textcounter + 1;
					}
					else
					{
						printf(" ");
					}
				}
				else
				{
					printf(" ");
					textdone = 1;
				}
			}
		}
		printf("\n");
	}

	printf(" ");
	for (int i = 0; i < width*6; i++)
	{
		if (i == 0 || i == width*6 -1)
		{
			printf("|");
		}
		else
		{
			printf("_");
		}
	}
	printf("\n");
}
void init_tile(struct tile* tile)
{
	int vind = 0, hind = 0;
	for (int i = 0; i < 3; i++)
	{
		vind = i;
		for (int j = 0; j < 6; j++)
		{
			hind = j;
			tile->layout[vind][hind] = '~';
		}
	}

}
void init_tile_pointer(struct tile* tile)
{
	int vind = 0, hind = 0;
	for (int i = 0; i < 3; i++)
	{
		vind = i;
		for (int j = 0; j < 6; j++)
		{
			hind = j;
            tile->layout[vind][hind] = '~';
		}
	}

}
void init_tiles(struct tile* local_tiles)
{
	for (int i = 0; i < 100; i++)
	{
		init_tile(local_tiles+i);
	}
}
void print_tile(struct tile* tile)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			printf("%c", tile->layout[j][i]);
		}
		printf("\n");
	}
}
void print_tile_ids(int tile_ids[width][height])
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			printf("%d", tile_ids[j][i]);
		}
		printf("\n");
	}
}
void get_frequency(int tile_ids[width][height], int tile_frequency[100])
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			tile_frequency[tile_ids[j][i]] = tile_frequency[tile_ids[j][i]] + 1;
		}
	}
}
void print_frequency(int tile_frequency[100])
{
	for (int i = 0; i < 100; i++)
	{
		printf("%d ", tile_frequency[i]);
	}
	printf("\n");
}
void load_tiles(int tile_frequency[100], int tile_ids[width][height], int loaded_tile_ids[8], struct tile* local_tiles, struct tile* Tiles)
{
    int count = unique_local_tile_count(tile_frequency);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            for( int l = 0; l < count; l++)
            {
                if (loaded_tile_ids[l] == tile_ids[j][i])
                {
                    break;
                }
                else if (loaded_tile_ids[l] == -1)
                {
                    loaded_tile_ids[l] = tile_ids[j][i];
                    break;
                }
            }
        }
    }
    for (int i = 0; i < count; i++)
    {
       FILE* current_tile_asset = fopen((Tiles + loaded_tile_ids[i])->file, "r");
       (local_tiles + i)->flags[0] = (Tiles + loaded_tile_ids[i])->flags[0];
       (local_tiles + i)->flags[1] = (Tiles + loaded_tile_ids[i])->flags[1];
       (local_tiles + i)->warp[0] = (Tiles + loaded_tile_ids[i])->warp[0];
       (local_tiles + i)->warp[1] = (Tiles + loaded_tile_ids[i])->warp[1];
       (local_tiles + i)->warp[2] = (Tiles + loaded_tile_ids[i])->warp[2];


        if(current_tile_asset != NULL)
        {
            if(debug == 't')
            {
                printf("in the if statement\n");
            }
            for (int k = 0; k < 3; k++)
            {
                for (int j = 0; j < 6; j++)
                {
                    fscanf(current_tile_asset, "%c", &(local_tiles+i)->layout[j][k]);
                }
                fscanf(current_tile_asset, "%*c");
            }
            fclose(current_tile_asset);
        }
        else
        {
            printf("NULL FILE.\n");
        }
    }
    system("PAUSE");
}
void init_local_tiles(struct tile* local_tiles, int tile_frequency[100])
{
    int count = unique_local_tile_count(tile_frequency);

    realloc(local_tiles, count * sizeof(struct tile));

    for (int i = 0; i < count; i++)
    {
        (local_tiles + i)->id = i;
        if(debug == 't')
        {
            printf("ID %d.\n", (local_tiles + i)->id);
        }
        (local_tiles + i)->layout = (char**) malloc(3 * sizeof(char*));
        for (int j = 0; j < 6; j++)
        {
            (local_tiles+i)->layout[j] = (char*) malloc(3 * sizeof(char*));
        }
        (local_tiles + i)->flags[0] = '\0';
        (local_tiles + i)->flags[1] = '\0';
        (local_tiles + i)->warp[0] = -1;
        (local_tiles + i)->warp[1] = -1;
        (local_tiles + i)->warp[2] = -1;

    }
    if (debug == 't')
    {
        printf("Made it out of init\n");
    }
}
int unique_local_tile_count(int tile_frequency[100])
{
    int count = 0;

    for (int i = 0; i < 100; i++)
    {
        if (tile_frequency[i]>0)
        {
            count = count + 1;
        }
    }

    return count;
}
void change_scene(struct asset* scenes, int tile_ids[width][height], int ref[width][height], int tile_frequency[100], int pos[2], int warppos[3], int loaded_tile_ids[8], int warp_def[3], struct tile* Tiles, struct tile* local_tiles)
{
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j <10; j++)
        {
            tile_ids[j][i] = 0;
            ref[j][i] = 0;
        }
    }

    for(int i = 0; i < 100; i++)
    {
        tile_frequency[i] = 0;

    }

    for(int i = 0; i < 8; i++)
    {
        loaded_tile_ids[i] = -1;

    }

    //Load scene and get frequency
    load_scene(scenes, tile_ids, ref, tile_frequency, pos, warppos);
    get_frequency(tile_ids, tile_frequency);

    //Create and initialize local_tiles
    realloc(local_tiles, sizeof(struct tile));


    //init local_tiles
    init_local_tiles(local_tiles, tile_frequency);
    if(debug == 't')
    {
        system("PAUSE");
    }


    //load tiles
    load_tiles(tile_frequency, tile_ids, loaded_tile_ids, local_tiles, Tiles);
    if(debug == 't')
    {
        system("PAUSE");
    }

}

