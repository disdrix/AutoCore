// READABILITY (auto CF):
//  - Body size: ~61 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: Client_SendRespawnInSector, Client_SendSectorPacket, FUN_00402ae0, FUN_00404a20, FUN_00404c90, FUN_007fc840, countdown, opcode.
//  - Strings: "Returning you to nearest repair station...".
//  - Return sites: 1.

// =============================================================================
// Client_SendRespawnInSector
// -----------------------------------------------------------------------------
// Stable ID: aa_00935300
// Address:   0x00935300  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

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

/* Client_SendRespawnInSector - INC airlift request (C2S).

   

   EMSG: EMSG_Sector_RespawnInSector = 0x2073

   Wire size: 0x28 bytes including opcode (FUN_00807460 size arg).

   

   Layout:

     +0x00 uint32  opcode 0x2073

     +0x04 float3  current vehicle position (NOT destination)

     +0x10 float4  current vehicle quaternion

     +0x20 int64   entity COID at client 0xe98 (live: CHARACTER coid, not vehicle)

   

   Called after INC option 0 countdown ("Returning you to nearest repair station...").

   Server resolves dest from LastStation* / pad pose and replies with SpecialEvent type Respawn.

   

   AutoCore: RespawnInSectorPacket + RespawnManager */



void Client_SendRespawnInSector(void)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  uint32_t /* width from decompiler */ *puVar4;

  void *unaff_ESI;

  uint8_t local_3c [4];

  uint32_t /* width from decompiler */ local_38;

  uint32_t /* width from decompiler */ local_34;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  float local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  

  iVar1 = *(int *)((int)unaff_ESI + 0xe98);

  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x250) != 0)) {

    piVar3 = (int *)FUN_00402ae0(local_3c);

    if (*piVar3 == *(int *)((int)unaff_ESI + 0xd28)) {

      local_2c = 0;

      local_30 = 0;

      local_34 = 0;

      local_20 = 0;

      local_24 = 0;

      local_28 = 0;

      local_1c = g_flMsToSeconds_Inferred;

      local_38 = 0x2073;

                    /* opcode 0x2073 RespawnInSector - full packet starts at local_38, size 0x28

                        */

      puVar4 = (uint32_t /* width from decompiler */ *)FUN_00404c90();

      local_34 = *puVar4;

      local_30 = puVar4[1];

      local_2c = puVar4[2];

      puVar4 = (uint32_t /* width from decompiler */ *)FUN_00404a20();

      local_28 = *puVar4;

      local_24 = puVar4[1];

      local_20 = puVar4[2];

      local_1c = (float)puVar4[3];

      iVar2 = *(int *)(*(int *)(iVar1 + 4) + 4);

      local_18 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x164 + iVar1);

      local_14 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x168 + iVar1);

      Client_SendSectorPacket(unaff_ESI,0x28,&local_38);

      FUN_007fc840();

    }

  }

  return;

}
