// =============================================================================
// FUN_00636d30
// -----------------------------------------------------------------------------
// Stable ID: aa_00636d30
// Address:   0x00636d30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00636d30 @ 0x00636d30
// Stable ID: aa_00636d30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~87 non-empty decompiler lines.
//  - Control keywords: if×5, do×2, while×2, return×1.
//  - Notable callees: BitStream_writeFlag×7, BitStream_writeBits×4, CONCAT22×2, CONCAT31, FUN_00433ab0, FUN_00636d30, realloc.
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

void FUN_00636d30(int *param_1,uint *param_2)



{

  uint *puVar1;

  int iVar2;

  uint _NewSize;

  void *pvVar3;

  uint16_t extraout_var;

  uint8_t uVar4;

  uint16_t extraout_var_00;

  int iVar5;

  int iVar6;

  void *local_1c;

  uint local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a8cab;

  local_c = ExceptionList;

  iVar6 = 0;

  local_1c = (void *)0x0;

  ExceptionList = &local_c;

  local_1c = operator_new(0x138);

  local_4 = 0;

  if (local_1c == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_00433ab0();

  }

  puVar1 = param_2;

  local_1c = (void *)*param_2;

  local_18 = param_2[1];

  local_4 = 0xffffffff;

  if ((((uint)local_1c & local_18) == 0xffffffff) && ((char)param_2[2] == '\0')) {

    local_1c = (void *)param_2[4];

    local_18 = param_2[5];

    uVar4 = (uint8_t)param_2[6];

  }

  else {

    uVar4 = (uint8_t)param_2[2];

  }

  param_2 = (uint *)CONCAT31(param_2._1_3_,uVar4);

  BitStream_writeBits(0x40,&local_1c);

  BitStream_writeFlag(param_2);

  param_2 = (uint *)CONCAT22(extraout_var_00,*(uint16_t *)((int)puVar1 + 0x22));

  BitStream_writeBits(0x10,&param_2);

  param_2 = (uint *)0x0;

  if (*(short *)((int)puVar1 + 0x22) != 0) {

    do {

      BitStream_writeFlag(*(uint8_t *)(puVar1[9] + 0x15 + iVar6));

      local_1c = (void *)CONCAT22(extraout_var,*(uint16_t *)(puVar1[9] + 0x10 + iVar6));

      BitStream_writeBits(0x10,&local_1c);

      local_14 = *(uint32_t /* width from decompiler */ *)(puVar1[9] + iVar6);

      local_10 = *(uint32_t /* width from decompiler */ *)(puVar1[9] + 4 + iVar6);

      BitStream_writeBits(0x40,&local_14);

      BitStream_writeFlag(*(uint8_t *)(puVar1[9] + 8 + iVar6));

      BitStream_writeFlag(*(uint8_t *)(puVar1[9] + 0x1c + iVar6));

      BitStream_writeFlag(*(uint8_t *)(puVar1[9] + 0x1d + iVar6));

      BitStream_writeFlag(*(uint8_t *)(puVar1[9] + 0x1e + iVar6));

      iVar5 = 0;

      do {

        BitStream_writeFlag(*(uint8_t *)(iVar5 + iVar6 + 0x16 + puVar1[9]));

        iVar5 = iVar5 + 1;

      } while (iVar5 < 6);

      param_2 = (uint *)((int)param_2 + 1);

      iVar6 = iVar6 + 0x20;

    } while ((int)param_2 < (int)(uint)*(ushort *)((int)puVar1 + 0x22));

  }

  _NewSize = *(int *)(iVar2 + 0x18) + 7U >> 3;

  if (*(uint *)(iVar2 + 0x10) < _NewSize) {

    if (*(char *)(iVar2 + 0x14) != '\0') {

      *(uint *)(iVar2 + 0x10) = _NewSize;

      pvVar3 = realloc(*(void **)(iVar2 + 0xc),_NewSize);

      *(void **)(iVar2 + 0xc) = pvVar3;

    }

  }

  else {

    *(uint *)(iVar2 + 0x10) = _NewSize;

  }

  *param_1 = iVar2;

  *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) + 1;

  ExceptionList = local_c;

  return;

}
