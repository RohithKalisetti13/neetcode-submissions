class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        

        unordered_set<string> nextWord(wordList.begin(),wordList.end());
        int count = 1;
        queue<string>q;
        q.push(beginWord);
        nextWord.erase(beginWord);

        while(q.size()>0){
            int levelSize = q.size();

            for(int level=0;level<levelSize;level++){
                string curr = q.front();
                q.pop();

                if(curr==endWord) return count;

                for(int i=0;i<curr.size();i++){
                    char original = curr[i];

                    for(char c = 'a';c <= 'z';c++){
                        curr[i]=c; 

                        if(nextWord.count(curr)){
                            q.push(curr);
                            nextWord.erase(curr);
                        }  
                    }
                    curr[i]=original;
                }
            }
            count++;
        }
        return 0;

    }


};
