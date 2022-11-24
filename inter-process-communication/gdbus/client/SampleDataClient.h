#ifndef GDBUS_SAMPLEDATACLIENT_H
#define GDBUS_SAMPLEDATACLIENT_H

#include <iostream>

#include "../gdbus-gen/SampleData_proxy.h"

class SampleDataClient {
public:
  void initialize();
  void getData(int index, std::string &data);
  void setData(int index, const std::string &data);
  void onDataChanged(gint32 index, Glib::ustring data);

public:
  void onNameAppeared(const Glib::RefPtr<Gio::DBus::Connection> &connection,
                      const Glib::ustring &name,
                      const Glib::ustring &name_owner);
  void onNameVanished(const Glib::RefPtr<Gio::DBus::Connection> &connection,
                      const Glib::ustring &name);

private:
  Glib::RefPtr<sample::SampleDataProxy> mpSampleDataProxy;
  guint mWatcherId;
  sigc::connection mOnDataChanged;
};
#endif // GDBUS_SAMPLEDATACLIENT_H