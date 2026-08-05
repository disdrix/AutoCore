// =============================================================================
// FUN_008e40f0
// -----------------------------------------------------------------------------
// Stable ID: aa_008e40f0
// Address:   0x008e40f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008e40f0 @ 0x008e40f0
// Stable ID: aa_008e40f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×5, do×2, goto×2, while×2, return×1.
//  - Notable callees: FUN_005710c0×2, FUN_008e40f0.
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

void FUN_008e40f0(void)



{

  int in_EAX;

  int iVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int *piVar5;

  

  piVar5 = (int *)(in_EAX + 0x61c);

  puVar4 = (uint32_t /* width from decompiler */ *)(in_EAX + 0x680);

  iVar3 = 5;

  do {

    iVar2 = 5;

    do {

      if (*piVar5 == 0) {

LAB_008e4185:

        *puVar4 = 0xffffffff;

        puVar4[1] = 0xffffffff;

      }

      else {

        iVar1 = FUN_005710c0(*(uint32_t /* width from decompiler */ *)(*(int *)(*piVar5 + 0xa8) + 0x34),0,0);

        if (iVar1 == 0) {

          if (*(char *)(DAT_00d1b644 + 0xf5) != '\0') {

            iVar1 = FUN_005710c0(*(uint32_t /* width from decompiler */ *)(*(int *)(*piVar5 + 0xa8) + 0x34),0,0);

            if (iVar1 != 0) goto LAB_008e4172;

          }

          goto LAB_008e4185;

        }

LAB_008e4172:

        *puVar4 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x160);

        puVar4[1] = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x164);

      }

      piVar5 = piVar5 + 1;

      puVar4 = puVar4 + 2;

      iVar2 = iVar2 + -1;

    } while (iVar2 != 0);

    iVar3 = iVar3 + -1;

    if (iVar3 == 0) {

      return;

    }

  } while( true );

}
