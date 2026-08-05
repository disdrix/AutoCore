// =============================================================================
// Named_CalleeOf_Drive_s_VEHICLE_EXHAUST_d_004b7030
// -----------------------------------------------------------------------------
// Stable ID: aa_004b7030
// Callee of Drive_s_VEHICLE_EXHAUST_d
// Address:   0x004b7030  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Drive_s_VEHICLE_EXHAUST_d: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_004b7030, FUN_0058e270, FUN_0058e300.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Drive_s_VEHICLE_EXHAUST_d
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

Named_CalleeOf_Drive_s_VEHICLE_EXHAUST_d_004b7030(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,char param_4,uint32_t /* width from decompiler */ param_5)



{

  int *piVar1;

  

  piVar1 = (int *)**(int **)(param_1 + 0x204);

  if (piVar1 != *(int **)(param_1 + 0x204)) {

    do {

      if ((*(byte *)(piVar1[2] + 0x90e) & 0x80) != 0) {

        if (param_4 == '\0') {

          FUN_0058e300(param_2,param_3);

        }

        else {

          FUN_0058e270(param_2,param_3,param_5);

        }

      }

      piVar1 = (int *)*piVar1;

    } while (piVar1 != (int *)*(int *)(param_1 + 0x204));

  }

  return;

}
