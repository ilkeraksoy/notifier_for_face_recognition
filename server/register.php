<?php

	if(isset($_POST['Device']) && isset($_POST['Token'])) {
		
		$device = $_POST['Device'];
		$token = $_POST['Token'];		
		
		$conn = mysqli_connect("localhost", "root", "", "fcm");
		$query = "INSERT INTO users(device, token) VALUES('$device' ,'$token') ON DUPLICATE KEY UPDATE device='$device';";
		
		mysqli_query($conn, $query);
		mysqli_close($conn);
	}
?>
