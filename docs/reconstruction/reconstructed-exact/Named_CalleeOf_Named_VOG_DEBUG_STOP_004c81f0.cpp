// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_004c81f0
// -----------------------------------------------------------------------------
// Stable ID: aa_004c81f0
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x004c81f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×2, for×1, return×1.
//  - Notable callees: FUN_004c81f0, FUN_004d0e90, Object_ResolveFromTFID.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP
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

void __fastcall Named_CalleeOf_Named_VOG_DEBUG_STOP_004c81f0(int param_1)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  uint uVar4;

  

  iVar3 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1);

  if ((iVar3 != 0) && (*(char *)(iVar3 + 0x7e) != '\0')) {

    iVar3 = 0;

    for (uVar4 = 0;

        (iVar2 = *(int *)(param_1 + 0x1bc), iVar2 != 0 &&

        (uVar4 < (uint)(*(int *)(param_1 + 0x1c0) - iVar2 >> 4))); uVar4 = uVar4 + 1) {

      piVar1 = Object_ResolveFromTFID((TFID_16 *)(iVar2 + iVar3));

      if ((piVar1 != (int *)0x0) &&

         ((iVar2 = (**(code **)(*piVar1 + 0x214))(), iVar2 != 0 &&

          (g_flZero < *(float *)(iVar2 + 0x310))))) {

        piVar1[0x33] = 1;

        FUN_004d0e90(piVar1);

      }

      iVar3 = iVar3 + 0x10;

    }

  }

  return;

}
