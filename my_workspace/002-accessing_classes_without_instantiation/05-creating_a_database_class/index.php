<?php

require 'class.Address.inc';
require 'class.Database.inc';

echo '<h2>Postal Code from the database</h2>';
$address_2 = new Address([
		'street_address_1' => 'Avenue Surath',
		'street_address_2' => 'Belle-Rose',
		'city_name' => 'Quatre-Bornes',
		'subdivision_name' => 'Plaines-Wilhems',
		'country_name' => 'Mauritius',
		'address_type_id' => 1
	]);
echo $address_2;