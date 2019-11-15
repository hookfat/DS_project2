#include "p2.h"
#include <iostream>
using namespace std;

void graph::readmap()
{
    cin >> x >> y >> battery;
    road = new char*[x];
    for(int i = 0; i < x; ++i) {
        road[i] = new char[y];
    }

    bfs_map = new int*[x];
    for(int i = 0; i < x; ++i) {
        bfs_map[i] = new int[y];
    }

    char c;
    cin.ignore();
    for(int i = 0; i<x; i++){
        for(int j = 0; j<y; j++){
            cin.get(road[i][j]);
            if(road[i][j] == '0'){
                total_0++;
                bfs_map[i][j] = -1;
            }
            else if(road[i][j] == 'R'){
                R_point = new Point;
                R_point->x = i;
                R_point->y = j;
                bfs_map[i][j] = 0;
            }
            else{
                bfs_map[i][j] = 1000000;
            }
        }
        cin.ignore();
    }

}

void graph::showmap()
{
    for(int i = 0; i<x; i++){
        for(int j = 0; j<y; j++){
            cout << road[i][j];
        }
        cout << endl;
    }
}

void graph::BFS()
{
    bfs_to_R = new node*[total_0];
    node* last[total_0];
    bfs_to_R[0] = new node(R_point);
    for(int i = 1; i<=total_0; i++){
        bfs_to_R[i] = nullptr;
    }
    myqueue q1;
    int length = 0;
    Point p;
    if(R_point->x - 1 > 0){
        if(road[R_point->x-1][R_point->y] == '0'){
            p.x = R_point->x-1;
            p.y = R_point->y;
            bfs_map[p.x][p.y] = bfs_map[R_point->x][R_point->y]+1;
            q1.push(&p);
            bfs_to_R[1] = new node(&p);
            last[1] = bfs_to_R[1];
        }
    }
    if(R_point->x + 1 < x){
        if(road[R_point->x+1][R_point->y] == '0'){
            p.x = R_point->x+1;
            p.y = R_point->y;
            bfs_map[p.x][p.y] = bfs_map[R_point->x][R_point->y]+1;
            q1.push(&p);
            if(bfs_to_R[1] != nullptr){
                last[1]->next = new node(&p);
                last[1] = last[1]->next;
            }
            else{
                bfs_to_R[1] = new node(&p);
                last[1] = bfs_to_R[1];
            }
        }
    }
    if(R_point->y - 1 > 0){
        if(road[R_point->x][R_point->y-1] == '0'){
            p.x = R_point->x;
            p.y = R_point->y-1;
            bfs_map[p.x][p.y] = bfs_map[R_point->x][R_point->y]+1;
            q1.push(&p);
            if(bfs_to_R[1] != nullptr){
                last[1]->next = new node(&p);
                last[1] = last[1]->next;
            }
            else{
                bfs_to_R[1] = new node(&p);
                last[1] = bfs_to_R[1];
            }
        }
    }
    if(R_point->y+1 < y){
        if(road[R_point->x][R_point->y+1] == '0'){
            p.x = R_point->x;
            p.y = R_point->y+1;
            bfs_map[p.x][p.y] = bfs_map[R_point->x][R_point->y]+1;
            q1.push(&p);
            if(bfs_to_R[1] != nullptr){
                last[1]->next = new node(&p);
                last[1] = last[1]->next;
            }
            else{
                bfs_to_R[1] = new node(&p);
                last[1] = bfs_to_R[1];
            }
        }
    }
    while(!q1.isempty()){
        int i = q1.gethead()->x;
        int j = q1.gethead()->y;
        if(i+1 < x){
            if(road[i+1][j] == '0' && bfs_map[i+1][j] == -1){
                p.x = i+1;
                p.y = j;
                bfs_map[p.x][p.y] = bfs_map[i][j]+1;
                length = bfs_map[p.x][p.y];
                q1.push(&p);
                if(bfs_to_R[length] != nullptr){
                    last[length]->next = new node(&p);
                    last[length] = last[length]->next;
                }
                else{
                    bfs_to_R[length] = new node(&p);
                    last[length] = bfs_to_R[length];
                }
            }
        }
        if(i-1 > 0){
            if(road[i-1][j] == '0' && bfs_map[i-1][j] == -1){
                p.x = i-1;
                p.y = j;
                bfs_map[p.x][p.y] = bfs_map[i][j]+1;
                length = bfs_map[p.x][p.y];
                q1.push(&p);
                if(bfs_to_R[length] != nullptr){
                    last[length]->next = new node(&p);
                    last[length] = last[length]->next;
                }
                else{
                    bfs_to_R[length] = new node(&p);
                    last[length] = bfs_to_R[length];
                }
            }
        }
        if(j-1 > 0){
            if(road[i][j-1] == '0' && bfs_map[i][j-1] == -1){
                p.x = i;
                p.y = j-1;
                bfs_map[p.x][p.y] = bfs_map[i][j]+1;
                length = bfs_map[p.x][p.y];
                q1.push(&p);
                if(bfs_to_R[length] != nullptr){
                    last[length]->next = new node(&p);
                    last[length] = last[length]->next;
                }
                else{
                    bfs_to_R[length] = new node(&p);
                    last[length] = bfs_to_R[length];
                }
            }
        }
        if(j+1 < y){
            if(road[i][j+1] == '0' && bfs_map[i][j+1] == -1){
                p.x = i;
                p.y = j+1;
                bfs_map[p.x][p.y] = bfs_map[i][j]+1;
                length = bfs_map[p.x][p.y];
                q1.push(&p);
                if(bfs_to_R[length] != nullptr){
                    last[length]->next = new node(&p);
                    last[length] = last[length]->next;
                }
                else{
                    bfs_to_R[length] = new node(&p);
                    last[length] = bfs_to_R[length];
                }
            }
        }
        q1.pop();
    }
    for(int i = 1; i<=total_0; i++){
        if(bfs_to_R[i] == nullptr){
            far_limit = i-1;
            break;
        }
        else
            far_limit = i;
    }
}

