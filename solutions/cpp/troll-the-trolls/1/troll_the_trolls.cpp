
namespace hellmath {

enum class AccountStatus {
    troll,
    guest,
    user,
    mod
};

enum class Action {
    read,
    write,
    remove
};

bool display_post(AccountStatus poster, AccountStatus viewer) {
    if (poster == AccountStatus::troll) {
        return viewer == AccountStatus::troll;
    }
    return true;
}   

bool permission_check(Action action, AccountStatus account) {
    if (action == Action::write) {
        return account != AccountStatus::guest;
    }   
    else if (action == Action::remove) {
        return account == AccountStatus::mod;
    }
    return true;
}

bool valid_player_combination(AccountStatus account, AccountStatus player) {
    if (player == AccountStatus::guest || account == AccountStatus::guest) {
        return false;
    }
    if (player == AccountStatus::troll || account == AccountStatus::troll) {
        return player == AccountStatus::troll && account == AccountStatus::troll;
    }
    return true;
}   
    
bool has_priority(AccountStatus first, AccountStatus second) {
 return static_cast<int>(first) > static_cast<int>(second);
}   

}  // namespace hellmath
