// Dual Emerald: learnable (AM-compatible) ability lists for each species.
// Each list is ABILITY_NONE-terminated and holds at most DE_MAX_LEARNABLE_ABILITIES entries.
// Rules (enforced by test/learned_ability.c):
// - An evolution's list starts with its pre-evolution's list, entry for entry; new abilities go at the end.
// - Species linked by a form change share one list.
// - No ability with cantBeSwapped set may appear in a list.
// Generated once by dev_scripts/dual_emerald/generate_learnable_abilities.py; edit by hand from now on.

#if (P_FAMILY_BULBASAUR)
static const u16 sBulbasaurLearnableAbilities[] = {
    ABILITY_OVERGROW,
    ABILITY_CHLOROPHYLL,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_BULBASAUR)
static const u16 sIvysaurLearnableAbilities[] = {
    ABILITY_OVERGROW,
    ABILITY_CHLOROPHYLL,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_BULBASAUR)
static const u16 sVenusaurLearnableAbilities[] = {
    ABILITY_OVERGROW,
    ABILITY_CHLOROPHYLL,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CHARMANDER)
static const u16 sCharmanderLearnableAbilities[] = {
    ABILITY_BLAZE,
    ABILITY_SOLAR_POWER,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CHARMANDER)
static const u16 sCharmeleonLearnableAbilities[] = {
    ABILITY_BLAZE,
    ABILITY_SOLAR_POWER,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CHARMANDER)
static const u16 sCharizardLearnableAbilities[] = {
    ABILITY_BLAZE,
    ABILITY_SOLAR_POWER,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SQUIRTLE)
static const u16 sSquirtleLearnableAbilities[] = {
    ABILITY_TORRENT,
    ABILITY_RAIN_DISH,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SQUIRTLE)
static const u16 sWartortleLearnableAbilities[] = {
    ABILITY_TORRENT,
    ABILITY_RAIN_DISH,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SQUIRTLE)
static const u16 sBlastoiseLearnableAbilities[] = {
    ABILITY_TORRENT,
    ABILITY_RAIN_DISH,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CATERPIE)
static const u16 sCaterpieLearnableAbilities[] = {
    ABILITY_SHIELD_DUST,
    ABILITY_RUN_AWAY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CATERPIE)
static const u16 sMetapodLearnableAbilities[] = {
    ABILITY_SHIELD_DUST,
    ABILITY_RUN_AWAY,
    ABILITY_SHED_SKIN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CATERPIE)
static const u16 sButterfreeLearnableAbilities[] = {
    ABILITY_SHIELD_DUST,
    ABILITY_RUN_AWAY,
    ABILITY_SHED_SKIN,
    ABILITY_COMPOUND_EYES,
    ABILITY_TINTED_LENS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_WEEDLE)
static const u16 sWeedleLearnableAbilities[] = {
    ABILITY_SHIELD_DUST,
    ABILITY_RUN_AWAY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_WEEDLE)
static const u16 sKakunaLearnableAbilities[] = {
    ABILITY_SHIELD_DUST,
    ABILITY_RUN_AWAY,
    ABILITY_SHED_SKIN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_WEEDLE)
static const u16 sBeedrillLearnableAbilities[] = {
    ABILITY_SHIELD_DUST,
    ABILITY_RUN_AWAY,
    ABILITY_SHED_SKIN,
    ABILITY_SWARM,
    ABILITY_SNIPER,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PIDGEY)
static const u16 sPidgeyLearnableAbilities[] = {
    ABILITY_KEEN_EYE,
    ABILITY_TANGLED_FEET,
    ABILITY_BIG_PECKS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PIDGEY)
static const u16 sPidgeottoLearnableAbilities[] = {
    ABILITY_KEEN_EYE,
    ABILITY_TANGLED_FEET,
    ABILITY_BIG_PECKS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PIDGEY)
static const u16 sPidgeotLearnableAbilities[] = {
    ABILITY_KEEN_EYE,
    ABILITY_TANGLED_FEET,
    ABILITY_BIG_PECKS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_RATTATA)
static const u16 sRattataLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_GUTS,
    ABILITY_HUSTLE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_RATTATA)
static const u16 sRaticateLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_GUTS,
    ABILITY_HUSTLE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_RATTATA) && (P_ALOLAN_FORMS)
static const u16 sRattataAlolaLearnableAbilities[] = {
    ABILITY_GLUTTONY,
    ABILITY_HUSTLE,
    ABILITY_THICK_FAT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_RATTATA) && (P_ALOLAN_FORMS)
static const u16 sRaticateAlolaLearnableAbilities[] = {
    ABILITY_GLUTTONY,
    ABILITY_HUSTLE,
    ABILITY_THICK_FAT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_RATTATA) && (P_ALOLAN_FORMS)
static const u16 sRaticateAlolaTotemLearnableAbilities[] = {
    ABILITY_GLUTTONY,
    ABILITY_HUSTLE,
    ABILITY_THICK_FAT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SPEAROW)
static const u16 sSpearowLearnableAbilities[] = {
    ABILITY_KEEN_EYE,
    ABILITY_SNIPER,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SPEAROW)
static const u16 sFearowLearnableAbilities[] = {
    ABILITY_KEEN_EYE,
    ABILITY_SNIPER,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_EKANS)
static const u16 sEkansLearnableAbilities[] = {
    ABILITY_INTIMIDATE,
    ABILITY_SHED_SKIN,
    ABILITY_UNNERVE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_EKANS)
static const u16 sArbokLearnableAbilities[] = {
    ABILITY_INTIMIDATE,
    ABILITY_SHED_SKIN,
    ABILITY_UNNERVE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PIKACHU) && (P_GEN_2_CROSS_EVOS)
static const u16 sPichuLearnableAbilities[] = {
    ABILITY_STATIC,
    ABILITY_LIGHTNING_ROD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PIKACHU) && (P_GEN_2_CROSS_EVOS)
static const u16 sPichuSpikyEaredLearnableAbilities[] = {
    ABILITY_STATIC,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PIKACHU)
static const u16 sPikachuLearnableAbilities[] = {
    ABILITY_STATIC,
    ABILITY_LIGHTNING_ROD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PIKACHU) && (P_COSPLAY_PIKACHU_FORMS)
static const u16 sPikachuCosplayLearnableAbilities[] = {
    ABILITY_STATIC,
    ABILITY_LIGHTNING_ROD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PIKACHU) && (P_COSPLAY_PIKACHU_FORMS)
static const u16 sPikachuRockStarLearnableAbilities[] = {
    ABILITY_STATIC,
    ABILITY_LIGHTNING_ROD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PIKACHU) && (P_COSPLAY_PIKACHU_FORMS)
static const u16 sPikachuBelleLearnableAbilities[] = {
    ABILITY_STATIC,
    ABILITY_LIGHTNING_ROD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PIKACHU) && (P_COSPLAY_PIKACHU_FORMS)
static const u16 sPikachuPopStarLearnableAbilities[] = {
    ABILITY_STATIC,
    ABILITY_LIGHTNING_ROD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PIKACHU) && (P_COSPLAY_PIKACHU_FORMS)
static const u16 sPikachuPhdLearnableAbilities[] = {
    ABILITY_STATIC,
    ABILITY_LIGHTNING_ROD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PIKACHU) && (P_COSPLAY_PIKACHU_FORMS)
static const u16 sPikachuLibreLearnableAbilities[] = {
    ABILITY_STATIC,
    ABILITY_LIGHTNING_ROD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PIKACHU) && (P_CAP_PIKACHU_FORMS)
static const u16 sPikachuOriginalLearnableAbilities[] = {
    ABILITY_STATIC,
    ABILITY_LIGHTNING_ROD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PIKACHU) && (P_CAP_PIKACHU_FORMS)
static const u16 sPikachuHoennLearnableAbilities[] = {
    ABILITY_STATIC,
    ABILITY_LIGHTNING_ROD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PIKACHU) && (P_CAP_PIKACHU_FORMS)
static const u16 sPikachuSinnohLearnableAbilities[] = {
    ABILITY_STATIC,
    ABILITY_LIGHTNING_ROD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PIKACHU) && (P_CAP_PIKACHU_FORMS)
static const u16 sPikachuUnovaLearnableAbilities[] = {
    ABILITY_STATIC,
    ABILITY_LIGHTNING_ROD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PIKACHU) && (P_CAP_PIKACHU_FORMS)
static const u16 sPikachuKalosLearnableAbilities[] = {
    ABILITY_STATIC,
    ABILITY_LIGHTNING_ROD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PIKACHU) && (P_CAP_PIKACHU_FORMS)
static const u16 sPikachuAlolaLearnableAbilities[] = {
    ABILITY_STATIC,
    ABILITY_LIGHTNING_ROD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PIKACHU) && (P_CAP_PIKACHU_FORMS)
static const u16 sPikachuPartnerLearnableAbilities[] = {
    ABILITY_STATIC,
    ABILITY_LIGHTNING_ROD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PIKACHU) && (P_CAP_PIKACHU_FORMS)
static const u16 sPikachuWorldLearnableAbilities[] = {
    ABILITY_STATIC,
    ABILITY_LIGHTNING_ROD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PIKACHU)
static const u16 sPikachuStarterLearnableAbilities[] = {
    ABILITY_STATIC,
    ABILITY_LIGHTNING_ROD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PIKACHU)
static const u16 sRaichuLearnableAbilities[] = {
    ABILITY_STATIC,
    ABILITY_LIGHTNING_ROD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PIKACHU) && (P_ALOLAN_FORMS)
static const u16 sRaichuAlolaLearnableAbilities[] = {
    ABILITY_STATIC,
    ABILITY_LIGHTNING_ROD,
    ABILITY_SURGE_SURFER,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SANDSHREW)
static const u16 sSandshrewLearnableAbilities[] = {
    ABILITY_SAND_VEIL,
    ABILITY_SAND_RUSH,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SANDSHREW)
static const u16 sSandslashLearnableAbilities[] = {
    ABILITY_SAND_VEIL,
    ABILITY_SAND_RUSH,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SANDSHREW) && (P_ALOLAN_FORMS)
static const u16 sSandshrewAlolaLearnableAbilities[] = {
    ABILITY_SNOW_CLOAK,
    ABILITY_SLUSH_RUSH,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SANDSHREW) && (P_ALOLAN_FORMS)
static const u16 sSandslashAlolaLearnableAbilities[] = {
    ABILITY_SNOW_CLOAK,
    ABILITY_SLUSH_RUSH,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_NIDORAN)
static const u16 sNidoranFLearnableAbilities[] = {
    ABILITY_POISON_POINT,
    ABILITY_RIVALRY,
    ABILITY_HUSTLE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_NIDORAN)
static const u16 sNidorinaLearnableAbilities[] = {
    ABILITY_POISON_POINT,
    ABILITY_RIVALRY,
    ABILITY_HUSTLE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_NIDORAN)
static const u16 sNidoqueenLearnableAbilities[] = {
    ABILITY_POISON_POINT,
    ABILITY_RIVALRY,
    ABILITY_HUSTLE,
    ABILITY_SHEER_FORCE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_NIDORAN)
static const u16 sNidoranMLearnableAbilities[] = {
    ABILITY_POISON_POINT,
    ABILITY_RIVALRY,
    ABILITY_HUSTLE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_NIDORAN)
static const u16 sNidorinoLearnableAbilities[] = {
    ABILITY_POISON_POINT,
    ABILITY_RIVALRY,
    ABILITY_HUSTLE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_NIDORAN)
static const u16 sNidokingLearnableAbilities[] = {
    ABILITY_POISON_POINT,
    ABILITY_RIVALRY,
    ABILITY_HUSTLE,
    ABILITY_SHEER_FORCE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CLEFAIRY) && (P_GEN_2_CROSS_EVOS)
static const u16 sCleffaLearnableAbilities[] = {
    ABILITY_CUTE_CHARM,
    ABILITY_MAGIC_GUARD,
    ABILITY_FRIEND_GUARD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CLEFAIRY)
static const u16 sClefairyLearnableAbilities[] = {
    ABILITY_CUTE_CHARM,
    ABILITY_MAGIC_GUARD,
    ABILITY_FRIEND_GUARD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CLEFAIRY)
static const u16 sClefableLearnableAbilities[] = {
    ABILITY_CUTE_CHARM,
    ABILITY_MAGIC_GUARD,
    ABILITY_FRIEND_GUARD,
    ABILITY_UNAWARE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_VULPIX)
static const u16 sVulpixLearnableAbilities[] = {
    ABILITY_FLASH_FIRE,
    ABILITY_DROUGHT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_VULPIX)
static const u16 sNinetalesLearnableAbilities[] = {
    ABILITY_FLASH_FIRE,
    ABILITY_DROUGHT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_VULPIX) && (P_ALOLAN_FORMS)
static const u16 sVulpixAlolaLearnableAbilities[] = {
    ABILITY_SNOW_CLOAK,
    ABILITY_SNOW_WARNING,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_VULPIX) && (P_ALOLAN_FORMS)
static const u16 sNinetalesAlolaLearnableAbilities[] = {
    ABILITY_SNOW_CLOAK,
    ABILITY_SNOW_WARNING,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_JIGGLYPUFF) && (P_GEN_2_CROSS_EVOS)
static const u16 sIgglybuffLearnableAbilities[] = {
    ABILITY_CUTE_CHARM,
    ABILITY_COMPETITIVE,
    ABILITY_FRIEND_GUARD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_JIGGLYPUFF)
static const u16 sJigglypuffLearnableAbilities[] = {
    ABILITY_CUTE_CHARM,
    ABILITY_COMPETITIVE,
    ABILITY_FRIEND_GUARD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_JIGGLYPUFF)
static const u16 sWigglytuffLearnableAbilities[] = {
    ABILITY_CUTE_CHARM,
    ABILITY_COMPETITIVE,
    ABILITY_FRIEND_GUARD,
    ABILITY_FRISK,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ZUBAT)
static const u16 sZubatLearnableAbilities[] = {
    ABILITY_INNER_FOCUS,
    ABILITY_INFILTRATOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ZUBAT)
static const u16 sGolbatLearnableAbilities[] = {
    ABILITY_INNER_FOCUS,
    ABILITY_INFILTRATOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ZUBAT) && (P_GEN_2_CROSS_EVOS)
static const u16 sCrobatLearnableAbilities[] = {
    ABILITY_INNER_FOCUS,
    ABILITY_INFILTRATOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ODDISH)
static const u16 sOddishLearnableAbilities[] = {
    ABILITY_CHLOROPHYLL,
    ABILITY_RUN_AWAY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ODDISH)
static const u16 sGloomLearnableAbilities[] = {
    ABILITY_CHLOROPHYLL,
    ABILITY_RUN_AWAY,
    ABILITY_STENCH,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ODDISH)
static const u16 sVileplumeLearnableAbilities[] = {
    ABILITY_CHLOROPHYLL,
    ABILITY_RUN_AWAY,
    ABILITY_STENCH,
    ABILITY_EFFECT_SPORE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ODDISH) && (P_GEN_2_CROSS_EVOS)
static const u16 sBellossomLearnableAbilities[] = {
    ABILITY_CHLOROPHYLL,
    ABILITY_RUN_AWAY,
    ABILITY_STENCH,
    ABILITY_HEALER,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PARAS)
static const u16 sParasLearnableAbilities[] = {
    ABILITY_EFFECT_SPORE,
    ABILITY_DRY_SKIN,
    ABILITY_DAMP,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PARAS)
static const u16 sParasectLearnableAbilities[] = {
    ABILITY_EFFECT_SPORE,
    ABILITY_DRY_SKIN,
    ABILITY_DAMP,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_VENONAT)
static const u16 sVenonatLearnableAbilities[] = {
    ABILITY_COMPOUND_EYES,
    ABILITY_TINTED_LENS,
    ABILITY_RUN_AWAY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_VENONAT)
static const u16 sVenomothLearnableAbilities[] = {
    ABILITY_COMPOUND_EYES,
    ABILITY_TINTED_LENS,
    ABILITY_RUN_AWAY,
    ABILITY_SHIELD_DUST,
    ABILITY_WONDER_SKIN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DIGLETT)
static const u16 sDiglettLearnableAbilities[] = {
    ABILITY_SAND_VEIL,
    ABILITY_ARENA_TRAP,
    ABILITY_SAND_FORCE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DIGLETT)
static const u16 sDugtrioLearnableAbilities[] = {
    ABILITY_SAND_VEIL,
    ABILITY_ARENA_TRAP,
    ABILITY_SAND_FORCE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DIGLETT) && (P_ALOLAN_FORMS)
static const u16 sDiglettAlolaLearnableAbilities[] = {
    ABILITY_SAND_VEIL,
    ABILITY_TANGLING_HAIR,
    ABILITY_SAND_FORCE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DIGLETT) && (P_ALOLAN_FORMS)
static const u16 sDugtrioAlolaLearnableAbilities[] = {
    ABILITY_SAND_VEIL,
    ABILITY_TANGLING_HAIR,
    ABILITY_SAND_FORCE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MEOWTH)
static const u16 sMeowthLearnableAbilities[] = {
    ABILITY_PICKUP,
    ABILITY_TECHNICIAN,
    ABILITY_UNNERVE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MEOWTH)
static const u16 sPersianLearnableAbilities[] = {
    ABILITY_PICKUP,
    ABILITY_TECHNICIAN,
    ABILITY_UNNERVE,
    ABILITY_LIMBER,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MEOWTH) && (P_ALOLAN_FORMS)
static const u16 sMeowthAlolaLearnableAbilities[] = {
    ABILITY_PICKUP,
    ABILITY_TECHNICIAN,
    ABILITY_RATTLED,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MEOWTH) && (P_ALOLAN_FORMS)
static const u16 sPersianAlolaLearnableAbilities[] = {
    ABILITY_PICKUP,
    ABILITY_TECHNICIAN,
    ABILITY_RATTLED,
    ABILITY_FUR_COAT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MEOWTH) && (P_GALARIAN_FORMS)
static const u16 sMeowthGalarLearnableAbilities[] = {
    ABILITY_PICKUP,
    ABILITY_TOUGH_CLAWS,
    ABILITY_UNNERVE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MEOWTH) && (P_GALARIAN_FORMS)
static const u16 sPerrserkerLearnableAbilities[] = {
    ABILITY_PICKUP,
    ABILITY_TOUGH_CLAWS,
    ABILITY_UNNERVE,
    ABILITY_BATTLE_ARMOR,
    ABILITY_STEELY_SPIRIT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PSYDUCK)
static const u16 sPsyduckLearnableAbilities[] = {
    ABILITY_DAMP,
    ABILITY_CLOUD_NINE,
    ABILITY_SWIFT_SWIM,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PSYDUCK)
static const u16 sGolduckLearnableAbilities[] = {
    ABILITY_DAMP,
    ABILITY_CLOUD_NINE,
    ABILITY_SWIFT_SWIM,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MANKEY)
static const u16 sMankeyLearnableAbilities[] = {
    ABILITY_VITAL_SPIRIT,
    ABILITY_ANGER_POINT,
    ABILITY_DEFIANT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MANKEY)
static const u16 sPrimeapeLearnableAbilities[] = {
    ABILITY_VITAL_SPIRIT,
    ABILITY_ANGER_POINT,
    ABILITY_DEFIANT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MANKEY) && (P_GEN_9_CROSS_EVOS)
static const u16 sAnnihilapeLearnableAbilities[] = {
    ABILITY_VITAL_SPIRIT,
    ABILITY_ANGER_POINT,
    ABILITY_DEFIANT,
    ABILITY_INNER_FOCUS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GROWLITHE)
static const u16 sGrowlitheLearnableAbilities[] = {
    ABILITY_INTIMIDATE,
    ABILITY_FLASH_FIRE,
    ABILITY_JUSTIFIED,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GROWLITHE)
static const u16 sArcanineLearnableAbilities[] = {
    ABILITY_INTIMIDATE,
    ABILITY_FLASH_FIRE,
    ABILITY_JUSTIFIED,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GROWLITHE) && (P_HISUIAN_FORMS)
static const u16 sGrowlitheHisuiLearnableAbilities[] = {
    ABILITY_INTIMIDATE,
    ABILITY_FLASH_FIRE,
    ABILITY_ROCK_HEAD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GROWLITHE) && (P_HISUIAN_FORMS)
static const u16 sArcanineHisuiLearnableAbilities[] = {
    ABILITY_INTIMIDATE,
    ABILITY_FLASH_FIRE,
    ABILITY_ROCK_HEAD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_POLIWAG)
static const u16 sPoliwagLearnableAbilities[] = {
    ABILITY_WATER_ABSORB,
    ABILITY_DAMP,
    ABILITY_SWIFT_SWIM,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_POLIWAG)
static const u16 sPoliwhirlLearnableAbilities[] = {
    ABILITY_WATER_ABSORB,
    ABILITY_DAMP,
    ABILITY_SWIFT_SWIM,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_POLIWAG)
static const u16 sPoliwrathLearnableAbilities[] = {
    ABILITY_WATER_ABSORB,
    ABILITY_DAMP,
    ABILITY_SWIFT_SWIM,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_POLIWAG) && (P_GEN_2_CROSS_EVOS)
static const u16 sPolitoedLearnableAbilities[] = {
    ABILITY_WATER_ABSORB,
    ABILITY_DAMP,
    ABILITY_SWIFT_SWIM,
    ABILITY_DRIZZLE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ABRA)
static const u16 sAbraLearnableAbilities[] = {
    ABILITY_SYNCHRONIZE,
    ABILITY_INNER_FOCUS,
    ABILITY_MAGIC_GUARD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ABRA)
static const u16 sKadabraLearnableAbilities[] = {
    ABILITY_SYNCHRONIZE,
    ABILITY_INNER_FOCUS,
    ABILITY_MAGIC_GUARD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ABRA)
static const u16 sAlakazamLearnableAbilities[] = {
    ABILITY_SYNCHRONIZE,
    ABILITY_INNER_FOCUS,
    ABILITY_MAGIC_GUARD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MACHOP)
static const u16 sMachopLearnableAbilities[] = {
    ABILITY_GUTS,
    ABILITY_NO_GUARD,
    ABILITY_STEADFAST,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MACHOP)
static const u16 sMachokeLearnableAbilities[] = {
    ABILITY_GUTS,
    ABILITY_NO_GUARD,
    ABILITY_STEADFAST,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MACHOP)
static const u16 sMachampLearnableAbilities[] = {
    ABILITY_GUTS,
    ABILITY_NO_GUARD,
    ABILITY_STEADFAST,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_BELLSPROUT)
static const u16 sBellsproutLearnableAbilities[] = {
    ABILITY_CHLOROPHYLL,
    ABILITY_GLUTTONY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_BELLSPROUT)
static const u16 sWeepinbellLearnableAbilities[] = {
    ABILITY_CHLOROPHYLL,
    ABILITY_GLUTTONY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_BELLSPROUT)
static const u16 sVictreebelLearnableAbilities[] = {
    ABILITY_CHLOROPHYLL,
    ABILITY_GLUTTONY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TENTACOOL)
static const u16 sTentacoolLearnableAbilities[] = {
    ABILITY_CLEAR_BODY,
    ABILITY_LIQUID_OOZE,
    ABILITY_RAIN_DISH,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TENTACOOL)
static const u16 sTentacruelLearnableAbilities[] = {
    ABILITY_CLEAR_BODY,
    ABILITY_LIQUID_OOZE,
    ABILITY_RAIN_DISH,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GEODUDE)
static const u16 sGeodudeLearnableAbilities[] = {
    ABILITY_ROCK_HEAD,
    ABILITY_STURDY,
    ABILITY_SAND_VEIL,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GEODUDE)
static const u16 sGravelerLearnableAbilities[] = {
    ABILITY_ROCK_HEAD,
    ABILITY_STURDY,
    ABILITY_SAND_VEIL,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GEODUDE)
static const u16 sGolemLearnableAbilities[] = {
    ABILITY_ROCK_HEAD,
    ABILITY_STURDY,
    ABILITY_SAND_VEIL,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GEODUDE) && (P_ALOLAN_FORMS)
static const u16 sGeodudeAlolaLearnableAbilities[] = {
    ABILITY_MAGNET_PULL,
    ABILITY_STURDY,
    ABILITY_GALVANIZE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GEODUDE) && (P_ALOLAN_FORMS)
static const u16 sGravelerAlolaLearnableAbilities[] = {
    ABILITY_MAGNET_PULL,
    ABILITY_STURDY,
    ABILITY_GALVANIZE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GEODUDE) && (P_ALOLAN_FORMS)
static const u16 sGolemAlolaLearnableAbilities[] = {
    ABILITY_MAGNET_PULL,
    ABILITY_STURDY,
    ABILITY_GALVANIZE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PONYTA)
static const u16 sPonytaLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_FLASH_FIRE,
    ABILITY_FLAME_BODY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PONYTA)
static const u16 sRapidashLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_FLASH_FIRE,
    ABILITY_FLAME_BODY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PONYTA) && (P_GALARIAN_FORMS)
static const u16 sPonytaGalarLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_PASTEL_VEIL,
    ABILITY_ANTICIPATION,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PONYTA) && (P_GALARIAN_FORMS)
static const u16 sRapidashGalarLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_PASTEL_VEIL,
    ABILITY_ANTICIPATION,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SLOWPOKE)
static const u16 sSlowpokeLearnableAbilities[] = {
    ABILITY_OBLIVIOUS,
    ABILITY_OWN_TEMPO,
    ABILITY_REGENERATOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SLOWPOKE)
static const u16 sSlowbroLearnableAbilities[] = {
    ABILITY_OBLIVIOUS,
    ABILITY_OWN_TEMPO,
    ABILITY_REGENERATOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SLOWPOKE) && (P_GEN_2_CROSS_EVOS)
static const u16 sSlowkingLearnableAbilities[] = {
    ABILITY_OBLIVIOUS,
    ABILITY_OWN_TEMPO,
    ABILITY_REGENERATOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SLOWPOKE) && (P_GALARIAN_FORMS)
static const u16 sSlowpokeGalarLearnableAbilities[] = {
    ABILITY_GLUTTONY,
    ABILITY_OWN_TEMPO,
    ABILITY_REGENERATOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SLOWPOKE) && (P_GALARIAN_FORMS)
static const u16 sSlowbroGalarLearnableAbilities[] = {
    ABILITY_GLUTTONY,
    ABILITY_OWN_TEMPO,
    ABILITY_REGENERATOR,
    ABILITY_QUICK_DRAW,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SLOWPOKE) && (P_GALARIAN_FORMS) && (P_GEN_2_CROSS_EVOS)
static const u16 sSlowkingGalarLearnableAbilities[] = {
    ABILITY_GLUTTONY,
    ABILITY_OWN_TEMPO,
    ABILITY_REGENERATOR,
    ABILITY_CURIOUS_MEDICINE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MAGNEMITE)
static const u16 sMagnemiteLearnableAbilities[] = {
    ABILITY_MAGNET_PULL,
    ABILITY_STURDY,
    ABILITY_ANALYTIC,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MAGNEMITE)
static const u16 sMagnetonLearnableAbilities[] = {
    ABILITY_MAGNET_PULL,
    ABILITY_STURDY,
    ABILITY_ANALYTIC,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MAGNEMITE) && (P_GEN_4_CROSS_EVOS)
static const u16 sMagnezoneLearnableAbilities[] = {
    ABILITY_MAGNET_PULL,
    ABILITY_STURDY,
    ABILITY_ANALYTIC,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FARFETCHD)
static const u16 sFarfetchdLearnableAbilities[] = {
    ABILITY_KEEN_EYE,
    ABILITY_INNER_FOCUS,
    ABILITY_DEFIANT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FARFETCHD) && (P_GALARIAN_FORMS)
static const u16 sFarfetchdGalarLearnableAbilities[] = {
    ABILITY_STEADFAST,
    ABILITY_SCRAPPY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FARFETCHD) && (P_GALARIAN_FORMS)
