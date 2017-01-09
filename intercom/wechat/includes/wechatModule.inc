<?php
class wechatModule extends wechatManager
{
    public static function getMenu()
    {
        $items = array();
        $items[self::MENU_ITEM_WECHAT_CONFIG] = array(
            'title'            => t('Wechat'),
            'description'      => t('Wechat configuration'),
            'access arguments' => array(self::WECHAT_PERMISSION),
            'page callback'    => 'drupal_get_form',
            'page arguments'   => array('admin_form_wechat_setting'),
            'file'             => 'wechat.pages.admin.inc'
        );

        $items[self::MENU_ITEM_WECHAT_SYNC] = array(
            'title'            => 'Wechat Sync',
            'type'             => MENU_CALLBACK,
            'page callback'    => 'drupal_get_form',
            'page arguments'   => array('admin_wechat_sync_account'),
            'access arguments' => array(self::WECHAT_PERMISSION),
            'file'             => 'wechat.pages.inc'
        );
        return $items;
    }

    public static function getPermissions()
    {
        return array(
            self::WECHAT_PERMISSION => array(
                'title'       => 'access wechat account',
                'description' => 'access manage account for drcom'
            )
        );
    }

    /**
   * Implements the theme array for this type of domain access revision class.
   * For further information check: http://api.drupal.org/api/drupal/modules%21system%21system.api.php/function/hook_theme/7
   */
    public static function getTheme($existing, $type, $theme, $path)
    {
        return array(
            self::WECHAT_TEMPLATE => array(
                'template' => 'template/wechat-page',
                'variables' => array('viewresults' => null, 'tags' => null)
            )
        );
    }
}
