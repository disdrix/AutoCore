// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_Input_PollB_00837d50
// -----------------------------------------------------------------------------
// Stable ID: aa_00837d50
// Callee of Named_CalleeOf_Named_CalleeOf_Client_Input_PollBoundActions
// Address:   0x00837d50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_Input_PollBoundActions: input/binding helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00837d50.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_Input_PollBoundActions
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_Input_PollB_00837d50(uint32_t /* width from decompiler */ param_1)



{

  int iVar1;

  uint8_t uVar2;

  int in_EAX;

  int *unaff_ESI;

  float10 fVar3;

  uint32_t /* width from decompiler */ uVar4;

  

  unaff_ESI[0x146] = in_EAX;

  uVar2 = (**(code **)(*unaff_ESI + 0xd0))(param_1);

  uVar4 = 1;

  (**(code **)(*unaff_ESI + 0xcc))(1,uVar2);

  (**(code **)(*unaff_ESI + 0x444))();

  (**(code **)(*unaff_ESI + 0xcc))(uVar4);

  if (((int *)unaff_ESI[0x14f] != (int *)0x0) && (unaff_ESI[0x146] != 0)) {

    iVar1 = *(int *)unaff_ESI[0x14f];

    fVar3 = (float10)(**(code **)(iVar1 + 0x3c8))();

    (**(code **)(iVar1 + 0x3b0))((float)fVar3);

  }

                    /* WARNING: Could not recover jumptable at 0x00837dbc. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (**(code **)(*unaff_ESI + 0x34c))();

  return;

}
