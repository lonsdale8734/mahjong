//
// Created by farmer on 2018/6/27.
//

#include "BaseUILayer.h"


void BaseUILayer::setTouchEventListener(Node *pNode, bool button, bool imageView) {
    if (pNode) {
        const auto &arrayRootChildren = pNode->getChildren();
        for (auto &subWidget : arrayRootChildren) {
            Node *child = dynamic_cast<Node *>(subWidget);
            ui::Button *pButtonWidget = dynamic_cast<ui::Button *>(child);          //按钮
            ui::ImageView *pImageViewWidget = dynamic_cast<ui::ImageView *>(child); //图片
            if (pButtonWidget != NULL && button) {
                cocos2d::log("set button touch listener");
                pButtonWidget->addTouchEventListener(CC_CALLBACK_2(BaseUILayer::onTouch, this));
            }
            if (pImageViewWidget != NULL && imageView) {
                cocos2d::log("set image touch listener");
                pImageViewWidget->addTouchEventListener(CC_CALLBACK_2(BaseUILayer::onTouch, this));
            }
            if (child) {
                cocos2d::log("set touch listener");
                setTouchEventListener(child);
            }
        }
    }
}

void BaseUILayer::onTouch(Ref *ref, ui::Widget::TouchEventType eventType) {
    ui::Widget *pWidget = dynamic_cast<ui::Widget *>(ref);
    if (pWidget != NULL) {
        const char *pName = pWidget->getName().c_str();
        switch (eventType) {
            case ui::Widget::TouchEventType::ENDED:
                cocos2d::log("touched ended %s", pName);
                onTouchEnded(pWidget, pName);
                break;
            case ui::Widget::TouchEventType::BEGAN:
                cocos2d::log("touched began %s", pName);
                break;
            case ui::Widget::TouchEventType::MOVED:
                cocos2d::log("touched moved %s", pName);
                break;
            default:
                cocos2d::log("touched cancelled %s", pName);
                break;
        }
    }
}

void BaseUILayer::initLayer(){

}

void BaseUILayer::onTouchBegan(ui::Widget *pWidget, const char *pName) {

}

void BaseUILayer::onTouchMoved(ui::Widget *pWidget, const char *pName) {

}

void BaseUILayer::onTouchCanceled(ui::Widget *pWidget, const char *pName) {

}

void BaseUILayer::onTouchEnded(ui::Widget *pWidget, const char *pName) {

}
