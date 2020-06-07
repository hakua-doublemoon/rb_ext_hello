#include <stdio.h>

#include <ruby.h>

#define SIZE_OF_HELLO_WORD (10)
static char hello_word[SIZE_OF_HELLO_WORD];


static VALUE Hello_say(VALUE self)
{
    return rb_str_new("Hello World", 11);
}

static VALUE Hello_word_set(VALUE self, VALUE word)
{
    char* in_word = RSTRING_PTR(word);
    strncpy(hello_word, in_word, SIZE_OF_HELLO_WORD-1);
    hello_word[SIZE_OF_HELLO_WORD-1] = '\0';
    return Qnil;
}

static VALUE Hello_word_get(VALUE self)
{
    return rb_str_new(hello_word, SIZE_OF_HELLO_WORD);
}

void Init_Hello(void)
{
    VALUE cHello = rb_define_class("Hello", rb_cObject);
    
    rb_define_method(cHello, "say", Hello_say, 0);
    rb_define_method(cHello, "word_set", Hello_word_set, 1);
    rb_define_method(cHello, "word_get", Hello_word_get, 0);
   
    rb_global_variable((VALUE*)(char*)hello_word);
}