static const u16 sSirfetchdLearnableAbilities[] = {
    ABILITY_STEADFAST,
    ABILITY_SCRAPPY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DODUO)
static const u16 sDoduoLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_EARLY_BIRD,
    ABILITY_TANGLED_FEET,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DODUO)
static const u16 sDodrioLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_EARLY_BIRD,
    ABILITY_TANGLED_FEET,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SEEL)
static const u16 sSeelLearnableAbilities[] = {
    ABILITY_THICK_FAT,
    ABILITY_HYDRATION,
    ABILITY_ICE_BODY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SEEL)
static const u16 sDewgongLearnableAbilities[] = {
    ABILITY_THICK_FAT,
    ABILITY_HYDRATION,
    ABILITY_ICE_BODY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GRIMER)
static const u16 sGrimerLearnableAbilities[] = {
    ABILITY_STENCH,
    ABILITY_STICKY_HOLD,
    ABILITY_POISON_TOUCH,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GRIMER)
static const u16 sMukLearnableAbilities[] = {
    ABILITY_STENCH,
    ABILITY_STICKY_HOLD,
    ABILITY_POISON_TOUCH,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GRIMER) && (P_ALOLAN_FORMS)
static const u16 sGrimerAlolaLearnableAbilities[] = {
    ABILITY_POISON_TOUCH,
    ABILITY_GLUTTONY,
    ABILITY_POWER_OF_ALCHEMY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GRIMER) && (P_ALOLAN_FORMS)
static const u16 sMukAlolaLearnableAbilities[] = {
    ABILITY_POISON_TOUCH,
    ABILITY_GLUTTONY,
    ABILITY_POWER_OF_ALCHEMY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SHELLDER)
static const u16 sShellderLearnableAbilities[] = {
    ABILITY_SHELL_ARMOR,
    ABILITY_SKILL_LINK,
    ABILITY_OVERCOAT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SHELLDER)
static const u16 sCloysterLearnableAbilities[] = {
    ABILITY_SHELL_ARMOR,
    ABILITY_SKILL_LINK,
    ABILITY_OVERCOAT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GASTLY)
static const u16 sGastlyLearnableAbilities[] = {
    ABILITY_LEVITATE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GASTLY)
static const u16 sHaunterLearnableAbilities[] = {
    ABILITY_LEVITATE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GASTLY)
static const u16 sGengarLearnableAbilities[] = {
    ABILITY_LEVITATE,
    ABILITY_CURSED_BODY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ONIX)
static const u16 sOnixLearnableAbilities[] = {
    ABILITY_ROCK_HEAD,
    ABILITY_STURDY,
    ABILITY_WEAK_ARMOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ONIX) && (P_GEN_2_CROSS_EVOS)
static const u16 sSteelixLearnableAbilities[] = {
    ABILITY_ROCK_HEAD,
    ABILITY_STURDY,
    ABILITY_WEAK_ARMOR,
    ABILITY_SHEER_FORCE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DROWZEE)
static const u16 sDrowzeeLearnableAbilities[] = {
    ABILITY_INSOMNIA,
    ABILITY_FOREWARN,
    ABILITY_INNER_FOCUS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DROWZEE)
static const u16 sHypnoLearnableAbilities[] = {
    ABILITY_INSOMNIA,
    ABILITY_FOREWARN,
    ABILITY_INNER_FOCUS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_KRABBY)
static const u16 sKrabbyLearnableAbilities[] = {
    ABILITY_HYPER_CUTTER,
    ABILITY_SHELL_ARMOR,
    ABILITY_SHEER_FORCE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_KRABBY)
static const u16 sKinglerLearnableAbilities[] = {
    ABILITY_HYPER_CUTTER,
    ABILITY_SHELL_ARMOR,
    ABILITY_SHEER_FORCE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_VOLTORB)
static const u16 sVoltorbLearnableAbilities[] = {
    ABILITY_SOUNDPROOF,
    ABILITY_STATIC,
    ABILITY_AFTERMATH,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_VOLTORB)
static const u16 sElectrodeLearnableAbilities[] = {
    ABILITY_SOUNDPROOF,
    ABILITY_STATIC,
    ABILITY_AFTERMATH,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_VOLTORB) && (P_HISUIAN_FORMS)
static const u16 sVoltorbHisuiLearnableAbilities[] = {
    ABILITY_SOUNDPROOF,
    ABILITY_STATIC,
    ABILITY_AFTERMATH,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_VOLTORB) && (P_HISUIAN_FORMS)
static const u16 sElectrodeHisuiLearnableAbilities[] = {
    ABILITY_SOUNDPROOF,
    ABILITY_STATIC,
    ABILITY_AFTERMATH,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_EXEGGCUTE)
static const u16 sExeggcuteLearnableAbilities[] = {
    ABILITY_CHLOROPHYLL,
    ABILITY_HARVEST,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_EXEGGCUTE)
static const u16 sExeggutorLearnableAbilities[] = {
    ABILITY_CHLOROPHYLL,
    ABILITY_HARVEST,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_EXEGGCUTE) && (P_ALOLAN_FORMS)
static const u16 sExeggutorAlolaLearnableAbilities[] = {
    ABILITY_CHLOROPHYLL,
    ABILITY_HARVEST,
    ABILITY_FRISK,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CUBONE)
static const u16 sCuboneLearnableAbilities[] = {
    ABILITY_ROCK_HEAD,
    ABILITY_LIGHTNING_ROD,
    ABILITY_BATTLE_ARMOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CUBONE)
static const u16 sMarowakLearnableAbilities[] = {
    ABILITY_ROCK_HEAD,
    ABILITY_LIGHTNING_ROD,
    ABILITY_BATTLE_ARMOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CUBONE) && (P_ALOLAN_FORMS)
static const u16 sMarowakAlolaLearnableAbilities[] = {
    ABILITY_ROCK_HEAD,
    ABILITY_LIGHTNING_ROD,
    ABILITY_BATTLE_ARMOR,
    ABILITY_CURSED_BODY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CUBONE) && (P_ALOLAN_FORMS)
static const u16 sMarowakAlolaTotemLearnableAbilities[] = {
    ABILITY_ROCK_HEAD,
    ABILITY_LIGHTNING_ROD,
    ABILITY_BATTLE_ARMOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_HITMONS) && (P_GEN_2_CROSS_EVOS)
static const u16 sTyrogueLearnableAbilities[] = {
    ABILITY_GUTS,
    ABILITY_STEADFAST,
    ABILITY_VITAL_SPIRIT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_HITMONS)
static const u16 sHitmonleeLearnableAbilities[] = {
    ABILITY_GUTS,
    ABILITY_STEADFAST,
    ABILITY_VITAL_SPIRIT,
    ABILITY_LIMBER,
    ABILITY_RECKLESS,
    ABILITY_UNBURDEN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_HITMONS)
static const u16 sHitmonchanLearnableAbilities[] = {
    ABILITY_GUTS,
    ABILITY_STEADFAST,
    ABILITY_VITAL_SPIRIT,
    ABILITY_KEEN_EYE,
    ABILITY_IRON_FIST,
    ABILITY_INNER_FOCUS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_HITMONS) && (P_GEN_2_CROSS_EVOS)
static const u16 sHitmontopLearnableAbilities[] = {
    ABILITY_GUTS,
    ABILITY_STEADFAST,
    ABILITY_VITAL_SPIRIT,
    ABILITY_INTIMIDATE,
    ABILITY_TECHNICIAN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_LICKITUNG)
static const u16 sLickitungLearnableAbilities[] = {
    ABILITY_OWN_TEMPO,
    ABILITY_OBLIVIOUS,
    ABILITY_CLOUD_NINE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_LICKITUNG) && (P_GEN_4_CROSS_EVOS)
static const u16 sLickilickyLearnableAbilities[] = {
    ABILITY_OWN_TEMPO,
    ABILITY_OBLIVIOUS,
    ABILITY_CLOUD_NINE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_KOFFING)
static const u16 sKoffingLearnableAbilities[] = {
    ABILITY_LEVITATE,
    ABILITY_STENCH,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_KOFFING)
static const u16 sWeezingLearnableAbilities[] = {
    ABILITY_LEVITATE,
    ABILITY_STENCH,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_KOFFING) && (P_GALARIAN_FORMS)
static const u16 sWeezingGalarLearnableAbilities[] = {
    ABILITY_LEVITATE,
    ABILITY_STENCH,
    ABILITY_MISTY_SURGE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_RHYHORN)
static const u16 sRhyhornLearnableAbilities[] = {
    ABILITY_LIGHTNING_ROD,
    ABILITY_ROCK_HEAD,
    ABILITY_RECKLESS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_RHYHORN)
static const u16 sRhydonLearnableAbilities[] = {
    ABILITY_LIGHTNING_ROD,
    ABILITY_ROCK_HEAD,
    ABILITY_RECKLESS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_RHYHORN) && (P_GEN_4_CROSS_EVOS)
static const u16 sRhyperiorLearnableAbilities[] = {
    ABILITY_LIGHTNING_ROD,
    ABILITY_ROCK_HEAD,
    ABILITY_RECKLESS,
    ABILITY_SOLID_ROCK,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CHANSEY) && (P_GEN_4_CROSS_EVOS)
static const u16 sHappinyLearnableAbilities[] = {
    ABILITY_NATURAL_CURE,
    ABILITY_SERENE_GRACE,
    ABILITY_FRIEND_GUARD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CHANSEY)
static const u16 sChanseyLearnableAbilities[] = {
    ABILITY_NATURAL_CURE,
    ABILITY_SERENE_GRACE,
    ABILITY_FRIEND_GUARD,
    ABILITY_HEALER,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CHANSEY) && (P_GEN_2_CROSS_EVOS)
static const u16 sBlisseyLearnableAbilities[] = {
    ABILITY_NATURAL_CURE,
    ABILITY_SERENE_GRACE,
    ABILITY_FRIEND_GUARD,
    ABILITY_HEALER,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TANGELA)
static const u16 sTangelaLearnableAbilities[] = {
    ABILITY_CHLOROPHYLL,
    ABILITY_LEAF_GUARD,
    ABILITY_REGENERATOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TANGELA) && (P_GEN_4_CROSS_EVOS)
static const u16 sTangrowthLearnableAbilities[] = {
    ABILITY_CHLOROPHYLL,
    ABILITY_LEAF_GUARD,
    ABILITY_REGENERATOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_KANGASKHAN)
static const u16 sKangaskhanLearnableAbilities[] = {
    ABILITY_EARLY_BIRD,
    ABILITY_SCRAPPY,
    ABILITY_INNER_FOCUS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_HORSEA)
static const u16 sHorseaLearnableAbilities[] = {
    ABILITY_SWIFT_SWIM,
    ABILITY_SNIPER,
    ABILITY_DAMP,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_HORSEA)
static const u16 sSeadraLearnableAbilities[] = {
    ABILITY_SWIFT_SWIM,
    ABILITY_SNIPER,
    ABILITY_DAMP,
    ABILITY_POISON_POINT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_HORSEA) && (P_GEN_2_CROSS_EVOS)
static const u16 sKingdraLearnableAbilities[] = {
    ABILITY_SWIFT_SWIM,
    ABILITY_SNIPER,
    ABILITY_DAMP,
    ABILITY_POISON_POINT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GOLDEEN)
static const u16 sGoldeenLearnableAbilities[] = {
    ABILITY_SWIFT_SWIM,
    ABILITY_WATER_VEIL,
    ABILITY_LIGHTNING_ROD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GOLDEEN)
static const u16 sSeakingLearnableAbilities[] = {
    ABILITY_SWIFT_SWIM,
    ABILITY_WATER_VEIL,
    ABILITY_LIGHTNING_ROD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_STARYU)
static const u16 sStaryuLearnableAbilities[] = {
    ABILITY_ILLUMINATE,
    ABILITY_NATURAL_CURE,
    ABILITY_ANALYTIC,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_STARYU)
static const u16 sStarmieLearnableAbilities[] = {
    ABILITY_ILLUMINATE,
    ABILITY_NATURAL_CURE,
    ABILITY_ANALYTIC,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MR_MIME) && (P_GEN_4_CROSS_EVOS)
static const u16 sMimeJrLearnableAbilities[] = {
    ABILITY_SOUNDPROOF,
    ABILITY_FILTER,
    ABILITY_TECHNICIAN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MR_MIME)
static const u16 sMrMimeLearnableAbilities[] = {
    ABILITY_SOUNDPROOF,
    ABILITY_FILTER,
    ABILITY_TECHNICIAN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MR_MIME) && (P_GALARIAN_FORMS)
static const u16 sMrMimeGalarLearnableAbilities[] = {
    ABILITY_SOUNDPROOF,
    ABILITY_FILTER,
    ABILITY_TECHNICIAN,
    ABILITY_VITAL_SPIRIT,
    ABILITY_SCREEN_CLEANER,
    ABILITY_ICE_BODY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MR_MIME) && (P_GALARIAN_FORMS)
static const u16 sMrRimeLearnableAbilities[] = {
    ABILITY_SOUNDPROOF,
    ABILITY_FILTER,
    ABILITY_TECHNICIAN,
    ABILITY_VITAL_SPIRIT,
    ABILITY_SCREEN_CLEANER,
    ABILITY_ICE_BODY,
    ABILITY_TANGLED_FEET,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SCYTHER)
static const u16 sScytherLearnableAbilities[] = {
    ABILITY_SWARM,
    ABILITY_TECHNICIAN,
    ABILITY_STEADFAST,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SCYTHER) && (P_GEN_2_CROSS_EVOS)
static const u16 sScizorLearnableAbilities[] = {
    ABILITY_SWARM,
    ABILITY_TECHNICIAN,
    ABILITY_STEADFAST,
    ABILITY_LIGHT_METAL,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SCYTHER) && (P_GEN_8_CROSS_EVOS)
static const u16 sKleavorLearnableAbilities[] = {
    ABILITY_SWARM,
    ABILITY_TECHNICIAN,
    ABILITY_STEADFAST,
    ABILITY_SHEER_FORCE,
    ABILITY_SHARPNESS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_JYNX) && (P_GEN_2_CROSS_EVOS)
static const u16 sSmoochumLearnableAbilities[] = {
    ABILITY_OBLIVIOUS,
    ABILITY_FOREWARN,
    ABILITY_HYDRATION,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_JYNX)
static const u16 sJynxLearnableAbilities[] = {
    ABILITY_OBLIVIOUS,
    ABILITY_FOREWARN,
    ABILITY_HYDRATION,
    ABILITY_DRY_SKIN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ELECTABUZZ) && (P_GEN_2_CROSS_EVOS)
static const u16 sElekidLearnableAbilities[] = {
    ABILITY_STATIC,
    ABILITY_VITAL_SPIRIT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ELECTABUZZ)
static const u16 sElectabuzzLearnableAbilities[] = {
    ABILITY_STATIC,
    ABILITY_VITAL_SPIRIT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ELECTABUZZ) && (P_GEN_4_CROSS_EVOS)
static const u16 sElectivireLearnableAbilities[] = {
    ABILITY_STATIC,
    ABILITY_VITAL_SPIRIT,
    ABILITY_MOTOR_DRIVE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MAGMAR) && (P_GEN_2_CROSS_EVOS)
static const u16 sMagbyLearnableAbilities[] = {
    ABILITY_FLAME_BODY,
    ABILITY_VITAL_SPIRIT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MAGMAR)
static const u16 sMagmarLearnableAbilities[] = {
    ABILITY_FLAME_BODY,
    ABILITY_VITAL_SPIRIT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MAGMAR) && (P_GEN_4_CROSS_EVOS)
static const u16 sMagmortarLearnableAbilities[] = {
    ABILITY_FLAME_BODY,
    ABILITY_VITAL_SPIRIT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PINSIR)
static const u16 sPinsirLearnableAbilities[] = {
    ABILITY_HYPER_CUTTER,
    ABILITY_MOLD_BREAKER,
    ABILITY_MOXIE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TAUROS)
static const u16 sTaurosLearnableAbilities[] = {
    ABILITY_INTIMIDATE,
    ABILITY_ANGER_POINT,
    ABILITY_SHEER_FORCE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TAUROS) && (P_PALDEAN_FORMS)
static const u16 sTaurosPaldeaCombatLearnableAbilities[] = {
    ABILITY_INTIMIDATE,
    ABILITY_ANGER_POINT,
    ABILITY_CUD_CHEW,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TAUROS) && (P_PALDEAN_FORMS)
static const u16 sTaurosPaldeaBlazeLearnableAbilities[] = {
    ABILITY_INTIMIDATE,
    ABILITY_ANGER_POINT,
    ABILITY_CUD_CHEW,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TAUROS) && (P_PALDEAN_FORMS)
static const u16 sTaurosPaldeaAquaLearnableAbilities[] = {
    ABILITY_INTIMIDATE,
    ABILITY_ANGER_POINT,
    ABILITY_CUD_CHEW,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MAGIKARP)
static const u16 sMagikarpLearnableAbilities[] = {
    ABILITY_SWIFT_SWIM,
    ABILITY_RATTLED,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MAGIKARP)
static const u16 sGyaradosLearnableAbilities[] = {
    ABILITY_SWIFT_SWIM,
    ABILITY_RATTLED,
    ABILITY_INTIMIDATE,
    ABILITY_MOXIE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_LAPRAS)
static const u16 sLaprasLearnableAbilities[] = {
    ABILITY_WATER_ABSORB,
    ABILITY_SHELL_ARMOR,
    ABILITY_HYDRATION,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DITTO)
static const u16 sDittoLearnableAbilities[] = {
    ABILITY_LIMBER,
    ABILITY_IMPOSTER,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_EEVEE)
static const u16 sEeveeLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_ADAPTABILITY,
    ABILITY_ANTICIPATION,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_EEVEE)
static const u16 sEeveeStarterLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_ADAPTABILITY,
    ABILITY_ANTICIPATION,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_EEVEE)
static const u16 sVaporeonLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_ADAPTABILITY,
    ABILITY_ANTICIPATION,
    ABILITY_WATER_ABSORB,
    ABILITY_HYDRATION,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_EEVEE)
static const u16 sJolteonLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_ADAPTABILITY,
    ABILITY_ANTICIPATION,
    ABILITY_VOLT_ABSORB,
    ABILITY_QUICK_FEET,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_EEVEE)
static const u16 sFlareonLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_ADAPTABILITY,
    ABILITY_ANTICIPATION,
    ABILITY_FLASH_FIRE,
    ABILITY_GUTS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_EEVEE) && (P_GEN_2_CROSS_EVOS)
static const u16 sEspeonLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_ADAPTABILITY,
    ABILITY_ANTICIPATION,
    ABILITY_SYNCHRONIZE,
    ABILITY_MAGIC_BOUNCE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_EEVEE) && (P_GEN_2_CROSS_EVOS)
static const u16 sUmbreonLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_ADAPTABILITY,
    ABILITY_ANTICIPATION,
    ABILITY_SYNCHRONIZE,
    ABILITY_INNER_FOCUS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_EEVEE) && (P_GEN_4_CROSS_EVOS)
static const u16 sLeafeonLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_ADAPTABILITY,
    ABILITY_ANTICIPATION,
    ABILITY_LEAF_GUARD,
    ABILITY_CHLOROPHYLL,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_EEVEE) && (P_GEN_4_CROSS_EVOS)
static const u16 sGlaceonLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_ADAPTABILITY,
    ABILITY_ANTICIPATION,
    ABILITY_SNOW_CLOAK,
    ABILITY_ICE_BODY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_EEVEE) && (P_GEN_6_CROSS_EVOS)
static const u16 sSylveonLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_ADAPTABILITY,
    ABILITY_ANTICIPATION,
    ABILITY_CUTE_CHARM,
    ABILITY_PIXILATE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PORYGON)
static const u16 sPorygonLearnableAbilities[] = {
    ABILITY_TRACE,
    ABILITY_DOWNLOAD,
    ABILITY_ANALYTIC,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PORYGON) && (P_GEN_2_CROSS_EVOS)
static const u16 sPorygon2LearnableAbilities[] = {
    ABILITY_TRACE,
    ABILITY_DOWNLOAD,
    ABILITY_ANALYTIC,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PORYGON) && (P_GEN_2_CROSS_EVOS) && (P_GEN_4_CROSS_EVOS)
static const u16 sPorygonZLearnableAbilities[] = {
    ABILITY_TRACE,
    ABILITY_DOWNLOAD,
    ABILITY_ANALYTIC,
    ABILITY_ADAPTABILITY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_OMANYTE)
static const u16 sOmanyteLearnableAbilities[] = {
    ABILITY_SWIFT_SWIM,
    ABILITY_SHELL_ARMOR,
    ABILITY_WEAK_ARMOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_OMANYTE)
static const u16 sOmastarLearnableAbilities[] = {
    ABILITY_SWIFT_SWIM,
    ABILITY_SHELL_ARMOR,
    ABILITY_WEAK_ARMOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_KABUTO)
static const u16 sKabutoLearnableAbilities[] = {
    ABILITY_SWIFT_SWIM,
    ABILITY_BATTLE_ARMOR,
    ABILITY_WEAK_ARMOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_KABUTO)
static const u16 sKabutopsLearnableAbilities[] = {
    ABILITY_SWIFT_SWIM,
    ABILITY_BATTLE_ARMOR,
    ABILITY_WEAK_ARMOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_AERODACTYL)
static const u16 sAerodactylLearnableAbilities[] = {
    ABILITY_ROCK_HEAD,
    ABILITY_PRESSURE,
    ABILITY_UNNERVE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SNORLAX) && (P_GEN_4_CROSS_EVOS)
static const u16 sMunchlaxLearnableAbilities[] = {
    ABILITY_PICKUP,
    ABILITY_THICK_FAT,
    ABILITY_GLUTTONY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SNORLAX)
static const u16 sSnorlaxLearnableAbilities[] = {
    ABILITY_PICKUP,
    ABILITY_THICK_FAT,
    ABILITY_GLUTTONY,
    ABILITY_IMMUNITY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ARTICUNO)
static const u16 sArticunoLearnableAbilities[] = {
    ABILITY_PRESSURE,
    ABILITY_SNOW_CLOAK,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ARTICUNO) && (P_GALARIAN_FORMS)
static const u16 sArticunoGalarLearnableAbilities[] = {
    ABILITY_COMPETITIVE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ZAPDOS)
static const u16 sZapdosLearnableAbilities[] = {
    ABILITY_PRESSURE,
    ABILITY_STATIC,
    ABILITY_LIGHTNING_ROD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ZAPDOS) && (P_GALARIAN_FORMS)
static const u16 sZapdosGalarLearnableAbilities[] = {
    ABILITY_DEFIANT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MOLTRES)
static const u16 sMoltresLearnableAbilities[] = {
    ABILITY_PRESSURE,
    ABILITY_FLAME_BODY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MOLTRES) && (P_GALARIAN_FORMS)
static const u16 sMoltresGalarLearnableAbilities[] = {
    ABILITY_BERSERK,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DRATINI)
static const u16 sDratiniLearnableAbilities[] = {
    ABILITY_SHED_SKIN,
    ABILITY_MARVEL_SCALE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DRATINI)
static const u16 sDragonairLearnableAbilities[] = {
    ABILITY_SHED_SKIN,
    ABILITY_MARVEL_SCALE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DRATINI)
static const u16 sDragoniteLearnableAbilities[] = {
    ABILITY_SHED_SKIN,
    ABILITY_MARVEL_SCALE,
    ABILITY_INNER_FOCUS,
    ABILITY_MULTISCALE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MEWTWO)
static const u16 sMewtwoLearnableAbilities[] = {
    ABILITY_PRESSURE,
    ABILITY_UNNERVE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MEW)
static const u16 sMewLearnableAbilities[] = {
    ABILITY_SYNCHRONIZE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CHIKORITA)
static const u16 sChikoritaLearnableAbilities[] = {
    ABILITY_OVERGROW,
    ABILITY_LEAF_GUARD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CHIKORITA)
static const u16 sBayleefLearnableAbilities[] = {
    ABILITY_OVERGROW,
    ABILITY_LEAF_GUARD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CHIKORITA)
static const u16 sMeganiumLearnableAbilities[] = {
    ABILITY_OVERGROW,
    ABILITY_LEAF_GUARD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CYNDAQUIL)
static const u16 sCyndaquilLearnableAbilities[] = {
    ABILITY_BLAZE,
    ABILITY_FLASH_FIRE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CYNDAQUIL)
static const u16 sQuilavaLearnableAbilities[] = {
    ABILITY_BLAZE,
    ABILITY_FLASH_FIRE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CYNDAQUIL)
static const u16 sTyphlosionLearnableAbilities[] = {
    ABILITY_BLAZE,
    ABILITY_FLASH_FIRE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CYNDAQUIL) && (P_HISUIAN_FORMS)
static const u16 sTyphlosionHisuiLearnableAbilities[] = {
    ABILITY_BLAZE,
    ABILITY_FLASH_FIRE,
    ABILITY_FRISK,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TOTODILE)
static const u16 sTotodileLearnableAbilities[] = {
    ABILITY_TORRENT,
    ABILITY_SHEER_FORCE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TOTODILE)
static const u16 sCroconawLearnableAbilities[] = {
    ABILITY_TORRENT,
    ABILITY_SHEER_FORCE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TOTODILE)
static const u16 sFeraligatrLearnableAbilities[] = {
    ABILITY_TORRENT,
    ABILITY_SHEER_FORCE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SENTRET)
static const u16 sSentretLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_KEEN_EYE,
    ABILITY_FRISK,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SENTRET)
static const u16 sFurretLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_KEEN_EYE,
    ABILITY_FRISK,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_HOOTHOOT)
static const u16 sHoothootLearnableAbilities[] = {
    ABILITY_INSOMNIA,
    ABILITY_KEEN_EYE,
    ABILITY_TINTED_LENS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_HOOTHOOT)
static const u16 sNoctowlLearnableAbilities[] = {
    ABILITY_INSOMNIA,
    ABILITY_KEEN_EYE,
    ABILITY_TINTED_LENS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_LEDYBA)
static const u16 sLedybaLearnableAbilities[] = {
    ABILITY_SWARM,
    ABILITY_EARLY_BIRD,
    ABILITY_RATTLED,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_LEDYBA)
static const u16 sLedianLearnableAbilities[] = {
    ABILITY_SWARM,
    ABILITY_EARLY_BIRD,
    ABILITY_RATTLED,
    ABILITY_IRON_FIST,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SPINARAK)
static const u16 sSpinarakLearnableAbilities[] = {
    ABILITY_SWARM,
    ABILITY_INSOMNIA,
    ABILITY_SNIPER,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SPINARAK)
static const u16 sAriadosLearnableAbilities[] = {
    ABILITY_SWARM,
    ABILITY_INSOMNIA,
    ABILITY_SNIPER,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CHINCHOU)
static const u16 sChinchouLearnableAbilities[] = {
    ABILITY_VOLT_ABSORB,
    ABILITY_ILLUMINATE,
    ABILITY_WATER_ABSORB,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CHINCHOU)
static const u16 sLanturnLearnableAbilities[] = {
    ABILITY_VOLT_ABSORB,
    ABILITY_ILLUMINATE,
    ABILITY_WATER_ABSORB,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TOGEPI)
static const u16 sTogepiLearnableAbilities[] = {
    ABILITY_HUSTLE,
    ABILITY_SERENE_GRACE,
    ABILITY_SUPER_LUCK,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TOGEPI)
static const u16 sTogeticLearnableAbilities[] = {
    ABILITY_HUSTLE,
    ABILITY_SERENE_GRACE,
    ABILITY_SUPER_LUCK,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TOGEPI) && (P_GEN_4_CROSS_EVOS)
static const u16 sTogekissLearnableAbilities[] = {
    ABILITY_HUSTLE,
    ABILITY_SERENE_GRACE,
    ABILITY_SUPER_LUCK,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_NATU)
