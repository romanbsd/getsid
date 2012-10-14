#include <unistd.h>
#include <ruby.h>

static VALUE proc_getsid(VALUE obj, VALUE pid)
{
    rb_secure(2);
    pid_t sid = getsid(NUM2PIDT(pid));
    if (sid < 0) {
        rb_sys_fail(0);
    }
    return PIDT2NUM(sid);
}

void Init_getsid(void)
{
    rb_define_module_function(rb_mProcess, "getsid", proc_getsid, 1);
}
