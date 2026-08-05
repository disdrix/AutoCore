// =============================================================================
// FUN_00511100
// -----------------------------------------------------------------------------
// Stable ID: aa_00511100
// Address:   0x00511100  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00511100 @ 0x00511100
// Stable ID: aa_00511100
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_0050eb40, FUN_00510360, FUN_00511100.
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

void __thiscall FUN_00511100(int param_1,uint param_2)



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

    uVar2 = (*(int *)(param_1 + 8) - iVar3) / 300;

  }

  if (param_2 <= uVar2) {

    if (((iVar3 != 0) && (iVar1 = *(int *)(param_1 + 8), param_2 < (uint)((iVar1 - iVar3) / 300)))

       && (iVar3 = iVar3 + param_2 * 300, iVar3 != iVar1)) {

      uVar4 = FUN_0050eb40(iVar1,iVar1,iVar3);

      *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar4;

    }

    return;

  }

  if (iVar3 == 0) {

    iVar3 = 0;

  }

  else {

    iVar3 = (*(int *)(param_1 + 8) - iVar3) / 300;

  }

  FUN_00510360(*(uint32_t /* width from decompiler */ *)(param_1 + 8),param_2 - iVar3,&stack0x00000008);

  return;

}
