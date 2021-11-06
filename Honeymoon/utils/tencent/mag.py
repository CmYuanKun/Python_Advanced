from tencentcloud.common import credential
from tencentcloud.common.exception.tencent_cloud_sdk_exception import TencentCloudSDKException
# 导入对应产品模块的client models。
from tencentcloud.sms.v20190711 import sms_client, models

# 导入可选配置类
from tencentcloud.common.profile.client_profile import ClientProfile
from tencentcloud.common.profile.http_profile import HttpProfile

def send_message(phone, random_code):
    phone = "{}{}".format("+86", phone)
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
        req.TemplateID = "1162790"
        # 模板参数: 若无模板参数，则设置为空
        req.TemplateParamSet = [random_code, ]
        resp = client.SendSms(req)

        # 输出json格式的字符串回包

        if resp.SendStatusSet[0].Code == "Ok":
            print(resp.to_json_string(indent=2))
            return True
        else:
            return False
            
    except TencentCloudSDKException as err:
        return False