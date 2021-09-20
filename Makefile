#  Name Emile LEPETIT
#  Class (CECS 282-01)
#  Project Name (Prog 2 – myDate)
#  Due Date (09/27/2021)
#  I certify that this program is my own original work. I did not copy any part of this program from
#  any other source. I further certify that I typed each and every line of code in this program.

CXX			=	g++

NAME		=	myDate

RM			=	rm -f

CXXFLAGS	+=	-std=c++11
CXXFLAGS	+=	-Werror -Wall -Wextra

SRCS		=	./main.cpp 		\
				./myDate.cpp	\

TESTS_SRCS	=	./tests/myDateTest.cpp 		\
				./myDate.cpp				\

OBJS		=	$(SRCS:.cpp=.o)

TEST_OBJS		=	$(TESTS_SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CXX) $(OBJS) $(CXXFLAGS) -o $(NAME)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

tests: $(TEST_OBJS)
		$(CXX) $(TEST_OBJS) -lcriterion $(CXXFLAGS) -o tests_run