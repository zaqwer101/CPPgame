#include "Creature.h"


Creature::Creature(string name, int hp, int mana, int armor, int damage, bool is_NPC, string type, int time_attack) {
    this->_stats.armor = armor;
    this->_stats.maxarmor = armor;
    this->_stats.name = name;
    this->_stats.hp = hp;
    this->_stats.maxhp = hp;
    this->_stats.mana = mana;
    this->_stats.maxmana = mana;
    this->_stats.damage = damage;
    this->_stats.maxdamage = damage;
    this->_stats.level = 1;
    this->_stats.exp = 0;
    this->_stats.exp_to_level = 100;
    this->_stats.maxspeed = this->_stats.speed = 2;
    this->_stats.attack_range = 0; // Все существа по умолчанию могут атаковать лишь в упор

    this->alive = true;
    this->_is_NPC = is_NPC;
    this->_stats.type = type;
    is_in_battle = false;
    this->target = nullptr;

    this->currentAction = ACTION_IDLE;
    this->currentActionRemainingTime = 0;
    this->timings[ACTION_ATTACK] = time_attack;
    this->step = 0;

    this->resists["fire"] = 0;
}

struct stats Creature::getStats() {
    return this->_stats;
}

void Creature::takeDamage_phys(int damage, Creature* attacker) {
    int tmp = this->getStats().hp;
    this->_stats.hp = this->_stats.hp - (damage - this->_stats.armor);
    LOG(_stats.name + " taken " + to_string(tmp - _stats.hp) + " physical damage from " + attacker->getStats().name);

    if (this->_stats.hp <= 0) {
        this->die();
    } else {
        if (target == nullptr) {
            selectTarget(attacker);
        }
    }
}

void Creature::takeDamage_magic(Creature *attacker, MagicSpell *spell) {
    int tmp = this->getStats().hp;
    this->_stats.hp -= static_cast<int>(
            spell->getPower() - (spell->getPower() * getResist(spell->getType()))
    );
    LOG(_stats.name + " taken " + to_string(tmp - _stats.hp) + " " + spell->getType() + " damage from " +
        attacker->getStats().name);

    if (this->_stats.hp <= 0) {
        this->die();
    } else {
        if (target == nullptr) {
            selectTarget(attacker);
        }
    }
}

void Creature::attack_magic() {
    this->is_in_battle = true;
    if (getTarget()->isAlive()) {
        getTarget()->takeDamage_magic(this, getSpell(currentSpell));
        LOG(_stats.name + " casted " + getSpell(currentSpell)->name + " on " + getTarget()->_stats.name);
    }

    if (!getTarget()->isAlive()) {
        this->takeExp(getTarget()->_stats.maxhp);
        this->is_in_battle = false; // Противник погиб, мы больше не сражаемся
        LOG("Enemy " + getTarget()->getStats().name + " died");
    }
}

void Creature::attack_phys() {
    Creature *_target = getTarget();
    this->is_in_battle = true;

    if (getTarget()->isAlive()) {
        LOG(getStats().name + " attacked " + getTarget()->getStats().name);
        getTarget()->takeDamage_phys(this->_stats.damage, this);
    }

    if (!getTarget()->isAlive()) {
        this->takeExp(getTarget()->_stats.maxhp);
        this->is_in_battle = false; // Противник погиб, мы больше не сражаемся
        LOG("Enemy " + target->getStats().name + " died");
    }
}

void Creature::takeExp(int exp) {
    int delta = exp;
    LOG(_stats.name + " got " + to_string(exp) + " experience");
    while (delta >= 0) {
        this->_stats.exp += delta;

        if (this->_stats.exp >= this->_stats.exp_to_level) {
            delta -= this->_stats.exp_to_level;
            lvlUp();
        } else
            break;
    }
}

void Creature::die() {
    this->_stats.hp = 0;
    this->alive = false;
    LOG(_stats.name + " died");
}

bool Creature::isAlive() {
    return this->alive;
}

void Creature::lvlUp() {
    this->_stats.exp = 0;
    this->_stats.exp_to_level *= 2;
    this->_stats.level++;
    this->lvlUp_upgradeStats();
    LOG(_stats.name + " reached level " + to_string(_stats.level));
}

void Creature::changeDamage(int value) {
    this->_stats.maxdamage += value;
    this->_stats.damage += value;
}

void Creature::changeMaxHP(int value) {
    this->_stats.maxhp += value;
    this->_stats.hp += value;
}

