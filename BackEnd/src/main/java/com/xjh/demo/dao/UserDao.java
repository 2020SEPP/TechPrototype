package com.xjh.demo.dao;

public interface UserDao {
    public Boolean lookup(String phone);
    public Boolean register(String phone, String password);
}
