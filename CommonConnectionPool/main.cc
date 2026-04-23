#include <iostream>
#include "Connection.h"
#include "CommonConnectionPool.h"

int main()
{
	//插入一条sql语句测试
	/*Connection conn;
	char sql[1024] = { 0 };
	sprintf(sql, "insert into user(name,age,sex) values ('%s',%d,'%s')",
		"zhangsan", 20, "male");
	conn.connect("127.0.0.1", 3306, "root", "123456", "chat");
	conn.update(sql);*/


	clock_t begin = clock();



	//不使用连接池测试
	/*for (int i = 0; i < 1000; ++i)
	{
		Connection conn;
		char sql[1024] = { 0 };
		sprintf(sql, "insert into user(name,age,sex) values ('%s',%d,'%s')",
			"zhangsan", 20, "male");
		conn.connect("127.0.0.1", 3306, "root", "123456", "chat");
		conn.update(sql);
	}*/

	//不使用连接池 四线程测试
	/*Connection conn;
	conn.connect("127.0.0.1", 3306, "root", "123456", "chat");
	std::thread t1([]() {
		for (int i = 0; i < 2500; ++i)
		{
			Connection conn;
			char sql[1024] = { 0 };
			sprintf(sql, "insert into user(name,age,sex) values ('%s',%d,'%s')",
				"zhangsan", 20, "male");
			conn.connect("127.0.0.1", 3306, "root", "123456", "chat");
			conn.update(sql);
		}
	});

	std::thread t2([]() {
		for (int i = 0; i < 2500; ++i)
		{
			Connection conn;
			char sql[1024] = { 0 };
			sprintf(sql, "insert into user(name,age,sex) values ('%s',%d,'%s')",
				"zhangsan", 20, "male");
			conn.connect("127.0.0.1", 3306, "root", "123456", "chat");
			conn.update(sql);
		}
	});

	std::thread t3([]() {
		for (int i = 0; i < 2500; ++i)
		{
			Connection conn;
			char sql[1024] = { 0 };
			sprintf(sql, "insert into user(name,age,sex) values ('%s',%d,'%s')",
				"zhangsan", 20, "male");
			conn.connect("127.0.0.1", 3306, "root", "123456", "chat");
			conn.update(sql);
		}
	});

	std::thread t4([]() {
		for (int i = 0; i < 2500; ++i)
		{
			Connection conn;
			char sql[1024] = { 0 };
			sprintf(sql, "insert into user(name,age,sex) values ('%s',%d,'%s')",
				"zhangsan", 20, "male");
			conn.connect("127.0.0.1", 3306, "root", "123456", "chat");
			conn.update(sql);
		}
	});


	t1.join();
	t2.join();
	t3.join();
	t4.join();*/

	//使用连接池测试
	/*ConnectionPool* cp = ConnectionPool::getConnectionPool();
	for (int i = 0; i < 10000; ++i)
	{
		std::shared_ptr<Connection> sp = cp->getConnection();
		char sql[1024] = { 0 };
		sprintf(sql, "insert into user(name,age,sex) values ('%s',%d,'%s')",
			"zhangsan", 20, "male");
		sp->update(sql);
	}*/

	//使用连接池 四线程测试
	/*std::thread t1([]() {
		ConnectionPool* cp = ConnectionPool::getConnectionPool();
		for (int i = 0; i < 2500; ++i)
		{
			char sql[1024] = { 0 };
			sprintf(sql, "insert into user(name,age,sex) values ('%s',%d,'%s')",
				"zhangsan", 20, "male");
			std::shared_ptr<Connection> sp = cp->getConnection();
			sp->update(sql);
		}
		});

	std::thread t2([]() {
		ConnectionPool* cp = ConnectionPool::getConnectionPool();
		for (int i = 0; i < 2500; ++i)
		{
			char sql[1024] = { 0 };
			sprintf(sql, "insert into user(name,age,sex) values ('%s',%d,'%s')",
				"zhangsan", 20, "male");
			std::shared_ptr<Connection> sp = cp->getConnection();
			sp->update(sql);
		}
		});

	std::thread t3([]() {
		ConnectionPool* cp = ConnectionPool::getConnectionPool();
		for (int i = 0; i < 2500; ++i)
		{
			char sql[1024] = { 0 };
			sprintf(sql, "insert into user(name,age,sex) values ('%s',%d,'%s')",
				"zhangsan", 20, "male");
			std::shared_ptr<Connection> sp = cp->getConnection();
			sp->update(sql);
		}
		});

	std::thread t4([]() {
		ConnectionPool* cp = ConnectionPool::getConnectionPool();
		for (int i = 0; i < 2500; ++i)
		{
			char sql[1024] = { 0 };
			sprintf(sql, "insert into user(name,age,sex) values ('%s',%d,'%s')",
				"zhangsan", 20, "male");
			std::shared_ptr<Connection> sp = cp->getConnection();
			sp->update(sql);
		}
		});

	

	t1.join();
	t2.join();
	t3.join();
	t4.join();*/



	clock_t end = clock();
	std::cout << end - begin << "ms" << std::endl;

	return 0;
}