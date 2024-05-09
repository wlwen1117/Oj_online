#include <iostream>
#include <queue>
#include <mutex>
#include <thread>
#include <string>

using namespace std;

std::queue<std::string> messageQueue; // 消息队列
std::mutex mtx; // 互斥量用于保护消息队列

// 生产者线程函数，向消息队列中添加消息
void producerThread() {
    for (int i = 0; i < 5; ++i) {
        std::this_thread::sleep_for(std::chrono::seconds(1)); // 模拟耗时操作
        std::lock_guard<std::mutex> guard(mtx);
        messageQueue.push("Message " + to_string(i));
    }
}

// 消费者线程函数，从消息队列中读取消息
void consumerThread() {
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1)); // 模拟耗时操作
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
