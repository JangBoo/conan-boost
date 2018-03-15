
conan create -s arch=x86 -s compiler.runtime=MT --keep-source --keep-build . demo/testing

conan create -s arch=x86 -s compiler.runtime=MT . conan/stable
