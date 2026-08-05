// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_PlayNamedInterfaceSound_0071f870
// -----------------------------------------------------------------------------
// Stable ID: aa_0071f870
// Callee of Named_CalleeOf_Client_PlayNamedInterfaceSound
// Address:   0x0071f870  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_PlayNamedInterfaceSound: presentation/world helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_0071f870.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_PlayNamedInterfaceSound
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

uint32_t /* width from decompiler */ __fastcall Named_CalleeOf_Named_CalleeOf_Client_PlayNamedInterfaceSound_0071f870(uint32_t /* width from decompiler */ *param_1,uint param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  int in_EAX;

  uint32_t /* width from decompiler */ uVar2;

  

  if (*(int *)(in_EAX + 0x10) == 0) {

    return 0x800401f0;

  }

  if (*(uint *)(in_EAX + 0x1c) <= param_2) {

    return 0x80070057;

  }

  *param_1 = 0;

  puVar1 = *(uint32_t /* width from decompiler */ **)(*(int *)(in_EAX + 0x10) + param_2 * 4);

  uVar2 = (**(code **)*puVar1)(puVar1,&DAT_00a0d034,param_1);

  return uVar2;

}
