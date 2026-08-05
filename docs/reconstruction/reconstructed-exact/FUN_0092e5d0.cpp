// =============================================================================
// FUN_0092e5d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0092e5d0
// Address:   0x0092e5d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0092e5d0 @ 0x0092e5d0
// Stable ID: aa_0092e5d0
// Embedded strings (evidence for future rename):
//   - "Level "
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~104 non-empty decompiler lines.
//  - Control keywords: do×8, while×8, for×6, return×2, if×1.
//  - Notable callees: FUN_007a6de0×2, FUN_00521900, FUN_007a69d0, FUN_0092e5d0, _itoa.
//  - Strings: "Level ".
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

int FUN_0092e5d0(int param_1)



{

  char cVar1;

  char *pcVar2;

  char *pcVar3;

  int _Value;

  uint32_t /* width from decompiler */ uVar4;

  uint uVar5;

  uint uVar6;

  char *unaff_EBX;

  char *pcVar7;

  char *pcVar8;

  int _Radix;

  uint32_t /* width from decompiler */ uVar9;

  char local_c [12];

  

  if ((param_1 != 0) && (unaff_EBX != (char *)0x0)) {

    FUN_007a69d0();

    pcVar2 = (char *)FUN_007a6de0("Level ",0xffffffff);

    pcVar3 = pcVar2;

    do {

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    pcVar8 = unaff_EBX + -1;

    do {

      pcVar7 = pcVar8 + 1;

      pcVar8 = pcVar8 + 1;

    } while (*pcVar7 != '\0');

    pcVar7 = pcVar2;

    for (uVar5 = (uint)((int)pcVar3 - (int)pcVar2) >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar8 = *(uint32_t /* width from decompiler */ *)pcVar7;

      pcVar7 = pcVar7 + 4;

      pcVar8 = pcVar8 + 4;

    }

    for (uVar5 = (int)pcVar3 - (int)pcVar2 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {

      *pcVar8 = *pcVar7;

      pcVar7 = pcVar7 + 1;

      pcVar8 = pcVar8 + 1;

    }

    _Radix = 10;

    pcVar3 = local_c;

    _Value = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x27c))();

    _itoa(_Value,pcVar3,_Radix);

    pcVar3 = local_c;

    do {

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    uVar5 = (int)pcVar3 - (int)local_c;

    pcVar3 = unaff_EBX + -1;

    do {

      pcVar2 = pcVar3 + 1;

      pcVar3 = pcVar3 + 1;

    } while (*pcVar2 != '\0');

    pcVar2 = local_c;

    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar3 = *(uint32_t /* width from decompiler */ *)pcVar2;

      pcVar2 = pcVar2 + 4;

      pcVar3 = pcVar3 + 4;

    }

    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {

      *pcVar3 = *pcVar2;

      pcVar2 = pcVar2 + 1;

      pcVar3 = pcVar3 + 1;

    }

    pcVar3 = unaff_EBX + -1;

    do {

      pcVar2 = pcVar3 + 1;

      pcVar3 = pcVar3 + 1;

    } while (*pcVar2 != '\0');

    *(uint16_t *)pcVar3 = DAT_00a2a000;

    uVar9 = 0xffffffff;

    uVar4 = FUN_00521900(0xffffffff);

    pcVar2 = (char *)FUN_007a6de0(uVar4,uVar9);

    pcVar3 = pcVar2;

    do {

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    pcVar8 = unaff_EBX + -1;

    do {

      pcVar7 = pcVar8 + 1;

      pcVar8 = pcVar8 + 1;

    } while (*pcVar7 != '\0');

    pcVar7 = pcVar2;

    for (uVar5 = (uint)((int)pcVar3 - (int)pcVar2) >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar8 = *(uint32_t /* width from decompiler */ *)pcVar7;

      pcVar7 = pcVar7 + 4;

      pcVar8 = pcVar8 + 4;

    }

    for (uVar5 = (int)pcVar3 - (int)pcVar2 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {

      *pcVar8 = *pcVar7;

      pcVar7 = pcVar7 + 1;

      pcVar8 = pcVar8 + 1;

    }

    pcVar3 = unaff_EBX + 1;

    do {

      cVar1 = *unaff_EBX;

      unaff_EBX = unaff_EBX + 1;

    } while (cVar1 != '\0');

    return (int)unaff_EBX - (int)pcVar3;

  }

  return 0;

}
