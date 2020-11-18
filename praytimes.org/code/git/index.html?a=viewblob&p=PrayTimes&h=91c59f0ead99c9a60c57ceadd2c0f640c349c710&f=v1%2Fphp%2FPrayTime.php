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
 &raquo; <a href="?a=summary&amp;p=PrayTimes">PrayTimes</a> : Blob 91c59f / <a href="?a=tree&amp;p=PrayTimes&amp;h=b23faa99cb9c02ed969c4dafcef6de57cb4b32bf&amp;hb=17ee68cff3d814bae3fcf7dc55beaf3e49909889&amp;f=v1">v1</a> / <a href="?a=tree&amp;p=PrayTimes&amp;h=be6b87be8f97134e4da77359af4cb3fe2ec3d22c&amp;hb=17ee68cff3d814bae3fcf7dc55beaf3e49909889&amp;f=v1/php">php</a> / <a href="?a=viewblob&amp;p=PrayTimes&amp;h=673041d7d7946221d98aa269a73b930ae6ff8468&amp;hb=17ee68cff3d814bae3fcf7dc55beaf3e49909889&amp;f=v1/php/PrayTime.php">PrayTime.php</a> </div>
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

<h2>Last commit for v1/php/PrayTime.php: <a href="?a=commit&amp;p=PrayTimes&amp;h=17ee68cff3d814bae3fcf7dc55beaf3e49909889">17ee68cff3d814bae3fcf7dc55beaf3e49909889</a></h2>
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

//--------------------- Copyright Block ----------------------
/*

PrayTime.php: Prayer Times Calculator (ver 1.2.2)
Copyright (C) 2007-2010 PrayTimes.org

Developer: Hamid Zarrabi-Zadeh
License: GNU General Public License, ver 3

TERMS OF USE:
    Permission is granted to use this code, with or
    without modification, in any website or application
    provided that credit is given to the original work
    with a link back to PrayTimes.org.

This program is distributed in the hope that it will
be useful, but WITHOUT ANY WARRANTY.

PLEASE DO NOT REMOVE THIS COPYRIGHT BLOCK.

*/


//--------------------- Help and Manual ----------------------
/*

User's Manual:
http://praytimes.org/manual

Calculating Formulas:
http://praytimes.org/calculation



//------------------------ User Interface -------------------------


    getPrayerTimes (timestamp, latitude, longitude, timeZone)
    getDatePrayerTimes (year, month, day, latitude, longitude, timeZone)

    setCalcMethod (methodID)
    setAsrMethod (methodID)

    setFajrAngle (angle)
    setMaghribAngle (angle)
    setIshaAngle (angle)
    setDhuhrMinutes (minutes)    // minutes after mid-day
    setMaghribMinutes (minutes)  // minutes after sunset
    setIshaMinutes (minutes)     // minutes after maghrib

    setHighLatsMethod (methodID) // adjust method for higher latitudes

    setTimeFormat (timeFormat)
    floatToTime24 (time)
    floatToTime12 (time)
    floatToTime12NS (time)


//------------------------- Sample Usage --------------------------


    $prayTime-&gt;setCalcMethod($prayTime-&gt;ISNA);
    $times = $prayTime-&gt;getPrayerTimes(time(), 43, -80, -5);
    print('Sunrise = '. $times[1]);


*/


//--------------------- PrayTime Class -----------------------

class PrayTime
{

    //------------------------ Constants --------------------------


    // Calculation Methods
    var $Jafari     = 0;    // Ithna Ashari
    var $Karachi    = 1;    // University of Islamic Sciences, Karachi
    var $ISNA       = 2;    // Islamic Society of North America (ISNA)
    var $MWL        = 3;    // Muslim World League (MWL)
    var $Makkah     = 4;    // Umm al-Qura, Makkah
    var $Egypt      = 5;    // Egyptian General Authority of Survey
    var $Custom     = 6;    // Custom Setting
    var $Tehran     = 7;    // Institute of Geophysics, University of Tehran

    // Juristic Methods
    var $Shafii     = 0;    // Shafii (standard)
    var $Hanafi     = 1;    // Hanafi

    // Adjusting Methods for Higher Latitudes
    var $None       = 0;    // No adjustment
    var $MidNight   = 1;    // middle of night
    var $OneSeventh = 2;    // 1/7th of night
    var $AngleBased = 3;    // angle/60th of night


