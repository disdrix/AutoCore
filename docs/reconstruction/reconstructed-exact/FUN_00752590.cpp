// =============================================================================
// FUN_00752590
// -----------------------------------------------------------------------------
// Stable ID: aa_00752590
// Address:   0x00752590  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00752590 @ 0x00752590
// Stable ID: aa_00752590
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, do×1, while×1.
//  - Notable callees: CONCAT31, FUN_00752590.
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

uint __fastcall FUN_00752590(uint32_t /* width from decompiler */ param_1,int param_2)



{

  int in_EAX;

  uint uVar1;

  int iVar2;

  char *pcVar3;

  char *pcVar4;

  bool bVar5;

  

  uVar1 = *(uint *)(in_EAX + 8);

  if ((((uVar1 == *(uint *)(param_2 + 8)) &&

       (*(short *)(in_EAX + 0x1c) == *(short *)(param_2 + 0x1c))) &&

      (*(short *)(in_EAX + 0x1e) == *(short *)(param_2 + 0x1e))) &&

     (*(int *)(in_EAX + 0x20) == *(int *)(param_2 + 0x20))) {

    if (*(int *)(uVar1 + 0x18) < 1) {

      iVar2 = 0;

    }

    else {

      iVar2 = *(int *)(uVar1 + 0x10) + *(int *)(uVar1 + 0x18) * 8;

      uVar1 = (uint)*(ushort *)(iVar2 + -2);

      iVar2 = *(ushort *)(iVar2 + -4) + uVar1;

    }

    bVar5 = true;

    pcVar3 = *(char **)(in_EAX + 0xc);

    pcVar4 = *(char **)(param_2 + 0xc);

    do {

      if (iVar2 == 0) break;

      iVar2 = iVar2 + -1;

      bVar5 = *pcVar3 == *pcVar4;

      pcVar3 = pcVar3 + 1;

      pcVar4 = pcVar4 + 1;

    } while (bVar5);

    if (bVar5) {

      return CONCAT31((int3)(uVar1 >> 8),1);

    }

  }

  return uVar1 & 0xffffff00;

}
