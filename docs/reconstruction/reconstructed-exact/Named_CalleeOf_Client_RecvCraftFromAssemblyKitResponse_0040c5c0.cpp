// =============================================================================
// Named_CalleeOf_Client_RecvCraftFromAssemblyKitResponse_0040c5c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0040c5c0
// Callee of Client_RecvCraftFromAssemblyKitResponse (+2 other named callers)
// Address:   0x0040c5c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_RecvCraftFromAssemblyKitResponse: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Client_RecvCraftFromAssemblyKitResponse (+2 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00404670, FUN_0040c5c0, FUN_0040c720.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Client_RecvCraftFromAssemblyKitResponse (+2 other named callers)
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

void __thiscall Named_CalleeOf_Client_RecvCraftFromAssemblyKitResponse_0040c5c0(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 4);

  if ((iVar1 != 0) &&

     ((uint)((*(int *)(param_1 + 8) - iVar1) / 0x98) <

      (uint)((*(int *)(param_1 + 0xc) - iVar1) / 0x98))) {

    iVar1 = *(int *)(param_1 + 8);

    FUN_00404670(iVar1,1,param_2,param_1,param_2);

    *(int *)(param_1 + 8) = iVar1 + 0x98;

    return;

  }

  FUN_0040c720(&param_2,*(uint32_t /* width from decompiler */ *)(param_1 + 8),param_2);

  return;

}
