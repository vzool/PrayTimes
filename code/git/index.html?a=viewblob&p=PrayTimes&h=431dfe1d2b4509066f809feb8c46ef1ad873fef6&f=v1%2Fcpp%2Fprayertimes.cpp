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
 &raquo; <a href="?a=summary&amp;p=PrayTimes">PrayTimes</a> : Blob 431dfe / <a href="?a=tree&amp;p=PrayTimes&amp;h=b23faa99cb9c02ed969c4dafcef6de57cb4b32bf&amp;hb=17ee68cff3d814bae3fcf7dc55beaf3e49909889&amp;f=v1">v1</a> / <a href="?a=tree&amp;p=PrayTimes&amp;h=671aeb697e9b7613a19d13fb8fe4def45f2c00a9&amp;hb=17ee68cff3d814bae3fcf7dc55beaf3e49909889&amp;f=v1/cpp">cpp</a> / <a href="?a=viewblob&amp;p=PrayTimes&amp;h=69a03c4fc8041faa9e76c67e0836a694a075f60f&amp;hb=17ee68cff3d814bae3fcf7dc55beaf3e49909889&amp;f=v1/cpp/prayertimes.cpp">prayertimes.cpp</a> </div>
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

<h2>Last commit for v1/cpp/prayertimes.cpp: <a href="?a=commit&amp;p=PrayTimes&amp;h=17ee68cff3d814bae3fcf7dc55beaf3e49909889">17ee68cff3d814bae3fcf7dc55beaf3e49909889</a></h2>
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
/*-------------------- In the name of God ----------------------*\

    PrayerTimes 0.3
    Islamic prayer times calculator

Developed by:
  Mohammad Ebrahim Mohammadi Panah &lt;ebrahim at mohammadi dot ir&gt;

------------------------------------------------------------------

Copyright 2009, Mohammad Ebrahim Mohammadi Panah

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You can get a copy of the GNU General Public License from
http://www.gnu.org/copyleft/gpl.html

\*--------------------------------------------------------------*/

#include &lt;ctime&gt;
#include &lt;cmath&gt;
#include &lt;cstring&gt;
#include &lt;unistd.h&gt;
#include &lt;getopt.h&gt;

#include &quot;prayertimes.hpp&quot;

#define PROG_NAME &quot;prayertimes&quot;
#define PROG_NAME_FRIENDLY &quot;PrayerTimes&quot;
#define PROG_VERSION &quot;0.3&quot;

static const char* TimeName[] =
{
	&quot;Fajr&quot;,
	&quot;Sunrise&quot;,
	&quot;Dhuhr&quot;,
	&quot;Asr&quot;,
	&quot;Sunset&quot;,
	&quot;Maghrib&quot;,
	&quot;Isha&quot;,
};

void print_help(FILE* f)
{
	fputs(PROG_NAME_FRIENDLY &quot; &quot; PROG_VERSION &quot;\n\n&quot;, stderr);
	fputs(&quot;Usage: &quot; PROG_NAME &quot; options...\n&quot;
	      &quot;\n&quot;
		  &quot; Options\n&quot;
	      &quot;    --help                      -h  you're reading it\n&quot;
	      &quot;    --version                   -v  prints name and version, then exits\n&quot;
	      &quot;    --date arg                  -d  get prayer times for arbitrary date\n&quot;
	      &quot;    --timezone arg              -z  get prayer times for arbitrary timezone\n&quot;
	      &quot;  * --latitude arg              -l  latitude of desired location\n&quot;
	      &quot;  * --longitude arg             -n  longitude of desired location\n&quot;
	      &quot;    --calc-method arg           -c  select prayer time calculation method\n&quot;
	      &quot;    --asr-juristic-method arg   -a  select Juristic method for calculating Asr prayer time\n&quot;
	      &quot;    --high-lats-method arg      -i  select adjusting method for higher latitude\n&quot;
	      &quot;    --dhuhr-minutes arg             minutes after mid-way for calculating Dhuhr prayer time\n&quot;
	      &quot; ** --maghrib-minutes arg           minutes after sunset for calculating Maghrib prayer time\n&quot;
	      &quot; ** --isha-minutes arg              minutes after Maghrib for calculating Isha prayer time\n&quot;
	      &quot; ** --fajr-angle arg                angle for calculating Fajr prayer time\n&quot;
	      &quot; ** --maghrib-angle arg             angle for calculating Maghrib prayer time\n&quot;
	      &quot; ** --isha-angle arg                angle for calculating Isha prayer time\n&quot;
		  &quot;\n&quot;
		  &quot;  * These options are required\n&quot;
		  &quot; ** By providing any of these options the calculation method is set to custom\n&quot;
	      &quot;\n&quot;
		  &quot; Possible arguments for --calc-method\n&quot;
	      &quot;    jafari        Ithna Ashari\n&quot;
	      &quot;    karachi       University of Islamic Sciences, Karachi\n&quot;
	      &quot;    isna          Islamic Society of North America (ISNA)\n&quot;
	      &quot;    mwl           Muslim World League (MWL)\n&quot;
	      &quot;    makkah        Umm al-Qura, Makkah\n&quot;
	      &quot;    egypt         Egyptian General Authority of Survey\n&quot;
	      &quot;    custom        Custom Setting\n&quot;
          &quot;\n&quot;
		  &quot; Possible arguments for --asr-juristic-method\n&quot;
	      &quot;    shafii        Shafii (standard)\n&quot;
	      &quot;    hanafi        Hanafi\n&quot;
          &quot;\n&quot;
		  &quot; Possible arguments for --high-lats-method\n&quot;
	      &quot;    none          No adjustment\n&quot;
	      &quot;    midnight      middle of night\n&quot;
	      &quot;    oneseventh    1/7th of night\n&quot;
	      &quot;    anglebased    angle/60th of night\n&quot;
		  , stderr);

}

