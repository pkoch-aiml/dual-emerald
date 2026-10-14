EventScript_PC::
	lockall
	setvar VAR_0x8004, PC_LOCATION_OTHER
	special DoPCTurnOnEffect
	playse SE_PC_ON
	msgbox Text_BootUpPC, MSGBOX_DEFAULT
	goto EventScript_PCMainMenu
	end

EventScript_PCMainMenu::
	message gText_WhichPCShouldBeAccessed
	waitmessage
	special ScriptMenu_CreatePCMultichoice
	goto EventScript_AccessPC
	end

EventScript_AccessPC::
	switch VAR_RESULT
	case 0, EventScript_AccessPokemonStorage
	case 1, EventScript_AccessPlayersPC
	case 2, EventScript_AccessCrossTraining
	case 3, EventScript_AccessHallOfFame
	case 4, EventScript_TurnOffPC
	case MULTI_B_PRESSED, EventScript_TurnOffPC
	end

@ Dual Emerald: cross-training. A party Pokémon passes on one of its remembered learned abilities, or its
@ natural ability, to a compatible party Pokémon. The source isn't changed.
EventScript_AccessCrossTraining::
	playse SE_PC_LOGIN
	msgbox Text_CrossTrainChooseSource, MSGBOX_DEFAULT
	special ChoosePartyMon
	goto_if_ge VAR_0x8004, PARTY_SIZE, EventScript_PCMainMenu
	callnative Native_PushCrossTrainableAbilities
	goto_if_eq VAR_RESULT, 0, EventScript_CrossTrainNothingToPass
	message Text_CrossTrainChooseAbility
	waitmessage
	dynmultistack 0, 0, FALSE, 6, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	goto_if_eq VAR_RESULT, MULTI_B_PRESSED, EventScript_PCMainMenu
	callnative Native_SetChosenCrossTrainAbility
	msgbox Text_CrossTrainChooseTarget, MSGBOX_DEFAULT
	special ChooseMonForAbilityTutor
	goto EventScript_PCMainMenu
	end

EventScript_CrossTrainNothingToPass::
	msgbox Text_CrossTrainNothingToPass, MSGBOX_DEFAULT
	goto EventScript_PCMainMenu
	end

Text_CrossTrainChooseSource:
	.string "Choose a POKéMON to cross-train from.$"

Text_CrossTrainChooseAbility:
	.string "Which Ability should it pass on?$"

Text_CrossTrainChooseTarget:
	.string "Choose a POKéMON to learn\n{STR_VAR_1}.$"

Text_CrossTrainNothingToPass:
	.string "That POKéMON has no Ability\nto pass on.$"

EventScript_AccessPlayersPC::
	playse SE_PC_LOGIN
	msgbox gText_AccessedPlayersPC, MSGBOX_DEFAULT
	special PlayerPC
	goto EventScript_PCMainMenu
	end

EventScript_AccessPokemonStorage::
	playse SE_PC_LOGIN
	call_if_unset FLAG_SYS_PC_LANETTE, EventScript_AccessSomeonesPC
	call_if_set FLAG_SYS_PC_LANETTE, EventScript_AccessLanettesPC
	msgbox gText_StorageSystemOpened, MSGBOX_DEFAULT
	special ShowPokemonStorageSystemPC
	goto EventScript_PCMainMenu
	end

EventScript_AccessSomeonesPC::
	msgbox gText_AccessedSomeonesPC, MSGBOX_DEFAULT
	return

EventScript_AccessLanettesPC::
#if IS_FRLG
	msgbox gText_AccessedBillsPC, MSGBOX_DEFAULT
#else
	msgbox gText_AccessedLanettesPC, MSGBOX_DEFAULT
#endif
	return

EventScript_TurnOffPC::
	setvar VAR_0x8004, PC_LOCATION_OTHER
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	releaseall
	end

EventScript_AccessHallOfFame::
	goto_if_unset FLAG_SYS_GAME_CLEAR, EventScript_TurnOffPC
	playse SE_PC_LOGIN
	special AccessHallOfFamePC
	goto EventScript_AccessPC
	end

EventScript_AccessPokemonBoxLink::
	playse SE_PC_LOGIN
	msgbox gText_StorageSystemOpened, MSGBOX_DEFAULT
	special ShowPokemonStorageSystemPC
	goto EventScript_TurnOffPC
	end
