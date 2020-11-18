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
 &raquo; <a href="?a=summary&amp;p=PrayTimes">PrayTimes</a> : Blob d086dd / <a href="?a=tree&amp;p=PrayTimes&amp;h=b23faa99cb9c02ed969c4dafcef6de57cb4b32bf&amp;hb=17ee68cff3d814bae3fcf7dc55beaf3e49909889&amp;f=v1">v1</a> / <a href="?a=tree&amp;p=PrayTimes&amp;h=c72271b474ed9f33ee80bfa1924c29df54da38fa&amp;hb=17ee68cff3d814bae3fcf7dc55beaf3e49909889&amp;f=v1/csharp">csharp</a> / <a href="?a=viewblob&amp;p=PrayTimes&amp;h=d086dd4e20256802cc83d63aaefaa71cd8f1aa14&amp;hb=17ee68cff3d814bae3fcf7dc55beaf3e49909889&amp;f=v1/csharp/sample.cs">sample.cs</a> </div>
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

<h2>Last commit for v1/csharp/sample.cs: <a href="?a=commit&amp;p=PrayTimes&amp;h=1c500fff7f21d1993f205d3e36dc17ee56efdf24">1c500fff7f21d1993f205d3e36dc17ee56efdf24</a></h2>
<h1>JavaScript ver 2.0 uploaded</h1>
<div class="authorinfo">
<a href="?a=search&amp;p=PrayTimes&amp;h=HEAD&amp;st=author&amp;s=Hamid">Hamid</a> [2010-10-29 05:14:09]</div>
<div class="commitmessage">
<pre>
JavaScript ver 2.0 uploaded
</pre>
</div>
<div class="file">
<pre>

// Pray Times Example
// By: Jandost Khoso

class Program
{
    static void Main ( string [ ] args )
    {
        PrayerTime p = new PrayTime();
        double lo = 25;
        double la = 55;
        int y = 0 , m = 0 , d = 0 , tz = 0;

        DateTime cc = DateTime.Now;
        y = cc.Year;
        m = cc.Month;
        d = cc.Day;
        tz = TimeZone.CurrentTimeZone.GetUtcOffset(new DateTime (y,m,d)).Hours;
        String [] s ;

        p.setCalcMethod ( 2 );
        p . setAsrMethod ( 0 );
        s = p . getDatePrayerTimes ( y , m , d , lo , la , tz );
        for(int i = 0 ; i &lt; s.Length ; ++i )
        {
            Console . WriteLine ( s [ i ] );
        }
    }
}</pre>
</div>
<div class="ad"><a href="http://viewgit.sourceforge.net/" title="Visit the ViewGit homepage">ViewGit</a></div></div>
</body>
</html>
