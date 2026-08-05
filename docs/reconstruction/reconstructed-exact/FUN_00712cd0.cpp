// =============================================================================
// FUN_00712cd0
// -----------------------------------------------------------------------------
// Stable ID: aa_00712cd0
// Address:   0x00712cd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00712cd0 @ 0x00712cd0
// Stable ID: aa_00712cd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_00712cd0.
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

void FUN_00712cd0(int *param_1,short param_2,char param_3)



{

  ushort uVar1;

  ushort *puVar2;

  byte *pbVar3;

  byte *pbVar4;

  

  puVar2 = (ushort *)param_1[4];

  pbVar3 = (byte *)param_1[5];

  uVar1 = *(ushort *)(param_1 + 1);

  pbVar4 = (byte *)((uint)*puVar2 + *param_1);

  if (*pbVar3 == 0) {

    *pbVar4 = (byte)param_2;

  }

  else {

    *pbVar4 = *pbVar4 | (byte)param_2 << (*pbVar3 & 0x1f);

  }

  *pbVar3 = *pbVar3 + param_3;

  if (8 < *pbVar3) {

    pbVar4 = pbVar4 + 1;

    *puVar2 = *puVar2 + 1;

    if (uVar1 <= *puVar2) {

      *puVar2 = 0;

      pbVar4 = (byte *)*param_1;

    }

    *pbVar4 = (byte)(param_2 >> ((param_3 - *pbVar3) + 8 & 0x1f));

    *pbVar3 = *pbVar3 - 8;

    return;

  }

  if (*pbVar3 == 8) {

    *pbVar3 = 0;

    *puVar2 = *puVar2 + 1;

    if (uVar1 <= *puVar2) {

      *puVar2 = 0;

    }

  }

  return;

}
