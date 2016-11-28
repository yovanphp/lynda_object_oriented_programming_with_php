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


echo '<h2>Testing typecasting to an object</h2>';
$numbers = [1, 42, 153, 41, 57 , 126];
echo '<tt><pre>' . var_export((object) $numbers, true) . '</pre></tt>';

$employee_assoc = [
	'first_name' => 'Yovan',
	'last_name' => 'Juggoo',
	'age' => 33,
	'salary' => 200000,
	'friends' => [
		[
			'first_name' => 'John',
			'last_name' => 'Doe',
			'age' => 25,
			'hobby' => 'Scuba diving'
		],
		[
			'first_name' => 'Mary',
			'last_name' => 'Smith',
			'age' => 65,
			'hobby' => 'Salsa'
		]
	]
];

echo '<tt><pre>' . var_export((object) $employee_assoc, true) . '</pre></tt>';

$population = 78966513;
echo '<tt><pre>' . var_export((object) $population, true) . '</pre></tt>';

/********************************************************************/

echo '<h2>Loading from database</h2>';
$address_db = Address::load(1);
echo '<tt><pre>' . var_export($address_db, true) . '</pre></tt>';