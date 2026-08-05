// =============================================================================
// FUN_00763820
// -----------------------------------------------------------------------------
// Stable ID: aa_00763820
// Address:   0x00763820  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00763820 @ 0x00763820
// Stable ID: aa_00763820
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, for×1.
//  - Notable callees: FUN_00967ec0×2, FUN_00763820.
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

uint32_t /* width from decompiler */ __thiscall FUN_00763820(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  if (param_1[0x25] == 0) {

    if ((param_1[0x30] != 0) && (param_1[0x31] - param_1[0x30] >> 2 != 0)) {

      (**(code **)(*param_1 + 0x34))();

      puVar1 = (uint32_t /* width from decompiler */ *)param_1[0x31];

      for (puVar3 = (uint32_t /* width from decompiler */ *)param_1[0x30]; puVar3 != puVar1; puVar3 = puVar3 + 1) {

        (**(code **)(*param_1 + 0x6c))(*puVar3,param_2);

      }

    }

  }

  else {

    iVar2 = (**(code **)(*(int *)param_1[0x25] + 0xc))();

    if (iVar2 != 0) {

      (**(code **)(*param_1 + 0x34))();

      (**(code **)(*(int *)param_1[0x25] + 0x14))(param_2);

      FUN_00967ec0(param_1 + 0x37);

      return 0;

    }

  }

  FUN_00967ec0(param_1 + 0x37);

  return 0;

}
