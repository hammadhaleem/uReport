<?php
/**
 * @copyright 2011-2012 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 * @param Category $this->category
 */
echo "
<service_definition>
	<service_code>{$this->category->getId()}</service_code>
	<attributes>
";
	$customFields = $this->category->getCustomFields();
	if ($customFields) {
		foreach ($customFields as $i=>$d) {
			$order = $i+1;
			$code  = View::escape($d->name);
			$datatype    = isset($d->type)     ? View::escape($d->type)  : 'string';
			$description = isset($d->label)    ? View::escape($d->label) : $code;
			$required    = isset($d->required) ? $d->required            : false;
			$required = $required ? "true" : "false";
			echo "
			<attribute>
				<variable>true</variable>
				<code>$code</code>
				<order>$order</order>
				<datatype>$datatype</datatype>
				<datatype_description></datatype_description>
				<required>$required</required>
				<description>$description</description>
			";
				if (isset($d->values)) {
					echo '<values>';
					foreach ($d->values as $value) {
						$value = View::escape($value);
						echo "
						<value>
							<key>$value</key>
							<name>$value</name>
						</value>
						";
					}
					echo '</values>';
				}
			echo "
			</attribute>
			";
		}
	}
echo "
	</attributes>
</service_definition>
";