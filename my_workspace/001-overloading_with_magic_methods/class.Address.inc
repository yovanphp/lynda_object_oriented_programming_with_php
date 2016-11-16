<?php 
class Address {
	public $street_1;
	public $street_2;
	public $city;
	public $postal_code;
	public $zip_code;
	public $country = 'Mauritius';

	protected $_id;
	protected $_creation_date;
	protected $modification_date;


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


/*
Overloading means to dynamically create a property or method that
	- has not been declared
	- or is not visible in the current scope

These dynamic properties are processed with "magic methods".
Magic methods names are prepended with two underscores.
Example: __construct() and __toSting()

By default magic methods are public so we don't need to declare them as such.

public properties cannot be modified by magic methods as the latter won't be trigged.

Magic methods are useful for example
 - for triggering custom behavior upon specific events such as accessing an unset property or calling a method that does not exist.
- for customizing the creation of an object and set defaults that are not available at runtime, such as the logged-in user or the current time.

Pbs with magic methods
- 3-20 times slower
- they ignore scope and hence may expose properties or methods that are normally hidden frm the rest of the program.
- Code completion in IDEs may broke as they assume that we are trying to access something that does not exist.

 */