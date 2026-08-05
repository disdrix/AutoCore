// =============================================================================
// FUN_0094c730
// -----------------------------------------------------------------------------
// Stable ID: aa_0094c730
// Address:   0x0094c730  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0094c730 @ 0x0094c730
// Stable ID: aa_0094c730
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~65 non-empty decompiler lines.
//  - Control keywords: do×4, while×4, if×3, return×1.
//  - Notable callees: FUN_0079d560×7, FUN_008073b0, FUN_0094c730.
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

void FUN_0094c730(void)



{

  int *piVar1;

  char cVar2;

  int in_EAX;

  char *pcVar3;

  char *pcVar4;

  uint32_t /* width from decompiler */ auStack_1e8 [14];

  char acStack_1ad [251];

  char acStack_b2 [51];

  char acStack_7f [51];

  char acStack_4c [52];

  uint32_t /* width from decompiler */ uStack_18;

  

  piVar1 = *(int **)(in_EAX + 0x106c);

  if (piVar1 != (int *)0x0) {

    cVar2 = (**(code **)(*piVar1 + 0x3d8))();

    if (cVar2 != '\0') {

      auStack_1e8[0] = 0x8041;

      pcVar3 = (char *)(**(code **)(*(int *)piVar1[0x15a] + 0x1dc))();

      pcVar4 = acStack_1ad;

      do {

        cVar2 = *pcVar3;

        *pcVar4 = cVar2;

        pcVar3 = pcVar3 + 1;

        pcVar4 = pcVar4 + 1;

      } while (cVar2 != '\0');

      pcVar3 = (char *)(**(code **)(*(int *)piVar1[0x15f] + 0x1dc))();

      pcVar4 = acStack_b2;

      do {

        cVar2 = *pcVar3;

        *pcVar4 = cVar2;

        pcVar3 = pcVar3 + 1;

        pcVar4 = pcVar4 + 1;

      } while (cVar2 != '\0');

      pcVar3 = (char *)(**(code **)(*(int *)piVar1[0x160] + 0x1dc))();

      pcVar4 = acStack_7f;

      do {

        cVar2 = *pcVar3;

        *pcVar4 = cVar2;

        pcVar3 = pcVar3 + 1;

        pcVar4 = pcVar4 + 1;

      } while (cVar2 != '\0');

      pcVar3 = (char *)(**(code **)(*(int *)piVar1[0x161] + 0x1dc))();

      pcVar4 = acStack_4c;

      do {

        cVar2 = *pcVar3;

        *pcVar4 = cVar2;

        pcVar3 = pcVar3 + 1;

        pcVar4 = pcVar4 + 1;

      } while (cVar2 != '\0');

      if (*(int *)(in_EAX + 0x3088) != 0) {

        FUN_0079d560(*(int *)(in_EAX + 0x3088),acStack_1ad);

        FUN_0079d560(*(uint32_t /* width from decompiler */ *)(in_EAX + 0x3088),acStack_b2);

        FUN_0079d560(*(uint32_t /* width from decompiler */ *)(in_EAX + 0x3088),acStack_7f);

        FUN_0079d560(*(uint32_t /* width from decompiler */ *)(in_EAX + 0x3088),acStack_4c);

        FUN_0079d560(*(uint32_t /* width from decompiler */ *)(in_EAX + 0x308c),acStack_b2);

        FUN_0079d560(*(uint32_t /* width from decompiler */ *)(in_EAX + 0x308c),acStack_7f);

        FUN_0079d560(*(uint32_t /* width from decompiler */ *)(in_EAX + 0x308c),acStack_4c);

      }

      uStack_18 = *(uint32_t /* width from decompiler */ *)(*(int *)(in_EAX + 0x31f0) + 0x1cc);

      FUN_008073b0(0x1e8,auStack_1e8);

    }

  }

  return;

}
