set config_file [open config.dat r]
set server_nr 0
set flag 0
while {$flag==0} {
	if {[gets $config_file temp]<0} { set flag 1 }
	set add [split $temp ":"]
	set IP($server_nr) [lindex $add 0]
	set ports($server_nr) [lindex $add 1]
	set server_nr [expr $server_nr+1]
}
set server_nr [expr $server_nr-1]
close $config_file
set ns [new Simulator]
set repertoire "bcast.nam"
set repert [open $repertoire w]
$ns namtrace-all $repert
set i 0
while {$i<$server_nr} {
	set nodes($i) [$ns node $IP($i) $ports($i)]
	puts $IP($i):$ports($i)
#	set nodes($i) [$ns node]
	set i [expr $i+1]
}
set i 0
while {$i<[expr $server_nr-1]} {
	$ns duplex-link $nodes($i) $nodes([expr $i+1]) 1Mb 10ms DropTail	
	set i [expr $i+1]
}
$ns at 2.0 "finish"
proc finish { } {
	global ns repert repertoire
	$ns flush-trace
	close $repert
	exec nam $repertoire &
	exit 0
}
$ns run