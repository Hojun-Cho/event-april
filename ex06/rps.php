<?php
		echo "Choose rock, paper, or scissors: ";
		$user = rtrim(fgets(STDIN), "\r\n");
        $Choosefrom= array('rock', 'paper', 'scissors');
        $Choice= rand(0,2);
        $computer=$Choosefrom[$Choice];
		if ($user == $computer) {
			
		}	
		else if($user == "rock") {
			if ($computer == "scissors")
				echo "Congratulations! You won! The computer chose scissors.";
			if ($computer == "paper")
				echo "Sorry, you lost. The computer chose paper.";	
		}
		else if ($user == "paper") {
			if ($computer == "rock")
				echo "Congratulations! You won! The computer chose rock.";
			if ($computer == "scissors")
				echo "Sorry, you lost. The computer chose scissors.";	
		}
		else if ($user == "scissors") {
			if ($computer == "paper")
				echo "Congratulations! You won! The computer chose paper.";
			if ($computer == "rock")
				echo "Sorry, you lost. The computer chose rock.";	
			}

?>

