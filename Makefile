all: RaspControl

RaspControl: RCSwitch.o RaspControl.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $+ -o $@ -lwiringPi -lcgicc

clean:
	$(RM) *.o RaspControl