    // Time Formats
    var $Time24     = 0;    // 24-hour format
    var $Time12     = 1;    // 12-hour format
    var $Time12NS   = 2;    // 12-hour format with no suffix
    var $Float      = 3;    // floating point number

    // Time Names
    var $timeNames = array(
        'Fajr',
        'Sunrise',
        'Dhuhr',
        'Asr',
        'Sunset',
        'Maghrib',
        'Isha'
    );

    var $InvalidTime = '-----';     // The string used for invalid times


    //---------------------- Global Variables --------------------


    var $calcMethod   = 0;        // caculation method
    var $asrJuristic  = 0;        // Juristic method for Asr
    var $dhuhrMinutes = 0;        // minutes after mid-day for Dhuhr
    var $adjustHighLats = 1;    // adjusting method for higher latitudes

    var $timeFormat   = 0;        // time format

    var $lat;        // latitude
    var $lng;        // longitude
    var $timeZone;   // time-zone
    var $JDate;      // Julian date


    //--------------------- Technical Settings --------------------


    var $numIterations = 1;        // number of iterations needed to compute times


    //------------------- Calc Method Parameters --------------------


    var $methodParams = array();

    /*  var $methodParams[methodNum] = array(fa, ms, mv, is, iv);

            fa : fajr angle
            ms : maghrib selector (0 = angle; 1 = minutes after sunset)
            mv : maghrib parameter value (in angle or minutes)
            is : isha selector (0 = angle; 1 = minutes after maghrib)
            iv : isha parameter value (in angle or minutes)
    */


    //----------------------- Constructors -------------------------


    function PrayTime($methodID = 0)
    {

        $this-&gt;methodParams[$this-&gt;Jafari]    = array(16, 0, 4, 0, 14);
        $this-&gt;methodParams[$this-&gt;Karachi]   = array(18, 1, 0, 0, 18);
        $this-&gt;methodParams[$this-&gt;ISNA]      = array(15, 1, 0, 0, 15);
        $this-&gt;methodParams[$this-&gt;MWL]       = array(18, 1, 0, 0, 17);
        $this-&gt;methodParams[$this-&gt;Makkah]    = array(18.5, 1, 0, 1, 90);
        $this-&gt;methodParams[$this-&gt;Egypt]     = array(19.5, 1, 0, 0, 17.5);
        $this-&gt;methodParams[$this-&gt;Tehran]    = array(17.7, 0, 4.5, 0, 14);
        $this-&gt;methodParams[$this-&gt;Custom]    = array(18, 1, 0, 0, 17);

        $this-&gt;setCalcMethod($methodID);
    }

    function __construct($methodID = 0)
    {
        $this-&gt;PrayTime($methodID);
    }



    //-------------------- Interface Functions --------------------


    // return prayer times for a given date
    function getDatePrayerTimes($year, $month, $day, $latitude, $longitude, $timeZone)
    {
        $this-&gt;lat = $latitude;
        $this-&gt;lng = $longitude;
        $this-&gt;timeZone = $timeZone;
        $this-&gt;JDate = $this-&gt;julianDate($year, $month, $day)- $longitude/ (15* 24);
        return $this-&gt;computeDayTimes();
    }

    // return prayer times for a given timestamp
    function getPrayerTimes($timestamp, $latitude, $longitude, $timeZone)
    {
        $date = @getdate($timestamp);
        return $this-&gt;getDatePrayerTimes($date['year'], $date['mon'], $date['mday'],
                    $latitude, $longitude, $timeZone);
    }

    // set the calculation method
    function setCalcMethod($methodID)
    {
        $this-&gt;calcMethod = $methodID;
    }

    // set the juristic method for Asr
    function setAsrMethod($methodID)
    {
        if ($methodID &lt; 0 || $methodID &gt; 1)
            return;
        $this-&gt;asrJuristic = $methodID;
    }

    // set the angle for calculating Fajr
    function setFajrAngle($angle)
    {
        $this-&gt;setCustomParams(array($angle, null, null, null, null));
    }

    // set the angle for calculating Maghrib
    function setMaghribAngle($angle)
    {
        $this-&gt;setCustomParams(array(null, 0, $angle, null, null));
    }

    // set the angle for calculating Isha
    function setIshaAngle($angle)
    {
        $this-&gt;setCustomParams(array(null, null, null, 0, $angle));
    }

    // set the minutes after mid-day for calculating Dhuhr
    function setDhuhrMinutes($minutes)
    {
        $this-&gt;dhuhrMinutes = $minutes;
    }

