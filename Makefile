CC=g++
OBJS = checker.cpp file.cpp parse.cpp URL.cpp
PATHS = -I/usr/include -L/usr/local/lib64
LIBS = -lcurl -lcurlpp `xml2-config --cflags --libs` `pkg-config libxml++-3.0 --cflags --libs`
CFLAGS= -Wall -c $(LIBS) --std=c++14
LFLAGS = -Wall --std=c++14

checker : 
	$(CC) $(OBJS) $(LFLAGS) $(PATHS) $(LIBS) -o checker

