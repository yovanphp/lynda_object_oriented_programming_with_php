<?php

class AddressResidence extends Address {
	/**
	 * Initializer
	 */
	protected function _init() {
		$this -> _setAddressTypeId(Address::ADDRESS_TYPE_RESIDENCE);
	}
}