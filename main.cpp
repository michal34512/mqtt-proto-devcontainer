#include <iostream>
#include "proto/message.pb.h"
#include "mqtt/client.h"

using namespace std;
int main(int argc, char const *argv[])
{
  // Preparing data
  message::Message mes;
  mes.set_mystring("Hello Protobuf");
  mes.set_myint(2137);
  message::Person* person = mes.mutable_myperson();
  person->set_age(84);
  person->set_name("Karol");
  cout << "Message before encryption: " << mes.mystring() << " " << mes.myint() << " " << mes.myperson().name() <<  " " << mes.myperson().age() <<  endl;

  // Encryption
  std::string encrypted;
  mes.SerializeToString(&encrypted);

  std::cout << "Initializing mqtt..." << std::endl;
	mqtt::client client("mqtt://127.0.0.1:1883", "My client id");

	mqtt::connect_options connOpts;
	connOpts.set_keep_alive_interval(20);
	connOpts.set_clean_session(true);

	try {
		std::cout << "\nConnecting..." << std::endl;
		client.connect(connOpts);

		std::cout << "\nSending message..." << std::endl;
		auto pubmsg = mqtt::make_message("my_topic", "huj");
		pubmsg->set_qos(2);
		client.publish(pubmsg);

		std::cout << "\nDisconnecting..." << std::endl;
		client.disconnect();
	}
	catch (const mqtt::persistence_exception& exc) {
		std::cerr << "Persistence Error: " << exc.what() << " ["
			<< exc.get_reason_code() << "]" << std::endl;
		return 1;
	}
	catch (const mqtt::exception& exc) {
		std::cerr << exc.what() << std::endl;
		return 1;
	}
 	return 0;
}
