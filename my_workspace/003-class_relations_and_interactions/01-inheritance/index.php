<?php

require 'class.Address.inc';
require 'class.Database.inc';

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
		'country_name' => 'Mauritius',
		'address_type_id' => 1
	]);

echo '<tt><pre>' . var_export($address_residence, true) . '</pre></tt>';
