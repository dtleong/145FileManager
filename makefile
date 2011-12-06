all: disk.o DataBlock.o FCB.o FileDirectory.o FileInfo.o FSHarness.o FSCommon.o
	cc disk.o DataBlock.o FCB.o FileDirectory.o FileInfo.o FSHarness.o FSCommon.o -g -lm -o FS.bin
clean: 
	rm *.o 2>/dev/null
project2: disk.o 
disk.o: disk.c disk.h
	cc -g -c disk.c
DataBlock.o: DataBlock.c DataBlock.h FSCommon.h
	cc -g -c DataBlock.c
FCB.o: FCB.c FCB.h DataBlock.h FSCommon.h
	cc -g -c FCB.c
FileDirectory.o: FileDirectory.c FileDirectory.h FSCommon.h
	cc -g -c FileDirectory.c
FileInfo.o: FileInfo.c FileInfo.h FSCommon.h
	cc -g -c FileInfo.c
FSHarness.o: FSHarness.c FSCommon.h
	cc -g -c FSHarness.c
FSCommon.o: FSCommon.c FSCommon.h
	cc -g -c FSCommon.c
