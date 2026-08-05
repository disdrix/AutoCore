// =============================================================================
// Experience_XpToReachRelativeLevel
// -----------------------------------------------------------------------------
// Stable ID: aa_0052dec0
// Address:   0x0052dec0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 */

/* Experience_XpToReachRelativeLevel - XP needed to reach level+delta

   

   Parameters:

     this        - Character*

     nLevelDelta - relative level steps (can be negative)

   

   Algorithm:

     curLevel = vtable GetLevel (+0x27c)

     if curLevel + nLevelDelta < 1: return 0

     thr = Experience_GetCumulativeThreshold(curLevel + nLevelDelta - 1)

     return (int)(thr / flPersonalXpGain) - nTotalXp + 1

   

   Used by reaction SetLevel / relative-level helpers.

   Returns: int XP amount to grant (may be negative for de-level) */



int __thiscall Experience_XpToReachRelativeLevel(void *this,int nLevelDelta)



{

  int iVar1;

  uint uVar2;

  

  iVar1 = (**(code **)(*(int *)(*(int *)(*(int *)((int)this + 4) + 4) + 4 + (int)this) + 0x27c))();

  if (iVar1 + nLevelDelta < 1) {

    return 0;

  }

  uVar2 = Experience_GetCumulativeThreshold((short)(iVar1 + nLevelDelta) - 1);

  return ((int)((float)(int)uVar2 / *(float *)((int)this + 0xc54)) - *(int *)((int)this + 0x730)) +

         1;

}
