// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×5, return×3, for×1, do×1, goto×1, while×1.
//  - Notable callees: FUN_00411900×2, FUN_007a4480×2, FUN_0092fd00, FUN_009346e0.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP".
//  - Return sites: 3.

// =============================================================================
// Named_VOG_DEBUG_STOP_009346e0
// -----------------------------------------------------------------------------
// Stable ID: aa_009346e0
// Address:   0x009346e0  (autoassault.exe, image base 0x400000)
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

uint Named_VOG_DEBUG_STOP_009346e0(int param_1)



{

  int in_EAX;

  int iVar1;

  uint uVar2;

  int iVar3;

  uint32_t /* width from decompiler */ local_4;

  

  if (DAT_00d1b6d8 == 0) {

    return 0;

  }

  iVar1 = *(int *)(DAT_00d1b6d8 + 0x548);

  iVar3 = 0;

  local_4 = 0;

  if (*(char *)(iVar1 + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  *(uint8_t *)(iVar1 + 0x1d) = 1;

  iVar1 = FUN_00411900(&local_4);

  uVar2 = DAT_00d1b6d8;

  do {

    DAT_00d1b6d8 = uVar2;

    if (iVar1 == 0) {

LAB_0093476c:

      *(uint8_t *)(*(int *)(uVar2 + 0x548) + 0x1d) = 0;

      if (*(int *)(*(int *)(param_1 + 0x4d0) + 0x10) == iVar3) {

        return uVar2 & 0xffffff00;

      }

      uVar2 = FUN_0092fd00();

      return uVar2;

    }

    if ((*(int **)(iVar1 + 0x14c) != (int *)0x0) && (**(int **)(iVar1 + 0x14c) == in_EAX)) {

      iVar3 = *(int *)(iVar1 + 0x10);

      goto LAB_0093476c;

    }

    iVar1 = FUN_00411900(&local_4);

    uVar2 = DAT_00d1b6d8;

  } while( true );

}
