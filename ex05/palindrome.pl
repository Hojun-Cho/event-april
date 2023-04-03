#!/usr/bin/perl
use strict;
use warnings;

print "Enter a string: ";
chomp( my $string = <STDIN> );

my @chars = split //, $string;
my $palindrome = 1;
for (0..@chars/2-1) {
   $palindrome = $chars[$_] eq $chars[-($_+1)]
      or last;
}

if ($palindrome){
	print "The string is a palindrome!\n"
}else{
	print "The string is not a palindrome.\n"
}
