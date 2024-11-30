CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = spell_checker
SRCS = spell_checker.c hashset_pa4.c
OBJS = $(SRCS:.c=.o)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

spell_checker.o: spell_checker.c
	$(CC) $(CFLAGS) -c $< -o $@

hashset_pa4.o: hashset_pa4.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
