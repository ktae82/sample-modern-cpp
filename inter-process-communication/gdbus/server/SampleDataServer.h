#ifndef GDBUS_SAMPLEDATASERVER_H
#define GDBUS_SAMPLEDATASERVER_H

#include <iostream>
#include <map>

#include "../gdbus-gen/SampleData_stub.h"

class SampleDataServer : public sample::SampleDataStub {
public:
  void initialize();
  void connect(MethodInvocation &invocation) override;
  void getData(gint32 index, MethodInvocation &invocation) override;
  void setData(gint32 index, const Glib::ustring &data,
               MethodInvocation &invocation) override;

public:
  void onNameAppeared(const Glib::RefPtr<Gio::DBus::Connection> &connection,
                      const Glib::ustring &name,
                      const Glib::ustring &name_owner);
  void onNameVanished(const Glib::RefPtr<Gio::DBus::Connection> &connection,
                      const Glib::ustring &name);
  void onBusAcquired(const Glib::RefPtr<Gio::DBus::Connection> &connection,
                     const Glib::ustring &name);
  void onNameAcquired(const Glib::RefPtr<Gio::DBus::Connection> &connection,
                      const Glib::ustring &name);
  void onNameLost(const Glib::RefPtr<Gio::DBus::Connection> &connection,
                  const Glib::ustring &name);

private:
  guint mGdbusOwnerId;
  gint32 mIndex;
  std::map<gint32, Glib::ustring> mDatas;
  std::map<Glib::ustring /*busName*/, gint32 /*watchId*/> mWatchMap;
};
#endif // GDBUS_SAMPLEDATASERVER_H