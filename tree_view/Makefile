view : view.o tree_input.o tree_views.o
	g++ -o view view.o tree_input.o tree_views.o

view.o : view.cpp tree.h
	g++ -c view.cpp

tree_views.o : tree_views.cpp tree.h
	g++ -c tree_views.cpp

tree_input.o : tree_input.cpp tree.h
	g++ -c tree_input.cpp
