// =============================================================================
// FUN_009143b0
// -----------------------------------------------------------------------------
// Stable ID: aa_009143b0
// Address:   0x009143b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009143b0 @ 0x009143b0
// Stable ID: aa_009143b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: ClientToScreen×2, ClipCursor, FUN_009143b0, GetClientRect.
//  - Return sites: 2.

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

uint8_t __thiscall FUN_009143b0(int *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  char cVar1;

  uint8_t uVar2;

  uint8_t auStack_10 [16];

  

  if (param_1[0x31e] == 0) {

    if (DAT_00d1da19 == '\0') {

      DAT_00d1da18 = DAT_00d1da18 == '\0';

      (**(code **)(*param_1 + 0x3c4))(0);

      GetClientRect(DAT_00d1d9c8,(LPRECT)auStack_10);

      ClientToScreen(DAT_00d1d9c8,(LPPOINT)auStack_10);

      ClientToScreen(DAT_00d1d9c8,(LPPOINT)(auStack_10 + 8));

      ClipCursor((RECT *)auStack_10);

    }

    else {

      (**(code **)(*param_1 + 0x3c4))(*(char *)((int)param_1 + 0x493) == '\0');

    }

  }

  cVar1 = (**(code **)(*param_1 + 0x3d8))();

  if ((cVar1 != '\0') && (param_1[0x12e] != 0)) {

    uVar2 = (**(code **)(*(int *)param_1[0x12e] + 900))(param_2,param_3);

    return uVar2;

  }

  return *(uint8_t *)((int)param_1 + 0x496);

}
