#include <iostream>
#include "p2.h"
using namespace std;

int main()
{
    graph* mymap;
    mymap = new graph();
    mymap->BFS();
    //mymap->showmap();
    //mymap->show_bfs_list();

    return 0;
}
