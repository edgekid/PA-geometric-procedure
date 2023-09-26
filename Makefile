include Makefile.configuration

# LIBSOURCES = $(wildcard libnormaliz/*.cpp)
# LIBHEADERS = $(wildcard libnormaliz/*.h)
# LIBOBJECTS = $(wildcard libnormaliz/*.o)

SOURCES = $(wildcard *.cpp)
HEADERS = $(wildcard *.h)

ANTLR_HEADER = -Iparser/antlr4/include/antlr4-runtime
ANTLR_LINK = parser/antlr4/lib/libantlr4-runtime.a

default: linknormaliz

linknormaliz: libnorm
	@$(MAKE) geometric
# must force the kinking of libnormaliz/libnormaloiz.a or so
geometric: $(SOURCES) $(HEADERS) $(LIBLINK) $(ANTLR_LINK) geometric_procedure.cpp
	$(CXX) $(CXXFLAGS) $(NORMFLAGS) geometric_procedure.cpp semilinear_expression.cpp arrangement.cpp parser/*.cpp $(LIBLINK) $(LINKFLAGS) $(ANTLR_HEADER) $(ANTLR_LINK) -o geometric_procedure

libnorm: 
	@$(MAKE) --directory=libnormaliz -f Makefile.classic $(LIBNAME)

clean:
	rm libnormaliz/*.o
	rm libnormaliz/*.a
	rm geometric_procedure.exe