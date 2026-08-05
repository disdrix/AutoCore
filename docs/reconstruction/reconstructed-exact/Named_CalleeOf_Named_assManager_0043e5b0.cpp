// =============================================================================
// Named_CalleeOf_Named_assManager_0043e5b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0043e5b0
// Callee of Named_assManager
// Address:   0x0043e5b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_assManager: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×5, do×1, return×1, goto×1, while×1.
//  - Notable callees: EnterCriticalSection, FUN_0043e5b0, LeaveCriticalSection.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_assManager
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

uint8_t Named_CalleeOf_Named_assManager_0043e5b0(int *param_1)



{

  int iVar1;

  int in_EAX;

  uint uVar2;

  uint uVar3;

  uint8_t uVar4;

  uint uVar5;

  

  if (*(char *)(in_EAX + 0x2c) != '\0') {

    EnterCriticalSection((LPCRITICAL_SECTION)(in_EAX + 0x14));

  }

  uVar3 = *(uint *)(in_EAX + 0xc);

  uVar4 = 0;

  uVar5 = *(int *)(in_EAX + 0x10) + uVar3;

  do {

    if (uVar3 == uVar5) {

LAB_0043e614:

      if (*(char *)(in_EAX + 0x2c) != '\0') {

        LeaveCriticalSection((LPCRITICAL_SECTION)(in_EAX + 0x14));

      }

      return uVar4;

    }

    uVar2 = uVar3 >> 2;

    iVar1 = uVar2 * -4;

    if (*(uint *)(in_EAX + 8) <= uVar2) {

      uVar2 = uVar2 - *(uint *)(in_EAX + 8);

    }

    if (*(int *)(*(int *)(*(int *)(in_EAX + 4) + uVar2 * 4) + (uVar3 + iVar1) * 4) == *param_1) {

      uVar4 = 1;

      goto LAB_0043e614;

    }

    uVar3 = uVar3 + 1;

  } while( true );

}
