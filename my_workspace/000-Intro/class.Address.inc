<?php
class Address {
	public $street_1;
	public $street_2;
	public $city;
	public $postal_code;
	public $zip_code;
	public $country = 'Mauritius';
	

	// These fields are marked as protected so that we cannot access them directly.
	// Manipulation of these fields is restricted to the class itself or anything associtated to it.
	// It is a good practice to prefix protected fields using an _
	protected $_id;
	protected $_creation_date;
	protected $_modification_date;

	// time() is not a constant. Its value is not set at compilation time but at runtime.
	// We can initialize our class member variables with CONSTANTS only. 
	//public $creation_date = time();


	public function getReadable() {
		return "[<br>&nbsp;Street: {$this->street_1}, "
		. ($this->street_2 ? "{$this->street_2}, " : "")
		. "<br>&nbsp;City: $this->city, "
		. "<br>&nbsp;Postal Code: $this->postal_code, "
		. "<br>&nbsp;Zip Code: $this->zip_code, "
		. "<br>&nbsp;Country: $this->country"
		. "<br>]";
	}
}