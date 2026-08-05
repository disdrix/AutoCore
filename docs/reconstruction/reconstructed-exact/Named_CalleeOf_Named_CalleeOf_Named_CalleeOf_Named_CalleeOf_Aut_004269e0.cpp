// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Aut_004269e0
// -----------------------------------------------------------------------------
// Stable ID: aa_004269e0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Auth_No_authentica
// Address:   0x004269e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Auth_No_authentica: auth/session helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00424c90, FUN_004269e0, FUN_0042d440.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Auth_No_authentica
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

void __thiscall

Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Aut_004269e0(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ *param_3,uint8_t param_4,

            uint8_t param_5)



{

  *(uint8_t *)(param_1 + 0x164) = param_4;

  *(uint8_t *)(param_1 + 0x165) = param_5;

  *(uint8_t *)(param_1 + 0x194) = 1;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xf8) = *param_3;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xfc) = param_3[1];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x100) = param_3[2];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x104) = param_3[3];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x108) = param_3[4];

  FUN_00424c90();

  FUN_0042d440(*(uint32_t /* width from decompiler */ *)(param_1 + 0x1a8));

  return;

}
