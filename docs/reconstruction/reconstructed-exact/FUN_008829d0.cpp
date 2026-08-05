// =============================================================================
// FUN_008829d0
// -----------------------------------------------------------------------------
// Stable ID: aa_008829d0
// Address:   0x008829d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008829d0 @ 0x008829d0
// Stable ID: aa_008829d0
// Embedded strings (evidence for future rename):
//   - "Current Power Distribution:"
//   - "Power Distribution Would Be:"
//   - "__ Power Distribution __"
//   - " %+.0f%%\n"
//   - " %+.0f%%"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~136 non-empty decompiler lines.
//  - Control keywords: if×9, do×3, while×3, return×1.
//  - Notable callees: FUN_007a6de0×6, sprintf×3, FUN_0051f230, FUN_007a69d0, FUN_008829d0.
//  - Strings: "Current Power Distribution:"; "Power Distribution Would Be:"; "__ Power Distribution __"; " %+.0f%%\n".
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

void FUN_008829d0(void)



{

  char cVar1;

  int iVar2;

  int in_EAX;

  char *pcVar3;

  uint32_t /* width from decompiler */ uVar4;

  float fVar5;

  char *pcVar6;

  int unaff_ESI;

  float unaff_EDI;

  uint32_t /* width from decompiler */ uStack_228;

  uint32_t /* width from decompiler */ *puStack_224;

  char *pcStack_220;

  uint32_t /* width from decompiler */ *puStack_21c;

  uint32_t /* width from decompiler */ local_20c;

  uint32_t /* width from decompiler */ local_208;

  uint32_t /* width from decompiler */ local_204 [64];

  uint8_t local_101;

  char local_100 [212];

  char cStack_2c;

  uint8_t local_1;

  

  puStack_21c = (uint32_t /* width from decompiler */ *)0x8829e0;

  FUN_007a69d0();

  puStack_21c = &local_20c;

  pcStack_220 = (char *)local_204;

  puStack_224 = &local_208;

  local_208 = 0;

  local_204[0] = 0;

  local_20c = 0;

  FUN_0051f230();

  local_1 = 0;

  puStack_21c = (uint32_t /* width from decompiler */ *)0xffffffff;

  if (*(char *)(unaff_ESI + 0x51c) == '\0') {

    if (in_EAX == *(int *)(unaff_ESI + 0x518)) {

      pcStack_220 = "Current Power Distribution:";

      puStack_224 = (uint32_t /* width from decompiler */ *)0x882a57;

      pcVar3 = (char *)FUN_007a6de0();

      pcVar6 = local_100;

      do {

        cVar1 = *pcVar3;

        *pcVar6 = cVar1;

        pcVar3 = pcVar3 + 1;

        pcVar6 = pcVar6 + 1;

      } while (cVar1 != '\0');

    }

    else {

      pcStack_220 = "Power Distribution Would Be:";

      puStack_224 = (uint32_t /* width from decompiler */ *)0x882a7a;

      pcVar3 = (char *)FUN_007a6de0();

      pcVar6 = local_100;

      do {

        cVar1 = *pcVar3;

        *pcVar6 = cVar1;

        pcVar3 = pcVar3 + 1;

        pcVar6 = pcVar6 + 1;

      } while (cVar1 != '\0');

    }

  }

  else {

    pcStack_220 = "__ Power Distribution __";

    puStack_224 = (uint32_t /* width from decompiler */ *)0x882a2e;

    pcVar3 = (char *)FUN_007a6de0();

    pcVar6 = local_100;

    do {

      cVar1 = *pcVar3;

      *pcVar6 = cVar1;

      pcVar3 = pcVar3 + 1;

      pcVar6 = pcVar6 + 1;

    } while (cVar1 != '\0');

  }

  local_101 = 0;

  puStack_21c = (uint32_t /* width from decompiler */ *)0x882aa4;

  (**(code **)(**(int **)(unaff_ESI + 0x530) + 0x268))();

  puStack_21c = (uint32_t /* width from decompiler */ *)((-(uint)(*(char *)(unaff_ESI + 0x51c) != '\0') & 0xfffff045) - 1);

  pcStack_220 = local_100;

  puStack_224 = (uint32_t /* width from decompiler */ *)0x882acd;

  (**(code **)(**(int **)(unaff_ESI + 0x530) + 0x224))();

  puStack_224 = (uint32_t /* width from decompiler */ *)&DAT_00a4f48c;

  uStack_228 = 0x882ae0;

  (**(code **)(**(int **)(unaff_ESI + 0x530) + 0x250))();

  iVar2 = **(int **)(unaff_ESI + 0x530);

  uStack_228 = 0xffffffff;

  uStack_228 = FUN_007a6de0();

  (**(code **)(iVar2 + 0x250))();

  sprintf(&stack0xfffffdf0," %+.0f%%\n",(double)(unaff_EDI * DAT_00aaa7ac));

  if (unaff_EDI <= DAT_00aaa664) {

    if (DAT_00aaa6b4 <= unaff_EDI) {

      uVar4 = 0xffffffff;

    }

    else {

      uVar4 = 0xffff6666;

    }

  }

  else {

    uVar4 = 0xff66ff66;

  }

  (**(code **)(**(int **)(unaff_ESI + 0x530) + 0x224))(&stack0xfffffdf0,uVar4);

  iVar2 = **(int **)(unaff_ESI + 0x530);

  fVar5 = (float)FUN_007a6de0();

  (**(code **)(iVar2 + 0x250))();

  sprintf((char *)&puStack_21c," %+.0f%%\n",(double)((float)pcStack_220 * DAT_00aaa7ac));

  if ((float)pcStack_220 <= DAT_00aaa664) {

    if (DAT_00aaa6b4 <= (float)pcStack_220) {

      uVar4 = 0xffffffff;

    }

    else {

      uVar4 = 0xffff6666;

    }

  }

  else {

    uVar4 = 0xff66ff66;

  }

  (**(code **)(**(int **)(unaff_ESI + 0x530) + 0x224))(&puStack_21c,uVar4);

  iVar2 = **(int **)(unaff_ESI + 0x530);

  uVar4 = FUN_007a6de0();

  (**(code **)(iVar2 + 0x250))(uVar4);

  sprintf((char *)&uStack_228," %+.0f%%",(double)(fVar5 * DAT_00aaa7ac));

  if (fVar5 <= DAT_00aaa664) {

    if (DAT_00aaa6b4 <= fVar5) {

      uVar4 = 0xffffffff;

    }

    else {

      uVar4 = 0xffff6666;

    }

  }

  else {

    uVar4 = 0xff66ff66;

  }

  (**(code **)(**(int **)(unaff_ESI + 0x530) + 0x224))(&uStack_228,uVar4);

  if (cStack_2c == '\0') {

    (**(code **)(**(int **)(unaff_ESI + 0x530) + 0x1f0))();

  }

  (**(code **)(**(int **)(unaff_ESI + 0x530) + 0x34c))();

  return;

}
