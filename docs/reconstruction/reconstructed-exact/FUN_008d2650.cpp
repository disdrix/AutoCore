// =============================================================================
// FUN_008d2650
// -----------------------------------------------------------------------------
// Stable ID: aa_008d2650
// Address:   0x008d2650  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008d2650 @ 0x008d2650
// Stable ID: aa_008d2650
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~55 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_0040d1a0, FUN_00521b40, FUN_00523200, FUN_005232d0, FUN_00756060, FUN_007560a0, FUN_008cfa00, FUN_008d2650.
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

void FUN_008d2650(int param_1)



{

  int iVar1;

  int unaff_EBX;

  uint32_t /* width from decompiler */ uVar2;

  int local_14;

  uint32_t /* width from decompiler */ uStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  uint32_t /* width from decompiler */ uStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  if ((((*(int *)(unaff_EBX + 0x8e0) != 0) &&

       (local_14 = *(int *)(unaff_EBX + 0x8e4) - *(int *)(unaff_EBX + 0x8e0) >> 2, local_14 != 0))

      && (*(int *)(unaff_EBX + 0x544) != 0)) && (*(int *)(*(int *)(unaff_EBX + 0x544) + 0x48) != 0))

  {

    (**(code **)(*DAT_00d1b77c + 0x1a8))();

    FUN_00756060();

    (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(unaff_EBX + 0x544) + 4) + 4) + 4 +

                         *(int *)(unaff_EBX + 0x544)) + 0xfc))();

    *(int *)(unaff_EBX + 0x824) = *(int *)(unaff_EBX + 0x824) + param_1;

    if (*(int *)(unaff_EBX + 0x840) <= *(int *)(unaff_EBX + 0x824)) {

      *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x824) = 0;

    }

    if (*(int *)(unaff_EBX + 0x824) < 0) {

      if (*(int *)(unaff_EBX + 0x8e0) == 0) {

        iVar1 = 0;

      }

      else {

        iVar1 = *(int *)(unaff_EBX + 0x8e4) - *(int *)(unaff_EBX + 0x8e0) >> 2;

      }

      *(int *)(unaff_EBX + 0x824) = iVar1 + -1;

    }

    iVar1 = (**(code **)(**(int **)(*(int *)(unaff_EBX + 0x544) + 0x48) + 0xc))();

    uStack_10 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x80);

    uStack_c = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x84);

    uStack_8 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x88);

    uStack_4 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x8c);

    FUN_005232d0(*(uint32_t /* width from decompiler */ *)(*(int *)(unaff_EBX + 0x8e0) + *(int *)(unaff_EBX + 0x824) * 4),

                 *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x574));

    FUN_00523200();

    FUN_00521b40();

    (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(unaff_EBX + 0x544) + 4) + 4) + 4 +

                         *(int *)(unaff_EBX + 0x544)) + 0xb8))

              (*(float *)(unaff_EBX + 0x5b0) + DAT_00aaaa1c);

    (**(code **)(*DAT_00d1b77c + 0x1a8))();

    FUN_007560a0();

    uVar2 = 3;

    (**(code **)(**(int **)(*(int *)(unaff_EBX + 0x544) + 0x48) + 0x10))(3,&local_14);

    FUN_0040d1a0(uVar2);

    (**(code **)(**(int **)(*(int *)(unaff_EBX + 0x544) + 0x48) + 0x10))(3);

    (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(unaff_EBX + 0x544) + 4) + 4) + 4 +

                         *(int *)(unaff_EBX + 0x544)) + 0x100))();

    FUN_008cfa00(unaff_EBX);

  }

  return;

}
