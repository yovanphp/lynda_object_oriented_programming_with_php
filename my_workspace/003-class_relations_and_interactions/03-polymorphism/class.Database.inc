<?php
/**
 * MySQLi database; Only one connection is allowed.
 */

class Database {
	private $_connection;
	private static $_instance;

	/**
	 * Get an instance of the Database
	 * @return {[type]} [description]
	 */
	public static function getInstance () {
		if(!self::$_instance) {
			self::$_instance = new self();
		}
		return self::$_instance;
	}

	/**
	 * Constructor: setting our connection
	 * @return {[type]} [description]
	 */
	public function __construct () {
		$this->connection = new Mysqli( 'localhost', 'yovan', '12345678', 'lms');
		if (mysqli_connect_errno()) {
			trigger_error('Failed to connect to MySQL: ' . mysqli_connect_error(), E_USER_ERROR);
		}
	}

	/**
	 * Empty clone magic method to prevent cloning
	 */
	private function __clone() {}

	/**
	 * Get the MySQLi connection.
	 */
	public function getConnection() {
		return $this->connection;
	}

}