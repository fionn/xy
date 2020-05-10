TARGET = xy

CXX = g++

CXXFLAGS = -Wall -Ofast -funroll-loops -flto 
LDFLAGS = $(CXXFLAGS)

SRCS = src/main.cpp src/angle.cpp src/parse.cpp src/metropolis.cpp \
       src/latticeupdate.cpp src/magnetisation.cpp src/correlator.cpp \
	   src/correlation.cpp src/betamag.cpp src/hot_start.cpp
OBJS = $(subst .cpp,.o,$(SRCS))
HDRS = $(filter-out src/main.hpp, $(subst .cpp,.hpp,$(SRCS))) src/arguments.hpp

all: $(TARGET)
	$(info)

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) -o $(TARGET)

.PHONY: clean
clean:
	@$(RM) -v $(OBJS)
	$(info Cleaning up object files)

.PHONY: cleanall
cleanall: clean
	@$(RM) -v $(TARGET)

.PHONY: tar
tar:
	@tar -cvJf $(TARGET).tar.xz Makefile $(SRCS) $(HDRS)

.PHONY: lint
lint:
	@clang-tidy $(HDRS) $(SRCS)

