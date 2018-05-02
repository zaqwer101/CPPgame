#include "Creature.h"


Creature::Creature(string name, int hp, int mana, int armor, int damage, bool is_NPC, string type, int time_attack) {
    this->stats.armor = armor;
    this->stats.maxarmor = armor;
    this->stats.name = name;
    this->stats.hp = hp;
    this->stats.maxhp = hp;
    this->stats.mana = mana;
    this->stats.maxmana = mana;
    this->stats.damage = damage;
    this->stats.maxdamage = damage;
    this->stats.level = 1;
    this->stats.exp = 0;
    this->stats.exp_to_level = 100;

    this->alive = true;
    this->_is_NPC = is_NPC;
    this->stats.type = type;
    is_in_battle = false;
    this->target = nullptr;

    this->currentAction = ACTION_IDLE;
    this->currentActionRemainingTime = 0;
    this->timings[ACTION_ATTACK] = time_attack;
    this->step = 0;
}

struct _stats Creature::getStats() {
    return this->stats;
}

void Creature::takeDamage_phys(int damage, Creature* attacker) {
    int tmp = this->stats.hp;
    this->stats.hp = this->stats.hp - (damage - this->stats.armor);
    LOG(stats.name + " taken " + to_string(tmp - stats.hp) + " physical damage from " + attacker->getStats().name);
    if(target == nullptr)
    {
        selectTarget(attacker);
    }
    if (this->stats.hp <= 0) {
        this->die();
    }
}

void Creature::attack() {
    Creature* _target = getTarget();
    this->is_in_battle = true;

    if (getTarget()->isAlive()) {
        LOG(getStats().name + " attacked " + getTarget()->getStats().name);
        getTarget()->takeDamage_phys(this->stats.damage, this);
    }

    if (!getTarget()->isAlive()) {
        this->takeExp(getTarget()->stats.maxhp);
        this->is_in_battle = false; // Противник погиб, мы больше не сражаемся
        LOG("Enemy " + target->getStats().name + " died");
    }
}

void Creature::takeExp(int exp) {
    int delta = exp;
    LOG(stats.name + " got " + to_string(exp) + " experience");
    while (delta >= 0) {
        this->stats.exp += delta;

        if (this->stats.exp >= this->stats.exp_to_level) {
            delta -= this->stats.exp_to_level;
            lvlUp();
        } else
            break;
    }
}

void Creature::die() {
    this->stats.hp = 0;
    this->alive = false;
    LOG(stats.name + " died");
}

bool Creature::isAlive() {
    return this->alive;
}

void Creature::lvlUp() {
    this->stats.exp = 0;
    this->stats.exp_to_level *= 2;
    this->stats.level++;
    this->lvlUp_upgradeStats();
    LOG(stats.name + " reached level " + to_string(stats.level));
}

void Creature::changeDamage(int value) {
    this->stats.maxdamage += value;
    this->stats.damage += value;
}

void Creature::changeMaxHP(int value) {
    this->stats.maxhp += value;
    this->stats.hp += value;
}

void Creature::__debug_printStats() {
    cout <<
         "----------------" << endl <<
         "Name: " << this->stats.name << endl <<
         "HP: " << this->stats.hp << "/" << this->stats.maxhp << endl <<
         "Damage: " << this->stats.damage << endl <<
         "Level: " << this->stats.level << endl <<
         "EXP: " << this->stats.exp << "/" << this->stats.exp_to_level << endl <<
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
    LOG(stats.name + " choose target " + target->getStats().name);
}

Creature *Creature::getTarget() {
    return this->target;
}

int Creature::actionGet() {
    return this->currentAction;
}

void Creature::actionStart(int action) {
    if (actionGet() == 0) {
        this->currentAction = action;
        this->currentActionRemainingTime = this->timings[ACTION_ATTACK];
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
                attack();
                break;
        }
        currentAction = ACTION_IDLE;
        currentActionRemainingTime = 0;
    }
    currentActionRemainingTime--;
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


