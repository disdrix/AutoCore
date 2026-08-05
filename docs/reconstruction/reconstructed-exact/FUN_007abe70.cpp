// =============================================================================
// FUN_007abe70
// -----------------------------------------------------------------------------
// Stable ID: aa_007abe70
// Address:   0x007abe70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007abe70 @ 0x007abe70
// Stable ID: aa_007abe70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×4, return×3.
//  - Notable callees: FUN_007abe70.
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

uint32_t /* width from decompiler */ __thiscall FUN_007abe70(int *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  char cVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  cVar1 = (**(code **)(*param_1 + 0xd8))();

  if (cVar1 != '\0') {

    if (*(char *)((int)param_1 + 0xda) == '\0') {

      if (param_1[0xac] != 0) {

                    /* WARNING: Could not recover jumptable at 0x007abeeb. Too many branches */

                    /* WARNING: Treating indirect jump as call */

        uVar2 = (**(code **)(*(int *)param_1[0xac] + 0x338))();

        return uVar2;

      }

    }

    else {

      cVar1 = (**(code **)(*param_1 + 0x280))

                        ((int)(short)param_3,(int)(short)((uint)param_3 >> 0x10));

      if (cVar1 != '\0') {

        return 1;

      }

      (**(code **)(*param_1 + 800))(0,0,0,0,0,0);

    }

  }

  return 0;

}
