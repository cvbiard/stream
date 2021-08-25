#include "header.h"


int main(void)
{

    //Declare stack variables
    int scr_size = calc_screen_size(1);
    //debug_printer(1);
	char input = '\0';
	int scrstr = (int) malloc(scr_size * sizeof(int));
	int bgmap = (int) malloc(scr_size * sizeof(int));
	//debug_printer(2);
	int linear_ids = (int) malloc((height*width) * sizeof(int));
    int tile_map[(height*width)][(tile_height*tile_width)] = {0};
    //debug_printer(3);
    mapping(tile_map, scr_size);

	char TestText[] = "This is test text, and I'm making it long to see what happens :)";
	int linear_pos[(width*height)][2] = {0};
	map_pos(linear_pos);
	int tile_ids[width][height], tile_frequency[(width*height)] = { 0 };
    int exit = 0;
    struct object player;
    player.pos = 50;

    char player_tile[(tile_width*tile_height)];

    //debug_printer(2);

    //Declare global tiles
	struct tile Dummy;
    Dummy.id = 0;
    Dummy.file = "Dummy.txt";
	Dummy.flags[0] = '\0';
	Dummy.flags[1] = '\0';
	Dummy.warp[0] = -1;
	Dummy.warp[1] = -1;


	struct tile Player;
	Player.id = 1;
	Player.file = "assets\\PlayerTile.txt";
	Player.flags[0] = '\0';
    Player.flags[1] = '\0';

    FILE* pt = fopen(Player.file, "r");
    int tick = 0;
    for(int i = 0; i<tile_height; i++)
    {
        for(int j = 0; j <tile_width;j++)
        {
            fscanf(pt, "%c", &player_tile[tick]);
            tick = tick + 1;
        }
        fscanf(pt, "%*c");
    }
    fclose(pt);

	struct tile Grass;
	Grass.id = 2;
	Grass.file = "Grass.txt";
	Grass.flags[0] = '\0';
	Grass.flags[1] = '\0';


	struct tile Wall;
	Wall.id = 3;
	Wall.file = "Wall.txt";
	Wall.flags[0] = 'c';
	Wall.flags[1] = '\0';


	struct tile Door1;
	Door1.id = 4;
	Door1.file = "Door.txt";
	Door1.flags[0] = '\0';
	Door1.flags[1] = 'd';
	Door1.warp[0] = 1;
	Door1.warp[1] = 369;

    struct tile Door2;
    Door2.id = 5;
    Door2.file = "Door.txt";
    Door2.flags[0] = '\0';
    Door2.flags[1] = 'd';
    Door2.warp[0] = 0;
    Door2.warp[1] = 273;

    struct tile Floor;
    Floor.id = 6;
    Floor.file = "Floor.txt";
    Floor.flags[0] = '\0';
    Floor.flags[1] = '\0';

    struct tile GrassPath;
    GrassPath.id = 7;
    GrassPath.file = "GrassPath.txt";
    GrassPath.flags[0] = '\0';
    GrassPath.flags[1] = '\0';

    struct tile GrassPathH;
    GrassPathH.id = 8;
    GrassPathH.file = "GrassPathH.txt";
    GrassPathH.flags[0] = '\0';
    GrassPathH.flags[1] = '\0';

    struct tile GrassPathBR;
    GrassPathBR.id = 9;
    GrassPathBR.file = "GrassPathBR.txt";
    GrassPathBR.flags[0] = '\0';
    GrassPathBR.flags[1] = '\0';

    struct tile TreeTop;
    TreeTop.id = 10;
    TreeTop.file = "TreeTop.txt";
    TreeTop.flags[0] = 'c';
    TreeTop.flags[1] = '\0';

    struct tile TreeBottom;
    TreeBottom.id = 11;
    TreeBottom.file = "TreeBottom.txt";
    TreeBottom.flags[0] = 'c';
    TreeBottom.flags[1] = '\0';

    struct tile GrassPathTR;
    GrassPathTR.id = 12;
    GrassPathTR.file = "GrassPathTR.txt";
    GrassPathTR.flags[0] = '\0';
    GrassPathTR.flags[1] = '\0';

    struct tile GrassPathTL;
    GrassPathTL.id = 13;
    GrassPathTL.file = "GrassPathTL.txt";
    GrassPathTL.flags[0] = '\0';
    GrassPathTL.flags[1] = '\0';

    struct tile GrassPathBL;
    GrassPathBL.id = 14;
    GrassPathBL.file = "GrassPathBL.txt";
    GrassPathBL.flags[0] = '\0';
    GrassPathBL.flags[1] = '\0';

    struct tile GrassPathC;
    GrassPathC.id = 15;
    GrassPathC.file = "GrassPathC.txt";
    GrassPathC.flags[0] = '\0';
    GrassPathC.flags[1] = '\0';

    struct tile Brick;
    Brick.id = 16;
    Brick.file = "Brick.txt";
    Brick.flags[0] = 'c';
    Brick.flags[1] = '\0';

    struct tile RoofBase;
    RoofBase.id = 17;
    RoofBase.file = "RoofBase.txt";
    RoofBase.flags[0] = 'c';
    RoofBase.flags[1] = '\0';

    struct tile RoofL;
    RoofL.id = 18;
    RoofL.file = "RoofL.txt";
    RoofL.flags[0] = 'c';
    RoofL.flags[1] = '\0';

    struct tile RoofR;
    RoofR.id = 19;
    RoofR.file = "RoofR.txt";
    RoofR.flags[0] = 'c';
    RoofR.flags[1] = '\0';

    struct tile RoofT;
    RoofT.id = 20;
    RoofT.file = "RoofT.txt";
    RoofT.flags[0] = 'c';
    RoofT.flags[1] = '\0';

    struct tile Blank;
    Blank.id = 21;
    Blank.file = "Blank.txt";
    Blank.flags[0] = 'c';
    Blank.flags[1] = '\0';

    struct tile GrassPathCU;
    GrassPathCU.id = 22;
    GrassPathCU.file = "GrassPathCU.txt";
    GrassPathCU.flags[0] = '\0';
    GrassPathCU.flags[1] = '\0';

    struct tile GrassPathCD;
    GrassPathCD.id = 23;
    GrassPathCD.file = "GrassPathCD.txt";
    GrassPathCD.flags[0] = '\0';
    GrassPathCD.flags[1] = '\0';

    struct tile GrassPathCL;
    GrassPathCL.id = 24;
    GrassPathCL.file = "GrassPathCL.txt";
    GrassPathCL.flags[0] = '\0';
    GrassPathCL.flags[1] = '\0';

    struct tile GrassPathCR;
    GrassPathCR.id = 25;
    GrassPathCR.file = "GrassPathCR.txt";
    GrassPathCR.flags[0] = '\0';
    GrassPathCR.flags[1] = '\0';

    struct tile BrickWindow;
    BrickWindow.id = 26;
    BrickWindow.file = "BrickWindow.txt";
    BrickWindow.flags[0] = '\0';
    BrickWindow.flags[1] = '\0';


    //Add to global tiles array
	struct tile* Tiles = (struct tile*) malloc(global_amount_tiles*sizeof(struct tile));
    *(Tiles) = Dummy;
    *(Tiles+1) = Player;
    *(Tiles+2) = Grass;
    *(Tiles+3) = Wall;
    *(Tiles+4) = Door1;
    *(Tiles+5) = Door2;
    *(Tiles+6) = Floor;
    *(Tiles+7) = GrassPath;
    *(Tiles+8) = GrassPathH;
    *(Tiles+9) = GrassPathBR;
    *(Tiles+10) = TreeTop;
    *(Tiles+11) = TreeBottom;
    *(Tiles+12) = GrassPathTR;
    *(Tiles+13) = GrassPathTL;
    *(Tiles+14) = GrassPathBL;
    *(Tiles+15) = GrassPathC;
    *(Tiles+16) = Brick;
    *(Tiles+17) = RoofBase;
    *(Tiles+18) = RoofL;
    *(Tiles+19) = RoofR;
    *(Tiles+20) = RoofT;
    *(Tiles+21) = Blank;
    *(Tiles+22) = GrassPathCU;
    *(Tiles+23) = GrassPathCD;
    *(Tiles+24) = GrassPathCL;
    *(Tiles+25) = GrassPathCR;
    *(Tiles+26) = BrickWindow;

    //Declare global scenes
    struct asset FirstScreen;
    FirstScreen.file = "FirstScreen.txt";

    struct asset Inside;
    Inside.file = "Inside.txt";

    struct asset* scenes = (struct asset*) malloc(global_amount_scenes*sizeof(struct asset));
    *(scenes) = FirstScreen;
    *(scenes+1) = Inside;

    if(debug == 't')
    {
        printf("Made it here\n");
        system("PAUSE");
    }

    //Load scene and get frequency
    load_scene((scenes+0), tile_ids, tile_frequency);
    get_frequency(tile_ids, tile_frequency);

    if(debug == 't')
    {
        printf("Made it out of load tiles\n");
        system("PAUSE");
    }

    screen_manager(scrstr, bgmap, tile_map, Tiles, tile_ids, tile_frequency, linear_ids, player.pos, player_tile, scr_size);

    //debug_printer(5);


    print_screen(scrstr, scr_size);

    //system("PAUSE");


	while (exit != 1)
	{

		input = _getch();

		if (input == 'p')
        {
		    break;
        }
        if (input == 'r' && debug == 't')
        {
            load_scene((scenes+0), tile_ids, tile_frequency);
            get_frequency(tile_ids, tile_frequency);
            screen_manager(scrstr, bgmap, tile_map, Tiles, tile_ids, tile_frequency, linear_ids, player.pos, player_tile, scr_size);

        }

        player.pos = move(scrstr, bgmap, tile_map, input, player_tile, linear_ids, linear_pos, Tiles, scenes, tile_ids, tile_frequency, &player, scr_size);
		input = '\0';
		system("cls");

        print_screen(scrstr, scr_size);
        print_menu(TestText);
        if(debug == 't')
        {
            printf("Player position is %d.\n", player.pos);
        }
	}

	free(scrstr);
	free(bgmap);
    free(Tiles);
    free(scenes);
    return 0;
}