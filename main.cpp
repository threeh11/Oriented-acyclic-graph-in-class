#include <iostream>
#include <string>
#include "logic.hpp"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    class Graph* graphs;
    string answer;

    cout << "�� ������� ������� ��������� ������ ����('y' - ��, 'n' - ���):" << endl;
    cin >> answer; 

    if (answer == "y")
    {
        class Graph* graphs = new Graph;

        int tool = getTools();
        while (tool != 8)
        {    
            switch (tool)
            {
                case 1:
                {
                    int count = graphs->amount(graphs->start);
                    cout << "---------------------------------------------------------------" << endl;
                    cout << "|       ���������� ������ � ��������� ������ = "<< count <<"              |" << endl;
                    cout << "---------------------------------------------------------------" << endl;
                    break;
                }
                case 2:
                {
                    graphs->addGraphToStart();
                    break;
                }
                case 3:
                {   
                    graphs->addGraphToRoot();
                    break;
                }
                case 4:
                {
                    class Node* deletedRoot = graphs->root;
                    graphs->removeGraph(graphs->root);
                    cout << "---------------------------------------------------------------" << endl;
                    cout << "|        ��������� �������� � ����� {{"<< graphs->root <<"}}             |" << endl;
                    cout << "---------------------------------------------------------------" << endl;
                    graphs->clearPointers(deletedRoot);
                    graphs->root = graphs->before;
                    break;
                }
                case 5:
                {
                    graphs->clearGraphs(graphs->start);
                    cout << "---------------------------------------------------------------" << endl;
                    cout << "|            ��������� �������� ��������� ������              |" << endl;
                    cout << "---------------------------------------------------------------" << endl;
                    exit(0);
                    break;
                }
                case 6:
                {
                    graphs->before = graphs->root;
                    graphs->changePosition();
                    break;
                }
                case 7:
                {
                    graphs->getValue();
                    break;
                }
            }
            tool = getTools();
        }
    }
    else if (answer == "n")
    {
        exit(0);
    }
    else
    {
        cout << "�� ��������� ������� ������!" << endl;
        exit(0);   
    }
    
    return 0;
}