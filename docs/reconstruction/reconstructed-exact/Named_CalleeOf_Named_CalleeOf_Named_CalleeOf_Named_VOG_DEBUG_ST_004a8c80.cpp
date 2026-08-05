// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_004a8c80
// -----------------------------------------------------------------------------
// Stable ID: aa_004a8c80
// Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x004a8c80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: switch×1, do×1, while×1, return×1.
//  - Notable callees: CONCAT12, CONCAT22, FUN_004a8c80.
//  - Return sites: 1.

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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_004a8c80(uint32_t /* width from decompiler */ param_1,int param_2)



{

  char cVar1;

  uint8_t **ppuVar2;

  uint8_t *local_104;

  char local_100 [2];

  char cStack_fe;

  uint8_t uStack_fd;

  

  ppuVar2 = &local_104;

  switch(param_1) {

  case 0:

    local_104 = (uint8_t *)s_morning_009cae90._0_4_;

    _local_100 = s_morning_009cae90._4_4_;

    break;

  case 1:

    local_104 = &LAB_00796164;

    break;

  case 2:

    local_104 = (uint8_t *)s_sunset_009cae88._0_4_;

    _local_100 = CONCAT12(s_sunset_009cae88[6],s_sunset_009cae88._4_2_);

    break;

  case 3:

    local_104 = (uint8_t *)s_night_009cae80._0_4_;

    _local_100 = CONCAT22(_cStack_fe,s_night_009cae80._4_2_);

    break;

  default:

    local_104 = (uint8_t *)((uint)local_104 & 0xffffff00);

  }

  do {

    cVar1 = *(char *)ppuVar2;

    *(char *)((int)ppuVar2 + (param_2 - (int)&local_104)) = cVar1;

    ppuVar2 = (uint8_t **)((int)ppuVar2 + 1);

  } while (cVar1 != '\0');

  return;

}
