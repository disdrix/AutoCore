// =============================================================================
// FUN_00415a20
// -----------------------------------------------------------------------------
// Stable ID: aa_00415a20
// Address:   0x00415a20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00415a20 @ 0x00415a20
// Stable ID: aa_00415a20
// Embedded strings (evidence for future rename):
//   - "VOG_DEBUG_STOP"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, do×1, while×1.
//  - Notable callees: FUN_00415a20, FUN_007a4480, _CxxThrowException, malloc.
//  - Strings: "VOG_DEBUG_STOP".
//  - Return sites: 2.

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

void FUN_00415a20(void)



{

  uint32_t /* width from decompiler */ *puVar1;

  void *pvVar2;

  uint uVar3;

  int unaff_ESI;

  uint32_t /* width from decompiler */ local_4;

  

  if (('\0' < *(char *)(unaff_ESI + 0x1c)) && (*(char *)(unaff_ESI + 0x1c) < '\x11')) {

    pvVar2 = operator_new__(*(int *)(unaff_ESI + 8) * 4);

    *(void **)(unaff_ESI + 0x10) = pvVar2;

    pvVar2 = malloc(*(int *)(unaff_ESI + 8) * 0xc);

    uVar3 = 0;

    if (*(int *)(unaff_ESI + 8) != 0) {

      do {

        *(void **)(*(int *)(unaff_ESI + 0x10) + uVar3 * 4) = pvVar2;

        puVar1 = *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_ESI + 0x10) + uVar3 * 4);

        uVar3 = uVar3 + 1;

        *puVar1 = &PTR_LAB_00a6d1a0;

        puVar1[1] = 0;

        puVar1[2] = 0;

        pvVar2 = (void *)((int)pvVar2 + 0xc);

      } while (uVar3 < *(uint *)(unaff_ESI + 8));

    }

    *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + -1;

    return;

  }

  FUN_007a4480(0,"VOG_DEBUG_STOP");

  local_4 = 0x80004003;

                    /* WARNING: Subroutine does not return */

  _CxxThrowException(&local_4,(ThrowInfo *)&DAT_00acc430);

}
