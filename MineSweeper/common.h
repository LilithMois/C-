#ifndef COMMON_H
#define COMMON_H

class Common{

public:
    enum gameLeve
    {
     LOWLEVE = 0,
     MIDDLELEVE = 1,
     HEIGHTLEVE = 2,
     CUSOMLEVE = 3
    };

    enum lowset
    {
        LOWROWANDCOL = 9,
        LOWMINENUM = 10
    };

    enum middleset
    {
        MIDDLEROWANDCOL = 16,
        MIDDLEMINENUM = 40
    };

    enum heightset
    {
        HEIGHTROW = 16,
        HEIGHTCOL = 30,
        HEIGHTMINENUM = 99
    };

    enum mapset
    {
        MAPWIDYH = 25,
        MAPHEIGHT = 25
    };
    enum sound
    {
        soundon = true,
        soundoff = false
    };
};
#endif // COMMON_H
