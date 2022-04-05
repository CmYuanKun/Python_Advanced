const express = require("express")

const app =  express()




//定义个最简单中间件函数
const mw = function(req, res, next){

    console.log("这是个最简单的中间件函数")
    next()
}

//将mw注册为全局中间件函数
app.use(mw)
//挂载路由
app.get("/", (req, res) =>{

    res.send("hello world.")
})

app.post('/', (req, res) =>{

    res.send("Post Request.")

})
app.listen(80, () => {

    console.log("http://127.0.0.1")

})