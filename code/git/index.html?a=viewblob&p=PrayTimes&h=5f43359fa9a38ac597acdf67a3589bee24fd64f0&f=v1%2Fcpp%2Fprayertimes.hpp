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
 &raquo; <a href="?a=summary&amp;p=PrayTimes">PrayTimes</a> : Blob 5f4335 / <a href="?a=tree&amp;p=PrayTimes&amp;h=b23faa99cb9c02ed969c4dafcef6de57cb4b32bf&amp;hb=17ee68cff3d814bae3fcf7dc55beaf3e49909889&amp;f=v1">v1</a> / <a href="?a=tree&amp;p=PrayTimes&amp;h=671aeb697e9b7613a19d13fb8fe4def45f2c00a9&amp;hb=17ee68cff3d814bae3fcf7dc55beaf3e49909889&amp;f=v1/cpp">cpp</a> / <a href="?a=viewblob&amp;p=PrayTimes&amp;h=5f43359fa9a38ac597acdf67a3589bee24fd64f0&amp;hb=17ee68cff3d814bae3fcf7dc55beaf3e49909889&amp;f=v1/cpp/prayertimes.hpp">prayertimes.hpp</a> </div>
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

<h2>Last commit for v1/cpp/prayertimes.hpp: <a href="?a=commit&amp;p=PrayTimes&amp;h=17ee68cff3d814bae3fcf7dc55beaf3e49909889">17ee68cff3d814bae3fcf7dc55beaf3e49909889</a></h2>
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
/*-------------------------- In the name of God ----------------------------*\

    libprayertimes 1.0
    Islamic prayer times calculator library
    Based on PrayTimes 1.1 JavaScript library

----------------------------- Copyright Block --------------------------------

Copyright (C) 2007-2010 PrayTimes.org

Developed By: Mohammad Ebrahim Mohammadi Panah &lt;ebrahim at mohammadi dot ir&gt;
Based on a JavaScript Code By: Hamid Zarrabi-Zadeh

License: GNU LGPL v3.0

TERMS OF USE:
    Permission is granted to use this code, with or
    without modification, in any website or application
    provided that credit is given to the original work
    with a link back to PrayTimes.org.

This program is distributed in the hope that it will
be useful, but WITHOUT ANY WARRANTY.

PLEASE DO NOT REMOVE THIS COPYRIGHT BLOCK.

------------------------------------------------------------------------------

User's Manual:
http://praytimes.org/manual

Calculating Formulas:
http://praytimes.org/calculation

Code Repository:
http://code.ebrahim.ir/prayertimes/

\*--------------------------------------------------------------------------*/

#include &lt;cstdio&gt;
#include &lt;cmath&gt;
#include &lt;string&gt;

/* -------------------- PrayerTimes Class --------------------- */

class PrayerTimes
{
public:
	enum
	{
		VERSION_MAJOR = 1,
		VERSION_MINOR = 0,
	};
/* --------------------- User Interface ----------------------- */
/*
	PrayerTimes(CalculationMethod calc_method = Jafari,
			JuristicMethod asr_juristic = Shafii,
			AdjustingMethod adjust_high_lats = MidNight,
			double dhuhr_minutes = 0)

	get_prayer_times(date, latitude, longitude, timezone, &amp;times)
	get_prayer_times(year, month, day, latitude, longitude, timezone, &amp;times)

	set_calc_method(method_id)
	set_asr_method(method_id)
	set_high_lats_adjust_method(method_id)		// adjust method for higher latitudes

	set_fajr_angle(angle)
	set_maghrib_angle(angle)
	set_isha_angle(angle)
	set_dhuhr_minutes(minutes)		// minutes after mid-day
	set_maghrib_minutes(minutes)		// minutes after sunset
	set_isha_minutes(minutes)		// minutes after maghrib

	get_float_time_parts(time, &amp;hours, &amp;minutes)
	float_time_to_time24(time)
	float_time_to_time12(time)
	float_time_to_time12ns(time)
*/

	// Calculation Methods
	enum CalculationMethod
	{
		Jafari, 	// Ithna Ashari
		Karachi,	// University of Islamic Sciences, Karachi
		ISNA,   	// Islamic Society of North America (ISNA)
		MWL,    	// Muslim World League (MWL)
		Makkah, 	// Umm al-Qura, Makkah
		Egypt,  	// Egyptian General Authority of Survey
		Custom, 	// Custom Setting

