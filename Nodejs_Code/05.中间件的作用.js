const express = require("express")

const app =  express()




//���������м������
const mw = function(req, res, next){
    const time = Date.now()
    console.log('���')
    req.startTime = time
    next()
}

//��mwע��Ϊȫ���м������
app.use(mw)

//����·��
app.get("/", (req, res) =>{

    res.send("hello world." + req.startTime)
})

app.post('/', (req, res) =>{

    res.send("Post Request." + req.startTime)

})
app.listen(80, () => {

    console.log("http://127.0.0.1")

})