# Where to find user code.
USER_DIR = ..

CXX = g++

# Flags passed to the preprocessor.
# CPPFLAGS += -I$(GTEST_DIR)/include

# Flags passed to the C++ compiler.
CXXFLAGS += -g -Wall -Wextra

# All tests produced by this Makefile.  Remember to add new tests you
# created to the list.
TESTS = checkpoints
TESTS += checkmatrices
TESTS += checksva

# House-keeping build targets.

all : $(TESTS)

clean :
	rm -f $(TESTS) *.o

# Builds a sample test.

Point.o : $(USER_DIR)/Point.cpp $(USER_DIR)/Point.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/Point.cpp

checkpoints.o : checkpoints.cpp $(USER_DIR)/Point.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c checkpoints.cpp

checkpoints : Point.o checkpoints.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

Matrix.o : $(USER_DIR)/Matrix.cpp $(USER_DIR)/Matrix.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/Matrix.cpp

checkmatrices.o : checkpoints.cpp $(USER_DIR)/Matrix.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c checkmatrices.cpp

checkmatrices : Matrix.o checkmatrices.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

SparseVector.o : $(USER_DIR)/SparseVector.cpp $(USER_DIR)/SparseVector.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/SparseVector.cpp

checksva.o : checksva.cpp $(USER_DIR)/SparseVector.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c checksva.cpp

checksva : SparseVector.o checksva.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@
