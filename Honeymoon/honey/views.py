from django.shortcuts import render
from rest_framework.views import APIView
from rest_framework.response import Response
from rest_framework import serializers
from rest_framework.exceptions import ValidationError
import re

def phone_validator(value):
    if not re.match("^1[3|4|5|8][0-9]\d{4,8}$", value):
        raise ValidationError("手机格式错误")


class MessageSerializers(serializers.Serializer):
    phone = serializers.CharField(label="手机号", validators=[phone_validator,])

class LoginView(APIView):

    def post(self, request, *args, **kwargs):
        print(request.data)
        return Response({"status": True})

class MessageView(APIView):
    def get(self, request, *args, **kwargs):
        # 1. 获取手机号
        # 2. 手机号格式验证
        ser = MessageSerializers(data = request.query_params)
        if not ser.is_vaild():
            return Response({'status': False,"message":"手机格式错误"}
        phone = ser.validated_data.get("phone")
        # 3. 生成验证码
        return Response({"status": True})