    // set the minutes after Sunset for calculating Maghrib
    function setMaghribMinutes($minutes)
    {
        $this-&gt;setCustomParams(array(null, 1, $minutes, null, null));
    }

    // set the minutes after Maghrib for calculating Isha
    function setIshaMinutes($minutes)
    {
        $this-&gt;setCustomParams(array(null, null, null, 1, $minutes));
    }

    // set custom values for calculation parameters
    function setCustomParams($params)
    {
        for ($i=0; $i&lt;5; $i++)
        {
            if ($params[$i] == null)
                $this-&gt;methodParams[$this-&gt;Custom][$i] = $this-&gt;methodParams[$this-&gt;calcMethod][$i];
            else
                $this-&gt;methodParams[$this-&gt;Custom][$i] = $params[$i];
        }
        $this-&gt;calcMethod = $this-&gt;Custom;
    }

    // set adjusting method for higher latitudes
    function setHighLatsMethod($methodID)
    {
        $this-&gt;adjustHighLats = $methodID;
    }

    // set the time format
    function setTimeFormat($timeFormat)
    {
        $this-&gt;timeFormat = $timeFormat;
    }

    // convert float hours to 24h format
    function floatToTime24($time)
    {
        if (is_nan($time))
            return $this-&gt;InvalidTime;
        $time = $this-&gt;fixhour($time+ 0.5/ 60);  // add 0.5 minutes to round
        $hours = floor($time);
        $minutes = floor(($time- $hours)* 60);
        return $this-&gt;twoDigitsFormat($hours). ':'. $this-&gt;twoDigitsFormat($minutes);
    }

    // convert float hours to 12h format
    function floatToTime12($time, $noSuffix = false)
    {
        if (is_nan($time))
            return $this-&gt;InvalidTime;
        $time = $this-&gt;fixhour($time+ 0.5/ 60);  // add 0.5 minutes to round
        $hours = floor($time);
        $minutes = floor(($time- $hours)* 60);
        $suffix = $hours &gt;= 12 ? ' pm' : ' am';
        $hours = ($hours+ 12- 1)% 12+ 1;
        return $hours. ':'. $this-&gt;twoDigitsFormat($minutes). ($noSuffix ? '' : $suffix);
    }

    // convert float hours to 12h format with no suffix
    function floatToTime12NS($time)
    {
        return $this-&gt;floatToTime12($time, true);
    }



    //---------------------- Calculation Functions -----------------------

    // References:
    // http://www.ummah.net/astronomy/saltime
    // http://aa.usno.navy.mil/faq/docs/SunApprox.html


    // compute declination angle of sun and equation of time
    function sunPosition($jd)
    {
        $D = $jd - 2451545.0;
        $g = $this-&gt;fixangle(357.529 + 0.98560028* $D);
        $q = $this-&gt;fixangle(280.459 + 0.98564736* $D);
        $L = $this-&gt;fixangle($q + 1.915* $this-&gt;dsin($g) + 0.020* $this-&gt;dsin(2*$g));

        $R = 1.00014 - 0.01671* $this-&gt;dcos($g) - 0.00014* $this-&gt;dcos(2*$g);
        $e = 23.439 - 0.00000036* $D;

        $d = $this-&gt;darcsin($this-&gt;dsin($e)* $this-&gt;dsin($L));
        $RA = $this-&gt;darctan2($this-&gt;dcos($e)* $this-&gt;dsin($L), $this-&gt;dcos($L))/ 15;
        $RA = $this-&gt;fixhour($RA);
        $EqT = $q/15 - $RA;

        return array($d, $EqT);
    }

    // compute equation of time
    function equationOfTime($jd)
    {
        $sp = $this-&gt;sunPosition($jd);
        return $sp[1];
    }

    // compute declination angle of sun
    function sunDeclination($jd)
    {
        $sp = $this-&gt;sunPosition($jd);
        return $sp[0];
    }

    // compute mid-day (Dhuhr, Zawal) time
    function computeMidDay($t)
    {
        $T = $this-&gt;equationOfTime($this-&gt;JDate+ $t);
        $Z = $this-&gt;fixhour(12- $T);
        return $Z;
    }