static const u16 sNatuLearnableAbilities[] = {
    ABILITY_SYNCHRONIZE,
    ABILITY_EARLY_BIRD,
    ABILITY_MAGIC_BOUNCE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_NATU)
static const u16 sXatuLearnableAbilities[] = {
    ABILITY_SYNCHRONIZE,
    ABILITY_EARLY_BIRD,
    ABILITY_MAGIC_BOUNCE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MAREEP)
static const u16 sMareepLearnableAbilities[] = {
    ABILITY_STATIC,
    ABILITY_PLUS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MAREEP)
static const u16 sFlaaffyLearnableAbilities[] = {
    ABILITY_STATIC,
    ABILITY_PLUS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MAREEP)
static const u16 sAmpharosLearnableAbilities[] = {
    ABILITY_STATIC,
    ABILITY_PLUS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MARILL) && (P_GEN_3_CROSS_EVOS)
static const u16 sAzurillLearnableAbilities[] = {
    ABILITY_THICK_FAT,
    ABILITY_HUGE_POWER,
    ABILITY_SAP_SIPPER,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MARILL)
static const u16 sMarillLearnableAbilities[] = {
    ABILITY_THICK_FAT,
    ABILITY_HUGE_POWER,
    ABILITY_SAP_SIPPER,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MARILL)
static const u16 sAzumarillLearnableAbilities[] = {
    ABILITY_THICK_FAT,
    ABILITY_HUGE_POWER,
    ABILITY_SAP_SIPPER,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SUDOWOODO) && (P_GEN_4_CROSS_EVOS)
static const u16 sBonslyLearnableAbilities[] = {
    ABILITY_STURDY,
    ABILITY_ROCK_HEAD,
    ABILITY_RATTLED,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SUDOWOODO)
static const u16 sSudowoodoLearnableAbilities[] = {
    ABILITY_STURDY,
    ABILITY_ROCK_HEAD,
    ABILITY_RATTLED,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_HOPPIP)
static const u16 sHoppipLearnableAbilities[] = {
    ABILITY_CHLOROPHYLL,
    ABILITY_LEAF_GUARD,
    ABILITY_INFILTRATOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_HOPPIP)
static const u16 sSkiploomLearnableAbilities[] = {
    ABILITY_CHLOROPHYLL,
    ABILITY_LEAF_GUARD,
    ABILITY_INFILTRATOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_HOPPIP)
static const u16 sJumpluffLearnableAbilities[] = {
    ABILITY_CHLOROPHYLL,
    ABILITY_LEAF_GUARD,
    ABILITY_INFILTRATOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_AIPOM)
static const u16 sAipomLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_PICKUP,
    ABILITY_SKILL_LINK,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_AIPOM) && (P_GEN_4_CROSS_EVOS)
static const u16 sAmbipomLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_PICKUP,
    ABILITY_SKILL_LINK,
    ABILITY_TECHNICIAN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SUNKERN)
static const u16 sSunkernLearnableAbilities[] = {
    ABILITY_CHLOROPHYLL,
    ABILITY_SOLAR_POWER,
    ABILITY_EARLY_BIRD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SUNKERN)
static const u16 sSunfloraLearnableAbilities[] = {
    ABILITY_CHLOROPHYLL,
    ABILITY_SOLAR_POWER,
    ABILITY_EARLY_BIRD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_YANMA)
static const u16 sYanmaLearnableAbilities[] = {
    ABILITY_SPEED_BOOST,
    ABILITY_COMPOUND_EYES,
    ABILITY_FRISK,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_YANMA) && (P_GEN_4_CROSS_EVOS)
static const u16 sYanmegaLearnableAbilities[] = {
    ABILITY_SPEED_BOOST,
    ABILITY_COMPOUND_EYES,
    ABILITY_FRISK,
    ABILITY_TINTED_LENS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_WOOPER)
static const u16 sWooperLearnableAbilities[] = {
    ABILITY_DAMP,
    ABILITY_WATER_ABSORB,
    ABILITY_UNAWARE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_WOOPER)
static const u16 sQuagsireLearnableAbilities[] = {
    ABILITY_DAMP,
    ABILITY_WATER_ABSORB,
    ABILITY_UNAWARE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_WOOPER) && (P_PALDEAN_FORMS)
static const u16 sWooperPaldeaLearnableAbilities[] = {
    ABILITY_POISON_POINT,
    ABILITY_WATER_ABSORB,
    ABILITY_UNAWARE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_WOOPER) && (P_PALDEAN_FORMS)
static const u16 sClodsireLearnableAbilities[] = {
    ABILITY_POISON_POINT,
    ABILITY_WATER_ABSORB,
    ABILITY_UNAWARE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MURKROW)
static const u16 sMurkrowLearnableAbilities[] = {
    ABILITY_INSOMNIA,
    ABILITY_SUPER_LUCK,
    ABILITY_PRANKSTER,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MURKROW) && (P_GEN_4_CROSS_EVOS)
static const u16 sHonchkrowLearnableAbilities[] = {
    ABILITY_INSOMNIA,
    ABILITY_SUPER_LUCK,
    ABILITY_PRANKSTER,
    ABILITY_MOXIE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MISDREAVUS)
static const u16 sMisdreavusLearnableAbilities[] = {
    ABILITY_LEVITATE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MISDREAVUS) && (P_GEN_4_CROSS_EVOS)
static const u16 sMismagiusLearnableAbilities[] = {
    ABILITY_LEVITATE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_UNOWN)
static const u16 sUnownLearnableAbilities[] = {
    ABILITY_LEVITATE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_WOBBUFFET) && (P_GEN_3_CROSS_EVOS)
static const u16 sWynautLearnableAbilities[] = {
    ABILITY_SHADOW_TAG,
    ABILITY_TELEPATHY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_WOBBUFFET)
static const u16 sWobbuffetLearnableAbilities[] = {
    ABILITY_SHADOW_TAG,
    ABILITY_TELEPATHY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GIRAFARIG)
static const u16 sGirafarigLearnableAbilities[] = {
    ABILITY_INNER_FOCUS,
    ABILITY_EARLY_BIRD,
    ABILITY_SAP_SIPPER,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GIRAFARIG) && (P_GEN_9_CROSS_EVOS)
static const u16 sFarigirafLearnableAbilities[] = {
    ABILITY_INNER_FOCUS,
    ABILITY_EARLY_BIRD,
    ABILITY_SAP_SIPPER,
    ABILITY_CUD_CHEW,
    ABILITY_ARMOR_TAIL,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PINECO)
static const u16 sPinecoLearnableAbilities[] = {
    ABILITY_STURDY,
    ABILITY_OVERCOAT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PINECO)
static const u16 sForretressLearnableAbilities[] = {
    ABILITY_STURDY,
    ABILITY_OVERCOAT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DUNSPARCE)
static const u16 sDunsparceLearnableAbilities[] = {
    ABILITY_SERENE_GRACE,
    ABILITY_RUN_AWAY,
    ABILITY_RATTLED,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DUNSPARCE) && (P_GEN_9_CROSS_EVOS)
static const u16 sDudunsparceTwoSegmentLearnableAbilities[] = {
    ABILITY_SERENE_GRACE,
    ABILITY_RUN_AWAY,
    ABILITY_RATTLED,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DUNSPARCE) && (P_GEN_9_CROSS_EVOS)
static const u16 sDudunsparceThreeSegmentLearnableAbilities[] = {
    ABILITY_SERENE_GRACE,
    ABILITY_RUN_AWAY,
    ABILITY_RATTLED,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GLIGAR)
static const u16 sGligarLearnableAbilities[] = {
    ABILITY_HYPER_CUTTER,
    ABILITY_SAND_VEIL,
    ABILITY_IMMUNITY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GLIGAR) && (P_GEN_4_CROSS_EVOS)
static const u16 sGliscorLearnableAbilities[] = {
    ABILITY_HYPER_CUTTER,
    ABILITY_SAND_VEIL,
    ABILITY_IMMUNITY,
    ABILITY_POISON_HEAL,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SNUBBULL)
static const u16 sSnubbullLearnableAbilities[] = {
    ABILITY_INTIMIDATE,
    ABILITY_RUN_AWAY,
    ABILITY_RATTLED,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SNUBBULL)
static const u16 sGranbullLearnableAbilities[] = {
    ABILITY_INTIMIDATE,
    ABILITY_RUN_AWAY,
    ABILITY_RATTLED,
    ABILITY_QUICK_FEET,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_QWILFISH)
static const u16 sQwilfishLearnableAbilities[] = {
    ABILITY_POISON_POINT,
    ABILITY_SWIFT_SWIM,
    ABILITY_INTIMIDATE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_QWILFISH) && (P_HISUIAN_FORMS)
static const u16 sQwilfishHisuiLearnableAbilities[] = {
    ABILITY_POISON_POINT,
    ABILITY_SWIFT_SWIM,
    ABILITY_INTIMIDATE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_QWILFISH) && (P_HISUIAN_FORMS)
static const u16 sOverqwilLearnableAbilities[] = {
    ABILITY_POISON_POINT,
    ABILITY_SWIFT_SWIM,
    ABILITY_INTIMIDATE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SHUCKLE)
static const u16 sShuckleLearnableAbilities[] = {
    ABILITY_STURDY,
    ABILITY_GLUTTONY,
    ABILITY_CONTRARY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_HERACROSS)
static const u16 sHeracrossLearnableAbilities[] = {
    ABILITY_SWARM,
    ABILITY_GUTS,
    ABILITY_MOXIE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SNEASEL)
static const u16 sSneaselLearnableAbilities[] = {
    ABILITY_INNER_FOCUS,
    ABILITY_KEEN_EYE,
    ABILITY_PICKPOCKET,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SNEASEL) && (P_GEN_4_CROSS_EVOS)
static const u16 sWeavileLearnableAbilities[] = {
    ABILITY_INNER_FOCUS,
    ABILITY_KEEN_EYE,
    ABILITY_PICKPOCKET,
    ABILITY_PRESSURE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SNEASEL) && (P_HISUIAN_FORMS)
static const u16 sSneaselHisuiLearnableAbilities[] = {
    ABILITY_INNER_FOCUS,
    ABILITY_KEEN_EYE,
    ABILITY_PICKPOCKET,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SNEASEL) && (P_HISUIAN_FORMS)
static const u16 sSneaslerLearnableAbilities[] = {
    ABILITY_INNER_FOCUS,
    ABILITY_KEEN_EYE,
    ABILITY_PICKPOCKET,
    ABILITY_PRESSURE,
    ABILITY_UNBURDEN,
    ABILITY_POISON_TOUCH,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TEDDIURSA)
static const u16 sTeddiursaLearnableAbilities[] = {
    ABILITY_PICKUP,
    ABILITY_QUICK_FEET,
    ABILITY_HONEY_GATHER,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TEDDIURSA)
static const u16 sUrsaringLearnableAbilities[] = {
    ABILITY_PICKUP,
    ABILITY_QUICK_FEET,
    ABILITY_HONEY_GATHER,
    ABILITY_GUTS,
    ABILITY_UNNERVE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TEDDIURSA) && (P_GEN_8_CROSS_EVOS)
static const u16 sUrsalunaLearnableAbilities[] = {
    ABILITY_PICKUP,
    ABILITY_QUICK_FEET,
    ABILITY_HONEY_GATHER,
    ABILITY_GUTS,
    ABILITY_UNNERVE,
    ABILITY_BULLETPROOF,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TEDDIURSA) && (P_GEN_8_CROSS_EVOS)
static const u16 sUrsalunaBloodmoonLearnableAbilities[] = {
    ABILITY_PICKUP,
    ABILITY_QUICK_FEET,
    ABILITY_HONEY_GATHER,
    ABILITY_GUTS,
    ABILITY_UNNERVE,
    ABILITY_MINDS_EYE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SLUGMA)
static const u16 sSlugmaLearnableAbilities[] = {
    ABILITY_MAGMA_ARMOR,
    ABILITY_FLAME_BODY,
    ABILITY_WEAK_ARMOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SLUGMA)
static const u16 sMagcargoLearnableAbilities[] = {
    ABILITY_MAGMA_ARMOR,
    ABILITY_FLAME_BODY,
    ABILITY_WEAK_ARMOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SWINUB)
static const u16 sSwinubLearnableAbilities[] = {
    ABILITY_OBLIVIOUS,
    ABILITY_SNOW_CLOAK,
    ABILITY_THICK_FAT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SWINUB)
static const u16 sPiloswineLearnableAbilities[] = {
    ABILITY_OBLIVIOUS,
    ABILITY_SNOW_CLOAK,
    ABILITY_THICK_FAT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SWINUB) && (P_GEN_4_CROSS_EVOS)
static const u16 sMamoswineLearnableAbilities[] = {
    ABILITY_OBLIVIOUS,
    ABILITY_SNOW_CLOAK,
    ABILITY_THICK_FAT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CORSOLA)
static const u16 sCorsolaLearnableAbilities[] = {
    ABILITY_HUSTLE,
    ABILITY_NATURAL_CURE,
    ABILITY_REGENERATOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CORSOLA) && (P_GALARIAN_FORMS)
static const u16 sCorsolaGalarLearnableAbilities[] = {
    ABILITY_WEAK_ARMOR,
    ABILITY_CURSED_BODY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CORSOLA) && (P_GALARIAN_FORMS)
static const u16 sCursolaLearnableAbilities[] = {
    ABILITY_WEAK_ARMOR,
    ABILITY_CURSED_BODY,
    ABILITY_PERISH_BODY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_REMORAID)
static const u16 sRemoraidLearnableAbilities[] = {
    ABILITY_HUSTLE,
    ABILITY_SNIPER,
    ABILITY_MOODY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_REMORAID)
static const u16 sOctilleryLearnableAbilities[] = {
    ABILITY_HUSTLE,
    ABILITY_SNIPER,
    ABILITY_MOODY,
    ABILITY_SUCTION_CUPS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DELIBIRD)
static const u16 sDelibirdLearnableAbilities[] = {
    ABILITY_VITAL_SPIRIT,
    ABILITY_HUSTLE,
    ABILITY_INSOMNIA,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MANTINE) && (P_GEN_4_CROSS_EVOS)
static const u16 sMantykeLearnableAbilities[] = {
    ABILITY_SWIFT_SWIM,
    ABILITY_WATER_ABSORB,
    ABILITY_WATER_VEIL,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MANTINE)
static const u16 sMantineLearnableAbilities[] = {
    ABILITY_SWIFT_SWIM,
    ABILITY_WATER_ABSORB,
    ABILITY_WATER_VEIL,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SKARMORY)
static const u16 sSkarmoryLearnableAbilities[] = {
    ABILITY_KEEN_EYE,
    ABILITY_STURDY,
    ABILITY_WEAK_ARMOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_HOUNDOUR)
static const u16 sHoundourLearnableAbilities[] = {
    ABILITY_EARLY_BIRD,
    ABILITY_FLASH_FIRE,
    ABILITY_UNNERVE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_HOUNDOUR)
static const u16 sHoundoomLearnableAbilities[] = {
    ABILITY_EARLY_BIRD,
    ABILITY_FLASH_FIRE,
    ABILITY_UNNERVE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PHANPY)
static const u16 sPhanpyLearnableAbilities[] = {
    ABILITY_PICKUP,
    ABILITY_SAND_VEIL,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PHANPY)
static const u16 sDonphanLearnableAbilities[] = {
    ABILITY_PICKUP,
    ABILITY_SAND_VEIL,
    ABILITY_STURDY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_STANTLER)
static const u16 sStantlerLearnableAbilities[] = {
    ABILITY_INTIMIDATE,
    ABILITY_FRISK,
    ABILITY_SAP_SIPPER,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_STANTLER) && (P_GEN_8_CROSS_EVOS)
static const u16 sWyrdeerLearnableAbilities[] = {
    ABILITY_INTIMIDATE,
    ABILITY_FRISK,
    ABILITY_SAP_SIPPER,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SMEARGLE)
static const u16 sSmeargleLearnableAbilities[] = {
    ABILITY_OWN_TEMPO,
    ABILITY_TECHNICIAN,
    ABILITY_MOODY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MILTANK)
static const u16 sMiltankLearnableAbilities[] = {
    ABILITY_THICK_FAT,
    ABILITY_SCRAPPY,
    ABILITY_SAP_SIPPER,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_RAIKOU)
static const u16 sRaikouLearnableAbilities[] = {
    ABILITY_PRESSURE,
    ABILITY_INNER_FOCUS,
    ABILITY_VOLT_ABSORB,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ENTEI)
static const u16 sEnteiLearnableAbilities[] = {
    ABILITY_PRESSURE,
    ABILITY_INNER_FOCUS,
    ABILITY_FLASH_FIRE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SUICUNE)
static const u16 sSuicuneLearnableAbilities[] = {
    ABILITY_PRESSURE,
    ABILITY_INNER_FOCUS,
    ABILITY_WATER_ABSORB,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_LARVITAR)
static const u16 sLarvitarLearnableAbilities[] = {
    ABILITY_GUTS,
    ABILITY_SAND_VEIL,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_LARVITAR)
static const u16 sPupitarLearnableAbilities[] = {
    ABILITY_GUTS,
    ABILITY_SAND_VEIL,
    ABILITY_SHED_SKIN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_LARVITAR)
static const u16 sTyranitarLearnableAbilities[] = {
    ABILITY_GUTS,
    ABILITY_SAND_VEIL,
    ABILITY_SHED_SKIN,
    ABILITY_SAND_STREAM,
    ABILITY_UNNERVE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_LUGIA)
static const u16 sLugiaLearnableAbilities[] = {
    ABILITY_PRESSURE,
    ABILITY_MULTISCALE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_HO_OH)
static const u16 sHoOhLearnableAbilities[] = {
    ABILITY_PRESSURE,
    ABILITY_REGENERATOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CELEBI)
static const u16 sCelebiLearnableAbilities[] = {
    ABILITY_NATURAL_CURE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TREECKO)
static const u16 sTreeckoLearnableAbilities[] = {
    ABILITY_OVERGROW,
    ABILITY_UNBURDEN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TREECKO)
static const u16 sGrovyleLearnableAbilities[] = {
    ABILITY_OVERGROW,
    ABILITY_UNBURDEN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TREECKO)
static const u16 sSceptileLearnableAbilities[] = {
    ABILITY_OVERGROW,
    ABILITY_UNBURDEN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TORCHIC)
static const u16 sTorchicLearnableAbilities[] = {
    ABILITY_BLAZE,
    ABILITY_SPEED_BOOST,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TORCHIC)
static const u16 sCombuskenLearnableAbilities[] = {
    ABILITY_BLAZE,
    ABILITY_SPEED_BOOST,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TORCHIC)
static const u16 sBlazikenLearnableAbilities[] = {
    ABILITY_BLAZE,
    ABILITY_SPEED_BOOST,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MUDKIP)
static const u16 sMudkipLearnableAbilities[] = {
    ABILITY_TORRENT,
    ABILITY_DAMP,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MUDKIP)
static const u16 sMarshtompLearnableAbilities[] = {
    ABILITY_TORRENT,
    ABILITY_DAMP,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MUDKIP)
static const u16 sSwampertLearnableAbilities[] = {
    ABILITY_TORRENT,
    ABILITY_DAMP,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_POOCHYENA)
static const u16 sPoochyenaLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_QUICK_FEET,
    ABILITY_RATTLED,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_POOCHYENA)
static const u16 sMightyenaLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_QUICK_FEET,
    ABILITY_RATTLED,
    ABILITY_INTIMIDATE,
    ABILITY_MOXIE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ZIGZAGOON)
static const u16 sZigzagoonLearnableAbilities[] = {
    ABILITY_PICKUP,
    ABILITY_GLUTTONY,
    ABILITY_QUICK_FEET,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ZIGZAGOON)
static const u16 sLinooneLearnableAbilities[] = {
    ABILITY_PICKUP,
    ABILITY_GLUTTONY,
    ABILITY_QUICK_FEET,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ZIGZAGOON) && (P_GALARIAN_FORMS)
static const u16 sZigzagoonGalarLearnableAbilities[] = {
    ABILITY_PICKUP,
    ABILITY_GLUTTONY,
    ABILITY_QUICK_FEET,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ZIGZAGOON) && (P_GALARIAN_FORMS)
static const u16 sLinooneGalarLearnableAbilities[] = {
    ABILITY_PICKUP,
    ABILITY_GLUTTONY,
    ABILITY_QUICK_FEET,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ZIGZAGOON) && (P_GALARIAN_FORMS)
static const u16 sObstagoonLearnableAbilities[] = {
    ABILITY_PICKUP,
    ABILITY_GLUTTONY,
    ABILITY_QUICK_FEET,
    ABILITY_RECKLESS,
    ABILITY_GUTS,
    ABILITY_DEFIANT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_WURMPLE)
static const u16 sWurmpleLearnableAbilities[] = {
    ABILITY_SHIELD_DUST,
    ABILITY_RUN_AWAY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_WURMPLE)
static const u16 sSilcoonLearnableAbilities[] = {
    ABILITY_SHIELD_DUST,
    ABILITY_RUN_AWAY,
    ABILITY_SHED_SKIN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_WURMPLE)
static const u16 sBeautiflyLearnableAbilities[] = {
    ABILITY_SHIELD_DUST,
    ABILITY_RUN_AWAY,
    ABILITY_SHED_SKIN,
    ABILITY_SWARM,
    ABILITY_RIVALRY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_WURMPLE)
static const u16 sCascoonLearnableAbilities[] = {
    ABILITY_SHIELD_DUST,
    ABILITY_RUN_AWAY,
    ABILITY_SHED_SKIN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_WURMPLE)
static const u16 sDustoxLearnableAbilities[] = {
    ABILITY_SHIELD_DUST,
    ABILITY_RUN_AWAY,
    ABILITY_SHED_SKIN,
    ABILITY_COMPOUND_EYES,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_LOTAD)
static const u16 sLotadLearnableAbilities[] = {
    ABILITY_SWIFT_SWIM,
    ABILITY_RAIN_DISH,
    ABILITY_OWN_TEMPO,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_LOTAD)
static const u16 sLombreLearnableAbilities[] = {
    ABILITY_SWIFT_SWIM,
    ABILITY_RAIN_DISH,
    ABILITY_OWN_TEMPO,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_LOTAD)
static const u16 sLudicoloLearnableAbilities[] = {
    ABILITY_SWIFT_SWIM,
    ABILITY_RAIN_DISH,
    ABILITY_OWN_TEMPO,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SEEDOT)
static const u16 sSeedotLearnableAbilities[] = {
    ABILITY_CHLOROPHYLL,
    ABILITY_EARLY_BIRD,
    ABILITY_PICKPOCKET,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SEEDOT)
static const u16 sNuzleafLearnableAbilities[] = {
    ABILITY_CHLOROPHYLL,
    ABILITY_EARLY_BIRD,
    ABILITY_PICKPOCKET,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SEEDOT)
static const u16 sShiftryLearnableAbilities[] = {
    ABILITY_CHLOROPHYLL,
    ABILITY_EARLY_BIRD,
    ABILITY_PICKPOCKET,
    ABILITY_WIND_RIDER,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TAILLOW)
static const u16 sTaillowLearnableAbilities[] = {
    ABILITY_GUTS,
    ABILITY_SCRAPPY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TAILLOW)
static const u16 sSwellowLearnableAbilities[] = {
    ABILITY_GUTS,
    ABILITY_SCRAPPY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_WINGULL)
static const u16 sWingullLearnableAbilities[] = {
    ABILITY_KEEN_EYE,
    ABILITY_HYDRATION,
    ABILITY_RAIN_DISH,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_WINGULL)
static const u16 sPelipperLearnableAbilities[] = {
    ABILITY_KEEN_EYE,
    ABILITY_HYDRATION,
    ABILITY_RAIN_DISH,
    ABILITY_DRIZZLE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_RALTS)
static const u16 sRaltsLearnableAbilities[] = {
    ABILITY_SYNCHRONIZE,
    ABILITY_TRACE,
    ABILITY_TELEPATHY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_RALTS)
static const u16 sKirliaLearnableAbilities[] = {
    ABILITY_SYNCHRONIZE,
    ABILITY_TRACE,
    ABILITY_TELEPATHY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_RALTS)
static const u16 sGardevoirLearnableAbilities[] = {
    ABILITY_SYNCHRONIZE,
    ABILITY_TRACE,
    ABILITY_TELEPATHY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_RALTS) && (P_GEN_4_CROSS_EVOS)
static const u16 sGalladeLearnableAbilities[] = {
    ABILITY_SYNCHRONIZE,
    ABILITY_TRACE,
    ABILITY_TELEPATHY,
    ABILITY_STEADFAST,
    ABILITY_SHARPNESS,
    ABILITY_JUSTIFIED,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SURSKIT)
static const u16 sSurskitLearnableAbilities[] = {
    ABILITY_SWIFT_SWIM,
    ABILITY_RAIN_DISH,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SURSKIT)
static const u16 sMasquerainLearnableAbilities[] = {
    ABILITY_SWIFT_SWIM,
    ABILITY_RAIN_DISH,
    ABILITY_INTIMIDATE,
    ABILITY_UNNERVE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SHROOMISH)
static const u16 sShroomishLearnableAbilities[] = {
    ABILITY_EFFECT_SPORE,
    ABILITY_POISON_HEAL,
    ABILITY_QUICK_FEET,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SHROOMISH)
static const u16 sBreloomLearnableAbilities[] = {
    ABILITY_EFFECT_SPORE,
    ABILITY_POISON_HEAL,
    ABILITY_QUICK_FEET,
    ABILITY_TECHNICIAN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SLAKOTH)
static const u16 sSlakothLearnableAbilities[] = {
    ABILITY_TRUANT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SLAKOTH)
static const u16 sVigorothLearnableAbilities[] = {
    ABILITY_TRUANT,
    ABILITY_VITAL_SPIRIT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SLAKOTH)
static const u16 sSlakingLearnableAbilities[] = {
    ABILITY_TRUANT,
    ABILITY_VITAL_SPIRIT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_NINCADA)
static const u16 sNincadaLearnableAbilities[] = {
    ABILITY_COMPOUND_EYES,
    ABILITY_RUN_AWAY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_NINCADA)
static const u16 sNinjaskLearnableAbilities[] = {
    ABILITY_COMPOUND_EYES,
    ABILITY_RUN_AWAY,
    ABILITY_SPEED_BOOST,
    ABILITY_INFILTRATOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_NINCADA)
static const u16 sShedinjaLearnableAbilities[] = {
    ABILITY_COMPOUND_EYES,
    ABILITY_RUN_AWAY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_WHISMUR)
static const u16 sWhismurLearnableAbilities[] = {
    ABILITY_SOUNDPROOF,
    ABILITY_RATTLED,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_WHISMUR)
static const u16 sLoudredLearnableAbilities[] = {
    ABILITY_SOUNDPROOF,
    ABILITY_RATTLED,
    ABILITY_SCRAPPY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_WHISMUR)
static const u16 sExploudLearnableAbilities[] = {
    ABILITY_SOUNDPROOF,
    ABILITY_RATTLED,
    ABILITY_SCRAPPY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MAKUHITA)
static const u16 sMakuhitaLearnableAbilities[] = {
    ABILITY_THICK_FAT,
    ABILITY_GUTS,
    ABILITY_SHEER_FORCE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MAKUHITA)
static const u16 sHariyamaLearnableAbilities[] = {
    ABILITY_THICK_FAT,
    ABILITY_GUTS,
    ABILITY_SHEER_FORCE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_NOSEPASS)
static const u16 sNosepassLearnableAbilities[] = {
    ABILITY_STURDY,
    ABILITY_MAGNET_PULL,
    ABILITY_SAND_FORCE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_NOSEPASS) && (P_GEN_4_CROSS_EVOS)
static const u16 sProbopassLearnableAbilities[] = {
    ABILITY_STURDY,
    ABILITY_MAGNET_PULL,
    ABILITY_SAND_FORCE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SKITTY)
