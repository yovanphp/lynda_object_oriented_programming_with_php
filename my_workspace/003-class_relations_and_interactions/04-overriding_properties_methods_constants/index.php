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

/*******************************************************/
echo '<h2>Instanciating park address</h2>';
$address_park = new AddressPark([
		'street_address_1' => '789 Missing Circle',
		'street_address_2' => 'Suite 0',
		'city_name' => 'Hamlet',
		'subdivision_name' => 'Territory'
	]);
echo '<tt><pre>' . var_export($address_park, true) . '</pre></tt>';

echo $address_park;