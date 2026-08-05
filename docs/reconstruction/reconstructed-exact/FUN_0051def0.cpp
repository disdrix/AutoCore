// =============================================================================
// FUN_0051def0
// -----------------------------------------------------------------------------
// Stable ID: aa_0051def0
// Address:   0x0051def0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0051def0 @ 0x0051def0
// Stable ID: aa_0051def0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_0043fb00, FUN_0051d4a0, FUN_0051def0.
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

void __thiscall FUN_0051def0(int param_1,uint param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint uVar3;

  int iVar4;

  

  iVar4 = *(int *)(param_1 + 4);

  if (iVar4 == 0) {

    uVar3 = 0;

  }

  else {

    uVar3 = *(int *)(param_1 + 8) - iVar4 >> 4;

  }

  if (uVar3 < param_2) {

    if (iVar4 == 0) {

      iVar4 = 0;

    }

    else {

      iVar4 = *(int *)(param_1 + 8) - iVar4 >> 4;

    }

    FUN_0051d4a0(*(uint32_t /* width from decompiler */ *)(param_1 + 8),param_2 - iVar4,&stack0x00000008);

    return;

  }

  if (((iVar4 != 0) && (iVar1 = *(int *)(param_1 + 8), param_2 < (uint)(iVar1 - iVar4 >> 4))) &&

     (iVar4 = param_2 * 0x10 + iVar4, iVar4 != iVar1)) {

    uVar2 = FUN_0043fb00(iVar1,iVar1,iVar4,param_2);

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar2;

  }

  return;

}