static const u16 sSkittyLearnableAbilities[] = {
    ABILITY_CUTE_CHARM,
    ABILITY_NORMALIZE,
    ABILITY_WONDER_SKIN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SKITTY)
static const u16 sDelcattyLearnableAbilities[] = {
    ABILITY_CUTE_CHARM,
    ABILITY_NORMALIZE,
    ABILITY_WONDER_SKIN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SABLEYE)
static const u16 sSableyeLearnableAbilities[] = {
    ABILITY_KEEN_EYE,
    ABILITY_STALL,
    ABILITY_PRANKSTER,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MAWILE)
static const u16 sMawileLearnableAbilities[] = {
    ABILITY_HYPER_CUTTER,
    ABILITY_INTIMIDATE,
    ABILITY_SHEER_FORCE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ARON)
static const u16 sAronLearnableAbilities[] = {
    ABILITY_STURDY,
    ABILITY_ROCK_HEAD,
    ABILITY_HEAVY_METAL,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ARON)
static const u16 sLaironLearnableAbilities[] = {
    ABILITY_STURDY,
    ABILITY_ROCK_HEAD,
    ABILITY_HEAVY_METAL,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ARON)
static const u16 sAggronLearnableAbilities[] = {
    ABILITY_STURDY,
    ABILITY_ROCK_HEAD,
    ABILITY_HEAVY_METAL,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MEDITITE)
static const u16 sMedititeLearnableAbilities[] = {
    ABILITY_PURE_POWER,
    ABILITY_TELEPATHY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MEDITITE)
static const u16 sMedichamLearnableAbilities[] = {
    ABILITY_PURE_POWER,
    ABILITY_TELEPATHY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ELECTRIKE)
static const u16 sElectrikeLearnableAbilities[] = {
    ABILITY_STATIC,
    ABILITY_LIGHTNING_ROD,
    ABILITY_MINUS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ELECTRIKE)
static const u16 sManectricLearnableAbilities[] = {
    ABILITY_STATIC,
    ABILITY_LIGHTNING_ROD,
    ABILITY_MINUS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PLUSLE)
static const u16 sPlusleLearnableAbilities[] = {
    ABILITY_PLUS,
    ABILITY_LIGHTNING_ROD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MINUN)
static const u16 sMinunLearnableAbilities[] = {
    ABILITY_MINUS,
    ABILITY_VOLT_ABSORB,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_VOLBEAT_ILLUMISE)
static const u16 sVolbeatLearnableAbilities[] = {
    ABILITY_ILLUMINATE,
    ABILITY_SWARM,
    ABILITY_PRANKSTER,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_VOLBEAT_ILLUMISE)
static const u16 sIllumiseLearnableAbilities[] = {
    ABILITY_OBLIVIOUS,
    ABILITY_TINTED_LENS,
    ABILITY_PRANKSTER,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ROSELIA) && (P_GEN_4_CROSS_EVOS)
static const u16 sBudewLearnableAbilities[] = {
    ABILITY_NATURAL_CURE,
    ABILITY_POISON_POINT,
    ABILITY_LEAF_GUARD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ROSELIA)
static const u16 sRoseliaLearnableAbilities[] = {
    ABILITY_NATURAL_CURE,
    ABILITY_POISON_POINT,
    ABILITY_LEAF_GUARD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ROSELIA) && (P_GEN_4_CROSS_EVOS)
static const u16 sRoseradeLearnableAbilities[] = {
    ABILITY_NATURAL_CURE,
    ABILITY_POISON_POINT,
    ABILITY_LEAF_GUARD,
    ABILITY_TECHNICIAN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GULPIN)
static const u16 sGulpinLearnableAbilities[] = {
    ABILITY_LIQUID_OOZE,
    ABILITY_STICKY_HOLD,
    ABILITY_GLUTTONY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GULPIN)
static const u16 sSwalotLearnableAbilities[] = {
    ABILITY_LIQUID_OOZE,
    ABILITY_STICKY_HOLD,
    ABILITY_GLUTTONY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CARVANHA)
static const u16 sCarvanhaLearnableAbilities[] = {
    ABILITY_ROUGH_SKIN,
    ABILITY_SPEED_BOOST,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CARVANHA)
static const u16 sSharpedoLearnableAbilities[] = {
    ABILITY_ROUGH_SKIN,
    ABILITY_SPEED_BOOST,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_WAILMER)
static const u16 sWailmerLearnableAbilities[] = {
    ABILITY_WATER_VEIL,
    ABILITY_OBLIVIOUS,
    ABILITY_PRESSURE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_WAILMER)
static const u16 sWailordLearnableAbilities[] = {
    ABILITY_WATER_VEIL,
    ABILITY_OBLIVIOUS,
    ABILITY_PRESSURE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_NUMEL)
static const u16 sNumelLearnableAbilities[] = {
    ABILITY_OBLIVIOUS,
    ABILITY_SIMPLE,
    ABILITY_OWN_TEMPO,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_NUMEL)
static const u16 sCameruptLearnableAbilities[] = {
    ABILITY_OBLIVIOUS,
    ABILITY_SIMPLE,
    ABILITY_OWN_TEMPO,
    ABILITY_MAGMA_ARMOR,
    ABILITY_SOLID_ROCK,
    ABILITY_ANGER_POINT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TORKOAL)
static const u16 sTorkoalLearnableAbilities[] = {
    ABILITY_WHITE_SMOKE,
    ABILITY_DROUGHT,
    ABILITY_SHELL_ARMOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SPOINK)
static const u16 sSpoinkLearnableAbilities[] = {
    ABILITY_THICK_FAT,
    ABILITY_OWN_TEMPO,
    ABILITY_GLUTTONY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SPOINK)
static const u16 sGrumpigLearnableAbilities[] = {
    ABILITY_THICK_FAT,
    ABILITY_OWN_TEMPO,
    ABILITY_GLUTTONY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SPINDA)
static const u16 sSpindaLearnableAbilities[] = {
    ABILITY_OWN_TEMPO,
    ABILITY_TANGLED_FEET,
    ABILITY_CONTRARY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TRAPINCH)
static const u16 sTrapinchLearnableAbilities[] = {
    ABILITY_HYPER_CUTTER,
    ABILITY_ARENA_TRAP,
    ABILITY_SHEER_FORCE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TRAPINCH)
static const u16 sVibravaLearnableAbilities[] = {
    ABILITY_HYPER_CUTTER,
    ABILITY_ARENA_TRAP,
    ABILITY_SHEER_FORCE,
    ABILITY_LEVITATE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TRAPINCH)
static const u16 sFlygonLearnableAbilities[] = {
    ABILITY_HYPER_CUTTER,
    ABILITY_ARENA_TRAP,
    ABILITY_SHEER_FORCE,
    ABILITY_LEVITATE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CACNEA)
static const u16 sCacneaLearnableAbilities[] = {
    ABILITY_SAND_VEIL,
    ABILITY_WATER_ABSORB,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CACNEA)
static const u16 sCacturneLearnableAbilities[] = {
    ABILITY_SAND_VEIL,
    ABILITY_WATER_ABSORB,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SWABLU)
static const u16 sSwabluLearnableAbilities[] = {
    ABILITY_NATURAL_CURE,
    ABILITY_CLOUD_NINE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SWABLU)
static const u16 sAltariaLearnableAbilities[] = {
    ABILITY_NATURAL_CURE,
    ABILITY_CLOUD_NINE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ZANGOOSE)
static const u16 sZangooseLearnableAbilities[] = {
    ABILITY_IMMUNITY,
    ABILITY_TOXIC_BOOST,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SEVIPER)
static const u16 sSeviperLearnableAbilities[] = {
    ABILITY_SHED_SKIN,
    ABILITY_INFILTRATOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_LUNATONE)
static const u16 sLunatoneLearnableAbilities[] = {
    ABILITY_LEVITATE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SOLROCK)
static const u16 sSolrockLearnableAbilities[] = {
    ABILITY_LEVITATE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_BARBOACH)
static const u16 sBarboachLearnableAbilities[] = {
    ABILITY_OBLIVIOUS,
    ABILITY_ANTICIPATION,
    ABILITY_HYDRATION,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_BARBOACH)
static const u16 sWhiscashLearnableAbilities[] = {
    ABILITY_OBLIVIOUS,
    ABILITY_ANTICIPATION,
    ABILITY_HYDRATION,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CORPHISH)
static const u16 sCorphishLearnableAbilities[] = {
    ABILITY_HYPER_CUTTER,
    ABILITY_SHELL_ARMOR,
    ABILITY_ADAPTABILITY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CORPHISH)
static const u16 sCrawdauntLearnableAbilities[] = {
    ABILITY_HYPER_CUTTER,
    ABILITY_SHELL_ARMOR,
    ABILITY_ADAPTABILITY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_BALTOY)
static const u16 sBaltoyLearnableAbilities[] = {
    ABILITY_LEVITATE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_BALTOY)
static const u16 sClaydolLearnableAbilities[] = {
    ABILITY_LEVITATE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_LILEEP)
static const u16 sLileepLearnableAbilities[] = {
    ABILITY_SUCTION_CUPS,
    ABILITY_STORM_DRAIN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_LILEEP)
static const u16 sCradilyLearnableAbilities[] = {
    ABILITY_SUCTION_CUPS,
    ABILITY_STORM_DRAIN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ANORITH)
static const u16 sAnorithLearnableAbilities[] = {
    ABILITY_BATTLE_ARMOR,
    ABILITY_SWIFT_SWIM,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ANORITH)
static const u16 sArmaldoLearnableAbilities[] = {
    ABILITY_BATTLE_ARMOR,
    ABILITY_SWIFT_SWIM,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FEEBAS)
static const u16 sFeebasLearnableAbilities[] = {
    ABILITY_SWIFT_SWIM,
    ABILITY_OBLIVIOUS,
    ABILITY_ADAPTABILITY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FEEBAS)
static const u16 sMiloticLearnableAbilities[] = {
    ABILITY_SWIFT_SWIM,
    ABILITY_OBLIVIOUS,
    ABILITY_ADAPTABILITY,
    ABILITY_MARVEL_SCALE,
    ABILITY_COMPETITIVE,
    ABILITY_CUTE_CHARM,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CASTFORM)
static const u16 sCastformNormalLearnableAbilities[] = {
    ABILITY_FORECAST,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_KECLEON)
static const u16 sKecleonLearnableAbilities[] = {
    ABILITY_COLOR_CHANGE,
    ABILITY_PROTEAN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SHUPPET)
static const u16 sShuppetLearnableAbilities[] = {
    ABILITY_INSOMNIA,
    ABILITY_FRISK,
    ABILITY_CURSED_BODY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SHUPPET)
static const u16 sBanetteLearnableAbilities[] = {
    ABILITY_INSOMNIA,
    ABILITY_FRISK,
    ABILITY_CURSED_BODY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DUSKULL)
static const u16 sDuskullLearnableAbilities[] = {
    ABILITY_LEVITATE,
    ABILITY_FRISK,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DUSKULL)
static const u16 sDusclopsLearnableAbilities[] = {
    ABILITY_LEVITATE,
    ABILITY_FRISK,
    ABILITY_PRESSURE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DUSKULL) && (P_GEN_4_CROSS_EVOS)
static const u16 sDusknoirLearnableAbilities[] = {
    ABILITY_LEVITATE,
    ABILITY_FRISK,
    ABILITY_PRESSURE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TROPIUS)
static const u16 sTropiusLearnableAbilities[] = {
    ABILITY_CHLOROPHYLL,
    ABILITY_SOLAR_POWER,
    ABILITY_HARVEST,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CHIMECHO) && (P_GEN_4_CROSS_EVOS)
static const u16 sChinglingLearnableAbilities[] = {
    ABILITY_LEVITATE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CHIMECHO)
static const u16 sChimechoLearnableAbilities[] = {
    ABILITY_LEVITATE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ABSOL)
static const u16 sAbsolLearnableAbilities[] = {
    ABILITY_PRESSURE,
    ABILITY_SUPER_LUCK,
    ABILITY_JUSTIFIED,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SNORUNT)
static const u16 sSnoruntLearnableAbilities[] = {
    ABILITY_INNER_FOCUS,
    ABILITY_ICE_BODY,
    ABILITY_MOODY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SNORUNT)
static const u16 sGlalieLearnableAbilities[] = {
    ABILITY_INNER_FOCUS,
    ABILITY_ICE_BODY,
    ABILITY_MOODY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SNORUNT) && (P_GEN_4_CROSS_EVOS)
static const u16 sFroslassLearnableAbilities[] = {
    ABILITY_INNER_FOCUS,
    ABILITY_ICE_BODY,
    ABILITY_MOODY,
    ABILITY_SNOW_CLOAK,
    ABILITY_CURSED_BODY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SPHEAL)
static const u16 sSphealLearnableAbilities[] = {
    ABILITY_THICK_FAT,
    ABILITY_ICE_BODY,
    ABILITY_OBLIVIOUS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SPHEAL)
static const u16 sSealeoLearnableAbilities[] = {
    ABILITY_THICK_FAT,
    ABILITY_ICE_BODY,
    ABILITY_OBLIVIOUS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SPHEAL)
static const u16 sWalreinLearnableAbilities[] = {
    ABILITY_THICK_FAT,
    ABILITY_ICE_BODY,
    ABILITY_OBLIVIOUS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CLAMPERL)
static const u16 sClamperlLearnableAbilities[] = {
    ABILITY_SHELL_ARMOR,
    ABILITY_RATTLED,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CLAMPERL)
static const u16 sHuntailLearnableAbilities[] = {
    ABILITY_SHELL_ARMOR,
    ABILITY_RATTLED,
    ABILITY_SWIFT_SWIM,
    ABILITY_WATER_VEIL,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CLAMPERL)
static const u16 sGorebyssLearnableAbilities[] = {
    ABILITY_SHELL_ARMOR,
    ABILITY_RATTLED,
    ABILITY_SWIFT_SWIM,
    ABILITY_HYDRATION,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_RELICANTH)
static const u16 sRelicanthLearnableAbilities[] = {
    ABILITY_SWIFT_SWIM,
    ABILITY_ROCK_HEAD,
    ABILITY_STURDY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_LUVDISC)
static const u16 sLuvdiscLearnableAbilities[] = {
    ABILITY_SWIFT_SWIM,
    ABILITY_HYDRATION,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_BAGON)
static const u16 sBagonLearnableAbilities[] = {
    ABILITY_ROCK_HEAD,
    ABILITY_SHEER_FORCE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_BAGON)
static const u16 sShelgonLearnableAbilities[] = {
    ABILITY_ROCK_HEAD,
    ABILITY_SHEER_FORCE,
    ABILITY_OVERCOAT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_BAGON)
static const u16 sSalamenceLearnableAbilities[] = {
    ABILITY_ROCK_HEAD,
    ABILITY_SHEER_FORCE,
    ABILITY_OVERCOAT,
    ABILITY_INTIMIDATE,
    ABILITY_MOXIE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_BELDUM)
static const u16 sBeldumLearnableAbilities[] = {
    ABILITY_CLEAR_BODY,
    ABILITY_LIGHT_METAL,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_BELDUM)
static const u16 sMetangLearnableAbilities[] = {
    ABILITY_CLEAR_BODY,
    ABILITY_LIGHT_METAL,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_BELDUM)
static const u16 sMetagrossLearnableAbilities[] = {
    ABILITY_CLEAR_BODY,
    ABILITY_LIGHT_METAL,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_REGIROCK)
static const u16 sRegirockLearnableAbilities[] = {
    ABILITY_CLEAR_BODY,
    ABILITY_STURDY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_REGICE)
static const u16 sRegiceLearnableAbilities[] = {
    ABILITY_CLEAR_BODY,
    ABILITY_ICE_BODY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_REGISTEEL)
static const u16 sRegisteelLearnableAbilities[] = {
    ABILITY_CLEAR_BODY,
    ABILITY_LIGHT_METAL,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_LATIAS)
static const u16 sLatiasLearnableAbilities[] = {
    ABILITY_LEVITATE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_LATIOS)
static const u16 sLatiosLearnableAbilities[] = {
    ABILITY_LEVITATE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_KYOGRE)
static const u16 sKyogreLearnableAbilities[] = {
    ABILITY_DRIZZLE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GROUDON)
static const u16 sGroudonLearnableAbilities[] = {
    ABILITY_DROUGHT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_RAYQUAZA)
static const u16 sRayquazaLearnableAbilities[] = {
    ABILITY_AIR_LOCK,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_JIRACHI)
static const u16 sJirachiLearnableAbilities[] = {
    ABILITY_SERENE_GRACE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DEOXYS)
static const u16 sDeoxysNormalLearnableAbilities[] = {
    ABILITY_PRESSURE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TURTWIG)
static const u16 sTurtwigLearnableAbilities[] = {
    ABILITY_OVERGROW,
    ABILITY_SHELL_ARMOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TURTWIG)
static const u16 sGrotleLearnableAbilities[] = {
    ABILITY_OVERGROW,
    ABILITY_SHELL_ARMOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TURTWIG)
static const u16 sTorterraLearnableAbilities[] = {
    ABILITY_OVERGROW,
    ABILITY_SHELL_ARMOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CHIMCHAR)
static const u16 sChimcharLearnableAbilities[] = {
    ABILITY_BLAZE,
    ABILITY_IRON_FIST,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CHIMCHAR)
static const u16 sMonfernoLearnableAbilities[] = {
    ABILITY_BLAZE,
    ABILITY_IRON_FIST,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CHIMCHAR)
static const u16 sInfernapeLearnableAbilities[] = {
    ABILITY_BLAZE,
    ABILITY_IRON_FIST,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PIPLUP)
static const u16 sPiplupLearnableAbilities[] = {
    ABILITY_TORRENT,
    ABILITY_COMPETITIVE,
    ABILITY_DEFIANT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PIPLUP)
static const u16 sPrinplupLearnableAbilities[] = {
    ABILITY_TORRENT,
    ABILITY_COMPETITIVE,
    ABILITY_DEFIANT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PIPLUP)
static const u16 sEmpoleonLearnableAbilities[] = {
    ABILITY_TORRENT,
    ABILITY_COMPETITIVE,
    ABILITY_DEFIANT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_STARLY)
static const u16 sStarlyLearnableAbilities[] = {
    ABILITY_KEEN_EYE,
    ABILITY_RECKLESS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_STARLY)
static const u16 sStaraviaLearnableAbilities[] = {
    ABILITY_KEEN_EYE,
    ABILITY_RECKLESS,
    ABILITY_INTIMIDATE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_STARLY)
static const u16 sStaraptorLearnableAbilities[] = {
    ABILITY_KEEN_EYE,
    ABILITY_RECKLESS,
    ABILITY_INTIMIDATE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_BIDOOF)
static const u16 sBidoofLearnableAbilities[] = {
    ABILITY_SIMPLE,
    ABILITY_UNAWARE,
    ABILITY_MOODY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_BIDOOF)
static const u16 sBibarelLearnableAbilities[] = {
    ABILITY_SIMPLE,
    ABILITY_UNAWARE,
    ABILITY_MOODY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_KRICKETOT)
static const u16 sKricketotLearnableAbilities[] = {
    ABILITY_SHED_SKIN,
    ABILITY_RUN_AWAY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_KRICKETOT)
static const u16 sKricketuneLearnableAbilities[] = {
    ABILITY_SHED_SKIN,
    ABILITY_RUN_AWAY,
    ABILITY_SWARM,
    ABILITY_TECHNICIAN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SHINX)
static const u16 sShinxLearnableAbilities[] = {
    ABILITY_RIVALRY,
    ABILITY_INTIMIDATE,
    ABILITY_GUTS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SHINX)
static const u16 sLuxioLearnableAbilities[] = {
    ABILITY_RIVALRY,
    ABILITY_INTIMIDATE,
    ABILITY_GUTS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SHINX)
static const u16 sLuxrayLearnableAbilities[] = {
    ABILITY_RIVALRY,
    ABILITY_INTIMIDATE,
    ABILITY_GUTS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CRANIDOS)
static const u16 sCranidosLearnableAbilities[] = {
    ABILITY_MOLD_BREAKER,
    ABILITY_SHEER_FORCE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CRANIDOS)
static const u16 sRampardosLearnableAbilities[] = {
    ABILITY_MOLD_BREAKER,
    ABILITY_SHEER_FORCE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SHIELDON)
static const u16 sShieldonLearnableAbilities[] = {
    ABILITY_STURDY,
    ABILITY_SOUNDPROOF,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SHIELDON)
static const u16 sBastiodonLearnableAbilities[] = {
    ABILITY_STURDY,
    ABILITY_SOUNDPROOF,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_BURMY)
static const u16 sBurmyPlantLearnableAbilities[] = {
    ABILITY_SHED_SKIN,
    ABILITY_OVERCOAT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_BURMY)
static const u16 sWormadamPlantLearnableAbilities[] = {
    ABILITY_SHED_SKIN,
    ABILITY_OVERCOAT,
    ABILITY_ANTICIPATION,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_BURMY)
static const u16 sWormadamSandyLearnableAbilities[] = {
    ABILITY_SHED_SKIN,
    ABILITY_OVERCOAT,
    ABILITY_ANTICIPATION,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_BURMY)
static const u16 sWormadamTrashLearnableAbilities[] = {
    ABILITY_SHED_SKIN,
    ABILITY_OVERCOAT,
    ABILITY_ANTICIPATION,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_BURMY)
static const u16 sMothimPlantLearnableAbilities[] = {
    ABILITY_SHED_SKIN,
    ABILITY_OVERCOAT,
    ABILITY_SWARM,
    ABILITY_TINTED_LENS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_COMBEE)
static const u16 sCombeeLearnableAbilities[] = {
    ABILITY_HONEY_GATHER,
    ABILITY_HUSTLE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_COMBEE)
static const u16 sVespiquenLearnableAbilities[] = {
    ABILITY_HONEY_GATHER,
    ABILITY_HUSTLE,
    ABILITY_PRESSURE,
    ABILITY_UNNERVE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PACHIRISU)
static const u16 sPachirisuLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_PICKUP,
    ABILITY_VOLT_ABSORB,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_BUIZEL)
static const u16 sBuizelLearnableAbilities[] = {
    ABILITY_SWIFT_SWIM,
    ABILITY_WATER_VEIL,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_BUIZEL)
static const u16 sFloatzelLearnableAbilities[] = {
    ABILITY_SWIFT_SWIM,
    ABILITY_WATER_VEIL,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CHERUBI)
static const u16 sCherubiLearnableAbilities[] = {
    ABILITY_CHLOROPHYLL,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CHERUBI)
static const u16 sCherrimOvercastLearnableAbilities[] = {
    ABILITY_CHLOROPHYLL,
    ABILITY_FLOWER_GIFT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SHELLOS)
static const u16 sShellosWestLearnableAbilities[] = {
    ABILITY_STICKY_HOLD,
    ABILITY_STORM_DRAIN,
    ABILITY_SAND_FORCE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SHELLOS)
static const u16 sShellosEastLearnableAbilities[] = {
    ABILITY_STICKY_HOLD,
    ABILITY_STORM_DRAIN,
    ABILITY_SAND_FORCE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SHELLOS)
static const u16 sGastrodonWestLearnableAbilities[] = {
    ABILITY_STICKY_HOLD,
    ABILITY_STORM_DRAIN,
    ABILITY_SAND_FORCE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SHELLOS)
static const u16 sGastrodonEastLearnableAbilities[] = {
    ABILITY_STICKY_HOLD,
    ABILITY_STORM_DRAIN,
    ABILITY_SAND_FORCE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DRIFLOON)
static const u16 sDrifloonLearnableAbilities[] = {
    ABILITY_AFTERMATH,
    ABILITY_UNBURDEN,
    ABILITY_FLARE_BOOST,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DRIFLOON)
static const u16 sDrifblimLearnableAbilities[] = {
    ABILITY_AFTERMATH,
    ABILITY_UNBURDEN,
    ABILITY_FLARE_BOOST,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_BUNEARY)
static const u16 sBunearyLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_KLUTZ,
    ABILITY_LIMBER,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_BUNEARY)
static const u16 sLopunnyLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_KLUTZ,
    ABILITY_LIMBER,
    ABILITY_CUTE_CHARM,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GLAMEOW)
static const u16 sGlameowLearnableAbilities[] = {
    ABILITY_LIMBER,
    ABILITY_OWN_TEMPO,
    ABILITY_KEEN_EYE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GLAMEOW)
static const u16 sPuruglyLearnableAbilities[] = {
    ABILITY_LIMBER,
    ABILITY_OWN_TEMPO,
    ABILITY_KEEN_EYE,
    ABILITY_THICK_FAT,
    ABILITY_DEFIANT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_STUNKY)
static const u16 sStunkyLearnableAbilities[] = {
    ABILITY_STENCH,
    ABILITY_AFTERMATH,
    ABILITY_KEEN_EYE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_STUNKY)
static const u16 sSkuntankLearnableAbilities[] = {
    ABILITY_STENCH,
    ABILITY_AFTERMATH,
    ABILITY_KEEN_EYE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_BRONZOR)
static const u16 sBronzorLearnableAbilities[] = {
    ABILITY_LEVITATE,
    ABILITY_HEATPROOF,
    ABILITY_HEAVY_METAL,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_BRONZOR)
static const u16 sBronzongLearnableAbilities[] = {
    ABILITY_LEVITATE,
    ABILITY_HEATPROOF,
    ABILITY_HEAVY_METAL,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CHATOT)
static const u16 sChatotLearnableAbilities[] = {
    ABILITY_KEEN_EYE,
    ABILITY_TANGLED_FEET,
    ABILITY_BIG_PECKS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SPIRITOMB)
static const u16 sSpiritombLearnableAbilities[] = {
    ABILITY_PRESSURE,
    ABILITY_INFILTRATOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GIBLE)
static const u16 sGibleLearnableAbilities[] = {
    ABILITY_SAND_VEIL,
    ABILITY_ROUGH_SKIN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GIBLE)
static const u16 sGabiteLearnableAbilities[] = {
    ABILITY_SAND_VEIL,
    ABILITY_ROUGH_SKIN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GIBLE)
static const u16 sGarchompLearnableAbilities[] = {
    ABILITY_SAND_VEIL,
    ABILITY_ROUGH_SKIN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_RIOLU)
static const u16 sRioluLearnableAbilities[] = {
    ABILITY_STEADFAST,
    ABILITY_INNER_FOCUS,
    ABILITY_PRANKSTER,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_RIOLU)
static const u16 sLucarioLearnableAbilities[] = {
    ABILITY_STEADFAST,
    ABILITY_INNER_FOCUS,
    ABILITY_PRANKSTER,
    ABILITY_JUSTIFIED,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_HIPPOPOTAS)
static const u16 sHippopotasLearnableAbilities[] = {
    ABILITY_SAND_STREAM,
    ABILITY_SAND_FORCE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_HIPPOPOTAS)
static const u16 sHippowdonLearnableAbilities[] = {
    ABILITY_SAND_STREAM,
    ABILITY_SAND_FORCE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SKORUPI)
static const u16 sSkorupiLearnableAbilities[] = {
    ABILITY_BATTLE_ARMOR,
    ABILITY_SNIPER,
    ABILITY_KEEN_EYE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SKORUPI)
static const u16 sDrapionLearnableAbilities[] = {
    ABILITY_BATTLE_ARMOR,
    ABILITY_SNIPER,
    ABILITY_KEEN_EYE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CROAGUNK)
static const u16 sCroagunkLearnableAbilities[] = {
    ABILITY_ANTICIPATION,
    ABILITY_DRY_SKIN,
    ABILITY_POISON_TOUCH,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CROAGUNK)
static const u16 sToxicroakLearnableAbilities[] = {
    ABILITY_ANTICIPATION,
    ABILITY_DRY_SKIN,
    ABILITY_POISON_TOUCH,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CARNIVINE)
