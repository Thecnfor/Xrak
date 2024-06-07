// 获取所有的 main-body 元素  
var mainBodyElements = document.querySelectorAll('.main-body');  
  
// 为每个 main-body 元素添加点击事件监听器  
mainBodyElements.forEach(function(element) {  
    element.addEventListener('click', function() {  
        // 移除其他元素的 full-screen 类  
        mainBodyElements.forEach(function(otherElement) {  
            otherElement.classList.remove('full-screen');  
        });  
        // 为当前点击的元素添加 full-screen 类  
        this.classList.add('full-screen');  
    });  
});