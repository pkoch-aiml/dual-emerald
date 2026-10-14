@ Dual Emerald: shared scripts for teaching learned abilities (Milestone 4).
@
@ Ability tutors (Milestone 6 places them): set VAR_0x8005 to the ability, handle any payment, then
@ `special ChooseMonForAbilityTutor`. VAR_RESULT is TRUE if a Pokémon learned the ability, so the
@ tutor only takes payment then.

@ The Ability Relearner. Expects VAR_0x8004 to be the chosen party slot; lists the learned abilities
@ that Pokémon remembers and makes the chosen one its learned ability again.
Common_EventScript_AbilityRelearner::
	callnative Native_PushRememberedAbilities
	goto_if_eq VAR_RESULT, 0, Common_EventScript_AbilityRelearnerNothing
	message Text_AbilityRelearnerWhich
	waitmessage
	dynmultistack 0, 0, FALSE, 6, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	goto_if_eq VAR_RESULT, MULTI_B_PRESSED, Common_EventScript_AbilityRelearnerEnd
	callnative Native_SetChosenRememberedAbility
	callnative Native_RelearnChosenAbility
	goto_if_eq VAR_RESULT, 1, Common_EventScript_AbilityRelearnerAlreadyHas
	goto_if_eq VAR_RESULT, 2, Common_EventScript_AbilityRelearnerCant
	playfanfare MUS_LEVEL_UP
	msgbox Text_AbilityRelearnerLearned, MSGBOX_DEFAULT
	waitfanfare
Common_EventScript_AbilityRelearnerEnd:
	return

Common_EventScript_AbilityRelearnerNothing:
	msgbox Text_AbilityRelearnerNothing, MSGBOX_DEFAULT
	return

Common_EventScript_AbilityRelearnerAlreadyHas:
	msgbox Text_AbilityRelearnerAlreadyHas, MSGBOX_DEFAULT
	return

Common_EventScript_AbilityRelearnerCant:
	msgbox Text_AbilityRelearnerCant, MSGBOX_DEFAULT
	return

Text_AbilityRelearnerWhich:
	.string "Which Ability should it relearn?$"

Text_AbilityRelearnerNothing:
	.string "{STR_VAR_2} doesn't remember any\nlearned Abilities.$"

Text_AbilityRelearnerLearned:
	.string "{STR_VAR_2} relearned\n{STR_VAR_1}!$"

Text_AbilityRelearnerAlreadyHas:
	.string "{STR_VAR_2} already has\n{STR_VAR_1}.$"

Text_AbilityRelearnerCant:
	.string "{STR_VAR_2} can't learn\n{STR_VAR_1}.$"
