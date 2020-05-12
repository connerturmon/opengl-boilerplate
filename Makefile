SOURCE = source/*.cpp
C_SOURCE = -x c Dependencies/glad/glad.c
IMGUI_SOURCE = Dependencies/imgui/*.cpp
INCLUDE = -Isource/include/ -IDependencies/

LFLAGS_LINUX = -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl
LFLAGS_MACOS = -lglfw

linux:
	clang++ $(LFLAGS_LINUX) $(INCLUDE) $(SOURCE) $(IMGUI_SOURCE) $(C_SOURCE)