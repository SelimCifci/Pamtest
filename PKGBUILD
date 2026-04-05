# Maintainer: Your Name <youremail@example.com>
pkgname=pamtest
pkgver=1.0.0
pkgrel=1
desc="PAM-aware program to test custom PAM modules"
arch=('x86_64')
url="https://github.com/SelimCifci/Pamtest"
license=('GPL3')
depends=('pam')
makedepends=('cmake')
source=("git+https://github.com/SelimCifci/Pamtest.git")
sha256sums=('SKIP')

build() {
  cd "src/Pamtest"
  cmake -S . -B build -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr
  cmake --build build
}

package() {
  cd "src/Pamtest"
  cmake --install build --prefix=/usr --destdir="${pkgdir}"
}
