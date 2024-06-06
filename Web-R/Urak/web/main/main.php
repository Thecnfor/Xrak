<?php
session_start();
header("Content-type:text/html;charst=UTF-8");
require_once('conn.php');
$username=$_POST['username'];
$password=$_POST['password'];
$sql="select * from user where username='$username' and password='$password'";
$result=mysqli_query($conn,$sql);
$num=mysqli_num_rows($result);
if($num){
    $_SESSION['username']=$username;
    echo "<script>alert('登录成功');location.href='index.php';</script>";
}else{
    echo "<script>alert('登录失败');location.href='login.php';</script>";
}
// 关闭数据库连接
mysqli_close($conn);
?>