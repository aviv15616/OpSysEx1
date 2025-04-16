# קומפיילר והגדרות
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -fprofile-arcs -ftest-coverage -g
LDFLAGS = -fprofile-arcs -ftest-coverage

# קבצי מקור
SRC = GraphApp.cpp GraphBuilder.cpp Dijkstra.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = graph_app

# ברירת מחדל
all: $(TARGET)

# יצירת קובץ הרצה
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# קומפילציה של כל .cpp ל-.o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# הרצה
run: $(TARGET)
	./$(TARGET)


# הצגת סיכום כיסוי 
coverage-summary:
	@gcov GraphApp.cpp GraphBuilder.cpp Dijkstra.cpp | awk '/File '\''(GraphApp|GraphBuilder|Dijkstra)\.cpp'\''/ {file=$$0} /Lines executed:/ {if (file) {print file; print $$0; print ""; file=""}}'
	find . -type f -name '*.gcov' ! -name 'GraphApp.cpp.gcov' ! -name 'GraphBuilder.cpp.gcov' ! -name 'Dijkstra.cpp.gcov' -delete

# ניקוי קבצים זמניים
clean:
	rm -f $(OBJ) $(TARGET) *.gcda *.gcno *.gcov

.PHONY: all run coverage coverage-summary clean