static const u16 sCarnivineLearnableAbilities[] = {
    ABILITY_LEVITATE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FINNEON)
static const u16 sFinneonLearnableAbilities[] = {
    ABILITY_SWIFT_SWIM,
    ABILITY_STORM_DRAIN,
    ABILITY_WATER_VEIL,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FINNEON)
static const u16 sLumineonLearnableAbilities[] = {
    ABILITY_SWIFT_SWIM,
    ABILITY_STORM_DRAIN,
    ABILITY_WATER_VEIL,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SNOVER)
static const u16 sSnoverLearnableAbilities[] = {
    ABILITY_SNOW_WARNING,
    ABILITY_SOUNDPROOF,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SNOVER)
static const u16 sAbomasnowLearnableAbilities[] = {
    ABILITY_SNOW_WARNING,
    ABILITY_SOUNDPROOF,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ROTOM)
static const u16 sRotomLearnableAbilities[] = {
    ABILITY_LEVITATE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_UXIE)
static const u16 sUxieLearnableAbilities[] = {
    ABILITY_LEVITATE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MESPRIT)
static const u16 sMespritLearnableAbilities[] = {
    ABILITY_LEVITATE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_AZELF)
static const u16 sAzelfLearnableAbilities[] = {
    ABILITY_LEVITATE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DIALGA)
static const u16 sDialgaLearnableAbilities[] = {
    ABILITY_PRESSURE,
    ABILITY_TELEPATHY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PALKIA)
static const u16 sPalkiaLearnableAbilities[] = {
    ABILITY_PRESSURE,
    ABILITY_TELEPATHY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_HEATRAN)
static const u16 sHeatranLearnableAbilities[] = {
    ABILITY_FLASH_FIRE,
    ABILITY_FLAME_BODY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_REGIGIGAS)
static const u16 sRegigigasLearnableAbilities[] = {
    ABILITY_SLOW_START,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GIRATINA)
static const u16 sGiratinaAlteredLearnableAbilities[] = {
    ABILITY_PRESSURE,
    ABILITY_TELEPATHY,
    ABILITY_LEVITATE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CRESSELIA)
static const u16 sCresseliaLearnableAbilities[] = {
    ABILITY_LEVITATE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MANAPHY)
static const u16 sPhioneLearnableAbilities[] = {
    ABILITY_HYDRATION,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MANAPHY)
static const u16 sManaphyLearnableAbilities[] = {
    ABILITY_HYDRATION,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DARKRAI)
static const u16 sDarkraiLearnableAbilities[] = {
    ABILITY_BAD_DREAMS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SHAYMIN)
static const u16 sShayminLandLearnableAbilities[] = {
    ABILITY_NATURAL_CURE,
    ABILITY_SERENE_GRACE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ARCEUS)
static const u16 sArceusNormalLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_VICTINI)
static const u16 sVictiniLearnableAbilities[] = {
    ABILITY_VICTORY_STAR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SNIVY)
static const u16 sSnivyLearnableAbilities[] = {
    ABILITY_OVERGROW,
    ABILITY_CONTRARY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SNIVY)
static const u16 sServineLearnableAbilities[] = {
    ABILITY_OVERGROW,
    ABILITY_CONTRARY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SNIVY)
static const u16 sSerperiorLearnableAbilities[] = {
    ABILITY_OVERGROW,
    ABILITY_CONTRARY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TEPIG)
static const u16 sTepigLearnableAbilities[] = {
    ABILITY_BLAZE,
    ABILITY_THICK_FAT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TEPIG)
static const u16 sPigniteLearnableAbilities[] = {
    ABILITY_BLAZE,
    ABILITY_THICK_FAT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TEPIG)
static const u16 sEmboarLearnableAbilities[] = {
    ABILITY_BLAZE,
    ABILITY_THICK_FAT,
    ABILITY_RECKLESS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_OSHAWOTT)
static const u16 sOshawottLearnableAbilities[] = {
    ABILITY_TORRENT,
    ABILITY_SHELL_ARMOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_OSHAWOTT)
static const u16 sDewottLearnableAbilities[] = {
    ABILITY_TORRENT,
    ABILITY_SHELL_ARMOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_OSHAWOTT)
static const u16 sSamurottLearnableAbilities[] = {
    ABILITY_TORRENT,
    ABILITY_SHELL_ARMOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_OSHAWOTT) && (P_HISUIAN_FORMS)
static const u16 sSamurottHisuiLearnableAbilities[] = {
    ABILITY_TORRENT,
    ABILITY_SHELL_ARMOR,
    ABILITY_SHARPNESS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PATRAT)
static const u16 sPatratLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_KEEN_EYE,
    ABILITY_ANALYTIC,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PATRAT)
static const u16 sWatchogLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_KEEN_EYE,
    ABILITY_ANALYTIC,
    ABILITY_ILLUMINATE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_LILLIPUP)
static const u16 sLillipupLearnableAbilities[] = {
    ABILITY_VITAL_SPIRIT,
    ABILITY_PICKUP,
    ABILITY_RUN_AWAY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_LILLIPUP)
static const u16 sHerdierLearnableAbilities[] = {
    ABILITY_VITAL_SPIRIT,
    ABILITY_PICKUP,
    ABILITY_RUN_AWAY,
    ABILITY_INTIMIDATE,
    ABILITY_SAND_RUSH,
    ABILITY_SCRAPPY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_LILLIPUP)
static const u16 sStoutlandLearnableAbilities[] = {
    ABILITY_VITAL_SPIRIT,
    ABILITY_PICKUP,
    ABILITY_RUN_AWAY,
    ABILITY_INTIMIDATE,
    ABILITY_SAND_RUSH,
    ABILITY_SCRAPPY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PURRLOIN)
static const u16 sPurrloinLearnableAbilities[] = {
    ABILITY_LIMBER,
    ABILITY_UNBURDEN,
    ABILITY_PRANKSTER,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PURRLOIN)
static const u16 sLiepardLearnableAbilities[] = {
    ABILITY_LIMBER,
    ABILITY_UNBURDEN,
    ABILITY_PRANKSTER,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PANSAGE)
static const u16 sPansageLearnableAbilities[] = {
    ABILITY_GLUTTONY,
    ABILITY_OVERGROW,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PANSAGE)
static const u16 sSimisageLearnableAbilities[] = {
    ABILITY_GLUTTONY,
    ABILITY_OVERGROW,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PANSEAR)
static const u16 sPansearLearnableAbilities[] = {
    ABILITY_GLUTTONY,
    ABILITY_BLAZE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PANSEAR)
static const u16 sSimisearLearnableAbilities[] = {
    ABILITY_GLUTTONY,
    ABILITY_BLAZE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PANPOUR)
static const u16 sPanpourLearnableAbilities[] = {
    ABILITY_GLUTTONY,
    ABILITY_TORRENT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PANPOUR)
static const u16 sSimipourLearnableAbilities[] = {
    ABILITY_GLUTTONY,
    ABILITY_TORRENT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MUNNA)
static const u16 sMunnaLearnableAbilities[] = {
    ABILITY_FOREWARN,
    ABILITY_SYNCHRONIZE,
    ABILITY_TELEPATHY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MUNNA)
static const u16 sMusharnaLearnableAbilities[] = {
    ABILITY_FOREWARN,
    ABILITY_SYNCHRONIZE,
    ABILITY_TELEPATHY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PIDOVE)
static const u16 sPidoveLearnableAbilities[] = {
    ABILITY_BIG_PECKS,
    ABILITY_SUPER_LUCK,
    ABILITY_RIVALRY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PIDOVE)
static const u16 sTranquillLearnableAbilities[] = {
    ABILITY_BIG_PECKS,
    ABILITY_SUPER_LUCK,
    ABILITY_RIVALRY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PIDOVE)
static const u16 sUnfezantLearnableAbilities[] = {
    ABILITY_BIG_PECKS,
    ABILITY_SUPER_LUCK,
    ABILITY_RIVALRY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_BLITZLE)
static const u16 sBlitzleLearnableAbilities[] = {
    ABILITY_LIGHTNING_ROD,
    ABILITY_MOTOR_DRIVE,
    ABILITY_SAP_SIPPER,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_BLITZLE)
static const u16 sZebstrikaLearnableAbilities[] = {
    ABILITY_LIGHTNING_ROD,
    ABILITY_MOTOR_DRIVE,
    ABILITY_SAP_SIPPER,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ROGGENROLA)
static const u16 sRoggenrolaLearnableAbilities[] = {
    ABILITY_STURDY,
    ABILITY_WEAK_ARMOR,
    ABILITY_SAND_FORCE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ROGGENROLA)
static const u16 sBoldoreLearnableAbilities[] = {
    ABILITY_STURDY,
    ABILITY_WEAK_ARMOR,
    ABILITY_SAND_FORCE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ROGGENROLA)
static const u16 sGigalithLearnableAbilities[] = {
    ABILITY_STURDY,
    ABILITY_WEAK_ARMOR,
    ABILITY_SAND_FORCE,
    ABILITY_SAND_STREAM,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_WOOBAT)
static const u16 sWoobatLearnableAbilities[] = {
    ABILITY_UNAWARE,
    ABILITY_KLUTZ,
    ABILITY_SIMPLE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_WOOBAT)
static const u16 sSwoobatLearnableAbilities[] = {
    ABILITY_UNAWARE,
    ABILITY_KLUTZ,
    ABILITY_SIMPLE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DRILBUR)
static const u16 sDrilburLearnableAbilities[] = {
    ABILITY_SAND_RUSH,
    ABILITY_SAND_FORCE,
    ABILITY_MOLD_BREAKER,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DRILBUR)
static const u16 sExcadrillLearnableAbilities[] = {
    ABILITY_SAND_RUSH,
    ABILITY_SAND_FORCE,
    ABILITY_MOLD_BREAKER,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_AUDINO)
static const u16 sAudinoLearnableAbilities[] = {
    ABILITY_HEALER,
    ABILITY_REGENERATOR,
    ABILITY_KLUTZ,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TIMBURR)
static const u16 sTimburrLearnableAbilities[] = {
    ABILITY_GUTS,
    ABILITY_SHEER_FORCE,
    ABILITY_IRON_FIST,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TIMBURR)
static const u16 sGurdurrLearnableAbilities[] = {
    ABILITY_GUTS,
    ABILITY_SHEER_FORCE,
    ABILITY_IRON_FIST,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TIMBURR)
static const u16 sConkeldurrLearnableAbilities[] = {
    ABILITY_GUTS,
    ABILITY_SHEER_FORCE,
    ABILITY_IRON_FIST,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TYMPOLE)
static const u16 sTympoleLearnableAbilities[] = {
    ABILITY_SWIFT_SWIM,
    ABILITY_HYDRATION,
    ABILITY_WATER_ABSORB,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TYMPOLE)
static const u16 sPalpitoadLearnableAbilities[] = {
    ABILITY_SWIFT_SWIM,
    ABILITY_HYDRATION,
    ABILITY_WATER_ABSORB,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TYMPOLE)
static const u16 sSeismitoadLearnableAbilities[] = {
    ABILITY_SWIFT_SWIM,
    ABILITY_HYDRATION,
    ABILITY_WATER_ABSORB,
    ABILITY_POISON_TOUCH,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_THROH)
static const u16 sThrohLearnableAbilities[] = {
    ABILITY_GUTS,
    ABILITY_INNER_FOCUS,
    ABILITY_MOLD_BREAKER,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SAWK)
static const u16 sSawkLearnableAbilities[] = {
    ABILITY_STURDY,
    ABILITY_INNER_FOCUS,
    ABILITY_MOLD_BREAKER,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SEWADDLE)
static const u16 sSewaddleLearnableAbilities[] = {
    ABILITY_SWARM,
    ABILITY_CHLOROPHYLL,
    ABILITY_OVERCOAT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SEWADDLE)
static const u16 sSwadloonLearnableAbilities[] = {
    ABILITY_SWARM,
    ABILITY_CHLOROPHYLL,
    ABILITY_OVERCOAT,
    ABILITY_LEAF_GUARD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SEWADDLE)
static const u16 sLeavannyLearnableAbilities[] = {
    ABILITY_SWARM,
    ABILITY_CHLOROPHYLL,
    ABILITY_OVERCOAT,
    ABILITY_LEAF_GUARD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_VENIPEDE)
static const u16 sVenipedeLearnableAbilities[] = {
    ABILITY_POISON_POINT,
    ABILITY_SWARM,
    ABILITY_SPEED_BOOST,
    ABILITY_QUICK_FEET,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_VENIPEDE)
static const u16 sWhirlipedeLearnableAbilities[] = {
    ABILITY_POISON_POINT,
    ABILITY_SWARM,
    ABILITY_SPEED_BOOST,
    ABILITY_QUICK_FEET,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_VENIPEDE)
static const u16 sScolipedeLearnableAbilities[] = {
    ABILITY_POISON_POINT,
    ABILITY_SWARM,
    ABILITY_SPEED_BOOST,
    ABILITY_QUICK_FEET,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_COTTONEE)
static const u16 sCottoneeLearnableAbilities[] = {
    ABILITY_PRANKSTER,
    ABILITY_INFILTRATOR,
    ABILITY_CHLOROPHYLL,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_COTTONEE)
static const u16 sWhimsicottLearnableAbilities[] = {
    ABILITY_PRANKSTER,
    ABILITY_INFILTRATOR,
    ABILITY_CHLOROPHYLL,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PETILIL)
static const u16 sPetililLearnableAbilities[] = {
    ABILITY_CHLOROPHYLL,
    ABILITY_OWN_TEMPO,
    ABILITY_LEAF_GUARD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PETILIL)
static const u16 sLilligantLearnableAbilities[] = {
    ABILITY_CHLOROPHYLL,
    ABILITY_OWN_TEMPO,
    ABILITY_LEAF_GUARD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PETILIL) && (P_HISUIAN_FORMS)
static const u16 sLilligantHisuiLearnableAbilities[] = {
    ABILITY_CHLOROPHYLL,
    ABILITY_OWN_TEMPO,
    ABILITY_LEAF_GUARD,
    ABILITY_HUSTLE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_BASCULIN)
static const u16 sBasculinRedStripedLearnableAbilities[] = {
    ABILITY_RECKLESS,
    ABILITY_ADAPTABILITY,
    ABILITY_MOLD_BREAKER,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_BASCULIN)
static const u16 sBasculinBlueStripedLearnableAbilities[] = {
    ABILITY_ROCK_HEAD,
    ABILITY_ADAPTABILITY,
    ABILITY_MOLD_BREAKER,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_BASCULIN) && (P_HISUIAN_FORMS)
static const u16 sBasculinWhiteStripedLearnableAbilities[] = {
    ABILITY_RATTLED,
    ABILITY_ADAPTABILITY,
    ABILITY_MOLD_BREAKER,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_BASCULIN) && (P_HISUIAN_FORMS)
static const u16 sBasculegionMLearnableAbilities[] = {
    ABILITY_RATTLED,
    ABILITY_ADAPTABILITY,
    ABILITY_MOLD_BREAKER,
    ABILITY_SWIFT_SWIM,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_BASCULIN) && (P_HISUIAN_FORMS)
static const u16 sBasculegionFLearnableAbilities[] = {
    ABILITY_RATTLED,
    ABILITY_ADAPTABILITY,
    ABILITY_MOLD_BREAKER,
    ABILITY_SWIFT_SWIM,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SANDILE)
static const u16 sSandileLearnableAbilities[] = {
    ABILITY_INTIMIDATE,
    ABILITY_MOXIE,
    ABILITY_ANGER_POINT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SANDILE)
static const u16 sKrokorokLearnableAbilities[] = {
    ABILITY_INTIMIDATE,
    ABILITY_MOXIE,
    ABILITY_ANGER_POINT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SANDILE)
static const u16 sKrookodileLearnableAbilities[] = {
    ABILITY_INTIMIDATE,
    ABILITY_MOXIE,
    ABILITY_ANGER_POINT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DARUMAKA)
static const u16 sDarumakaLearnableAbilities[] = {
    ABILITY_HUSTLE,
    ABILITY_INNER_FOCUS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DARUMAKA)
static const u16 sDarmanitanStandardLearnableAbilities[] = {
    ABILITY_HUSTLE,
    ABILITY_INNER_FOCUS,
    ABILITY_SHEER_FORCE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DARUMAKA) && (P_GALARIAN_FORMS)
static const u16 sDarumakaGalarLearnableAbilities[] = {
    ABILITY_HUSTLE,
    ABILITY_INNER_FOCUS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DARUMAKA) && (P_GALARIAN_FORMS)
static const u16 sDarmanitanGalarStandardLearnableAbilities[] = {
    ABILITY_HUSTLE,
    ABILITY_INNER_FOCUS,
    ABILITY_GORILLA_TACTICS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MARACTUS)
static const u16 sMaractusLearnableAbilities[] = {
    ABILITY_WATER_ABSORB,
    ABILITY_CHLOROPHYLL,
    ABILITY_STORM_DRAIN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DWEBBLE)
static const u16 sDwebbleLearnableAbilities[] = {
    ABILITY_STURDY,
    ABILITY_SHELL_ARMOR,
    ABILITY_WEAK_ARMOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DWEBBLE)
static const u16 sCrustleLearnableAbilities[] = {
    ABILITY_STURDY,
    ABILITY_SHELL_ARMOR,
    ABILITY_WEAK_ARMOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SCRAGGY)
static const u16 sScraggyLearnableAbilities[] = {
    ABILITY_SHED_SKIN,
    ABILITY_MOXIE,
    ABILITY_INTIMIDATE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SCRAGGY)
static const u16 sScraftyLearnableAbilities[] = {
    ABILITY_SHED_SKIN,
    ABILITY_MOXIE,
    ABILITY_INTIMIDATE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SIGILYPH)
static const u16 sSigilyphLearnableAbilities[] = {
    ABILITY_WONDER_SKIN,
    ABILITY_MAGIC_GUARD,
    ABILITY_TINTED_LENS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_YAMASK)
static const u16 sYamaskLearnableAbilities[] = {
    ABILITY_MUMMY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_YAMASK)
static const u16 sCofagrigusLearnableAbilities[] = {
    ABILITY_MUMMY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_YAMASK) && (P_GALARIAN_FORMS)
static const u16 sYamaskGalarLearnableAbilities[] = {
    ABILITY_WANDERING_SPIRIT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_YAMASK) && (P_GALARIAN_FORMS)
static const u16 sRunerigusLearnableAbilities[] = {
    ABILITY_WANDERING_SPIRIT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TIRTOUGA)
static const u16 sTirtougaLearnableAbilities[] = {
    ABILITY_SOLID_ROCK,
    ABILITY_STURDY,
    ABILITY_SWIFT_SWIM,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TIRTOUGA)
static const u16 sCarracostaLearnableAbilities[] = {
    ABILITY_SOLID_ROCK,
    ABILITY_STURDY,
    ABILITY_SWIFT_SWIM,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ARCHEN)
static const u16 sArchenLearnableAbilities[] = {
    ABILITY_DEFEATIST,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ARCHEN)
static const u16 sArcheopsLearnableAbilities[] = {
    ABILITY_DEFEATIST,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TRUBBISH)
static const u16 sTrubbishLearnableAbilities[] = {
    ABILITY_STENCH,
    ABILITY_STICKY_HOLD,
    ABILITY_AFTERMATH,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TRUBBISH)
static const u16 sGarbodorLearnableAbilities[] = {
    ABILITY_STENCH,
    ABILITY_STICKY_HOLD,
    ABILITY_AFTERMATH,
    ABILITY_WEAK_ARMOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ZORUA)
static const u16 sZoruaLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ZORUA)
static const u16 sZoroarkLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ZORUA) && (P_HISUIAN_FORMS)
static const u16 sZoruaHisuiLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ZORUA) && (P_HISUIAN_FORMS)
static const u16 sZoroarkHisuiLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MINCCINO)
static const u16 sMinccinoLearnableAbilities[] = {
    ABILITY_CUTE_CHARM,
    ABILITY_TECHNICIAN,
    ABILITY_SKILL_LINK,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MINCCINO)
static const u16 sCinccinoLearnableAbilities[] = {
    ABILITY_CUTE_CHARM,
    ABILITY_TECHNICIAN,
    ABILITY_SKILL_LINK,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GOTHITA)
static const u16 sGothitaLearnableAbilities[] = {
    ABILITY_FRISK,
    ABILITY_COMPETITIVE,
    ABILITY_SHADOW_TAG,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GOTHITA)
static const u16 sGothoritaLearnableAbilities[] = {
    ABILITY_FRISK,
    ABILITY_COMPETITIVE,
    ABILITY_SHADOW_TAG,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GOTHITA)
static const u16 sGothitelleLearnableAbilities[] = {
    ABILITY_FRISK,
    ABILITY_COMPETITIVE,
    ABILITY_SHADOW_TAG,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SOLOSIS)
static const u16 sSolosisLearnableAbilities[] = {
    ABILITY_OVERCOAT,
    ABILITY_MAGIC_GUARD,
    ABILITY_REGENERATOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SOLOSIS)
static const u16 sDuosionLearnableAbilities[] = {
    ABILITY_OVERCOAT,
    ABILITY_MAGIC_GUARD,
    ABILITY_REGENERATOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SOLOSIS)
static const u16 sReuniclusLearnableAbilities[] = {
    ABILITY_OVERCOAT,
    ABILITY_MAGIC_GUARD,
    ABILITY_REGENERATOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DUCKLETT)
static const u16 sDucklettLearnableAbilities[] = {
    ABILITY_KEEN_EYE,
    ABILITY_BIG_PECKS,
    ABILITY_HYDRATION,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DUCKLETT)
static const u16 sSwannaLearnableAbilities[] = {
    ABILITY_KEEN_EYE,
    ABILITY_BIG_PECKS,
    ABILITY_HYDRATION,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_VANILLITE)
static const u16 sVanilliteLearnableAbilities[] = {
    ABILITY_ICE_BODY,
    ABILITY_SNOW_CLOAK,
    ABILITY_WEAK_ARMOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_VANILLITE)
static const u16 sVanillishLearnableAbilities[] = {
    ABILITY_ICE_BODY,
    ABILITY_SNOW_CLOAK,
    ABILITY_WEAK_ARMOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_VANILLITE)
static const u16 sVanilluxeLearnableAbilities[] = {
    ABILITY_ICE_BODY,
    ABILITY_SNOW_CLOAK,
    ABILITY_WEAK_ARMOR,
    ABILITY_SNOW_WARNING,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DEERLING)
static const u16 sDeerlingSpringLearnableAbilities[] = {
    ABILITY_CHLOROPHYLL,
    ABILITY_SAP_SIPPER,
    ABILITY_SERENE_GRACE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DEERLING)
static const u16 sDeerlingSummerLearnableAbilities[] = {
    ABILITY_CHLOROPHYLL,
    ABILITY_SAP_SIPPER,
    ABILITY_SERENE_GRACE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DEERLING)
static const u16 sDeerlingAutumnLearnableAbilities[] = {
    ABILITY_CHLOROPHYLL,
    ABILITY_SAP_SIPPER,
    ABILITY_SERENE_GRACE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DEERLING)
static const u16 sDeerlingWinterLearnableAbilities[] = {
    ABILITY_CHLOROPHYLL,
    ABILITY_SAP_SIPPER,
    ABILITY_SERENE_GRACE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DEERLING)
static const u16 sSawsbuckSpringLearnableAbilities[] = {
    ABILITY_CHLOROPHYLL,
    ABILITY_SAP_SIPPER,
    ABILITY_SERENE_GRACE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DEERLING)
static const u16 sSawsbuckSummerLearnableAbilities[] = {
    ABILITY_CHLOROPHYLL,
    ABILITY_SAP_SIPPER,
    ABILITY_SERENE_GRACE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DEERLING)
static const u16 sSawsbuckAutumnLearnableAbilities[] = {
    ABILITY_CHLOROPHYLL,
    ABILITY_SAP_SIPPER,
    ABILITY_SERENE_GRACE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DEERLING)
static const u16 sSawsbuckWinterLearnableAbilities[] = {
    ABILITY_CHLOROPHYLL,
    ABILITY_SAP_SIPPER,
    ABILITY_SERENE_GRACE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_EMOLGA)
static const u16 sEmolgaLearnableAbilities[] = {
    ABILITY_STATIC,
    ABILITY_MOTOR_DRIVE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_KARRABLAST)
static const u16 sKarrablastLearnableAbilities[] = {
    ABILITY_SWARM,
    ABILITY_SHED_SKIN,
    ABILITY_NO_GUARD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_KARRABLAST)
static const u16 sEscavalierLearnableAbilities[] = {
    ABILITY_SWARM,
    ABILITY_SHED_SKIN,
    ABILITY_NO_GUARD,
    ABILITY_SHELL_ARMOR,
    ABILITY_OVERCOAT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FOONGUS)
static const u16 sFoongusLearnableAbilities[] = {
    ABILITY_EFFECT_SPORE,
    ABILITY_REGENERATOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FOONGUS)
static const u16 sAmoongussLearnableAbilities[] = {
    ABILITY_EFFECT_SPORE,
    ABILITY_REGENERATOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FRILLISH)
static const u16 sFrillishLearnableAbilities[] = {
    ABILITY_WATER_ABSORB,
    ABILITY_CURSED_BODY,
    ABILITY_DAMP,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FRILLISH)
static const u16 sJellicentLearnableAbilities[] = {
    ABILITY_WATER_ABSORB,
    ABILITY_CURSED_BODY,
    ABILITY_DAMP,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ALOMOMOLA)
static const u16 sAlomomolaLearnableAbilities[] = {
    ABILITY_HEALER,
    ABILITY_HYDRATION,
    ABILITY_REGENERATOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_JOLTIK)
static const u16 sJoltikLearnableAbilities[] = {
    ABILITY_COMPOUND_EYES,
    ABILITY_UNNERVE,
    ABILITY_SWARM,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_JOLTIK)
static const u16 sGalvantulaLearnableAbilities[] = {
    ABILITY_COMPOUND_EYES,
    ABILITY_UNNERVE,
    ABILITY_SWARM,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FERROSEED)
static const u16 sFerroseedLearnableAbilities[] = {
    ABILITY_IRON_BARBS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FERROSEED)
static const u16 sFerrothornLearnableAbilities[] = {
    ABILITY_IRON_BARBS,
    ABILITY_ANTICIPATION,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_KLINK)
static const u16 sKlinkLearnableAbilities[] = {
    ABILITY_PLUS,
    ABILITY_MINUS,
    ABILITY_CLEAR_BODY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_KLINK)
static const u16 sKlangLearnableAbilities[] = {
    ABILITY_PLUS,
    ABILITY_MINUS,
    ABILITY_CLEAR_BODY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_KLINK)
static const u16 sKlinklangLearnableAbilities[] = {
    ABILITY_PLUS,
    ABILITY_MINUS,
    ABILITY_CLEAR_BODY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TYNAMO)
static const u16 sTynamoLearnableAbilities[] = {
    ABILITY_LEVITATE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TYNAMO)
static const u16 sEelektrikLearnableAbilities[] = {
    ABILITY_LEVITATE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TYNAMO)
static const u16 sEelektrossLearnableAbilities[] = {
    ABILITY_LEVITATE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ELGYEM)
static const u16 sElgyemLearnableAbilities[] = {
    ABILITY_TELEPATHY,
    ABILITY_SYNCHRONIZE,
    ABILITY_ANALYTIC,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ELGYEM)
static const u16 sBeheeyemLearnableAbilities[] = {
    ABILITY_TELEPATHY,
    ABILITY_SYNCHRONIZE,
    ABILITY_ANALYTIC,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_LITWICK)
static const u16 sLitwickLearnableAbilities[] = {
    ABILITY_FLASH_FIRE,
    ABILITY_FLAME_BODY,
    ABILITY_INFILTRATOR,
    ABILITY_SHADOW_TAG,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_LITWICK)
