// =============================================================================
// FUN_009163a0
// -----------------------------------------------------------------------------
// Stable ID: aa_009163a0
// Address:   0x009163a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009163a0 @ 0x009163a0
// Stable ID: aa_009163a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×5, return×3.
//  - Notable callees: FUN_008a0210, FUN_009163a0.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint8_t __thiscall FUN_009163a0(int *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  char cVar1;

  int iVar2;

  

  cVar1 = (**(code **)(*param_1 + 0x3d8))();

  if (cVar1 == '\0') {

    return 0;

  }

  cVar1 = (**(code **)(*param_1 + 0x3d8))();

  if (((cVar1 == '\0') || (param_1[0x12e] == 0)) ||

     (cVar1 = (**(code **)(*(int *)param_1[0x12e] + 0x39c))(param_2,param_3), cVar1 == '\0')) {

    iVar2 = (int)(short)((uint)param_2 >> 0x10);

    if (DAT_00d1bdfa == '\0') {

      if (*(char *)((int)param_1 + 0x50a) != '\0') {

        (**(code **)(*param_1 + 0x44c))((float)iVar2 * _DAT_00aaa960);

      }

    }

    else if ((DAT_00d1b8f0 != (int *)0x0) &&

            (cVar1 = (**(code **)(*DAT_00d1b8f0 + 0x3d8))(), cVar1 != '\0')) {

      FUN_008a0210(0 < iVar2);

      return 1;

    }

  }

  return 1;

}
