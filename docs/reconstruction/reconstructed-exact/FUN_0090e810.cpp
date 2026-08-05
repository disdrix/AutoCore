// =============================================================================
// FUN_0090e810
// -----------------------------------------------------------------------------
// Stable ID: aa_0090e810
// Address:   0x0090e810  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0090e810 @ 0x0090e810
// Stable ID: aa_0090e810
// Embedded strings (evidence for future rename):
//   - "HashError:TraversalLock, already locked for traversal"
//   - "VOG_DEBUG_STOP"
//   - "HashError:TraverseToNext, not locked for traversal"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: if×7, for×2, while×1, return×1.
//  - Notable callees: FUN_007a4480×4, FUN_0090e810.
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

void FUN_0090e810(int param_1,int param_2)



{

  char cVar1;

  int iVar2;

  int unaff_EBX;

  int iVar3;

  

  if ((&DAT_00d09a38)[unaff_EBX] != 0) {

    *(int *)((&DAT_00d09a38)[unaff_EBX] + 0x500) =

         *(int *)((&DAT_00d09a38)[unaff_EBX] + 0x500) + param_1;

    *(int *)((&DAT_00d09a38)[unaff_EBX] + 0x504) =

         *(int *)((&DAT_00d09a38)[unaff_EBX] + 0x504) + param_2;

    cVar1 = (**(code **)(*(int *)(&DAT_00d09a38)[unaff_EBX] + 0x3d8))();

    if (cVar1 != '\0') {

      iVar2 = *(int *)((&DAT_00d09a38)[unaff_EBX] + 0x534);

      iVar3 = 0;

      if (*(char *)(iVar2 + 0x1d) != '\0') {

        FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

        FUN_007a4480(0,"VOG_DEBUG_STOP");

      }

      *(uint8_t *)(iVar2 + 0x1d) = 1;

      while( true ) {

        iVar2 = *(int *)((&DAT_00d09a38)[unaff_EBX] + 0x534);

        if (*(char *)(iVar2 + 0x1d) == '\0') {

          FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

          FUN_007a4480(0,"VOG_DEBUG_STOP");

        }

        if (iVar3 == 0) {

          iVar3 = *(int *)(iVar2 + 0x14);

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

        (**(code **)(*(int *)(&DAT_00d09a38)[unaff_EBX] + 0x448))

                  (iVar2 + 8,*(uint32_t /* width from decompiler */ *)(iVar2 + 4));

      }

      *(uint8_t *)(*(int *)((&DAT_00d09a38)[unaff_EBX] + 0x534) + 0x1d) = 0;

    }

  }

  return;

}