static const u16 sLampentLearnableAbilities[] = {
    ABILITY_FLASH_FIRE,
    ABILITY_FLAME_BODY,
    ABILITY_INFILTRATOR,
    ABILITY_SHADOW_TAG,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_LITWICK)
static const u16 sChandelureLearnableAbilities[] = {
    ABILITY_FLASH_FIRE,
    ABILITY_FLAME_BODY,
    ABILITY_INFILTRATOR,
    ABILITY_SHADOW_TAG,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_AXEW)
static const u16 sAxewLearnableAbilities[] = {
    ABILITY_RIVALRY,
    ABILITY_MOLD_BREAKER,
    ABILITY_UNNERVE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_AXEW)
static const u16 sFraxureLearnableAbilities[] = {
    ABILITY_RIVALRY,
    ABILITY_MOLD_BREAKER,
    ABILITY_UNNERVE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_AXEW)
static const u16 sHaxorusLearnableAbilities[] = {
    ABILITY_RIVALRY,
    ABILITY_MOLD_BREAKER,
    ABILITY_UNNERVE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CUBCHOO)
static const u16 sCubchooLearnableAbilities[] = {
    ABILITY_SNOW_CLOAK,
    ABILITY_SLUSH_RUSH,
    ABILITY_RATTLED,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CUBCHOO)
static const u16 sBearticLearnableAbilities[] = {
    ABILITY_SNOW_CLOAK,
    ABILITY_SLUSH_RUSH,
    ABILITY_RATTLED,
    ABILITY_SWIFT_SWIM,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CRYOGONAL)
static const u16 sCryogonalLearnableAbilities[] = {
    ABILITY_LEVITATE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SHELMET)
static const u16 sShelmetLearnableAbilities[] = {
    ABILITY_HYDRATION,
    ABILITY_SHELL_ARMOR,
    ABILITY_OVERCOAT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SHELMET)
static const u16 sAccelgorLearnableAbilities[] = {
    ABILITY_HYDRATION,
    ABILITY_SHELL_ARMOR,
    ABILITY_OVERCOAT,
    ABILITY_STICKY_HOLD,
    ABILITY_UNBURDEN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_STUNFISK)
static const u16 sStunfiskLearnableAbilities[] = {
    ABILITY_STATIC,
    ABILITY_LIMBER,
    ABILITY_SAND_VEIL,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_STUNFISK) && (P_GALARIAN_FORMS)
static const u16 sStunfiskGalarLearnableAbilities[] = {
    ABILITY_MIMICRY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MIENFOO)
static const u16 sMienfooLearnableAbilities[] = {
    ABILITY_INNER_FOCUS,
    ABILITY_REGENERATOR,
    ABILITY_RECKLESS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MIENFOO)
static const u16 sMienshaoLearnableAbilities[] = {
    ABILITY_INNER_FOCUS,
    ABILITY_REGENERATOR,
    ABILITY_RECKLESS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DRUDDIGON)
static const u16 sDruddigonLearnableAbilities[] = {
    ABILITY_ROUGH_SKIN,
    ABILITY_SHEER_FORCE,
    ABILITY_MOLD_BREAKER,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GOLETT)
static const u16 sGolettLearnableAbilities[] = {
    ABILITY_IRON_FIST,
    ABILITY_KLUTZ,
    ABILITY_NO_GUARD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GOLETT)
static const u16 sGolurkLearnableAbilities[] = {
    ABILITY_IRON_FIST,
    ABILITY_KLUTZ,
    ABILITY_NO_GUARD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PAWNIARD)
static const u16 sPawniardLearnableAbilities[] = {
    ABILITY_DEFIANT,
    ABILITY_INNER_FOCUS,
    ABILITY_PRESSURE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PAWNIARD)
static const u16 sBisharpLearnableAbilities[] = {
    ABILITY_DEFIANT,
    ABILITY_INNER_FOCUS,
    ABILITY_PRESSURE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PAWNIARD) && (P_GEN_9_CROSS_EVOS)
static const u16 sKingambitLearnableAbilities[] = {
    ABILITY_DEFIANT,
    ABILITY_INNER_FOCUS,
    ABILITY_PRESSURE,
    ABILITY_SUPREME_OVERLORD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_BOUFFALANT)
static const u16 sBouffalantLearnableAbilities[] = {
    ABILITY_RECKLESS,
    ABILITY_SAP_SIPPER,
    ABILITY_SOUNDPROOF,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_RUFFLET)
static const u16 sRuffletLearnableAbilities[] = {
    ABILITY_KEEN_EYE,
    ABILITY_SHEER_FORCE,
    ABILITY_HUSTLE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_RUFFLET)
static const u16 sBraviaryLearnableAbilities[] = {
    ABILITY_KEEN_EYE,
    ABILITY_SHEER_FORCE,
    ABILITY_HUSTLE,
    ABILITY_DEFIANT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_RUFFLET) && (P_HISUIAN_FORMS)
static const u16 sBraviaryHisuiLearnableAbilities[] = {
    ABILITY_KEEN_EYE,
    ABILITY_SHEER_FORCE,
    ABILITY_HUSTLE,
    ABILITY_TINTED_LENS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_VULLABY)
static const u16 sVullabyLearnableAbilities[] = {
    ABILITY_BIG_PECKS,
    ABILITY_OVERCOAT,
    ABILITY_WEAK_ARMOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_VULLABY)
static const u16 sMandibuzzLearnableAbilities[] = {
    ABILITY_BIG_PECKS,
    ABILITY_OVERCOAT,
    ABILITY_WEAK_ARMOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_HEATMOR)
static const u16 sHeatmorLearnableAbilities[] = {
    ABILITY_GLUTTONY,
    ABILITY_FLASH_FIRE,
    ABILITY_WHITE_SMOKE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DURANT)
static const u16 sDurantLearnableAbilities[] = {
    ABILITY_SWARM,
    ABILITY_HUSTLE,
    ABILITY_TRUANT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DEINO)
static const u16 sDeinoLearnableAbilities[] = {
    ABILITY_HUSTLE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DEINO)
static const u16 sZweilousLearnableAbilities[] = {
    ABILITY_HUSTLE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DEINO)
static const u16 sHydreigonLearnableAbilities[] = {
    ABILITY_HUSTLE,
    ABILITY_LEVITATE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_LARVESTA)
static const u16 sLarvestaLearnableAbilities[] = {
    ABILITY_FLAME_BODY,
    ABILITY_SWARM,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_LARVESTA)
static const u16 sVolcaronaLearnableAbilities[] = {
    ABILITY_FLAME_BODY,
    ABILITY_SWARM,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_COBALION)
static const u16 sCobalionLearnableAbilities[] = {
    ABILITY_JUSTIFIED,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TERRAKION)
static const u16 sTerrakionLearnableAbilities[] = {
    ABILITY_JUSTIFIED,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_VIRIZION)
static const u16 sVirizionLearnableAbilities[] = {
    ABILITY_JUSTIFIED,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TORNADUS)
static const u16 sTornadusIncarnateLearnableAbilities[] = {
    ABILITY_PRANKSTER,
    ABILITY_DEFIANT,
    ABILITY_REGENERATOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_THUNDURUS)
static const u16 sThundurusIncarnateLearnableAbilities[] = {
    ABILITY_PRANKSTER,
    ABILITY_DEFIANT,
    ABILITY_VOLT_ABSORB,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_RESHIRAM)
static const u16 sReshiramLearnableAbilities[] = {
    ABILITY_TURBOBLAZE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ZEKROM)
static const u16 sZekromLearnableAbilities[] = {
    ABILITY_TERAVOLT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_LANDORUS)
static const u16 sLandorusIncarnateLearnableAbilities[] = {
    ABILITY_SAND_FORCE,
    ABILITY_SHEER_FORCE,
    ABILITY_INTIMIDATE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_KYUREM)
static const u16 sKyuremLearnableAbilities[] = {
    ABILITY_PRESSURE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_KYUREM) && (P_FUSION_FORMS)
static const u16 sKyuremWhiteLearnableAbilities[] = {
    ABILITY_TURBOBLAZE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_KYUREM) && (P_FUSION_FORMS)
static const u16 sKyuremBlackLearnableAbilities[] = {
    ABILITY_TERAVOLT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_KELDEO)
static const u16 sKeldeoOrdinaryLearnableAbilities[] = {
    ABILITY_JUSTIFIED,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MELOETTA)
static const u16 sMeloettaAriaLearnableAbilities[] = {
    ABILITY_SERENE_GRACE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GENESECT)
static const u16 sGenesectLearnableAbilities[] = {
    ABILITY_DOWNLOAD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CHESPIN)
static const u16 sChespinLearnableAbilities[] = {
    ABILITY_OVERGROW,
    ABILITY_BULLETPROOF,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CHESPIN)
static const u16 sQuilladinLearnableAbilities[] = {
    ABILITY_OVERGROW,
    ABILITY_BULLETPROOF,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CHESPIN)
static const u16 sChesnaughtLearnableAbilities[] = {
    ABILITY_OVERGROW,
    ABILITY_BULLETPROOF,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FENNEKIN)
static const u16 sFennekinLearnableAbilities[] = {
    ABILITY_BLAZE,
    ABILITY_MAGICIAN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FENNEKIN)
static const u16 sBraixenLearnableAbilities[] = {
    ABILITY_BLAZE,
    ABILITY_MAGICIAN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FENNEKIN)
static const u16 sDelphoxLearnableAbilities[] = {
    ABILITY_BLAZE,
    ABILITY_MAGICIAN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FROAKIE)
static const u16 sFroakieLearnableAbilities[] = {
    ABILITY_TORRENT,
    ABILITY_PROTEAN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FROAKIE)
static const u16 sFrogadierLearnableAbilities[] = {
    ABILITY_TORRENT,
    ABILITY_PROTEAN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FROAKIE)
static const u16 sGreninjaLearnableAbilities[] = {
    ABILITY_TORRENT,
    ABILITY_PROTEAN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FROAKIE)
static const u16 sGreninjaBattleBondLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_BUNNELBY)
static const u16 sBunnelbyLearnableAbilities[] = {
    ABILITY_PICKUP,
    ABILITY_CHEEK_POUCH,
    ABILITY_HUGE_POWER,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_BUNNELBY)
static const u16 sDiggersbyLearnableAbilities[] = {
    ABILITY_PICKUP,
    ABILITY_CHEEK_POUCH,
    ABILITY_HUGE_POWER,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FLETCHLING)
static const u16 sFletchlingLearnableAbilities[] = {
    ABILITY_BIG_PECKS,
    ABILITY_GALE_WINGS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FLETCHLING)
static const u16 sFletchinderLearnableAbilities[] = {
    ABILITY_BIG_PECKS,
    ABILITY_GALE_WINGS,
    ABILITY_FLAME_BODY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FLETCHLING)
static const u16 sTalonflameLearnableAbilities[] = {
    ABILITY_BIG_PECKS,
    ABILITY_GALE_WINGS,
    ABILITY_FLAME_BODY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SCATTERBUG)
static const u16 sScatterbugIcySnowLearnableAbilities[] = {
    ABILITY_SHIELD_DUST,
    ABILITY_COMPOUND_EYES,
    ABILITY_FRIEND_GUARD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SCATTERBUG)
static const u16 sSpewpaIcySnowLearnableAbilities[] = {
    ABILITY_SHIELD_DUST,
    ABILITY_COMPOUND_EYES,
    ABILITY_FRIEND_GUARD,
    ABILITY_SHED_SKIN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SCATTERBUG)
static const u16 sVivillonIcySnowLearnableAbilities[] = {
    ABILITY_SHIELD_DUST,
    ABILITY_COMPOUND_EYES,
    ABILITY_FRIEND_GUARD,
    ABILITY_SHED_SKIN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SCATTERBUG)
static const u16 sVivillonPolarLearnableAbilities[] = {
    ABILITY_SHIELD_DUST,
    ABILITY_COMPOUND_EYES,
    ABILITY_FRIEND_GUARD,
    ABILITY_SHED_SKIN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SCATTERBUG)
static const u16 sVivillonTundraLearnableAbilities[] = {
    ABILITY_SHIELD_DUST,
    ABILITY_COMPOUND_EYES,
    ABILITY_FRIEND_GUARD,
    ABILITY_SHED_SKIN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SCATTERBUG)
static const u16 sVivillonContinentalLearnableAbilities[] = {
    ABILITY_SHIELD_DUST,
    ABILITY_COMPOUND_EYES,
    ABILITY_FRIEND_GUARD,
    ABILITY_SHED_SKIN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SCATTERBUG)
static const u16 sVivillonGardenLearnableAbilities[] = {
    ABILITY_SHIELD_DUST,
    ABILITY_COMPOUND_EYES,
    ABILITY_FRIEND_GUARD,
    ABILITY_SHED_SKIN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SCATTERBUG)
static const u16 sVivillonElegantLearnableAbilities[] = {
    ABILITY_SHIELD_DUST,
    ABILITY_COMPOUND_EYES,
    ABILITY_FRIEND_GUARD,
    ABILITY_SHED_SKIN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SCATTERBUG)
static const u16 sVivillonMeadowLearnableAbilities[] = {
    ABILITY_SHIELD_DUST,
    ABILITY_COMPOUND_EYES,
    ABILITY_FRIEND_GUARD,
    ABILITY_SHED_SKIN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SCATTERBUG)
static const u16 sVivillonModernLearnableAbilities[] = {
    ABILITY_SHIELD_DUST,
    ABILITY_COMPOUND_EYES,
    ABILITY_FRIEND_GUARD,
    ABILITY_SHED_SKIN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SCATTERBUG)
static const u16 sVivillonMarineLearnableAbilities[] = {
    ABILITY_SHIELD_DUST,
    ABILITY_COMPOUND_EYES,
    ABILITY_FRIEND_GUARD,
    ABILITY_SHED_SKIN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SCATTERBUG)
static const u16 sVivillonArchipelagoLearnableAbilities[] = {
    ABILITY_SHIELD_DUST,
    ABILITY_COMPOUND_EYES,
    ABILITY_FRIEND_GUARD,
    ABILITY_SHED_SKIN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SCATTERBUG)
static const u16 sVivillonHighPlainsLearnableAbilities[] = {
    ABILITY_SHIELD_DUST,
    ABILITY_COMPOUND_EYES,
    ABILITY_FRIEND_GUARD,
    ABILITY_SHED_SKIN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SCATTERBUG)
static const u16 sVivillonSandstormLearnableAbilities[] = {
    ABILITY_SHIELD_DUST,
    ABILITY_COMPOUND_EYES,
    ABILITY_FRIEND_GUARD,
    ABILITY_SHED_SKIN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SCATTERBUG)
static const u16 sVivillonRiverLearnableAbilities[] = {
    ABILITY_SHIELD_DUST,
    ABILITY_COMPOUND_EYES,
    ABILITY_FRIEND_GUARD,
    ABILITY_SHED_SKIN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SCATTERBUG)
static const u16 sVivillonMonsoonLearnableAbilities[] = {
    ABILITY_SHIELD_DUST,
    ABILITY_COMPOUND_EYES,
    ABILITY_FRIEND_GUARD,
    ABILITY_SHED_SKIN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SCATTERBUG)
static const u16 sVivillonSavannaLearnableAbilities[] = {
    ABILITY_SHIELD_DUST,
    ABILITY_COMPOUND_EYES,
    ABILITY_FRIEND_GUARD,
    ABILITY_SHED_SKIN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SCATTERBUG)
static const u16 sVivillonSunLearnableAbilities[] = {
    ABILITY_SHIELD_DUST,
    ABILITY_COMPOUND_EYES,
    ABILITY_FRIEND_GUARD,
    ABILITY_SHED_SKIN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SCATTERBUG)
static const u16 sVivillonOceanLearnableAbilities[] = {
    ABILITY_SHIELD_DUST,
    ABILITY_COMPOUND_EYES,
    ABILITY_FRIEND_GUARD,
    ABILITY_SHED_SKIN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SCATTERBUG)
static const u16 sVivillonJungleLearnableAbilities[] = {
    ABILITY_SHIELD_DUST,
    ABILITY_COMPOUND_EYES,
    ABILITY_FRIEND_GUARD,
    ABILITY_SHED_SKIN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SCATTERBUG)
static const u16 sVivillonFancyLearnableAbilities[] = {
    ABILITY_SHIELD_DUST,
    ABILITY_COMPOUND_EYES,
    ABILITY_FRIEND_GUARD,
    ABILITY_SHED_SKIN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SCATTERBUG)
static const u16 sVivillonPokeballLearnableAbilities[] = {
    ABILITY_SHIELD_DUST,
    ABILITY_COMPOUND_EYES,
    ABILITY_FRIEND_GUARD,
    ABILITY_SHED_SKIN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_LITLEO)
static const u16 sLitleoLearnableAbilities[] = {
    ABILITY_RIVALRY,
    ABILITY_UNNERVE,
    ABILITY_MOXIE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_LITLEO)
static const u16 sPyroarLearnableAbilities[] = {
    ABILITY_RIVALRY,
    ABILITY_UNNERVE,
    ABILITY_MOXIE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FLABEBE)
static const u16 sFlabebeRedLearnableAbilities[] = {
    ABILITY_FLOWER_VEIL,
    ABILITY_SYMBIOSIS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FLABEBE)
static const u16 sFlabebeYellowLearnableAbilities[] = {
    ABILITY_FLOWER_VEIL,
    ABILITY_SYMBIOSIS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FLABEBE)
static const u16 sFlabebeOrangeLearnableAbilities[] = {
    ABILITY_FLOWER_VEIL,
    ABILITY_SYMBIOSIS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FLABEBE)
static const u16 sFlabebeBlueLearnableAbilities[] = {
    ABILITY_FLOWER_VEIL,
    ABILITY_SYMBIOSIS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FLABEBE)
static const u16 sFlabebeWhiteLearnableAbilities[] = {
    ABILITY_FLOWER_VEIL,
    ABILITY_SYMBIOSIS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FLABEBE)
static const u16 sFloetteRedLearnableAbilities[] = {
    ABILITY_FLOWER_VEIL,
    ABILITY_SYMBIOSIS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FLABEBE)
static const u16 sFloetteYellowLearnableAbilities[] = {
    ABILITY_FLOWER_VEIL,
    ABILITY_SYMBIOSIS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FLABEBE)
static const u16 sFloetteOrangeLearnableAbilities[] = {
    ABILITY_FLOWER_VEIL,
    ABILITY_SYMBIOSIS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FLABEBE)
static const u16 sFloetteBlueLearnableAbilities[] = {
    ABILITY_FLOWER_VEIL,
    ABILITY_SYMBIOSIS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FLABEBE)
static const u16 sFloetteWhiteLearnableAbilities[] = {
    ABILITY_FLOWER_VEIL,
    ABILITY_SYMBIOSIS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FLABEBE)
static const u16 sFloetteEternalLearnableAbilities[] = {
    ABILITY_FLOWER_VEIL,
    ABILITY_SYMBIOSIS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FLABEBE)
static const u16 sFlorgesRedLearnableAbilities[] = {
    ABILITY_FLOWER_VEIL,
    ABILITY_SYMBIOSIS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FLABEBE)
static const u16 sFlorgesYellowLearnableAbilities[] = {
    ABILITY_FLOWER_VEIL,
    ABILITY_SYMBIOSIS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FLABEBE)
static const u16 sFlorgesOrangeLearnableAbilities[] = {
    ABILITY_FLOWER_VEIL,
    ABILITY_SYMBIOSIS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FLABEBE)
static const u16 sFlorgesBlueLearnableAbilities[] = {
    ABILITY_FLOWER_VEIL,
    ABILITY_SYMBIOSIS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FLABEBE)
static const u16 sFlorgesWhiteLearnableAbilities[] = {
    ABILITY_FLOWER_VEIL,
    ABILITY_SYMBIOSIS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SKIDDO)
static const u16 sSkiddoLearnableAbilities[] = {
    ABILITY_SAP_SIPPER,
    ABILITY_GRASS_PELT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SKIDDO)
static const u16 sGogoatLearnableAbilities[] = {
    ABILITY_SAP_SIPPER,
    ABILITY_GRASS_PELT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PANCHAM)
static const u16 sPanchamLearnableAbilities[] = {
    ABILITY_IRON_FIST,
    ABILITY_MOLD_BREAKER,
    ABILITY_SCRAPPY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PANCHAM)
static const u16 sPangoroLearnableAbilities[] = {
    ABILITY_IRON_FIST,
    ABILITY_MOLD_BREAKER,
    ABILITY_SCRAPPY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FURFROU)
static const u16 sFurfrouNaturalLearnableAbilities[] = {
    ABILITY_FUR_COAT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ESPURR)
static const u16 sEspurrLearnableAbilities[] = {
    ABILITY_KEEN_EYE,
    ABILITY_INFILTRATOR,
    ABILITY_OWN_TEMPO,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ESPURR)
static const u16 sMeowsticMLearnableAbilities[] = {
    ABILITY_KEEN_EYE,
    ABILITY_INFILTRATOR,
    ABILITY_OWN_TEMPO,
    ABILITY_PRANKSTER,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ESPURR)
static const u16 sMeowsticFLearnableAbilities[] = {
    ABILITY_KEEN_EYE,
    ABILITY_INFILTRATOR,
    ABILITY_OWN_TEMPO,
    ABILITY_COMPETITIVE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_HONEDGE)
static const u16 sHonedgeLearnableAbilities[] = {
    ABILITY_NO_GUARD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_HONEDGE)
static const u16 sDoubladeLearnableAbilities[] = {
    ABILITY_NO_GUARD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_HONEDGE)
static const u16 sAegislashShieldLearnableAbilities[] = {
    ABILITY_NO_GUARD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SPRITZEE)
static const u16 sSpritzeeLearnableAbilities[] = {
    ABILITY_HEALER,
    ABILITY_AROMA_VEIL,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SPRITZEE)
static const u16 sAromatisseLearnableAbilities[] = {
    ABILITY_HEALER,
    ABILITY_AROMA_VEIL,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SWIRLIX)
static const u16 sSwirlixLearnableAbilities[] = {
    ABILITY_SWEET_VEIL,
    ABILITY_UNBURDEN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SWIRLIX)
static const u16 sSlurpuffLearnableAbilities[] = {
    ABILITY_SWEET_VEIL,
    ABILITY_UNBURDEN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_INKAY)
static const u16 sInkayLearnableAbilities[] = {
    ABILITY_CONTRARY,
    ABILITY_SUCTION_CUPS,
    ABILITY_INFILTRATOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_INKAY)
static const u16 sMalamarLearnableAbilities[] = {
    ABILITY_CONTRARY,
    ABILITY_SUCTION_CUPS,
    ABILITY_INFILTRATOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_BINACLE)
static const u16 sBinacleLearnableAbilities[] = {
    ABILITY_TOUGH_CLAWS,
    ABILITY_SNIPER,
    ABILITY_PICKPOCKET,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_BINACLE)
static const u16 sBarbaracleLearnableAbilities[] = {
    ABILITY_TOUGH_CLAWS,
    ABILITY_SNIPER,
    ABILITY_PICKPOCKET,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SKRELP)
static const u16 sSkrelpLearnableAbilities[] = {
    ABILITY_POISON_POINT,
    ABILITY_POISON_TOUCH,
    ABILITY_ADAPTABILITY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SKRELP)
static const u16 sDragalgeLearnableAbilities[] = {
    ABILITY_POISON_POINT,
    ABILITY_POISON_TOUCH,
    ABILITY_ADAPTABILITY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CLAUNCHER)
static const u16 sClauncherLearnableAbilities[] = {
    ABILITY_MEGA_LAUNCHER,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CLAUNCHER)
static const u16 sClawitzerLearnableAbilities[] = {
    ABILITY_MEGA_LAUNCHER,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_HELIOPTILE)
static const u16 sHelioptileLearnableAbilities[] = {
    ABILITY_DRY_SKIN,
    ABILITY_SAND_VEIL,
    ABILITY_SOLAR_POWER,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_HELIOPTILE)
static const u16 sHelioliskLearnableAbilities[] = {
    ABILITY_DRY_SKIN,
    ABILITY_SAND_VEIL,
    ABILITY_SOLAR_POWER,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TYRUNT)
static const u16 sTyruntLearnableAbilities[] = {
    ABILITY_STRONG_JAW,
    ABILITY_STURDY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TYRUNT)
static const u16 sTyrantrumLearnableAbilities[] = {
    ABILITY_STRONG_JAW,
    ABILITY_STURDY,
    ABILITY_ROCK_HEAD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_AMAURA)
static const u16 sAmauraLearnableAbilities[] = {
    ABILITY_REFRIGERATE,
    ABILITY_SNOW_WARNING,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_AMAURA)
static const u16 sAurorusLearnableAbilities[] = {
    ABILITY_REFRIGERATE,
    ABILITY_SNOW_WARNING,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_HAWLUCHA)
static const u16 sHawluchaLearnableAbilities[] = {
    ABILITY_LIMBER,
    ABILITY_UNBURDEN,
    ABILITY_MOLD_BREAKER,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DEDENNE)
static const u16 sDedenneLearnableAbilities[] = {
    ABILITY_CHEEK_POUCH,
    ABILITY_PICKUP,
    ABILITY_PLUS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CARBINK)
static const u16 sCarbinkLearnableAbilities[] = {
    ABILITY_CLEAR_BODY,
    ABILITY_STURDY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GOOMY)
static const u16 sGoomyLearnableAbilities[] = {
    ABILITY_SAP_SIPPER,
    ABILITY_HYDRATION,
    ABILITY_GOOEY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GOOMY)
static const u16 sSliggooLearnableAbilities[] = {
    ABILITY_SAP_SIPPER,
    ABILITY_HYDRATION,
    ABILITY_GOOEY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GOOMY)
static const u16 sGoodraLearnableAbilities[] = {
    ABILITY_SAP_SIPPER,
    ABILITY_HYDRATION,
    ABILITY_GOOEY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GOOMY) && (P_HISUIAN_FORMS)
static const u16 sSliggooHisuiLearnableAbilities[] = {
    ABILITY_SAP_SIPPER,
    ABILITY_HYDRATION,
    ABILITY_GOOEY,
    ABILITY_SHELL_ARMOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GOOMY) && (P_HISUIAN_FORMS)
static const u16 sGoodraHisuiLearnableAbilities[] = {
    ABILITY_SAP_SIPPER,
    ABILITY_HYDRATION,
    ABILITY_GOOEY,
    ABILITY_SHELL_ARMOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_KLEFKI)
static const u16 sKlefkiLearnableAbilities[] = {
    ABILITY_PRANKSTER,
    ABILITY_MAGICIAN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PHANTUMP)
static const u16 sPhantumpLearnableAbilities[] = {
    ABILITY_NATURAL_CURE,
    ABILITY_FRISK,
    ABILITY_HARVEST,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PHANTUMP)
static const u16 sTrevenantLearnableAbilities[] = {
    ABILITY_NATURAL_CURE,
    ABILITY_FRISK,
    ABILITY_HARVEST,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PUMPKABOO)
static const u16 sPumpkabooAverageLearnableAbilities[] = {
    ABILITY_PICKUP,
    ABILITY_FRISK,
    ABILITY_INSOMNIA,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PUMPKABOO)
static const u16 sPumpkabooSmallLearnableAbilities[] = {
    ABILITY_PICKUP,
    ABILITY_FRISK,
    ABILITY_INSOMNIA,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PUMPKABOO)
static const u16 sPumpkabooLargeLearnableAbilities[] = {
    ABILITY_PICKUP,
    ABILITY_FRISK,
    ABILITY_INSOMNIA,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PUMPKABOO)
static const u16 sPumpkabooSuperLearnableAbilities[] = {
    ABILITY_PICKUP,
    ABILITY_FRISK,
    ABILITY_INSOMNIA,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PUMPKABOO)
static const u16 sGourgeistAverageLearnableAbilities[] = {
    ABILITY_PICKUP,
    ABILITY_FRISK,
    ABILITY_INSOMNIA,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PUMPKABOO)
