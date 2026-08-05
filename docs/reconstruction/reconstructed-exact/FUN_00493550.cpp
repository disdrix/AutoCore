// =============================================================================
// FUN_00493550
// -----------------------------------------------------------------------------
// Stable ID: aa_00493550
// Address:   0x00493550  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00493550 @ 0x00493550
// Stable ID: aa_00493550
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00493550, FUN_00752370, FUN_00752a00, FUN_0096f5d0, FUN_0096fdf0.
//  - Return sites: 1.

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

int __thiscall FUN_00493550(int *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  uint32_t /* width from decompiler */ uVar1;

  char cVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  

  if (*param_1 == 0) {

    param_2 = 0xffffffff;

    puVar3 = &param_2;

  }

  else {

    puVar3 = (uint32_t /* width from decompiler */ *)FUN_00752370(&param_2,param_2);

  }

  uVar1 = *puVar3;

  cVar2 = FUN_0096fdf0();

  iVar4 = FUN_00752a00(uVar1,param_3);

  if ((iVar4 == -1) && (cVar2 != '\0')) {

    FUN_0096f5d0();

  }

  return iVar4;

}
