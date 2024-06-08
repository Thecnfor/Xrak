/**
 * 摇杆配置
 */
const config = {
  /** 摇杆半径 */
  radius: 100,
};

/**
 * 摇杆区域元素，摇杆只会渲染在该区域
 */
let ele = document.getElementById("joystickContainer");

/** 是否正在按压 */
let pressing = false;

/** 初始X坐标 */
let prevX = 0;
/** 初始Y坐标 */
let prevY = 0;

/** 当前X坐标 */
let newX = 0;
/** 当前Y坐标 */
let newY = 0;

/** 相对X坐标 */
let relX = 0;
/** 相对Y坐标 */
let relY = 0;

/** 摇杆canvas移动后应在的X坐标 */
let moveX = 0;
/** 摇杆canvas移动后应在的Y坐标 */
let moveY = 0;

/** 根据半径限制相对坐标后的X坐标 */
let displayX = 0;
/** 根据半径限制相对坐标后的Y坐标 */
let displayY = 0;

ele.addEventListener("mousedown", down);
ele.addEventListener("mousemove", move);
ele.addEventListener("mouseup", up);

ele.addEventListener("touchstart", down);
ele.addEventListener("touchmove", move);
ele.addEventListener("touchend", up);

let lastSentX = null;  
let lastSentY = null;  
let hasReceivedData = false; // 新增的标志变量，用于跟踪是否已接收过数据  
let lastServerResponse = null;  
  
setInterval(function () {  
  if (displayX !== lastSentX || displayY !== lastSentY) { // 如果坐标发生变化，则发送数据到服务器  
    let outputEl = document.getElementById("result");  
  
    // 更新相对位置显示  
    outputEl.innerHTML = "<b>相对位置:</b> X:" + displayX + " Y:" + displayY;  
  
    // 使用Fetch API发送数据到PHP  
    fetch('../home.php', {  
      method: 'POST',  
      headers: {  
        'Content-Type': 'application/json',  
      },  
      body: JSON.stringify({ x: displayX, y: displayY }), // 将数据转换为JSON格式  
    })  
    .then(response => {  
      if (!response.ok) {  
        throw new Error('网络响应状态码不是2xx');  
      }  
      return response.json(); // 解析PHP返回JSON格式的数据  
    })  
    .then(data => {  
      // 无论数据是否改变，如果尚未接收过数据，则显示它  
      if (!hasReceivedData) {  
        hasReceivedData = true; // 标记为已接收过数据  
        outputEl.innerHTML += "<br><b>服务器返回:</b> " + data.message;  
      }  
  
      // 检查数据是否已改变（仅当已接收过数据时）  
      if (hasReceivedData && JSON.stringify(data) !== JSON.stringify(lastServerResponse)) {  
        // 数据已改变，更新显示  
        lastServerResponse = data; // 更新上次返回的数据  
        outputEl.innerHTML += "<br><b>服务器返回:</b> " + data.message;  
      }  
    })  
    .catch((error) => {  
      // 错误时总是更新显示  
      outputEl.innerHTML += "<br><b>服务器返回错误:</b> " + (error.message || error);  
      lastServerResponse = null; // 重置上次返回的数据  
    });  
  
    // 更新最后发送的值  
    lastSentX = displayX;  
    lastSentY = displayY;  
  }  
}, 30); // 假设这里的间隔是合适的

let stickEle = createStickCanvas();
let baseEle = createBaseCanvas();

ele.style.position = "fixed";
ele.appendChild(baseEle);
baseEle.style.position = "absolute";
baseEle.style.visibility = "hidden";
ele.appendChild(stickEle);
stickEle.style.position = "absolute";
stickEle.style.visibility = "hidden";

/**
 * 按压或鼠标点击后渲染摇杆
 * @param  {} event TouchEvent | MouseEvent
 */
function down(event) {
  pressing = true;
  prevX = getClientPosition(event).x;
  prevY = getClientPosition(event).y;
  baseEle.style.visibility = "visible";
  stickEle.style.visibility = "visible";
  stickMove(
    stickEle.style,
    prevX - stickEle.width / 2,
    prevY - stickEle.height / 2
  );
  stickMove(
    baseEle.style,
    prevX - baseEle.width / 2,
    prevY - baseEle.height / 2
  );
}