int main(int argc, char* argv[])
{
	PrayerTimes prayer_times;
	double latitude = NAN;		// 35.7061
	double longitude = NAN;		// 51.4358
	time_t date = time(NULL);
	double timezone = NAN;

	// Parse options
	for (;;)
	{
		static option long_options[] =
		{
			{ &quot;help&quot;,                no_argument,       NULL, 'h' },
			{ &quot;version&quot;,             no_argument,       NULL, 'v' },
			{ &quot;date&quot;,                required_argument, NULL, 'd' },
			{ &quot;timezone&quot;,            required_argument, NULL, 'z' },
			{ &quot;latitude&quot;,            required_argument, NULL, 'l' },
			{ &quot;longitude&quot;,           required_argument, NULL, 'n' },
			{ &quot;calc-method&quot;,         required_argument, NULL, 'c' },
			{ &quot;asr-juristic-method&quot;, required_argument, NULL, 'a' },
			{ &quot;high-lats-method&quot;,    required_argument, NULL, 'i' },
			{ &quot;dhuhr-minutes&quot;,       required_argument, NULL, 0   },
			{ &quot;maghrib-minutes&quot;,     required_argument, NULL, 0   },
			{ &quot;isha-minutes&quot;,        required_argument, NULL, 0   },
			{ &quot;fajr-angle&quot;,          required_argument, NULL, 0   },
			{ &quot;maghrib-angle&quot;,       required_argument, NULL, 0   },
			{ &quot;isha-angle&quot;,          required_argument, NULL, 0   },
			{ 0, 0, 0, 0 }
		};

		enum	// long options missing a short form
		{
			DHUHR_MINUTES = 9,
			MAGHRIB_MINUTES,
			ISHA_MINUTES,
			FAJR_ANGLE,
			MAGHRIB_ANGLE,
			ISHA_ANGLE,
		};

		int option_index = 0;
		int c = getopt_long(argc, argv, &quot;hvd:z:l:n:c:a:i:&quot;, long_options, &amp;option_index);

		if (c == -1)
			break;		// Last option

		if (!optarg &amp;&amp; c != 'h' &amp;&amp; c != 'v')
		{
			fprintf(stderr, &quot;Error: %s option requires an argument\n&quot;, long_options[option_index].name);
			return 2;
		}

		switch (c)
		{
			case 0:
				double arg;
				if (sscanf(optarg, &quot;%lf&quot;, &amp;arg) != 1)
				{
					fprintf(stderr, &quot;Error: Invalid number '%s'\n&quot;, optarg);
					return 2;
				}
				switch (option_index)
				{
					case DHUHR_MINUTES:
						prayer_times.set_dhuhr_minutes(arg);
						break;
					case MAGHRIB_MINUTES:
						prayer_times.set_maghrib_minutes(arg);
						break;
					case ISHA_MINUTES:
						prayer_times.set_isha_minutes(arg);
						break;
					case FAJR_ANGLE:
						prayer_times.set_fajr_angle(arg);
						break;
					case MAGHRIB_ANGLE:
						prayer_times.set_maghrib_angle(arg);
						break;
					case ISHA_ANGLE:
						prayer_times.set_isha_angle(arg);
						break;
					default:
						fprintf(stderr, &quot;Error: Invalid command line option\n&quot;);
						return 2;
				}
				break;
			case 'h':		// --help
				print_help(stdout);
				return 0;
			case 'v':		// --version
				puts(PROG_NAME_FRIENDLY &quot; &quot; PROG_VERSION);
				return 0;
			case 'd':		// --date
			{
				tm* new_date = getdate(optarg);
				if (!new_date)
				{
					fprintf(stderr, &quot;Error: Failed to parse '%s' as date (%m)\n&quot;, optarg);
					return 2;
				}
				date = mktime(new_date);
				break;
			}
			case 'z':		// --timezone
				if (sscanf(optarg, &quot;%lf&quot;, &amp;timezone) != 1)
				{
					fprintf(stderr, &quot;Error: Invalid timezone '%s'\n&quot;, optarg);
					return 2;
				}
				break;
			case 'l':		// --latitude
				if (sscanf(optarg, &quot;%lf&quot;, &amp;latitude) != 1)
				{
					fprintf(stderr, &quot;Error: Invalid latitude '%s'\n&quot;, optarg);
					return 2;
				}
				break;
			case 'n':		// --longitude
				if (sscanf(optarg, &quot;%lf&quot;, &amp;longitude) != 1)
				{
					fprintf(stderr, &quot;Error: Invalid longitude '%s'\n&quot;, optarg);
					return 2;
				}
				break;
			case 'c':		// --calc-method
				if (strcmp(optarg, &quot;jafari&quot;) == 0)
					prayer_times.set_calc_method(PrayerTimes::Jafari);
				else if (strcmp(optarg, &quot;karachi&quot;) == 0)
					prayer_times.set_calc_method(PrayerTimes::Karachi);
				else if (strcmp(optarg, &quot;isna&quot;) == 0)
					prayer_times.set_calc_method(PrayerTimes::ISNA);
				else if (strcmp(optarg, &quot;mwl&quot;) == 0)
					prayer_times.set_calc_method(PrayerTimes::MWL);
				else if (strcmp(optarg, &quot;makkah&quot;) == 0)
					prayer_times.set_calc_method(PrayerTimes::Makkah);
				else if (strcmp(optarg, &quot;egypt&quot;) == 0)
					prayer_times.set_calc_method(PrayerTimes::Egypt);
				else if (strcmp(optarg, &quot;custom&quot;) == 0)
					prayer_times.set_calc_method(PrayerTimes::Custom);
				else
				{
					fprintf(stderr, &quot;Error: Unknown method '%s'\n&quot;, optarg);
					return 2;
				}
				break;
			case 'a':		// --asr-juristic-method
				if (strcmp(optarg, &quot;shafii&quot;) == 0)
					prayer_times.set_asr_method(PrayerTimes::Shafii);
				else if (strcmp(optarg, &quot;hanafi&quot;) == 0)
					prayer_times.set_asr_method(PrayerTimes::Hanafi);
				else
				{
					fprintf(stderr, &quot;Error: Unknown method '%s'\n&quot;, optarg);
					return 2;
				}
				break;
			case 'i':		// --high-lats-method
				if (strcmp(optarg, &quot;none&quot;) == 0)
					prayer_times.set_high_lats_adjust_method(PrayerTimes::None);
				else if (strcmp(optarg, &quot;midnight&quot;) == 0)
					prayer_times.set_high_lats_adjust_method(PrayerTimes::MidNight);
				else if (strcmp(optarg, &quot;oneseventh&quot;) == 0)
					prayer_times.set_high_lats_adjust_method(PrayerTimes::OneSeventh);
				else if (strcmp(optarg, &quot;anglebased&quot;) == 0)
					prayer_times.set_high_lats_adjust_method(PrayerTimes::AngleBased);
				else
				{
					fprintf(stderr, &quot;Error: Unknown method '%s'\n&quot;, optarg);
					return 2;
				}
				break;
			default:
				fprintf(stderr, &quot;Error: Unknown option '%c'\n&quot;, c);
				print_help(stderr);
				return 2;
		}
	}

	if (isnan(latitude) || isnan(longitude))
	{
		fprintf(stderr, &quot;Error: You must provide both latitude and longitude\n&quot;);
		return 2;
	}

	fputs(PROG_NAME_FRIENDLY &quot; &quot; PROG_VERSION &quot;\n\n&quot;, stderr);

	if (isnan(timezone))
		timezone = PrayerTimes::get_effective_timezone(date);

	double times[PrayerTimes::TimesCount];
	fprintf(stderr, &quot;date          : %s&quot;, ctime(&amp;date));
	fprintf(stderr, &quot;timezone      : %.1lf\n&quot;, timezone);
	fprintf(stderr, &quot;latitude      : %.5lf\n&quot;, latitude);
	fprintf(stderr, &quot;longitude     : %.5lf\n&quot;, longitude);
	puts(&quot;&quot;);
	prayer_times.get_prayer_times(date, latitude, longitude, timezone, times);
	for (int i = 0; i &lt; PrayerTimes::TimesCount; ++i)
		printf(&quot;%8s : %s\n&quot;, TimeName[i], PrayerTimes::float_time_to_time24(times[i]).c_str());
	return 0;
}</pre>
</div>
<div class="ad"><a href="http://viewgit.sourceforge.net/" title="Visit the ViewGit homepage">ViewGit</a></div></div>
</body>
</html>
