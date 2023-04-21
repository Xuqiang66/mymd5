# mymd5
# $^ 依赖 不重复
# %@ 目标
# @ 不显示命令执行
TARGET=mymd5
CFLAGS=-I/home/nvidia/myfile/mymd5/src
CFLAGS+=-I/usr/local/include/openssl
#LIBS=-L/home/nvidia/myfile/mymd5/lib
LIBS=-L/usr/local/lib -lssl -lcrypto
OBJS=mymd5.o
$(TARGET):$(OBJS)
	@echo "begin build $(TARGET)"
	$(CC) $^ $(CFLAGS) -o $@ $(LIBS)
	@echo "$(TARGET) build success!"

clean:
	$(RM) $(OBJS) $(TARGET)
.PHONY: clean *clean
