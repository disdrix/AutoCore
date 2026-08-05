// =============================================================================
// FUN_0042d770
// -----------------------------------------------------------------------------
// Stable ID: aa_0042d770
// Address:   0x0042d770  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0042d770 @ 0x0042d770
// Stable ID: aa_0042d770
// Embedded strings (evidence for future rename):
//   - "LogNetInterface"
//   - "Sending Challenge Response: %8x"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~94 non-empty decompiler lines.
//  - Control keywords: if×8, return×1.
//  - Notable callees: BitStream_writeBits×5, BitStream_writeFlag×2, FUN_0042b7d0×2, FUN_0040b290, FUN_00424d10, FUN_0042c460, FUN_0042d770, FUN_00783aa0.
//  - Strings: "LogNetInterface"; "Sending Challenge Response: %8x".
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall FUN_0042d770(int param_1,int param_2,uint32_t /* width from decompiler */ param_3,char param_4,char param_5)



{

  int iVar1;

  char cVar2;

  uint32_t /* width from decompiler */ in_EAX;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint8_t local_715;

  int local_714;

  uint32_t /* width from decompiler */ local_710;

  undefined **local_70c;

  uint32_t /* width from decompiler */ local_708;

  uint32_t /* width from decompiler */ local_704;

  uint8_t *local_700;

  uint32_t /* width from decompiler */ local_6fc;

  uint8_t local_6f8;

  int local_6f4;

  uint8_t local_6f0;

  uint8_t local_6ef;

  uint32_t /* width from decompiler */ local_6e0;

  uint32_t /* width from decompiler */ local_6dc;

  uint32_t /* width from decompiler */ local_6d8;

  uint8_t local_6d4;

  uint8_t local_5d4 [1492];

  

  local_700 = local_5d4;

  local_708 = 0;

  local_704 = 0;

  local_6fc = 0x5d2;

  local_6f8 = 0;

  local_6e0 = 0x2e90;

  local_6dc = 0x2e90;

  local_6f4 = 0;

  local_6f0 = 0;

  local_6ef = 0;

  local_6d4 = 0;

  local_6d8 = 0;

  local_70c = &PTR_LAB_009d7ba4;

  local_715 = 1;

  BitStream_writeBits(8,&local_715);

  BitStream_writeBits(0x40,in_EAX);

  iVar3 = FUN_0042c460(param_1,param_3,in_EAX);

  local_714 = iVar3;

  BitStream_writeBits(0x20,&local_714);

  local_714 = *(int *)(param_1 + 0x50);

  local_710 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x54);

  iVar1 = *(int *)(param_1 + 0x44);

  BitStream_writeBits(0x40,&local_714);

  local_714 = iVar1;

  BitStream_writeBits(0x20,&local_714);

  if ((*(char *)(param_1 + 0x7c) == '\0') && ((param_4 == '\0' || (*(int *)(param_1 + 0x3c) == 0))))

  {

    uVar4 = 0;

  }

  else {

    uVar4 = 1;

  }

  cVar2 = BitStream_writeFlag(uVar4);

  if (cVar2 != '\0') {

    if ((param_5 == '\0') || (*(int *)(param_1 + 0x40) == 0)) {

      uVar4 = 0;

    }

    else {

      uVar4 = 1;

    }

    cVar2 = BitStream_writeFlag(uVar4);

    if (cVar2 == '\0') {

      local_714 = *(int *)(*(int *)(param_1 + 0x3c) + 0x18);

      if (local_714 != 0) {

        *(int *)(local_714 + 8) = *(int *)(local_714 + 8) + 1;

      }

      FUN_0042b7d0();

      FUN_0040b290();

    }

    else {

      FUN_0042b7d0();

    }

  }

  if ((_DAT_00d20be8 & 1) == 0) {

    _DAT_00d20be8 = _DAT_00d20be8 | 1;

    DAT_00d20be4 = FUN_00783b60("LogNetInterface");

  }

  if (*(char *)(DAT_00d20be4 + 4) != '\0') {

    DAT_00d179a0 = DAT_00d20be4;

    FUN_00783aa0("Sending Challenge Response: %8x",iVar3);

    DAT_00d179a0 = 0;

  }

  if (param_2 == 0) {

    param_2 = param_1 + 0x68;

  }

  FUN_00784d20(param_2,local_5d4,local_6f4 + 7U >> 3);

  FUN_00424d10();

  return;

}
