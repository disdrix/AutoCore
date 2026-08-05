// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004abc80
// -----------------------------------------------------------------------------
// Stable ID: aa_004abc80
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x004abc80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: do×2, while×2, return×1.
//  - Notable callees: CONCAT31×3, FUN_004a8ec0, FUN_004abc80.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
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

void Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004abc80(int param_1,int param_2)



{

  uint8_t *puVar1;

  char cVar2;

  int iVar3;

  int iVar4;

  uint local_8;

  int local_4;

  

  iVar4 = 0;

  local_4 = 4;

  do {

    cVar2 = '\0';

    local_8 = local_8 & 0xffffff00;

    iVar3 = param_2;

    do {

      puVar1 = (uint8_t *)(*(int *)(param_1 + 4) + iVar4);

      FUN_004a8ec0(CONCAT31((int3)((uint)puVar1 >> 8),*puVar1),

                   CONCAT31((int3)((uint)*(int *)(param_1 + 4) >> 8),puVar1[1]),iVar3,local_8);

      cVar2 = cVar2 + '\x01';

      iVar3 = iVar3 + 0x20;

      local_8 = CONCAT31(local_8._1_3_,cVar2);

    } while (cVar2 < '\x04');

    param_2 = param_2 + 8;

    iVar4 = iVar4 + 2;

    local_4 = local_4 + -1;

  } while (local_4 != 0);

  return;

}
