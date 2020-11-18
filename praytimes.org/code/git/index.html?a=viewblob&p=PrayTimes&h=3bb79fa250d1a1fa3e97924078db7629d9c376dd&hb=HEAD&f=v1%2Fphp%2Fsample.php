<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">
<head>
	<title>PrayTimes - Blob - ViewGit</title>
	<link rel="stylesheet" href="default.css" type="text/css" />
	<link rel="icon" type="image/png" href="favicon.png" />
	<link rel="alternate" type="application/rss+xml" title="PrayTimes log" href="?a=rss-log&amp;p=PrayTimes" />
	<meta name="generator" content="ViewGit" />
</head>
<body>


<div class="nav">
<a href=".">Index</a>
 &raquo; <a href="?a=summary&amp;p=PrayTimes">PrayTimes</a> : Blob 3bb79f / <a href="?a=tree&amp;p=PrayTimes&amp;h=b23faa99cb9c02ed969c4dafcef6de57cb4b32bf&amp;hb=17ee68cff3d814bae3fcf7dc55beaf3e49909889&amp;f=v1">v1</a> / <a href="?a=tree&amp;p=PrayTimes&amp;h=be6b87be8f97134e4da77359af4cb3fe2ec3d22c&amp;hb=17ee68cff3d814bae3fcf7dc55beaf3e49909889&amp;f=v1/php">php</a> / <a href="?a=viewblob&amp;p=PrayTimes&amp;h=3bb79fa250d1a1fa3e97924078db7629d9c376dd&amp;hb=17ee68cff3d814bae3fcf7dc55beaf3e49909889&amp;f=v1/php/sample.php">sample.php</a> </div>
<div id="page_body">

<div class="pagenav">
<a href="?a=summary&amp;p=PrayTimes">Summary</a> | <a href="?a=shortlog&amp;p=PrayTimes">Shortlog</a> | <a href="?a=commit&amp;p=PrayTimes&amp;h=17ee68cff3d814bae3fcf7dc55beaf3e49909889">Commit</a> | <a href="?a=commitdiff&amp;p=PrayTimes&amp;h=17ee68cff3d814bae3fcf7dc55beaf3e49909889">Commitdiff</a> | <a href="?a=tree&amp;p=PrayTimes&amp;h=637f054682333b708187333b6a566223af62a6c7&amp;hb=17ee68cff3d814bae3fcf7dc55beaf3e49909889">Tree</a> | 
<form action="?" method="get" class="search">
<input type="hidden" name="a" value="search" />
<input type="hidden" name="p" value="PrayTimes" />
<input type="hidden" name="h" value="17ee68cff3d814bae3fcf7dc55beaf3e49909889" />
<select name="st">
	<option>commit</option>
	<option>change</option>
	<option>author</option>
	<option>committer</option>
</select>
<input type="text" name="s" />
</form>
</div>

<h2>Last commit for v1/php/sample.php: <a href="?a=commit&amp;p=PrayTimes&amp;h=17ee68cff3d814bae3fcf7dc55beaf3e49909889">17ee68cff3d814bae3fcf7dc55beaf3e49909889</a></h2>
<h1>All code licences changed to LGPL v3.0</h1>
<div class="authorinfo">
<a href="?a=search&amp;p=PrayTimes&amp;h=HEAD&amp;st=author&amp;s=Hamid">Hamid</a> [2012-07-05 10:38:10]</div>
<div class="commitmessage">
<pre>
All code licences changed to LGPL v3.0
</pre>
</div>
<div class="file">
<pre>
&lt;?php

	// Prayer Times Calculator, Sample Usage
	// By: Hamid Zarrabi-Zadeh
	// Inputs : $method, $year, $latitude, $longitude, $timeZone

	import_request_variables(&quot;p&quot;);
	include('PrayTime.php');

	if (!isset($method) || !isset($year) )
		list($method, $year, $latitude, $longitude, $timeZone) = array(0, 2007, 43, -80, -5);
