// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005f2d70
// -----------------------------------------------------------------------------
// Stable ID: aa_005f2d70
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x005f2d70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×4, return×3, do×2, while×2.
//  - Notable callees: FUN_005f2d70.
//  - Return sites: 3.

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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005f2d70(void)



{

  char cVar1;

  int iVar2;

  int iVar3;

  int *unaff_EDI;

  uint8_t *puStack_4c;

  uint32_t /* width from decompiler */ uStack_48;

  uint32_t /* width from decompiler */ auStack_44 [17];

  

  auStack_44[0] = 0x40;

  uStack_48 = 0x5f2d7c;

  (**(code **)(*unaff_EDI + 0x14))();

  uStack_48 = 0x40;

  puStack_4c = (uint8_t *)auStack_44;

  iVar2 = (**(code **)(*unaff_EDI + 8))();

  if (iVar2 == 0) {

    return;

  }

  do {

    iVar3 = 0;

    if (0 < iVar2) {

      do {

        cVar1 = *(char *)((int)&puStack_4c + iVar3);

        if ((((cVar1 != ' ') && (cVar1 != '\t')) && (cVar1 != '\r')) && (cVar1 != '\n')) {

          (**(code **)(*unaff_EDI + 0x18))();

          (**(code **)(*unaff_EDI + 0xc))(iVar3);

          return;

        }

        iVar3 = iVar3 + 1;

      } while (iVar3 < iVar2);

    }

    (**(code **)(*unaff_EDI + 0x14))(0x40);

    iVar2 = (**(code **)(*unaff_EDI + 8))(&stack0xffffffb0,0x40);

    if (iVar2 == 0) {

      return;

    }

  } while( true );

}
