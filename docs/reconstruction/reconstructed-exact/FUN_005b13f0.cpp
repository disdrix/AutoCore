// =============================================================================
// FUN_005b13f0
// -----------------------------------------------------------------------------
// Stable ID: aa_005b13f0
// Address:   0x005b13f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005b13f0 @ 0x005b13f0
// Stable ID: aa_005b13f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~58 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: BitStream_writeFlag×6, BitStream_writeBits×5, BitStream_writeInt×4, CONCAT21, FUN_005b13f0.
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

void __thiscall

FUN_005b13f0(int param_1,uint32_t /* width from decompiler */ param_2,int param_3,int param_4,uint32_t /* width from decompiler */ param_5)



{

  int iVar1;

  bool bVar2;

  int iVar3;

  char cVar4;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  iVar3 = param_3;

  BitStream_writeInt(*(uint16_t *)(param_3 + 0xc),0xe);

  BitStream_writeInt((int)*(short *)(iVar3 + 0xe),8);

  BitStream_writeInt(*(uint8_t *)(iVar3 + 0x21),8);

  cVar4 = BitStream_writeFlag(CONCAT21((short)((uint)param_5 >> 0x10),~(byte)((uint)param_5 >> 8)) &

                              0xffffff01);

  if (cVar4 != '\0') {

    param_3 = *(uint32_t /* width from decompiler */ *)(iVar3 + 4);

    BitStream_writeBits(0x20,&param_3);

    param_3 = *(int *)(iVar3 + 8);

    BitStream_writeBits(0x20,&param_3);

    iVar1 = *(int *)(param_1 + 0x50);

    if (((*(int *)(iVar3 + 0x10) == *(int *)(iVar1 + 0x160)) &&

        (*(int *)(iVar3 + 0x14) == *(int *)(iVar1 + 0x164))) &&

       (*(char *)(iVar3 + 0x18) == *(char *)(iVar1 + 0x168))) {

      bVar2 = true;

    }

    else {

      bVar2 = false;

    }

    cVar4 = BitStream_writeFlag(!bVar2);

    if (cVar4 != '\0') {

      local_8 = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x10);

      local_4 = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x14);

      BitStream_writeBits(0x40,&local_8);

      BitStream_writeFlag(*(uint8_t *)(iVar3 + 0x18));

    }

    BitStream_writeFlag(*(uint8_t *)(iVar3 + 0x20));

    BitStream_writeInt((int)*(short *)(iVar3 + 0x22),10);

    iVar1 = *(int *)(param_1 + 0x50);

    if (((*(int *)(iVar3 + 0x28) == *(int *)(iVar1 + 0x160)) &&

        (*(int *)(iVar3 + 0x2c) == *(int *)(iVar1 + 0x164))) &&

       (*(char *)(iVar3 + 0x30) == *(char *)(iVar1 + 0x168))) {

      bVar2 = true;

    }

    else {

      bVar2 = false;

    }

    cVar4 = BitStream_writeFlag(!bVar2);

    if (cVar4 != '\0') {

      local_4 = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x2c);

      local_8 = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x28);

      BitStream_writeBits(0x40,&local_8);

      BitStream_writeFlag(*(uint8_t *)(iVar3 + 0x30));

    }

  }

  BitStream_writeBits(param_4 * 8 + -0x1c0,iVar3 + 0x38);

  return;

}
