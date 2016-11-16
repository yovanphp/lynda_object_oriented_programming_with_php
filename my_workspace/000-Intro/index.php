<?php
require 'class.Address.inc';

$address = new Address;
echo '<h2>Empty address object</h2>';
echo '<tt><pre>' . var_export($address, TRUE) . '</pre></tt>';

echo '<h2>Populated address object</h2>';
$address->street_1 = 'Avenue Surath';
$address->street_2 = 'Belle Rose';
$address->city = 'Quatre-Bornes';
$address->postal_code = '31401';
$address->zip_code = '31401';
// We cannot directly set not get these properties as they are defined as protected in the class.
// We can use magic methods to access them.
//$address->creation_date = time();
//$address->modification_date = time();
echo '<tt><pre></tt>' . var_export($address, TRUE) . '</pre></tt>';

echo '<h2>Display address</h2>';
echo $address->getReadable();