void Creature::__debug_printStats() {
    cout <<
         "----------------" << endl <<
         "Name: " << this->_stats.name << endl <<
         "HP: " << this->_stats.hp << "/" << this->_stats.maxhp << endl <<
         "Damage: " << this->_stats.damage << endl <<
         "Level: " << this->_stats.level << endl <<
         "EXP: " << this->_stats.exp << "/" << this->_stats.exp_to_level << endl <<
         "----------------" << endl;
}

bool Creature::is_NPC() {
    return _is_NPC;
}

void Creature::changeLocation(Location *location) {
    this->location = location;
    this->location->addMember(this);
}

Location *Creature::getLocation() {
    return this->location;
}

bool Creature::isInBattle() {
    return this->is_in_battle;
}

void Creature::selectTarget(Creature *target) {
    this->target = target;
    LOG(_stats.name + " choose target " + target->getStats().name);
}

Creature *Creature::getTarget() {
    return this->target;
}

int Creature::getAction() {
    return this->currentAction;
}

void Creature::actionStart(int action, int action_duration) {
    if (getAction() == 0 && isAlive()) {
        this->currentAction = action;
        this->currentActionRemainingTime = action_duration;
    }
}

int Creature::actionGetTime() {
    return this->currentActionRemainingTime;
}

void Creature::actionStep() {
    step++;
    LOG("Step: " + to_string(step));
    if (currentActionRemainingTime <= 0) {
        switch (currentAction) {
            case ACTION_ATTACK:
                attack_phys();
                break;
            case ACTION_CAST_SPELL:
                getSpell(currentSpell)->use();
                currentSpell = "";
                break;
        }
        currentAction = ACTION_IDLE;
        currentActionRemainingTime = 0;
    }
    currentActionRemainingTime--;

    // Проходим по кулдаунам
    updateCooldowns();
}

void Creature::LOG(string message) {
    log.push_back(message);
}

vector<string> Creature::getLastLog(int count) {
    if (count >= log.size()) {
        return log;
    } else {
        vector<string> tmp;
        for (int i = (log.size() - count); i < log.size(); i++) {
            tmp.push_back(log[i]);
        }
        return tmp;
    }
}

void Creature::lvlUp_upgradeStats() {
    this->changeDamage(static_cast<int>(getStats().damage / 5));
    this->changeMaxHP(static_cast<int>(getStats().maxhp / 5));
}

void Creature::addSpell(MagicSpell *spell) {
    bool notAlreadyInSpellBook = true;

    for (MagicSpell *a : spellBook) {
        if (a->name == spell->name) {
            notAlreadyInSpellBook = false;
            break;
        }
    }

    if (notAlreadyInSpellBook) {
        spell->setCaster(this);
        spellBook.push_back(spell);
    }
}

vector<MagicSpell *> Creature::getSpells() {
    return spellBook;
}

void Creature::castSpell(MagicSpell *spell) {

    if (currentSpell != "") {
        return;
    }

    if (getCooldown(spell->name) == 0) {
        if (getStats().mana >= spell->getManacost()) {
            this->_stats.mana -= spell->getManacost();
            this->currentSpell = spell->name;
            actionStart(ACTION_CAST_SPELL, spell->getCastTime());
            setCooldown(spell->name, this->getSpell(currentSpell)->cooldown);
            LOG("Preparing to cast " + spell->name);
        } else
            LOG("Not enough mana");
    } else
        LOG("This spell is still under cooldown");
}

int Creature::getResist(string type) {
    return resists[type];
}

MagicSpell *Creature::getCurrentSpell() {
    return this->getSpell(currentSpell);
}

void Creature::updateCooldowns() {

}

vector<string> Creature::getLog() {
    return this->log;
}

void Creature::heal(int value) {
    this->_stats.hp += value;
    if (this->_stats.hp > _stats.maxhp)
        _stats.hp = _stats.maxhp;
    LOG(_stats.name + " healed on " + to_string(value));
}

bool Creature::isIdle() {
    return currentAction == ACTION_IDLE;
}

bool Creature::hasEnoughMana(MagicSpell *cast) {
    return _stats.mana >= cast->getManacost();
}

void Creature::attack() {
    if (isIdle() && this->getTarget()) {
        actionStart(ACTION_ATTACK, this->timings[ACTION_ATTACK]);
    }
}

MagicSpell *Creature::getSpell(string name) {
    for (MagicSpell *spell : spellBook) {
        if (spell->name == name)
            return spell;
    }
    return nullptr;
}

int Creature::getCooldown(string name) {
    for (cooldown c : cooldowns) {
        if (c.name == name) {
            return c.value;
        }
    }
    return NULL;
}

void Creature::setCooldown(string name, int value) {
    cooldown c = {name, value};
    cooldowns.push_back(c);
}

