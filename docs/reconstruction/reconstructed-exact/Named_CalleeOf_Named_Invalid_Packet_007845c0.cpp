// =============================================================================
// Named_CalleeOf_Named_Invalid_Packet_007845c0
// -----------------------------------------------------------------------------
// Stable ID: aa_007845c0
// Callee of Named_Invalid_Packet (+5 other named callers)
// Address:   0x007845c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Invalid_Packet: packet/network helper. Evidence string: "IPX:%.2X%.2X%.2X%.2X:%.2X%.2X%.2X%.2X%.2X%.2X:%d". Supports parent flow (not a free-standing entry point). Named_Invalid_Packet (+5 other named callers).
// Embedded strings (evidence):
//   - "IPX:%.2X%.2X%.2X%.2X:%.2X%.2X%.2X%.2X%.2X%.2X:%d"
//   - "IP:Broadcast:%d"
//   - "IP:%d.%d.%d.%d:%d"
//   - "IP:Any:%d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: FUN_007831c0×3, CONCAT22×2, htonl×2, ntohs×2, FUN_00784490, FUN_007845c0.
//  - Strings: "IPX:%.2X%.2X%.2X%.2X:%.2X%.2X%.2X%.2X%.2X%.2X:%d"; "IP:Broadcast:%d"; "IP:%d.%d.%d.%d:%d"; "IP:Any:%d".
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_Invalid_Packet (+5 other named callers)
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

undefined * __fastcall Named_CalleeOf_Named_Invalid_Packet_007845c0(short *param_1)



{

  uint uVar1;

  uint uVar2;

  u_short uVar3;

  u_long uVar4;

  char *pcVar5;

  u_short uStack_e;

  uint16_t local_c;

  uint16_t uStack_a;

  

  if ((*param_1 != 0) && (*param_1 != 1)) {

    uVar1 = *(uint *)(param_1 + 4);

    uVar2 = *(uint *)(param_1 + 2);

    FUN_007831c0(&DAT_00d1fd78,"IPX:%.2X%.2X%.2X%.2X:%.2X%.2X%.2X%.2X%.2X%.2X:%d",uVar2 >> 0x18,

                 uVar2 >> 0x10 & 0xff,uVar2 >> 8 & 0xff,uVar2 & 0xff,uVar1 >> 0x18,

                 uVar1 >> 0x10 & 0xff,uVar1 >> 8 & 0xff,uVar1 & 0xff,

                 *(uint *)(param_1 + 6) >> 8 & 0xff,(char)param_1[6],param_1[1]);

    return &DAT_00d1fd78;

  }

  FUN_00784490();

  uVar4 = htonl(0xffffffff);

  if (CONCAT22(uStack_a,local_c) == uVar4) {

    uVar3 = ntohs(uStack_e);

    pcVar5 = "IP:Broadcast:%d";

  }

  else {

    uVar4 = htonl(0);

    if (CONCAT22(uStack_a,local_c) != uVar4) {

      uVar1 = *(uint *)(param_1 + 2);

      FUN_007831c0(&DAT_00d1fd78,"IP:%d.%d.%d.%d:%d",uVar1 >> 0x18,uVar1 >> 0x10 & 0xff,

                   uVar1 >> 8 & 0xff,uVar1 & 0xff,param_1[1]);

      return &DAT_00d1fd78;

    }

    uVar3 = ntohs(uStack_e);

    pcVar5 = "IP:Any:%d";

  }

  FUN_007831c0(&DAT_00d1fd78,pcVar5,uVar3);

  return &DAT_00d1fd78;

}
