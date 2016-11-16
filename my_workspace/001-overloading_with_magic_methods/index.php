<?php 
require 'class.Address.inc';

$address = new Address;
$address->street_1 = '3, Rue des Champs';
$address->street_2 = 'Melville';
$address->postal_code = '25698';
$address->zip_code = '25698';
$address->city = 'Paris';
$address->country = 'France';

echo '<tt><pre>' . var_export($address, TRUE) . '</pre></tt>';

var_dump($address);

unset($address->country);
var_dump($address);