/**
 * 取消按压或松开鼠标后隐藏摇杆，并重置display坐标
 * @param  {} event TouchEvent | MouseEvent
 */
function up(event) {
  pressing = false;
  baseEle.style.visibility = "hidden";
  stickEle.style.visibility = "hidden";
  displayX = 0;
  displayY = 0;
}

/**
 * 移动鼠标响应事件，根据移动坐标计算相对坐标以及需要渲染的坐标，
 * 并根据半径限制距离，对计算后的值进行四舍五入
 * @param  {} event TouchEvent | MouseEvent
 */
function move(event) {
  if (pressing) {
    newX = getClientPosition(event).x;
    newY = getClientPosition(event).y;
    relX = newX - prevX;
    relY = prevY - newY;
    let stickNormalizedX;
    let stickNormalizedY;
    let distance = Math.sqrt(Math.pow(relX, 2) + Math.pow(relY, 2));
    stickNormalizedX = relX / distance;
    stickNormalizedY = relY / distance;
    if (distance <= config.radius) {
      moveX = newX - stickEle.width / 2;
      moveY = newY - stickEle.height / 2;
      stickMove(stickEle.style, moveX, moveY);
    } else {
      moveX = stickNormalizedX * config.radius + prevX - stickEle.width / 2;
      moveY = -stickNormalizedY * config.radius + prevY - stickEle.height / 2;
      stickMove(stickEle.style, moveX, moveY);
    }
    displayX = Math.round(stickNormalizedX * config.radius);
    displayY = Math.round(stickNormalizedY * config.radius);
  }
}

/**
 * 创建摇杆canvas
 */
function createStickCanvas() {
  let canvas = document.createElement("canvas");
  canvas.width = 86;
  canvas.height = 86;
  let ctx = canvas.getContext("2d");
  ctx.beginPath();
  ctx.lineWidth = 6;
  ctx.arc(canvas.width / 2, canvas.width / 2, 40, 0, Math.PI * 2, true);
  ctx.stroke();
  return canvas;
}
/**
 * 创建摇杆底座canvas
 */
function createBaseCanvas() {
  let canvas = document.createElement("canvas");
  canvas.width = 126;
  canvas.height = 126;

  let ctx = canvas.getContext("2d");
  ctx.beginPath();
  ctx.lineWidth = 6;
  ctx.arc(canvas.width / 2, canvas.width / 2, 40, 0, Math.PI * 2, true);
  ctx.stroke();

  ctx.beginPath();
  ctx.lineWidth = 2;
  ctx.arc(canvas.width / 2, canvas.width / 2, 60, 0, Math.PI * 2, true);
  ctx.stroke();

  return canvas;
}
/**
 * 移动摇杆
 * @param  {} style 传入摇杆底座/摇杆的style属性
 * @param  {} x x轴移动距离
 * @param  {} y y轴移动距离
 * @example stickMove(stickEle.style, (prevX - stickEle.width/2), (prevY - stickEle.height/2));
 */
function stickMove(style, x, y) {
  let transform = supportTransform();
  if (transform) {
    style[transform] = "translate(" + x + "px," + y + "px)";
  } else {
    style.left = x + "px";
    style.top = y + "px";
  }
}

/**
 * 查看是否支持translate
 */
function supportTransform() {
  let styles = [
    "webkitTransform",
    "MozTransform",
    "msTransform",
    "OTransform",
    "transform",
  ];

  let el = document.createElement("p");
  let style;

  for (let i = 0; i < styles.length; i++) {
    style = styles[i];
    if (null != el.style[style]) {
      return style;
    }
  }
}

/**
 * 获取client坐标，不同的响应对象取值方法不同
 * @param  {} event TouchEvent | MouseEvent
 */
function getClientPosition(event) {
  if (event instanceof TouchEvent) {
    return {
      x: event.touches[0].clientX,
      y: event.touches[0].clientY,
    }
  } else {
    return {
      x: event.clientX,
      y: event.clientY,
    }
  }
}
