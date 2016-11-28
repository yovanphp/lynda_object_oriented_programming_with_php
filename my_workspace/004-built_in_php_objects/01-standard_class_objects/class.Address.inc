<?php 
abstract class Address implements Model {
  public static $valid_address_types = array(
    1 => 'Residence', 
    2 => 'Business',
    3 => 'Park'
  );

  const ADDRESS_TYPE_RESIDENCE = 1;
  const ADDRESS_TYPE_BUSINESS = 2;
  const ADDRESS_TYPE_PARK = 3;

  public static $address_count = 0;

  public $street_address_1;
  public $street_address_2;
  public $city_name;
  public $subdivision_name;
  protected $_postal_code;
  public $country_name;

  protected $_id;
  protected $_address_type_id;
  protected $_time_created;
  protected $_time_updated;


  /**
   * Post clone behaviour
   */
  function __clone() {
    // Hardcoded values for demostration only:
    $this->_time_created = 12345;
    $this->_time_updated = 67890;
  }

  function __construct($data=[]) {
    $this->_init();
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
    self::$address_count++;
  }

  public static function getCount() {
    return self::$address_count;
  }


  /**
   * Determine if an address type is valid
   * @param  {Integer}  $address_type_id  
   * @return {Boolean}
   */
  public static function isValidAddressTypeId($address_type_id) {
      return array_key_exists($address_type_id, self::$valid_address_types);
  }


  /**
   * if valid set the address type id
   * @param {int} $address_type_id 
   */
  protected function _setAddressTypeId($address_type_id) {
      if(self::isValidAddressTypeId($address_type_id)) {
          $this->_address_type_id = $address_type_id;
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
    $db = Database::getInstance();
    $mysqli = $db->getConnection();

    $query = "SELECT postal_code FROM addresses ";
    $query .= "WHERE city_name = '" . $mysqli->real_escape_string($this->city_name) . "' ";
    $query .= "AND subdivision_name = '" . $mysqli->real_escape_string($this->subdivision_name) . "' ";
    $query .= "LIMIT 1";

    $result_set = $mysqli->query($query);

    if($row = $result_set->fetch_assoc())
      return $row['postal_code'];
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


  // Force extending classes to implement init method 
  abstract protected function _init();

  /**
   * Load Address
   * @param  {integer} $address_id 
   */
  public static final function load($address_id) {

  }

  /**
   * Save Address
   */
  public final function save() {

  }

}
