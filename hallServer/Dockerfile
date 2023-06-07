FROM ubuntu:18.04

RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone
RUN apt-get update

RUN apt-get install qt5-default -y
RUN apt-get install qtbase5-dev -y
RUN apt-get install qt5-qmake
RUN apt-get install build-essential -y

RUN mkdir Asadov_221-3210
COPY *.cpp /Asadov_221-3210
COPY *.h /Asadov_221-3210
COPY *.pro /Asadov_221-3210

RUN qmake hallServer.pro
RUN make

ENTRYPOINT ["./hallServer"]