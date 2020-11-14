package com.xjh.demo.daoImpl;

import com.xjh.demo.dao.UserDao;
import com.xjh.demo.entity.User;
import com.xjh.demo.entity.UserMongo;
import com.xjh.demo.repository.UserMongoRepository;
import com.xjh.demo.repository.UserRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Repository;

@Repository
public class UserDaoImpl implements UserDao {
    @Autowired
    UserRepository userRepository;
    @Autowired
    UserMongoRepository userMongoRepository;
    @Override
    public Boolean lookup(String phone) {
        return false;
    }

    @Override
    public Boolean register(String phone, String password) {
        User user = new User();
        user.setPhone(phone);
        user.setPassword(password);
        userRepository.save(user);
        UserMongo userMongo = new UserMongo();
        userMongo.setId(user.getId());
        userMongoRepository.save(userMongo);
        return true;
    }
}
