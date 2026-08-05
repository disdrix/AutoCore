// =============================================================================
// FUN_0099cfb0
// -----------------------------------------------------------------------------
// Stable ID: aa_0099cfb0
// Address:   0x0099cfb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0099cfb0 @ 0x0099cfb0
// Stable ID: aa_0099cfb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: CONCAT44, FUN_0043f4b0, FUN_00734550, FUN_00752df0, FUN_00967150, FUN_00972b20, FUN_00972e50, FUN_0099cfb0.
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

void __thiscall FUN_0099cfb0(int param_1,int param_2)



{

  int iVar1;

  uint64_t uVar2;

  

  if (*(int *)(param_1 + 0x14) != 0) {

    FUN_0043f4b0();

  }

  if (*(int *)(*(int *)(param_1 + 0x14) + 0x34) == 0) {

    FUN_00967150(*(int *)(param_1 + 0x14) + 0x24);

  }

  FUN_00734550();

  iVar1 = *(int *)(param_2 + 0x10);

  if ((*(byte *)(iVar1 + 0xbc) & 1) != 0) {

    iVar1 = FUN_00972e50();

  }

  if ((*(uint *)(*(int *)(param_2 + 0x10) + 0xbc) >> 2 & 1) == 0) {

    uVar2 = CONCAT44(iVar1,*(int *)(param_2 + 0x10) + 0xa8);

  }

  else {

    uVar2 = FUN_00972b20();

  }

  FUN_00752df0(*(uint32_t /* width from decompiler */ *)(param_2 + 4),(int)((ulonglong)uVar2 >> 0x20),1,(int)uVar2,0,0);

  return;

}
