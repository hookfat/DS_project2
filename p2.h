using namespace std;

typedef struct{
    int x;
    int y;
}Point;

class myqueue;
class graph;
class node;

class node{
public:
    Point *data;
    node *next;
    node(){
        data = new Point;
        data->x = -1;
        data->y = -1;
        next = nullptr;
    }
    node(Point* a){
        data = new Point;
        data->x = a->x;
        data->y = a->y;
        next = nullptr;
    }
    ~node(){
        delete data;
        next = nullptr;
    }
    friend class myqueue;
};

class myqueue{
public:
    myqueue(){
        head = nullptr;
        tail = nullptr;
    }
    ~myqueue();
    void push(Point*);
    void pop();
    Point* gethead();
    Point* gettail();
    bool isempty();
private:
    node* head;
    node* tail;
};

class graph{
public:
    graph();
    ~graph();
    void readmap();
    void showmap();
    void BFS();
    void show_bfs_list();
    void walk(Point*);
    void impl();
    void to_far();
    void roaming();
    int recharge();
    void showpath();
    Point* find_way();//盡力找到最近的沒走過的點
private:
    char** road;
    int** bfs_map;
    int x, y, battery; //x是往下數的
    int total_0;
    node** bfs_to_R;
    Point* R_point;
    int far_point;
    int far_limit;
    Point* now_pos;
    int now_step;
    node* path;
    node* path_last;
    int step;
};
