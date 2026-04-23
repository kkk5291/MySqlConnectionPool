#pragma once
//实现Mysql数据库的操作
#include <string>
#include <ctime>
#include <mysql.h>


class Connection
{
public:
	Connection();

	~Connection();

	bool connect(std::string ip,
		unsigned short port,
		std::string user,
		std::string password,
		std::string dbname);

	bool update(std::string sql);

	MYSQL_RES* query(std::string sql);

	//刷新一下连接的起始空闲时间
	void refreshAliveTime() { _alivetime = clock(); }
	//返回存活的时间
	clock_t getAliveTime() const { return _alivetime - clock(); }

private:
	MYSQL* _conn;		//表示和MySQL Server的一条连接
	clock_t _alivetime;	//记录进入空闲状态后的存活时间
};