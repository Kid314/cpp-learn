#include <iostream>
#include <sstream>
#include <string>
/**
 * 思路，将句子分割，一个个数
 * 
 * 重点：std::istringstream stream(sentence);
 * 使sentence能和输入输出流一样，可以用>>操作，来分割string
 */
std::string sentence;

void solve()
{
    std::getline(std::cin, sentence);
    std::istringstream stream(sentence);//流化字符串，用于将句子分割
    std::string word;
    std::string longestWord;

    size_t longestLength = 0;
    size_t indexOfLongestWord = std::string::npos;//std::string::npos表示无效位置哇

    size_t currentIndex = 0; // 用于跟踪当前单词的起始索引

    while (stream >> word) 
    {
        size_t wordLength = word.length();
        if(word[word.length()-1]=='.')
            wordLength--;
        if (wordLength > longestLength) 
        {
            longestLength = wordLength;
            longestWord = word;
            indexOfLongestWord = currentIndex; // 更新最长单词的索引
        }
        // 更新当前单词的起始索引
        currentIndex += word.length() + 1; // +1 是为了考虑空格
    }
    std::cout<<indexOfLongestWord<<" "<<longestLength;
}
int main() {
    solve();
    return 0;
}
