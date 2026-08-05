// =============================================================================
// FUN_007666c0
// -----------------------------------------------------------------------------
// Stable ID: aa_007666c0
// Address:   0x007666c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007666c0 @ 0x007666c0
// Stable ID: aa_007666c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_007666c0.
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

int __thiscall FUN_007666c0(int *param_1,uint32_t /* width from decompiler */ *param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  uint uVar2;

  void *pvVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *unaff_ESI;

  

  if (0 < param_1[4]) {

    param_1[4] = param_1[4] + 1;

    uVar1 = (**(code **)(*param_1 + 0x1c))();

    *param_2 = uVar1;

    return param_1[3];

  }

  uVar2 = (**(code **)(*param_1 + 0x1c))();

  pvVar3 = operator_new__(uVar2);

  param_1[3] = (int)pvVar3;

  iVar4 = (**(code **)(*param_1 + 0x14))(pvVar3,uVar2);

  if (-1 < iVar4) {

    param_1[4] = param_1[4] + 1;

    uVar1 = (**(code **)(*param_1 + 0x1c))();

    *unaff_ESI = uVar1;

    return param_1[3];

  }

  operator_delete__((void *)param_1[3]);

  param_1[3] = 0;

  uVar1 = (**(code **)(*param_1 + 0x1c))();

  *unaff_ESI = uVar1;

  return param_1[3];

}
