#include "header.h"


int main(void)
{

    //Declare stack variables
	FILE* settings = fopen("settings.txt", "r");
	char screen[width*6][height*3] = {'\0'}, input = '\0';
	char TestText[] = "This is test text, and I'm making it long to see what happens :)";
	int tile_ids[width][height], ref[width][height], tile_frequency[100] = { 0 }, loaded_tile_ids[8] = {-1, -1, -1, -1, -1, -1, -1, -1};
    int exit = 0;
    struct object player;
    player.xpos = 0;
    player.ypos = 0;

    int warp_def[3] = {0, 0, 0};

    int pos[2] = { player.xpos, player.ypos };

    //Init stack objects
    init_screen(screen);

    //Declare global tiles
	struct tile Dummy;
    Dummy.id = 0;
    Dummy.file = "C:\\Users\\Clark\\Desktop\\stream\\RPG\\Dummy.txt";
	Dummy.flags[0] = '\0';
	Dummy.flags[1] = '\0';
	Dummy.warp[0] = -1;
	Dummy.warp[1] = -1;
	Dummy.warp[2] = -1;


	struct tile Player_global;
	Player_global.id = 1;
	Player_global.file = "C:\\Users\\Clark\\Desktop\\stream\\RPG\\PlayerTile.txt";
	Player_global.flags[0] = '\0';
    Player_global.flags[1] = '\0';


	struct tile TestTile_global;
	TestTile_global.id = 2;
	TestTile_global.file = "C:\\Users\\Clark\\Desktop\\stream\\RPG\\TestTile.txt";
	TestTile_global.flags[0] = '\0';
	TestTile_global.flags[1] = '\0';


	struct tile TestTile2_global;
	TestTile2_global.id = 3;
	TestTile2_global.file = "C:\\Users\\Clark\\Desktop\\stream\\RPG\\TestTile2.txt";
	TestTile2_global.flags[0] = 'c';
	TestTile2_global.flags[1] = '\0';


	struct tile Door1_global;
	Door1_global.id = 4;
	Door1_global.file = "C:\\Users\\Clark\\Desktop\\stream\\RPG\\TestDoor.txt";
	Door1_global.flags[0] = '\0';
	Door1_global.flags[1] = 'd';
	Door1_global.warp[0] = 1;
	Door1_global.warp[1] = 5;
	Door1_global.warp[2] = 5;

    struct tile Door2_global;
    Door2_global.id = 5;
    Door2_global.file = "TestDoor.txt";
    Door2_global.flags[0] = '\0';
    Door2_global.flags[1] = 'd';
    Door2_global.warp[0] = 0;
    Door2_global.warp[1] = 5;
    Door2_global.warp[2] = 5;

    struct tile Wall;
    Wall.id = 6;
    Wall.file = "Wall.txt";
    Wall.flags[0] = 'c';
    Wall.flags[1] = '\0';

    struct tile Floor;
    Floor.id = 7;
    Floor.file = "Floor.txt";
    Floor.flags[0] = '\0';
    Floor.flags[1] = '\0';



    //Add to global tiles array
	struct tile* Tiles = (struct tile*) malloc(global_amount*sizeof(struct tile));
    *(Tiles) = Dummy;
    *(Tiles+1) = Player_global;
    *(Tiles+2) = TestTile_global;
    *(Tiles+3) = TestTile2_global;
    *(Tiles+4) = Door1_global;
    *(Tiles+5) = Door2_global;
    *(Tiles+6) = Wall;
    *(Tiles+7) = Floor;




    //Declare global scenes
    struct asset TestZone;
    TestZone.file = "C:\\Users\\Clark\\Desktop\\stream\\RPG\\TileTestZone.txt";

    struct asset TestZone2;
    TestZone2.file = "C:\\Users\\Clark\\Desktop\\stream\\RPG\\TestZone2.txt";

    struct asset* scenes = (struct asset*) malloc(global_amount*sizeof(struct asset));
    *(scenes) = TestZone;
    *(scenes+1) = TestZone2;

    printf("Made it here\n");
    system("PAUSE");

    //Load scene and get frequency
    load_scene(scenes, tile_ids, ref, tile_frequency, pos, warp_def);
    get_frequency(tile_ids, tile_frequency);

    //Create and initialize local_tiles
	struct tile* local_tiles;
	local_tiles = (struct tile*) malloc(sizeof(struct tile));


	//init local_tiles
	init_local_tiles(local_tiles, tile_frequency);

	//load tiles
    load_tiles(tile_frequency, tile_ids, loaded_tile_ids, local_tiles, Tiles);
    //printf("Made it out of load tiles\n");


	print_screen(screen, pos, local_tiles, tile_ids, loaded_tile_ids);
    print_menu(TestText);

	load_settings(settings);



	while (exit != 1)
	{
		input = _getche();

		if (input == 'p')
        {
		    exit = 1;
        }

		update_location(tile_ids, ref, pos, input, local_tiles, loaded_tile_ids, scenes, tile_ids, tile_frequency, Tiles, warp_def);
		input = '\0';
		system("cls");
        print_screen(screen, pos, local_tiles, tile_ids, loaded_tile_ids);
        print_menu(TestText);
		//printf("Player position is %d %d.\n", pos[0], pos[1]);
	}

    free(local_tiles);
    free(Tiles);
    free(scenes);
    return 0;
}