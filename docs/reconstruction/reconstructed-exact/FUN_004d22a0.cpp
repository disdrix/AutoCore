// =============================================================================
// FUN_004d22a0
// -----------------------------------------------------------------------------
// Stable ID: aa_004d22a0
// Address:   0x004d22a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004d22a0 @ 0x004d22a0
// Stable ID: aa_004d22a0
// Embedded strings (evidence for future rename):
//   - "HashError:TraversalLock, already locked for traversal"
//   - "VOG_DEBUG_STOP"
//   - "HashError:TraverseToNext, not locked for traversal"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~55 non-empty decompiler lines.
//  - Control keywords: if×10, while×2, for×2, do×1, return×1.
//  - Notable callees: FUN_007a4480×4, FUN_004d22a0.
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

void __fastcall FUN_004d22a0(int param_1)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  uint32_t /* width from decompiler */ *puVar4;

  

  puVar4 = *(uint32_t /* width from decompiler */ **)(param_1 + 0xe52c);

  if (puVar4 != *(uint32_t /* width from decompiler */ **)(param_1 + 0xe530)) {

    do {

      piVar3 = (int *)*puVar4;

      iVar1 = (**(code **)(*piVar3 + 0x20))();

      if (iVar1 != 0) {

        (**(code **)(*piVar3 + 0x78))();

        if (*(char *)(param_1 + 0x7d) != '\0') {

          (**(code **)(*piVar3 + 0x84))();

        }

      }

      puVar4 = puVar4 + 1;

    } while (puVar4 != *(uint32_t /* width from decompiler */ **)(param_1 + 0xe530));

  }

  iVar1 = 0;

  if (*(char *)(param_1 + 0xe575) != '\0') {

    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  *(uint8_t *)(param_1 + 0xe575) = 1;

  while( true ) {

    if (*(char *)(param_1 + 0xe575) == '\0') {

      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    if (iVar1 == 0) {

      iVar1 = *(int *)(param_1 + 0xe56c);

    }

    else {

      iVar1 = *(int *)(iVar1 + 0x14);

    }

    if (iVar1 == 0) {

      piVar3 = (int *)0x0;

    }

    else {

      piVar3 = *(int **)(iVar1 + 8);

    }

    if (piVar3 == (int *)0x0) break;

    iVar2 = (**(code **)(*piVar3 + 0x20))();

    if (iVar2 == 0) {

      (**(code **)(*piVar3 + 0x78))();

      if (*(char *)(param_1 + 0x7d) != '\0') {

        (**(code **)(*piVar3 + 0x84))();

      }

    }

  }

  *(uint8_t *)(param_1 + 0xe575) = 0;

  return;

}
