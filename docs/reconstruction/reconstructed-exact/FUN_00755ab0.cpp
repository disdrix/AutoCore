// =============================================================================
// FUN_00755ab0
// -----------------------------------------------------------------------------
// Stable ID: aa_00755ab0
// Address:   0x00755ab0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00755ab0 @ 0x00755ab0
// Stable ID: aa_00755ab0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: while×1, if×1, return×1.
//  - Notable callees: CONCAT31×2, CONCAT22, FUN_00755890, FUN_00755ab0.
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

void __thiscall FUN_00755ab0(int param_1,int *param_2)



{

  char cVar1;

  int iVar2;

  ushort uVar3;

  char *in_EAX;

  uint32_t /* width from decompiler */ uVar4;

  int iVar5;

  int iVar6;

  

  cVar1 = *in_EAX;

  uVar4 = CONCAT31((int3)((uint)in_EAX >> 8),cVar1);

  iVar2 = *(int *)(param_1 + 0x7c);

  iVar6 = 0;

  while (cVar1 != '\0') {

    uVar3 = (ushort)(byte)uVar4;

    iVar5 = CONCAT22((short)((uint)uVar4 >> 0x10),uVar3);

    in_EAX = in_EAX + 1;

    if ((*(ushort *)(param_1 + 0x88) <= uVar3) && (uVar3 <= *(ushort *)(param_1 + 0x8a))) {

      iVar5 = FUN_00755890(iVar5);

      iVar6 = iVar6 + *(int *)(iVar5 + 0x18);

    }

    cVar1 = *in_EAX;

    uVar4 = CONCAT31((int3)((uint)iVar5 >> 8),cVar1);

  }

  param_2[1] = iVar2;

  *param_2 = iVar6;

  return;

}
