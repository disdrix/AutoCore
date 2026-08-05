// =============================================================================
// FUN_005d5360
// -----------------------------------------------------------------------------
// Stable ID: aa_005d5360
// Address:   0x005d5360  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005d5360 @ 0x005d5360
// Stable ID: aa_005d5360
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~56 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: FUN_004e87d0, FUN_004e88e0, FUN_005b5590, FUN_005d5360.
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

void __fastcall FUN_005d5360(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ *local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20 [3];

  uint8_t auStack_14 [4];

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  if (*(int *)(param_1 + 0x48) != 0) {

    if (*(int *)(param_1 + 8) == 0) {

      if (*(int **)(param_1 + 0x48) == (int *)0x0) {

        puVar1 = &DAT_00d1a6c0;

      }

      else {

        iVar2 = (**(code **)(**(int **)(param_1 + 0x48) + 0xc))();

        puVar1 = (uint32_t /* width from decompiler */ *)(iVar2 + 0x90);

      }

    }

    else {

      puVar1 = (uint32_t /* width from decompiler */ *)FUN_004e88e0(local_20,*(int *)(*(int *)(param_1 + 8) + 0x3c) + 0xb0);

    }

    local_2c = *puVar1;

    local_28 = (uint32_t /* width from decompiler */ *)puVar1[1];

    local_24 = puVar1[2];

    if (*(int *)(param_1 + 8) == 0) {

      if (*(int **)(param_1 + 0x48) == (int *)0x0) {

        puVar1 = &DAT_00afdfec;

      }

      else {

        iVar2 = (**(code **)(**(int **)(param_1 + 0x48) + 0xc))();

        puVar1 = (uint32_t /* width from decompiler */ *)(iVar2 + 0x80);

      }

    }

    else {

      puVar1 = (uint32_t /* width from decompiler */ *)FUN_004e87d0(local_20,*(int *)(*(int *)(param_1 + 8) + 0x3c) + 0x30);

    }

    local_10 = *puVar1;

    local_c = puVar1[1];

    local_8 = puVar1[2];

    local_4 = puVar1[3];

    puVar1 = &local_2c;

    (**(code **)(**(int **)(param_1 + 0x48) + 0x18))(puVar1);

    (**(code **)(**(int **)(param_1 + 0x48) + 0x14))(auStack_14);

    if (*(int *)(param_1 + 0x60) != 0) {

      local_20[0] = local_2c;

      local_28 = puVar1;

      FUN_005b5590(&local_28);

    }

  }

  return;

}
