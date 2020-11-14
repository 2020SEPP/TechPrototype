package com.xjh.demo.repository;

import com.xjh.demo.entity.UserMongo;
import org.springframework.data.mongodb.repository.MongoRepository;

public interface UserMongoRepository extends MongoRepository<UserMongo, Integer> {
}
