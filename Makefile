.DEFAULT_GOAL := app
SRC       	= $(CURDIR)/src
CC        	= ccache gcc
APPDIR      = $(CURDIR)/bin
SRCS    	= $(SRC)/config_parser.c $(SRC)/test_config_parser.c
OBJS     	= $(SRCS:.c=.o)
INCLUDE     = -I$(SRC)

app: configParser
	@echo "Compiled"

configParser: ${OBJS}
	@mkdir -p ${APPDIR}
	${CC} ${CFLAG} ${INCLUDE} ${OBJS} -o ${APPDIR}/configParser

# Compile all .c into .o right in the src/ folder
${OBJS}: %.o: %.c
	${CC} ${CFLAG} ${INCLUDE} -o $*.o -c $<

clean:
	@rm -rf bin/${APPNAME}
	@rm -f ${OBJS}