?&gt;
&lt;html&gt;
&lt;head&gt;
	&lt;title&gt;Prayer Timetable&lt;/title&gt;
&lt;/head&gt;
&lt;style&gt;
	pre {font-family: courier, serif, size: 10pt; margin: 0px 8px;}
&lt;/style&gt;

&lt;body&gt;

&lt;h1&gt; Prayer Timetable &lt;/h1&gt;
&lt;form name=&quot;form&quot; method=&quot;post&quot; action=&quot;&lt;?php echo $PHP_SELF ?&gt;&quot;&gt;
&lt;div style=&quot;padding:10px; background-color: #F8F7F4; border: 1px dashed #EAE9CD;&quot;&gt;

	Latitude: &lt;input type=&quot;text&quot; value=&quot;&lt;?php echo $latitude ?&gt;&quot; name=&quot;latitude&quot; size=&quot;4&quot;&gt;
	Longitude: &lt;input type=&quot;text&quot; value=&quot;&lt;?php echo $longitude ?&gt;&quot; name=&quot;longitude&quot; size=&quot;4&quot;&gt;
	Time Zone: &lt;input type=&quot;text&quot; value=&quot;&lt;?php echo $timeZone ?&gt;&quot; name=&quot;timeZone&quot; size=&quot;2&quot;&gt;
	Year: &lt;input type=&quot;text&quot; value=&quot;&lt;?php echo $year ?&gt;&quot; name=&quot;year&quot; size=&quot;4&quot;&gt; &lt;br&gt;
	Method:
	&lt;select id=&quot;method&quot; name=&quot;method&quot; size=&quot;1&quot; onchange=&quot;document.form.submit()&quot;&gt;
		&lt;option value=&quot;0&quot;&gt;Shia Ithna-Ashari&lt;/option&gt;
		&lt;option value=&quot;1&quot;&gt;University of Islamic Sciences, Karachi&lt;/option&gt;
		&lt;option value=&quot;2&quot;&gt;Islamic Society of North America (ISNA)&lt;/option&gt;
		&lt;option value=&quot;3&quot;&gt;Muslim World League (MWL)&lt;/option&gt;
		&lt;option value=&quot;4&quot;&gt;Umm al-Qura, Makkah&lt;/option&gt;
		&lt;option value=&quot;5&quot;&gt;Egyptian General Authority of Survey&lt;/option&gt;
		&lt;option value=&quot;7&quot;&gt;Institute of Geophysics, University of Tehran&lt;/option&gt;
    &lt;/select&gt;
	&lt;input type=&quot;submit&quot; value=&quot;Make Timetable&quot;&gt;

&lt;/div&gt;
&lt;/form&gt;

&lt;pre&gt;
 Date   Fajr   Sunrise  Dhuhr    Asr   Sunset  Maghrib  Isha
-------------------------------------------------------------
&lt;?php

	$prayTime = new PrayTime($method);

	$date = strtotime($year. '-1-1');
	$endDate = strtotime(($year+ 1). '-1-1');

	while ($date &lt; $endDate)
	{
		$times = $prayTime-&gt;getPrayerTimes($date, $latitude, $longitude, $timeZone);
		$day = date('M d', $date);
		print $day. &quot;\t&quot;. implode(&quot;\t&quot;, $times). &quot;\n&quot;;
		$date += 24* 60* 60;  // next day
	}

?&gt;
&lt;/pre&gt;

&lt;script type=&quot;text/javascript&quot;&gt;

	var method = &lt;?php echo $method ?&gt;;
	document.getElementById('method').selectedIndex = Math.min(method, 6);

&lt;/script&gt;

&lt;/body&gt;
&lt;/html&gt;


</pre>
</div>
<div class="ad"><a href="http://viewgit.sourceforge.net/" title="Visit the ViewGit homepage">ViewGit</a></div></div>
</body>
</html>
