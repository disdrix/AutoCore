// =============================================================================
// FUN_00790380
// -----------------------------------------------------------------------------
// Stable ID: aa_00790380
// Address:   0x00790380  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00790380 @ 0x00790380
// Stable ID: aa_00790380
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_00790380.
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

uint32_t /* width from decompiler */ __thiscall

FUN_00790380(int *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  int iVar1;

  

  iVar1 = param_1[0x12d];

  *(uint8_t *)((int)param_1 + 0x491) = 0;

  if (iVar1 != 0) {

    if (*(int *)(iVar1 + 0x1c) != 0) {

      *(uint32_t /* width from decompiler */ *)(iVar1 + 0x20) = param_2;

      iVar1 = param_1[0x12d];

      *(uint32_t /* width from decompiler */ *)(iVar1 + 0xc) = param_3;

      *(uint32_t /* width from decompiler */ *)(iVar1 + 0x10) = param_4;

      (**(code **)(*param_1 + 0x360))(param_1[0x12d]);

      iVar1 = param_1[0x12d];

      if (*(int *)(iVar1 + 0x14) != 0) {

        (**(code **)(**(int **)(iVar1 + 0x14) + 0x364))(iVar1);

      }

      (**(code **)(*param_1 + 0xb0))(*(uint32_t /* width from decompiler */ *)(param_1[0x12d] + 0x1c));

      if (*(uint32_t /* width from decompiler */ **)(param_1[0x12d] + 0x1c) != (uint32_t /* width from decompiler */ *)0x0) {

        (**(code **)**(uint32_t /* width from decompiler */ **)(param_1[0x12d] + 0x1c))(1);

      }

      *(uint32_t /* width from decompiler */ *)(param_1[0x12d] + 0x1c) = 0;

      (**(code **)(*param_1 + 0x34c))();

    }

    if ((uint32_t /* width from decompiler */ *)param_1[0x12d] != (uint32_t /* width from decompiler */ *)0x0) {

      (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x12d])(1);

    }

    param_1[0x12d] = 0;

    return 1;

  }

  return 0;

}
