#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
    string typeAnimal;
    string race;
    string name;
    string mainColor;
    string gender;
    
    class Node* pointers[10];
    friend class Graph;
};

class Graph
{
    public:
    class Node* created;
    class Node* start;
    class Node* root;
    class Node* before;

    Graph(){
        created = new Node;
        cout << "---------------------------------------------------------------" << endl;
        cout << "|                     ��������� ����...                       |" << endl;
        cout << "---------------------------------------------------------------" << endl;

        string answer[5];

        cout << "������� ��� ��������� ���������: ";
        cin >> answer[0];
        cout << "������� ������ ��������� ���������: ";
        cin >> answer[1];
        cout << "������� ��� ��������� ���������: ";
        cin >> answer[2];
        cout << "������� ������������� ���� ��������� ���������: ";
        cin >> answer[3];
        cout << "������� ��� ��������� ���������: ";
        cin >> answer[4];

        created->typeAnimal = answer[0];
        created->race = answer[1];
        created->name = answer[2];
        created->mainColor = answer[3];
        created->gender = answer[4];

        for (int i = 0; i < 10; i++)
        {
            created->pointers[i] = NULL;
        }
        start, root, before = created;
    };

    void fillGraph(class Node* graph);
    int amount(class Node* graph);
    void addGraph();
    void insertGraph();
    void removeGraph(class Node* node);
    void clearGraphs(class Node* node);
    void changePosition();
    void getValue();
    void insert(struct Node* root, struct Node* child);

    ~Graph()
    {
        clearGraphs(this->start);
    };

};

void Graph :: fillGraph(class Node* node)
{
    cout << "---------------------------------------------------------------" << endl;
    cout << "|                     ��������� ����...                       |" << endl;
    cout << "---------------------------------------------------------------" << endl;

    string answer[5];

    cout << "������� ��� ��������� ���������: ";
    cin >> answer[0];
    cout << "������� ������ ��������� ���������: ";
    cin >> answer[1];
    cout << "������� ��� ��������� ���������: ";
    cin >> answer[2];
    cout << "������� ������������� ���� ��������� ���������: ";
    cin >> answer[3];
    cout << "������� ��� ��������� ���������: ";
    cin >> answer[4];

    node->typeAnimal = answer[0];
    node->race = answer[1];
    node->name = answer[2];
    node->mainColor = answer[3];
    node->gender = answer[4];

    for (int i = 0; i < 10; i++)
    {
        node->pointers[i] = NULL;
    }

}

int Graph :: amount(class Node* graph)
{
    int count = 0;

    if (graph == NULL)
    {
        return 0;
    }
    else if (graph != NULL)
    {
        count++;
    }
    for (int i = 0; i < 10; i++)
    {
        count += amount(graph->pointers[i]);
    }
    return count;
}

void Graph :: addGraph()
{
    class Node* fresh = new Node;
    this->fillGraph(fresh);

    for (int i = 0; i < 10; i++)
    {
        if (this->root->pointers[i] == NULL)
        {
            this->root->pointers[i] = fresh;
            break;
        }
        if (i == 9)
        {
            cout << "���������� �� �������� ���������� ������������ ���������� �������� ������!" << endl;    
        }
    }
}

void Graph :: getValue()
{
    cout << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << "                      {{" << this->root << "}}" << endl;
    cout << "��� ��������� ���������: " << this->root->typeAnimal << endl;
    cout << "������ ��������� ���������: " << this->root->race << endl;
    cout << "��� ��������� ���������: "  << this->root->name << endl;
    cout << "������������� ���� ��������� ���������: " << this->root->mainColor << endl;
    cout << "��� ��������� ���������: " << this->root->gender << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << endl;
}

