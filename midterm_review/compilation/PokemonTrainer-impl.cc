module PokemonTrainer;

using namespace std;

PokemonTrainer::PokemonTrainer(string name, Pokemon poke): name{name}, favourite{poke} {}

void PokemonTrainer::challenge(const PokemonTrainer &opponent) const {
    strong_ordering result = combat(favourite, opponent.favourite);
    if (result < 0) cout << name << "'s " << favourite.name << " lost to "<< opponent.name << "'s " << opponent.favourite.name << endl;
    else if (result == 0) cout << favourite.name << " and " << opponent.favourite.name << " ties" << endl;
    else cout << name << "'s " << favourite.name << " won against "<< opponent.name << "'s " << opponent.favourite.name << endl;
}
