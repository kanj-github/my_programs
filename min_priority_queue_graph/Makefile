test : min_p_q_test.o min_priority_queue.o
	g++ -o test min_p_q_test.o min_priority_queue.o

min_p_q_test.o : min_p_q_test.cpp
	g++ -c min_p_q_test.cpp

min_priority_queue.o : min_priority_queue.cpp mpq.h
	g++ -c min_priority_queue.cpp
