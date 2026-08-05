// =============================================================================
// FUN_009190d0
// -----------------------------------------------------------------------------
// Stable ID: aa_009190d0
// Address:   0x009190d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009190d0 @ 0x009190d0
// Stable ID: aa_009190d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, goto×2.
//  - Notable callees: FUN_004c3ac0, FUN_007a0120, FUN_009190d0.
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

void FUN_009190d0(void)



{

  int *piVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int unaff_ESI;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  

  local_24 = DAT_00aaa690;

  iVar2 = *(int *)(unaff_ESI + 0x60c);

  if (iVar2 != 0) {

    if (iVar2 == 1) {

      local_24 = DAT_00a0f6a4;

      if (*(int *)(unaff_ESI + 0xc70) == 0) {

        return;

      }

      puVar3 = (uint32_t /* width from decompiler */ *)(**(code **)(**(int **)(unaff_ESI + 0xc70) + 0x24))(&local_20);

      local_20 = *puVar3;

      local_1c = puVar3[1];

      local_18 = puVar3[2];

      goto LAB_009191c0;

    }

    if (((iVar2 != 3) ||

        (piVar1 = *(int **)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xa4 + DAT_00d1b6d8),

        piVar1 == (int *)0x0)) || (iVar2 = (**(code **)(*piVar1 + 0x1d8))(), iVar2 == 0)) {

      goto LAB_009191c0;

    }

  }

  puVar3 = (uint32_t /* width from decompiler */ *)FUN_004c3ac0();

  local_20 = *puVar3;

  local_1c = puVar3[1];

  local_18 = puVar3[2];

LAB_009191c0:

  FUN_007a0120(2,2,4,0x1a,0,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x548),0x3f800000,0x3f800000,local_24,

               local_24,0,0xccc8ffc8,0xffffff,local_20,local_1c,local_18,local_20,local_1c,local_18,

               DAT_00afdfc8,DAT_00afdfcc,DAT_00afdfd0,DAT_00afdfd4,DAT_00afdfd8,DAT_00afdfdc,

               DAT_00d1a6c0,DAT_00d1a6c4,DAT_00d1a6c8,1);

  return;

}
