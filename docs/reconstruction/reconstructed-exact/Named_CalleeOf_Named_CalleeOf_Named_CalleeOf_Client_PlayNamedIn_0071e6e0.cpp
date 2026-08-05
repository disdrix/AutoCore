// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_PlayNamedIn_0071e6e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0071e6e0
// Callee of Named_CalleeOf_Named_CalleeOf_Client_PlayNamedInterfaceSound
// Address:   0x0071e6e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_PlayNamedInterfaceSound: presentation/world helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0071e6e0, FUN_0071f9b0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_PlayNamedInterfaceSound
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

uint32_t /* width from decompiler */ * __fastcall

Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_PlayNamedIn_0071e6e0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

            uint32_t /* width from decompiler */ param_5,uint32_t /* width from decompiler */ param_6,uint32_t /* width from decompiler */ param_7,uint32_t /* width from decompiler */ param_8,

            uint8_t param_9)



{

  uint32_t /* width from decompiler */ in_EAX;

  

  FUN_0071f9b0(&param_3,param_1,in_EAX);

  param_2[0x87] = param_5;

  param_2[0x8b] = param_8;

  param_2[0x8f] = 1;

  param_2[0x90] = 1;

  param_2[0x84] = 0;

  param_2[0x85] = 0;

  param_2[0x86] = 0;

  param_2[0x88] = 0;

  param_2[0x89] = 0;

  param_2[0x8a] = 0;

  param_2[0x8c] = 0;

  *(uint8_t *)((int)param_2 + 0x235) = 0;

  *param_2 = &PTR_FUN_00aa98a0;

  *(uint8_t *)(param_2 + 0x8d) = param_9;

  param_2[0x8e] = param_6;

  return param_2;

}
