from django.shortcuts import render
from rest_framework.views import APIView
from rest_framework.response import Response
from rest_framework import serializers
from rest_framework.exceptions import ValidationError
import re
from django_redis import get_redis_connection

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
        if not ser.is_valid():
            return Response({'status': False,"message":"手机格式错误"})
        phone = ser.validated_data.get("phone")
        CHINA = "+86"

        phone = "{}{}".format(CHINA, phone)
        # 3. 生成验证码
        import random
        random_code = str(random.randint(1000, 9999))

        from tencentcloud.common import credential
        from tencentcloud.common.exception.tencent_cloud_sdk_exception import TencentCloudSDKException
        # 导入对应产品模块的client models。
        from tencentcloud.sms.v20190711 import sms_client, models

        # 导入可选配置类
        from tencentcloud.common.profile.client_profile import ClientProfile
        from tencentcloud.common.profile.http_profile import HttpProfile
        try:
            cred = credential.Credential("AKIDe6IEtHPHuHNCk23oIVS8XgYAWbPwDDwP", "EBrGb0B6k9H8i24qLaYFfogHaeQv96mB")

            # 实例化一个http选项，可选的，没有特殊需求可以跳过。
            httpProfile = HttpProfile()
            # 如果需要指定proxy访问接口，可以按照如下方式初始化hp
            # httpProfile = HttpProfile(proxy="http://用户名:密码@代理IP:代理端口")
            httpProfile.reqMethod = "GET"  # post请求(默认为post请求)
            httpProfile.reqTimeout = 30    # 请求超时时间，单位为秒(默认60秒)
            httpProfile.endpoint = "sms.tencentcloudapi.com"  # 指定接入地域域名(默认就近接入)

            # 非必要步骤:
            # 实例化一个客户端配置对象，可以指定超时时间等配置
            clientProfile = ClientProfile()
            clientProfile.signMethod = "TC3-HMAC-SHA256"  # 指定签名算法
            clientProfile.language = "en-US"
            clientProfile.httpProfile = httpProfile
            
            client = sms_client.SmsClient(cred, "ap-guangzhou", clientProfile)
            req = models.SendSmsRequest()

            req.SmsSdkAppid = "1400583234"
            # 短信签名内容: 使用 UTF-8 编码，必须填写已审核通过的签名，签名信息可登录 [短信控制台] 查看
            req.Sign = "明志与致远"
            req.PhoneNumberSet = [phone, ]
            # 模板 ID: 必须填写已审核通过的模板 ID。模板ID可登录 [短信控制台] 查看
            req.TemplateID = "1160487"
            # 模板参数: 若无模板参数，则设置为空
            req.TemplateParamSet = [random_code, ]
            resp = client.SendSms(req)

            # 输出json格式的字符串回包
            print(resp.to_json_string(indent=2))

        except TencentCloudSDKException as err:
            print(err)

        #5. 把验证码+手机号保存(30s过期)

        
        conn = get_redis_connection()
        conn.set(phone, random_code, ex = 30)

        return Response({"status": True, "message":"发送成功"})