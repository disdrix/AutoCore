
/* CVOGCharacter_WeaponAllowsKillXpBonus
   
   Parameters: this/character context (fastcall INFERRED)
   Returns: non-zero if kill-path spree bonus table may scale amount
   in CVOGReaction_AddExperience.
   
   Checks weapon/object state near +0xa0 / +0x100 / +0xac (INFERRED layout).
   Returns: bool-ish int */

int __fastcall CVOGCharacter_WeaponAllowsKillXpBonus(int param_1)

{
  uint3 uVar1;
  
  uVar1 = (uint3)((uint)(param_1 + 0xa0) >> 8);
  if (((param_1 + 0xa0 != 0) && (*(char *)(param_1 + 0x100) == '\0')) &&
     (*(int *)(param_1 + 0xac) != 2)) {
    return CONCAT31(uVar1,1);
  }
  return (uint)uVar1 << 8;
}