void graph::show_bfs_list()
{
    for(int i = 1; i<=total_0; i++){
        if(bfs_to_R[i] == nullptr)
            break;
        else{
            cout << i << ": " << endl;
            node* temp = bfs_to_R[i];
            while(temp != nullptr){
                cout << '(' << temp->data->x << ','<< temp->data->y << ")" << endl;
                temp = temp->next;
            }
        }
    }
}

graph::graph()
{
    total_0 = 0;
    step = 0;
    path = nullptr;
    path_last = path;
    readmap();
    now_pos = new Point;
    now_pos->x = R_point->x;
    now_pos->y = R_point->y;
    now_step = 0;
}

graph::~graph()
{
    for(int i = 0; i < y; ++i) {
        delete [] road[i];
    }
    delete [] road;
}

void graph::walk(Point* p)
{
    step++;
    now_step++;
    //cout << p->x << " " << p->y << endl;
    if(path != nullptr){
        path_last->next = new node(p);
        path_last = path_last->next;
    }
    else{
        path = new node(p);
        path_last = path;
    }
    if(road[p->x][p->y] == '0'){
        road[p->x][p->y] = 'T';
        total_0--;
        node* temp = bfs_to_R[bfs_map[p->x][p->y]];
        node* temp1 = nullptr;
        while(temp->data->x != p->x || temp->data->y != p->y){
            temp1 = temp;
            temp = temp->next;
        }
        if(temp != bfs_to_R[bfs_map[p->x][p->y]]){
            temp1->next = temp->next;
            delete temp;
        }
        else{
            bfs_to_R[bfs_map[p->x][p->y]] = temp->next;
            delete temp;
        }
    }
}

void graph::showpath()
{
    cout << step << endl;
    node* temp = path;
    while(temp != nullptr){
        cout << temp->data->x << " " << temp->data->y << endl;
        temp = temp->next;
    }
}
