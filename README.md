# 🎲 Jeu du 421

Un jeu de dés classique français développé en C, offrant une expérience complète avec interface console, mode solo contre IA et multijoueur local.

## 📋 Description

Le 421 est un jeu de dés traditionnel où deux joueurs s'affrontent en lançant trois dés. L'objectif est d'obtenir la combinaison la plus puissante pour gagner des jetons et éliminer son adversaire.

## ✨ Fonctionnalités

- 🎮 **Deux modes de jeu**
  - Joueur vs Joueur (local)
  - Joueur vs IA
  
- 🎯 **Système de jeu complet**
  - Système de puissance basé sur les combinaisons de dés
  - Mécanisme de jetons avec pot central (21 jetons)
  - Phases de jeu : Charge (C) et Décharge (D)
  - Jusqu'à 3 relances par tour
  
- 🤖 **IA intelligente**
  - Stratégie adaptative basée sur la puissance des dés
  - Relance automatique des dés faibles
  
- 🎨 **Interface console soignée**
  - Affichage ASCII art des dés
  - Interface claire et intuitive
  - Compatible Windows et Linux

## 🏗️ Structure du projet

```
421/
├── main.c          # Point d'entrée du programme
├── game.c/h        # Logique principale du jeu
├── rules.c/h       # Règles et calculs de puissance
├── dice.c/h        # Gestion et affichage des dés
├── ai.c/h          # Intelligence artificielle
└── utils.c/h       # Fonctions utilitaires
```

## 📊 Hiérarchie des combinaisons

| Rang | Combinaison | Puissance | Jetons |
|------|-------------|-----------|--------|
| 1 | 4-2-1 | 1 | 10 |
| 2 | 1-1-1 | 2 | 7 |
| 3 | 1-1-6 | 3 | 6 |
| 4 | 6-6-6 | 4 | 6 |
| 5 | 1-1-5 | 5 | 5 |
| 6 | 5-5-5 | 6 | 5 |
| 7 | 1-1-4 | 7 | 4 |
| 8 | 4-4-4 | 8 | 4 |
| 9 | 1-1-3 | 9 | 3 |
| 10 | 3-3-3 | 10 | 3 |
| 11 | 1-1-2 | 11 | 2 |
| 12 | 2-2-2 | 12 | 2 |
| 13 | 6-5-4 | 13 | 2 |
| 14 | 5-4-3 | 14 | 2 |
| 15 | 4-3-2 | 15 | 2 |
| 16 | 3-2-1 | 16 | 2 |
| 17 | 2-2-1 (Nenette) | 17 | Victoire automatique |
| 18 | Autre | 18 | 1 |

*Note : Pour les combinaisons de puissance 18, le gagnant est déterminé par la somme des dés.*

## 🎮 Règles du jeu

### Déroulement d'une partie

1. **Phase initiale** : Manche de détermination pour savoir qui commence
2. **Phase de Charge** (C) : Les joueurs accumulent des jetons depuis le pot (21 jetons)
3. **Phase de Décharge** (D) : Une fois le pot vide, les joueurs s'échangent leurs jetons
4. **Victoire** : Le premier joueur à atteindre 0 jeton remporte la partie

### Tour de jeu

- Chaque joueur lance 3 dés
- Possibilité de relancer certains dés (jusqu'à 3 lancers maximum)
- Le second joueur ne peut pas faire plus de lancers que le premier
- Comparaison des puissances pour déterminer le perdant
- Le perdant récupère des jetons selon la puissance du gagnant

## 🚀 Compilation et exécution

### Avec Code::Blocks

1. Ouvrir Code::Blocks
2. Ajouter un projet existant
3. Ouvrire le dossier contenant le projet

### En ligne de commande

#### Windows (MinGW)
```bash
gcc main.c game.c rules.c dice.c ai.c utils.c -o 421.exe
421.exe
```

#### Linux/Mac
```bash
gcc main.c game.c rules.c dice.c ai.c utils.c -o 421
./421
```

## 🎯 Utilisation

1. Lancez le programme
2. Choisissez votre mode de jeu (1 ou 2)
3. Suivez les instructions à l'écran
4. Pour relancer des dés, entrez leurs numéros (ex: "13" pour relancer les dés 1 et 3)
5. Appuyez sur Entrée pour continuer entre les tours

## 🛠️ Prérequis

- Compilateur C (GCC, MinGW, ou autre)
- Code::Blocks (recommandé) ou tout autre IDE C
- Système d'exploitation : Windows, Linux ou macOS

## 📝 Licence

Projet éducatif libre d'utilisation.

## 👨‍💻 Contribution

Ce projet est un jeu complet et fonctionnel. Les améliorations possibles :
- Ajout de graphismes SDL
- Sauvegarde des parties
- Mode multijoueur en réseau
- Statistiques et historique des parties
- Niveaux de difficulté pour l'IA

---

**Bon jeu ! 🎲🎲🎲**