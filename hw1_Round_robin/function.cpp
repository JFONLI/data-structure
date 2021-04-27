#include "function.h"

template<class T>
Queue<T>::Queue()
{
    front = -1;
    rear = -1;
    capacity = 1;
    size = 0;
    Data = new T[capacity];
}
template<class T>
Queue<T>::Queue(const Queue<T> &q)
{
    front = q.front;
    rear  = q.rear;
    capacity = q.capacity;
    size = q.size;
    Data = new T[capacity];
	for ( int i = 0 ; i < capacity ; i++)
		Data[i] = q.Data[i];
}

template<class T>
Queue<T>::~Queue(){}

template<class T>
bool Queue<T>::IsEmpty()
{
    if (size==0)
    {
        return true;
    }
    else
        return false;
}

template<class T>
T& Queue<T>::Front()
{
    if (!IsEmpty()) return Data[(front+1)%capacity];
}

template<class T>
T& Queue<T>::Rear()
{
    if (!IsEmpty()) return Data[(rear)];
}

template<class T>
void Queue<T>::Push(const T &item)
{
    if (capacity-1<=size)
    {
        T *newQueue = new T [capacity*2];

        int j=-1;
        for (int i=(front+1)%capacity; i != (rear+1)%capacity; i = (i+1)%capacity){
            j++;
            newQueue[j]=Data[i];
        }
        capacity *= 2;
        front = -1;
        rear = j;
        //size++;

        delete [] Data;
        Data = newQueue;
    }
        rear = (rear+1)%capacity;
        size++;
        Data [rear] = item;
        //cout<<rear<<endl;
        //cout<<front<<endl;
        //cout << "PUSH" << endl;
        //cout << "Capacity: " << capacity<< endl;
        //cout << "Size: " << size << endl;
}

template<class T>
void Queue<T>::Pop()
{
    Data[front].~T();
    front = (front+1)%capacity;
    size = size -1;
    //cout << "POP" << endl;
    //cout << "Capacity: " << capacity <<endl;
    //cout << "Size: " << size << endl;
}

void scheduler(Queue<process>& q,int n)
{

    Queue<process> ready_queue;
    int tq=3;    //timequantuam
    int time=0;  //time
    struct process temp;
    while(!ready_queue.IsEmpty() || !q.IsEmpty())
    {
        //cout << "Time: "<< time << endl;
        //cout << "TQ: " << tq << endl;
        while(!q.IsEmpty() && q.Front().arrival_time == time)
        {
            temp.process_id = q.Front().process_id;
            temp.arrival_time = q.Front().arrival_time;
            temp.require_time = q.Front().require_time;
            ready_queue.Push(temp);
            q.Pop();
        }

        //cout<<"Wonderful"<<endl;
        if (!ready_queue.IsEmpty())
        {
            tq--;
            ready_queue.Front().require_time--;
            //cout << "RT: " << ready_queue.Front().require_time << endl;
            if (ready_queue.Front().require_time == 0)
            {
                cout <<  ready_queue.Front().process_id ;
                ready_queue.Pop();
                tq=3;
                if (q.IsEmpty() && ready_queue.IsEmpty())
                {
                    cout << "";
                }
                else
                {
                    cout<< ",";
                }
            }
            else
            {
                if (tq==0)
                {
                    tq=3;
                    temp.process_id = ready_queue.Front().process_id;
                    temp.arrival_time = ready_queue.Front().arrival_time;
                    temp.require_time = ready_queue.Front().require_time;
                    ready_queue.Push(temp);
                    ready_queue.Pop();
                }

            }
        }
        time = time+1;
    }
    cout << endl;
    return;
}





