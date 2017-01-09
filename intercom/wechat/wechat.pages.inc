<?php
function admin_wechat_sync_account($form, &$form_state)
{
    return wechatForms::getAccountForm($form, $form_state);
}

function admin_wechat_sync_account_submit($form, &$form_state)
{
    return wechatForms::getSubmitForm($form, $form_state);
}
