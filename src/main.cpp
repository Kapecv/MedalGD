#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/PauseLayer.hpp>

using namespace geode::prelude;

class $modify(MedalGDMenu, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;
        auto win = CCDirector::get()->getWinSize();

        auto label = CCLabelBMFont::create("Witaj od tej chwili jak masz naszego moda MedalGD posiadasz moliwo robienia klipw tak jak w medalu ale nie potrzeeba aplikacji.Bawcie si dobrze", "bigFont.fnt");
        label->setScale(0.5f);
        label->setPosition({ win.width / 2, 20.f });
        this->addChild(label);
        return true;
    }
};

class $modify(MedalGDPause, PauseLayer) {
    void customSetup() {
        PauseLayer::customSetup();
        auto spr = ButtonSprite::create("Moj przycisk");
        auto btn = CCMenuItemExt::createSpriteExtra(spr, [](auto*) {
            Notification::create("Zapisano!", NotificationIcon::Success)->show();
        });
        auto menu = CCMenu::create();
        menu->addChild(btn);
        auto win = CCDirector::get()->getWinSize();
        menu->setPosition({ win.width - 70.f, 30.f });
        this->addChild(menu);
    }
};
