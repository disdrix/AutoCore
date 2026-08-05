// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvLoginCa_00976390
// -----------------------------------------------------------------------------
// Stable ID: aa_00976390
// Callee of Named_CalleeOf_Named_CalleeOf_Client_RecvLoginCallback_3
// Address:   0x00976390  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_RecvLoginCallback_3: auth/session helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: return×3, if×2, for×1.
//  - Notable callees: FUN_00976390.
//  - Return sites: 3.

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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvLoginCa_00976390(void)



{

  int iVar1;

  uint uVar2;

  int unaff_ESI;

  int iVar3;

  

  iVar3 = 0;

  for (uVar2 = 0;

      (*(int *)(unaff_ESI + 0x6c) != 0 &&

      (uVar2 < (uint)((*(int *)(unaff_ESI + 0x70) - *(int *)(unaff_ESI + 0x6c)) / 0x28)));

      uVar2 = uVar2 + 1) {

    iVar1 = *(int *)(unaff_ESI + 0x6c) + iVar3;

    if (*(int *)(iVar1 + 0x24) != 0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(*(void **)(iVar1 + 0x24));

    }

    *(uint32_t /* width from decompiler */ *)(*(int *)(unaff_ESI + 0x6c) + iVar3 + 0x24) = 0;

    iVar3 = iVar3 + 0x28;

  }

  if (*(void **)(unaff_ESI + 0x6c) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(unaff_ESI + 0x6c));

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x6c) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x70) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x74) = 0;

  return;

}