static const u16 sGourgeistSmallLearnableAbilities[] = {
    ABILITY_PICKUP,
    ABILITY_FRISK,
    ABILITY_INSOMNIA,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PUMPKABOO)
static const u16 sGourgeistLargeLearnableAbilities[] = {
    ABILITY_PICKUP,
    ABILITY_FRISK,
    ABILITY_INSOMNIA,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PUMPKABOO)
static const u16 sGourgeistSuperLearnableAbilities[] = {
    ABILITY_PICKUP,
    ABILITY_FRISK,
    ABILITY_INSOMNIA,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_BERGMITE)
static const u16 sBergmiteLearnableAbilities[] = {
    ABILITY_OWN_TEMPO,
    ABILITY_ICE_BODY,
    ABILITY_STURDY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_BERGMITE)
static const u16 sAvaluggLearnableAbilities[] = {
    ABILITY_OWN_TEMPO,
    ABILITY_ICE_BODY,
    ABILITY_STURDY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_BERGMITE) && (P_HISUIAN_FORMS)
static const u16 sAvaluggHisuiLearnableAbilities[] = {
    ABILITY_OWN_TEMPO,
    ABILITY_ICE_BODY,
    ABILITY_STURDY,
    ABILITY_STRONG_JAW,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_NOIBAT)
static const u16 sNoibatLearnableAbilities[] = {
    ABILITY_FRISK,
    ABILITY_INFILTRATOR,
    ABILITY_TELEPATHY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_NOIBAT)
static const u16 sNoivernLearnableAbilities[] = {
    ABILITY_FRISK,
    ABILITY_INFILTRATOR,
    ABILITY_TELEPATHY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_XERNEAS)
static const u16 sXerneasNeutralLearnableAbilities[] = {
    ABILITY_FAIRY_AURA,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_YVELTAL)
static const u16 sYveltalLearnableAbilities[] = {
    ABILITY_DARK_AURA,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ZYGARDE)
static const u16 sZygarde50LearnableAbilities[] = {
    ABILITY_AURA_BREAK,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DIANCIE)
static const u16 sDiancieLearnableAbilities[] = {
    ABILITY_CLEAR_BODY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_HOOPA)
static const u16 sHoopaConfinedLearnableAbilities[] = {
    ABILITY_MAGICIAN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_VOLCANION)
static const u16 sVolcanionLearnableAbilities[] = {
    ABILITY_WATER_ABSORB,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ROWLET)
static const u16 sRowletLearnableAbilities[] = {
    ABILITY_OVERGROW,
    ABILITY_LONG_REACH,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ROWLET)
static const u16 sDartrixLearnableAbilities[] = {
    ABILITY_OVERGROW,
    ABILITY_LONG_REACH,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ROWLET)
static const u16 sDecidueyeLearnableAbilities[] = {
    ABILITY_OVERGROW,
    ABILITY_LONG_REACH,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ROWLET) && (P_HISUIAN_FORMS)
static const u16 sDecidueyeHisuiLearnableAbilities[] = {
    ABILITY_OVERGROW,
    ABILITY_LONG_REACH,
    ABILITY_SCRAPPY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_LITTEN)
static const u16 sLittenLearnableAbilities[] = {
    ABILITY_BLAZE,
    ABILITY_INTIMIDATE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_LITTEN)
static const u16 sTorracatLearnableAbilities[] = {
    ABILITY_BLAZE,
    ABILITY_INTIMIDATE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_LITTEN)
static const u16 sIncineroarLearnableAbilities[] = {
    ABILITY_BLAZE,
    ABILITY_INTIMIDATE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_POPPLIO)
static const u16 sPopplioLearnableAbilities[] = {
    ABILITY_TORRENT,
    ABILITY_LIQUID_VOICE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_POPPLIO)
static const u16 sBrionneLearnableAbilities[] = {
    ABILITY_TORRENT,
    ABILITY_LIQUID_VOICE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_POPPLIO)
static const u16 sPrimarinaLearnableAbilities[] = {
    ABILITY_TORRENT,
    ABILITY_LIQUID_VOICE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PIKIPEK)
static const u16 sPikipekLearnableAbilities[] = {
    ABILITY_KEEN_EYE,
    ABILITY_SKILL_LINK,
    ABILITY_PICKUP,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PIKIPEK)
static const u16 sTrumbeakLearnableAbilities[] = {
    ABILITY_KEEN_EYE,
    ABILITY_SKILL_LINK,
    ABILITY_PICKUP,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PIKIPEK)
static const u16 sToucannonLearnableAbilities[] = {
    ABILITY_KEEN_EYE,
    ABILITY_SKILL_LINK,
    ABILITY_PICKUP,
    ABILITY_SHEER_FORCE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_YUNGOOS)
static const u16 sYungoosLearnableAbilities[] = {
    ABILITY_STAKEOUT,
    ABILITY_STRONG_JAW,
    ABILITY_ADAPTABILITY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_YUNGOOS)
static const u16 sGumshoosLearnableAbilities[] = {
    ABILITY_STAKEOUT,
    ABILITY_STRONG_JAW,
    ABILITY_ADAPTABILITY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_YUNGOOS)
static const u16 sGumshoosTotemLearnableAbilities[] = {
    ABILITY_ADAPTABILITY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GRUBBIN)
static const u16 sGrubbinLearnableAbilities[] = {
    ABILITY_SWARM,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GRUBBIN)
static const u16 sCharjabugLearnableAbilities[] = {
    ABILITY_SWARM,
    ABILITY_BATTERY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GRUBBIN)
static const u16 sVikavoltLearnableAbilities[] = {
    ABILITY_SWARM,
    ABILITY_BATTERY,
    ABILITY_LEVITATE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GRUBBIN)
static const u16 sVikavoltTotemLearnableAbilities[] = {
    ABILITY_SWARM,
    ABILITY_BATTERY,
    ABILITY_LEVITATE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CRABRAWLER)
static const u16 sCrabrawlerLearnableAbilities[] = {
    ABILITY_HYPER_CUTTER,
    ABILITY_IRON_FIST,
    ABILITY_ANGER_POINT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CRABRAWLER)
static const u16 sCrabominableLearnableAbilities[] = {
    ABILITY_HYPER_CUTTER,
    ABILITY_IRON_FIST,
    ABILITY_ANGER_POINT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ORICORIO)
static const u16 sOricorioBaileLearnableAbilities[] = {
    ABILITY_DANCER,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CUTIEFLY)
static const u16 sCutieflyLearnableAbilities[] = {
    ABILITY_HONEY_GATHER,
    ABILITY_SHIELD_DUST,
    ABILITY_SWEET_VEIL,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CUTIEFLY)
static const u16 sRibombeeLearnableAbilities[] = {
    ABILITY_HONEY_GATHER,
    ABILITY_SHIELD_DUST,
    ABILITY_SWEET_VEIL,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CUTIEFLY)
static const u16 sRibombeeTotemLearnableAbilities[] = {
    ABILITY_HONEY_GATHER,
    ABILITY_SHIELD_DUST,
    ABILITY_SWEET_VEIL,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ROCKRUFF)
static const u16 sRockruffLearnableAbilities[] = {
    ABILITY_KEEN_EYE,
    ABILITY_VITAL_SPIRIT,
    ABILITY_STEADFAST,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ROCKRUFF)
static const u16 sRockruffOwnTempoLearnableAbilities[] = {
    ABILITY_OWN_TEMPO,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ROCKRUFF)
static const u16 sLycanrocMiddayLearnableAbilities[] = {
    ABILITY_KEEN_EYE,
    ABILITY_VITAL_SPIRIT,
    ABILITY_STEADFAST,
    ABILITY_SAND_RUSH,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ROCKRUFF)
static const u16 sLycanrocMidnightLearnableAbilities[] = {
    ABILITY_KEEN_EYE,
    ABILITY_VITAL_SPIRIT,
    ABILITY_STEADFAST,
    ABILITY_NO_GUARD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ROCKRUFF)
static const u16 sLycanrocDuskLearnableAbilities[] = {
    ABILITY_OWN_TEMPO,
    ABILITY_TOUGH_CLAWS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_WISHIWASHI)
static const u16 sWishiwashiSoloLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MAREANIE)
static const u16 sMareanieLearnableAbilities[] = {
    ABILITY_MERCILESS,
    ABILITY_LIMBER,
    ABILITY_REGENERATOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MAREANIE)
static const u16 sToxapexLearnableAbilities[] = {
    ABILITY_MERCILESS,
    ABILITY_LIMBER,
    ABILITY_REGENERATOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MUDBRAY)
static const u16 sMudbrayLearnableAbilities[] = {
    ABILITY_OWN_TEMPO,
    ABILITY_STAMINA,
    ABILITY_INNER_FOCUS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MUDBRAY)
static const u16 sMudsdaleLearnableAbilities[] = {
    ABILITY_OWN_TEMPO,
    ABILITY_STAMINA,
    ABILITY_INNER_FOCUS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DEWPIDER)
static const u16 sDewpiderLearnableAbilities[] = {
    ABILITY_WATER_BUBBLE,
    ABILITY_WATER_ABSORB,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DEWPIDER)
static const u16 sAraquanidLearnableAbilities[] = {
    ABILITY_WATER_BUBBLE,
    ABILITY_WATER_ABSORB,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DEWPIDER)
static const u16 sAraquanidTotemLearnableAbilities[] = {
    ABILITY_WATER_BUBBLE,
    ABILITY_WATER_ABSORB,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FOMANTIS)
static const u16 sFomantisLearnableAbilities[] = {
    ABILITY_LEAF_GUARD,
    ABILITY_CONTRARY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FOMANTIS)
static const u16 sLurantisLearnableAbilities[] = {
    ABILITY_LEAF_GUARD,
    ABILITY_CONTRARY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FOMANTIS)
static const u16 sLurantisTotemLearnableAbilities[] = {
    ABILITY_LEAF_GUARD,
    ABILITY_CONTRARY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MORELULL)
static const u16 sMorelullLearnableAbilities[] = {
    ABILITY_ILLUMINATE,
    ABILITY_EFFECT_SPORE,
    ABILITY_RAIN_DISH,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MORELULL)
static const u16 sShiinoticLearnableAbilities[] = {
    ABILITY_ILLUMINATE,
    ABILITY_EFFECT_SPORE,
    ABILITY_RAIN_DISH,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SALANDIT)
static const u16 sSalanditLearnableAbilities[] = {
    ABILITY_CORROSION,
    ABILITY_OBLIVIOUS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SALANDIT)
static const u16 sSalazzleLearnableAbilities[] = {
    ABILITY_CORROSION,
    ABILITY_OBLIVIOUS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SALANDIT)
static const u16 sSalazzleTotemLearnableAbilities[] = {
    ABILITY_CORROSION,
    ABILITY_OBLIVIOUS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_STUFFUL)
static const u16 sStuffulLearnableAbilities[] = {
    ABILITY_FLUFFY,
    ABILITY_KLUTZ,
    ABILITY_CUTE_CHARM,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_STUFFUL)
static const u16 sBewearLearnableAbilities[] = {
    ABILITY_FLUFFY,
    ABILITY_KLUTZ,
    ABILITY_CUTE_CHARM,
    ABILITY_UNNERVE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_BOUNSWEET)
static const u16 sBounsweetLearnableAbilities[] = {
    ABILITY_LEAF_GUARD,
    ABILITY_OBLIVIOUS,
    ABILITY_SWEET_VEIL,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_BOUNSWEET)
static const u16 sSteeneeLearnableAbilities[] = {
    ABILITY_LEAF_GUARD,
    ABILITY_OBLIVIOUS,
    ABILITY_SWEET_VEIL,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_BOUNSWEET)
static const u16 sTsareenaLearnableAbilities[] = {
    ABILITY_LEAF_GUARD,
    ABILITY_OBLIVIOUS,
    ABILITY_SWEET_VEIL,
    ABILITY_QUEENLY_MAJESTY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_COMFEY)
static const u16 sComfeyLearnableAbilities[] = {
    ABILITY_FLOWER_VEIL,
    ABILITY_TRIAGE,
    ABILITY_NATURAL_CURE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ORANGURU)
static const u16 sOranguruLearnableAbilities[] = {
    ABILITY_INNER_FOCUS,
    ABILITY_TELEPATHY,
    ABILITY_SYMBIOSIS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PASSIMIAN)
static const u16 sPassimianLearnableAbilities[] = {
    ABILITY_RECEIVER,
    ABILITY_DEFIANT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_WIMPOD)
static const u16 sWimpodLearnableAbilities[] = {
    ABILITY_WIMP_OUT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_WIMPOD)
static const u16 sGolisopodLearnableAbilities[] = {
    ABILITY_WIMP_OUT,
    ABILITY_EMERGENCY_EXIT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SANDYGAST)
static const u16 sSandygastLearnableAbilities[] = {
    ABILITY_WATER_COMPACTION,
    ABILITY_SAND_VEIL,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SANDYGAST)
static const u16 sPalossandLearnableAbilities[] = {
    ABILITY_WATER_COMPACTION,
    ABILITY_SAND_VEIL,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PYUKUMUKU)
static const u16 sPyukumukuLearnableAbilities[] = {
    ABILITY_INNARDS_OUT,
    ABILITY_UNAWARE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TYPE_NULL)
static const u16 sTypeNullLearnableAbilities[] = {
    ABILITY_BATTLE_ARMOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TYPE_NULL)
static const u16 sSilvallyNormalLearnableAbilities[] = {
    ABILITY_BATTLE_ARMOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MINIOR)
static const u16 sMiniorMeteorRedLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_KOMALA)
static const u16 sKomalaLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TURTONATOR)
static const u16 sTurtonatorLearnableAbilities[] = {
    ABILITY_SHELL_ARMOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TOGEDEMARU)
static const u16 sTogedemaruLearnableAbilities[] = {
    ABILITY_IRON_BARBS,
    ABILITY_LIGHTNING_ROD,
    ABILITY_STURDY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TOGEDEMARU)
static const u16 sTogedemaruTotemLearnableAbilities[] = {
    ABILITY_STURDY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MIMIKYU)
static const u16 sMimikyuDisguisedLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MIMIKYU)
static const u16 sMimikyuTotemDisguisedLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_BRUXISH)
static const u16 sBruxishLearnableAbilities[] = {
    ABILITY_DAZZLING,
    ABILITY_STRONG_JAW,
    ABILITY_WONDER_SKIN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DRAMPA)
static const u16 sDrampaLearnableAbilities[] = {
    ABILITY_BERSERK,
    ABILITY_SAP_SIPPER,
    ABILITY_CLOUD_NINE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DHELMISE)
static const u16 sDhelmiseLearnableAbilities[] = {
    ABILITY_STEELWORKER,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_JANGMO_O)
static const u16 sJangmoOLearnableAbilities[] = {
    ABILITY_BULLETPROOF,
    ABILITY_SOUNDPROOF,
    ABILITY_OVERCOAT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_JANGMO_O)
static const u16 sHakamoOLearnableAbilities[] = {
    ABILITY_BULLETPROOF,
    ABILITY_SOUNDPROOF,
    ABILITY_OVERCOAT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_JANGMO_O)
static const u16 sKommoOLearnableAbilities[] = {
    ABILITY_BULLETPROOF,
    ABILITY_SOUNDPROOF,
    ABILITY_OVERCOAT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_JANGMO_O)
static const u16 sKommoOTotemLearnableAbilities[] = {
    ABILITY_BULLETPROOF,
    ABILITY_SOUNDPROOF,
    ABILITY_OVERCOAT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TAPU_KOKO)
static const u16 sTapuKokoLearnableAbilities[] = {
    ABILITY_ELECTRIC_SURGE,
    ABILITY_TELEPATHY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TAPU_LELE)
static const u16 sTapuLeleLearnableAbilities[] = {
    ABILITY_PSYCHIC_SURGE,
    ABILITY_TELEPATHY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TAPU_BULU)
static const u16 sTapuBuluLearnableAbilities[] = {
    ABILITY_GRASSY_SURGE,
    ABILITY_TELEPATHY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TAPU_FINI)
static const u16 sTapuFiniLearnableAbilities[] = {
    ABILITY_MISTY_SURGE,
    ABILITY_TELEPATHY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_COSMOG)
static const u16 sCosmogLearnableAbilities[] = {
    ABILITY_UNAWARE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_COSMOG)
static const u16 sCosmoemLearnableAbilities[] = {
    ABILITY_UNAWARE,
    ABILITY_STURDY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_COSMOG)
static const u16 sSolgaleoLearnableAbilities[] = {
    ABILITY_UNAWARE,
    ABILITY_STURDY,
    ABILITY_FULL_METAL_BODY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_COSMOG)
static const u16 sLunalaLearnableAbilities[] = {
    ABILITY_UNAWARE,
    ABILITY_STURDY,
    ABILITY_SHADOW_SHIELD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_NIHILEGO)
static const u16 sNihilegoLearnableAbilities[] = {
    ABILITY_BEAST_BOOST,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_BUZZWOLE)
static const u16 sBuzzwoleLearnableAbilities[] = {
    ABILITY_BEAST_BOOST,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PHEROMOSA)
static const u16 sPheromosaLearnableAbilities[] = {
    ABILITY_BEAST_BOOST,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_XURKITREE)
static const u16 sXurkitreeLearnableAbilities[] = {
    ABILITY_BEAST_BOOST,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CELESTEELA)
static const u16 sCelesteelaLearnableAbilities[] = {
    ABILITY_BEAST_BOOST,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_KARTANA)
static const u16 sKartanaLearnableAbilities[] = {
    ABILITY_BEAST_BOOST,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GUZZLORD)
static const u16 sGuzzlordLearnableAbilities[] = {
    ABILITY_BEAST_BOOST,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_NECROZMA)
static const u16 sNecrozmaLearnableAbilities[] = {
    ABILITY_PRISM_ARMOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_NECROZMA) && (P_FUSION_FORMS)
static const u16 sNecrozmaDuskManeLearnableAbilities[] = {
    ABILITY_PRISM_ARMOR,
    ABILITY_NEUROFORCE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MAGEARNA)
static const u16 sMagearnaLearnableAbilities[] = {
    ABILITY_SOUL_HEART,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MAGEARNA)
static const u16 sMagearnaOriginalLearnableAbilities[] = {
    ABILITY_SOUL_HEART,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MARSHADOW)
static const u16 sMarshadowLearnableAbilities[] = {
    ABILITY_TECHNICIAN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_POIPOLE)
static const u16 sPoipoleLearnableAbilities[] = {
    ABILITY_BEAST_BOOST,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_POIPOLE)
static const u16 sNaganadelLearnableAbilities[] = {
    ABILITY_BEAST_BOOST,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_STAKATAKA)
static const u16 sStakatakaLearnableAbilities[] = {
    ABILITY_BEAST_BOOST,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_BLACEPHALON)
static const u16 sBlacephalonLearnableAbilities[] = {
    ABILITY_BEAST_BOOST,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ZERAORA)
static const u16 sZeraoraLearnableAbilities[] = {
    ABILITY_VOLT_ABSORB,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MELTAN)
static const u16 sMeltanLearnableAbilities[] = {
    ABILITY_MAGNET_PULL,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MELTAN)
static const u16 sMelmetalLearnableAbilities[] = {
    ABILITY_IRON_FIST,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GROOKEY)
static const u16 sGrookeyLearnableAbilities[] = {
    ABILITY_OVERGROW,
    ABILITY_GRASSY_SURGE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GROOKEY)
static const u16 sThwackeyLearnableAbilities[] = {
    ABILITY_OVERGROW,
    ABILITY_GRASSY_SURGE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GROOKEY)
static const u16 sRillaboomLearnableAbilities[] = {
    ABILITY_OVERGROW,
    ABILITY_GRASSY_SURGE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SCORBUNNY)
static const u16 sScorbunnyLearnableAbilities[] = {
    ABILITY_BLAZE,
    ABILITY_LIBERO,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SCORBUNNY)
static const u16 sRabootLearnableAbilities[] = {
    ABILITY_BLAZE,
    ABILITY_LIBERO,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SCORBUNNY)
static const u16 sCinderaceLearnableAbilities[] = {
    ABILITY_BLAZE,
    ABILITY_LIBERO,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SOBBLE)
static const u16 sSobbleLearnableAbilities[] = {
    ABILITY_TORRENT,
    ABILITY_SNIPER,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SOBBLE)
static const u16 sDrizzileLearnableAbilities[] = {
    ABILITY_TORRENT,
    ABILITY_SNIPER,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SOBBLE)
static const u16 sInteleonLearnableAbilities[] = {
    ABILITY_TORRENT,
    ABILITY_SNIPER,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SKWOVET)
static const u16 sSkwovetLearnableAbilities[] = {
    ABILITY_CHEEK_POUCH,
    ABILITY_GLUTTONY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SKWOVET)
static const u16 sGreedentLearnableAbilities[] = {
    ABILITY_CHEEK_POUCH,
    ABILITY_GLUTTONY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ROOKIDEE)
static const u16 sRookideeLearnableAbilities[] = {
    ABILITY_KEEN_EYE,
    ABILITY_UNNERVE,
    ABILITY_BIG_PECKS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ROOKIDEE)
static const u16 sCorvisquireLearnableAbilities[] = {
    ABILITY_KEEN_EYE,
    ABILITY_UNNERVE,
    ABILITY_BIG_PECKS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ROOKIDEE)
static const u16 sCorviknightLearnableAbilities[] = {
    ABILITY_KEEN_EYE,
    ABILITY_UNNERVE,
    ABILITY_BIG_PECKS,
    ABILITY_PRESSURE,
    ABILITY_MIRROR_ARMOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_BLIPBUG)
static const u16 sBlipbugLearnableAbilities[] = {
    ABILITY_SWARM,
    ABILITY_COMPOUND_EYES,
    ABILITY_TELEPATHY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_BLIPBUG)
static const u16 sDottlerLearnableAbilities[] = {
    ABILITY_SWARM,
    ABILITY_COMPOUND_EYES,
    ABILITY_TELEPATHY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_BLIPBUG)
static const u16 sOrbeetleLearnableAbilities[] = {
    ABILITY_SWARM,
    ABILITY_COMPOUND_EYES,
    ABILITY_TELEPATHY,
    ABILITY_FRISK,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_NICKIT)
static const u16 sNickitLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_UNBURDEN,
    ABILITY_STAKEOUT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_NICKIT)
static const u16 sThievulLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_UNBURDEN,
    ABILITY_STAKEOUT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GOSSIFLEUR)
static const u16 sGossifleurLearnableAbilities[] = {
    ABILITY_COTTON_DOWN,
    ABILITY_REGENERATOR,
    ABILITY_EFFECT_SPORE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GOSSIFLEUR)
static const u16 sEldegossLearnableAbilities[] = {
    ABILITY_COTTON_DOWN,
    ABILITY_REGENERATOR,
    ABILITY_EFFECT_SPORE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_WOOLOO)
static const u16 sWoolooLearnableAbilities[] = {
    ABILITY_FLUFFY,
    ABILITY_RUN_AWAY,
    ABILITY_BULLETPROOF,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_WOOLOO)
static const u16 sDubwoolLearnableAbilities[] = {
    ABILITY_FLUFFY,
    ABILITY_RUN_AWAY,
    ABILITY_BULLETPROOF,
    ABILITY_STEADFAST,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CHEWTLE)
static const u16 sChewtleLearnableAbilities[] = {
    ABILITY_STRONG_JAW,
    ABILITY_SHELL_ARMOR,
    ABILITY_SWIFT_SWIM,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CHEWTLE)
static const u16 sDrednawLearnableAbilities[] = {
    ABILITY_STRONG_JAW,
    ABILITY_SHELL_ARMOR,
    ABILITY_SWIFT_SWIM,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_YAMPER)
static const u16 sYamperLearnableAbilities[] = {
    ABILITY_BALL_FETCH,
    ABILITY_RATTLED,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_YAMPER)
static const u16 sBoltundLearnableAbilities[] = {
    ABILITY_BALL_FETCH,
    ABILITY_RATTLED,
    ABILITY_STRONG_JAW,
    ABILITY_COMPETITIVE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ROLYCOLY)
static const u16 sRolycolyLearnableAbilities[] = {
    ABILITY_STEAM_ENGINE,
    ABILITY_HEATPROOF,
    ABILITY_FLASH_FIRE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ROLYCOLY)
static const u16 sCarkolLearnableAbilities[] = {
    ABILITY_STEAM_ENGINE,
    ABILITY_HEATPROOF,
    ABILITY_FLASH_FIRE,
    ABILITY_FLAME_BODY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ROLYCOLY)
static const u16 sCoalossalLearnableAbilities[] = {
    ABILITY_STEAM_ENGINE,
    ABILITY_HEATPROOF,
    ABILITY_FLASH_FIRE,
    ABILITY_FLAME_BODY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_APPLIN)
static const u16 sApplinLearnableAbilities[] = {
    ABILITY_RIPEN,
    ABILITY_GLUTTONY,
    ABILITY_BULLETPROOF,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_APPLIN)
static const u16 sFlappleLearnableAbilities[] = {
    ABILITY_RIPEN,
    ABILITY_GLUTTONY,
    ABILITY_BULLETPROOF,
    ABILITY_HUSTLE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_APPLIN)
static const u16 sAppletunLearnableAbilities[] = {
    ABILITY_RIPEN,
    ABILITY_GLUTTONY,
    ABILITY_BULLETPROOF,
    ABILITY_THICK_FAT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_APPLIN) && (P_GEN_9_CROSS_EVOS)
static const u16 sDipplinLearnableAbilities[] = {
    ABILITY_RIPEN,
    ABILITY_GLUTTONY,
    ABILITY_BULLETPROOF,
    ABILITY_SUPERSWEET_SYRUP,
    ABILITY_STICKY_HOLD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_APPLIN) && (P_GEN_9_CROSS_EVOS)
static const u16 sHydrappleLearnableAbilities[] = {
    ABILITY_RIPEN,
    ABILITY_GLUTTONY,
    ABILITY_BULLETPROOF,
    ABILITY_SUPERSWEET_SYRUP,
    ABILITY_STICKY_HOLD,
    ABILITY_REGENERATOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SILICOBRA)
static const u16 sSilicobraLearnableAbilities[] = {
    ABILITY_SAND_SPIT,
    ABILITY_SHED_SKIN,
    ABILITY_SAND_VEIL,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SILICOBRA)
static const u16 sSandacondaLearnableAbilities[] = {
    ABILITY_SAND_SPIT,
    ABILITY_SHED_SKIN,
    ABILITY_SAND_VEIL,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CRAMORANT)
static const u16 sCramorantLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ARROKUDA)
static const u16 sArrokudaLearnableAbilities[] = {
    ABILITY_SWIFT_SWIM,
    ABILITY_PROPELLER_TAIL,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ARROKUDA)
static const u16 sBarraskewdaLearnableAbilities[] = {
    ABILITY_SWIFT_SWIM,
    ABILITY_PROPELLER_TAIL,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TOXEL)
static const u16 sToxelLearnableAbilities[] = {
    ABILITY_RATTLED,
    ABILITY_STATIC,
    ABILITY_KLUTZ,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TOXEL)
static const u16 sToxtricityAmpedLearnableAbilities[] = {
    ABILITY_RATTLED,
    ABILITY_STATIC,
    ABILITY_KLUTZ,
    ABILITY_PUNK_ROCK,
    ABILITY_PLUS,
    ABILITY_TECHNICIAN,
    ABILITY_MINUS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SIZZLIPEDE)
static const u16 sSizzlipedeLearnableAbilities[] = {
    ABILITY_FLASH_FIRE,
    ABILITY_WHITE_SMOKE,
    ABILITY_FLAME_BODY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SIZZLIPEDE)
static const u16 sCentiskorchLearnableAbilities[] = {
    ABILITY_FLASH_FIRE,
    ABILITY_WHITE_SMOKE,
    ABILITY_FLAME_BODY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CLOBBOPUS)
