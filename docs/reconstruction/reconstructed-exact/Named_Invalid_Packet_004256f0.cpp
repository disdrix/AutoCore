// READABILITY (auto CF):
//  - Body size: ~60 non-empty decompiler lines.
//  - Control keywords: if×11, return×5, goto×1.
//  - Notable callees: FUN_00783aa0×2, FUN_00783b60×2, FUN_007845c0×2, FUN_00425530, FUN_004256f0, FUN_00425ac0, FUN_00425fe0, FUN_0042fe60.
//  - Strings: "LogNetConnection"; "NetConnection %s: RECVDROP - %d"; "NetConnection %s: RECV- %d bytes"; "Invalid Packet.".
//  - Return sites: 5.

// =============================================================================
// Named_Invalid_Packet_004256f0
// -----------------------------------------------------------------------------
// Stable ID: aa_004256f0
// Address:   0x004256f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "Invalid Packet."
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



void __thiscall Named_Invalid_Packet_004256f0(int *param_1,int param_2)



{

  double dVar1;

  char cVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  

  if ((float)param_1[0x32] != g_flZero) {

    iVar3 = FUN_00976080();

    dVar1 = (double)iVar3;

    if (iVar3 < 0) {

      dVar1 = dVar1 + _DAT_00aaa728;

    }

    if (dVar1 * _DAT_00aaa9d0 < (double)(float)param_1[0x32]) {

      if ((_DAT_00d20d88 & 1) == 0) {

        _DAT_00d20d88 = _DAT_00d20d88 | 1;

        DAT_00d20d84 = FUN_00783b60("LogNetConnection");

      }

      if (*(char *)(DAT_00d20d84 + 4) != '\0') {

        DAT_00d179a0 = DAT_00d20d84;

        uVar4 = FUN_007845c0(param_1[0x25]);

        FUN_00783aa0("NetConnection %s: RECVDROP - %d",uVar4);

        DAT_00d179a0 = 0;

        return;

      }

      return;

    }

  }

  if ((_DAT_00d20d88 & 2) == 0) {

    _DAT_00d20d88 = _DAT_00d20d88 | 2;

    DAT_00d20d80 = FUN_00783b60("LogNetConnection");

  }

  if (*(char *)(DAT_00d20d80 + 4) != '\0') {

    DAT_00d179a0 = DAT_00d20d80;

    uVar4 = FUN_007845c0(*(uint *)(param_2 + 0x2c) >> 3);

    FUN_00783aa0("NetConnection %s: RECV- %d bytes",uVar4);

    DAT_00d179a0 = 0;

  }

  DAT_00d0a290 = '\0';

  cVar2 = FUN_00425ac0(param_1);

  if (cVar2 == '\0') {

    return;

  }

  param_1[0x46] = *(int *)(param_1[0x6a] + 0x78);

  FUN_00425fe0(param_1);

  *(int *)(param_2 + 0x34) = param_1[0x73];

  (**(code **)(*param_1 + 0x30))(param_2);

  if (*(char *)(param_2 + 0x1c) != '\0') {

    if (DAT_00d0a290 != '\0') goto LAB_00425864;

    FUN_00425530("Invalid Packet.");

  }

  if (DAT_00d0a290 == '\0') {

    DAT_00d0a290 = 0;

    return;

  }

LAB_00425864:

  FUN_0042fe60();

  DAT_00d0a290 = 0;

  return;

}
