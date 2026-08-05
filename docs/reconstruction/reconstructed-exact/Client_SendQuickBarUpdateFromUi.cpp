// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×3, for×1, return×1.
//  - Notable callees: index×2, Client_SendQuickBarUpdateFromUi, EMSG_Sector_QuickBarUpdate, RE, Registers, column, g_pSectorNetConnection_INFERRED, isItem.
//  - Return sites: 1.

// =============================================================================
// Client_SendQuickBarUpdateFromUi
// -----------------------------------------------------------------------------
// Stable ID: aa_00826720
// Address:   0x00826720  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
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

/* Client_SendQuickBarUpdateFromUi

   

   Builds and sends EMSG_Sector_QuickBarUpdate (0x2062) for the active QuickBar UI slot.

   

   Registers (custom / not pure __fastcall):

     ECX = QuickBarSlotPayload_INFERRED*  (kind@0, value@+8 as int64)

     ESI = QuickBar UI object (this from caller)

       ESI+0x500 = column index (byte)

       ESI+0x504 = page index (byte)

       absolute slot = page*10 + column

   

   Wire packet (16 bytes total, Client_SendSectorPacket size 0x10):

     +0x00 uint32 opcode = 0x2062

     +0x04 uint8  slot

     +0x05 uint8  isItem  (0 if kind==1 skill, 1 otherwise)

     +0x06 uint16 pad     (uninitialized on stack)

     +0x08 int64  value   (skillId sign-extended OR item COID)

   

   Transport: g_pSectorNetConnection_INFERRED (DAT_00d1b4b8) vtable +0x18.

   No server ack expected; UI is optimistic. Login restore via CreateCharacterExtended.

   Verified: AutoCore QuickBarUpdate session RE (2026-07). */



void __fastcall Client_SendQuickBarUpdateFromUi(QuickBarSlotPayload_INFERRED *pSlot)



{

  int unaff_ESI;

  uint dwOpcode;

  byte bSlot;

  byte bIsItem;

  uint dwValueLo;

  uint dwValueHi;

  

  if (pSlot != (QuickBarSlotPayload_INFERRED *)0x0) {

                    /* slot = page(ESI+0x504)*10 + column(ESI+0x500) */

    bSlot = *(char *)(unaff_ESI + 0x504) * '\n' + *(char *)(unaff_ESI + 0x500);

                    /* isItem = (kind != QuickBarSlotKind_Skill / 1) */

    bIsItem = pSlot->nKind != QuickBarSlotKind_Skill;

    dwValueLo = pSlot->dwValueLo;

    dwValueHi = pSlot->dwValueHi;

                    /* opcode EMSG_Sector_QuickBarUpdate = 0x2062 */

    dwOpcode = 0x2062;

    if (g_pSectorNetConnection_INFERRED != (void *)0x0) {

      (**(code **)(*(int *)g_pSectorNetConnection_INFERRED + 0x18))(0xffffffff,&dwOpcode,0x10,0);

    }

  }

  return;

}
