<?php
/**
 * @copyright 2011-2012 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 */
$text = isset($_GET['location']['text']) ? View::escape($_GET['location']['text']) : '';
?>
<div class="findDescriptiveLocationForm">
	<form method="get" action="<?php echo BASE_URL; ?>/locations">
		<fieldset><legend>Find a descriptive location</legend>
			<input name="location[text]" id="location-text" value="<?php echo $text; ?>" />
			<?php
				// Preserve any extra parameters passed in
				foreach ($_REQUEST as $key=>$value) {
					if ($key != 'location') {
						$key = View::escape($key);
						$value = View::escape($value);
						echo "<input type=\"hidden\" name=\"$key\" value=\"$value\" />\n";
					}
				}
			?>
			<button type="submit" class="submit">Submit</button>
		</fieldset>
	</form>
</div>