    // compute time for a given angle G
    function computeTime($G, $t)
    {
        $D = $this-&gt;sunDeclination($this-&gt;JDate+ $t);
        $Z = $this-&gt;computeMidDay($t);
        $V = 1/15* $this-&gt;darccos((-$this-&gt;dsin($G)- $this-&gt;dsin($D)* $this-&gt;dsin($this-&gt;lat))/
                ($this-&gt;dcos($D)* $this-&gt;dcos($this-&gt;lat)));
        return $Z+ ($G&gt;90 ? -$V : $V);
    }

    // compute the time of Asr
    function computeAsr($step, $t)  // Shafii: step=1, Hanafi: step=2
    {
        $D = $this-&gt;sunDeclination($this-&gt;JDate+ $t);
        $G = -$this-&gt;darccot($step+ $this-&gt;dtan(abs($this-&gt;lat- $D)));
        return $this-&gt;computeTime($G, $t);
    }


    //---------------------- Compute Prayer Times -----------------------


    // compute prayer times at given julian date
    function computeTimes($times)
    {
        $t = $this-&gt;dayPortion($times);

        $Fajr    = $this-&gt;computeTime(180- $this-&gt;methodParams[$this-&gt;calcMethod][0], $t[0]);
        $Sunrise = $this-&gt;computeTime(180- 0.833, $t[1]);
        $Dhuhr   = $this-&gt;computeMidDay($t[2]);
        $Asr     = $this-&gt;computeAsr(1+ $this-&gt;asrJuristic, $t[3]);
        $Sunset  = $this-&gt;computeTime(0.833, $t[4]);;
        $Maghrib = $this-&gt;computeTime($this-&gt;methodParams[$this-&gt;calcMethod][2], $t[5]);
        $Isha    = $this-&gt;computeTime($this-&gt;methodParams[$this-&gt;calcMethod][4], $t[6]);

        return array($Fajr, $Sunrise, $Dhuhr, $Asr, $Sunset, $Maghrib, $Isha);
    }


    // compute prayer times at given julian date
    function computeDayTimes()
    {
        $times = array(5, 6, 12, 13, 18, 18, 18); //default times

        for ($i=1; $i&lt;=$this-&gt;numIterations; $i++)
            $times = $this-&gt;computeTimes($times);

        $times = $this-&gt;adjustTimes($times);
        return $this-&gt;adjustTimesFormat($times);
    }


    // adjust times in a prayer time array
    function adjustTimes($times)
    {
        for ($i=0; $i&lt;7; $i++)
            $times[$i] += $this-&gt;timeZone- $this-&gt;lng/ 15;
        $times[2] += $this-&gt;dhuhrMinutes/ 60; //Dhuhr
        if ($this-&gt;methodParams[$this-&gt;calcMethod][1] == 1) // Maghrib
            $times[5] = $times[4]+ $this-&gt;methodParams[$this-&gt;calcMethod][2]/ 60;
        if ($this-&gt;methodParams[$this-&gt;calcMethod][3] == 1) // Isha
            $times[6] = $times[5]+ $this-&gt;methodParams[$this-&gt;calcMethod][4]/ 60;

        if ($this-&gt;adjustHighLats != $this-&gt;None)
            $times = $this-&gt;adjustHighLatTimes($times);
        return $times;
    }


    // convert times array to given time format
    function adjustTimesFormat($times)
    {
        if ($this-&gt;timeFormat == $this-&gt;Float)
            return $times;
        for ($i=0; $i&lt;7; $i++)
            if ($this-&gt;timeFormat == $this-&gt;Time12)
                $times[$i] = $this-&gt;floatToTime12($times[$i]);
            else if ($this-&gt;timeFormat == $this-&gt;Time12NS)
                $times[$i] = $this-&gt;floatToTime12($times[$i], true);
            else
                $times[$i] = $this-&gt;floatToTime24($times[$i]);
        return $times;
    }


    // adjust Fajr, Isha and Maghrib for locations in higher latitudes
    function adjustHighLatTimes($times)
    {
        $nightTime = $this-&gt;timeDiff($times[4], $times[1]); // sunset to sunrise

        // Adjust Fajr
        $FajrDiff = $this-&gt;nightPortion($this-&gt;methodParams[$this-&gt;calcMethod][0])* $nightTime;
        if (is_nan($times[0]) || $this-&gt;timeDiff($times[0], $times[1]) &gt; $FajrDiff)
            $times[0] = $times[1]- $FajrDiff;

        // Adjust Isha
        $IshaAngle = ($this-&gt;methodParams[$this-&gt;calcMethod][3] == 0) ? $this-&gt;methodParams[$this-&gt;calcMethod][4] : 18;
        $IshaDiff = $this-&gt;nightPortion($IshaAngle)* $nightTime;
        if (is_nan($times[6]) || $this-&gt;timeDiff($times[4], $times[6]) &gt; $IshaDiff)
            $times[6] = $times[4]+ $IshaDiff;

        // Adjust Maghrib
        $MaghribAngle = ($this-&gt;methodParams[$this-&gt;calcMethod][1] == 0) ? $this-&gt;methodParams[$this-&gt;calcMethod][2] : 4;
        $MaghribDiff = $this-&gt;nightPortion($MaghribAngle)* $nightTime;
        if (is_nan($times[5]) || $this-&gt;timeDiff($times[4], $times[5]) &gt; $MaghribDiff)
            $times[5] = $times[4]+ $MaghribDiff;

        return $times;
    }


