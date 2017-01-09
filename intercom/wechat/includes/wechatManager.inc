<?php
abstract class wechatManager
{
    const API_WECHAT_SERVER            = 'https://api.wechat.com/cgi-bin';
    const API_ENTERPRISE_WECHAT_SERVER = 'https://qyapi.weixin.qq.com/cgi-bin';
    const MODULE_NAME                  = 'wechat';
    const MENU_ITEM_WECHAT_CONFIG      = 'admin/config/wechat';
    const MENU_ITEM_WECHAT_SYNC        = 'admin/people/wechatsync';
    const WECHAT_PERMISSION            = 'administer users configuration';
    const WECHAT_API_SERVER            = 'wechat_api_server';
    const WECHAT_API_APPID             = 'wechat_api_appid';
    const WECHAT_API_SECRET            = 'wechat_api_secret';
    const WECHAT_API_ENTERPRISE_SERVER = 'wechat_api_enterprise_server';
    const WECHAT_API_CORPID            = 'wechat_api_corpid';
    const WECHAT_API_CORPSECRET        = 'wechat_api_corpsecret';
    const WECHAT_TEMPLATE              = 'wechat_page';
}
