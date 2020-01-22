/**********TRIE*********TRIE*********TRIE********TRIE*****/

//다루고 싶은 문자 종류에 따라 변경하여 사용.
const int BRANCH_SIZE = 26;
int toNumber(char ch) { return ch - 'A'; }

struct TrieNode {
    TrieNode* children[BRANCH_SIZE];
    bool isEndOfWord;

    // Constructor
    TrieNode() : isEndOfWord(false) {
        // 다음 TrieNode를 가리키는 children 초기값은 
        // 모두 NULL로 비어있음을 보장하도록 합니다.
        memset(children, NULL, sizeof(children));
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
            if (children[next] == NULL) //자식 노드가 없다면 생성.
                children[next] = new TrieNode();
            here = here->children[next]; //다음 문자로 재귀 호출.
        }
        isEndOfWord = true;
    }

    bool find(const string& key) {
        TrieNode* here = this;
        int len = key.length();
        if (len == 0) return false;         // Choose for empty strings.

        for (int i = 0; i < len; i++) {     //If isEndOfWord == true, return here.
            int next = toNumber(key[i]);    //If not, search next character.
            if (here->children[i] == NULL)
                return false;
            here = here->children[i];
        }

        return here->isEndOfWord;     // Recursive
    }

};

/**********TRIE***********END**********TRIE**********END************/
