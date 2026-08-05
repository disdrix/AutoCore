// =============================================================================
// FUN_005afa60
// -----------------------------------------------------------------------------
// Stable ID: aa_005afa60
// Address:   0x005afa60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005afa60 @ 0x005afa60
// Stable ID: aa_005afa60
// Embedded strings (evidence for future rename):
//   - "CVOGVariableManager"
//   - "lNumberVars"
//   - "HashError:TraversalLock, already locked for traversal"
//   - "VOG_DEBUG_STOP"
//   - "HashError:TraverseToNext, not locked for traversal"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×5, for×2, while×1, return×1.
//  - Notable callees: FUN_007a4480×4, FUN_00498740, FUN_005af890, FUN_005afa60, FUN_0079d1e0, FUN_0079d290.
//  - Strings: "CVOGVariableManager"; "lNumberVars"; "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall FUN_005afa60(int param_1,uint32_t /* width from decompiler */ param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  int iVar3;

  

  uVar1 = param_2;

  FUN_0079d290(1,"CVOGVariableManager");

  param_2 = *(uint32_t /* width from decompiler */ *)(param_1 + 0xc);

  FUN_00498740("lNumberVars",&param_2);

  iVar3 = 0;

  if (*(char *)(param_1 + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  *(uint8_t *)(param_1 + 0x1d) = 1;

  while( true ) {

    if (*(char *)(param_1 + 0x1d) == '\0') {

      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    if (iVar3 == 0) {

      iVar3 = *(int *)(param_1 + 0x14);

    }

    else {

      iVar3 = *(int *)(iVar3 + 0x14);

    }

    if (iVar3 == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = *(int *)(iVar3 + 8);

    }

    if (iVar2 == 0) break;

    FUN_005af890(uVar1,iVar2);

  }

  *(uint8_t *)(param_1 + 0x1d) = 0;

  FUN_0079d1e0();

  return;

}
