// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0068ba40
// -----------------------------------------------------------------------------
// Stable ID: aa_0068ba40
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x0068ba40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, goto×1, return×1, while×1.
//  - Notable callees: FUN_0068ba40.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0068ba40(int param_1,ushort param_2)



{

  int iVar1;

  uint uVar2;

  int iVar3;

  

  iVar3 = 0;

  do {

    if ((short)param_2 < 0) {

LAB_0068ba78:

      uVar2 = 0;

    }

    else {

      iVar1 = *(int *)((short)param_2 * 0x10 + 4 + *(int *)(param_1 + 0x44));

      if (iVar1 == 0) goto LAB_0068ba78;

      uVar2 = *(int *)((short)param_2 * 0x10 + *(int *)(param_1 + 0x44) + 8) - iVar1 >> 2;

    }

    if ((int)(uVar2 & 0xffff) <= iVar3) {

      return;

    }

    operator_delete__(*(void **)(*(int *)(*(int *)(param_1 + 0x44) + (uint)param_2 * 0x10 + 4) +

                                iVar3 * 4));

    *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 0x44) + (uint)param_2 * 0x10 + 4) + iVar3 * 4) = 0;

    iVar3 = iVar3 + 1;

  } while( true );

}
