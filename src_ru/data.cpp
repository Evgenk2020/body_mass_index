#include "data.h"

const float MaleBase[MAX_GEND_INDEX][MAX_AGE_INDEX] = {
    {11.2, 12.2, 13.4, 14.8, 16.1, 17.1}, //0
    {12.4, 13.6, 15, 16.3, 17.6, 18.6}, //1
    {13.8, 14.9, 16.3, 17.8, 19.2, 20.2}, //2
    {14.4, 15.5, 16.9, 18.2, 19.8, 20.8}, //3
    {14.6, 15.8, 17.2, 18.7, 20.1, 21.1}, //4
    {14.8, 15.9, 17.3, 18.8, 20.2, 21.2}, //5
    {14.9, 15.9, 17.4, 18.9, 20.3, 21.3}, //6
    {14.9, 15.9, 17.3, 18.8, 20.2, 21.2}, //7
    {14.8, 15.9, 17.2, 18.8, 20.2, 21.2}, //8
    {14.8, 15.8, 17.2, 18.7, 20.1, 21.1}, //9
    {14.7, 15.7, 17, 18.6, 19.9, 20.9}, //10
    {14.6, 15.6, 16.9, 18.2, 19.8, 20.8}, //11
    {14.5, 15.5, 16.8, 18.3, 19.6, 20.6}, //12
    {14.2, 15.2, 16.4, 17.9, 19.2, 20.2}, //13
    {14, 14.9, 16.2, 17.5, 18.8, 19.8}, //14
    {13.8, 14.7, 15.9, 17.2, 18.6, 19.6}, //15
    {13.9, 14.8, 16, 17.4, 18.6, 19.6}, //16
    {13.7, 14.6, 15.8, 17.2, 18.4, 19.4}, //17
    {13.5, 14.4, 15.6, 17, 18.2, 19.2}, //18
    {13.3, 14.2, 15.4, 16.8, 18, 19}, //19
    {13.2, 14.1, 15.4, 16.8, 18, 19}, //20
    {13.1, 14, 15.2, 16.7, 18, 19}, //21
    {13, 13.9, 15.2, 16.6, 18.1, 19.1}, //22
    {13.1, 14, 15.3, 16.7, 18.2, 20.8}, //23
    {13.2, 14.1, 15.5, 17, 18.8, 21.9}, //24
    {13.5, 14.2, 15.8, 17.5, 19.2, 23.1}, //25
    {13.5, 14.5, 16, 18, 20.1, 24.6}, //26
    {13.9, 14.9, 16.5, 18.5, 21, 26.5}, //27
    {14.1, 15.1, 17, 19.2, 22, 28.5}, //28
    {14.6, 15.7, 17.5, 20, 23, 30.8}, //29
    {15, 16.3, 18.2, 20.9, 24.2, 32.5}, //30
    {15.6, 17, 19, 21.9, 25.3, 34}, //31
    {16.2, 17.6, 19.8, 22.8, 26.4, 35}, //32
    {16.6, 18.1, 20.5, 23.6, 27.2, 35.5}, //33
    {17, 18.6, 21.1, 24.4, 28, 36}, //34
    {17.5, 19.1, 21.8, 25, 28.6, 36.1}, //35
    {17.9, 19.5, 22.1, 25.5, 29.1, 36.1}, //36
    {16, 18.5, 25, 30, 35, 40} //37
};

