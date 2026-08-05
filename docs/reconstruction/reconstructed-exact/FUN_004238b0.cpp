// =============================================================================
// FUN_004238b0
// -----------------------------------------------------------------------------
// Stable ID: aa_004238b0
// Address:   0x004238b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004238b0 @ 0x004238b0
// Stable ID: aa_004238b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×4, return×3.
//  - Notable callees: FUN_004048e0, FUN_004238b0, LOCK, UNLOCK.
//  - Return sites: 3.

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

void FUN_004238b0(void)



{

  uint32_t /* width from decompiler */ *puVar1;

  int *piVar2;

  int *piVar3;

  int iVar4;

  int *unaff_ESI;

  

  iVar4 = *unaff_ESI;

  puVar1 = (uint32_t /* width from decompiler */ *)(iVar4 + -0x10);

  piVar3 = (int *)*puVar1;

  if (*(int *)(iVar4 + -0xc) != 0) {

    piVar2 = (int *)(iVar4 + -4);

    if (*(int *)(iVar4 + -4) < 0) {

      if (*(int *)(iVar4 + -8) < 0) {

                    /* WARNING: Subroutine does not return */

        FUN_004048e0(0x80070057);

      }

      *(uint32_t /* width from decompiler */ *)(iVar4 + -0xc) = 0;

      *(uint16_t *)*unaff_ESI = 0;

      return;

    }

    LOCK();

    iVar4 = *piVar2;

    *piVar2 = *piVar2 + -1;

    UNLOCK();

    if (iVar4 == 1 || iVar4 + -1 < 0) {

      (**(code **)(*(int *)*puVar1 + 4))(puVar1);

    }

    iVar4 = (**(code **)(*piVar3 + 0xc))();

    *unaff_ESI = iVar4 + 0x10;

  }

  return;

}
