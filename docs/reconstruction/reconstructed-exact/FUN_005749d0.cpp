// =============================================================================
// FUN_005749d0
// -----------------------------------------------------------------------------
// Stable ID: aa_005749d0
// Address:   0x005749d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005749d0 @ 0x005749d0
// Stable ID: aa_005749d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×3, return×3, while×1.
//  - Notable callees: CONCAT31, FUN_005749d0.
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

int __thiscall FUN_005749d0(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  uint3 uVar3;

  byte bVar4;

  uint uVar5;

  

  if (param_2 == 0) {

    return 0;

  }

  iVar1 = *(int *)(*(int *)(param_2 + 4) + 4);

  uVar5 = 0;

  while( true ) {

    iVar2 = uVar5 * 0x10;

    uVar3 = (uint3)((uint)iVar2 >> 8);

    if ((*(int *)(iVar1 + 0x164 + param_2) == *(int *)(iVar2 + 0x198 + param_1)) &&

       (*(int *)(iVar1 + 0x168 + param_2) == *(int *)(iVar2 + 0x19c + param_1))) break;

    bVar4 = (char)uVar5 + 1;

    uVar5 = (uint)bVar4;

    if (3 < bVar4) {

      return (uint)uVar3 << 8;

    }

  }

  return CONCAT31(uVar3,1);

}
