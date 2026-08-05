// =============================================================================
// FUN_00755a50
// -----------------------------------------------------------------------------
// Stable ID: aa_00755a50
// Address:   0x00755a50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00755a50 @ 0x00755a50
// Stable ID: aa_00755a50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: while×1, if×1, return×1.
//  - Notable callees: FUN_00755890, FUN_00755a50.
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

void __thiscall FUN_00755a50(int param_1,int *param_2)



{

  ushort uVar1;

  int iVar2;

  ushort *in_EAX;

  int iVar3;

  int iVar4;

  

  iVar2 = *(int *)(param_1 + 0x7c);

  iVar4 = 0;

  uVar1 = *in_EAX;

  while (uVar1 != 0) {

    in_EAX = in_EAX + 1;

    if ((*(ushort *)(param_1 + 0x88) <= uVar1) && (uVar1 <= *(ushort *)(param_1 + 0x8a))) {

      iVar3 = FUN_00755890(uVar1);

      iVar4 = iVar4 + *(int *)(iVar3 + 0x18);

    }

    uVar1 = *in_EAX;

  }

  *param_2 = iVar4;

  param_2[1] = iVar2;

  return;

}
