package com.ashish;
import jakarta.inject.Singleton;

@Singleton
public class MathServiceImpl implements MathService{
    @Override
    public Integer compute(Integer num){
        return num * 4;
    }
    public Integer add(Integer a , Integer b){
        return a+b;
    }
}