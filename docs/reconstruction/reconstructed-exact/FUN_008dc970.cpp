// =============================================================================
// FUN_008dc970
// -----------------------------------------------------------------------------
// Stable ID: aa_008dc970
// Address:   0x008dc970  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008dc970 @ 0x008dc970
// Stable ID: aa_008dc970
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_008dc970, NDUIWindow_ReloadInterface.
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

void __thiscall FUN_008dc970(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  char cVar2;

  int *piVar3;

  uint8_t local_8 [8];

  

  NDUIWindow_ReloadInterface(param_2);

  piVar3 = (int *)(**(code **)(*param_1 + 0x120))(local_8,1,0);

  iVar1 = piVar3[1];

  param_1[0x147] = *piVar3;

  param_1[0x148] = iVar1;

  cVar2 = (**(code **)(*param_1 + 0x3d8))();

  if (cVar2 != '\0') {

    cVar2 = (**(code **)(*param_1 + 0x468))();

    if (cVar2 != '\0') {

      (**(code **)(*param_1 + 0x110))(param_1 + 0x147);

      *(uint8_t *)(param_1 + 0x146) = 0;

      (**(code **)(*param_1 + 0x464))(1);

      return;

    }

    *(uint8_t *)(param_1 + 0x146) = 1;

    (**(code **)(*param_1 + 0x464))(0);

  }

  return;

}
