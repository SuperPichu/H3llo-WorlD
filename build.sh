#Clean
make clean
#Build
make
#Send
cat h3llo-worlD.3dsx | pv -b | nc 192.168.1.148 9000 -q 2