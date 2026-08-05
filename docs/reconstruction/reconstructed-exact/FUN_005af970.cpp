// =============================================================================
// FUN_005af970
// -----------------------------------------------------------------------------
// Stable ID: aa_005af970
// Address:   0x005af970  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005af970 @ 0x005af970
// Stable ID: aa_005af970
// Embedded strings (evidence for future rename):
//   - "HashError:TraversalLock, already locked for traversal"
//   - "VOG_DEBUG_STOP"
//   - "HashError:TraverseToNext, not locked for traversal"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×5, for×2, while×1, return×1.
//  - Notable callees: fwrite×7, FUN_007a4480×4, FUN_005af970.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal".
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

void __thiscall FUN_005af970(int param_1,FILE *param_2)



{

  int iVar1;

  void *_Str;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = *(uint32_t /* width from decompiler */ *)(param_1 + 0xc);

  fwrite(&local_4,4,1,param_2);

  iVar1 = 0;

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

    if (iVar1 == 0) {

      iVar1 = *(int *)(param_1 + 0x14);

    }

    else {

      iVar1 = *(int *)(iVar1 + 0x14);

    }

    if (iVar1 == 0) {

      _Str = (void *)0x0;

    }

    else {

      _Str = *(void **)(iVar1 + 8);

    }

    if (_Str == (void *)0x0) break;

    fwrite((void *)((int)_Str + 0x44),4,1,param_2);

    fwrite((void *)((int)_Str + 0x40),1,1,param_2);

    fwrite((void *)((int)_Str + 0x48),4,1,param_2);

    fwrite((void *)((int)_Str + 0x4c),4,1,param_2);

    fwrite((void *)((int)_Str + 0x50),1,1,param_2);

    fwrite(_Str,1,0x40,param_2);

  }

  *(uint8_t *)(param_1 + 0x1d) = 0;

  return;

}
