#include "InterfejsDrona.hh"

bool kbhit()
{
    termios term;
    tcgetattr(0, &term);

    termios term2 = term;
    term2.c_lflag &= ~ICANON;
    tcsetattr(0, TCSANOW, &term2);

    int byteswaiting;
    ioctl(0, FIONREAD, &byteswaiting);

    tcsetattr(0, TCSANOW, &term);

    return byteswaiting > 0;
}

//enum opcje{PRZOD=0,TYL,PRAWO,LEWO};

char InterfejsDrona::Input()
{
    char key;
    if(kbhit())
    {
        key=getchar();
        switch (key)
        {//=============================
        case 'w':
        {
            if(Tyl==1)
                Tyl=0;
            else
                Przod=1;
                      
            break;
        }//=============================
        case 's':
        {
            if(Przod==1)
                Przod=0;
            else
                Tyl=1;
            
            break;
        }//=============================
        case 'a':
        {
            Lewo=1;
            
            break;
        }//=============================
        case 'd':
        {
            Prawo=1;
            
            break;
        }//=============================
        case '=':
        {
            if(Zanurz==1)
                Zanurz=0;
            else
                Wynurz=1;
            
            break;
        }//=============================
        case '-':
        {
            if(Wynurz==1)
                Wynurz=0;
            else
                Zanurz=1;
            
            break;
        }//=============================
        default:
            break;
        }
        return key;
    }
    return '0';
}
