#include <iostream>
#include <thread>

#include "SampleDataClient.h"

void doWork(SampleDataClient &client) {}

void senderThread() {
  SampleDataClient client;
  client.initialize();

  int index = 0;

  while (1) {
    std::string input;
    std::string output;
    std::getline(std::cin, input);

    client.setData(index, input);
    client.getData(index, output);

    std::cout << __FUNCTION__ << " getData() index:" << index
              << ", input:" << input << ", output:" << output << std::endl;

    ++index;
    index = index % 3;
  }
}

int main(int argc, char *argv[]) {
  std::cout << __FUNCTION__ << "() start" << std::endl;
  Glib::init();
  Gio::init();

  std::thread thread(senderThread);

  Glib::RefPtr<Glib::MainLoop> mainLoop = Glib::MainLoop::create();
  mainLoop->run();

  std::cout << __FUNCTION__ << "() end" << std::endl;
  return 0;
}
