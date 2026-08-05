// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0043e630
// -----------------------------------------------------------------------------
// Stable ID: aa_0043e630
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST
// Address:   0x0043e630  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×5, do×1, return×1, goto×1, while×1.
//  - Notable callees: EnterCriticalSection, FUN_0043df90, FUN_0043e630, LeaveCriticalSection.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST
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

uint8_t Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0043e630(int *param_1)



{

  int iVar1;

  uint uVar2;

  uint uVar3;

  uint8_t uVar4;

  uint uVar5;

  int unaff_ESI;

  uint8_t local_8 [8];

  

  if (*(char *)(unaff_ESI + 0x2c) != '\0') {

    EnterCriticalSection((LPCRITICAL_SECTION)(unaff_ESI + 0x14));

  }

  uVar3 = *(uint *)(unaff_ESI + 0xc);

  uVar4 = 0;

  uVar5 = *(int *)(unaff_ESI + 0x10) + uVar3;

  do {

    if (uVar3 == uVar5) {

LAB_0043e6aa:

      if (*(char *)(unaff_ESI + 0x2c) != '\0') {

        LeaveCriticalSection((LPCRITICAL_SECTION)(unaff_ESI + 0x14));

      }

      return uVar4;

    }

    uVar2 = uVar3 >> 2;

    iVar1 = uVar2 * -4;

    if (*(uint *)(unaff_ESI + 8) <= uVar2) {

      uVar2 = uVar2 - *(uint *)(unaff_ESI + 8);

    }

    if (*(int *)(*(int *)(*(int *)(unaff_ESI + 4) + uVar2 * 4) + (uVar3 + iVar1) * 4) == *param_1) {

      FUN_0043df90(local_8,unaff_ESI,uVar3,unaff_ESI,uVar3 + 1);

      uVar4 = 1;

      goto LAB_0043e6aa;

    }

    uVar3 = uVar3 + 1;

  } while( true );

}
