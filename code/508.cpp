#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<set>
#include<algorithm>
#include<vector>
#include<stack>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;
const int MAXN = 100005;
struct trienode {
    int id;//这个单词的序号，只有单词的最后的结点才有
    trienode *next[4]; //如果为ASCII码可见字符，则为128
    trienode *fail;//失败指针
};
char strx[MAXN];
char str[MAXN];//匹配穿
int num[MAXN];
int fa[MAXN];
int t, c = 0, n;
int convert(char x) {
    if(x == 'A') return 0;
    if(x == 'T') return 1;
    if(x == 'G') return 2;
    return 3;
}

void inserttrie(trienode* &root, char* key, int idx) { //将字符串key放入字段树
    trienode *p = root;
    int len = strlen(key);
    for(int i = 0; i <= len - 1; i++) {
        int k = convert(key[i]);
        if(p->next[k] == NULL) {
            p->next[k] = (struct trienode*)malloc(sizeof(struct trienode));
            p->next[k]->fail = NULL;
            p->next[k]->id = 0;
            memset(p->next[k]->next, 0, sizeof(p->next[k]->next));
        }
        p = p->next[k];
    }
    if(p->id != 0)fa[idx] = p->id;
    else p->id = idx;
}
void buildfail(trienode *&root) { //用bfs建立失配指针
    queue<trienode*> q;
    q.push(root);
    while(!q.empty()) {
        trienode* temp = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
            if(temp->next[i]) {
                if(temp == root)
                    temp->next[i]->fail = root;
                else {
                    //兄弟结点之间不能建立失败指针，所以不断回溯，如果该结点的
                    //父节点的失败指针对应的结点next[i]存在,则将这个结点的失败指针连到这里
                    //回溯到root都没有，则结点的失败指针直接指向root
                    trienode *p = temp->fail;
                    while(p) {
                        if(p->next[i]) {
                            temp->next[i]->fail = p->next[i];
                            break;
                        }
                        p = p->fail;
                    }
                    if(!p)
                        temp->next[i]->fail = root;
                }
                q.push(temp->next[i]);
            }
    }
}
void query(trienode *&root) {
    memset(num, 0, sizeof(num));
    trienode *p = root;
    int len = strlen(str);
    for(int i = 0; i <= len - 1; i++) {
        if(str[i] < 'A' || str[i] > 'Z') {
            p = root;
            continue;
        }
        int k = convert(str[i]);
        while(!p->next[k] && p != root)
            p = p->fail;
        p = p->next[k];
        if(!p)
            p = root;
        trienode *temp = p;
        while(temp != root) {
            if(temp->id > 0)
                num[temp->id]++;
            temp = temp->fail;
        }
    }
    for(int i = 1; i <= n; i++) {
        int idx = i;
        if(fa[idx] != 0) idx = fa[idx];
        printf("%d\n", num[idx]);
    }
}

int main() {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d\n", &t);
    while(t--) {
        if(c) gets(str);
        gets(str);
        printf("Case #%d\n", ++c);
        scanf("%d\n", &n);
        memset(fa, 0, sizeof(fa));
        trienode *root = (struct trienode*)malloc(sizeof(struct trienode));
        root->fail = NULL;
        root->id = 0;
        memset(root->next,0,sizeof(root->next));
        int idx = 0;
        for(int i = 1; i <= n; i++) {
            gets(strx);
            idx++;
            inserttrie(root, strx, idx);
        }
        buildfail(root);
        query(root);
    }
    return 0;
}