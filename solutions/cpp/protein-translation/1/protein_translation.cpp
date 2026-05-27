#include "protein_translation.h"
#include <stdexcept>
namespace protein_translation {

std::vector<std::string> proteins(const std::string& rna) {
    std::vector<std::string> result;


auto codon_to_protein = [](const std::string& codon) -> std::string {
    if (codon  == "AUG") return "Methionine";
    if (codon  == "UUU" || codon  == "UUC") return "Phenylalanine";
    if (codon  == "UUA" || codon  == "UUG") return "Leucine";
    if (codon  == "UCU" || codon  == "UCC" || codon  == "UCA" || codon  == "UCG") return "Serine";
    if (codon  == "UAU" || codon  == "UAC") return "Tyrosine";
    if (codon  == "UGU" || codon  == "UGC") return "Cysteine";
    if (codon  == "UGG" ) return "Tryptophan";
    if (codon  == "UAA" || codon  == "UAG" || codon  == "UGA") return "STOP";
    throw std::invalid_argument("invalid argument:" + codon);
};


    for (size_t i = 0; i + 3 <= rna.size(); i += 3) {
        std::string codon = rna.substr(i, 3);
        std::string protein = codon_to_protein(codon);

        if (protein == "STOP") break;    

        result.push_back(protein);
    }
    return result;
} } // namespace protein_translation
