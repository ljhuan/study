all:a.out test.service
	systemctl stop test
	cp -rf test.service /usr/lib/systemd/system/
	systemctl enable test.service
	systemctl start test
	systemctl status test
a.out:notice.cpp
	g++ notice.cpp -lsystemd
.PHONY:
clean:
	systemctl stop test
	rm -rf	/usr/lib/systemd/system/test.service
	rm -rf a.out
	
