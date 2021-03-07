#include "header.h"


int main(void)
{

	FILE* settings = fopen("settings.txt", "r");
	char screen[width*6][height*3], input = '\0';
	char TestText[] = "This is test text, and I'm making it long to see what happens :)";
	int tile_ids[width][height], ref[width][height], tile_frequency[100] = { 0 };
	
	struct tile* Dummy;
	Dummy = (struct tile*)malloc(sizeof(struct tile));
	(Dummy+0)->id = 0;
	//Dummy->file = malloc(20 * sizeof(char));
	(Dummy)->file[0] = "Dummy.txt";
	strcpy((Dummy)->file, "Dummy.txt");
	(Dummy)->layout = malloc(3 * sizeof(char*)); // allocates one dimension
	for (int j = 0; j < 6; j++)
	{
		(Dummy)->layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	}
	(Dummy)->asset = fopen("Dummy.txt", "r");
	//Dummy->flags = malloc(2 * sizeof(char));
	(Dummy)->flags[0] = '\0';
	(Dummy)->flags[1] = '\0';

	init_tile_pointer(Dummy);
	load_tile(Dummy);

	struct tile* Player_global;
	Player_global = (struct tile*)malloc(sizeof(struct tile));
	(Player_global)->id = 1;
	//Player_global.file = malloc(20 * sizeof(char));
	(Player_global)->file[0] = "PlayerTile.txt";
	strcpy((Player_global)->file, "PlayerTile.txt");

	struct tile* TestTile_global;
	TestTile_global = (struct tile*)malloc(sizeof(struct tile));
	(TestTile_global)->id = 2;
	//TestTile_global.file = malloc(20 * sizeof(char));
	(TestTile_global)->file[0] = "TestTile.txt";
	strcpy((TestTile_global)->file, "TestTile.txt");

	struct tile* TestTile2_global;
	TestTile2_global = (struct tile*)malloc(sizeof(struct tile));
	(TestTile2_global)->id = 3;
	//TestTile2_global.file = malloc(21 * sizeof(char));
	(TestTile2_global)->file[0] = "TestTile2.txt";
	strcpy((TestTile2_global)->file, "TestTile2.txt");

	struct tile* Door_global;
	Door_global = (struct tile*)malloc(sizeof(struct tile));
	(Door_global)->id = 4;
	//Door_global.file = malloc(20 * sizeof(char));
	(Door_global)->file[0] = "TestDoor.txt";
	strcpy((Door_global)->file, "TestDoor.txt");

	struct tile Tiles[100] = {Dummy, Player_global, TestTile_global, TestTile2_global, Door_global};

	struct tile* local_tiles;

	local_tiles = (struct tile*)malloc(100 * sizeof(struct tile));

	for (int i = 0; i < 100; i++)
	{
		(local_tiles + i)->id = i;
		printf("ID %d.\n", (local_tiles + i)->id);
		(local_tiles + i)->layout = (char**) malloc(3 * sizeof(char*));
		for (int j = 0; j < 6; j++)
			{
				(local_tiles+i)->layout[j] =(char**) malloc(3 * sizeof(char*));
			}

		init_tile_pointer(local_tiles + i);
	}

	printf("We made it through initializing tiles :)\n");

	int exit = 0;

	struct object player;
	player.xpos = 0;
	player.ypos = 0;
	
	struct asset TestZone;
	TestZone.visual_asset = fopen("TileTestZone.txt", "r");
	TestZone.functional_asset = fopen("TileTestZone.txt", "r");
	
	char TestTileArr[6][3] = { '\0' };

	//struct tile Tile0;
	//Tile0.id = malloc(sizeof(int*));
	//Tile0.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile0.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile0.flags = malloc(2 * sizeof (char));
	//Tile0.asset = Dummy.asset;
	//
	//struct tile Tile1;
	//Tile1.id = malloc(sizeof(int*));
	//Tile1.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile1.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile1.flags = malloc(2 * sizeof (char));
	//Tile1.asset = Dummy.asset;
	//
	//struct tile Tile2;
	//Tile2.id = malloc(sizeof(int*));
	//Tile2.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile2.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile2.flags = malloc(2 * sizeof (char));
	//Tile2.asset = Dummy.asset;
	//
	//struct tile Tile3;
	//Tile3.id = malloc(sizeof(int*));
	//Tile3.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile3.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile3.flags = malloc(2 * sizeof (char));
	//Tile3.asset = Dummy.asset;
	//
	//struct tile Tile4;
	//Tile4.id = malloc(sizeof(int*));
	//Tile4.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile4.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile4.flags = malloc(2 * sizeof (char));
	//Tile4.asset = Dummy.asset;
	//
	//struct tile Tile5;
	//Tile5.id = malloc(sizeof(int*));
	//Tile5.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile5.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile5.flags = malloc(2 * sizeof (char));
	//Tile5.asset = Dummy.asset;
	//
	//struct tile Tile6;
	//Tile6.id = malloc(sizeof(int*));
	//Tile6.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile6.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile6.flags = malloc(2 * sizeof (char));
	//Tile6.asset = Dummy.asset;
	//
	//struct tile Tile7;
	//Tile7.id = malloc(sizeof(int*));
	//Tile7.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile7.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile7.flags = malloc(2 * sizeof (char));
	//Tile7.asset = Dummy.asset;
	//
	//struct tile Tile8;
	//Tile8.id = malloc(sizeof(int*));
	//Tile8.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile8.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile8.flags = malloc(2 * sizeof (char));
	//Tile8.asset = Dummy.asset;
	//
	//struct tile Tile9;
	//Tile9.id = malloc(sizeof(int*));
	//Tile9.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile9.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile9.flags = malloc(2 * sizeof (char));
	//Tile9.asset = Dummy.asset;
	//
	//struct tile Tile10;
	//Tile10.id = malloc(sizeof(int*));
	//Tile10.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile10.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile10.flags = malloc(2 * sizeof (char));
	//Tile10.asset = Dummy.asset;
	//
	//struct tile Tile11;
	//Tile11.id = malloc(sizeof(int*));
	//Tile11.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile11.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile11.flags = malloc(2 * sizeof (char));
	//Tile11.asset = Dummy.asset;
	//
	//struct tile Tile12;
	//Tile12.id = malloc(sizeof(int*));
	//Tile12.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile12.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile12.flags = malloc(2 * sizeof (char));
	//Tile12.asset = Dummy.asset;
	//
	//struct tile Tile13;
	//Tile13.id = malloc(sizeof(int*));
	//Tile13.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile13.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile13.flags = malloc(2 * sizeof (char));
	//Tile13.asset = Dummy.asset;
	//
	//struct tile Tile14;
	//Tile14.id = malloc(sizeof(int*));
	//Tile14.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile14.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile14.flags = malloc(2 * sizeof (char));
	//Tile14.asset = Dummy.asset;
	//
	//struct tile Tile15;
	//Tile15.id = malloc(sizeof(int*));
	//Tile15.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile15.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile15.flags = malloc(2 * sizeof (char));
	//Tile15.asset = Dummy.asset;
	//
	//struct tile Tile16;
	//Tile16.id = malloc(sizeof(int*));
	//Tile16.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile16.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile16.flags = malloc(2 * sizeof (char));
	//Tile16.asset = Dummy.asset;
	//
	//struct tile Tile17;
	//Tile17.id = malloc(sizeof(int*));
	//Tile17.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile17.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile17.flags = malloc(2 * sizeof (char));
	//Tile17.asset = Dummy.asset;
	//
	//struct tile Tile18;
	//Tile18.id = malloc(sizeof(int*));
	//Tile18.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile18.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile18.flags = malloc(2 * sizeof (char));
	//Tile18.asset = Dummy.asset;
	//
	//struct tile Tile19;
	//Tile19.id = malloc(sizeof(int*));
	//Tile19.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile19.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile19.flags = malloc(2 * sizeof (char));
	//Tile19.asset = Dummy.asset;
	//
	//struct tile Tile20;
	//Tile20.id = malloc(sizeof(int*));
	//Tile20.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile20.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile20.flags = malloc(2 * sizeof (char));
	//Tile20.asset = Dummy.asset;
	//
	//struct tile Tile21;
	//Tile21.id = malloc(sizeof(int*));
	//Tile21.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile21.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile21.flags = malloc(2 * sizeof (char));
	//Tile21.asset = Dummy.asset;
	//
	//struct tile Tile22;
	//Tile22.id = malloc(sizeof(int*));
	//Tile22.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile22.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile22.flags = malloc(2 * sizeof (char));
	//Tile22.asset = Dummy.asset;
	//
	//struct tile Tile23;
	//Tile23.id = malloc(sizeof(int*));
	//Tile23.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile23.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile23.flags = malloc(2 * sizeof (char));
	//Tile23.asset = Dummy.asset;
	//
	//struct tile Tile24;
	//Tile24.id = malloc(sizeof(int*));
	//Tile24.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile24.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile24.flags = malloc(2 * sizeof (char));
	//Tile24.asset = Dummy.asset;
	//
	//struct tile Tile25;
	//Tile25.id = malloc(sizeof(int*));
	//Tile25.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile25.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile25.flags = malloc(2 * sizeof (char));
	//Tile25.asset = Dummy.asset;
	//
	//struct tile Tile26;
	//Tile26.id = malloc(sizeof(int*));
	//Tile26.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile26.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile26.flags = malloc(2 * sizeof (char));
	//Tile26.asset = Dummy.asset;
	//
	//struct tile Tile27;
	//Tile27.id = malloc(sizeof(int*));
	//Tile27.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile27.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile27.flags = malloc(2 * sizeof (char));
	//Tile27.asset = Dummy.asset;
	//
	//struct tile Tile28;
	//Tile28.id = malloc(sizeof(int*));
	//Tile28.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile28.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile28.flags = malloc(2 * sizeof (char));
	//Tile28.asset = Dummy.asset;
	//
	//struct tile Tile29;
	//Tile29.id = malloc(sizeof(int*));
	//Tile29.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile29.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile29.flags = malloc(2 * sizeof (char));
	//Tile29.asset = Dummy.asset;
	//
	//struct tile Tile30;
	//Tile30.id = malloc(sizeof(int*));
	//Tile30.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile30.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile30.flags = malloc(2 * sizeof (char));
	//Tile30.asset = Dummy.asset;
	//
	//struct tile Tile31;
	//Tile31.id = malloc(sizeof(int*));
	//Tile31.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile31.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile31.flags = malloc(2 * sizeof (char));
	//Tile31.asset = Dummy.asset;
	//
	//struct tile Tile32;
	//Tile32.id = malloc(sizeof(int*));
	//Tile32.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile32.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile32.flags = malloc(2 * sizeof (char));
	//Tile32.asset = Dummy.asset;
	//
	//struct tile Tile33;
	//Tile33.id = malloc(sizeof(int*));
	//Tile33.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile33.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile33.flags = malloc(2 * sizeof (char));
	//Tile33.asset = Dummy.asset;
	//
	//struct tile Tile34;
	//Tile34.id = malloc(sizeof(int*));
	//Tile34.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile34.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile34.flags = malloc(2 * sizeof (char));
	//Tile34.asset = Dummy.asset;
	//
	//struct tile Tile35;
	//Tile35.id = malloc(sizeof(int*));
	//Tile35.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile35.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile35.flags = malloc(2 * sizeof (char));
	//Tile35.asset = Dummy.asset;
	//
	//struct tile Tile36;
	//Tile36.id = malloc(sizeof(int*));
	//Tile36.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile36.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile36.flags = malloc(2 * sizeof (char));
	//Tile36.asset = Dummy.asset;
	//
	//struct tile Tile37;
	//Tile37.id = malloc(sizeof(int*));
	//Tile37.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile37.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile37.flags = malloc(2 * sizeof (char));
	//Tile37.asset = Dummy.asset;
	//
	//struct tile Tile38;
	//Tile38.id = malloc(sizeof(int*));
	//Tile38.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile38.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile38.flags = malloc(2 * sizeof (char));
	//Tile38.asset = Dummy.asset;
	//
	//struct tile Tile39;
	//Tile39.id = malloc(sizeof(int*));
	//Tile39.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile39.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile39.flags = malloc(2 * sizeof (char));
	//Tile39.asset = Dummy.asset;
	//
	//struct tile Tile40;
	//Tile40.id = malloc(sizeof(int*));
	//Tile40.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile40.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile40.flags = malloc(2 * sizeof (char));
	//Tile40.asset = Dummy.asset;
	//
	//struct tile Tile41;
	//Tile41.id = malloc(sizeof(int*));
	//Tile41.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile41.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile41.flags = malloc(2 * sizeof (char));
	//Tile41.asset = Dummy.asset;
	//
	//struct tile Tile42;
	//Tile42.id = malloc(sizeof(int*));
	//Tile42.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile42.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile42.flags = malloc(2 * sizeof (char));
	//Tile42.asset = Dummy.asset;
	//
	//struct tile Tile43;
	//Tile43.id = malloc(sizeof(int*));
	//Tile43.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile43.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile43.flags = malloc(2 * sizeof (char));
	//Tile43.asset = Dummy.asset;
	//
	//struct tile Tile44;
	//Tile44.id = malloc(sizeof(int*));
	//Tile44.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile44.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile44.flags = malloc(2 * sizeof (char));
	//Tile44.asset = Dummy.asset;
	//
	//struct tile Tile45;
	//Tile45.id = malloc(sizeof(int*));
	//Tile45.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile45.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile45.flags = malloc(2 * sizeof (char));
	//Tile45.asset = Dummy.asset;

	//struct tile Tile46;
	//Tile46.id = malloc(sizeof(int*));
	//Tile46.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile46.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile46.flags = malloc(2 * sizeof (char));
	//Tile46.asset = Dummy.asset;
	//
	//struct tile Tile47;
	//Tile47.id = malloc(sizeof(int*));
	//Tile47.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile47.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile47.flags = malloc(2 * sizeof (char));
	//Tile47.asset = Dummy.asset;
	//
	//struct tile Tile48;
	//Tile48.id = malloc(sizeof(int*));
	//Tile48.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile48.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile48.flags = malloc(2 * sizeof (char));
	//Tile48.asset = Dummy.asset;
	//
	//struct tile Tile49;
	//Tile49.id = malloc(sizeof(int*));
	//Tile49.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile49.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile49.flags = malloc(2 * sizeof (char));
	//Tile49.asset = Dummy.asset;
	//
	//struct tile Tile50;
	//Tile50.id = malloc(sizeof(int*));
	//Tile50.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile50.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile50.flags = malloc(2 * sizeof (char));
	//Tile50.asset = Dummy.asset;
	//
	//struct tile Tile51;
	//Tile51.id = malloc(sizeof(int*));
	//Tile51.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile51.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile51.flags = malloc(2 * sizeof (char));
	//Tile51.asset = Dummy.asset;
	//
	//struct tile Tile52;
	//Tile52.id = malloc(sizeof(int*));
	//Tile52.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile52.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile52.flags = malloc(2 * sizeof (char));
	//Tile52.asset = Dummy.asset;
	//
	//struct tile Tile53;
	//Tile53.id = malloc(sizeof(int*));
	//Tile53.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile53.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile53.flags = malloc(2 * sizeof (char));
	//Tile53.asset = Dummy.asset;
	//
	//struct tile Tile54;
	//Tile54.id = malloc(sizeof(int*));
	//Tile54.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile54.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile54.flags = malloc(2 * sizeof (char));
	//Tile54.asset = Dummy.asset;
	//
	//struct tile Tile55;
	//Tile55.id = malloc(sizeof(int*));
	//Tile55.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile55.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile55.flags = malloc(2 * sizeof (char));
	//Tile55.asset = Dummy.asset;
	//
	//struct tile Tile56;
	//Tile56.id = malloc(sizeof(int*));
	//Tile56.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile56.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile56.flags = malloc(2 * sizeof (char));
	//Tile56.asset = Dummy.asset;
	//
	//struct tile Tile57;
	//Tile57.id = malloc(sizeof(int*));
	//Tile57.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile57.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile57.flags = malloc(2 * sizeof (char));
	//Tile57.asset = Dummy.asset;
	//
	//struct tile Tile58;
	//Tile58.id = malloc(sizeof(int*));
	//Tile58.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile58.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile58.flags = malloc(2 * sizeof (char));
	//Tile58.asset = Dummy.asset;
	//
	//struct tile Tile59;
	//Tile59.id = malloc(sizeof(int*));
	//Tile59.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile59.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile59.flags = malloc(2 * sizeof (char));
	//Tile59.asset = Dummy.asset;
	//
	//struct tile Tile60;
	//Tile60.id = malloc(sizeof(int*));
	//Tile60.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile60.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile60.flags = malloc(2 * sizeof (char));
	//Tile60.asset = Dummy.asset;
	//
	//struct tile Tile61;
	//Tile61.id = malloc(sizeof(int*));
	//Tile61.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile61.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile61.flags = malloc(2 * sizeof (char));
	//Tile61.asset = Dummy.asset;
	//
	//struct tile Tile62;
	//Tile62.id = malloc(sizeof(int*));
	//Tile62.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile62.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile62.flags = malloc(2 * sizeof (char));
	//Tile62.asset = Dummy.asset;
	//
	//struct tile Tile63;
	//Tile63.id = malloc(sizeof(int*));
	//Tile63.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile63.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile63.flags = malloc(2 * sizeof (char));
	//Tile63.asset = Dummy.asset;
	//
	//struct tile Tile64;
	//Tile64.id = malloc(sizeof(int*));
	//Tile64.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile64.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile64.flags = malloc(2 * sizeof (char));
	//Tile64.asset = Dummy.asset;
	//
	//struct tile Tile65;
	//Tile65.id = malloc(sizeof(int*));
	//Tile65.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile65.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile65.flags = malloc(2 * sizeof (char));
	//Tile65.asset = Dummy.asset;
	//
	//struct tile Tile66;
	//Tile66.id = malloc(sizeof(int*));
	//Tile66.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile66.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile66.flags = malloc(2 * sizeof (char));
	//Tile66.asset = Dummy.asset;
	//
	//struct tile Tile67;
	//Tile67.id = malloc(sizeof(int*));
	//Tile67.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile67.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile67.flags = malloc(2 * sizeof (char));
	//Tile67.asset = Dummy.asset;
	//
	//struct tile Tile68;
	//Tile68.id = malloc(sizeof(int*));
	//Tile68.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile68.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile68.flags = malloc(2 * sizeof (char));
	//Tile68.asset = Dummy.asset;
	//
	//struct tile Tile69;
	//Tile69.id = malloc(sizeof(int*));
	//Tile69.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile69.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile69.flags = malloc(2 * sizeof (char));
	//Tile69.asset = Dummy.asset;
	//
	//struct tile Tile70;
	//Tile70.id = malloc(sizeof(int*));
	//Tile70.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile70.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile70.flags = malloc(2 * sizeof (char));
	//Tile70.asset = Dummy.asset;
	//
	//struct tile Tile71;
	//Tile71.id = malloc(sizeof(int*));
	//Tile71.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile71.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile71.flags = malloc(2 * sizeof (char));
	//Tile71.asset = Dummy.asset;
	//
	//struct tile Tile72;
	//Tile72.id = malloc(sizeof(int*));
	//Tile72.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile72.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile72.flags = malloc(2 * sizeof (char));
	//Tile72.asset = Dummy.asset;
	//
	//struct tile Tile73;
	//Tile73.id = malloc(sizeof(int*));
	//Tile73.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile73.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile73.flags = malloc(2 * sizeof (char));
	//Tile73.asset = Dummy.asset;
	//
	//struct tile Tile74;
	//Tile74.id = malloc(sizeof(int*));
	//Tile74.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile74.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile74.flags = malloc(2 * sizeof (char));
	//Tile74.asset = Dummy.asset;
	//
	//struct tile Tile75;
	//Tile75.id = malloc(sizeof(int*));
	//Tile75.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile75.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile75.flags = malloc(2 * sizeof (char));
	//Tile75.asset = Dummy.asset;
	//
	//struct tile Tile76;
	//Tile76.id = malloc(sizeof(int*));
	//Tile76.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile76.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile76.flags = malloc(2 * sizeof (char));
	//Tile76.asset = Dummy.asset;
	//
	//struct tile Tile77;
	//Tile77.id = malloc(sizeof(int*));
	//Tile77.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile77.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile77.flags = malloc(2 * sizeof (char));
	//Tile77.asset = Dummy.asset;
	//
	//struct tile Tile78;
	//Tile78.id = malloc(sizeof(int*));
	//Tile78.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile78.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile78.flags = malloc(2 * sizeof (char));
	//Tile78.asset = Dummy.asset;
	//
	//struct tile Tile79;
	//Tile79.id = malloc(sizeof(int*));
	//Tile79.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile79.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile79.flags = malloc(2 * sizeof (char));
	//Tile79.asset = Dummy.asset;
	//
	//struct tile Tile80;
	//Tile80.id = malloc(sizeof(int*));
	//Tile80.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile80.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile80.flags = malloc(2 * sizeof (char));
	//Tile80.asset = Dummy.asset;
	//
	//struct tile Tile81;
	//Tile81.id = malloc(sizeof(int*));
	//Tile81.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile81.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile81.flags = malloc(2 * sizeof (char));
	//Tile81.asset = Dummy.asset;
	//
	//struct tile Tile82;
	//Tile82.id = malloc(sizeof(int*));
	//Tile82.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile82.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile82.flags = malloc(2 * sizeof (char));
	//Tile82.asset = Dummy.asset;
	//
	//struct tile Tile83;
	//Tile83.id = malloc(sizeof(int*));
	//Tile83.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile83.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile83.flags = malloc(2 * sizeof (char));
	//Tile83.asset = Dummy.asset;
	//
	//struct tile Tile84;
	//Tile84.id = malloc(sizeof(int*));
	//Tile84.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile84.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile84.flags = malloc(2 * sizeof (char));
	//Tile84.asset = Dummy.asset;
	//
	//struct tile Tile85;
	//Tile85.id = malloc(sizeof(int*));
	//Tile85.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile85.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile85.flags = malloc(2 * sizeof (char));
	//Tile85.asset = Dummy.asset;
	//
	//struct tile Tile86;
	//Tile86.id = malloc(sizeof(int*));
	//Tile86.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile86.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile86.flags = malloc(2 * sizeof (char));
	//Tile86.asset = Dummy.asset;
	//
	//struct tile Tile87;
	//Tile87.id = malloc(sizeof(int*));
	//Tile87.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile87.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile87.flags = malloc(2 * sizeof (char));
	//Tile87.asset = Dummy.asset;
	//
	//struct tile Tile88;
	//Tile88.id = malloc(sizeof(int*));
	//Tile88.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile88.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile88.flags = malloc(2 * sizeof (char));
	//Tile88.asset = Dummy.asset;
	//
	//struct tile Tile89;
	//Tile89.id = malloc(sizeof(int*));
	//Tile89.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile89.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile89.flags = malloc(2 * sizeof (char));
	//Tile89.asset = Dummy.asset;
	//
	//struct tile Tile90;
	//Tile90.id = malloc(sizeof(int*));
	//Tile90.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile90.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile90.flags = malloc(2 * sizeof (char));
	//Tile90.asset = Dummy.asset;
	//
	//struct tile Tile91;
	//Tile91.id = malloc(sizeof(int*));
	//Tile91.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile91.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile91.flags = malloc(2 * sizeof (char));
	//Tile91.asset = Dummy.asset;
	//
	//struct tile Tile92;
	//Tile92.id = malloc(sizeof(int));
	//Tile92.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile92.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile92.flags = malloc(2 * sizeof (char));
	//Tile92.asset = Dummy.asset;
	//
	//struct tile Tile93;
	//Tile93.id = malloc(sizeof(int*));
	//Tile93.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile93.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile93.flags = malloc(2 * sizeof (char));
	//Tile93.asset = Dummy.asset;
	//
	//struct tile Tile94;
	//Tile94.id = malloc(sizeof(int*));
	//Tile94.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile94.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile94.flags = malloc(2 * sizeof (char));
	//Tile94.asset = Dummy.asset;
	//
	//struct tile Tile95;
	//Tile95.id = malloc(sizeof(int*));
	//Tile95.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile95.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile95.flags = malloc(2 * sizeof (char));
	//Tile95.asset = Dummy.asset;
	//
	//struct tile Tile96;
	//Tile96.id = malloc(sizeof(int*));
	//Tile96.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile96.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile96.flags = malloc(2 * sizeof (char));
	//Tile96.asset = Dummy.asset;
	//
	//struct tile Tile97;
	//Tile97.id = malloc(sizeof(int*));
	//Tile97.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile97.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile97.flags = malloc(2 * sizeof (char));
	//Tile97.asset = Dummy.asset;
	//
	//struct tile Tile98;
	//Tile98.id = malloc(sizeof(int*));
	//Tile98.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile98.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile98.flags = malloc(2 * sizeof (char));
	//Tile98.asset = Dummy.asset;
	//
	//struct tile Tile99;
	//Tile99.id = malloc(sizeof(int*));
	//Tile99.layout = malloc(3 * sizeof(char*)); // allocates one dimension
	//for (int j = 0; j < 6; j++)
	//{
	//	Tile99.layout[j] = malloc(3 * sizeof(char*)); // allocates the second dimension
	//}
	//Tile99.flags = malloc(2 * sizeof (char));
	//Tile99.asset = Dummy.asset;

	/*struct tile local_tiles[100] = {Tile0, Tile1, Tile2, Tile3, Tile4, Tile5, Tile6, Tile7, Tile8, Tile9, 
		Tile10, Tile11, Tile12, Tile13, Tile14, Tile15, Tile16, Tile17, Tile18, Tile19, Tile20, 
		Tile21, Tile22, Tile23, Tile24, Tile25, Tile26, Tile27, Tile28, Tile29, Tile30, 
		Tile31, Tile32, Tile33, Tile34, Tile35, Tile36, Tile37, Tile38, Tile39, Tile40,
		Tile41, Tile42, Tile43, Tile44, Tile45, Tile46, Tile47, Tile48, Tile49, Tile50,
		Tile51, Tile52, Tile53, Tile54, Tile55, Tile56, Tile57, Tile58, Tile59, Tile60,
		Tile61, Tile62, Tile63, Tile64, Tile65, Tile66, Tile67, Tile68, Tile69, Tile70,
		Tile71, Tile72, Tile73, Tile74, Tile75, Tile76, Tile77, Tile78, Tile79, Tile80,
		Tile81, Tile82, Tile83, Tile84, Tile85, Tile86, Tile87, Tile88, Tile89, Tile90,
		Tile91, Tile92, Tile93, Tile94, Tile95, Tile96, Tile97, Tile98, Tile99};*/

	init_local_tiles(local_tiles);
	init_tiles(local_tiles);

	int pos[2] = { player.xpos, player.ypos };

	init_screen(screen);
	load_scene(TestZone, screen, tile_ids, ref, local_tiles, tile_frequency);
	load_tiles(tile_frequency, local_tiles, Dummy, Tiles);
	//system("PAUSE");
	print_screen(screen, pos, local_tiles, tile_ids);
	print_menu(TestText);
	load_settings(settings);
	print_tile_ids(tile_ids);
	print_frequency(tile_frequency);


	while (exit != 1)
	{
		input = _getche();

		update_location(tile_ids, ref, pos, input, local_tiles);
		input = '\0';
		system("cls");
		print_screen(screen, pos, local_tiles, tile_ids);
		print_menu(TestText);
		printf("Player position is %d %d.\n", pos[0], pos[1]);
	}

	return 0;
}