var 我 ="撞死"//可以用中文
//大小写敏感
/t //制表
/n //换行
/' //单引号'
/s //空格
Number.MAX_SAFE_INTEGER //最大的安全整数
Number.MIN_SAFE_INTEGER //最小的安全整数
Number.MAX_VALUE //最大的数
Number.MIN_VALUE //最小的数
Number.NaN //非数值
Number.NEGATIVE_INFINITY //负无穷大
Number.POSITIVE_INFINITY //正无穷大

//三元运算符
1>2? "yes": "no"
//等同
if(value){
if(1>2){
    return "no";
}
else{
    return "yes";
    
}
}
//void-不返回值

//选择
switch (key) {
    case value:
        void
        value
        break;

    default:
        void
        value
        break;
}
//while循环
while(value){

while(1>2){
    void
    value
}

do
{
    value
}
while(1>2);
}
//for循环
for(volwe;value;value){
for(var i=0;i<10;i++){
    value
}
for(var i in document){
    document.write(i+"<br>");
    break
    return
}
}
//异常处理
for(;;){
try{//执行
    value;
    throw "error";
}
catch(error){//捕获的异常
    value;
}
finally{//最后必须处理
    value;
}
}
//函数
function functionName(arg0,arg1,arg2)/*形参*/{
    return value;
    var functionName = new function(arg0,arg1,arg2){
        return value;
    }
    document.write(functionName(arg0,arg1,arg2));//实参，会被忽略
    var a=function(){//可以没有函数名
        return value;
    }
    (function(a){return})(a)//可以直接做表达式
}
//with语句
with(document){
    with(document.getelementbyid("id").style){
        width="200px";
    }
    //等同于
    document.getElementById("id").style.width="200px";
}
//空语句
while(true){
    ;
}
//数值转化为字符串
with(value){
    return value.toString();
}
//整数与浮点数
with(value){
    return a=parseInt(value);
    return b=parseFloat(value);
}
//true、false、null、undefined
//对象
{
    name1:value
    var o=new Object();
    var o={
        name1:value
    }
    o.name1=value;//访问对象
    o["name1"]['name2']=value;//访问对象
    this.name1=value;//访问对象
}
//数组
{
    var a=new Array();
    var a=new Array(value);//长度
    var a=new Array(value,value);//长度和值
    var a=[value];//长度
    var a=[];
    a.length=value;//长度
    a[value]//访问数组，第value个
    a.push(value);//在数组末尾添加一个元素
    a.pop();//删除数组末尾的元素
    a.unshift(value);//在数组开头添加一个元素
    a.shift();//删除数组开头的元素
    a.splice(value,value);//截取数组中从第value个元素开始的value个元素
    a.splice(value,value,value);//截取数组中从第value个元素开始的value个元素，并添加一个元素
    a.join(value);//将数组中的所有元素以value连接成一个字符串
    a.reverse();//将数组中的元素反转
    a.sort();//将数组中的元素排序
    a.slice(value,value);//返回数组中从第value个元素开始的value个元素
}