void Graph :: changePosition()
{   
    cout << "---------------------------------------------------------------" << endl;
    cout << "          �� ���������� � {{" << this->root << "}} �����."       << endl;
    cout << "---------------------------------------------------------------" << endl;

    int countChildren = 0;

    while (this->root->pointers[countChildren] != NULL)
    {
        countChildren++;
    }

    if (countChildren == 0)
    {
        cout << "---------------------------------------------------------------" << endl;
        cout << "       � ����� ��� �������� ��������� ������� �� ��������!"      << endl;
        cout << "---------------------------------------------------------------" << endl;
    }
    else if (countChildren == 1)
    {
        cout << "� ����� 1 �������� �������, ������� � ����('y' - ��, 'n' - ���):" << endl;
        string answer;
        cin >> answer;
        if (answer == "y") 
        {
            this->root = this->root->pointers[0];
            cout << "---------------------------------------------------------------" << endl;
            cout << "                    �� ������� �������� ����!" << endl;
            cout << "---------------------------------------------------------------" << endl;
            countChildren = 0;
        }
        else if (answer == "n")
        {
            cout << "�� ���, ��� ���";
        }
        else
        {
            cout << "������� �� ���������� ��������!" << endl;
        }
    }
    else
    {
        int answer = 0;
        cout << "---------------------------------------------------------------" << endl;
        cout << "�������� ���� � �������� ������ �������, ����� �������� ������ = " << countChildren << endl;
        cout << "---------------------------------------------------------------" << endl;

        cout << "---------------------------------------------------------------" << endl;
        for (int i = 0; i < countChildren; i++)
        {
            cout << i+1 << ")" << root->pointers[i] << endl;
        }
        cout << "---------------------------------------------------------------" << endl;
        cout << "�������� ����: ";
        cin >> answer;
        
        if (answer > 0 && answer <= countChildren)
        {
            cout << "---------------------------------------------------------------" << endl;
            cout << "               �� ������� �������� ����!" << endl;
            cout << "---------------------------------------------------------------" << endl;
            this->root = this->root->pointers[answer-1];
            countChildren = 0;
        }
        else
        {
            answer = 0;
            cout << "������� �� ���������� ��������" << endl;
            changePosition();
        }
    }
}

void Graph :: removeGraph(class Node* node)
{
    if (node != NULL)
    {
        for (int i = 0; i < 10; i++)
        {
            removeGraph(node->pointers[i]);
        }
    }
    delete node;
}

void Graph :: clearGraphs(class Node* node)
{
    if (node != NULL)
        {
            for (int i = 0; i < 10; i++)
            {
                clearGraphs(node->pointers[i]);
            }
    }
    delete node;
}

void Graph :: insert(struct Node* root, struct Node* child)
{
    root->typeAnimal = child->typeAnimal;
    root->race = child->race;
    root->name = child->name;
    root->mainColor = child->mainColor;
    root->gender = child->gender;
}

void Graph :: insertGraph()
{
    int countChildren = 0;
    for (int i = 0; i < 10; i++)
    {
        if (this->root->pointers[i] != NULL)
        {
            countChildren++;
        }
    }
    if (countChildren == 0)
    {
        cout << "---------------------------------------------------------------" << endl;
        cout << "      � ����� ��� �������� ��������� ������� ����������!" << endl;
        cout << "---------------------------------------------------------------" << endl;
    }
    else if (countChildren == 1)
    {
        cout << "� ����� ���� �������� ������� ��������� �������('y' - ��, 'n' - ���)?" << endl;
        string answer;
        cin >> answer;
        if (answer == "y")
        {
            insert(this->root, this->root->pointers[0]);
        }
        else if (answer == "n") 
        {
            cout << "�� ���, ��� ���" << endl;
        }
        else 
        {
            cout << "�� ��������� ��������� ������" << endl;
        }
    }
    else if (countChildren > 1)
    {
        cout << "---------------------------------------------------------------" << endl;
        cout << "       � ����� " << countChildren << "�������� ���������   ";
        cout << "---------------------------------------------------------------" << endl;

        cout << "---------------------------------------------------------------" << endl;
        for (int i = 0; i < countChildren; i++)
        {
            cout << i+1 << ")" << root->pointers[i] << endl;
        }
        cout << "---------------------------------------------------------------" << endl;
        cout << "�������� ����: ";
        int answer = 0;
        cin >> answer;
        insert(root, root->pointers[answer-1]);
    }
}

void printTools()
{
    cout << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << "|                         ����                                |" << endl;
    cout << "| 1)��������� ���������� ��������� � ��������� ������         |" << endl;
    cout << "| 2)���������� �������� � ��������� ������                    |" << endl;
    cout << "| 3)������� ��������� �������� ��� �������� ��������          |" << endl;
    cout << "| 4)�������� �������� �������� ��������� ������               |" << endl;
    cout << "| 5)������� ��������� ������                                  |" << endl;
    cout << "| 6)����������� �� ��������� ��������� ������                 |" << endl;
    cout << "| 7)������ ���������� �� �������� �������� ��������� ������   |" << endl;
    cout << "| 8)�����                                                     |" << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << endl;
}

int getTools()
{
    printTools();
    int numberTool = 0;
    cout << "������� �����: ";
    cin >> numberTool;
    return numberTool;
}
