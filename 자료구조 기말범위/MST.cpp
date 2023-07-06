#include <iostream>
#define N 10
using namespace std;
typedef int element;

class ListNode;

class Edge{
    public:
    int v1, v2, weight;
    Edge* next;
};

class IncidentNode{
    public:
    Edge* e;
    IncidentNode* next;
    element data;
    void insert(ListNode* node, element e, Edge* E);
};

class ListNode{
    int V[N];
    int dist[N];
    Edge* arr[N];
    Edge* eHead;
    int size, count, isVisit;
    element data;
    ListNode* next;
    public:
    IncidentNode* head;
    void init();
    void insert(element e);
    void insertIncident(element e1, element e2, Edge* E);
    ListNode* findNode(element e);
    void insertEdge(int v1, int v2, int w);
    void sort();
    int find(int num);
    void Union(int v1, int v2);
    void kruskal();
    int getMin();
    void prim(int v);
};

void IncidentNode::insert(ListNode* node, element e, Edge* E){
    IncidentNode* p = new IncidentNode;
    p->e = E;
    p->data = e;
    p->next = NULL;

    IncidentNode* q = node->head;
    if(q==NULL)
        node->head = p;
    else{
        while(q->next!=NULL)
            q = q->next;
        q->next = p;
    }
}

void ListNode::init(){
    head = NULL;
    next = NULL;
    size = 0;
    count = 0;
    isVisit = 0;
    eHead = NULL;
    for(int i=0;i<N;i++){
        V[i] = -1;
        dist[i] = 100;
    }
}

void ListNode::insert(element e){
    ListNode* p = next;
    ListNode* q = new ListNode;
    q->data = e;
    q->next = NULL;
    q->head = NULL;
    count++;

    if(next==NULL)
        next = q;
    else{
        while(p->next != NULL)
            p = p->next;
        p->next = q;
    }
}

ListNode* ListNode::findNode(element e){
    ListNode* p = next;
    while(p->data != e)
        p = p->next;
    return p;
}

void ListNode::insertIncident(element e1, element e2, Edge* E){
    IncidentNode q;
    ListNode* p = this->findNode(e1);
    q.insert(p, e2, E);
    p = this->findNode(e2);
    q.insert(p, e1, E);
}

void ListNode::insertEdge(int v1, int v2, int w){
    Edge* E = new Edge;
    E->v1 = v1;
    E->v2 = v2;
    E->weight = w;
    E->next = NULL;
    size++;

    Edge* p = eHead;
    if(p == NULL)
        eHead = E;
    else{
        while(p->next != NULL)
            p = p->next;
        p->next = E;
    }

    insertIncident(v1,v2,E);
}

void ListNode::sort(){
    int i, j, least;
    Edge* p = eHead;
    for(i=0;i<size;i++){
        arr[i] = p;
        p = p->next;
    }


    for(i=0;i<=size - 2;i++){
        least = i;
        for(j=i+1;j<=size - 1; j++)
            if(arr[j]->weight < arr[least]->weight)
                least = j;
        p = arr[least];
        arr[least] = arr[i];
        arr[i] = p;
    }
    for(int i=0;i<size;i++){
        cout << "[" << arr[i]->v1 << " " << arr[i]->v2 << " "
        << arr[i]->weight << "]" << endl;
    }
    cout << endl;
}

int ListNode::find(int num){
    if(V[num] == -1)
        return num;
    
    while(V[num] != -1)
        num = V[num];
    return num;
}

void ListNode::Union(int v1, int v2){
    int V1 = find(v1);
    int V2 = find(v2);
    V[V2] = V1;
}

void ListNode::kruskal(){
    int eCnt = 0, k = 0;
    int v1, v2;
    Edge* p;

    while(eCnt < count - 1){
        p = arr[k];
        v1 = find(p->v1);
        v2 = find(p->v2);
        if(v1 != v2){
            eCnt++;
            cout << eCnt << " : " << p->v1 << " " << p->v2
            << " " << p->weight << endl;
            Union(v1,v2);
        }
        k++;
    }
}

int ListNode::getMin(){
    ListNode* p = next;
    char vName;

    for(; p != NULL; p = p->next){
        if(p->isVisit == 0){
            vName = p->data;
            break;
        }
    }
    for(p = next; p != NULL; p = p->next)
        if(p->isVisit == 0 && (dist[p->data] < dist[vName]))
            vName = p->data;

    return vName;
}

void ListNode::prim(int v){
    ListNode* p = findNode(v);
    IncidentNode* q;
    int num;

    dist[v] = 0;

    for(int i=0;i<count;i++){
        num = getMin();
        p = findNode(num);
        p->isVisit = 1;
        cout << p->data << " ";

        for(q = p->head; q != NULL; q = q->next){
            p = findNode(q->data);
            if(p->isVisit == 0 && dist[q->data] > q->e->weight)
                dist[q->data] = q->e->weight;
        }
    }
}

int main(){
    ListNode node;
    node.init();
    node.insert(0); node.insert(1); node.insert(2);
    node.insert(3); node.insert(4); node.insert(5);
    node.insert(6);

    node.insertEdge(0,1,29); node.insertEdge(0,5,10);
    node.insertEdge(1,2,16); node.insertEdge(1,6,15);
    node.insertEdge(2,3,12); node.insertEdge(3,4,22);
    node.insertEdge(3,6,18); node.insertEdge(4,5,27);
    node.insertEdge(4,6,25);

    // node.sort();
    // node.kruskal();

    node.prim(4);
}