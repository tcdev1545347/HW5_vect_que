#include <iostream>
#include <vector>
using namespace std;
// For this homework, you are going to implement an extendable vector based queue that
// uses "jump" trick to save space. 
// Finish function 
//              front() that prints the first element in the queue
//              deque() that dequeues the queue
//           enque(val) that enqueues val to the queue
//              print_vect() that prints out vect_que.
// Demonstrate that your code works in main.
// Refer to class PPT if you forgot all the different cases. 
template <class T>
class vect_queue {
    std::vector<T> vect_que;
    size_t size_;
    int que_front_;
public:

    vect_queue(T val) {
        vect_que.push_back(val);
        size_ = 1;
        que_front_ = 0;
    }

    T front() const {
        return vect_que[que_front_];
    }

    void deque() {
        if (size_ != 1) {
            if (que_front_ + size_ == vect_que.capacity()) {
                que_front_ = 0;
                size_--;
            }
            else {
                que_front_++;
                size_--;
            }
        }
        else {
            cout << "Deque Error." << endl;
        }
    }

    void enque(T val) {
        if (size_ >= vect_que.capacity()) {
            std::vector<T> temp;
            for (int i = que_front_; i < (que_front_ + size_ - 1); i++) {
                temp.push_back(vect_que[i % vect_que.capacity()]);
            }
            que_front_ = 0;
            vect_que.reserve(size_ * 2);
            vect_que = temp;
        }
        if (size_ < vect_que.capacity()) {
            if (((que_front_ + size_) >= vect_que.capacity()) && (que_front_ != 0)) {
                vect_que[(size_ + que_front_ - 1) % vect_que.capacity()] = val;
                size_++;
            }
            else {
                vect_que.push_back(val);
                size_++;
            }
        }
    }


    void print_vect() const {
        for (int i = que_front_; i < (que_front_ + size_ - 1); i++) {
            cout << vect_que[i % vect_que.capacity()] << " ";
        }
        cout << endl;
    }
};
int main()
{
    //Demonstrate your code works by adding/removing values in a vect_que class 
    //object. Print out your result.
    //You should include front index of queue, back index of queue, and the entire
    //vector (not queue) for each case.
  
    //vect_queue<int> tQueue(0);

    //case 1: add to an empty queue
    /*tQueue.enque(1);
    cout << "Add to empty queue: ";
    tQueue.print_vect();*/

    //case 2: add to a non-empty queue without jump
    /*tQueue.enque(2);
    tQueue.enque(3);
    tQueue.enque(4);
    tQueue.enque(5);
    tQueue.enque(6);
    cout << "Add to non-empty Queue without Jump: ";
    tQueue.print_vect();*/

    //case 3: add to a non-empty queue with a jump
    /*vect_queue<int> vQueue(0);
    vQueue.enque(1);
    vQueue.enque(2);
    vQueue.enque(3);
    vQueue.enque(4);
    vQueue.print_vect();
    vQueue.deque();
    vQueue.deque();
    vQueue.enque(5);
    cout << "Adding 5 to non-empty queue with a jump." << endl;
    vQueue.enque(6);
    cout << "Adding 6 to non-empty queue with a jump." << endl;
    vQueue.print_vect();*/
    
    

    //case 4: remove from a queue with number of elements > 1 
    //        and que.front not at vect.back
    /*vect_queue<int> rQueue(0);
    rQueue.enque(1);
    rQueue.enque(2);
    rQueue.enque(3);
    rQueue.enque(4);
    cout << "rQueue: ";
    rQueue.print_vect();
    rQueue.deque();
    cout << "rQueue after deque FRONT: " << rQueue.front();
    cout << endl;*/

    //case 5: remove from a queue with number of elements > 1 
    //        and que.front at vect.back
    /*vect_queue<int> sQueue(0);
    sQueue.enque(1);
    sQueue.enque(2);
    sQueue.enque(3);
    cout << "sQueue: ";
    sQueue.print_vect();

    cout << "sQueue with que.front at vect.back: ";
    sQueue.deque();
    sQueue.deque();
    sQueue.deque();
    sQueue.enque(5);
    sQueue.enque(6);
    sQueue.enque(7);
    sQueue.print_vect();
    sQueue.deque();
    cout << "sQueue after deque FRONT: " << sQueue.front();
    cout << endl;*/

    //case 6: remove from a queue with 1 element in it and que.front 
    //        not at vect[0]
    /*vect_queue<int> wQueue(0);
    cout << "wQueue FRONT: " << wQueue.front();
    cout << endl;
    wQueue.deque();*/

    cout << "\nprogram ends here.\n";
    return 0;
}