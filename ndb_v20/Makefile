LDFLAGS = -Map /var/tmp/ndbmap.txt
WFLAGS := -Wall -Wstrict-prototypes -Wno-trigraphs
EXTRA_CFLAGS := $(WFLAGS)
EXTRA_CFLAGS += -D_DEBUG -g3  -fno-stack-protector

MODULE = ndb_v20
KDIR = /lib/modules/`uname -r`/build
M := make -C ${KDIR} M=`pwd`

obj-m := $(MODULE).o 

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) modules

install:
	/bin/bash ./install.sh

modules_install:
	${M} modules_install

$(MODULE)-objs := main.o kgb.o

clean:
	rm -rf *.o *~ .*.cmd *.ko *.mod.c *.mod *.cmd *.builtin *.order *.symvers .tmp_versions built-in.o built-in.a
