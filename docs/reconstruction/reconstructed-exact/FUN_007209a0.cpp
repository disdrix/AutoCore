// =============================================================================
// FUN_007209a0
// -----------------------------------------------------------------------------
// Stable ID: aa_007209a0
// Address:   0x007209a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007209a0 @ 0x007209a0
// Stable ID: aa_007209a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: for×2, if×1, do×1, while×1, return×1.
//  - Notable callees: FUN_007209a0.
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

uint32_t /* width from decompiler */ FUN_007209a0(uint8_t param_1)



{

  char cVar1;

  char *in_EAX;

  int iVar2;

  int unaff_EBX;

  char *pcVar3;

  uint32_t /* width from decompiler */ *puVar4;

  char local_d0 [148];

  float local_3c;

  uint8_t local_2c;

  uint8_t local_2b;

  uint32_t /* width from decompiler */ local_18;

  

  if (*(char *)(unaff_EBX + 0x10) != '\0') {

    pcVar3 = local_d0;

    for (iVar2 = 0x32; iVar2 != 0; iVar2 = iVar2 + -1) {

      pcVar3[0] = '\0';

      pcVar3[1] = '\0';

      pcVar3[2] = '\0';

      pcVar3[3] = '\0';

      pcVar3 = pcVar3 + 4;

    }

    local_2b = param_1;

    local_18 = 3;

    local_2c = 0;

    local_3c = g_flOne;

    iVar2 = -(int)in_EAX;

    do {

      cVar1 = *in_EAX;

      in_EAX[(int)(local_d0 + iVar2)] = cVar1;

      in_EAX = in_EAX + 1;

    } while (cVar1 != '\0');

    pcVar3 = local_d0;

    puVar4 = (uint32_t /* width from decompiler */ *)(unaff_EBX + 0x90);

    for (iVar2 = 0x32; iVar2 != 0; iVar2 = iVar2 + -1) {

      *puVar4 = *(uint32_t /* width from decompiler */ *)pcVar3;

      pcVar3 = pcVar3 + 4;

      puVar4 = puVar4 + 1;

    }

    *(uint8_t *)(unaff_EBX + 0x12) = 1;

    *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x148) = 3;

    *(uint8_t *)(unaff_EBX + 0x134) = 0;

    *(uint8_t *)(unaff_EBX + 0x16) = 1;

  }

  return 0;

}
