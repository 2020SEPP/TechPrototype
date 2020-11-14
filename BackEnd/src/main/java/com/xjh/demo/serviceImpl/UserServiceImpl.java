package com.xjh.demo.serviceImpl;

import com.xjh.demo.dao.UserDao;
import com.xjh.demo.service.UserService;
import com.xjh.demo.utils.UserUtil;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class UserServiceImpl implements UserService {
    @Autowired
    UserDao userDao;
    @Override
    public UserUtil login(String phone, String password) {
        return null;
    }

    @Override
    public Boolean register(String phone, String password) {
        if(userDao.lookup(phone)) return false;
        return userDao.register(phone, password);
    }

}