		CalculationMethodsCount
	};

	// Juristic Methods
	enum JuristicMethod
	{
		Shafii,    // Shafii (standard)
		Hanafi,    // Hanafi
	};

	// Adjusting Methods for Higher Latitudes
	enum AdjustingMethod
	{
		None,      	// No adjustment
		MidNight,  	// middle of night
		OneSeventh,	// 1/7th of night
		AngleBased,	// angle/60th of night
	};

	// Time IDs
	enum TimeID
	{
		Fajr,
		Sunrise,
		Dhuhr,
		Asr,
		Sunset,
		Maghrib,
		Isha,

		TimesCount
	};

/* -------------------- Interface Functions -------------------- */

	PrayerTimes(CalculationMethod calc_method = Jafari,
			JuristicMethod asr_juristic = Shafii,
			AdjustingMethod adjust_high_lats = MidNight,
			double dhuhr_minutes = 0)
	: calc_method(calc_method)
	, asr_juristic(asr_juristic)
	, adjust_high_lats(adjust_high_lats)
	, dhuhr_minutes(dhuhr_minutes)
	{
		method_params[Jafari]  = MethodConfig(16.0, false, 4.0, false, 14.0);	// Jafari
		method_params[Karachi] = MethodConfig(18.0, true,  0.0, false, 18.0);	// Karachi
		method_params[ISNA]    = MethodConfig(15.0, true,  0.0, false, 15.0);	// ISNA
		method_params[MWL]     = MethodConfig(18.0, true,  0.0, false, 17.0);	// MWL
		method_params[Makkah]  = MethodConfig(19.0, true,  0.0, true,  90.0);	// Makkah
		method_params[Egypt]   = MethodConfig(19.5, true,  0.0, false, 17.5);	// Egypt
		method_params[Custom]  = MethodConfig(18.0, true,  0.0, false, 17.0);	// Custom
	}

	/* return prayer times for a given date */
	void get_prayer_times(int year, int month, int day, double _latitude, double _longitude, double _timezone, double times[])
	{
		latitude = _latitude;
		longitude = _longitude;
		timezone = _timezone;
		julian_date = get_julian_date(year, month, day) - longitude / (double) (15 * 24);
		compute_day_times(times);
	}

	/* return prayer times for a given date */
	void get_prayer_times(time_t date, double latitude, double longitude, double timezone, double times[])
	{
		tm* t = localtime(&amp;date);
		get_prayer_times(1900 + t-&gt;tm_year, t-&gt;tm_mon + 1, t-&gt;tm_mday, latitude, longitude, timezone, times);
	}

	/* set the calculation method  */
	void set_calc_method(CalculationMethod method_id)
	{
		calc_method = method_id;
	}

	/* set the juristic method for Asr */
	void set_asr_method(JuristicMethod method_id)
	{
		asr_juristic = method_id;
	}

	/* set adjusting method for higher latitudes */
	void set_high_lats_adjust_method(AdjustingMethod method_id)
	{
		adjust_high_lats = method_id;
	}

	/* set the angle for calculating Fajr */
	void set_fajr_angle(double angle)
	{
		method_params[Custom].fajr_angle = angle;
		calc_method = Custom;
	}

	/* set the angle for calculating Maghrib */
	void set_maghrib_angle(double angle)
	{
		method_params[Custom].maghrib_is_minutes = false;
		method_params[Custom].maghrib_value = angle;
		calc_method = Custom;
	}

	/* set the angle for calculating Isha */
	void set_isha_angle(double angle)
	{
		method_params[Custom].isha_is_minutes = false;
		method_params[Custom].isha_value = angle;
		calc_method = Custom;
	}

	/* set the minutes after mid-day for calculating Dhuhr */
	void set_dhuhr_minutes(double minutes)
	{
		dhuhr_minutes = minutes;
	}

	/* set the minutes after Sunset for calculating Maghrib */
	void set_maghrib_minutes(double minutes)
	{
		method_params[Custom].maghrib_is_minutes = true;
		method_params[Custom].maghrib_value = minutes;
		calc_method = Custom;
	}

	/* set the minutes after Maghrib for calculating Isha */
	void set_isha_minutes(double minutes)
	{
		method_params[Custom].isha_is_minutes = true;
		method_params[Custom].isha_value = minutes;
		calc_method = Custom;
	}

