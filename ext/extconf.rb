require 'mkmf'
raise "getsid() is not supported on your platform" unless have_func("getsid")
create_makefile('getsid')
