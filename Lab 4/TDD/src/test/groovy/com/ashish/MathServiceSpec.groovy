package com.ashish;

import io.micronaut.test.extensions.spock.annotation.MicronautTest;
import jakarta.inject.Inject;
import spock.lang.Specification;
import spock.lang.Unroll;

@MicronautTest // Declares the test as a micronaut test

class MathserviceSpec extends Specification {
    @Inject
    MathService mathService; // Dependancy injection is used to supply the system under test

    @Unroll
    void "should compute #num times 4"(){
        when:
        def result = mathService.compute(num)
        then:
        result == expected
        where:
        num | expected
        2   | 8
        3   | 12
    }

    void "should add #a and #b"(){
        when:
        def addResult = mathService.add(a,b)
        then:
        addResult == expected
        where:
        a  | b  | expected
        5  | 6  |  11
        10 | 6  |  16
        5  | -1 |  4

    }

}