	/* get hours and minutes parts of a float time */
	static void get_float_time_parts(double time, int&amp; hours, int&amp; minutes)
	{
		time = fix_hour(time + 0.5 / 60);		// add 0.5 minutes to round
		hours = floor(time);
		minutes = floor((time - hours) * 60);
	}

	/* convert float hours to 24h format */
	static std::string float_time_to_time24(double time)
	{
		if (isnan(time))
			return std::string();
		int hours, minutes;
		get_float_time_parts(time, hours, minutes);
		return two_digits_format(hours) + ':' + two_digits_format(minutes);
	}

	/* convert float hours to 12h format */
	static std::string float_time_to_time12(double time, bool no_suffix = false)
	{
		if (isnan(time))
			return std::string();
		int hours, minutes;
		get_float_time_parts(time, hours, minutes);
		const char* suffix = hours &gt;= 12 ? &quot; PM&quot; : &quot; AM&quot;;
		hours = (hours + 12 - 1) % 12 + 1;
		return int_to_string(hours) + ':' + two_digits_format(minutes) + (no_suffix ? &quot;&quot; : suffix);
	}

	/* convert float hours to 12h format with no suffix */
	static std::string float_time_to_time12ns(double time)
	{
		return float_time_to_time12(time, true);
	}

/* ---------------------- Time-Zone Functions ----------------------- */

	/* compute local time-zone for a specific date */
	static double get_effective_timezone(time_t local_time)
	{
		tm* tmp = localtime(&amp;local_time);
		tmp-&gt;tm_isdst = 0;
		time_t local = mktime(tmp);
		tmp = gmtime(&amp;local_time);
		tmp-&gt;tm_isdst = 0;
		time_t gmt = mktime(tmp);
		return (local - gmt) / 3600.0;
	}

	/* compute local time-zone for a specific date */
	static double get_effective_timezone(int year, int month, int day)
	{
		tm date = { 0 };
		date.tm_year = year - 1900;
		date.tm_mon = month - 1;
		date.tm_mday = day;
		date.tm_isdst = -1;		// determine it yourself from system
		time_t local = mktime(&amp;date);		// seconds since midnight Jan 1, 1970
		return get_effective_timezone(local);
	}

private:
/* ------------------- Calc Method Parameters -------------------- */

	struct MethodConfig
	{
		MethodConfig()
		{
		}

		MethodConfig(double fajr_angle,
				bool maghrib_is_minutes,
				double maghrib_value,
				bool isha_is_minutes,
				double isha_value)
		: fajr_angle(fajr_angle)
		, maghrib_is_minutes(maghrib_is_minutes)
		, maghrib_value(maghrib_value)
		, isha_is_minutes(isha_is_minutes)
		, isha_value(isha_value)
		{
		}

		double fajr_angle;
		bool   maghrib_is_minutes;
		double maghrib_value;		// angle or minutes
		bool   isha_is_minutes;
		double isha_value;		// angle or minutes
	};

/* ---------------------- Calculation Functions ----------------------- */

	/* References: */
	/* http://www.ummah.net/astronomy/saltime   */
	/* http://aa.usno.navy.mil/faq/docs/SunApprox.html */

	typedef std::pair&lt;double, double&gt; DoublePair;

	/* compute declination angle of sun and equation of time */
	DoublePair sun_position(double jd)
	{
		double d = jd - 2451545.0;
		double g = fix_angle(357.529 + 0.98560028 * d);
		double q = fix_angle(280.459 + 0.98564736 * d);
		double l = fix_angle(q + 1.915 * dsin(g) + 0.020 * dsin(2 * g));

		// double r = 1.00014 - 0.01671 * dcos(g) - 0.00014 * dcos(2 * g);
		double e = 23.439 - 0.00000036 * d;

		double dd = darcsin(dsin(e) * dsin(l));
		double ra = darctan2(dcos(e) * dsin(l), dcos(l)) / 15.0;
		ra = fix_hour(ra);
		double eq_t = q / 15.0 - ra;

		return DoublePair(dd, eq_t);
	}

	/* compute equation of time */
	double equation_of_time(double jd)
	{
		return sun_position(jd).second;
	}

	/* compute declination angle of sun */
	double sun_declination(double jd)
	{
		return sun_position(jd).first;
	}

