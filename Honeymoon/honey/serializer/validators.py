import re
from rest_framework.exceptions import ValidationError

def phone_validator(value):
    if not re.match("^1[3|4|5|8][0-9]\d{4,8}$", value):
        raise ValidationError("手机格式错误")