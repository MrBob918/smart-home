FROM arm64v8/debian:bookworm-slim
WORKDIR /smart-home/core
RUN cmake clang install
COPY . .
RUN cmake -workflow -preset RCAB
CMD "./build/relese/Handler"