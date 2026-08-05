// =============================================================================
// FUN_004bdd40
// -----------------------------------------------------------------------------
// Stable ID: aa_004bdd40
// Address:   0x004bdd40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004bdd40 @ 0x004bdd40
// Stable ID: aa_004bdd40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, do×1, while×1.
//  - Notable callees: FUN_004bdd40.
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

uint __thiscall FUN_004bdd40(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  byte bVar1;

  uint in_EAX;

  int iVar2;

  byte bVar3;

  

  if (*(int *)(param_1 + 0x1c) == 0) {

    return in_EAX & 0xffffff00;

  }

  iVar2 = *(int *)(param_1 + 0x14);

  bVar3 = 0;

  do {

    *(int *)(param_1 + 0x18) = iVar2;

    if ((int *)**(int **)(iVar2 + 0xc) != (int *)0x0) {

      bVar1 = (**(code **)(*(int *)**(int **)(iVar2 + 0xc) + 0x78))(param_2,param_3);

      bVar3 = bVar3 | bVar1;

    }

  } while ((*(int *)(param_1 + 0x18) != 0) &&

          (iVar2 = *(int *)(*(int *)(param_1 + 0x18) + 4), iVar2 != 0));

  return (uint)bVar3;

}
