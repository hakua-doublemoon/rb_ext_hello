#include <stdio.h>

#include <ruby.h>

static VALUE Hello_say(VALUE self)
{
    return rb_str_new("Hello World", 11);
}

void Init_Hello(void)
{
    VALUE cHello = rb_define_class("Hello", rb_cObject);
    
    rb_define_method(cHello, "say", Hello_say, 0);
}

