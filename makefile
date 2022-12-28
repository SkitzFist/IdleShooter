SHELL := pwsh -NoProfile
TARGET = game.html

OBJDIR := obj/
DEPDIR := $(OBJDIR)deps/

SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:%.cpp=$(OBJDIR)%.o)
DEPS := $(SRCS:%.cpp=$(DEPDIR)%.d)

CFLAGS := -03 -sASSERTIONS -Wall -I include/ -L lib/ -lraylib -s USE_GLFW=3 -s -sFULL_ES2 -s ASYNCIFY -sFORCE_FILESYSTEM --shell-file shell\Shell.html -DPLATFORM_WEB

$(TARGET) : $(OBJS)
	em++ -lembind  $^ -o $@ $(CFLAGS)

$(OBJDIR)%.o : %.cpp $(DEPDIR)%.d | $(DEPDIR)
	em++ -MMD -MT $@ -MP -MF $(DEPDIR)$*.d -o $@ -c $<

$(DEPS):

clean:
	del obj\*.o
	del obj\deps\*.d
	del *.js
	del *.wasm
	del *.html

include $(wildcard $(DEPS))