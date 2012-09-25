
// Own
#include <utils.hpp>
#include <Iteraction.hpp>

// C
#include <cstdio>
#include <cstdlib>
#include <cstring>

// STL
#include <list>
#include <string>
#include <fstream>

typedef std::list<Iteraction> ItList;
typedef std::list<std::string> StringList;

char * szAppName = NULL;

void usage();
void readData(const char * szFilePath, ItList &itList);

int main(int argc, char **argv)
{
    szAppName = argv[0];
    ItList itList;

    if(argc == 1)
    {
        std::perror("Argumentos inválidos");
        usage();

        exit(EXIT_FAILURE);
    }

    for(int i = 1; i < argc; i++)
    {
        if(strcmp(argv[i], "--help") == 0)
        {
            usage();

            exit(EXIT_SUCCESS);
        }
        else
            readData(argv[i], itList);
    }

    hline();

    return 0;
}

void usage()
{
    std::printf("uso:\t%s [opciones] archivo...\n", szAppName);
    std::printf("Opciones:\n");
    std::printf("  --help\tMostrar ayuda.\n");
}

void readData(const char * szFilePath, ItList &itList)
{
    std::ifstream infile;
    infile.open(szFilePath, std::ifstream::in);

    if(infile.is_open())
    {
        int n;
        infile >> n;

        while(0 < n--)
        {
            Iteraction it;
            infile >> it;
            itList.push_back(it);
        }
    }

    infile.close();
}
