#ifndef GUARD_CONFIG_DUAL_EMERALD_H
#define GUARD_CONFIG_DUAL_EMERALD_H

// Dual Emerald settings. See docs/DUAL_EMERALD_MASTER_DESIGN.md and docs/DUAL_EMERALD_IMPLEMENTATION_PLAN.md.

// Learned abilities
#define DE_MAX_LEARNABLE_ABILITIES       8          // Maximum entries in a species' learnable ability list. Bounded by the ability memory bits in BoxPokemon; do not raise without freeing more save data.

// Summary screen
#define DE_SUMMARY_ABILITY_TOGGLE_BUTTON R_BUTTON   // Button that swaps between the natural and learned ability on the summary screen's info page.

#endif // GUARD_CONFIG_DUAL_EMERALD_H
