<head>
	<meta charset="utf-8" />
	<link rel="stylesheet" type="text/css" href="<?php echo YUI; ?>/cssreset/cssreset-min.css" />
	<link rel="stylesheet" type="text/css" href="<?php echo YUI; ?>/cssfonts/fonts-min.css" />
	<?php
		if ($this->layout) {
			echo "<link rel=\"stylesheet\" type=\"text/css\" href=\"".BASE_URI."/skins/local/layouts/{$this->layout}.css\" />";
		}
	?>
	<link rel="stylesheet" type="text/css" href="<?php echo BASE_URI; ?>/skins/local/screen.css" />
	<link rel="stylesheet" type="text/css" href="<?php echo BASE_URI; ?>/skins/local/globals.css" />
	<script type="text/javascript">
		var CRM = {
			BASE_URL: '<?php echo BASE_URL; ?>'
		};
	</script>
	<title><?php echo $this->title ? View::escape($this->title) : APPLICATION_NAME; ?></title>
</head>
