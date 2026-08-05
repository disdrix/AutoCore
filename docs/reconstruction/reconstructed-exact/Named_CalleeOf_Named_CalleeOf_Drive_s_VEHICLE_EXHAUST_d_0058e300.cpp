// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Drive_s_VEHICLE_EXHAUST_d_0058e300
// -----------------------------------------------------------------------------
// Stable ID: aa_0058e300
// Callee of Named_CalleeOf_Drive_s_VEHICLE_EXHAUST_d
// Address:   0x0058e300  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Drive_s_VEHICLE_EXHAUST_d: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_0058e300, FUN_0096d460, FUN_0096d550, FUN_0096dc80.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Drive_s_VEHICLE_EXHAUST_d
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Drive_s_VEHICLE_EXHAUST_d_0058e300(int param_1,int param_2,int param_3)



{

  int iVar1;

  

  if (*(int *)(param_1 + 0x25c) < 0) {

    if (param_3 != 0) {

      FUN_0096d550(*(uint32_t /* width from decompiler */ *)(param_1 + 0x914));

    }

    if (param_2 != 0) {

      iVar1 = FUN_0096d460(*(uint32_t /* width from decompiler */ *)(param_1 + 600));

      if (iVar1 == 0) {

        FUN_0096dc80(*(uint32_t /* width from decompiler */ *)(param_1 + 600),*(uint32_t /* width from decompiler */ *)(param_1 + 0x914),

                     *(uint32_t /* width from decompiler */ *)(param_1 + 0x254));

        *(byte *)(param_1 + 0x90f) = *(byte *)(param_1 + 0x90f) | 1;

        return;

      }

    }

    *(byte *)(param_1 + 0x90f) = *(byte *)(param_1 + 0x90f) & 0xfe;

  }

  return;

}
