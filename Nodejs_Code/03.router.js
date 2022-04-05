const express = require("express")
const router = express.Router()


router.get("/user/list", (req, res) => {
    console.log(req.params)
    res.send("Get user list")
})


router.post("/user/add", (req, res) => {

    res.send("Post user list")
    
})



module.exports = router
