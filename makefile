TARGET = xy

CXXFLAGS = -Wall -Ofast -funroll-loops -flto 
LDFLAGS = $(CXXFLAGS)

SRCS = src/main.cpp src/angle.cpp src/parse.cpp src/metropolis.cpp \
       src/latticeupdate.cpp src/magnetisation.cpp src/correlator.cpp \
	   src/correlation.cpp src/betamag.cpp src/hot_start.cpp
OBJS = $(subst .cpp,.o,$(SRCS))
HDRS = $(filter-out src/main.h, $(subst .cpp,.h,$(SRCS))) src/arguments.h

all: $(TARGET)
	$(info)

$(TARGET): $(OBJS)
	g++ $(LDFLAGS) $(OBJS) -o $(TARGET)

.PHONY: clean
clean:
	@$(RM) -v $(OBJS)
	$(info Cleaning up object files)

.PHONY: tar
tar:
	@tar -cvJf $(TARGET).tar.xz makefile $(SRCS) $(HDRS)

