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
        cout << "|                     Заполняем граф...                       |" << endl;
        cout << "---------------------------------------------------------------" << endl;

        string answer[5];

        cout << "Введите тип домашнего животного: ";
        cin >> answer[0];
        cout << "Введите породу домашнего животного: ";
        cin >> answer[1];
        cout << "Введите имя домашнего животного: ";
        cin >> answer[2];
        cout << "Введите преоблодающий цвет домашнего животного: ";
        cin >> answer[3];
        cout << "Введите пол домашнего животного: ";
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
    cout << "|                     Заполняем граф...                       |" << endl;
    cout << "---------------------------------------------------------------" << endl;

    string answer[5];

    cout << "Введите тип домашнего животного: ";
    cin >> answer[0];
    cout << "Введите породу домашнего животного: ";
    cin >> answer[1];
    cout << "Введите имя домашнего животного: ";
    cin >> answer[2];
    cout << "Введите преоблодающий цвет домашнего животного: ";
    cin >> answer[3];
    cout << "Введите пол домашнего животного: ";
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
            cout << "Добавление не возможно достигнуто максимальное количество дочерних графов!" << endl;    
        }
    }
}

void Graph :: getValue()
{
    cout << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << "                      {{" << this->root << "}}" << endl;
    cout << "Тип домашнего животного: " << this->root->typeAnimal << endl;
    cout << "Порода домашнего животного: " << this->root->race << endl;
    cout << "Имя домашнего животного: "  << this->root->name << endl;
    cout << "Преоблодающий цвет домашнего животного: " << this->root->mainColor << endl;
    cout << "Пол домашнего животного: " << this->root->gender << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << endl;
}

void Graph :: changePosition()
{   
    cout << "---------------------------------------------------------------" << endl;
    cout << "          Вы находитесь в {{" << this->root << "}} графе."       << endl;
    cout << "---------------------------------------------------------------" << endl;

    int countChildren = 0;

    while (this->root->pointers[countChildren] != NULL)
    {
        countChildren++;
    }

    if (countChildren == 0)
    {
        cout << "---------------------------------------------------------------" << endl;
        cout << "       У графа нет дочерних элементов переход не возможен!"      << endl;
        cout << "---------------------------------------------------------------" << endl;
    }
    else if (countChildren == 1)
    {
        cout << "У графа 1 дочерний элемент, перейти к нему('y' - да, 'n' - нет):" << endl;
        string answer;
        cin >> answer;
        if (answer == "y") 
        {
            this->root = this->root->pointers[0];
            cout << "---------------------------------------------------------------" << endl;
            cout << "                    Вы успешно поменяли граф!" << endl;
            cout << "---------------------------------------------------------------" << endl;
            countChildren = 0;
        }
        else if (answer == "n")
        {
            cout << "Ну нет, так нет";
        }
        else
        {
            cout << "Введено не корректное значение!" << endl;
        }
    }
    else
    {
        int answer = 0;
        cout << "---------------------------------------------------------------" << endl;
        cout << "Выберите Граф к которому хотите перейти, всего дочерних графов = " << countChildren << endl;
        cout << "---------------------------------------------------------------" << endl;

        cout << "---------------------------------------------------------------" << endl;
        for (int i = 0; i < countChildren; i++)
        {
            cout << i+1 << ")" << root->pointers[i] << endl;
        }
        cout << "---------------------------------------------------------------" << endl;
        cout << "Выберите граф: ";
        cin >> answer;
        
        if (answer > 0 && answer <= countChildren)
        {
            cout << "---------------------------------------------------------------" << endl;
            cout << "               Вы успешно поменяли граф!" << endl;
            cout << "---------------------------------------------------------------" << endl;
            this->root = this->root->pointers[answer-1];
            countChildren = 0;
        }
        else
        {
            answer = 0;
            cout << "Введено не корректное значение" << endl;
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
        cout << "      У графа нет дочерних элементов вставка невозможна!" << endl;
        cout << "---------------------------------------------------------------" << endl;
    }
    else if (countChildren == 1)
    {
        cout << "У графа один дочерний элемент выполнить вставку('y' - да, 'n' - нет)?" << endl;
        string answer;
        cin >> answer;
        if (answer == "y")
        {
            insert(this->root, this->root->pointers[0]);
        }
        else if (answer == "n") 
        {
            cout << "Ну нет, дак нет" << endl;
        }
        else 
        {
            cout << "Не корректно введенные данные" << endl;
        }
    }
    else if (countChildren > 1)
    {
        cout << "---------------------------------------------------------------" << endl;
        cout << "       У графа " << countChildren << "дочерних элементов   ";
        cout << "---------------------------------------------------------------" << endl;

        cout << "---------------------------------------------------------------" << endl;
        for (int i = 0; i < countChildren; i++)
        {
            cout << i+1 << ")" << root->pointers[i] << endl;
        }
        cout << "---------------------------------------------------------------" << endl;
        cout << "Выберите граф: ";
        int answer = 0;
        cin >> answer;
        insert(root, root->pointers[answer-1]);
    }
}

void printTools()
{
    cout << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << "|                         МЕНЮ                                |" << endl;
    cout << "| 1)Получение количества элементов в структуре данных         |" << endl;
    cout << "| 2)Добавление элемента в структуру данных                    |" << endl;
    cout << "| 3)Вставка дочернего элемента для текущего элемента          |" << endl;
    cout << "| 4)Удаление текущего элемента структуры данных               |" << endl;
    cout << "| 5)Очистка структуры данных                                  |" << endl;
    cout << "| 6)Перемещение по элементам структуры данных                 |" << endl;
    cout << "| 7)Чтение информации из текущего элемента структуры данных   |" << endl;
    cout << "| 8)Выйти                                                     |" << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << endl;
}

int getTools()
{
    printTools();
    int numberTool = 0;
    cout << "Введите цифру: ";
    cin >> numberTool;
    return numberTool;
}
