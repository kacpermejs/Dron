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



char InterfejsDrona::Input()
{
    char key;
    
    if(kbhit())
    {
        key=getchar();

        switch (key)
        {
        case 'p':
            std::cout << "Podaj odleglosc:\n";
            std::cin >> m_odleglosc;
            std::cout << "Podaj kat:\n";
            std::cin >> m_katY;
            Plynie=1;
            break;
        
        case 'o':
            std::cout << "Podaj kat obrotu:\n";
            std::cin >> m_katZ;
            Skreca=1;
            break;
        
        default:
            break;
        }
        
        return key;
    }
    return '0';
}

void InterfejsDrona::UI()
{
    std::cout << "Dostepne opcje:\n"
                << "\t 'p' - plyn\n"
                << "\t 'o' - obroc\n";

    std::cout << "aktualne zadanie:\n";
    if(Plynie)
        std::cout << "\tplynie, odleglosc:" << m_odleglosc << " pod katem " << m_katY << "\n";
    else if(Skreca)
        std::cout << "\tskreca, kat:" << m_katZ << "\n";
    else
        std::cout << "stoi\n";

}