function showMore() {  
    var width = window.innerWidth;  
    var more = document.getElementById("more").checked;  
    var moreText = document.getElementById("nav");  
  
    if (width <= 767) {   
        if (more) {
            
        }
    } else {  
        if (more) {  
            moreText.style.opacity = "1";
            moreText.style.right = "0"
            document.getElementById("nav_mo").style.opacity="0.8"
            // 设置其他元素的样式为白色背景或文字  
            setStylesForWideScreen(true);  
        } else {  
            moreText.style.opacity = "0";
            moreText.style.right = "-15rem"
            document.getElementById("nav_mo").style.opacity="0"
            // 设置其他元素的样式为黑色背景或文字  
            setStylesForWideScreen(false);  
        }  
    }  
}  
  
function setStylesForWideScreen(isMoreChecked) {  
    var header = document.getElementById("header");  
    var logo = document.getElementById("logo");  
    if (isMoreChecked) {  
        header.style.backgroundColor = "black";  
        logo.style.color = "white";  
        document.getElementById("list-1").style.color = "white"
        document.getElementById("list-2").style.color = "white"
        document.getElementById("list-3").style.color = "white"
        document.getElementById("bar1").style.backgroundColor = "white"
        document.getElementById("bar2").style.backgroundColor = "white"
        document.getElementById("bar3").style.backgroundColor = "white"
    } else {  
        header.style.backgroundColor = "";
        logo.style.color = "black";  
        document.getElementById("list-1").style.color = "black"
        document.getElementById("list-2").style.color = "black"
        document.getElementById("list-3").style.color = "black"
        document.getElementById("bar1").style.backgroundColor = "black"
        document.getElementById("bar2").style.backgroundColor = "black"
        document.getElementById("bar3").style.backgroundColor = "black"
    }  
}  
  
// 当窗口大小改变时  
window.addEventListener('resize', function() {  
    showMore(); // 根据当前窗口宽度和checkbox状态更新样式  
});  
  
// 在页面加载时立即执行一次  
window.dispatchEvent(new Event('resize'));  
  
// 可能还需要为 "more" checkbox 添加一个点击事件监听器来调用 showMore()  
document.getElementById("more").addEventListener('change', showMore);