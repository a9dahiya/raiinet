import Pokemon;
import PokemonTrainer;

int main() {
    Pokemon p1("Gengar", 60);
    Pokemon p2("Incineroar", 80);
    PokemonTrainer trainer1("Ash", p1);
    PokemonTrainer trainer2("Gary", p2);
    trainer1.challenge(trainer2);
    trainer2.challenge(trainer1);
}