	/* compute mid-day (Dhuhr, Zawal) time */
	double compute_mid_day(double _t)
	{
		double t = equation_of_time(julian_date + _t);
		double z = fix_hour(12 - t);
		return z;
	}

	/* compute time for a given angle G */
	double compute_time(double g, double t)
	{
		double d = sun_declination(julian_date + t);
		double z = compute_mid_day(t);
		double v = 1.0 / 15.0 * darccos((-dsin(g) - dsin(d) * dsin(latitude)) / (dcos(d) * dcos(latitude)));
		return z + (g &gt; 90.0 ? - v :  v);
	}

	/* compute the time of Asr */
	double compute_asr(int step, double t)  // Shafii: step=1, Hanafi: step=2
	{
		double d = sun_declination(julian_date + t);
		double g = -darccot(step + dtan(fabs(latitude - d)));
		return compute_time(g, t);
	}

/* ---------------------- Compute Prayer Times ----------------------- */

	// array parameters must be at least of size TimesCount

	/* compute prayer times at given julian date */
	void compute_times(double times[])
	{
		day_portion(times);

		times[Fajr]    = compute_time(180.0 - method_params[calc_method].fajr_angle, times[Fajr]);
		times[Sunrise] = compute_time(180.0 - 0.833, times[Sunrise]);
		times[Dhuhr]   = compute_mid_day(times[Dhuhr]);
		times[Asr]     = compute_asr(1 + asr_juristic, times[Asr]);
		times[Sunset]  = compute_time(0.833, times[Sunset]);
		times[Maghrib] = compute_time(method_params[calc_method].maghrib_value, times[Maghrib]);
		times[Isha]    = compute_time(method_params[calc_method].isha_value, times[Isha]);
	}


	/* compute prayer times at given julian date */
	void compute_day_times(double times[])
	{
		double default_times[] = { 5, 6, 12, 13, 18, 18, 18 };		// default times
		for (int i = 0; i &lt; TimesCount; ++i)
			times[i] = default_times[i];

		for (int i = 0; i &lt; NUM_ITERATIONS; ++i)
			compute_times(times);

		adjust_times(times);
	}


	/* adjust times in a prayer time array */
	void adjust_times(double times[])
	{
		for (int i = 0; i &lt; TimesCount; ++i)
			times[i] += timezone - longitude / 15.0;
		times[Dhuhr] += dhuhr_minutes / 60.0;		// Dhuhr
		if (method_params[calc_method].maghrib_is_minutes)		// Maghrib
			times[Maghrib] = times[Sunset] + method_params[calc_method].maghrib_value / 60.0;
		if (method_params[calc_method].isha_is_minutes)		// Isha
			times[Isha] = times[Maghrib] + method_params[calc_method].isha_value / 60.0;

		if (adjust_high_lats != None)
			adjust_high_lat_times(times);
	}

	/* adjust Fajr, Isha and Maghrib for locations in higher latitudes */
	void adjust_high_lat_times(double times[])
	{
		double night_time = time_diff(times[Sunset], times[Sunrise]);		// sunset to sunrise

		// Adjust Fajr
		double fajr_diff = night_portion(method_params[calc_method].fajr_angle) * night_time;
		if (isnan(times[Fajr]) || time_diff(times[Fajr], times[Sunrise]) &gt; fajr_diff)
			times[Fajr] = times[Sunrise] - fajr_diff;

		// Adjust Isha
		double isha_angle = method_params[calc_method].isha_is_minutes ? 18.0 : method_params[calc_method].isha_value;
		double isha_diff = night_portion(isha_angle) * night_time;
		if (isnan(times[Isha]) || time_diff(times[Sunset], times[Isha]) &gt; isha_diff)
			times[Isha] = times[Sunset] + isha_diff;

		// Adjust Maghrib
		double maghrib_angle = method_params[calc_method].maghrib_is_minutes ? 4.0 : method_params[calc_method].maghrib_value;
		double maghrib_diff = night_portion(maghrib_angle) * night_time;
		if (isnan(times[Maghrib]) || time_diff(times[Sunset], times[Maghrib]) &gt; maghrib_diff)
			times[Maghrib] = times[Sunset] + maghrib_diff;
	}


	/* the night portion used for adjusting times in higher latitudes */
	double night_portion(double angle)
	{
		switch (adjust_high_lats)
		{
			case AngleBased:
				return angle / 60.0;
			case MidNight:
				return 1.0 / 2.0;
			case OneSeventh:
				return 1.0 / 7.0;
			default:
				// Just to return something!
				// In original library nothing was returned
				// Maybe I should throw an exception
				// It must be impossible to reach here
				return 0;
		}
	}

