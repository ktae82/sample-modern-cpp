#include "SampleDataServer.h"

constexpr char GDBUS_OBJECT_PATH[] = "/sample/SampleData";
constexpr char GDBUS_INTERFACE_NAME[] = "sample.SampleData";

void SampleDataServer::initialize() {
  try {
    std::cout << "SampleDataServer::" << __FUNCTION__ << "()" << std::endl;

    mGdbusOwnerId = Gio::DBus::own_name(
        Gio::DBus::BUS_TYPE_SESSION, GDBUS_INTERFACE_NAME,
        std::bind(&SampleDataServer::onBusAcquired, this, std::placeholders::_1,
                  std::placeholders::_2),
        std::bind(&SampleDataServer::onNameAcquired, this,
                  std::placeholders::_1, std::placeholders::_2),
        std::bind(&SampleDataServer::onNameLost, this, std::placeholders::_1,
                  std::placeholders::_2));
  } catch (const Glib::Error &e) {
    std::cout << __FUNCTION__ << "() exception e" << e.what() << std::endl;
  } catch (const std::exception &e) {
    std::cout << __FUNCTION__ << "() exception e" << e.what() << std::endl;
  }
}

void SampleDataServer::connect(MethodInvocation &invocation) {
  try {
    std::cout << "SampleDataServer::" << __FUNCTION__ << "()" << std::endl;

    guint watcherId = 0;
    std::string address = invocation.getMessage()->get_sender();
    const Glib::RefPtr<Gio::DBus::Connection> &connection =
        invocation.getMessage()->get_connection();

    watcherId = Gio::DBus::watch_name(
        connection, address,
        std::bind(&SampleDataServer::onNameAppeared, this,
                  std::placeholders::_1, std::placeholders::_2,
                  std::placeholders::_3),
        std::bind(&SampleDataServer::onNameVanished, this,
                  std::placeholders::_1, std::placeholders::_2));

    mWatchMap[address] = watcherId;

    std::cout << "SampleDataServer::" << __FUNCTION__
              << "() address:" << address << std::endl;

    invocation.ret();
  } catch (const Glib::Error &e) {
    std::cout << __FUNCTION__ << "() exception e" << e.what() << std::endl;
  } catch (const std::exception &e) {
    std::cout << __FUNCTION__ << "() exception e" << e.what() << std::endl;
  }
}

void SampleDataServer::getData(gint32 index, MethodInvocation &invocation) {
  try {
    std::cout << "SampleDataServer::" << __FUNCTION__ << "() index:" << index
              << std::endl;

    invocation.ret(mDatas[index]);

  } catch (const Glib::Error &e) {
    std::cout << __FUNCTION__ << "() exception e" << e.what() << std::endl;
  } catch (const std::exception &e) {
    std::cout << __FUNCTION__ << "() exception e" << e.what() << std::endl;
  }
}

void SampleDataServer::setData(gint32 index, const Glib::ustring &data,
                               MethodInvocation &invocation) {
  try {
    std::cout << "SampleDataServer::" << __FUNCTION__ << "()" << std::endl;

    std::vector<Glib::ustring> busNames;
    mDatas[index] = data;
    invocation.ret();

    for (const auto &watch : mWatchMap) {
      busNames.push_back(watch.first);
      std::cout << "SampleDataServer::setData() emit bus:" << watch.first
                << std::endl;
    }

    onDataChanged_emitter(busNames, index, data);
  } catch (const Glib::Error &e) {
    std::cout << __FUNCTION__ << "() exception e" << e.what() << std::endl;
  } catch (const std::exception &e) {
    std::cout << __FUNCTION__ << "() exception e" << e.what() << std::endl;
  }
}

void SampleDataServer::onNameAppeared(
    const Glib::RefPtr<Gio::DBus::Connection> &connection,
    const Glib::ustring &name, const Glib::ustring &name_owner) {
  try {
    std::cout << "SampleDataServer::" << __FUNCTION__ << "()" << std::endl;
  } catch (const Glib::Error &e) {
    std::cout << __FUNCTION__ << "() exception e" << e.what() << std::endl;
  } catch (const std::exception &e) {
    std::cout << __FUNCTION__ << "() exception e" << e.what() << std::endl;
  }
}

void SampleDataServer::onNameVanished(
    const Glib::RefPtr<Gio::DBus::Connection> &connection,
    const Glib::ustring &name) {
  try {
    std::cout << "SampleDataServer::" << __FUNCTION__ << "()" << std::endl;

    mWatchMap.erase(name);
  } catch (const Glib::Error &e) {
    std::cout << __FUNCTION__ << "() exception e" << e.what() << std::endl;
  } catch (const std::exception &e) {
    std::cout << __FUNCTION__ << "() exception e" << e.what() << std::endl;
  }
}

void SampleDataServer::onBusAcquired(
    const Glib::RefPtr<Gio::DBus::Connection> &connection,
    const Glib::ustring &name) {
  try {
    std::cout << "SampleDataServer::" << __FUNCTION__ << "()" << std::endl;
    register_object(connection, GDBUS_OBJECT_PATH);
  } catch (const Glib::Error &e) {
    std::cout << __FUNCTION__ << "() exception e" << e.what() << std::endl;
  } catch (const std::exception &e) {
    std::cout << __FUNCTION__ << "() exception e" << e.what() << std::endl;
  }
}

void SampleDataServer::onNameAcquired(
    const Glib::RefPtr<Gio::DBus::Connection> &connection,
    const Glib::ustring &name) {
  try {
    std::cout << "SampleDataServer::" << __FUNCTION__ << "()" << std::endl;
  } catch (const Glib::Error &e) {
    std::cout << __FUNCTION__ << "() exception e" << e.what() << std::endl;
  } catch (const std::exception &e) {
    std::cout << __FUNCTION__ << "() exception e" << e.what() << std::endl;
  }
}

void SampleDataServer::onNameLost(
    const Glib::RefPtr<Gio::DBus::Connection> &connection,
    const Glib::ustring &name) {
  try {
    std::cout << "SampleDataServer::" << __FUNCTION__ << "()" << std::endl;
  } catch (const Glib::Error &e) {
    std::cout << __FUNCTION__ << "() exception e" << e.what() << std::endl;
  } catch (const std::exception &e) {
    std::cout << __FUNCTION__ << "() exception e" << e.what() << std::endl;
  }
}