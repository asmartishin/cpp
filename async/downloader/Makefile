all: downloader.cpp
	gc++ downloader.cpp -lcurl -levent -odownloader

clean:
	rm -f downloader.o

run_test:
	./downloader.o https://curl.haxx.se/libcurl/c/hiperfifo.html https://curl.haxx.se/libcurl/c/curl_multi_info_read.html