const float FemaleBase[MAX_GEND_INDEX][MAX_AGE_INDEX] = {
    {11.2, 12.1, 13.3, 14.6, 15.8, 16.8}, //0
    {12, 13.1, 14.6, 16, 17.3, 18.3}, //1
    {13.2, 14.3, 15.8, 17.4, 18.8, 19.8}, //2
    {13.7, 14.8, 16.4, 18, 19.4, 20.4}, //3
    {14, 15.2, 16.7, 18.3, 19.8, 20.8}, //4
    {14.2, 15.3, 16.8, 18.5, 20, 21}, //5
    {14.3, 15.4, 16.9, 18.6, 20.1, 21.1}, //6
    {14.3, 15.4, 16.9, 18.6, 20.1, 21.1}, //7
    {14.3, 15.4, 16.8, 18.5, 20, 21}, //8
    {14.2, 15.3, 16.7, 18.4, 19.9, 20.9}, //9
    {14.1, 15.2, 16.6, 18.2, 19.7, 20.7}, //10
    {14, 15.1, 16.5, 18.1, 19.6, 20.6}, //11
    {13.9, 14.9, 16.4, 17.9, 19.4, 20.4}, //12
    {13.7, 14.8, 16, 17.7, 19, 20}, //13
    {13.4, 14.4, 15.7, 17.2, 18.6, 19.6}, //14
    {13.3, 14.2, 15.5, 17, 18.4, 19.4}, //15
    {13.4, 14.4, 15.7, 17.2, 18.5, 19.5}, //16
    {13.3, 14.2, 15.5, 17, 18.3, 19.3}, //17
    {13.2, 14.1, 15.2, 16.8, 18.2, 19.2}, //18
    {13.1, 14, 15.3, 16.8, 18.2, 19.2}, //19
    {12.9, 13.9, 15.2, 16.8, 18.3, 19.3}, //20
    {12.8, 13.8, 15.2, 16.9, 18.4, 19.4}, //21
    {12.8, 13.8, 15.2, 17, 18.6, 19.6}, //22
    {12.9, 13.9, 15.3, 17, 19, 22.5}, //23
    {12.9, 14, 15.5, 17.9, 19.5, 23.7}, //24
    {13, 14, 15.7, 17.8, 20.1, 25.2}, //25
    {13.3, 14.5, 16.1, 18.5, 21, 27}, //26
    {13.6, 14.7, 16.6, 19.1, 22, 29}, //27
    {14, 15.3, 17.3, 18, 23.1, 31}, //28
    {14.5, 16, 18, 19, 24.4, 32.7}, //29
    {15.1, 16.5, 18.8, 22, 25.5, 34.4}, //30
    {15.6, 17.1, 19.5, 22.9, 26.6, 35.5}, //31
    {16, 17.7, 20.2, 23.6, 27.5, 36.4}, //32
    {16.4, 18, 20.6, 24.2, 28.1, 36.9}, //33
    {16.6, 18.4, 21, 24.6, 28.6, 37}, //34
    {16.6, 18.5, 21.2, 25, 28.9, 37}, //35
    {16.7, 18.6, 23.5, 25.1, 29, 36.9}, //36
    {15.5, 18, 24.5, 29.5, 34.5, 39.5}, //37
};

const std::string Human_Ages_Name[MAX_GEND_INDEX] = {
    "новорожденный", //0
    "1 месяц", //1
    "2 месяца", //2
    "3 месяца", //3
    "4 месяца", //4
    "5 месяцев", //5
    "6 месяцев", //6
    "7 месяцев", //7
    "8 месяцев", //8
    "9 месяцев", //9
    "10 месяцев", //10
    "11 месяцев", //11
    "1 год", //12
    "1 год 3 месяца", //13
    "1 год 6 месяцев", //14
    "1 год 9 месяцев", //15
    "2 года", //16
    "2 года 6 месяцев", //17
    "3 года", //18
    "3 года 6 месяцев", //19
    "4 года", //20
    "4 года 6 месяцев", //21
    "5 лет", //22
    "6 лет", //23
    "7 лет", //24
    "8 лет", //25
    "9 лет", //26
    "10 лет", //27
    "11 лет", //28
    "12 лет", //29
    "13 лет", //30
    "14 лет", //31
    "15 лет", //32
    "16 лет", //33
    "17 лет", //34
    "18 лет", //35
    "19 лет", //36
    "взрослый" //37
};

const std::string Human_Gender_Name[MAX_HUM_GENDER] = {
    "мужской",
    "женский"
};

const std::string Human_Results_Name[MAX_RESULT] = {
    "Выраженный дефицит массы тела составляет: ", //0
    "Недостаточная масса тела составляет: ", //1
    "Масса тела в пределах нормы", //2
    "Избыточная масса тела составляет: ", //3
    "Ожирение составляет: ", //4
    "Ожирение резкое составляет: ", //5
    "Очень резкое ожирение составляет: " //6
};
