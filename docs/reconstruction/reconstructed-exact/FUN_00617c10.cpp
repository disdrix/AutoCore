// =============================================================================
// FUN_00617c10
// -----------------------------------------------------------------------------
// Stable ID: aa_00617c10
// Address:   0x00617c10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00617c10 @ 0x00617c10
// Stable ID: aa_00617c10
// Embedded strings (evidence for future rename):
//   - "Shielding points: %d\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: do×2, while×2, for×2, if×1, return×1.
//  - Notable callees: FUN_00578550, FUN_0058ae10, FUN_00617c10, sprintf.
//  - Strings: "Shielding points: %d\n".
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

int FUN_00617c10(int param_1,uint32_t /* width from decompiler */ param_2,int param_3,uint32_t /* width from decompiler */ param_4)



{

  char cVar1;

  char *pcVar2;

  uint uVar3;

  int iVar4;

  uint uVar5;

  char cVar6;

  char *pcVar7;

  char local_400 [1024];

  

  cVar6 = '\0';

  if (*(float *)(param_3 + 0x4c) != g_flZero) {

    sprintf(local_400,"Shielding points: %d\n",(int)*(float *)(param_3 + 0x4c));

    pcVar2 = local_400;

    do {

      cVar6 = *pcVar2;

      pcVar2 = pcVar2 + 1;

    } while (cVar6 != '\0');

    uVar3 = (int)pcVar2 - (int)local_400;

    pcVar2 = (char *)(param_1 + -1);

    do {

      pcVar7 = pcVar2 + 1;

      pcVar2 = pcVar2 + 1;

    } while (*pcVar7 != '\0');

    pcVar7 = local_400;

    for (uVar5 = uVar3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar2 = *(uint32_t /* width from decompiler */ *)pcVar7;

      pcVar7 = pcVar7 + 4;

      pcVar2 = pcVar2 + 4;

    }

    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

      *pcVar2 = *pcVar7;

      pcVar7 = pcVar7 + 1;

      pcVar2 = pcVar2 + 1;

    }

    cVar6 = '\x01';

  }

  cVar1 = FUN_0058ae10(param_1,param_2,param_3,0x3f800000);

  iVar4 = FUN_00578550(param_1,param_2,param_3,param_4);

  return iVar4 + (uint)(byte)(cVar6 + cVar1);

}
