const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>Glory project</title>
<style>
body {font-family: Arial, Helvetica, sans-serif;}

/* Full-width input fields */
input[type=text], input[type=password] {
  width: 100%;
  padding: 12px 20px;
  margin: 8px 0;
  display: inline-block;
  border: 1px solid #ccc;
  box-sizing: border-box;
}

/* Set a style for all buttons */
button {
  background-color: #04AA6D;
  color: white;
  padding: 14px 20px;
  margin: 8px 0;
  border: none;
  cursor: pointer;
  width: 100%;
}

button:hover {
  opacity: 0.8;
}

/* Extra styles for the cancel button */
.cancelbtn {
  width: auto;
  padding: 10px 18px;
  background-color: #f44336;
}

/* Center the image and position the close button */
.imgcontainer {
  text-align: center;
  margin: 24px 0 12px 0;
  position: relative;
}

img.avatar {
  width: 40%;
  border-radius: 50%;
}

.container {
  padding: 16px;
}

span.psw {
  float: right;
  padding-top: 16px;
}

/* The Modal (background) */
.modal {
  display: none; /* Hidden by default */
  position: fixed; /* Stay in place */
  z-index: 1; /* Sit on top */
  left: 0;
  top: 0;
  width: 100%; /* Full width */
  height: 100%; /* Full height */
  overflow: auto; /* Enable scroll if needed */
  background-color: rgb(0,0,0); /* Fallback color */
  background-color: rgba(0,0,0,0.4); /* Black w/ opacity */
  padding-top: 60px;
}

/* Modal Content/Box */
.modal-content {
  background-color: #fefefe;
  margin: 5% auto 15% auto; /* 5% from the top, 15% from the bottom and centered */
  border: 1px solid #888;
  width: 80%; /* Could be more or less, depending on screen size */
}

/* The Close Button (x) */
.close {
  position: absolute;
  right: 25px;
  top: 0;
  color: #000;
  font-size: 35px;
  font-weight: bold;
}

.close:hover,
.close:focus {
  color: red;
  cursor: pointer;
}

/* Add Zoom Animation */
.animate {
  -webkit-animation: animatezoom 0.6s;
  animation: animatezoom 0.6s
}

@-webkit-keyframes animatezoom {
  from {-webkit-transform: scale(0)} 
  to {-webkit-transform: scale(1)}
}
  
@keyframes animatezoom {
  from {transform: scale(0)} 
  to {transform: scale(1)}
}

/* Change styles for span and cancel button on extra small screens */
@media screen and (max-width: 300px) {
  span.psw {
     display: block;
     float: none;
  }
  .cancelbtn {
     width: 100%;
  }
}
*
        {
            font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
        
        }
/* /////////////////////////////////////////////// */
.switch {
  position: relative;
  display: inline-block;
  width: 90px;
  height: 34px;
}

.switch input {display:none;}
.slider {
  position: absolute;
  cursor: pointer;
  top: 0;
  left: 0;
  right: 0;
  bottom: 0;
  background-color: #ca2222;
  -webkit-transition: .4s;
  transition: .4s;
}

.slider:before {
  position: absolute;
  content: "";
  height: 26px;
  width: 26px;
  left: 4px;
  bottom: 4px;
  background-color: white;
  -webkit-transition: .4s;
  transition: .4s;
}

input:checked + .slider {
  background-color: #2ab934;
}

input:focus + .slider {
  box-shadow: 0 0 1px #2196F3;
}

input:checked + .slider:before {
  -webkit-transform: translateX(55px);
  -ms-transform: translateX(55px);
  transform: translateX(55px);
}

/*------ ADDED CSS ---------*/
.on
{
  display: none;
}

.on, .off
{
  color: white;
  position: absolute;
  transform: translate(-50%,-50%);
  top: 50%;
  left: 50%;
  font-size: 10px;
  font-family: Verdana, sans-serif;
}

input:checked+ .slider .on
{display: block;}

input:checked + .slider .off
{display: none;}

/*--------- END --------*/

/* Rounded sliders */
.slider.round {
  border-radius: 34px;
}

.slider.round:before {
  border-radius: 50%;}
