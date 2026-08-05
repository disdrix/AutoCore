// =============================================================================
// Named_CalleeOf_Named_ClientSpecialEvent_TeleportIn_0044adc0
// -----------------------------------------------------------------------------
// Stable ID: aa_0044adc0
// Callee of Named_ClientSpecialEvent_TeleportIn (+2 other named callers)
// Address:   0x0044adc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_ClientSpecialEvent_TeleportIn: spawn/transfer helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_ClientSpecialEvent_TeleportIn (+2 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_00437150×2, FUN_0044adc0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_ClientSpecialEvent_TeleportIn (+2 other named callers)
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

void Named_CalleeOf_Named_ClientSpecialEvent_TeleportIn_0044adc0(uint32_t /* width from decompiler */ *param_1)



{

  int *piVar1;

  int *piVar2;

  int *piVar3;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint local_4;

  

  puStack_8 = &LAB_009bcaea;

  pvStack_c = ExceptionList;

  local_4 = 1;

  piVar1 = param_1 + 3;

  ExceptionList = &pvStack_c;

  param_1[2] = 0;

  piVar3 = (int *)*piVar1;

  if (piVar3 != (int *)0x0) {

    piVar2 = piVar3 + 1;

    *piVar2 = *piVar2 + -1;

    if (*piVar2 == 0) {

      (**(code **)(*piVar3 + 8))();

    }

    *piVar1 = 0;

  }

  *param_1 = 0;

  piVar3 = (int *)param_1[1];

  if (piVar3 != (int *)0x0) {

    piVar2 = piVar3 + 1;

    *piVar2 = *piVar2 + -1;

    if (*piVar2 == 0) {

      (**(code **)(*piVar3 + 8))();

    }

    param_1[1] = 0;

  }

  local_4 = local_4 & 0xffffff00;

  FUN_00437150(piVar1);

  local_4 = 0xffffffff;

  FUN_00437150(param_1 + 1);

  ExceptionList = pvStack_c;

  return;

}
