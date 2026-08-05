// =============================================================================
// FUN_008a7f20
// -----------------------------------------------------------------------------
// Stable ID: aa_008a7f20
// Address:   0x008a7f20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008a7f20 @ 0x008a7f20
// Stable ID: aa_008a7f20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_008a7f20.
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

void FUN_008a7f20(void)



{

  int iVar1;

  int *piVar2;

  int *unaff_ESI;

  int iVar3;

  int iStack_24;

  uint8_t local_18 [8];

  uint8_t local_10 [8];

  uint8_t auStack_8 [8];

  

  if (DAT_00d17944 != 0) {

    iVar3 = 0;

    if (unaff_ESI[0x19c] != 0) {

      iStack_24 = 1;

      piVar2 = (int *)(**(code **)(*(int *)unaff_ESI[0x19c] + 0x140))(local_18);

      iVar3 = (int)((float)*piVar2 * (float)unaff_ESI[0x14b]);

    }

    if (unaff_ESI[0x1a0] != 0) {

      iVar1 = unaff_ESI[0x19a];

      iStack_24 = 1;

      piVar2 = (int *)(**(code **)(*(int *)unaff_ESI[0x1a0] + 0x140))(local_10);

      iVar3 = iVar3 + (int)((float)*piVar2 * (float)unaff_ESI[0x14c]) * iVar1;

    }

    if (unaff_ESI[0x1a1] != 0) {

      iStack_24 = 1;

      piVar2 = (int *)(**(code **)(*(int *)unaff_ESI[0x1a1] + 0x140))(auStack_8);

      iVar3 = iVar3 + *piVar2;

    }

    iVar1 = *(int *)(DAT_00d17944 + 0x2c);

    iStack_24 = 0;

    (**(code **)(*unaff_ESI + 0x120))(auStack_8,1);

    iStack_24 = *(int *)(iVar1 + 0x80) / 2 - iVar3 / 2;

    (**(code **)(*unaff_ESI + 0x118))(&iStack_24);

  }

  return;

}
