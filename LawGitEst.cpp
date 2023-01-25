#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <list>
#include "Act.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    std::string READ_FILE{ "read.csv" };
    std::string WRITE_FILE{ "write.csv" };

    Act fiction("УК РК;385;Подделка документов;Штраф 2000 МРП / КПЗ 2 года;");
    fiction.manual_list(fiction);
    
    Act evasion("УК РК; 245; Уклонения от уплаты налогов; Штраф 2000 МРП / КПЗ 3 года с ЧС;");
    fiction.manual_list(evasion);

    fiction.Act_file(READ_FILE);
    fiction.list_show();
    fiction.write(WRITE_FILE);

    return 0;
}