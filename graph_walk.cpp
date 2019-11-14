#include "p2.h"
#include <iostream>

void graph::start()
{
    while(total_0 != 0){
        to_far();
        roaming();
    }
}

void graph::to_far() //從最遠的點找一條路回來R
{
    for(int i = 1; i<=far_limit; i++){
        if(bfs_to_R[i] != nullptr){
            far_point = i;
        }
    }
    Point *p = bfs_to_R[far_point]->data;
    node* far_way = new node(p);
    node* temp = nullptr;
    //從最遠的點逆推一條路回來 並且存在far_way裡面
    for(int i = 0; i<far_point; i++){
        int buf[4];
        int len = bfs_map[p->x][p->y];
        for(int j = 0; j<4; j++){
            buf[j] = -1;
        }
        if(p->x - 1 > 0){
            if(bfs_map[p->x-1][p->y] == len-1){
                if(road[p->x-1][p->y] == '0' || road[p->x-1][p->y] == 'R'){
                    temp = new node();
                    temp->data->x = p->x-1;
                    temp->data->y = p->y;
                    temp->next = far_way;
                    far_way = temp;
                    p = temp->data;
                    continue;
                }
                else{
                    buf[0] = 1;
                }
            }
        }
        if(p->x + 1 < x){
            if(bfs_map[p->x+1][p->y] == len-1){
                if(road[p->x+1][p->y] == '0' || road[p->x+1][p->y] == 'R'){
                    temp = new node();
                    temp->data->x = p->x+1;
                    temp->data->y = p->y;
                    temp->next = far_way;
                    far_way = temp;
                    p = temp->data;
                    continue;
                }
                else{
                    buf[0] = 1;
                }
            }
        }
        if(p->y - 1 > 0){
            if(bfs_map[p->x][p->y-1] == len-1){
                if(road[p->x][p->y-1] == '0' || road[p->x][p->y-1] == 'R'){
                    temp = new node();
                    temp->data->x = p->x;
                    temp->data->y = p->y-1;
                    temp->next = far_way;
                    far_way = temp;
                    p = temp->data;
                    continue;
                }
                else{
                    buf[0] = 1;
                }
            }
        }
        if(p->y + 1 < y){
            if(bfs_map[p->x][p->y+1] == len-1){
                if(road[p->x][p->y+1] == '0' || road[p->x][p->y+1] == 'R'){
                    temp = new node();
                    temp->data->x = p->x;
                    temp->data->y = p->y+1;
                    temp->next = far_way;
                    far_way = temp;
                    p = temp->data;
                    continue;
                }
                else{
                    buf[0] = 1;
                }
            }
        }
        if(buf[0] == 1){
            temp = new node();
            temp->data->x = p->x-1;
            temp->data->y = p->y;
            temp->next = far_way;
            far_way = temp;
            p = temp->data;
        }
        else if(buf[1] == 1){
            temp = new node();
            temp->data->x = p->x+1;
            temp->data->y = p->y;
            temp->next = far_way;
            far_way = temp;
            p = temp->data;
        }
        else if(buf[2] == 1){
            temp = new node();
            temp->data->x = p->x;
            temp->data->y = p->y-1;
            temp->next = far_way;
            far_way = temp;
            p = temp->data;
        }
        else if(buf[3] == 1){
            temp = new node();
            temp->data->x = p->x;
            temp->data->y = p->y+1;
            temp->next = far_way;
            far_way = temp;
            p = temp->data;
        }
    }
    //end
    while(far_way != nullptr){
        walk(far_way->data);
        temp = far_way;
        far_way = far_way->next;
        delete temp;
    }
}

int graph::recharge() //傳入目前的位置 如果需要就返回充電
{
    if((battery - now_step) > bfs_map[now_pos->x][now_pos->y]){
        return 0;
    }
    else{

    }
}

void graph::roaming()
{
    Point* p = new Point;
    while(!recharge())
    {

    }
    delete p;
}

Point* graph::find_way()
{

}
