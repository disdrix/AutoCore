// READABILITY (auto CF):
//  - Body size: ~55 non-empty decompiler lines.
//  - Control keywords: if×8, for×2, while×2, return×1.
//  - Notable callees: FUN_007a4480×4, FUN_004113b0×2, FUN_00410d60, FUN_004294f0, FUN_0082ce20, LeaveCriticalSection.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal".
//  - Return sites: 1.

// =============================================================================
// Named_VOG_DEBUG_STOP_0082ce20
// -----------------------------------------------------------------------------
// Stable ID: aa_0082ce20
// Address:   0x0082ce20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOG_DEBUG_STOP"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Named_VOG_DEBUG_STOP_0082ce20(int *param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  iVar1 = param_1[0x14d];

  if (iVar1 != 0) {

    iVar3 = 0;

    local_4 = 0;

    if (*(char *)(iVar1 + 0x1d) != '\0') {

      FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    *(uint8_t *)(iVar1 + 0x1d) = 1;

    while( true ) {

      iVar1 = param_1[0x14d];

      if (*(char *)(iVar1 + 0x1d) == '\0') {

        FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

        FUN_007a4480(0,"VOG_DEBUG_STOP");

      }

      if (iVar3 == 0) {

        iVar3 = *(int *)(iVar1 + 0x14);

      }

      else {

        iVar3 = *(int *)(iVar3 + 0x14);

      }

      if (iVar3 == 0) {

        iVar1 = 0;

      }

      else {

        iVar1 = *(int *)(iVar3 + 8);

      }

      if (iVar1 == 0) break;

      FUN_004294f0();

      iVar2 = FUN_004113b0(iVar1 + 8,&local_8);

      while (iVar2 == 0) {

        (**(code **)(*param_1 + 0xbc))(local_8);

        iVar2 = FUN_004113b0(iVar1 + 8,&local_8);

      }

      if (*(char *)(iVar1 + 0x30) != '\0') {

        *(uint8_t *)(iVar1 + 0x30) = 0;

        LeaveCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0xc));

      }

      FUN_00410d60();

    }

    *(uint8_t *)(param_1[0x14d] + 0x1d) = 0;

    if ((uint32_t /* width from decompiler */ *)param_1[0x14d] != (uint32_t /* width from decompiler */ *)0x0) {

      (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x14d])(1);

    }

    param_1[0x14d] = 0;

  }

  return;

}
