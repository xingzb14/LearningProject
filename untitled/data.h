#ifndef DATA
#define DATA
typedef struct wordInfo         //生词学习信息
{
    int sum;
    int right;
    int remove;
    int wrong;
}INFO;

typedef struct Normal           //单词信息
{
    QString spell;
    QString translation;
    QString label;
    QString englishMeaning;
    QString example;
    QString exampleMeaning;
}WORD;
//WORD list[3] = {{"no", "no", "no", "no", "no", "no"},
//               {"yes", "yes", "yes", "yes", "yes", "yes"},
//               {"he", "he", "he", "he", "he", "he"}};

typedef struct PH               //短语信息
{
    QString spell;
    QString meaning;
}PHRASE;

enum BOOK
{
    DAILY,
    HIGHSCHOOL,
    CET_4,
    CET_6,
    TOEFL,
    IELTS,
    GRE,
    MORE
};

#endif // DATA

