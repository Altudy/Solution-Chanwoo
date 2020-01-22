/**********TRIE*********TRIE*********TRIE********TRIE*****/

//change to suit your needs
const int BRANCH_SIZE = 26;
int toNumber(const char& ch) { return ch - 'A'; }

struct TrieNode {
public:
    TrieNode* children[BRANCH_SIZE];
    bool isEndOfWord;

    // Constructor
    TrieNode() : isEndOfWord(false) {
        // Initialize all children points to null;
        for (int i = 0; i < BRANCH_SIZE; i++)
            children[i] = 0;
    }
    // Destructor
    ~TrieNode() {
        for (int i = 0; i < BRANCH_SIZE; ++i)
            if (children[i])
                delete children[i];
    }

    void insert(const string& key) {
        TrieNode* here = this;
        int len = key.length();

        // INSERT OPERATION 
        for (int i = 0; i < len; i++) {
            int next = toNumber(key[i]);
            if (here->children[next] == NULL) //자식 노드가 없다면 생성.
                here->children[next] = new TrieNode();
            here = here->children[next]; //다음 문자로 재귀 호출.
        }
        here->isEndOfWord = true;
    }

    bool find(const string& key) {
        TrieNode* here = this;
        int len = key.length();
        if (len == 0) return false;         // Choose for empty strings.

        for (int i = 0; i < len; i++) {     //If isEndOfWord == true, return here.
            int next = toNumber(key[next]);    //If not, search next character.
            if (here->children[next] == NULL)
                return false;
            here = here->children[next];
        }
        return here->isEndOfWord;
    }

};

/**********TRIE***********END**********TRIE**********END************/
