<?php
/**
 * @copyright 2011-2013 City of Bloomington, Indiana
 * @license http://www.gnu.org/licenses/agpl.txt GNU/AGPL, see LICENSE.txt
 * @author Cliff Ingham <inghamn@bloomington.in.gov>
 * @param MediaList $this->mediaList
 * @param bool $this->disableButtons
 */
if (count($this->mediaList)) {
	echo "<table class=\"mediaList\">";
	foreach ($this->mediaList as $media) {
		$deleteButton = '';
		if (!$this->disableButtons) {
			$deleteButton = "
			<a class=\"delete button\" href=\"".BASE_URI."/media/delete?media_id={$media->getId()}\">
				Delete Attachment
			</a>
			";
		}
		echo "
		<tr><td><a href=\"{$media->getURL()}\" class=\"{$media->getExtension()}\">
					{$media->getFilename()}
				</a>
			</td>
			<td>{$media->getUploaded(DATE_FORMAT)}</td>
			<td>$deleteButton</td>
		</tr>
		";
	}
	echo "</table>";
}
