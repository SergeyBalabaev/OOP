/*
Задача:
Приходят данные с трех источников - текстовый файл, USB, UART. Задача программы - принять данные и обработать их в соответствии с правилами
Текстовый файл содержит настройки устройства (3 числовых данных, записанных через символ ';'. Первое число - скорость передачи UART)
По USB приходят данные для обработки
По UART происходит отладка устройства и сообщения о его состоянии
	На UART приходят только два типа сообщений - D (Debug) и I (Info)

*/

#include <iostream>

#define MESSAGEFILE "123;456;789;"
#define MESSAGEUART "D some errors..."
#define MESSAGEUSB "123;456;789;"

class interface_readerWriter {
protected:
	virtual void writer_init() = 0;
	virtual void reader_init() = 0;
};

class reader : public interface_readerWriter {
public:
	void writer_init() {};
	void reader_init() {
		std::cout << "reader init" << std::endl;
	}
	std::string readfromfile() {
		std::cout << "reading from file: " << MESSAGEFILE << std::endl;
		return MESSAGEFILE;
	}
	std::string readFromUART() {
		std::string S = MESSAGEUART;
		if (S[0] == 'D')
			std::cout << "reading from UART debug message: " << MESSAGEUART << std::endl;
		if (S[0] == 'I')
			std::cout << "reading from UART info message: " << MESSAGEUART << std::endl;
		return MESSAGEUART;
	}
	std::string readfromUSB() {
		std::cout << "reading from USB: " << MESSAGEUSB << std::endl;
		return MESSAGEUSB;
	}
};

class parser {
private:
	int a = 0;
	int b = 0;
	int c = 0;
public:
	void reader(std::string Str) {
		int N = findsize(Str);
		int i = 0;
		while (Str[i] != ';') {
			a = a * 10 * (i != 0) + (int)Str[i] - 48;
			i++;
		}
		i++;
		while (Str[i] != ';') {
			b = b * 10 * (i != 0) + (int)Str[i] - 48;
			i++;
		}
		i++;
		while (i < N) {
			c = c * 10 * (i != 0) + (int)Str[i] - 48;
			i++;
		}


	}
	int get_a() { return a; };
	int get_b() { return b; };
	int get_c() { return c; };
	void set_a(int a_) { a = a_; };
	void set_b(int b_) { b = b_; };
	void set_c(int c_) { c = c_; };
	int findsize(std::string Str) {
		int i = 0, count = 0;
		while (Str[i]) {
			count++;
			i++;
		}
		return count;
	}
};

class writer : public interface_readerWriter {
public:
	void reader_init() {};
	void writer_init() {
		std::cout << "Writing init" << std::endl;
	}
	void writetofile(std::string S) {
		std::cout << "Writing to file" << S << std::endl;
	}
	void writetoUART(std::string S) {
		std::cout << "Writing to UART" << S << std::endl;
	}
	void writetoUSB(std::string S) {
		std::cout << "Writing to USB" << S << std::endl;
	}
};


int main()
{
	reader R;
	writer W;
	parser p;
	R.reader_init();
	p.reader(R.readfromfile());
	R.readFromUART();
	std::cout << "a = " << p.get_a() << " b = " << p.get_b() << " c = " << p.get_c() << std::endl;
}

