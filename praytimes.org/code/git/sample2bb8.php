<? 
	// Prayer Time Calculator
	// By: Hamid Zarrabi-Zadeh
	// Inputs : $method, $year, $lat, $lng, $timeZone
	
	import_request_variables("gpc");
	include('PrayTime.php');

	if (!isset($method) || !isset($year) )
		list($method, $year, $lat, $lng, $timeZone) = array(0, 2007, 43, -80, -5);
?>
<html>
<head>
	<title>Prayer Timetable</title>
</head>
<style>
	pre {font-family: courier, serif, size: 10pt; margin: 0px 8px;}
</style>

<body>

<h1> Prayer Timetable </h1>
<form name=form method="post" action="" onSubmit="submit_form();">
<div style="padding:10px; background-color: #F8F7F4; border: 1px dashed #EAE9CD;">

	Latitude: <input type="text" value="<?= $lat ?>" id="latitude" size="4">
	Longitude: <input type="text" value="<?= $lng ?>" id="longitude" size="4">
	Time Zone: <input type="text" value="<?= $timeZone ?>" id="timezone" size="2"> 
	Year: <input type="text" value="<?= $year ?>" id="year" size="4"> <br>
	Method: 
	<select id="method" name="method" size="1">
		<option value="0">Shia Ithna-Ashari</option>
		<option value="1">University of Islamic Sciences, Karachi</option>
		<option value="2">Islamic Society of North America (ISNA)</option>
		<option value="3">Muslim World League (MWL)</option>
		<option value="4">Umm al-Qura, Makkah</option>
		<option value="5">Egyptian General Authority of Survey</option>
		<option value="7">Institute of Geophysics, University of Tehran</option>
    </select>	
	<input type="submit" value="Make Timetable" onclick="submit_form();">

</div>
</form>

<pre>
 Date   Fajr   Sunrise  Dhuhr    Asr   Sunset  Maghrib  Isha 
-------------------------------------------------------------
<?

	$prayTime = new PrayTime($method);

	$date = strtotime($year. '-1-1');
	$endDate = strtotime(($year+ 1). '-1-1');

	while ($date < $endDate)
	{
		$times = $prayTime->getPrayerTimes($date, $lat, $lng, $timeZone);
		$day = date('M d', $date);
		print $day. "\t". implode("\t", $times). "\n";
		$date += 24* 60* 60;  // next day
	}

?>
</pre>

<script type="text/javascript">

	function submit_form()
	{
		var lat = document.getElementById('latitude').value;
		var lng = document.getElementById('longitude').value;
		var timeZone = document.getElementById('timezone').value;
		var year = document.getElementById('year').value;
		var method = document.getElementById('method').value;
		var table = document.getElementById('timetable');
		var link = '<?= $PHP_SELF ?>'+ '?method='+ method+ '&year='+ year+ '&lat='+ lat+ '&lng='+ lng+ '&timeZone='+ timeZone;
		document.form.action = link;
		document.form.submit();
	}

	document.getElementById('method').selectedIndex = <?= $method ?>;

</script>

</body>
</html>



