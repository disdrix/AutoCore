// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_0092cc60
// -----------------------------------------------------------------------------
// Stable ID: aa_0092cc60
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x0092cc60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: CONCAT22, FUN_0092cc60.
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

void Named_CalleeOf_Named_VOG_DEBUG_STOP_0092cc60(void)



{

  uint16_t uVar1;

  uint16_t uVar2;

  int unaff_ESI;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  uVar1 = *(uint16_t *)(unaff_ESI + 0x302c);

  uVar2 = *(uint16_t *)(unaff_ESI + 0x3030);

  if (*(int *)(unaff_ESI + 0x1168) != 0) {

    local_8 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x302c);

    local_4 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x3030);

    (**(code **)(**(int **)(unaff_ESI + 0x1168) + 0x118))(&local_8);

  }

  if (*(int *)(unaff_ESI + 0xf40) != 0) {

    if ((*(int *)(unaff_ESI + 0x1ac) < *(int *)(unaff_ESI + 0x302c)) &&

       (*(int *)(unaff_ESI + 0x302c) < *(int *)(unaff_ESI + 0x3198) - *(int *)(unaff_ESI + 0x1ac)))

    {

      (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0xf40) + 0x458))();

    }

    if ((*(int *)(unaff_ESI + 0x1ac) < *(int *)(unaff_ESI + 0x3030)) &&

       (*(int *)(unaff_ESI + 0x3030) < *(int *)(unaff_ESI + 0x319c) - *(int *)(unaff_ESI + 0x1ac)))

    {

      (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0xf40) + 0x45c))();

    }

    (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0xf40) + 0x368))(0,CONCAT22(uVar2,uVar1));

  }

  return;

}
