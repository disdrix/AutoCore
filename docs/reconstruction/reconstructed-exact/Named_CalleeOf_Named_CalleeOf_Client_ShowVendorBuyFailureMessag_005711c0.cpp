// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_ShowVendorBuyFailureMessag_005711c0
// -----------------------------------------------------------------------------
// Stable ID: aa_005711c0
// Callee of Named_CalleeOf_Client_ShowVendorBuyFailureMessage (+1 other named callers)
// Address:   0x005711c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_ShowVendorBuyFailureMessage: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Client_ShowVendorBuyFailureMessage (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×2, while×1, return×1.
//  - Notable callees: FUN_004022a0×2, FUN_004294f0, FUN_005711c0, LeaveCriticalSection.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_ShowVendorBuyFailureMessage (+1 other named callers)
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

int __thiscall Named_CalleeOf_Named_CalleeOf_Client_ShowVendorBuyFailureMessag_005711c0(int param_1,int param_2,char param_3)



{

  int iVar1;

  int iVar2;

  int *local_8;

  uint32_t /* width from decompiler */ local_4;

  

  iVar2 = 0;

  local_4 = 0;

  FUN_004294f0();

  iVar1 = FUN_004022a0(&local_4,&local_8);

  while (iVar1 == 0) {

    if (((local_8 != (int *)0x0) && (*(int *)(local_8[0x2a] + 0x34) == param_2)) &&

       ((param_3 != '\0' || (((uint)local_8[0x5f] >> 0x13 & 1) == 0)))) {

      iVar1 = (**(code **)(*local_8 + 0x25c))();

      iVar2 = iVar2 + iVar1;

    }

    iVar1 = FUN_004022a0(&local_4,&local_8);

  }

  if (*(char *)(param_1 + 0x54) != '\0') {

    *(uint8_t *)(param_1 + 0x54) = 0;

    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));

  }

  return iVar2;

}
