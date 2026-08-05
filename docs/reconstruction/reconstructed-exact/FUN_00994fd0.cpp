// =============================================================================
// FUN_00994fd0
// -----------------------------------------------------------------------------
// Stable ID: aa_00994fd0
// Address:   0x00994fd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00994fd0 @ 0x00994fd0
// Stable ID: aa_00994fd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×2, for×1, return×1.
//  - Notable callees: FUN_0044bbc0×2, FUN_0044b9c0, FUN_00450e60, FUN_00994fd0.
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

void __fastcall FUN_00994fd0(int param_1,int param_2)



{

  uint uVar1;

  uint32_t /* width from decompiler */ in_EAX;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  int unaff_EDI;

  uint uVar4;

  

  *(uint *)(param_2 + 0xbc) = *(uint *)(param_2 + 0xbc) | 1;

  FUN_0044bbc0(in_EAX,0,0);

  if (*(int *)(param_1 + 4) == 0) {

    uVar2 = 0;

  }

  else {

    uVar2 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 4) + 0x1c);

  }

  FUN_0044b9c0(uVar2,0x20,0,0);

  FUN_00450e60(param_1,0,0,0);

  if (*(char *)(param_2 + 0xcc) == '\0') {

    uVar1 = *(uint *)(param_2 + 0xd8);

    iVar3 = *(int *)(unaff_EDI + 4);

    for (uVar4 = *(uint *)(param_2 + 0xd4); uVar4 < uVar1; uVar4 = uVar4 + 8) {

      FUN_0044bbc0(iVar3,0,0);

      iVar3 = iVar3 + 8;

    }

  }

  return;

}
