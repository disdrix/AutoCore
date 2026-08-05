// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_00971900
// -----------------------------------------------------------------------------
// Stable ID: aa_00971900
// Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x00971900  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×4, return×3, for×1.
//  - Notable callees: FUN_005b2ba0×2, FUN_00971900×2, FUN_0043e5b0, FUN_00744360, FUN_00971480.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_00971900(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



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

  puStack_8 = &LAB_009b09cf;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_00971480(param_1);

  cVar2 = FUN_0043e5b0(param_2);

  if (cVar2 != '\0') {

    ExceptionList = local_c;

    return 1;

  }

  if ((char)param_3 != '\0') {

    local_1c = 0;

    local_18 = 0;

    local_14 = 0;

    local_10 = 0;

    local_4 = 0;

    FUN_00744360(param_2,local_20);

    for (uVar4 = local_14; uVar4 != local_14 + local_10; uVar4 = uVar4 + 1) {

      uVar3 = uVar4 >> 2;

      iVar1 = uVar3 * -4;

      if (local_18 <= uVar3) {

        uVar3 = uVar3 - local_18;

      }

      cVar2 = Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_00971900(*(int *)(local_1c + uVar3 * 4) + (uVar4 + iVar1) * 4,param_3);

      if (cVar2 != '\0') {

        FUN_005b2ba0();

        ExceptionList = local_c;

        return 1;

      }

    }

    FUN_005b2ba0();

  }

  ExceptionList = local_c;

  return 0;

}
