// =============================================================================
// Named_CalleeOf_Named_assManager_00971a20
// -----------------------------------------------------------------------------
// Stable ID: aa_00971a20
// Callee of Named_assManager (+1 other named callers)
// Address:   0x00971a20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_assManager: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_assManager (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×4, return×3, for×1.
//  - Notable callees: FUN_005b2ba0×2, FUN_00971a20×2, FUN_0043d5e0, FUN_0044e8c0, FUN_00744360, FUN_00971480.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_assManager (+1 other named callers)
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_assManager_00971a20(int param_1,int param_2,int param_3)



{

  int iVar1;

  char cVar2;

  uint uVar3;

  uint uVar4;

  uint8_t local_20 [4];

  int local_1c;

  uint local_18;

  uint local_14;

  int local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b09e1;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_00971480(param_1);

  FUN_0043d5e0();

  if (param_2 == *(int *)(param_1 + 0x14)) {

    ExceptionList = local_c;

    return 0;

  }

  if (((char)param_3 != '\0') && (*(int *)(*(int *)(param_1 + 0x110) + 100) != 0)) {

    local_1c = 0;

    local_18 = 0;

    local_14 = 0;

    local_10 = 0;

    local_4 = 0;

    FUN_00744360(param_2,local_20);

    for (uVar4 = local_14; uVar4 != local_10 + local_14; uVar4 = uVar4 + 1) {

      uVar3 = uVar4 >> 2;

      iVar1 = uVar3 * -4;

      if (local_18 <= uVar3) {

        uVar3 = uVar3 - local_18;

      }

      cVar2 = Named_CalleeOf_Named_assManager_00971a20(*(int *)(local_1c + uVar3 * 4) + (uVar4 + iVar1) * 4,0);

      if ((cVar2 == '\0') &&

         ((iVar1 = *(int *)(param_1 + 0x110), FUN_0044e8c0(&param_3), param_3 == *(int *)(iVar1 + 8)

          || (*(int *)(param_3 + 0xc) == 0)))) {

        FUN_005b2ba0();

        ExceptionList = local_c;

        return 0;

      }

    }

    FUN_005b2ba0();

  }

  ExceptionList = local_c;

  return 1;

}
