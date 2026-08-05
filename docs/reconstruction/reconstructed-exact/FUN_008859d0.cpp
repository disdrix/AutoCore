// =============================================================================
// FUN_008859d0
// -----------------------------------------------------------------------------
// Stable ID: aa_008859d0
// Address:   0x008859d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008859d0 @ 0x008859d0
// Stable ID: aa_008859d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, return×1.
//  - Notable callees: CNDHash_LookupByKey, FUN_008859d0.
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

void FUN_008859d0(void)



{

  int *piVar1;

  void *pvVar2;

  int iVar3;

  int *piVar4;

  int unaff_ESI;

  

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x530) = DAT_00aaa688;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x534) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x53c) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x540) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x518) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x528) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x52c) = 0;

  *(uint8_t *)(unaff_ESI + 0x547) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x51c) = 0;

  *(uint8_t *)(unaff_ESI + 0x514) = 0;

  *(uint8_t *)(unaff_ESI + 0x546) = 0;

  if ((((DAT_00d1b6d8 != 0) && (*(int *)(DAT_00d1b6d8 + 0x250) != 0)) &&

      (*(char *)(DAT_00d1b6d8 + 0x30c) != '\0')) &&

     (pvVar2 = CNDHash_LookupByKey(*(void **)(DAT_00d1b6d8 + 0x548),*(uint *)(DAT_00d1b6d8 + 0xd70))

     , pvVar2 != (void *)0x0)) {

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x540) = **(uint32_t /* width from decompiler */ **)((int)pvVar2 + 0x14c);

    piVar4 = *(int **)((int)pvVar2 + 0x158);

    if (piVar4 != *(int **)((int)pvVar2 + 0x15c)) {

      do {

        piVar1 = (int *)*piVar4;

        iVar3 = (**(code **)(*piVar1 + 0x50))();

        if (iVar3 == 0xe) {

          iVar3 = piVar1[0x19];

          *(char *)(unaff_ESI + 0x544) = (char)iVar3;

          *(char *)(unaff_ESI + 0x545) = (char)piVar1[0x1b];

          if ((char)iVar3 != '\0') {

            *(int *)(unaff_ESI + 0x538) = piVar1[0x1a];

          }

        }

        piVar4 = piVar4 + 1;

      } while (piVar4 != *(int **)((int)pvVar2 + 0x15c));

    }

  }

  return;

}
