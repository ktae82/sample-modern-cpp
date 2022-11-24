#include <iostream>

#include "SampleDataServer.h"

int main(int argc, char *argv[]) {
  std::cout << __FUNCTION__ << "() start" << std::endl;

  Glib::init();
  Gio::init();

  SampleDataServer server;
  server.initialize();

  Glib::RefPtr<Glib::MainLoop> mainLoop = Glib::MainLoop::create();
  mainLoop->run();

  std::cout << __FUNCTION__ << "() end" << std::endl;

  return 0;
}
