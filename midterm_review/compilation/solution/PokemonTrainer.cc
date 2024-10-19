export module PokemonTrainer;
import Pokemon;
import <iostream>;
import <string>;

export struct PokemonTrainer {
    std::string name;
    Pokemon favourite;
    PokemonTrainer(std::string name, Pokemon poke);
    void challenge (const PokemonTrainer &opponent) const;
};