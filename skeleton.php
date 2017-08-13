#!/usr/bin/php
<?php
$br = (php_sapi_name() == "cli")? "":"<br>";

if(!extension_loaded('markdown'))
{
	dl('markdown.' . PHP_SHLIB_SUFFIX);
}

$module = 'markdown';
$functions = get_extension_funcs($module);
echo "Functions available in the test extension:$br\n";
foreach($functions as $func)
{
    echo $func."$br\n";
}
echo "$br\n";

$function = 'confirm_' . $module . '_compiled';
if (extension_loaded($module))
{
	$str = $function("balls");
}
else
{
	$str = "Module $module is not compiled into PHP";
}
echo "$str\n";

var_dump(markdown_tohtml("ass"));
print "done"
?>
