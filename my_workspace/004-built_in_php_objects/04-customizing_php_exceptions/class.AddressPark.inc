<?php

class AddressPark extends Address {
	public $country_name = 'Australia';

	/**
	 * Initializer
	 */
	protected function _init() {
		$this -> _setAddressTypeId(Address::ADDRESS_TYPE_PARK);
	}

	public function display() {
		$output = '<div style="background-color: PaleGreen;">';
		$output .= parent::display();
		$output .= '</div>';
		return $output;
	}
}