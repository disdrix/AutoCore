// =============================================================================
// FUN_00522860
// -----------------------------------------------------------------------------
// Stable ID: aa_00522860
// Address:   0x00522860  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00522860 @ 0x00522860
// Stable ID: aa_00522860
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×3, return×3, do×2, while×2.
//  - Notable callees: FUN_00522780, FUN_00522860.
//  - Return sites: 3.

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

float10 __thiscall FUN_00522860(int param_1,uint *param_2)



{

  uint *puVar1;

  int iVar2;

  int iVar3;

  float10 fVar4;

  float local_4;

  

  local_4 = g_flOne;

  if (0 < *(int *)(param_1 + 0x6b4)) {

    return (float10)g_flOne;

  }

  iVar3 = 0;

  do {

    if ((*param_2 & param_2[1]) == 0xffffffff) {

      iVar2 = 1;

      puVar1 = param_2;

      do {

        if ((puVar1[2] & puVar1[3]) != 0xffffffff) {

          return (float10)g_flZero;

        }

        iVar2 = iVar2 + 1;

        puVar1 = puVar1 + 2;

      } while (iVar2 < 5);

    }

    else {

      fVar4 = (float10)FUN_00522780(iVar3 + 1,param_2);

      local_4 = (float)(fVar4 * (float10)local_4);

    }

    iVar3 = iVar3 + 1;

    param_2 = param_2 + 10;

  } while (iVar3 < 5);

  return (float10)local_4;

}
