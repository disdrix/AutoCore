// =============================================================================
// FUN_004d73c0
// -----------------------------------------------------------------------------
// Stable ID: aa_004d73c0
// Address:   0x004d73c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004d73c0 @ 0x004d73c0
// Stable ID: aa_004d73c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~57 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: FUN_0043d4a0, FUN_004d73c0, FUN_00744c10, FUN_00745bd0, FUN_0076a150, FUN_007b6a20, FUN_007b7420, FUN_0099c130.
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

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



void __thiscall FUN_004d73c0(int param_1,uint32_t /* width from decompiler */ param_2)



{

  char cVar1;

  int iVar2;

  char *pcVar3;

  char *pcVar4;

  uint32_t /* width from decompiler */ *puVar5;

  char local_4178 [260];

  uint8_t local_4074 [16484];

  uint32_t /* width from decompiler */ uStack_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a216f;

  local_c = ExceptionList;

  uStack_10 = 0x4d73df;

  if (0x30 < *(int *)(param_1 + 0x8c)) {

    if (*(int *)(param_1 + 0x8c) < 0x34) {

      ExceptionList = &local_c;

      FUN_0099c140(0);

      local_4 = 1;

      FUN_0099c1c0(param_2);

      local_4 = 0xffffffff;

      FUN_0099c130();

      ExceptionList = local_c;

      return;

    }

    pcVar3 = (char *)(param_1 + 0xe198);

    iVar2 = -(int)pcVar3;

    do {

      cVar1 = *pcVar3;

      pcVar3[(int)(local_4178 + iVar2)] = cVar1;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    ExceptionList = &local_c;

    pcVar4 = strrchr(local_4178,0x2e);

    pcVar3 = local_4178;

    pcVar4[1] = 'c';

    pcVar4[2] = 'a';

    pcVar4[3] = 't';

    FUN_007b6a20(pcVar3);

    puVar5 = (uint32_t /* width from decompiler */ *)FUN_007b7420(pcVar3);

    if (puVar5 != (uint32_t /* width from decompiler */ *)0x0) {

      FUN_00744c10();

      FUN_0076a150(puVar5);

      local_4 = 0;

      FUN_00745bd0(local_4074);

      local_4 = 0xffffffff;

      FUN_0043d4a0();

      (**(code **)*puVar5)(1);

    }

  }

  ExceptionList = local_c;

  return;

}