static const u16 sClobbopusLearnableAbilities[] = {
    ABILITY_LIMBER,
    ABILITY_TECHNICIAN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CLOBBOPUS)
static const u16 sGrapploctLearnableAbilities[] = {
    ABILITY_LIMBER,
    ABILITY_TECHNICIAN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SINISTEA)
static const u16 sSinisteaPhonyLearnableAbilities[] = {
    ABILITY_WEAK_ARMOR,
    ABILITY_CURSED_BODY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SINISTEA)
static const u16 sSinisteaAntiqueLearnableAbilities[] = {
    ABILITY_WEAK_ARMOR,
    ABILITY_CURSED_BODY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SINISTEA)
static const u16 sPolteageistPhonyLearnableAbilities[] = {
    ABILITY_WEAK_ARMOR,
    ABILITY_CURSED_BODY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SINISTEA)
static const u16 sPolteageistAntiqueLearnableAbilities[] = {
    ABILITY_WEAK_ARMOR,
    ABILITY_CURSED_BODY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_HATENNA)
static const u16 sHatennaLearnableAbilities[] = {
    ABILITY_HEALER,
    ABILITY_ANTICIPATION,
    ABILITY_MAGIC_BOUNCE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_HATENNA)
static const u16 sHattremLearnableAbilities[] = {
    ABILITY_HEALER,
    ABILITY_ANTICIPATION,
    ABILITY_MAGIC_BOUNCE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_HATENNA)
static const u16 sHattereneLearnableAbilities[] = {
    ABILITY_HEALER,
    ABILITY_ANTICIPATION,
    ABILITY_MAGIC_BOUNCE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_IMPIDIMP)
static const u16 sImpidimpLearnableAbilities[] = {
    ABILITY_PRANKSTER,
    ABILITY_FRISK,
    ABILITY_PICKPOCKET,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_IMPIDIMP)
static const u16 sMorgremLearnableAbilities[] = {
    ABILITY_PRANKSTER,
    ABILITY_FRISK,
    ABILITY_PICKPOCKET,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_IMPIDIMP)
static const u16 sGrimmsnarlLearnableAbilities[] = {
    ABILITY_PRANKSTER,
    ABILITY_FRISK,
    ABILITY_PICKPOCKET,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MILCERY)
static const u16 sMilceryLearnableAbilities[] = {
    ABILITY_SWEET_VEIL,
    ABILITY_AROMA_VEIL,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MILCERY)
static const u16 sAlcremieStrawberryVanillaCreamLearnableAbilities[] = {
    ABILITY_SWEET_VEIL,
    ABILITY_AROMA_VEIL,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FALINKS)
static const u16 sFalinksLearnableAbilities[] = {
    ABILITY_BATTLE_ARMOR,
    ABILITY_DEFIANT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PINCURCHIN)
static const u16 sPincurchinLearnableAbilities[] = {
    ABILITY_LIGHTNING_ROD,
    ABILITY_ELECTRIC_SURGE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SNOM)
static const u16 sSnomLearnableAbilities[] = {
    ABILITY_SHIELD_DUST,
    ABILITY_ICE_SCALES,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SNOM)
static const u16 sFrosmothLearnableAbilities[] = {
    ABILITY_SHIELD_DUST,
    ABILITY_ICE_SCALES,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_STONJOURNER)
static const u16 sStonjournerLearnableAbilities[] = {
    ABILITY_POWER_SPOT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_EISCUE)
static const u16 sEiscueIceLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_INDEEDEE)
static const u16 sIndeedeeMLearnableAbilities[] = {
    ABILITY_INNER_FOCUS,
    ABILITY_SYNCHRONIZE,
    ABILITY_PSYCHIC_SURGE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_INDEEDEE)
static const u16 sIndeedeeFLearnableAbilities[] = {
    ABILITY_OWN_TEMPO,
    ABILITY_SYNCHRONIZE,
    ABILITY_PSYCHIC_SURGE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MORPEKO)
static const u16 sMorpekoFullBellyLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CUFANT)
static const u16 sCufantLearnableAbilities[] = {
    ABILITY_SHEER_FORCE,
    ABILITY_HEAVY_METAL,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CUFANT)
static const u16 sCopperajahLearnableAbilities[] = {
    ABILITY_SHEER_FORCE,
    ABILITY_HEAVY_METAL,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DRACOZOLT)
static const u16 sDracozoltLearnableAbilities[] = {
    ABILITY_VOLT_ABSORB,
    ABILITY_HUSTLE,
    ABILITY_SAND_RUSH,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ARCTOZOLT)
static const u16 sArctozoltLearnableAbilities[] = {
    ABILITY_VOLT_ABSORB,
    ABILITY_STATIC,
    ABILITY_SLUSH_RUSH,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DRACOVISH)
static const u16 sDracovishLearnableAbilities[] = {
    ABILITY_WATER_ABSORB,
    ABILITY_STRONG_JAW,
    ABILITY_SAND_RUSH,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ARCTOVISH)
static const u16 sArctovishLearnableAbilities[] = {
    ABILITY_WATER_ABSORB,
    ABILITY_ICE_BODY,
    ABILITY_SLUSH_RUSH,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DURALUDON)
static const u16 sDuraludonLearnableAbilities[] = {
    ABILITY_LIGHT_METAL,
    ABILITY_HEAVY_METAL,
    ABILITY_STALWART,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DURALUDON) && (P_GEN_9_CROSS_EVOS)
static const u16 sArchaludonLearnableAbilities[] = {
    ABILITY_LIGHT_METAL,
    ABILITY_HEAVY_METAL,
    ABILITY_STALWART,
    ABILITY_STAMINA,
    ABILITY_STURDY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DREEPY)
static const u16 sDreepyLearnableAbilities[] = {
    ABILITY_CLEAR_BODY,
    ABILITY_INFILTRATOR,
    ABILITY_CURSED_BODY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DREEPY)
static const u16 sDrakloakLearnableAbilities[] = {
    ABILITY_CLEAR_BODY,
    ABILITY_INFILTRATOR,
    ABILITY_CURSED_BODY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DREEPY)
static const u16 sDragapultLearnableAbilities[] = {
    ABILITY_CLEAR_BODY,
    ABILITY_INFILTRATOR,
    ABILITY_CURSED_BODY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ZACIAN)
static const u16 sZacianHeroLearnableAbilities[] = {
    ABILITY_INTREPID_SWORD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ZAMAZENTA)
static const u16 sZamazentaHeroLearnableAbilities[] = {
    ABILITY_DAUNTLESS_SHIELD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ETERNATUS)
static const u16 sEternatusLearnableAbilities[] = {
    ABILITY_PRESSURE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ETERNATUS)
static const u16 sEternatusEternamaxLearnableAbilities[] = {
    ABILITY_PRESSURE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_KUBFU)
static const u16 sKubfuLearnableAbilities[] = {
    ABILITY_INNER_FOCUS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_KUBFU)
static const u16 sUrshifuSingleStrikeLearnableAbilities[] = {
    ABILITY_INNER_FOCUS,
    ABILITY_UNSEEN_FIST,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_KUBFU)
static const u16 sUrshifuRapidStrikeLearnableAbilities[] = {
    ABILITY_INNER_FOCUS,
    ABILITY_UNSEEN_FIST,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ZARUDE)
static const u16 sZarudeLearnableAbilities[] = {
    ABILITY_LEAF_GUARD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ZARUDE)
static const u16 sZarudeDadaLearnableAbilities[] = {
    ABILITY_LEAF_GUARD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_REGIELEKI)
static const u16 sRegielekiLearnableAbilities[] = {
    ABILITY_TRANSISTOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_REGIDRAGO)
static const u16 sRegidragoLearnableAbilities[] = {
    ABILITY_DRAGONS_MAW,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GLASTRIER)
static const u16 sGlastrierLearnableAbilities[] = {
    ABILITY_CHILLING_NEIGH,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SPECTRIER)
static const u16 sSpectrierLearnableAbilities[] = {
    ABILITY_GRIM_NEIGH,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CALYREX)
static const u16 sCalyrexLearnableAbilities[] = {
    ABILITY_UNNERVE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CALYREX) && (P_FUSION_FORMS)
static const u16 sCalyrexIceLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CALYREX) && (P_FUSION_FORMS)
static const u16 sCalyrexShadowLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ENAMORUS)
static const u16 sEnamorusIncarnateLearnableAbilities[] = {
    ABILITY_CUTE_CHARM,
    ABILITY_CONTRARY,
    ABILITY_OVERCOAT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SPRIGATITO)
static const u16 sSprigatitoLearnableAbilities[] = {
    ABILITY_OVERGROW,
    ABILITY_PROTEAN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SPRIGATITO)
static const u16 sFloragatoLearnableAbilities[] = {
    ABILITY_OVERGROW,
    ABILITY_PROTEAN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SPRIGATITO)
static const u16 sMeowscaradaLearnableAbilities[] = {
    ABILITY_OVERGROW,
    ABILITY_PROTEAN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FUECOCO)
static const u16 sFuecocoLearnableAbilities[] = {
    ABILITY_BLAZE,
    ABILITY_UNAWARE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FUECOCO)
static const u16 sCrocalorLearnableAbilities[] = {
    ABILITY_BLAZE,
    ABILITY_UNAWARE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FUECOCO)
static const u16 sSkeledirgeLearnableAbilities[] = {
    ABILITY_BLAZE,
    ABILITY_UNAWARE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_QUAXLY)
static const u16 sQuaxlyLearnableAbilities[] = {
    ABILITY_TORRENT,
    ABILITY_MOXIE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_QUAXLY)
static const u16 sQuaxwellLearnableAbilities[] = {
    ABILITY_TORRENT,
    ABILITY_MOXIE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_QUAXLY)
static const u16 sQuaquavalLearnableAbilities[] = {
    ABILITY_TORRENT,
    ABILITY_MOXIE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_LECHONK)
static const u16 sLechonkLearnableAbilities[] = {
    ABILITY_AROMA_VEIL,
    ABILITY_GLUTTONY,
    ABILITY_THICK_FAT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_LECHONK)
static const u16 sOinkologneMLearnableAbilities[] = {
    ABILITY_AROMA_VEIL,
    ABILITY_GLUTTONY,
    ABILITY_THICK_FAT,
    ABILITY_LINGERING_AROMA,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_LECHONK)
static const u16 sOinkologneFLearnableAbilities[] = {
    ABILITY_AROMA_VEIL,
    ABILITY_GLUTTONY,
    ABILITY_THICK_FAT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TAROUNTULA)
static const u16 sTarountulaLearnableAbilities[] = {
    ABILITY_INSOMNIA,
    ABILITY_STAKEOUT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TAROUNTULA)
static const u16 sSpidopsLearnableAbilities[] = {
    ABILITY_INSOMNIA,
    ABILITY_STAKEOUT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_NYMBLE)
static const u16 sNymbleLearnableAbilities[] = {
    ABILITY_SWARM,
    ABILITY_TINTED_LENS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_NYMBLE)
static const u16 sLokixLearnableAbilities[] = {
    ABILITY_SWARM,
    ABILITY_TINTED_LENS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PAWMI)
static const u16 sPawmiLearnableAbilities[] = {
    ABILITY_STATIC,
    ABILITY_NATURAL_CURE,
    ABILITY_IRON_FIST,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PAWMI)
static const u16 sPawmoLearnableAbilities[] = {
    ABILITY_STATIC,
    ABILITY_NATURAL_CURE,
    ABILITY_IRON_FIST,
    ABILITY_VOLT_ABSORB,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PAWMI)
static const u16 sPawmotLearnableAbilities[] = {
    ABILITY_STATIC,
    ABILITY_NATURAL_CURE,
    ABILITY_IRON_FIST,
    ABILITY_VOLT_ABSORB,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TANDEMAUS)
static const u16 sTandemausLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_PICKUP,
    ABILITY_OWN_TEMPO,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TANDEMAUS)
static const u16 sMausholdThreeLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_PICKUP,
    ABILITY_OWN_TEMPO,
    ABILITY_FRIEND_GUARD,
    ABILITY_CHEEK_POUCH,
    ABILITY_TECHNICIAN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TANDEMAUS)
static const u16 sMausholdFourLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_PICKUP,
    ABILITY_OWN_TEMPO,
    ABILITY_FRIEND_GUARD,
    ABILITY_CHEEK_POUCH,
    ABILITY_TECHNICIAN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FIDOUGH)
static const u16 sFidoughLearnableAbilities[] = {
    ABILITY_OWN_TEMPO,
    ABILITY_KLUTZ,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FIDOUGH)
static const u16 sDachsbunLearnableAbilities[] = {
    ABILITY_OWN_TEMPO,
    ABILITY_KLUTZ,
    ABILITY_WELL_BAKED_BODY,
    ABILITY_AROMA_VEIL,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SMOLIV)
static const u16 sSmolivLearnableAbilities[] = {
    ABILITY_EARLY_BIRD,
    ABILITY_HARVEST,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SMOLIV)
static const u16 sDollivLearnableAbilities[] = {
    ABILITY_EARLY_BIRD,
    ABILITY_HARVEST,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SMOLIV)
static const u16 sArbolivaLearnableAbilities[] = {
    ABILITY_EARLY_BIRD,
    ABILITY_HARVEST,
    ABILITY_SEED_SOWER,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SQUAWKABILLY)
static const u16 sSquawkabillyGreenLearnableAbilities[] = {
    ABILITY_INTIMIDATE,
    ABILITY_HUSTLE,
    ABILITY_GUTS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SQUAWKABILLY)
static const u16 sSquawkabillyBlueLearnableAbilities[] = {
    ABILITY_INTIMIDATE,
    ABILITY_HUSTLE,
    ABILITY_GUTS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SQUAWKABILLY)
static const u16 sSquawkabillyYellowLearnableAbilities[] = {
    ABILITY_INTIMIDATE,
    ABILITY_HUSTLE,
    ABILITY_SHEER_FORCE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SQUAWKABILLY)
static const u16 sSquawkabillyWhiteLearnableAbilities[] = {
    ABILITY_INTIMIDATE,
    ABILITY_HUSTLE,
    ABILITY_SHEER_FORCE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_NACLI)
static const u16 sNacliLearnableAbilities[] = {
    ABILITY_PURIFYING_SALT,
    ABILITY_STURDY,
    ABILITY_CLEAR_BODY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_NACLI)
static const u16 sNaclstackLearnableAbilities[] = {
    ABILITY_PURIFYING_SALT,
    ABILITY_STURDY,
    ABILITY_CLEAR_BODY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_NACLI)
static const u16 sGarganaclLearnableAbilities[] = {
    ABILITY_PURIFYING_SALT,
    ABILITY_STURDY,
    ABILITY_CLEAR_BODY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CHARCADET)
static const u16 sCharcadetLearnableAbilities[] = {
    ABILITY_FLASH_FIRE,
    ABILITY_FLAME_BODY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CHARCADET)
static const u16 sArmarougeLearnableAbilities[] = {
    ABILITY_FLASH_FIRE,
    ABILITY_FLAME_BODY,
    ABILITY_WEAK_ARMOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CHARCADET)
static const u16 sCeruledgeLearnableAbilities[] = {
    ABILITY_FLASH_FIRE,
    ABILITY_FLAME_BODY,
    ABILITY_WEAK_ARMOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TADBULB)
static const u16 sTadbulbLearnableAbilities[] = {
    ABILITY_OWN_TEMPO,
    ABILITY_STATIC,
    ABILITY_DAMP,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TADBULB)
static const u16 sBelliboltLearnableAbilities[] = {
    ABILITY_OWN_TEMPO,
    ABILITY_STATIC,
    ABILITY_DAMP,
    ABILITY_ELECTROMORPHOSIS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_WATTREL)
static const u16 sWattrelLearnableAbilities[] = {
    ABILITY_WIND_POWER,
    ABILITY_VOLT_ABSORB,
    ABILITY_COMPETITIVE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_WATTREL)
static const u16 sKilowattrelLearnableAbilities[] = {
    ABILITY_WIND_POWER,
    ABILITY_VOLT_ABSORB,
    ABILITY_COMPETITIVE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MASCHIFF)
static const u16 sMaschiffLearnableAbilities[] = {
    ABILITY_INTIMIDATE,
    ABILITY_RUN_AWAY,
    ABILITY_STAKEOUT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MASCHIFF)
static const u16 sMabosstiffLearnableAbilities[] = {
    ABILITY_INTIMIDATE,
    ABILITY_RUN_AWAY,
    ABILITY_STAKEOUT,
    ABILITY_GUARD_DOG,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SHROODLE)
static const u16 sShroodleLearnableAbilities[] = {
    ABILITY_UNBURDEN,
    ABILITY_PICKPOCKET,
    ABILITY_PRANKSTER,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SHROODLE)
static const u16 sGrafaiaiLearnableAbilities[] = {
    ABILITY_UNBURDEN,
    ABILITY_PICKPOCKET,
    ABILITY_PRANKSTER,
    ABILITY_POISON_TOUCH,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_BRAMBLIN)
static const u16 sBramblinLearnableAbilities[] = {
    ABILITY_WIND_RIDER,
    ABILITY_INFILTRATOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_BRAMBLIN)
static const u16 sBrambleghastLearnableAbilities[] = {
    ABILITY_WIND_RIDER,
    ABILITY_INFILTRATOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TOEDSCOOL)
static const u16 sToedscoolLearnableAbilities[] = {
    ABILITY_MYCELIUM_MIGHT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TOEDSCOOL)
static const u16 sToedscruelLearnableAbilities[] = {
    ABILITY_MYCELIUM_MIGHT,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_KLAWF)
static const u16 sKlawfLearnableAbilities[] = {
    ABILITY_ANGER_SHELL,
    ABILITY_SHELL_ARMOR,
    ABILITY_REGENERATOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CAPSAKID)
static const u16 sCapsakidLearnableAbilities[] = {
    ABILITY_CHLOROPHYLL,
    ABILITY_INSOMNIA,
    ABILITY_KLUTZ,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CAPSAKID)
static const u16 sScovillainLearnableAbilities[] = {
    ABILITY_CHLOROPHYLL,
    ABILITY_INSOMNIA,
    ABILITY_KLUTZ,
    ABILITY_MOODY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_RELLOR)
static const u16 sRellorLearnableAbilities[] = {
    ABILITY_COMPOUND_EYES,
    ABILITY_SHED_SKIN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_RELLOR)
static const u16 sRabscaLearnableAbilities[] = {
    ABILITY_COMPOUND_EYES,
    ABILITY_SHED_SKIN,
    ABILITY_SYNCHRONIZE,
    ABILITY_TELEPATHY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FLITTLE)
static const u16 sFlittleLearnableAbilities[] = {
    ABILITY_ANTICIPATION,
    ABILITY_FRISK,
    ABILITY_SPEED_BOOST,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FLITTLE)
static const u16 sEspathraLearnableAbilities[] = {
    ABILITY_ANTICIPATION,
    ABILITY_FRISK,
    ABILITY_SPEED_BOOST,
    ABILITY_OPPORTUNIST,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TINKATINK)
static const u16 sTinkatinkLearnableAbilities[] = {
    ABILITY_MOLD_BREAKER,
    ABILITY_OWN_TEMPO,
    ABILITY_PICKPOCKET,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TINKATINK)
static const u16 sTinkatuffLearnableAbilities[] = {
    ABILITY_MOLD_BREAKER,
    ABILITY_OWN_TEMPO,
    ABILITY_PICKPOCKET,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TINKATINK)
static const u16 sTinkatonLearnableAbilities[] = {
    ABILITY_MOLD_BREAKER,
    ABILITY_OWN_TEMPO,
    ABILITY_PICKPOCKET,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_WIGLETT)
static const u16 sWiglettLearnableAbilities[] = {
    ABILITY_GOOEY,
    ABILITY_RATTLED,
    ABILITY_SAND_VEIL,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_WIGLETT)
static const u16 sWugtrioLearnableAbilities[] = {
    ABILITY_GOOEY,
    ABILITY_RATTLED,
    ABILITY_SAND_VEIL,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_BOMBIRDIER)
static const u16 sBombirdierLearnableAbilities[] = {
    ABILITY_BIG_PECKS,
    ABILITY_KEEN_EYE,
    ABILITY_ROCKY_PAYLOAD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FINIZEN)
static const u16 sFinizenLearnableAbilities[] = {
    ABILITY_WATER_VEIL,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FINIZEN)
static const u16 sPalafinZeroLearnableAbilities[] = {
    ABILITY_WATER_VEIL,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_VAROOM)
static const u16 sVaroomLearnableAbilities[] = {
    ABILITY_OVERCOAT,
    ABILITY_SLOW_START,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_VAROOM)
static const u16 sRevavroomLearnableAbilities[] = {
    ABILITY_OVERCOAT,
    ABILITY_SLOW_START,
    ABILITY_FILTER,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CYCLIZAR)
static const u16 sCyclizarLearnableAbilities[] = {
    ABILITY_SHED_SKIN,
    ABILITY_REGENERATOR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ORTHWORM)
static const u16 sOrthwormLearnableAbilities[] = {
    ABILITY_EARTH_EATER,
    ABILITY_SAND_VEIL,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GLIMMET)
static const u16 sGlimmetLearnableAbilities[] = {
    ABILITY_TOXIC_DEBRIS,
    ABILITY_CORROSION,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GLIMMET)
static const u16 sGlimmoraLearnableAbilities[] = {
    ABILITY_TOXIC_DEBRIS,
    ABILITY_CORROSION,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GREAVARD)
static const u16 sGreavardLearnableAbilities[] = {
    ABILITY_PICKUP,
    ABILITY_FLUFFY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GREAVARD)
static const u16 sHoundstoneLearnableAbilities[] = {
    ABILITY_PICKUP,
    ABILITY_FLUFFY,
    ABILITY_SAND_RUSH,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FLAMIGO)
static const u16 sFlamigoLearnableAbilities[] = {
    ABILITY_SCRAPPY,
    ABILITY_TANGLED_FEET,
    ABILITY_COSTAR,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CETODDLE)
static const u16 sCetoddleLearnableAbilities[] = {
    ABILITY_THICK_FAT,
    ABILITY_SNOW_CLOAK,
    ABILITY_SHEER_FORCE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CETODDLE)
static const u16 sCetitanLearnableAbilities[] = {
    ABILITY_THICK_FAT,
    ABILITY_SNOW_CLOAK,
    ABILITY_SHEER_FORCE,
    ABILITY_SLUSH_RUSH,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_VELUZA)
static const u16 sVeluzaLearnableAbilities[] = {
    ABILITY_MOLD_BREAKER,
    ABILITY_SHARPNESS,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_DONDOZO)
static const u16 sDondozoLearnableAbilities[] = {
    ABILITY_UNAWARE,
    ABILITY_OBLIVIOUS,
    ABILITY_WATER_VEIL,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TATSUGIRI)
static const u16 sTatsugiriCurlyLearnableAbilities[] = {
    ABILITY_STORM_DRAIN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TATSUGIRI)
static const u16 sTatsugiriDroopyLearnableAbilities[] = {
    ABILITY_STORM_DRAIN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TATSUGIRI)
static const u16 sTatsugiriStretchyLearnableAbilities[] = {
    ABILITY_STORM_DRAIN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GREAT_TUSK)
static const u16 sGreatTuskLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SCREAM_TAIL)
static const u16 sScreamTailLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_BRUTE_BONNET)
static const u16 sBruteBonnetLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FLUTTER_MANE)
static const u16 sFlutterManeLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SLITHER_WING)
static const u16 sSlitherWingLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_SANDY_SHOCKS)
static const u16 sSandyShocksLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_IRON_TREADS)
static const u16 sIronTreadsLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_IRON_BUNDLE)
static const u16 sIronBundleLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_IRON_HANDS)
static const u16 sIronHandsLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_IRON_JUGULIS)
static const u16 sIronJugulisLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_IRON_MOTH)
static const u16 sIronMothLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_IRON_THORNS)
static const u16 sIronThornsLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FRIGIBAX)
static const u16 sFrigibaxLearnableAbilities[] = {
    ABILITY_THERMAL_EXCHANGE,
    ABILITY_ICE_BODY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FRIGIBAX)
static const u16 sArctibaxLearnableAbilities[] = {
    ABILITY_THERMAL_EXCHANGE,
    ABILITY_ICE_BODY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FRIGIBAX)
static const u16 sBaxcaliburLearnableAbilities[] = {
    ABILITY_THERMAL_EXCHANGE,
    ABILITY_ICE_BODY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GIMMIGHOUL)
static const u16 sGimmighoulChestLearnableAbilities[] = {
    ABILITY_RATTLED,
    ABILITY_RUN_AWAY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GIMMIGHOUL)
static const u16 sGholdengoLearnableAbilities[] = {
    ABILITY_RATTLED,
    ABILITY_RUN_AWAY,
    ABILITY_GOOD_AS_GOLD,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_WO_CHIEN)
static const u16 sWoChienLearnableAbilities[] = {
    ABILITY_TABLETS_OF_RUIN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CHIEN_PAO)
static const u16 sChienPaoLearnableAbilities[] = {
    ABILITY_SWORD_OF_RUIN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TING_LU)
static const u16 sTingLuLearnableAbilities[] = {
    ABILITY_VESSEL_OF_RUIN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_CHI_YU)
static const u16 sChiYuLearnableAbilities[] = {
    ABILITY_BEADS_OF_RUIN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_ROARING_MOON)
static const u16 sRoaringMoonLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_IRON_VALIANT)
static const u16 sIronValiantLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_KORAIDON)
static const u16 sKoraidonLearnableAbilities[] = {
    ABILITY_ORICHALCUM_PULSE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MIRAIDON)
static const u16 sMiraidonLearnableAbilities[] = {
    ABILITY_HADRON_ENGINE,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_WALKING_WAKE)
static const u16 sWalkingWakeLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_IRON_LEAVES)
static const u16 sIronLeavesLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_POLTCHAGEIST)
static const u16 sPoltchageistCounterfeitLearnableAbilities[] = {
    ABILITY_HOSPITALITY,
    ABILITY_HEATPROOF,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_POLTCHAGEIST)
static const u16 sPoltchageistArtisanLearnableAbilities[] = {
    ABILITY_HOSPITALITY,
    ABILITY_HEATPROOF,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_POLTCHAGEIST)
static const u16 sSinistchaUnremarkableLearnableAbilities[] = {
    ABILITY_HOSPITALITY,
    ABILITY_HEATPROOF,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_POLTCHAGEIST)
static const u16 sSinistchaMasterpieceLearnableAbilities[] = {
    ABILITY_HOSPITALITY,
    ABILITY_HEATPROOF,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_OKIDOGI)
static const u16 sOkidogiLearnableAbilities[] = {
    ABILITY_TOXIC_CHAIN,
    ABILITY_GUARD_DOG,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_MUNKIDORI)
static const u16 sMunkidoriLearnableAbilities[] = {
    ABILITY_TOXIC_CHAIN,
    ABILITY_FRISK,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_FEZANDIPITI)
static const u16 sFezandipitiLearnableAbilities[] = {
    ABILITY_TOXIC_CHAIN,
    ABILITY_TECHNICIAN,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_OGERPON)
static const u16 sOgerponTealLearnableAbilities[] = {
    ABILITY_DEFIANT,
    ABILITY_WATER_ABSORB,
    ABILITY_MOLD_BREAKER,
    ABILITY_STURDY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_GOUGING_FIRE)
static const u16 sGougingFireLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_RAGING_BOLT)
static const u16 sRagingBoltLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_IRON_BOULDER)
static const u16 sIronBoulderLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_IRON_CROWN)
static const u16 sIronCrownLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_TERAPAGOS)
static const u16 sTerapagosNormalLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_NONE,
};
#endif

#if (P_FAMILY_PECHARUNT)
static const u16 sPecharuntLearnableAbilities[] = {
    ABILITY_RUN_AWAY,
    ABILITY_NONE,
};
#endif
