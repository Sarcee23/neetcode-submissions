class TrieNode{
    public:
        bool word;
        array<TrieNode*,26> children;

        TrieNode(): word(false){
            children.fill(nullptr);
        }
};

class WordDictionary {
private:
    TrieNode* root;
    bool searchHelper(const char* word,TrieNode* node){
        for(int i=0;word[i]&&node;i++){
            if(word[i]!='.'){
                node = node->children[word[i]-'a'];
            }
            else{
                for(TrieNode* child : node->children){
                    if(child && searchHelper(word+i+1,child)){
                        return true;
                    }
                }
                return false;
            }
        }
        return node && node->word;
    }
public:
    WordDictionary(): root(new TrieNode()){}
    
    void addWord(const string& word){
        TrieNode* node = root;
        for(char c: word){
            int index = c -'a';
            if(!node->children[index]){
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->word = true;;
    }

    bool search(const string& word){
        return searchHelper(word.c_str(),root);
    }
};
