// =============================================================================
// FUN_0076c700
// -----------------------------------------------------------------------------
// Stable ID: aa_0076c700
// Address:   0x0076c700  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0076c700 @ 0x0076c700
// Stable ID: aa_0076c700
// Embedded strings (evidence for future rename):
//   - "%s(%d) : %s-%s: %s\n"
//   - "%s-%s: %s\n"
//   - "%-25.25s(%6d) : %s-%s: %s\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~67 non-empty decompiler lines.
//  - Control keywords: if×10, return×2, do×2, while×2, goto×1.
//  - Notable callees: _snprintf×2, FUN_0076c5d0, FUN_0076c700, FUN_0076d8b0, FUN_0076d9d0, FUN_0076dae0, _ctime64, _time64.
//  - Strings: "%s(%d) : %s-%s: %s\n"; "%s-%s: %s\n"; "%-25.25s(%6d) : %s-%s: %s\n".
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

uint32_t /* width from decompiler */ __thiscall

FUN_0076c700(int param_1,char *param_2,uint32_t /* width from decompiler */ param_3,int param_4,uint32_t /* width from decompiler */ param_5,

            uint32_t /* width from decompiler */ param_6)



{

  char cVar1;

  int iVar2;

  char *pcVar3;

  char *pcVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  __time64_t local_58;

  uint8_t local_50 [80];

  

  if (*(int *)(param_1 + 0x18) == 0) {

    return 1;

  }

  if (*(int *)(param_1 + 0x14) != 0) {

    FUN_0076c5d0();

  }

  _time64(&local_58);

  pcVar3 = _ctime64(&local_58);

  pcVar4 = pcVar3;

  do {

    cVar1 = *pcVar4;

    pcVar4 = pcVar4 + 1;

  } while (cVar1 != '\0');

  pcVar3[(int)(pcVar4 + (-1 - (int)(pcVar3 + 1)))] = ' ';

  iVar2 = *(int *)(param_1 + 0x10);

  if (iVar2 == 0) {

    pcVar4 = "%s(%d) : %s-%s: %s\n";

  }

  else {

    if (iVar2 != 1) {

      if (iVar2 == 2) {

        _snprintf(&DAT_00d1f210,0x400,"%s-%s: %s\n",pcVar3,param_5,param_6);

      }

      goto LAB_0076c7eb;

    }

    pcVar4 = strrchr(param_2,0x5c);

    if (pcVar4 != (char *)0x0) {

      param_2 = pcVar4 + 1;

    }

    pcVar4 = "%-25.25s(%6d) : %s-%s: %s\n";

  }

  _snprintf(&DAT_00d1f210,0x400,pcVar4,param_2,param_3,pcVar3,param_5,param_6);

LAB_0076c7eb:

  if (2 < param_4) {

    pcVar4 = &DAT_00d1f210;

    do {

      pcVar3 = pcVar4;

      pcVar4 = pcVar3 + 1;

    } while (*pcVar3 != '\0');

    uVar5 = FUN_0076dae0();

    if (DAT_00d0dfb0 != 0) {

      uVar6 = FUN_0076d9d0(uVar5,4,local_50,0x14);

      FUN_0076d8b0(uVar5,uVar6,local_50,pcVar3,0x3ff - (int)(pcVar3 + -0xd1f210));

    }

  }

  DAT_00d1f60f = 0;

  if (*(char *)(param_1 + 0xc) != '\0') {

    puts(&DAT_00d1f210);

  }

  if (*(FILE **)(param_1 + 0x18) != (FILE *)0x0) {

    fputs(&DAT_00d1f210,*(FILE **)(param_1 + 0x18));

    fflush(*(FILE **)(param_1 + 0x18));

  }

  return 1;

}
