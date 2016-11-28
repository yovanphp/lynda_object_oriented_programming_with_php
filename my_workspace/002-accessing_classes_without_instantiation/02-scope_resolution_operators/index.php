<?php

require 'class.Address.inc';

$address = new Address;
echo '<h2>Setting properties...</h2>';
$address->street_address_1 = '555 Fake Street';
$address->city_name = 'Townsville';
$address->subdivision_name = 'State';
$address->postal_code = '12345';
$address->country_name = 'United States of America';
echo '<tt><pre>' . var_export($address, TRUE) . '</pre></tt>';

echo '<h2>Displaying address...</h2>';
echo $address->display();

echo '<h2>Testing magic __get and __set</h2>';
unset($address->postal_code);
echo $address->display();

var_dump($address);

echo '<h2>testing address __construct with an array</h2>';
$address_2 = new Address([
		'street_address_1' => 'Avenue Surath',
		'street_address_2' => 'Belle-Rose',
		'city_name' => 'Quatre-Bornes',
		'subdivision_name' => 'Plaines-Wilhems',
		'postal_code' => '32500',
		'country_name' => 'Mauritius'
	]);

echo '<tt><pre>' . var_export($address_2, TRUE) . '</pre></tt>';

echo'<h2>Address__toString</h2>';
echo $address_2;

echo '<h2>Displaying address types</h2>';
echo '<tt><pre>' . var_export (Address::$valid_address_types, TRUE) . '</pre></tt>';

echo '<h2>Displaying address count</h2>';
echo 'Address count using static property: ' . Address::$address_count . '<br>';
echo 'Address count using static method: ' . Address::getCount() . '<br>';

