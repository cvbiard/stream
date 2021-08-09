#include "header.h"

void init_screen(char array[60][30])
{
	for (int i = 0; i < height*3; i++)
	{
		for (int j = 0; j < width*6; j++)
		{
			array[j][i] = '-';
		}
	}
}
void print_screen(char array[60][30], int pos[2], struct tile* local_tiles, int tile_ids[width][height], int loaded_tile_ids[8])
{
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
}
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
void load_scene(struct asset* scenes, int tile_ids[width][height], int ref[width][height], int tile_frequency[100], int pos[2], int warppos[3])
{

    FILE *scene_file = fopen((scenes+warppos[0])->file, "r");
    if (scene_file != NULL) {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                fscanf(scene_file, "%i", &tile_ids[j][i]);
                ref[j][i] = tile_ids[j][i];
            }
        }
    }
	fclose(scene_file);
    pos[0] = warppos[1];
    pos[1] = warppos[2];
    tile_ids[pos[1]][pos[0]] = 1;
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

