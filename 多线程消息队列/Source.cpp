#include <iostream>
#include <queue>
#include <mutex>
#include <thread>
#include <string>

using namespace std;

std::queue<std::string> messageQueue; // ��Ϣ����
std::mutex mtx; // ���������ڱ�����Ϣ����

// �������̺߳���������Ϣ�����������Ϣ
void producerThread() {
    for (int i = 0; i < 5; ++i) {
        std::this_thread::sleep_for(std::chrono::seconds(1)); // ģ���ʱ����
        std::lock_guard<std::mutex> guard(mtx);
        messageQueue.push("Message " + to_string(i));
    }
}

// �������̺߳���������Ϣ�����ж�ȡ��Ϣ
void consumerThread() {
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1)); // ģ���ʱ����
        std::lock_guard<std::mutex> guard(mtx);
        if (!messageQueue.empty()) {
            std::cout << "Received: " << messageQueue.front() << std::endl;
            messageQueue.pop();
        }
    }
}

int main() {
    std::thread producer(producerThread);
    std::thread consumer(consumerThread);

    producer.join();
    consumer.join();

    return 0;
}
