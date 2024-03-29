#include "p2.h"
#include <iostream>

void graph::impl()
{
    while(total_0 != 0){
        to_far();
    }
    //cout << "QQ";
}

void graph::to_far() //從最遠的點找一條路回來R
{
    int far_len = 0;
    for(int i = 1; i<=far_limit; i++){
        if(bfs_to_R[i] != nullptr)
            far_len = i;
    }
    node* start = bfs_to_R[far_len];

    node* the_way = new node();
    the_way->data->x = start->data->x;
    the_way->data->y = start->data->y;
    node* the_way_start = the_way;
    //選擇能走的路，長度必須是目前長度減一
    //最好還是沒走過的路
    int now_far = far_len;
    for(int i = 1; i<far_len; i++, now_far--){
        int nx = the_way_start->data->x;
        int ny = the_way_start->data->y;
        int buf[4] = {0};
        if(nx - 1 > 0){
            if(bfs_map[nx-1][ny] == now_far-1){
                if(road[nx-1][ny] == 'R' || road[nx-1][ny] == '0'){
                    the_way_start = new node();
                    the_way_start->next = the_way;
                    the_way_start->data->x = nx-1;
                    the_way_start->data->y = ny;
                    the_way = the_way_start;
                    continue;
                }
                else{
                    buf[0] = 1;
                }
            }
        }
        if(nx + 1 < x){
            if(bfs_map[nx+1][ny] == now_far-1){
                if(road[nx+1][ny] == 'R' || road[nx+1][ny] == '0'){
                    the_way_start = new node();
                    the_way_start->next = the_way;
                    the_way_start->data->x = nx+1;
                    the_way_start->data->y = ny;
                    the_way = the_way_start;
                    continue;
                }
                else{
                    buf[1] = 1;
                }
            }
        }
        if(ny - 1 > 0){
            if(bfs_map[nx][ny-1] == now_far-1){
                if(road[nx][ny-1] == 'R' || road[nx][ny-1] == '0'){
                    the_way_start = new node();
                    the_way_start->next = the_way;
                    the_way_start->data->x = nx;
                    the_way_start->data->y = ny-1;
                    the_way = the_way_start;
                    continue;
                }
                else{
                    buf[2] = 1;
                }
            }
        }
        if(ny + 1 < y){
            if(bfs_map[nx][ny+1] == now_far-1){
                if(road[nx][ny+1] == 'R' || road[nx][ny+1] == '0'){
                    the_way_start = new node();
                    the_way_start->next = the_way;
                    the_way_start->data->x = nx;
                    the_way_start->data->y = ny+1;
                    the_way = the_way_start;
                    continue;
                }
                else{
                    buf[3] = 1;
                }
            }
        }
        if(buf[0] == 1){
            the_way_start = new node();
            the_way_start->next = the_way;
            the_way_start->data->x = nx-1;
            the_way_start->data->y = ny;
            the_way = the_way_start;
        }
        else if(buf[1] == 1){
            the_way_start = new node();
            the_way_start->next = the_way;
            the_way_start->data->x = nx+1;
            the_way_start->data->y = ny;
            the_way = the_way_start;
        }
        else if(buf[2] == 1){
            the_way_start = new node();
            the_way_start->next = the_way;
            the_way_start->data->x = nx;
            the_way_start->data->y = ny-1;
            the_way = the_way_start;
        }
        else if(buf[3] == 1){
            the_way_start = new node();
            the_way_start->next = the_way;
            the_way_start->data->x = nx;
            the_way_start->data->y = ny+1;
            the_way = the_way_start;
        }
    }

    node** temp = new node*[far_len];
    the_way_start = the_way;
    for(int i = 0; i<far_len; i++){
        temp[i] = the_way_start;
        the_way_start = the_way_start->next;
    }
    for(int i = 0; i<far_len; i++){
        walk(temp[i]->data);
    }
    for(int i = far_len-2; i>=0; i--){
        walk(temp[i]->data);
    }
    while(the_way != nullptr){
        the_way_start = the_way;
        the_way = the_way->next;
    }
    walk(R_point);
    delete []temp;
}


