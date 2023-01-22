compile:
		
		g++ -std=c++11 Server.cpp Distance.cpp Knn.cpp Validation.cpp TCPServer.cpp TCPclient.cpp DefaultIO.cpp ClientData.cpp CliClient.cpp CommandsClient.cpp Command.cpp Upload.cpp Setting.cpp Classify.cpp DisplayCommand.cpp DownloadCommand.cpp CLI.cpp SocketIO.cpp -pthread -o server.out
		g++ -std=c++11 Client.cpp Distance.cpp Knn.cpp Validation.cpp TCPServer.cpp TCPclient.cpp DefaultIO.cpp ClientData.cpp CliClient.cpp CommandsClient.cpp Command.cpp Upload.cpp Setting.cpp Classify.cpp DisplayCommand.cpp DownloadCommand.cpp CLI.cpp SocketIO.cpp -pthread -o client.out

clean:
	rm -f *.o output
