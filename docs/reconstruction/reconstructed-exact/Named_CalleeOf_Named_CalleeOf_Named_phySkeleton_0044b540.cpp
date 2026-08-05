// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_phySkeleton_0044b540
// -----------------------------------------------------------------------------
// Stable ID: aa_0044b540
// Callee of Named_CalleeOf_Named_phySkeleton
// Address:   0x0044b540  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_phySkeleton: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: FUN_0044b540, FUN_00972cc0, _aligned_malloc.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_phySkeleton
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

void * Named_CalleeOf_Named_CalleeOf_Named_phySkeleton_0044b540(size_t param_1)



{

  int in_EAX;

  void *pvVar1;

  int extraout_EDX;

  int iVar2;

  

  if (in_EAX != 0) {

    pvVar1 = _aligned_malloc(in_EAX * 0x160,param_1);

    if (in_EAX != 0) {

      iVar2 = (int)pvVar1 + 0x30;

      do {

        if (iVar2 != 0x30) {

          *(undefined ***)(iVar2 + -0x30) = &PTR_LAB_00aa04e8;

          FUN_00972cc0();

          *(uint32_t /* width from decompiler */ *)(extraout_EDX + 0xc4) = 0;

          *(undefined ***)(extraout_EDX + 0xc0) = &PTR_FUN_00aa0504;

          *(uint32_t /* width from decompiler */ *)(extraout_EDX + 0x110) = 0xffffffff;

          iVar2 = extraout_EDX;

        }

        iVar2 = iVar2 + 0x160;

        in_EAX = in_EAX + -1;

      } while (in_EAX != 0);

    }

    return pvVar1;

  }

  return (void *)0x0;

}
