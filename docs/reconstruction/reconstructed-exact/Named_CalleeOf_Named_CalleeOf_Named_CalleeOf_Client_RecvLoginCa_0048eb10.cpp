// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvLoginCa_0048eb10
// -----------------------------------------------------------------------------
// Stable ID: aa_0048eb10
// Callee of Named_CalleeOf_Named_CalleeOf_Client_RecvLoginCallback_3
// Address:   0x0048eb10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_RecvLoginCallback_3: auth/session helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_0074e260×2, FUN_0048eb10, FUN_005b3580, FUN_0074e0d0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_RecvLoginCallback_3
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvLoginCa_0048eb10(int param_1)



{

  if (*(int *)(param_1 + 0x104) != 0) {

    FUN_0074e260(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x104) + 0x8c));

    if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x104) != (uint32_t /* width from decompiler */ *)0x0) {

      (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x104))(1);

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x104) = 0;

  }

  if (*(int *)(param_1 + 0x108) != 0) {

    FUN_0074e0d0(0);

    FUN_0074e260(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x108) + 0x8c));

    if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x108) != (uint32_t /* width from decompiler */ *)0x0) {

      (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x108))(1);

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x108) = 0;

  }

  if (*(int *)(param_1 + 0xc4) != 0) {

    FUN_005b3580();

    return;

  }

  return;

}
