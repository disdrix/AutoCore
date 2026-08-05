// =============================================================================
// Character_GetTechForPoolCalcs
// -----------------------------------------------------------------------------
// Stable ID: aa_004c3ff0
// Address:   0x004c3ff0  (autoassault.exe, image base 0x400000)
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
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* Character_GetTechForPoolCalcs - clamp Tech for pool formulas.

   

   Parameters:

     pCharacter (ECX): character; Tech@+0x13c, bonus@+0x144 (INFERRED)

   Returns: int tech in [1,250]; raw Tech capped at 200 before bonus.

   

   Algorithm:

     capped = min(Tech, 200); sum = capped + bonus

     if sum < 2: return 1; if sum < 250: return sum; return 250

   

   AutoCore: VehicleHitPointCalculator.GetTechForPoolCalcs */



int __fastcall Character_GetTechForPoolCalcs(void *pCharacter)



{

  short nTechRaw;

  int nTechBonus;

  short nTechCapped;

  

  nTechRaw = *(short *)((int)pCharacter + 0x13c);

  nTechCapped = nTechRaw;

  if (199 < nTechRaw) {

    nTechCapped = 200;

  }

  nTechBonus = (int)*(short *)((int)pCharacter + 0x144);

  if (nTechCapped + nTechBonus < 0xfa) {

    nTechCapped = nTechRaw;

    if (199 < nTechRaw) {

      nTechCapped = 200;

    }

    if (nTechCapped + nTechBonus < 2) {

      return 1;

    }

  }

  nTechCapped = nTechRaw;

  if (199 < nTechRaw) {

    nTechCapped = 200;

  }

  if (nTechCapped + nTechBonus < 0xfa) {

    if (199 < nTechRaw) {

      nTechRaw = 200;

    }

    return nTechRaw + nTechBonus;

  }

  return 0xfa;

}
