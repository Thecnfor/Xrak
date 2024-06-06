window.onload = function() {  
    function setRGBFromBaseColor() {  
        // 获取 --root-color 的值  
        const rootColor = getComputedStyle(document.documentElement).getPropertyValue('--root-color');  
  
        // 使用正则表达式来解析 RGB 值  
        const rgbRegex = /^rgb\((\d+),\s*(\d+),\s*(\d+)\)$/;  
        const match = rootColor.match(rgbRegex);  
  
        if (match) {  
            // 提取 RGB 分量  
            const r = match[1];  
            const g = match[2];  
            const b = match[3];  
  
            // 将 RGB 分量分别赋给 --r, --g, --b 变量  
            document.documentElement.style.setProperty('--r', r);  
            document.documentElement.style.setProperty('--g', g);  
            document.documentElement.style.setProperty('--b', b);  
        } else {  
            console.error('Invalid base color format');  
        }  
    }  
  
    // 设置初始的 RGB 分量值  
    setRGBFromBaseColor();  
  
    // 如果 --base-color 可能会改变（例如通过用户交互或另一个脚本），  
    // 你可能需要添加一个监听器来重新调用 setRGBFromBaseColor 函数。  
    // 但请注意，CSS本身不支持直接监听自定义属性的变化。  
};