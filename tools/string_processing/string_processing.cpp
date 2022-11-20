#include "string_processing.hpp"

#include <algorithm>
/*
    Функция парсит исходную строку txt на вектор строк strs и спользованием символа-разделителя ch.
*/
size_t split(const std::string &txt, std::vector<std::string> &strs, char ch)
{
    size_t pos = txt.find(ch);
    size_t initialPos = 0;
    strs.clear();

    // Decompose statement
    while( pos != std::string::npos ) {
        strs.push_back( txt.substr( initialPos, pos - initialPos ) );
        initialPos = pos + 1;

        pos = txt.find( ch, initialPos );
    }

    // Add the last one
    strs.push_back( txt.substr( initialPos, std::min( pos, txt.size() ) - initialPos + 1 ) );

    return strs.size();
} // -- END split

/*
Функция подрезает символ ch с правой и левой сторон строки, по умолчанию ch = ' ' - пробел
*/
int strip(std::string &str, char ch)
{
    int lcnt = 0, rcnt = 0;
    int n = str.length();
    while (str[lcnt] == ch)
        lcnt++;
    while (str[n - 1 - rcnt] == ch)
        rcnt++;
    if (lcnt)
    {
        str.erase(str.begin(), str.begin() + lcnt);
    }
    if(rcnt)
    {
        str.erase(str.end() - rcnt, str.end());
    }
    return lcnt + rcnt;
} // -- END strip


/*
Удаление серий повторяющегося символа ch
Например, "|abc||de|||f||g|||" => "|abc|de|f|g|"
*/
void deleteRepeatSeries(const std::string &src, std::string &dst, char ch)
{
    dst = "";
    bool symbolIncluded = false;
    for(int i = 0; i < src.size(); i++)
    {
        if(src[i] == ch )
        {
            if(!symbolIncluded)
            {
                dst += ch;
                symbolIncluded = true;
            }
        }
        else
        {
            dst += src[i];
            symbolIncluded = false;
        }
    }
}
void deleteRepeatSeries(std::string &s, char ch)
{
    std::string dst = "";
    deleteRepeatSeries(s, dst, ch);
    s = dst;
}

void intParseUsingCharacter(const std::string &src, std::vector<int> &result, char ch)
{
    // Шаг №0 - очистка result
    result.clear();
    // Шаг №1 - очистка от пробелов
    auto work_src = src;
    auto start_ptr = std::remove(work_src.begin(),work_src.end(),' ');
    work_src.erase(start_ptr, work_src.end());

    //Шаг №2 - удаление символа - разделителя с краев
    strip(work_src, ch);
    
    //Шаг №3 - разбиение исх. строки на подстроки и использованием разделителя
    std::vector<std::string> strs;
    split(work_src, strs, ch);
    for (auto s : strs)
    {
        if(s != "")
        {
            result.push_back(std::stoi(s));
        }
    }
}

cv::Scalar parse_BGR_color(const std::string &src, char ch)
{
    std::vector<int> res;
    intParseUsingCharacter(src,res, ch);
    for(int i = 0; i < 3; i++)
    {
        if(res[i] > 255)
            res[i] = 255;
        if(res[i] < 0)
            res[i] = 0;
    }
    return cv::Scalar(res[0], res[1], res[2]);
}


