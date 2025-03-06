SIGNAL=signal

cc=g++

SIGNAL_SRC=signal.cc


$(SIGNAL):$(SIGNAL_SRC)
	$(cc) -o $@ $^ -std=c++11


.PHONY:clean
clean:
	rm -f $(SIGNAL)