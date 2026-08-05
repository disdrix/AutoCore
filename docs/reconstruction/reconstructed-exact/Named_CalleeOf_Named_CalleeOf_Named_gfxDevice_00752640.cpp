// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_gfxDevice_00752640
// -----------------------------------------------------------------------------
// Stable ID: aa_00752640
// Callee of Named_CalleeOf_Named_gfxDevice
// Address:   0x00752640  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_gfxDevice: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: for×1, if×1, return×1.
//  - Notable callees: FUN_00752640.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_gfxDevice
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

void Named_CalleeOf_Named_CalleeOf_Named_gfxDevice_00752640(void)



{

  int iVar1;

  int *piVar2;

  int unaff_EBX;

  int *piVar3;

  int iVar4;

  

  iVar1 = *(int *)(*(int *)(unaff_EBX + 8) + 0x18);

  for (iVar4 = *(int *)(*(int *)(unaff_EBX + 8) + 0x14); iVar4 < iVar1; iVar4 = iVar4 + 1) {

    piVar3 = (int *)((uint)*(ushort *)(*(int *)(*(int *)(unaff_EBX + 8) + 0x10) + 4 + iVar4 * 8) +

                    *(int *)(unaff_EBX + 0xc));

    if ((((piVar3 != (int *)0x0) && (piVar3[1] != 0)) && (*(int *)(piVar3[1] + 0x30) == 0)) &&

       (piVar2 = (int *)*piVar3, piVar2 != (int *)0x0)) {

      (**(code **)(*piVar2 + 8))(piVar2);

      *piVar3 = 0;

    }

  }

  return;

}
