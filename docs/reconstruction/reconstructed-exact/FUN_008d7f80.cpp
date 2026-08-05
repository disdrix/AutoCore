// =============================================================================
// FUN_008d7f80
// -----------------------------------------------------------------------------
// Stable ID: aa_008d7f80
// Address:   0x008d7f80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008d7f80 @ 0x008d7f80
// Stable ID: aa_008d7f80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_0076c4d0×2, FUN_0040cf90, FUN_0040d1a0, FUN_00755db0, FUN_00755e80, FUN_00755f10, FUN_008d7f80.
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

void __fastcall FUN_008d7f80(int param_1)



{

  char cVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  

  iVar2 = *(int *)(param_1 + 0x544);

  if (*(int *)(iVar2 + 0x48) != 0) {

    (**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) + 0xb8))

              (*(float *)(iVar2 + 0x638) + DAT_00aaaa1c);

    uVar4 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x544) + 0x48);

    iVar2 = (**(code **)(*DAT_00d1b77c + 0x1a8))();

    *(uint8_t *)(iVar2 + 0x48) = 1;

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x44) = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x40);

    FUN_0076c4d0();

    cVar1 = (**(code **)(**(int **)(iVar2 + 8) + 8))(uVar4);

    if (cVar1 != '\0') {

      FUN_00755db0(uVar4);

      FUN_00755e80(uVar4);

    }

    iVar2 = *(int *)(*(int *)(param_1 + 0x544) + 0x48);

    iVar3 = (**(code **)(*DAT_00d1b77c + 0x1a8))();

    if (iVar2 != 0) {

      *(uint8_t *)(iVar3 + 0x48) = 1;

      *(uint32_t /* width from decompiler */ *)(iVar3 + 0x44) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x40);

      FUN_0076c4d0();

      (**(code **)(**(int **)(iVar3 + 8) + 4))(iVar2);

      FUN_00755f10(iVar2);

    }

    uVar4 = 3;

    (**(code **)(**(int **)(*(int *)(param_1 + 0x544) + 0x48) + 0x10))(3,param_1 + 0x50c);

    FUN_0040cf90(uVar4);

    uVar4 = 3;

    (**(code **)(**(int **)(*(int *)(param_1 + 0x544) + 0x48) + 0x10))(3,param_1 + 0x518);

    FUN_0040d1a0(uVar4);

    (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x544) + 4) + 4) + 4 +

                         *(int *)(param_1 + 0x544)) + 0x144))();

                    /* WARNING: Could not recover jumptable at 0x008d80b0. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x544) + 4) + 4) + 4 +

                         *(int *)(param_1 + 0x544)) + 0x100))();

    return;

  }

  return;

}
