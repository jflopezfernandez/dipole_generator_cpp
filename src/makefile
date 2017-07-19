
CPP := icpc

CPPFLAGS := -g -std=c++14 -strict-ansi -Wall -Werror-all                      \
            -Wstrict-aliasing -no-intel-extensions -Wcheck

# Unrecognized compiler flags
# -0d
# -Wport

SRCS := $(wildcard *.cpp)
OBJS := $(patsubst %.cpp,%.o,$(SRCS))


PROGRAM := test


$(PROGRAM): $(OBJS)
	$(CPP) $(CPPFLAGS) -g -o test $(OBJS)

$(OBJS): $(SRCS)
	$(CPP) -c $(CPPFLAGS) $(SRCS)

clean:
	rm -rf $(OBJS)
	rm ./DIP3D
