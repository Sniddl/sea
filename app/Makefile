CC = g++
CFLAGS = -std=c++17
DEPS =
OBJS = router.o response.o request.o

all: main

main: $(OBJS)
	cd /app/bin && $(CC) $(CFLAGS) -o /app/bin/main /app/src/main.cc $(OBJS)

router.o: /app/src/router.cc
	$(CC) $(CFLAGS) -c -o /app/bin/router.o /app/src/router.cc

response.o: /app/src/response.cc
	$(CC) $(CFLAGS) -c -o /app/bin/response.o /app/src/response.cc

request.o: /app/src/request.cc
	$(CC) $(CFLAGS) -c -o /app/bin/request.o /app/src/request.cc
