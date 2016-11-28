<?php 

class LazyInit {
	protected $_property;

	function getProperty() {
		if(is_null($this->property)) {
			$this->property = 'Init';
		}
		return $this->property;
	}
}