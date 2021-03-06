<?php
/**
 * @copyright 2011-2013 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 */
class Substatus extends ActiveRecord
{
	protected $tablename = 'substatus';
	/**
	 * Populates the object with data
	 *
	 * Passing in an associative array of data will populate this object without
	 * hitting the database.
	 *
	 * Passing in a scalar will load the data from the database.
	 * This will load all fields in the table as properties of this class.
	 * You may want to replace this with, or add your own extra, custom loading
	 *
	 * @param int|array $id
	 */
	public function __construct($id=null)
	{
		if ($id) {
			if (is_array($id)) {
				$result = $id;
			}
			else {
				$sql = ActiveRecord::isId($id)
					? 'select * from substatus where id=?'
					: 'select * from substatus where name=?';
				$zend_db = Database::getConnection();
				$result = $zend_db->fetchRow($sql, array($id));
			}

			if ($result) {
				$this->data = $result;
			}
			else {
				throw new Exception('substatus/unknownSubstatus');
			}
		}
		else {
			// This is where the code goes to generate a new, empty instance.
			// Set any default values for properties that need it here
			$this->setStatus('open');
		}
	}

	public function validate()
	{
		if (!$this->getName()) { throw new Exception('missingRequiredFields'); }
		if (!$this->getStatus()) { $this->setStatus('open'); }
	}

	public function save() { parent::save(); }

	//----------------------------------------------------------------
	// Generic Getters & Setters
	//----------------------------------------------------------------
	public function __toString()     { return parent::get('name');        }
	public function getId()          { return parent::get('id');          }
	public function getName()        { return parent::get('name');        }
	public function getDescription() { return parent::get('description'); }
	public function getStatus()      { return parent::get('status');      }

	public function setName       ($s) { parent::set('name',        $s); }
	public function setDescription($s) { parent::set('description', $s); }
	public function setStatus     ($s) { parent::set('status',      $s); }

	/**
	 * @param array $post
	 */
	public function handleUpdate($post)
	{
		$this->setName($post['name']);
		$this->setDescription($post['description']);
		$this->setStatus($post['status']);
	}
}
