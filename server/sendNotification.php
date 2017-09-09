<?php

 function sendNotification($tokens, $title, $message) { 	

 	 $url = 'https://fcm.googleapis.com/fcm/send';

 	 $fields = array(
 	 	'registration_ids' => $tokens,
 	 	'data' => $title, $message);

 	 $headers = array(
 	 	'Authorization:key = SERVER_API_KEY',
 	 	'Content-Type: application/json');

 	  $ch = curl_init();
 	  curl_setopt($ch, CURLOPT_URL, $url);
 	  curl_setopt($ch, CURLOPT_POST, true);
 	  curl_setopt($ch, CURLOPT_HTTPHEADER, $headers);
 	  curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
 	  curl_setopt ($ch, CURLOPT_SSL_VERIFYHOST, 0);
 	  curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, false);
 	  curl_setopt($ch, CURLOPT_POSTFIELDS, json_encode($fields));

 	  $result = curl_exec($ch);

 	  if($result === FALSE){

 	  	die('Curl failed: ' . curl_error($ch));
 	  }

 	   curl_close($ch);

 	   return $result;
 }

 if(isset($_POST['Title']) && isset($_POST['Message'])){

 	$conn = mysqli_connect("localhost","root","","fcm");

 	$sql = "select token from users";

 	$result = mysqli_query($conn,$sql);

 	$tokens = array();

 	if(mysqli_num_rows($result) > 0 ){

 		while ($row = mysqli_fetch_assoc($result)){

 			$tokens[] = $row["token"];
 		}

 	}

 	mysqli_close($conn);

 	$title = array("title" => $_POST['Title']);

 	$message = array("message" => $_POST['Message']);

 	$message_status = sendNotification($tokens, $title, $message);

 	echo $message_status;
 }
 ?>