#include <iostream>
#include <string>
#include "logic.hpp"

using namespace std;

int main()
{
    class Graph* graphs;
    class Graph* previosRoot;
    string answer;

    cout << "�� ������� ������� ��������� ������ ����('y' - ��, 'n' - ���):" << endl;
    cin >> answer; 

    if (answer == "y")
    {
        class Graph* graphs = new Graph;
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
                graphs->addGraph();
                break;
            }
            case 3:
            {   
                graphs->insertGraph();
                break;
            }
            case 4:
            {
                graphs->removeGraph(graphs->root);
                cout << "---------------------------------------------------------------" << endl;
                cout << "|        ��������� �������� � ����� {{"<< graphs->root <<"}}             |" << endl;
                cout << "---------------------------------------------------------------" << endl;
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
    
    return 0;
}