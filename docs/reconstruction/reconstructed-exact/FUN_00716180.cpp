// =============================================================================
// FUN_00716180
// -----------------------------------------------------------------------------
// Stable ID: aa_00716180
// Address:   0x00716180  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00716180 @ 0x00716180
// Stable ID: aa_00716180
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_00716180.
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

void FUN_00716180(int *param_1,byte *param_2,int param_3)



{

  ushort uVar1;

  ushort *puVar2;

  byte *pbVar3;

  int iVar4;

  uint uVar5;

  byte bVar6;

  byte *pbVar7;

  byte *pbVar8;

  

  puVar2 = (ushort *)param_1[2];

  uVar1 = *(ushort *)(param_1 + 1);

  pbVar3 = (byte *)param_1[3];

  pbVar7 = (byte *)((uint)*puVar2 + *param_1);

  iVar4 = (1 << ((byte)param_3 & 0x1f)) + -1;

  uVar5 = (uint)*pbVar3 + param_3;

  if ((uVar5 & 0xfffffff8) != 0) {

    bVar6 = 8 - *pbVar3;

    pbVar8 = pbVar7 + 1;

    *param_2 = *pbVar7 >> (*pbVar3 & 0x1f);

    *puVar2 = *puVar2 + 1;

    if (uVar1 <= *puVar2) {

      *puVar2 = 0;

      pbVar8 = (byte *)*param_1;

    }

    *param_2 = *param_2 | ((byte)(iVar4 >> (bVar6 & 0x1f)) & *pbVar8) << (bVar6 & 0x1f);

    *pbVar3 = (char)uVar5 - 8;

    return;

  }

  *param_2 = *pbVar7 >> (*pbVar3 & 0x1f) & (byte)iVar4;

  if (uVar5 == 8) {

    uVar5 = 0;

    *puVar2 = *puVar2 + 1;

    if (uVar1 <= *puVar2) {

      *puVar2 = 0;

    }

  }

  *pbVar3 = (byte)uVar5;

  return;

}
