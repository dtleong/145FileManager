all: disk.o DataBlock.o FCB.o FileDirectory.o FileInfo.o FSHarness.o
	cc disk.o DataBlock.o FCB.o FileDirectory.o FileInfo.o FSHarness.o -o FS.bin
clean: 
	rm *.o 2>/dev/null
project2: disk.o 
disk.o: disk.c disk.h
	cc -c disk.c
DataBlock.o: DataBlock.c DataBlock.h FSCommon.h
	cc -c DataBlock.c
FCB.o: FCB.c FCB.h DataBlock.h FSCommon.h
	cc -c FCB.c
FileDirectory.o: FileDirectory.c FileDirectory.h FSCommon.h
	cc -c FileDirectory.c
FileInfo.o: FileInfo.c FileInfo.h FSCommon.h
	cc -c FileInfo.c
FSHarness.o: FSHarness.c FSCommon.h
	cc -c FSHarness.c
