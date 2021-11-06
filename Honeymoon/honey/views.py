from django.shortcuts import render
from rest_framework.views import APIView
from rest_framework.response import Response
import random
import uuid
from django_redis import get_redis_connection
from utils.tencent.mag import send_message

from honey.serializer.account import MessageSerializers, LoginSerializer




class LoginView(APIView):
    def post(self, request, *args, **kwargs):
        print(request.data)
        '''
        1. 校验手机号是否合法
        2. 校验验证码 redis
            无验证码
            有验证码 错误
            有验证码 正常
        3. 数据库中获取用户信息
        4. 将一些信息给小程序
        '''
        ser = LoginSerializer(request.data)
    
        if not ser.is_valid():
            return Response({"status": False, "message": "短信验证失败"})
        
        from honey import models
        phone = ser.validated_data.get("phone")

        user_object, flag = models.UserInfo.objects.get_or_create(phone=phone)
        user_object.token = str(uuid.uuid4())
        user_object.save()

        return Response({"status": True, "data":{"token":user_object.token, "phone":phone}})




class MessageView(APIView):
    def get(self, request, *args, **kwargs):
        # 1. 获取手机号
        # 2. 手机号格式验证
        ser = MessageSerializers(data = request.query_params)
        if not ser.is_valid():
            return Response({'status': False,"message":"手机格式错误"})
        phone = ser.validated_data.get("phone")

        # 3. 生成验证码
        random_code = str(random.randint(10000, 99999))
        print(phone)
        print(random_code)
        # if not send_message(phone, random_code):
        #     return Response({"status": False, "message":"短信发送失败"})

        #5. 把验证码+手机号保存(30s过期)
        conn = get_redis_connection()
        conn.set(phone, random_code, ex = 60)

        return Response({"status": True, "message":"发送成功"})