cmake -S . -B build
cmake --build build
sudo rm /etc/pam.d/test_config
sudo cp test_config /etc/pam.d/test_config