</style>
</head>
<body style="background-color: rgb(12, 1, 51); margin-left: 10%; margin-right: 10%;">  

<div id="myP">
  <h1 style="color: rgb(255, 255, 255); text-align: center;">
    GLORY PROJECT
</h1>
<center>
   <div style="width: auto; height: auto; background-color: rgb(255, 255, 255); border-radius: 10px; padding: 5%;">
       <h1 style="color: rgb(12, 1, 51);">COMMANDE LUMIERE</h1>
        <h2 style="color: rgb(12, 1, 51);">LAMPE SALON</h2>
       <label class="switch">
           <input type="checkbox" id="togBtn" name="lampe1" onclick="togle(this)">
           <div class="slider round">
            <!--ADDED HTML -->
            <span class="on">ON</span>
            <span class="off">OFF</span>
            <!--END-->
           </div>
          </label>
          <h2 style="color: rgb(12, 1, 51);">LAMPE CHAMBRE</h2>
       <label class="switch">
           <input type="checkbox" id="togBtn" name="lampe2" onclick="togle(this)">
           <div class="slider round">
            <!--ADDED HTML -->
            <span class="on">ON</span>
            <span class="off">OFF</span>
            <!--END-->
           </div>
          </label>
          <h2 style="color: rgb(12, 1, 51);">LAMPE CUISINE</h2>
       <label class="switch">
           <input type="checkbox" id="togBtn" name="lampe3" onclick="togle(this)">
           <div class="slider round">
            <!--ADDED HTML -->
            <span class="on">ON</span>
            <span class="off">OFF</span>
            <!--END-->
           </div>
          </label>
          <h1 style="color: rgb(12, 1, 51);">COMMANDE PRISE</h1>
        <h2 style="color: rgb(12, 1, 51);">PRISE SALON</h2>
       <label class="switch">
           <input type="checkbox" id="togBtn" name="prise1" onclick="togle(this)">
           <div class="slider round">
            <!--ADDED HTML -->
            <span class="on">ON</span>
            <span class="off">OFF</span>
            <!--END-->
           </div>
          </label>  
    </div>
     <h6 style="color: white;">By glory</h6>
</center>
</div>

<!-- <button onclick="document.getElementById('id01').style.display='block'" style="width:auto;">Login</button> -->

<div id="id01" class="modal">
  
  <div class="modal-content animate">
    <div class="imgcontainer">
      <span onclick="document.getElementById('id01').style.display='none'" class="close" title="Close Modal">&times;</span>
     
    </div>

    <div class="container">
      <label for="uname"><b>Username</b></label>
      <input type="text" placeholder="Enter Username" name="uname"  id="login">

      <label for="psw"><b>Password</b></label>
      <input type="password" placeholder="Enter Password" name="psw" id="pass" >
        
      <button type="submit" onclick="login()">Login</button>
    </div>
  </div>
</div>

<script>
var  logins = "admin";
var  pass  = "1234";
var mylog = 0;
var mypass = document.getElementById("pass").value;
document.getElementById("myP").style.visibility = "hidden";

function login()
{

 
  if(document.getElementById("login").value.toString() == logins.toString())
  {
    if(document.getElementById("pass").value.toString() == pass.toString())
    {
      alert("j'avance");
    }
     document.getElementById('id01').style.display='none';
     document.getElementById("myP").style.visibility = "visible";
  }
}
document.getElementById('id01').style.display='block';
// Get the modal
var modal = document.getElementById('id01');
</script>
<script>

  function togle(state)
  {
     var dvPassport = document.getElementById("state");//recuperation de l'element cliker
     var xhttp = new XMLHttpRequest();  // variable de la requette xhttp
     if(state.checked) //verifi si le l'interupteur est sur on ou of
     { 
       //requette  d'allumage
       xhttp.open("GET",state.name, true); //Handle readADC server on ESP8266
       xhttp.send();
     }
     else
     {
        //requette d'extinction
       xhttp.open("GET",state.name+"off", true); //Handle readADC server on ESP8266
        xhttp.send();
     }

        //   alert(state.checked);
        //  alert(state.name);

  }
</script>  

</body>
</html>
)=====";
