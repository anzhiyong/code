#  @可以关闭回显
obj=proc
src=main.c proc.c
$(obj):$(src)
		gcc -o $@ $^

.PHONY:clean
clean:
		rm -f $(obj)
