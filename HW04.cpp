#include <iostream>

#include <cstdlib>

#include <cstring>

using namespace std;



#define MAX_QUEUE_SIZE 100



inline void error(char* str)

{

    cout << str << endl;

    exit(1);

}



class CircularStudent

{

protected:

    int front; //ù ��° ��� ���� ��ġ

    int rear; //������ ��� ��ġ

    char** data;

public:

    CircularStudent()

    {

        front = rear = 0;

        data = new char* [MAX_QUEUE_SIZE];

        for (int i = 0; i < MAX_QUEUE_SIZE; i++)

            data[i] = new char[20];

    }

    ~CircularStudent()

    {

        for (int i = 0; i < MAX_QUEUE_SIZE; i++)

            delete[]data[i];

        delete[]data;

    }

    bool isEmpty()

    {

        return front == rear;

    }

    bool isFull()

    {

        return (rear + 1) % MAX_QUEUE_SIZE == front;

    }

    void enqueue(char* name) //ť�� ����

    {

        if (isFull())

            error("error:ť�� ��ȭ�����Դϴ�\n");

        else

        {

            rear = (rear + 1) % MAX_QUEUE_SIZE;

            strcpy(data[rear], name);

        }

    }

    char* dequeue() //ù �׸��� ť���� ���� ��ȯ

    {

        if (isEmpty())

            error("Error: ť�� ��������Դϴ�\n");

        else

        {

            front = (front + 1) % MAX_QUEUE_SIZE;

            return data[front];

        }

    }

    char* peek() //ù �׸��� ť���� ���� �ʰ� ��ȯ

    {

        if (isEmpty())

            error("Error: ť�� ��������Դϴ�\n");

        else

            return data[(front + 1) % MAX_QUEUE_SIZE];

    }

    void display() //ť�� ��� ������ ������� ���

    {

        cout << "�л� : ";

        if (!isEmpty())

        {

            int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;

            for (int i = front + 1; i <= maxi; i++)

                cout << data[i % MAX_QUEUE_SIZE] << " ";

        }

        else

            cout << "�л��� ���� �����ϴ�";

        cout << endl;

    }

};

int main(void)

{

    CircularStudent male, female; //���� ����

    char name[20];

    char gender; //����

    cout << "���� �ּ� ���α׷��Դϴ�" << endl;

    cout << "���α׷� ���� ���Ͻø� �̸��� '�׸�'�� �Է����ּ���" << endl << endl;

    while (1)

    {

        cout << "���̸�: ";

        cin >> name;

        if (!strcmp(name, "�׸�"))

            break;

        cout << "������ �Է��ϼ���(f or m) ";

        cin >> gender;

        if (gender == 'm')

            male.enqueue(name);

        else if (gender == 'f')

            female.enqueue(name);



        if (!male.isEmpty() && !female.isEmpty()) //���� ���� �ѽ��� �̷� ���

        {

            char boyfriend[20], girlfriend[20];

            strcpy(boyfriend, male.dequeue());

            strcpy(girlfriend, female.dequeue());



            cout << "Ŀ���� ź���߽��ϴ�! " << boyfriend << "�� " << girlfriend << endl << endl;

        }

        else

            cout << "���� ����ڰ� �����ϴ�. ��ٷ��ֽʽÿ�." << endl << endl;

    }

    return 0;

}