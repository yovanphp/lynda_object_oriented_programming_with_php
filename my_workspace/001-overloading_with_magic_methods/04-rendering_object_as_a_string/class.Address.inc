<?php 
class Address {
  public $street_address_1;
  public $street_address_2;
  public $city_name;
  public $subdivision_name;
  protected $_postal_code;
  public $country_name;

  protected $_id;
  protected $_time_created;
  protected $_time_updated;

  function __construct($data=[]) {
    $this->_time_created = time();

    if(!is_array($data))
      trigger_error('Unable to construct address with a ' . get_class($name));

    if(count($data) > 0) {
      foreach($data as $name => $value) {
        if(in_array($name, ['time_created', 'time_updated'])) {
          $name = '_' . $name;
        }
        $this->$name = $value;
      }
    }
  }
   
   /**
   * Magic __get.
   * @param string $name 
   * @return mixed
   */
  function __get($name) {
    // Postal code lookup if unset.
    if (!$this->_postal_code) {
      $this->_postal_code = $this->_postal_code_guess();
    }
    
    // Attempt to return a protected property by name.
    $protected_property_name = '_' . $name;
    if (property_exists($this, $protected_property_name)) {
      return $this->$protected_property_name;
    }
    
    // Unable to access property; trigger error.
    trigger_error('Undefined property via __get: ' . $name);
    return NULL;
  }
  
  /**
   * Magic __set.
   * @param string $name
   * @param mixed $value 
   */
  function __set($name, $value) {
    // Allow anything to set the postal code.
    if ('postal_code' == $name) {
      $this->$name = $value;
      return;
    }
    
    // Unable to access property; trigger error.
    trigger_error('Undefined or unallowed property via __set(): ' . $name);
  }
  
  /**
   * Guess the postal code given the subdivision and city name.
   * @todo Replace with a database lookup.
   * @return string 
   */
  protected function _postal_code_guess() {
    return 'LOOKUP';
  }
	
	/**
   * Display an address in HTML.
   * @return string 
   */
  function display() {
    $output = '';
    $output .= $this->street_address_1;
    if ($this->street_address_2) {
      $output .= '<br/>' . $this->street_address_2;
    }
    $output .= '<br/>';
    $output .= $this->city_name . ', ' . $this->subdivision_name;
    $output .= ' ' . $this->postal_code;
    $output .= '<br/>';
    $output .= $this->country_name;
    return $output;
  }

  function __toString() {
    return $this->display();
  }

}
