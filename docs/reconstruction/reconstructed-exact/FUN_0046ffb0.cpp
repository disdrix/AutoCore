// =============================================================================
// FUN_0046ffb0
// -----------------------------------------------------------------------------
// Stable ID: aa_0046ffb0
// Address:   0x0046ffb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0046ffb0 @ 0x0046ffb0
// Stable ID: aa_0046ffb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: if×6, return×4, do×1, while×1.
//  - Notable callees: FUN_00476d60×2, FUN_0046ffb0, FUN_004766e0, FUN_00476cc0, malloc.
//  - Return sites: 4.

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

void FUN_0046ffb0(int param_1)



{

  uint uVar1;

  uint32_t /* width from decompiler */ uVar2;

  int in_EAX;

  void *pvVar3;

  int iVar4;

  int unaff_EDI;

  

  if ((in_EAX != 0) && (unaff_EDI != 0)) {

    if (*(short *)(unaff_EDI + 0x14) == 0) {

      FUN_00476d60();

      return;

    }

    FUN_004766e0();

    uVar1 = *(uint *)(in_EAX + 0x6c);

    *(uint *)(in_EAX + 0x6c) = uVar1 | 0x100000;

    if (*(code **)(in_EAX + 0x248) == (code *)0x0) {

      pvVar3 = malloc(0x200);

    }

    else {

      pvVar3 = (void *)(**(code **)(in_EAX + 0x248))();

    }

    if ((pvVar3 == (void *)0x0) && ((*(byte *)(in_EAX + 0x6e) & 0x10) == 0)) {

                    /* WARNING: Subroutine does not return */

      FUN_00476cc0();

    }

    *(uint *)(in_EAX + 0x6c) = uVar1;

    *(void **)(in_EAX + 500) = pvVar3;

    if (pvVar3 == (void *)0x0) {

      FUN_00476d60();

      return;

    }

    iVar4 = 0;

    if (*(short *)(unaff_EDI + 0x14) != 0) {

      do {

        *(uint16_t *)(*(int *)(in_EAX + 500) + iVar4 * 2) = *(uint16_t *)(param_1 + iVar4 * 2);

        iVar4 = iVar4 + 1;

      } while (iVar4 < (int)(uint)*(ushort *)(unaff_EDI + 0x14));

    }

    uVar2 = *(uint32_t /* width from decompiler */ *)(in_EAX + 500);

    *(uint *)(unaff_EDI + 8) = *(uint *)(unaff_EDI + 8) | 0x40;

    *(uint *)(unaff_EDI + 0xb8) = *(uint *)(unaff_EDI + 0xb8) | 8;

    *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x7c) = uVar2;

  }

  return;

}
