class Solution
{
    bool isWord(string &word, int ind, int counter, unordered_set<string> &s)
    {
        if (ind >= word.length())
            return counter > 1;

        for (int i = ind; i < word.length(); i++)
        {
            string curr = word.substr(ind, i - ind + 1);
            if (s.count(curr))
            {
                if (isWord(word, i + 1, counter + 1, s))
                    return true;
            }
        }
        return false;
    }

public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {
        unordered_set<string> s;
        vector<string> sol;
        for (auto &it : words)
            s.insert(it);
        for (auto &it : words)
            if (isWord(it, 0, 0, s))
                sol.emplace_back(it);

        return sol;
    }
};


// class trieNode
// {
// public:
//     bool end;
//     vector<trieNode *> next;

//     trieNode()
//     {
//         vector<trieNode *> n(26, NULL);
//         end = false;
//         this->next = n;
//     }
// };
// class Solution
// {
//     void insertToTrie(trieNode *tri, string &word)
//     {
//         trieNode *temp = tri;
//         for (int i = 0; i < word.length(); i++)
//         {
//             if (!temp->next[word[i] - 'a'])
//             {
//                 temp->next[word[i] - 'a'] = new trieNode();
//             }
//             temp = temp->next[word[i] - 'a'];
//         }
//         temp->end = true;
//     }

//     bool isWord(trieNode *tri, string &word, int ind, int counter)
//     {
//         if (ind == word.length())
//             return counter > 1;

//         trieNode *temp = tri;
//         for (int i = ind; i < word.length(); i++)
//         {
//             if (!temp->next[word[i] - 'a'])
//                 return false;
//             temp = temp->next[word[i] - 'a'];
//             if (temp->end && isWord(tri, word, i + 1, counter + 1))
//                 return true;
//         }

//         return false;
//     }

// public:
//     vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
//     {
//         trieNode *tri = new trieNode();
//         vector<string> sol;
//         for (auto &it : words)
//             insertToTrie(tri, it);
//         for (auto &it : words)
//         {
//             if (isWord(tri, it, 0, 0))
//                 sol.emplace_back(it);
//         }

//         return sol;
//     }
// };