// =============================================================================
// FUN_008011e0
// -----------------------------------------------------------------------------
// Stable ID: aa_008011e0
// Address:   0x008011e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008011e0 @ 0x008011e0
// Stable ID: aa_008011e0
// Embedded strings (evidence for future rename):
//   - "Convoy invitation sent to "
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~77 non-empty decompiler lines.
//  - Control keywords: do×6, while×6, if×3, for×2, return×1.
//  - Notable callees: FUN_007a69d0, FUN_007a6de0, FUN_008011e0, FUN_008073b0, FUN_008f8200.
//  - Strings: "Convoy invitation sent to ".
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

void FUN_008011e0(int param_1)



{

  char cVar1;

  char *in_EAX;

  char *pcVar2;

  char *pcVar3;

  char *pcVar4;

  uint uVar5;

  uint uVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint32_t /* width from decompiler */ local_128 [2];

  uint32_t /* width from decompiler */ local_120;

  uint32_t /* width from decompiler */ local_11c;

  char local_118 [23];

  char cStack_101;

  char local_100 [256];

  

  pcVar2 = in_EAX;

  do {

    cVar1 = *pcVar2;

    pcVar2 = pcVar2 + 1;

  } while (cVar1 != '\0');

  if (pcVar2 != in_EAX + 1) {

    pcVar2 = in_EAX;

    do {

      cVar1 = *pcVar2;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

    if ((uint)((int)pcVar2 - (int)(in_EAX + 1)) < 0x11) {

      local_128[0] = 0x8004;

      local_120 = 0xffffffff;

      local_11c = 0xffffffff;

      pcVar2 = in_EAX;

      do {

        cVar1 = *pcVar2;

        pcVar2[(int)(local_118 + -(int)in_EAX)] = cVar1;

        pcVar2 = pcVar2 + 1;

      } while (cVar1 != '\0');

      FUN_008073b0(0x28,local_128);

      uVar7 = 0xffffffff;

      pcVar2 = "Convoy invitation sent to ";

      FUN_007a69d0("Convoy invitation sent to ",0xffffffff);

      pcVar3 = (char *)FUN_007a6de0(pcVar2,uVar7);

      pcVar2 = local_100;

      do {

        cVar1 = *pcVar3;

        *pcVar2 = cVar1;

        pcVar3 = pcVar3 + 1;

        pcVar2 = pcVar2 + 1;

        pcVar4 = in_EAX;

      } while (cVar1 != '\0');

      do {

        cVar1 = *pcVar4;

        pcVar4 = pcVar4 + 1;

      } while (cVar1 != '\0');

      uVar5 = (int)pcVar4 - (int)in_EAX;

      pcVar2 = &cStack_101;

      do {

        pcVar3 = pcVar2 + 1;

        pcVar2 = pcVar2 + 1;

      } while (*pcVar3 != '\0');

      for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

        *(uint32_t /* width from decompiler */ *)pcVar2 = *(uint32_t /* width from decompiler */ *)in_EAX;

        in_EAX = in_EAX + 4;

        pcVar2 = pcVar2 + 4;

      }

      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {

        *pcVar2 = *in_EAX;

        in_EAX = in_EAX + 1;

        pcVar2 = pcVar2 + 1;

      }

      if ((**(int **)(param_1 + 0xf40) != 0) && (DAT_00d1b8dc != 0)) {

        FUN_008f8200(DAT_00d1b8dc,6,&DAT_00a3a4a0,local_100,0);

      }

    }

  }

  return;

}
