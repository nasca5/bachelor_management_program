CC = gcc
CFLAGS = -c -g
LDFLAGS = -Wall -Wextra -Werror -MMD -MP
SRCS = bachelor_management_for_staff.c register.c search.c print.c
OBJS = $(SRCS:.c=.o) 
DEPS = $(OBJS:.o=.d)
TARGET = main

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c bachelor_info.h
	$(CC) $(CFLAGS) $(LDFLAGS) $<

-include $(DEPS)

.PHONY: clean run all

clean : 
	del $(TARGET).exe $(OBJS) $(DEPS)

run : all
	$(TARGET)
