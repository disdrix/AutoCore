// =============================================================================
// FUN_00907ff0
// -----------------------------------------------------------------------------
// Stable ID: aa_00907ff0
// Address:   0x00907ff0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00907ff0 @ 0x00907ff0
// Stable ID: aa_00907ff0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~88 non-empty decompiler lines.
//  - Control keywords: if×8, do×2, while×2, return×1.
//  - Notable callees: _strlwr×2, atoi×2, FUN_007a69d0, FUN_00906c60, FUN_00906dd0, FUN_00906f30, FUN_00907ff0, FUN_009803a0.
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

void FUN_00907ff0(void)



{

  uint8_t uVar1;

  char cVar2;

  int in_EAX;

  int iVar3;

  char *pcVar4;

  char *pcVar5;

  byte bVar6;

  

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x538) = 999999999;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x53c) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x530) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x534) = 0;

  uVar1 = FUN_00906f30();

  *(uint8_t *)(in_EAX + 0x529) = uVar1;

  *(uint8_t *)(in_EAX + 0x528) = 0xf;

  uVar1 = FUN_00906dd0();

  *(uint8_t *)(in_EAX + 0x52c) = uVar1;

  uVar1 = FUN_00906c60();

  *(uint8_t *)(in_EAX + 0x52d) = uVar1;

  iVar3 = FUN_007a69d0();

  *(uint8_t *)(in_EAX + 0x52e) = *(uint8_t *)(iVar3 + 0x2c);

  if (*(int **)(in_EAX + 0x70c) == (int *)0x0) {

    cVar2 = -1;

  }

  else {

    pcVar4 = (char *)(**(code **)(**(int **)(in_EAX + 0x70c) + 0x1dc))();

    iVar3 = atoi(pcVar4);

    cVar2 = 'P';

    if ('\0' < (char)iVar3) {

      cVar2 = (char)iVar3;

    }

  }

  *(char *)(in_EAX + 0x52b) = cVar2;

  if (*(int **)(in_EAX + 0x708) == (int *)0x0) {

    cVar2 = -1;

  }

  else {

    pcVar4 = (char *)(**(code **)(**(int **)(in_EAX + 0x708) + 0x1dc))();

    iVar3 = atoi(pcVar4);

    if ((iVar3 == 1) || (cVar2 = '\x01', (char)iVar3 < 'P')) {

      cVar2 = (char)iVar3;

    }

  }

  bVar6 = 0;

  *(char *)(in_EAX + 0x52a) = cVar2;

  if ((*(int **)(in_EAX + 0x6ac) != (int *)0x0) &&

     (cVar2 = (**(code **)(**(int **)(in_EAX + 0x6ac) + 0x3bc))(), cVar2 != '\0')) {

    bVar6 = 1;

  }

  if ((*(int **)(in_EAX + 0x6b0) != (int *)0x0) &&

     (cVar2 = (**(code **)(**(int **)(in_EAX + 0x6b0) + 0x3bc))(), cVar2 != '\0')) {

    bVar6 = bVar6 | 2;

  }

  *(byte *)(in_EAX + 0x52f) = bVar6;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x540) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x544) = 0xffffffff;

  if (*(int **)(in_EAX + 0x67c) == (int *)0x0) {

    pcVar4 = "";

  }

  else {

    pcVar4 = (char *)(**(code **)(**(int **)(in_EAX + 0x67c) + 0x1dc))();

  }

  pcVar5 = (char *)(in_EAX + 0x55d);

  do {

    cVar2 = *pcVar4;

    *pcVar5 = cVar2;

    pcVar4 = pcVar4 + 1;

    pcVar5 = pcVar5 + 1;

  } while (cVar2 != '\0');

  if (*(int **)(in_EAX + 0x680) == (int *)0x0) {

    pcVar4 = "";

  }

  else {

    pcVar4 = (char *)(**(code **)(**(int **)(in_EAX + 0x680) + 0x1dc))();

  }

  pcVar5 = (char *)(in_EAX + 0x54c);

  do {

    cVar2 = *pcVar4;

    *pcVar5 = cVar2;

    pcVar4 = pcVar4 + 1;

    pcVar5 = pcVar5 + 1;

  } while (cVar2 != '\0');

  _strlwr((char *)(in_EAX + 0x55d));

  _strlwr((char *)(in_EAX + 0x54c));

  FUN_009803a0(DAT_00d1ad2c,0);

  return;

}
