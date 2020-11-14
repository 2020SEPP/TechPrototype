package com.xjh.demo.entity;

import lombok.Data;
import org.springframework.data.mongodb.core.mapping.Document;

import java.util.List;

@Data
@Document(collation = "userMongo")
public class UserMongo {
    Integer id;
    List<Integer> friends;
}
