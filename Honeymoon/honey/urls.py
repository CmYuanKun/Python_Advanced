
from django.contrib import admin
from django.conf.urls import url, include
from honey import views

urlpatterns = [
    url(r'^login/', views.LoginView.as_view()),
    url(r'^message/', views.MessageView.as_view()),
]
