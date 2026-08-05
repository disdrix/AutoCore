// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_00971640
// -----------------------------------------------------------------------------
// Stable ID: aa_00971640
// Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP (+1 other named callers)
// Address:   0x00971640  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×3, for×1, return×1.
//  - Notable callees: FUN_0043d5e0, FUN_0043e4b0, FUN_0043e5b0, FUN_0044e8c0, FUN_00971640, SetEvent.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP (+1 other named callers)
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_00971640(int param_1)



{

  int iVar1;

  int iVar2;

  bool bVar3;

  char cVar4;

  uint uVar5;

  int unaff_ESI;

  uint uVar6;

  int local_10;

  int local_c [2];

  uint local_4;

  

  bVar3 = false;

  for (uVar6 = *(uint *)(unaff_ESI + 0xc); local_4 = uVar6,

      uVar6 != *(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0xc); uVar6 = uVar6 + 1) {

    uVar5 = uVar6 >> 2;

    iVar1 = uVar5 * -4;

    if (*(uint *)(unaff_ESI + 8) <= uVar5) {

      uVar5 = uVar5 - *(uint *)(unaff_ESI + 8);

    }

    iVar1 = *(int *)(*(int *)(unaff_ESI + 4) + uVar5 * 4) + (uVar6 + iVar1) * 4;

    FUN_0043d5e0();

    if ((local_10 == *(int *)(param_1 + 0x14)) &&

       (((iVar2 = *(int *)(param_1 + 0x110), FUN_0044e8c0(local_c),

         local_c[0] == *(int *)(iVar2 + 8) || (uVar6 = local_4, *(int *)(local_c[0] + 0xc) == 0)) &&

        (cVar4 = FUN_0043e5b0(iVar1), uVar6 = local_4, cVar4 == '\0')))) {

      bVar3 = true;

      FUN_0043e4b0(iVar1);

      uVar6 = local_4;

    }

  }

  if (bVar3) {

    SetEvent(*(HANDLE *)(param_1 + 4));

  }

  return;

}
