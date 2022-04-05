const express = require('express')
const app = express()


const router = require('./03.router.js')
app.use('/api',router)

app.listen(80, ()=>{

    console.log("http://127.0.0.1")
})
