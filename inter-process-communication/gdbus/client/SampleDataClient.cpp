#include "SampleDataClient.h"

constexpr char GDBUS_OBJECT_PATH[] = "/sample/SampleData";
constexpr char GDBUS_INTERFACE_NAME[] = "sample.SampleData";

void SampleDataClient::initialize() {
  try {
    std::cout << "SampleDataClient::" << __FUNCTION__ << "()" << std::endl;

    mpSampleDataProxy = sample::SampleDataProxy::createForBus_sync(
        Gio::DBus::BUS_TYPE_SESSION, Gio::DBus::ProxyFlags::PROXY_FLAGS_NONE,
        GDBUS_INTERFACE_NAME, GDBUS_OBJECT_PATH);

    mOnDataChanged = mpSampleDataProxy->onDataChanged_signal.connect(
        std::bind(&SampleDataClient::onDataChanged, this, std::placeholders::_1,
                  std::placeholders::_2));

    mWatcherId = Gio::DBus::watch_name(
        mpSampleDataProxy->dbusProxy()->get_connection(), GDBUS_INTERFACE_NAME,
        std::bind(&SampleDataClient::onNameAppeared, this,
                  std::placeholders::_1, std::placeholders::_2,
                  std::placeholders::_3),
        std::bind(&SampleDataClient::onNameVanished, this,
                  std::placeholders::_1, std::placeholders::_2));

    mpSampleDataProxy->connect_sync();
  } catch (const Glib::Error &e) {
    std::cout << __FUNCTION__ << "() exception e" << e.what() << std::endl;
  } catch (const std::exception &e) {
    std::cout << __FUNCTION__ << "() exception e" << e.what() << std::endl;
  }
}

void SampleDataClient::getData(int index, std::string &data) {
  try {
    std::cout << "SampleDataClient::" << __FUNCTION__ << "()" << std::endl;

    if (mpSampleDataProxy.get() != nullptr) {
      data = mpSampleDataProxy->getData_sync(static_cast<gint32>(index));
    }
  } catch (const Glib::Error &e) {
    std::cout << __FUNCTION__ << "() exception e" << e.what() << std::endl;
  } catch (const std::exception &e) {
    std::cout << __FUNCTION__ << "() exception e" << e.what() << std::endl;
  }
}

void SampleDataClient::setData(int index, const std::string &data) {
  try {
    std::cout << "SampleDataClient::" << __FUNCTION__ << "()" << std::endl;

    if (mpSampleDataProxy.get() != nullptr) {
      mpSampleDataProxy->setData_sync(static_cast<gint32>(index),
                                      Glib::ustring(data));
    }
  } catch (const Glib::Error &e) {
    std::cout << __FUNCTION__ << "() exception e" << e.what() << std::endl;
  } catch (const std::exception &e) {
    std::cout << __FUNCTION__ << "() exception e" << e.what() << std::endl;
  }
}

void SampleDataClient::onDataChanged(gint32 index, Glib::ustring data) {
  try {
    std::cout << "SampleDataClient::" << __FUNCTION__
              << "(), index:" << static_cast<int>(index)
              << ", data:" << std::string(data) << std::endl;
  } catch (const Glib::Error &e) {
    std::cout << __FUNCTION__ << "() exception e" << e.what() << std::endl;
  } catch (const std::exception &e) {
    std::cout << __FUNCTION__ << "() exception e" << e.what() << std::endl;
  }
}

void SampleDataClient::onNameAppeared(
    const Glib::RefPtr<Gio::DBus::Connection> &connection,
    const Glib::ustring &name, const Glib::ustring &name_owner) {
  try {
    std::cout << "SampleDataClient::" << __FUNCTION__ << "()" << std::endl;

    if (mpSampleDataProxy.get() != nullptr) {
      mpSampleDataProxy->connect_sync();
    }
  } catch (const Glib::Error &e) {
    std::cout << __FUNCTION__ << "() exception e" << e.what() << std::endl;
  } catch (const std::exception &e) {
    std::cout << __FUNCTION__ << "() exception e" << e.what() << std::endl;
  }
}

void SampleDataClient::onNameVanished(
    const Glib::RefPtr<Gio::DBus::Connection> &connection,
    const Glib::ustring &name) {
  try {
    std::cout << "SampleDataClient::" << __FUNCTION__ << "()" << std::endl;
  } catch (const Glib::Error &e) {
    std::cout << __FUNCTION__ << "() exception e" << e.what() << std::endl;
  } catch (const std::exception &e) {
    std::cout << __FUNCTION__ << "() exception e" << e.what() << std::endl;
  }
}
