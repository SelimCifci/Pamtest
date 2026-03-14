cmake -S . -B build
cmake --build build
sudo rm /usr/bin/pamtest
sudo cp build/pamtest /usr/bin/pamtest
sudo rm /etc/pam.d/test_config
sudo cp test_config /etc/pam.d/test_config
