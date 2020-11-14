package com.xjh.demo.controller;

import com.xjh.demo.service.UserService;
import com.xjh.demo.utils.UserUtil;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;

@Controller
@ResponseBody
public class UserController {
    @Autowired
    UserService userService;
    
    @RequestMapping("/login")
    public UserUtil login(@RequestParam("phone") String phone, @RequestParam("password") String password)
    {
        return userService.login(phone, password);
    }
    @RequestMapping("/register")
    public Boolean register(@RequestParam("phone") String phone, @RequestParam("password") String password)
    {
        return userService.register(phone, password);
    }
}
