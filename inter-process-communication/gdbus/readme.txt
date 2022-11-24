build & run

1. install gdbus codegen
  $ git clone https://github.com/Pelagicore/gdbus-codegen-glibmm
  $ sudo python3 ./setup.py install

2. install libglibmm-2.4-dev
  $ sudo apt-get install libglibmm-2.4-dev

3. build
  $ source build.sh

4. run server
  $ ./server/build/gdbus-sample-server

5. run client
  $ ./client/build/gdbus-sample-client