    // the night portion used for adjusting times in higher latitudes
    function nightPortion($angle)
    {
        if ($this-&gt;adjustHighLats == $this-&gt;AngleBased)
            return 1/60* $angle;
        if ($this-&gt;adjustHighLats == $this-&gt;MidNight)
            return 1/2;
        if ($this-&gt;adjustHighLats == $this-&gt;OneSeventh)
            return 1/7;
    }


    // convert hours to day portions
    function dayPortion($times)
    {
        for ($i=0; $i&lt;7; $i++)
            $times[$i] /= 24;
        return $times;
    }



    //---------------------- Misc Functions -----------------------


    // compute the difference between two times
    function timeDiff($time1, $time2)
    {
        return $this-&gt;fixhour($time2- $time1);
    }


    // add a leading 0 if necessary
    function twoDigitsFormat($num)
    {
        return ($num &lt;10) ? '0'. $num : $num;
    }



    //---------------------- Julian Date Functions -----------------------


    // calculate julian date from a calendar date
    function julianDate($year, $month, $day)
    {
        if ($month &lt;= 2)
        {
            $year -= 1;
            $month += 12;
        }
        $A = floor($year/ 100);
        $B = 2- $A+ floor($A/ 4);

        $JD = floor(365.25* ($year+ 4716))+ floor(30.6001* ($month+ 1))+ $day+ $B- 1524.5;
        return $JD;
    }


    // convert a calendar date to julian date (second method)
    function calcJD($year, $month, $day)
    {
        $J1970 = 2440588.0;
        $date = $year. '-'. $month. '-'. $day;
        $ms = strtotime($date);   // # of milliseconds since midnight Jan 1, 1970
        $days = floor($ms/ (1000 * 60 * 60* 24));
        return $J1970+ $days- 0.5;
    }


    //---------------------- Trigonometric Functions -----------------------

    // degree sin
    function dsin($d)
    {
        return sin($this-&gt;dtr($d));
    }

    // degree cos
    function dcos($d)
    {
        return cos($this-&gt;dtr($d));
    }

    // degree tan
    function dtan($d)
    {
        return tan($this-&gt;dtr($d));
    }

    // degree arcsin
    function darcsin($x)
    {
        return $this-&gt;rtd(asin($x));
    }

    // degree arccos
    function darccos($x)
    {
        return $this-&gt;rtd(acos($x));
    }

    // degree arctan
    function darctan($x)
    {
        return $this-&gt;rtd(atan($x));
    }

    // degree arctan2
    function darctan2($y, $x)
    {
        return $this-&gt;rtd(atan2($y, $x));
    }

    // degree arccot
    function darccot($x)
    {
        return $this-&gt;rtd(atan(1/$x));
    }

    // degree to radian
    function dtr($d)
    {
        return ($d * M_PI) / 180.0;
    }

    // radian to degree
    function rtd($r)
    {
        return ($r * 180.0) / M_PI;
    }

    // range reduce angle in degrees.
    function fixangle($a)
    {
        $a = $a - 360.0 * floor($a / 360.0);
        $a = $a &lt; 0 ? $a + 360.0 : $a;
        return $a;
    }

    // range reduce hours to 0..23
    function fixhour($a)
    {
        $a = $a - 24.0 * floor($a / 24.0);
        $a = $a &lt; 0 ? $a + 24.0 : $a;
        return $a;
    }

}

//---------------------- prayTime Object -----------------------

$prayTime = new PrayTime();

?&gt;</pre>
</div>
<div class="ad"><a href="http://viewgit.sourceforge.net/" title="Visit the ViewGit homepage">ViewGit</a></div></div>
</body>
</html>
