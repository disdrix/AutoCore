// =============================================================================
// FUN_0041c370
// -----------------------------------------------------------------------------
// Stable ID: aa_0041c370
// Address:   0x0041c370  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0041c370 @ 0x0041c370
// Stable ID: aa_0041c370
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_0041c370, FUN_0041e800, FUN_004221e0.
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

void __thiscall FUN_0041c370(int param_1,uint param_2)



{

  int iVar1;

  uint uVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  

  iVar3 = *(int *)(param_1 + 4);

  if (iVar3 == 0) {

    uVar2 = 0;

  }

  else {

    uVar2 = (*(int *)(param_1 + 8) - iVar3) / 0x98;

  }

  if (param_2 <= uVar2) {

    if (((iVar3 != 0) && (iVar1 = *(int *)(param_1 + 8), param_2 < (uint)((iVar1 - iVar3) / 0x98)))

       && (iVar3 = iVar3 + param_2 * 0x98, iVar3 != iVar1)) {

      uVar4 = FUN_004221e0(iVar1,iVar1,iVar3,param_2);

      *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar4;

    }

    return;

  }

  if (iVar3 == 0) {

    iVar3 = 0;

  }

  else {

    iVar3 = (*(int *)(param_1 + 8) - iVar3) / 0x98;

  }

  FUN_0041e800(*(uint32_t /* width from decompiler */ *)(param_1 + 8),param_2 - iVar3,&stack0x00000008);

  return;

}
