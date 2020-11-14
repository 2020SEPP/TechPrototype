package com.xjh.demo.service;

import com.xjh.demo.utils.UserUtil;


public interface UserService {
    UserUtil login(String phone, String password);
    Boolean register(String phone, String password);
}
