package com.xjh.demo.entity;

import lombok.Data;
import org.hibernate.annotations.Proxy;

import javax.persistence.*;


@Entity
@Table(name="user", schema="pclogo")
@Proxy
@Data
public class User {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    @Column
    private Integer id;

    @Column
    private String phone;

    @Column
    private String password;
}
