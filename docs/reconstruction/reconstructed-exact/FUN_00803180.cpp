// =============================================================================
// FUN_00803180
// -----------------------------------------------------------------------------
// Stable ID: aa_00803180
// Address:   0x00803180  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00803180 @ 0x00803180
// Stable ID: aa_00803180
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~48 non-empty decompiler lines.
//  - Control keywords: if×5, return×2, do×2, goto×2, while×2.
//  - Notable callees: FUN_00803180, strncpy.
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

void __thiscall FUN_00803180(int param_1,byte *param_2)



{

  byte bVar1;

  byte *pbVar2;

  int iVar3;

  byte *pbVar4;

  bool bVar5;

  

  if (param_2 == (byte *)0x0) {

    *(uint8_t *)(param_1 + 0x34) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x13c) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x150) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x154) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x144) = 1;

    return;

  }

  pbVar2 = (byte *)(param_1 + 0x34);

  pbVar4 = param_2;

  do {

    bVar1 = *pbVar2;

    bVar5 = bVar1 < *pbVar4;

    if (bVar1 != *pbVar4) {

LAB_008031e4:

      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);

      goto LAB_008031e9;

    }

    if (bVar1 == 0) break;

    bVar1 = pbVar2[1];

    bVar5 = bVar1 < pbVar4[1];

    if (bVar1 != pbVar4[1]) goto LAB_008031e4;

    pbVar2 = pbVar2 + 2;

    pbVar4 = pbVar4 + 2;

  } while (bVar1 != 0);

  iVar3 = 0;

LAB_008031e9:

  if (iVar3 != 0) {

    strncpy((char *)(param_1 + 0x34),(char *)param_2,0x100);

    pbVar2 = param_2 + 1;

    do {

      bVar1 = *param_2;

      param_2 = param_2 + 1;

    } while (bVar1 != 0);

    *(int *)(param_1 + 0x13c) = (int)param_2 - (int)pbVar2;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x150) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x154) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x144) = 1;

  }

  return;

}
