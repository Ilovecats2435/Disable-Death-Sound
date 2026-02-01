#include <geode/Geode.hpp>
#include <geode/modify/PlayerObject.hpp>

using namespace geode::prelude;
$on_mod(Loaded) {
    Mod::get()->addBoolSetting({
        "disable-death-sound",
        "Disable Death Sound",
        "Stops the death sound from playing",
        true
    });
}
class $modify(PlayerObject) {
    void playDeathEffect() {
        if (Mod::get()->getSettingValue<bool>("disable-death-sound")) {
            // call original WITHOUT sound
            return;
        }
        PlayerObject::playDeathEffect();
    }
};
