<?php
class wechatForms extends wechatManager
{
    public static function getSettingsForm()
    {
        $form = array();
        $form['wechat'] = array(
            '#type'        => 'fieldset',
            '#title'       => t('Subscription settings'),
            '#collapsible' => true,
            '#collapsed'   => false
        );
        $form['wechat'][self::WECHAT_API_SERVER] = array(
            '#type'          => 'textfield',
            '#size'          => 156,
            '#title'         => t('Wechat subscription server api'),
            '#description'   => t('Configure webchat subscription server api'),
            '#default_value' => variable_get(self::WECHAT_API_SERVER, self::API_WECHAT_SERVER),
            '#required'      => true
        );
        $form['wechat'][self::WECHAT_API_APPID] = array(
            '#type'          => 'textfield',
            '#size'          => 156,
            '#title'         => t('Wechat AppID'),
            '#description'   => t('Configuration Application ID'),
            '#default_value' => variable_get(self::WECHAT_API_APPID, 'wxe6d2bf8e9bd1722f'),
            '#required'      => true
        );
        $form['wechat'][self::WECHAT_API_SECRET] = array(
            '#type'          => 'textfield',
            '#size'          => 156,
            '#maxlength'     => 256,
            '#title'         => t('Wechat AppSecret'),
            '#description'   => t('Configuration secret key for application'),
            '#default_value' => variable_get(self::WECHAT_API_SECRET, '839d72f8c3c4b8f98800030b3ed0bbfb'),
            '#required'      => true
        );

        $form['wechat_enterprise'] = array(
            '#type'        => 'fieldset',
            '#title'       => t('Enterprise settings'),
            '#collapsible' => true,
            '#collapsed'   => true
        );
        $form['wechat_enterprise'][self::WECHAT_API_ENTERPRISE_SERVER] = array(
            '#type'          => 'textfield',
            '#size'          => 156,
            '#title'         => t('Wechat Enterprise Server Api'),
            '#description'   => t('Configure Wechat Enterprise Server API'),
            '#default_value' => variable_get(self::WECHAT_API_ENTERPRISE_SERVER, self::API_ENTERPRISE_WECHAT_SERVER),
            '#required'      => true
        );
        $form['wechat_enterprise'][self::WECHAT_API_CORPID] = array(
            '#type'          => 'textfield',
            '#size'          => 156,
            '#title'         => t('Wechat CorpID'),
            '#description'   => t('Configure Corp ID'),
            '#default_value' => variable_get(self::WECHAT_API_CORPID, 'wxdf326e62157fc295')
        );
        $form['wechat_enterprise'][self::WECHAT_API_CORPSECRET] = array(
            '#type'          => 'textfield',
            '#size'          => 156,
            '#title'         => t('Wechat CorpSecret'),
            '#description'   => t('Configure CorpSecret key for application'),
            '#default_value' => variable_get(self::WECHAT_API_CORPSECRET, '3oko44POZz5G_cB0IMEWtonosk8ENSrmM-sbtLVDhe_ojmj4Nbq5l98XQqAVuOFw'),
            '#required'      => true
        );
        return system_settings_form($form);
    }

    public static function getAccountForm($form = array(), &$form_state)
    {
        $header = array(
            'username' => array(
                'data'  => t('Username'),
                'field' => 'u.name'
            ),
            'status' => array(
                'data'  => t('Status'),
                'field' => 'u.status'
            ),
            'roles' => array(
                'data' => t('Roles')
            ),
            'mail' => array(
                'data' => t('Email')
            ),
            'mobile' => array(
                'data' => t('Mobile')
            ),
            'department' => array(
                'data' => t('Department')
            ),
        );
        $form['account'] = array(
            '#type'    => 'tableselect',
            '#header'  => $header,
            '#options' => self::getUserList(100, $header),
            '#empty'   => t('No people available.')
        );
        $form['pager'] =  array('#markup' => theme('pager'));
        $form['submit'] = array(
            '#type'  => 'submit',
            '#value' => t('Sync')
        );
        return $form;
    }

    protected static function getUserList($limit = 100, $order = array())
    {
        $query = db_select('users', 'u');
        $query->condition('u.uid', 0, '<>');
        user_build_filter_query($query);

        $count_query = clone $query;
        $count_query->addExpression('COUNT(u.uid)');
        $query = $query->extend('PagerDefault')->extend('TableSort');
        $query
            ->fields('u', array('uid', 'name', 'status'))
            ->limit($limit)
            ->orderByHeader($order)
            ->setCountQuery($count_query);
        $results = $query->execute();
        $options = array();
        $status = array(t('blocked'), t('active'));
        foreach ($results as $key => $item) {
            $options[$item->uid] = array(
                'username' => theme('username', array('account' => $item)),
                'status'   => $status[$item->status],
                'mail'     => '',
                'mobile'   => '',
                'roles'    => '',
            );
        }
        return $options;
    }

    public static function getValidateForm($form, &$form_state)
    {
    }

    public static function getSubmitForm($form, &$form_state)
    {

    }
}
