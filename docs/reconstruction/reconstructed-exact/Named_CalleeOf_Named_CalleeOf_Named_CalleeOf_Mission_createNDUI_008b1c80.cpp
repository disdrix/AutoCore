// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_createNDUI_008b1c80
// -----------------------------------------------------------------------------
// Stable ID: aa_008b1c80
// Callee of Named_CalleeOf_Named_CalleeOf_Mission_createNDUIDialogs
// Address:   0x008b1c80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Mission_createNDUIDialogs: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_008b1430, FUN_008b1c80, NDUIWindow_ReloadInterface.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Mission_createNDUIDialogs
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_createNDUI_008b1c80(int *param_1)



{

  char cVar1;

  uint32_t /* width from decompiler */ uStack_1c;

  uint8_t uStack_8;

  uint8_t uStack_7;

  uint8_t uStack_6;

  uint8_t uStack_5;

  

  NDUIWindow_ReloadInterface();

  cVar1 = (**(code **)(*param_1 + 0x3d8))();

  if (cVar1 != '\0') {

    if (param_1[0x144] != 0) {

      (**(code **)(*(int *)param_1[0x144] + 0xcc))();

      uStack_1c = 0;

      (**(code **)(*(int *)param_1[0x144] + 0x15c))();

      uStack_6 = 0;

      uStack_7 = 0;

      uStack_8 = 0;

      uStack_5 = 0;

      (**(code **)(*(int *)param_1[0x144] + 0x15c))(1,&uStack_8);

      uStack_1c = 0;

      (**(code **)(*(int *)param_1[0x144] + 0x110))(&uStack_1c);

      *(uint8_t *)(param_1[0x144] + 0xc4) = 1;

      *(uint8_t *)(param_1[0x144] + 0xc5) = 0;

    }

    FUN_008b1430();

  }

  (**(code **)(*param_1 + 0x34c))();

  return;

}
