// =============================================================================
// FUN_00637380
// -----------------------------------------------------------------------------
// Stable ID: aa_00637380
// Address:   0x00637380  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00637380 @ 0x00637380
// Stable ID: aa_00637380
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~74 non-empty decompiler lines.
//  - Control keywords: if×5, do×1, while×1, return×1.
//  - Notable callees: BitStream_writeBits×5, BitStream_writeFlag×2, BitStream_writeInt, CONCAT22, CONCAT31, FUN_00433ab0, FUN_00637380, realloc.
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

void FUN_00637380(int *param_1,uint param_2)



{

  int iVar1;

  char cVar2;

  int iVar3;

  byte bVar4;

  uint _NewSize;

  void *pvVar5;

  uint16_t extraout_var;

  int iVar6;

  char local_1d;

  uint32_t /* width from decompiler */ local_1c;

  void *local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a8d0a;

  local_c = ExceptionList;

  iVar6 = 0;

  local_18 = (void *)0x0;

  ExceptionList = &local_c;

  local_18 = operator_new(0x138);

  local_4 = 0;

  if (local_18 != (void *)0x0) {

    iVar6 = FUN_00433ab0();

  }

  iVar3 = param_2;

  local_4 = 0xffffffff;

  param_2._0_1_ = *(uint8_t *)(param_2 + 4);

  BitStream_writeBits(8,&param_2);

  param_2 = (uint)param_2._1_3_ << 8;

  if (*(char *)(iVar3 + 4) != '\0') {

    do {

      cVar2 = *(char *)(iVar3 + 0xc + (param_2 & 0xff) * 0x28);

      iVar1 = iVar3 + (param_2 & 0xff) * 0x28;

      local_1d = cVar2;

      BitStream_writeBits(8,&local_1d);

      if (cVar2 == '\x01') {

        local_1c = CONCAT22(extraout_var,*(uint16_t *)(iVar1 + 0x10));

        BitStream_writeBits(0x10,&local_1c);

        local_18 = *(void **)(iVar1 + 0x14);

        BitStream_writeBits(0x20,&local_18);

      }

      else {

        BitStream_writeInt(*(uint32_t /* width from decompiler */ *)(iVar1 + 0x10),0x13);

        local_14 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x18);

        local_10 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x1c);

        BitStream_writeBits(0x40,&local_14);

        BitStream_writeFlag(*(uint8_t *)(iVar1 + 0x20));

        BitStream_writeFlag(*(uint8_t *)(iVar1 + 0x28));

      }

      bVar4 = (char)param_2 + 1;

      param_2 = CONCAT31(param_2._1_3_,bVar4);

    } while (bVar4 < *(byte *)(iVar3 + 4));

  }

  _NewSize = *(int *)(iVar6 + 0x18) + 7U >> 3;

  if (*(uint *)(iVar6 + 0x10) < _NewSize) {

    if (*(char *)(iVar6 + 0x14) != '\0') {

      *(uint *)(iVar6 + 0x10) = _NewSize;

      pvVar5 = realloc(*(void **)(iVar6 + 0xc),_NewSize);

      *(void **)(iVar6 + 0xc) = pvVar5;

    }

  }

  else {

    *(uint *)(iVar6 + 0x10) = _NewSize;

  }

  *param_1 = iVar6;

  *(int *)(iVar6 + 8) = *(int *)(iVar6 + 8) + 1;

  ExceptionList = local_c;

  return;

}
