<?php
	class A{
		public $test="give_me_flag";
		public $command;
		public function __wakeup()
		{
			if($this->test=="give_me_flag"){
				echo "lalala";
			}
		}
		public function __call($a,$b){
			$this->test=$val[0];
		}
		public function __toString(){
			echo $this->test;
			return "gg";
		}
		public function __invoke(){
			$this->command=str_replace("system","",$this->command);
			@eval($this->command);
		}

	}
	class B{
		public $external;
		public $arg;
		public function __destruct(){
			$this->external->NOT_EXIST($this->arg);
		}
	}
	class C{
		public $t;
		public $o;
		public function __call($func,$arg1){
			$this->t->test=$arg1[0];
		}
		public function __toString(){
			$s=$this->o;
			return $s();
		}
	}
	class D{
		public $str;
		public $sentence="";

		public function __set($n,$v){
			if($this->sentence=="I need flag"){
				strtolower($this->str);
			}
		}
	}
	if(isset($_GET['ctfer'])){
		@unserialize($_GET['ctfer']);
	}else{
		highlight_file(__FILE__);
	}
?>