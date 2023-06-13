CC = gcc
CFLAGS = -c -g
LDFLAGS = -Wall -Wextra -Werror -MMD -MP
SRCS = bachelor_management_for_staff.c register.c search.c print.c modify.c
OBJS = $(SRCS:.c=.o) 
DEPS = $(OBJS:.o=.d)
TARGET = bachelor_management_for_staff

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS)

%.o: %.c bachelor_info.h
	$(CC) $(CFLAGS) $(LDFLAGS) $< -o $@

-include $(DEPS)

.PHONY: clean run all

clean : 
	del $(TARGET) $(OBJS) $(DEPS)

run : all
	$(TARGET)
