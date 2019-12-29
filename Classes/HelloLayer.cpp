//
// Created by farmer on 2018/6/24.
//

#include "HelloLayer.h"
#include "GameSceneManager.h"
#include "ViewControl.h"
#include "ViewObject.h"

HelloLayer::HelloLayer() {
    initLayer();
}

HelloLayer::~HelloLayer() {
    cocos2d::log("release Hello Layer");
}

void HelloLayer::initLayer() {
    cocos2d::log("init Hello Layer");
    m_pLayer = CSLoader::createNode("res/HelloLayer.csb");  //加载Cocostudio创建的Layer
    m_pLayer->addChild(this, -1);
    setTouchEventListener(m_pLayer);
}

Node *HelloLayer::GetLayer() {
    return m_pLayer;
}

/**
 * 按钮事件
 * @param pWidget
 * @param pName
 */
void HelloLayer::onTouchEnded(ui::Widget *pWidget, const char *pName) {
    cocos2d::log("控件:%s 触发onTouchEnded事件", pName);
    GameSceneManager::getInstance()->alert("欢迎运行此游戏，此游戏是基于Cocos2d-X的开源单机麻将\n", false, false, this, CC_CALLFUNCN_SELECTOR(HelloLayer::GoToGameLayer));
}

/**
 * 进入游戏层
 * @param pNode
 */
void HelloLayer::GoToGameLayer(Node *pNode) {
    cocos2d::log("进入游戏层");
    ViewObject *pObject = ViewObject::create("GameLayer");
    auto dispatcher = Director::getInstance()->getEventDispatcher();
    dispatcher->dispatchCustomEvent(ccNd_ViewNotify, pObject);
}
