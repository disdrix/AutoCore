// =============================================================================
// FUN_0080bec0
// -----------------------------------------------------------------------------
// Stable ID: aa_0080bec0
// Address:   0x0080bec0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0080bec0 @ 0x0080bec0
// Stable ID: aa_0080bec0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~58 non-empty decompiler lines.
//  - Control keywords: if×8, return×1.
//  - Notable callees: FUN_00411990, FUN_004119e0, FUN_00533220, FUN_007fca10, FUN_007fef20, FUN_0080bec0, FUN_008a05a0.
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

void FUN_0080bec0(int param_1)



{

  uint *puVar1;

  uint uVar2;

  int iVar3;

  int *piVar4;

  char cVar5;

  uint8_t uVar6;

  uint32_t /* width from decompiler */ uVar7;

  int unaff_ESI;

  uint64_t uVar8;

  uint32_t /* width from decompiler */ uVar9;

  

  if ((*(char *)(param_1 + 4) != '\0') && (*(int *)(unaff_ESI + 0xe98) != 0)) {

    uVar9 = *(uint32_t /* width from decompiler */ *)(param_1 + 8);

    uVar7 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(unaff_ESI + 0xe98) + 4) + 4) + 4 +

                                 *(int *)(unaff_ESI + 0xe98)) + 0x27c))(uVar9);

    FUN_00533220(uVar7,uVar9);

    iVar3 = *(int *)(unaff_ESI + 0xe98);

    if (*(int *)(iVar3 + 0x660) < 1) {

      uVar8 = FUN_004119e0(0);

      puVar1 = (uint *)(iVar3 + 0x720);

      uVar2 = *puVar1;

      *puVar1 = *puVar1 - (uint)uVar8;

      *(int *)(iVar3 + 0x724) =

           (*(int *)(iVar3 + 0x724) - (int)((ulonglong)uVar8 >> 0x20)) - (uint)(uVar2 < (uint)uVar8)

      ;

      *(uint *)(iVar3 + 0x634) = *(uint *)(iVar3 + 0x634) | 1;

    }

    FUN_00411990(*(uint32_t /* width from decompiler */ *)(param_1 + 0x10),*(uint32_t /* width from decompiler */ *)(param_1 + 0x14));

    if ((((*(byte *)(param_1 + 8) & 1) != 0) && (DAT_00d1b874 != (int *)0x0)) &&

       (cVar5 = (**(code **)(*DAT_00d1b874 + 0x3d8))(), cVar5 == '\0')) {

      DAT_00d17928 = 1;

    }

    if ((((*(byte *)(param_1 + 8) & 0x40) != 0) && (DAT_00d1b870 != (int *)0x0)) &&

       (cVar5 = (**(code **)(*DAT_00d1b870 + 0x3d8))(), cVar5 == '\0')) {

      DAT_00d17929 = 1;

    }

    if ((((*(byte *)(param_1 + 8) & 4) != 0) && (DAT_00d1b87c != (int *)0x0)) &&

       (cVar5 = (**(code **)(*DAT_00d1b87c + 0x3d8))(), cVar5 == '\0')) {

      DAT_00d1792a = 1;

    }

    if ((*(int *)(unaff_ESI + 0x10b0) != 0) &&

       (cVar5 = (**(code **)(**(int **)(unaff_ESI + 0x10b0) + 0x3d8))(), cVar5 != '\0')) {

      FUN_008a05a0();

    }

    piVar4 = *(int **)(unaff_ESI + 0x10b0);

    if (piVar4 != (int *)0x0) {

      uVar6 = (**(code **)(*piVar4 + 0xd0))();

      cVar5 = (**(code **)(*piVar4 + 0x3d8))();

      FUN_007fca10();

      if (cVar5 != '\0') {

        FUN_007fef20(0x20,1,0);

        (**(code **)(*piVar4 + 4))(uVar6);

      }

    }

  }

  return;

}
