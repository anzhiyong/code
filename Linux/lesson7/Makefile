bin1=proc
src1=proc.c

#bin2=code
#src2=code.c

#.PHONY:all
#all:$(bin1) $(bin2)

$(bin1):$(src1)
	gcc $^ -o $@

#$(bin2):$(src2)
#	gcc $^ -o $@


.PHONY:clean
clean:
	rm -f $(bin1)
	#rm -f $(bin1) $(bin2)