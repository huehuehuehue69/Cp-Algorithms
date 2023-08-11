class Node{
    public:
        Node* child[26];
        bool isEnd;
        int wordCount;
        Node(){
            for(int i = 0;i < (int)26; i++){
                child[i] = NULL;
            }
            wordCount = 0;
            isEnd = false;
        }
};
class Trie{
    Node* root;
    public:
    Trie(){
        root = new Node();
    }
    void insert(string s){
        Node* curr = root;
        for(auto x : s){
            int idx = x - 'a';
            if(curr->child[idx] == NULL){
                curr->child[idx] = new Node();
            }
            curr = curr->child[idx];
            curr->wordCount++;
        }
        curr->isEnd = true;
    }
    int prefix(string s){
        Node* curr = root;
        for(auto x : s){
            int idx = x - 'a';
            if(curr->child[idx]==NULL){
                return 0;
            }
            curr = curr->child[idx];
        }
        return curr->wordCount;
    }
};
