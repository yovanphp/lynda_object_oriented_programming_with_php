<?php

/**
 * Define autoloader
 * @param  [type] $className [description]
 * @return [type]            [description]
 */
function __autoload($className) {
	include 'class.' . $className . '.inc';
}

echo '<h2>Instanciating residential address</h2>';
$address_residence = new AddressResidence([
		'street_address_1' => 'Avenue Surath',
		'street_address_2' => 'Belle-Rose',
		'city_name' => 'Quatre-Bornes',
		'subdivision_name' => 'Plaines-Wilhems',
		'country_name' => 'Mauritius'
	]);

echo '<tt><pre>' . var_export($address_residence, true) . '</pre></tt>';

echo '<h2>Instanciating park address</h2>';
$address_park = new AddressPark([
		'street_address_1' => '789 Missing Circle',
		'street_address_2' => 'Suite 0',
		'city_name' => 'Hamlet',
		'subdivision_name' => 'Territory'
	]);
echo '<tt><pre>' . var_export($address_park, true) . '</pre></tt>';

echo $address_park;

/********************************************************************/
echo '<h2>Cloning AddressPark</h2>';
//We defined the __clone() magic method, so == will fail too.
$address_park_clone = clone($address_park);
var_dump($address_park);
var_dump($address_park_clone);
echo $address_park_clone == $address_park ? 'Are equal. <br>' : 'Are not equal <br>';
echo $address_park_clone === $address_park ? 'Are equal and of the same instances of the class. <br>' : 'Are not of the same instance. <br>';