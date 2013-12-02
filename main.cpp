#include <QCoreApplication>
#include <QTextStream>
#include <QFile>
#include <QDebug>
#include <iostream>
//#include <fstream>
//#include <cstdlib>
using namespace std;

bool writeToFile(const QString &filename, const QString &fileContent);

int main(int argc, char *argv[])
{
    if (argc != 3) {
        cerr << "Program take 2 parameters: Send2Device <device> <message>\n";
        return -1;
    }

    if (writeToFile((QString) argv[1], (QString) argv[2])) {
        cout << "Message " << argv[2] << " to " << argv[1] << " sended\n";
        return 0;
    } else {
        cerr << "Failed to open device file\n";
        return -1;
    }
}

bool writeToFile(const QString &filename, const QString &fileContent)
{
    QFile gpioFile(filename);
    if (gpioFile.open(QIODevice::WriteOnly)) {
        QTextStream gpioStream(&gpioFile);
        gpioStream << fileContent;
        gpioFile.close();
        return true;
    } else {
        return false;
    }
}
