// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: BitStream_readBits, CONCAT31, FUN_0042d650, FUN_0042d770, FUN_00783aa0, FUN_00783b60, FUN_007845c0.
//  - Strings: "LogNetInterface"; "Received Connect Challenge Request from %s".
//  - Return sites: 1.

// =============================================================================
// Mission_Received_Connect_Challenge_Request_from_s_0042d650
// -----------------------------------------------------------------------------
// Stable ID: aa_0042d650
// Address:   0x0042d650  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "Received Connect Challenge Request from %s"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void Mission_Received_Connect_Challenge_Request_from_s_0042d650(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  byte bVar1;

  uint uVar2;

  uint32_t /* width from decompiler */ uVar3;

  int unaff_ESI;

  bool bVar4;

  uint local_c;

  uint8_t local_8 [8];

  

  if ((_DAT_00d20bf0 & 1) == 0) {

    _DAT_00d20bf0 = _DAT_00d20bf0 | 1;

    DAT_00d20bec = FUN_00783b60("LogNetInterface");

  }

  if (*(char *)(DAT_00d20bec + 4) != '\0') {

    DAT_00d179a0 = DAT_00d20bec;

    uVar3 = FUN_007845c0();

    FUN_00783aa0("Received Connect Challenge Request from %s",uVar3);

    DAT_00d179a0 = 0;

  }

  if (*(char *)(param_1 + 0x90) != '\0') {

    BitStream_readBits(0x40,local_8);

    uVar2 = *(uint *)(unaff_ESI + 0x18);

    if (*(uint *)(unaff_ESI + 0x2c) < uVar2) {

      *(uint8_t *)(unaff_ESI + 0x1c) = 1;

      local_c = local_c & 0xffffff00;

    }

    else {

      bVar1 = *(byte *)((uVar2 >> 3) + *(int *)(unaff_ESI + 0xc));

      *(uint *)(unaff_ESI + 0x18) = uVar2 + 1;

      local_c = CONCAT31((int3)(uVar2 >> 8),(bVar1 & (byte)(1 << ((byte)uVar2 & 7))) != 0);

    }

    uVar2 = *(uint *)(unaff_ESI + 0x18);

    if (*(uint *)(unaff_ESI + 0x2c) < uVar2) {

      *(uint8_t *)(unaff_ESI + 0x1c) = 1;

      bVar4 = false;

    }

    else {

      bVar4 = (*(byte *)((uVar2 >> 3) + *(int *)(unaff_ESI + 0xc)) & (byte)(1 << ((byte)uVar2 & 7)))

              != 0;

      *(uint *)(unaff_ESI + 0x18) = uVar2 + 1;

    }

    FUN_0042d770(param_3,param_2,local_c,bVar4);

  }

  return;

}
