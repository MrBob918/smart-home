FROM arm64v8/debian
WORKDIR /SmartHome/Core
RUN apt-get update && apt-get -y install cmake clang llvm lld libstdc++ libc++ && apt-get upgrade
COPY . .
RUN cmake --workflow -preset RCAB
CMD "./build/relese/Core"