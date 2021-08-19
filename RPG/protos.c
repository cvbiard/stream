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
void screen_manager(int scrstr[1984], int bgmap[1984], int tile_map[100][18], struct tile* Tiles, int tile_ids[width][height], int tile_frequency[100], int linear_ids[100], int pos, char player_tile[18])
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
        FILE* loaded = fopen((Tiles+(used_tiles[i]))->file, "r");
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
                   if((int)current[p] == (int)blank_symbol)
                   {
                       scrstr[tile_map[m][p]] = 32;
                   }
                   else
                   {
                       scrstr[tile_map[m][p]] = (int)current[p];
                   }
               }
           }

       }
    }

    //Updates the background map for future use to restore a tile on the screen that gets changed from moving tiles
    for (int i =0; i<1984; i++)
    {
        bgmap[i] = scrstr[i];
    }

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
void load_scene(struct asset* scenes, int tile_ids[width][height], int tile_frequency[100])
{

    FILE *scene_file = fopen(scenes->file, "r");
    if (scene_file != NULL) {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                fscanf(scene_file, "%d", &tile_ids[j][i]);
                //ref[j][i] = tile_ids[j][i];
            }
        }
    }
	fclose(scene_file);
    //tile_ids[pos[1]][pos[0]] = 1;
}
int move(int scrstr[1984], int bgmap[1984], int tile_map[100][18], char input, char player_tile[18], int linear_ids[100], int linear_pos[100][2], struct tile* Tiles, struct asset* scenes, int tile_ids[width][height], int tile_frequency[100], struct object *player)
{
    //Linear movement to a 2D space
    //One space down is +10
    //One space up is -10
    //One space right is +1
    //One left is -1
    int prewarppos = 0;


    if (input == 'w' || input == 'W')
    {
        if((Tiles + linear_ids[(player->pos) - 10])->flags[1] == 'd')
        {
            prewarppos = player->pos;
            player->pos = (Tiles + linear_ids[(player->pos) - 10])->warp[1];
            load_scene((scenes+(Tiles + linear_ids[prewarppos - 10])->warp[0]), tile_ids, tile_frequency);
            get_frequency(tile_ids, tile_frequency);
            screen_manager(scrstr, bgmap, tile_map, Tiles, tile_ids, tile_frequency, linear_ids, (Tiles + linear_ids[prewarppos - 10])->warp[1], player_tile);
            return player->pos;
        }
        if ((player->pos) - 10 >= 0 && (Tiles + linear_ids[(player->pos) - 10])->flags[0]!= 'c')
        {
            for(int i = 0; i < 18; i++)
            {
                scrstr[tile_map[(player->pos)][i]] = bgmap[tile_map[(player->pos)][i]];
                if(player_tile[i] == trans_symbol)
                {
                    scrstr[tile_map[(player->pos) - 10][i]] = bgmap[tile_map[(player->pos) -10][i]];
                }
                else if (player_tile[i] == blank_symbol)
                {
                    scrstr[tile_map[(player->pos) - 10][i]] = 32;
                }
                else
                {
                    scrstr[tile_map[(player->pos) -10][i]] = (int) player_tile[i];
                }
            }
            return (player->pos) - 10;
        }

    }
    if (input == 's' || input == 'S')
    {
        if((Tiles + linear_ids[(player->pos) + 10])->flags[1] == 'd')
        {
            prewarppos = player->pos;
            player->pos = (Tiles + linear_ids[(player->pos) + 10])->warp[1];
            load_scene((scenes+(Tiles + linear_ids[prewarppos + 10])->warp[0]), tile_ids, tile_frequency);
            get_frequency(tile_ids, tile_frequency);
            screen_manager(scrstr, bgmap, tile_map, Tiles, tile_ids, tile_frequency, linear_ids, (Tiles + linear_ids[prewarppos + 10])->warp[1], player_tile);
            return player->pos;
        }
        if ((player->pos) + 10 <= 99 && (Tiles + linear_ids[(player->pos) + 10])->flags[0]!= 'c')
        {
            for(int i = 0; i < 18; i++)
            {
                scrstr[tile_map[(player->pos)][i]] = bgmap[tile_map[(player->pos)][i]];
                if(player_tile[i] == trans_symbol)
                {
                    scrstr[tile_map[(player->pos) + 10][i]] = bgmap[tile_map[(player->pos) + 10][i]];
                }
                else if (player_tile[i] == blank_symbol)
                {
                    scrstr[tile_map[(player->pos) + 10][i]] = 32;
                }
                else
                {
                    scrstr[tile_map[(player->pos) + 10][i]] = (int) player_tile[i];
                }
            }
            return (player->pos) + 10;
        }
    }
    if (input == 'a' || input == 'A' )
    {
        if((Tiles + linear_ids[(player->pos) - 1])->flags[1] == 'd')
        {
            prewarppos = player->pos;
            player->pos = (Tiles + linear_ids[(player->pos) - 1])->warp[1];
            load_scene((scenes+(Tiles + linear_ids[prewarppos - 1])->warp[0]), tile_ids, tile_frequency);
            get_frequency(tile_ids, tile_frequency);
            screen_manager(scrstr, bgmap, tile_map, Tiles, tile_ids, tile_frequency, linear_ids, (Tiles + linear_ids[prewarppos - 1])->warp[1], player_tile);
            return player->pos;
        }
        if ((player->pos) - 1 >= 0 && (player->pos)%10 != 0 && (Tiles + linear_ids[(player->pos) - 1])->flags[0]!= 'c')
        {
            for(int i = 0; i < 18; i++)
            {
                scrstr[tile_map[(player->pos)][i]] = bgmap[tile_map[(player->pos)][i]];
                if(player_tile[i] == trans_symbol)
                {
                    scrstr[tile_map[(player->pos) - 1][i]] = bgmap[tile_map[(player->pos) - 1][i]];
                }
                else if (player_tile[i] == blank_symbol)
                {
                    scrstr[tile_map[(player->pos) - 1][i]] = 32;
                }
                else
                {
                    scrstr[tile_map[(player->pos) -1][i]] = (int) player_tile[i];
                }
            }
            return (player->pos) - 1;
        }
    }
    if (input == 'd' || input == 'D')
    {
        if((Tiles + linear_ids[(player->pos) + 1])->flags[1] == 'd')
        {
            prewarppos = player->pos;
            player->pos = (Tiles + linear_ids[(player->pos) + 1])->warp[1];
            load_scene((scenes+(Tiles + linear_ids[prewarppos + 1])->warp[0]), tile_ids, tile_frequency);
            get_frequency(tile_ids, tile_frequency);
            screen_manager(scrstr, bgmap, tile_map, Tiles, tile_ids, tile_frequency, linear_ids, (Tiles + linear_ids[prewarppos + 1])->warp[1], player_tile);
            return player->pos;
        }
        if ((player->pos) + 1 >= 0 && (player->pos)%10 != 9  && (Tiles + linear_ids[(player->pos) + 1])->flags[0]!= 'c')
        {
            for(int i = 0; i < 18; i++)
            {
                scrstr[tile_map[(player->pos)][i]] = bgmap[tile_map[(player->pos)][i]];
                if(player_tile[i] == trans_symbol)
                {
                    scrstr[tile_map[(player->pos) + 1][i]] = bgmap[tile_map[(player->pos) + 1][i]];
                }
                else if (player_tile[i] == blank_symbol)
                {
                    scrstr[tile_map[(player->pos) + 1][i]] = 32;
                }
                else
                {
                    scrstr[tile_map[(player->pos) + 1][i]] = (int) player_tile[i];
                }
            }
            return (player->pos) + 1;
        }
    }

    return (player->pos);

}
void print_menu(char text[]) {
    int textdone = 0, textcounter = 0;
    printf(" ");
    for (int i = 0; i < width * 6; i++) {
        if (i == 0 || i == width * 6 - 1) {
            printf(" ");
        } else {
            printf("_");
        }
    }
    printf("\n");

    for (int l = 0; l < height * 3 / 3; l++) {
        printf(" ");
        for (int j = 0; j <= width * 6 - 1; j++) {
            if (j == 0 || j == width * 6 - 1) {
                printf("|");
            } else {
                if (text[textcounter] > 0 && text[textcounter] <= 127) {
                    if (textdone == 0) {
                        printf("%c", text[textcounter]);
                        textcounter = textcounter + 1;
                    } else {
                        printf(" ");
                    }
                } else {
                    printf(" ");
                    textdone = 1;
                }
            }
        }
        printf("\n");
    }

    printf(" ");
    for (int i = 0; i < width * 6; i++) {
        if (i == 0 || i == width * 6 - 1) {
            printf("|");
        } else {
            printf("_");
        }
    }
    printf("\n");
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