const express = require("express")

const app =  express()




//定义个最简单中间件函数
const mw = function(req, res, next){
    const time = Date.now()
    console.log('你好')
    req.startTime = time
    next()
}

//将mw注册为全局中间件函数
app.use(mw)

//挂载路由
app.get("/", (req, res) =>{

    res.send("hello world." + req.startTime)
})

app.post('/', (req, res) =>{

    res.send("Post Request." + req.startTime)

})
app.listen(80, () => {

    console.log("http://127.0.0.1")

})