	/* convert hours to day portions  */
	void day_portion(double times[])
	{
		for (int i = 0; i &lt; TimesCount; ++i)
			times[i] /= 24.0;
	}

/* ---------------------- Misc Functions ----------------------- */

	/* compute the difference between two times  */
	static double time_diff(double time1, double time2)
	{
		return fix_hour(time2 - time1);
	}

	static std::string int_to_string(int num)
	{
		char tmp[16];
		tmp[0] = '\0';
		sprintf(tmp, &quot;%d&quot;, num);
		return std::string(tmp);
	}

	/* add a leading 0 if necessary */
	static std::string two_digits_format(int num)
	{
		char tmp[16];
		tmp[0] = '\0';
		sprintf(tmp, &quot;%2.2d&quot;, num);
		return std::string(tmp);
	}

/* ---------------------- Julian Date Functions ----------------------- */

	/* calculate julian date from a calendar date */
	double get_julian_date(int year, int month, int day)
	{
		if (month &lt;= 2)
		{
			year -= 1;
			month += 12;
		}

		double a = floor(year / 100.0);
		double b = 2 - a + floor(a / 4.0);

		return floor(365.25 * (year + 4716)) + floor(30.6001 * (month + 1)) + day + b - 1524.5;
	}

	/* convert a calendar date to julian date (second method) */
	double calc_julian_date(int year, int month, int day)
	{
		double j1970 = 2440588.0;
		tm date = { 0 };
		date.tm_year = year - 1900;
		date.tm_mon = month - 1;
		date.tm_mday = day;
		date.tm_isdst = -1;		// determine it yourself from system
		time_t ms = mktime(&amp;date);		// seconds since midnight Jan 1, 1970
		double days = floor(ms / (double) (60 * 60 * 24));
		return j1970 + days - 0.5;
	}

/* ---------------------- Trigonometric Functions ----------------------- */

	/* degree sin */
	static double dsin(double d)
	{
		return sin(deg2rad(d));
	}

	/* degree cos */
	static double dcos(double d)
	{
		return cos(deg2rad(d));
	}

	/* degree tan */
	static double dtan(double d)
	{
		return tan(deg2rad(d));
	}

	/* degree arcsin */
	static double darcsin(double x)
	{
		return rad2deg(asin(x));
	}

	/* degree arccos */
	static double darccos(double x)
	{
		return rad2deg(acos(x));
	}

	/* degree arctan */
	static double darctan(double x)
	{
		return rad2deg(atan(x));
	}

	/* degree arctan2 */
	static double darctan2(double y, double x)
	{
		return rad2deg(atan2(y, x));
	}

	/* degree arccot */
	static double darccot(double x)
	{
		return rad2deg(atan(1.0 / x));
	}

	/* degree to radian */
	static double deg2rad(double d)
	{
		return d * M_PI / 180.0;
	}

	/* radian to degree */
	static double rad2deg(double r)
	{
		return r * 180.0 / M_PI;
	}

	/* range reduce angle in degrees. */
	static double fix_angle(double a)
	{
		a = a - 360.0 * floor(a / 360.0);
		a = a &lt; 0.0 ? a + 360.0 : a;
		return a;
	}

	/* range reduce hours to 0..23 */
	static double fix_hour(double a)
	{
		a = a - 24.0 * floor(a / 24.0);
		a = a &lt; 0.0 ? a + 24.0 : a;
		return a;
	}

private:
/* ---------------------- Private Variables -------------------- */

	MethodConfig method_params[CalculationMethodsCount];

	CalculationMethod calc_method;		// caculation method
	JuristicMethod asr_juristic;		// Juristic method for Asr
	AdjustingMethod adjust_high_lats;	// adjusting method for higher latitudes
	double dhuhr_minutes;		// minutes after mid-day for Dhuhr

	double latitude;
	double longitude;
	double timezone;
	double julian_date;

/* --------------------- Technical Settings -------------------- */

	static const int NUM_ITERATIONS = 1;		// number of iterations needed to compute times
};</pre>
</div>
<div class="ad"><a href="http://viewgit.sourceforge.net/" title="Visit the ViewGit homepage">ViewGit</a></div></div>
</body>
</html>
