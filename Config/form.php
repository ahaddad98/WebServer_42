<!DOCTYPE html>
<html>
<?php
?>

<head>
    <title>Form</title>
</head>

<body>
    <form enctype="application/x-www-form-urlencoded" method="get">
        <input type="text" name="name" placeholder="Name">
        <input type="text" name="email" placeholder="Email">
         <input type="submit" value="Submit">
    </form>
    <?php

    if (isset($_POST['name']) && isset($_POST['email'])) {

        $str = "name=" . $_POST['name'] . "&email=" . $_POST['email'];
        parse_str($str, $output);
        echo "Welcome Mr " . $_POST['name'] . " To your session</br> Your Email is " . $_POST['email'];
        setcookie("name",output['name']);
        echo "Hereee";
        exit;
    }
    ?>
</body>

</html>