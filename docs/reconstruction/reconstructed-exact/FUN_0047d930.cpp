// =============================================================================
// FUN_0047d930
// -----------------------------------------------------------------------------
// Stable ID: aa_0047d930
// Address:   0x0047d930  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0047d930 @ 0x0047d930
// Stable ID: aa_0047d930
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~135 non-empty decompiler lines.
//  - Control keywords: if×23, return×3, for×2.
//  - Notable callees: FUN_00476cc0×2, FUN_00470dd0, FUN_004776d0, FUN_0047d930, malloc.
//  - Return sites: 3.

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

void FUN_0047d930(void)



{

  size_t _Size;

  byte bVar1;

  char cVar2;

  int in_EAX;

  uint uVar3;

  void *pvVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint uVar6;

  int iVar7;

  

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x78) = 0;

  FUN_00470dd0();

  if (*(char *)(in_EAX + 0x123) == '\0') {

    iVar7 = *(int *)(in_EAX + 200);

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0xd0) = *(uint32_t /* width from decompiler */ *)(in_EAX + 0xcc);

    *(int *)(in_EAX + 0xe0) = iVar7;

    *(int *)(in_EAX + 0xdc) = *(int *)(in_EAX + 0xd8) + 1;

  }

  else {

    if ((*(byte *)(in_EAX + 0x70) & 2) == 0) {

      *(uint *)(in_EAX + 0xd0) = *(int *)(in_EAX + 0xcc) + 7U >> 3;

    }

    else {

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0xd0) = *(uint32_t /* width from decompiler */ *)(in_EAX + 0xcc);

    }

    iVar7 = *(int *)(in_EAX + 200);

    uVar3 = ((iVar7 - *(int *)(&DAT_00a26640 + (uint)*(byte *)(in_EAX + 0x124) * 4)) + -1 +

            *(uint *)(&DAT_00a2665c + (uint)*(byte *)(in_EAX + 0x124) * 4)) /

            *(uint *)(&DAT_00a2665c + (uint)*(byte *)(in_EAX + 0x124) * 4);

    bVar1 = *(byte *)(in_EAX + 0x129);

    *(uint *)(in_EAX + 0xe0) = uVar3;

    if (bVar1 < 8) {

      *(uint *)(in_EAX + 0xdc) = (bVar1 * uVar3 + 7 >> 3) + 1;

    }

    else {

      *(uint *)(in_EAX + 0xdc) = (bVar1 >> 3) * uVar3 + 1;

    }

  }

  uVar3 = (uint)*(byte *)(in_EAX + 0x129);

  uVar6 = *(uint *)(in_EAX + 0x70);

  if (((uVar6 & 4) != 0) && (*(byte *)(in_EAX + 0x127) < 8)) {

    uVar3 = 8;

  }

  if ((uVar6 & 0x1000) != 0) {

    cVar2 = *(char *)(in_EAX + 0x126);

    if (cVar2 == '\x03') {

      uVar3 = (uint)(*(short *)(in_EAX + 0x11a) != 0) * 8 + 0x18;

    }

    else if (cVar2 == '\0') {

      if (uVar3 < 8) {

        uVar3 = 8;

      }

      if (*(short *)(in_EAX + 0x11a) != 0) {

        uVar3 = uVar3 * 2;

      }

    }

    else if ((cVar2 == '\x02') && (*(short *)(in_EAX + 0x11a) != 0)) {

      uVar3 = (uVar3 * 4) / 3;

    }

  }

  if ((uVar6 & 0x8000) != 0) {

    cVar2 = *(char *)(in_EAX + 0x126);

    if (cVar2 == '\x03') {

      uVar3 = 0x20;

    }

    else if (cVar2 == '\0') {

      uVar3 = ((8 < uVar3) - 1 & 0xfffffff0) + 0x20;

    }

    else if (cVar2 == '\x02') {

      uVar3 = ((0x20 < uVar3) - 1 & 0xffffffe0) + 0x40;

    }

  }

  if ((uVar6 & 0x4000) != 0) {

    if ((((*(short *)(in_EAX + 0x11a) == 0) || ((uVar6 & 0x1000) == 0)) && ((uVar6 & 0x8000) == 0))

       && (cVar2 = *(char *)(in_EAX + 0x126), cVar2 != '\x04')) {

      if ((int)uVar3 < 9) {

        uVar3 = (uint)(cVar2 == '\x06') * 8 + 0x18;

      }

      else {

        uVar3 = (-(uint)(cVar2 != '\x06') & 0xfffffff0) + 0x40;

      }

    }

    else {

      uVar3 = ((0x10 < (int)uVar3) - 1 & 0xffffffe0) + 0x40;

    }

  }

  if (((uVar6 & 0x100000) != 0) &&

     (uVar6 = (uint)*(byte *)(in_EAX + 0x65) * (uint)*(byte *)(in_EAX + 100),

     uVar6 - uVar3 != 0 && (int)uVar3 <= (int)uVar6)) {

    uVar3 = uVar6;

  }

  uVar6 = iVar7 + 7U & 0xfffffff8;

  if ((int)uVar3 < 8) {

    uVar6 = uVar3 * uVar6 + 7 >> 3;

  }

  else {

    uVar6 = (uVar3 >> 3) * uVar6;

  }

  _Size = ((int)(uVar3 + 7) >> 3) + 0x41 + uVar6;

  if (_Size == 0) {

    pvVar4 = (void *)0x0;

  }

  else {

    if (*(code **)(in_EAX + 0x248) == (code *)0x0) {

      pvVar4 = malloc(_Size);

    }

    else {

      pvVar4 = (void *)(**(code **)(in_EAX + 0x248))();

    }

    if ((pvVar4 == (void *)0x0) && ((*(byte *)(in_EAX + 0x6e) & 0x10) == 0)) {

                    /* WARNING: Subroutine does not return */

      FUN_00476cc0();

    }

  }

  *(void **)(in_EAX + 0x250) = pvVar4;

  *(int *)(in_EAX + 0xec) = (int)pvVar4 + 0x20;

  if (*(int *)(in_EAX + 0xd8) != -1) {

    puVar5 = (uint32_t /* width from decompiler */ *)FUN_004776d0();

    uVar6 = *(int *)(in_EAX + 0xd8) + 1;

    *(uint32_t /* width from decompiler */ **)(in_EAX + 0xe8) = puVar5;

    for (uVar3 = uVar6 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {

      *puVar5 = 0;

      puVar5 = puVar5 + 1;

    }

    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {

      *(uint8_t *)puVar5 = 0;

      puVar5 = (uint32_t /* width from decompiler */ *)((int)puVar5 + 1);

    }

    *(uint *)(in_EAX + 0x6c) = *(uint *)(in_EAX + 0x6c) | 0x40;

    return;

  }

                    /* WARNING: Subroutine does not return */

  FUN_00476cc0();

}
