// =============================================================================
// Named_CalleeOf_Client_ConfirmEquipOrCustomizeItem_004ce5f0
// -----------------------------------------------------------------------------
// Stable ID: aa_004ce5f0
// Callee of Client_ConfirmEquipOrCustomizeItem (+1 other named callers)
// Address:   0x004ce5f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_ConfirmEquipOrCustomizeItem: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Client_ConfirmEquipOrCustomizeItem (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: FUN_004ce5f0.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Client_ConfirmEquipOrCustomizeItem (+1 other named callers)
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

bool __thiscall Named_CalleeOf_Client_ConfirmEquipOrCustomizeItem_004ce5f0(int param_1,int param_2)



{

  int iVar1;

  

  if (param_2 != 0) {

    iVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 4 + param_2) + 0x210))(0);

    if (iVar1 != 0) {

      if (*(char *)(param_1 + 0xf5) != '\0') {

        return true;

      }

      return *(char *)(param_1 + 0x7e) != '\0';

    }

  }

  return false;

}
