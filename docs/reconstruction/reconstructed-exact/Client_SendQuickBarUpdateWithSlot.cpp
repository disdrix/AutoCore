// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: CL, Client_SendQuickBarUpdateWithSlot, EAX, EMSG_Sector_QuickBarUpdate, RE, Sector_QuickBarUpdatePacket, index.
//  - Return sites: 1.

// =============================================================================
// Client_SendQuickBarUpdateWithSlot
// -----------------------------------------------------------------------------
// Stable ID: aa_007fc100
// Address:   0x007fc100  (autoassault.exe, image base 0x400000)
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

/* Client_SendQuickBarUpdateWithSlot

   

   Same EMSG_Sector_QuickBarUpdate (0x2062) wire layout as Client_SendQuickBarUpdateFromUi,

   but slot is supplied in CL and payload pointer in EAX (custom register convention).

   

     EAX = QuickBarSlotPayload_INFERRED*

     CL  = absolute slot index (0..99)

   

   Packet stack buffer: Sector_QuickBarUpdatePacket (16 bytes).

   isItem = (payload->kind != 1). value = payload int64 at +8.

   

   INFERRED calling convention: registers, not standard stdcall.

   Verified: AutoCore QuickBarUpdate session RE (2026-07). */



void Client_SendQuickBarUpdateWithSlot(void)



{

  int *in_EAX;

  uint dwOpcode;

  byte bIsItem;

  uint dwValueLo;

  uint dwValueHi;

  

  if (in_EAX != (int *)0x0) {

    bIsItem = *in_EAX != 1;

                    /* slot from CL (absolute 0..99) */

    dwValueLo = in_EAX[2];

    dwValueHi = in_EAX[3];

                    /* opcode 0x2062 QuickBarUpdate */

    dwOpcode = 0x2062;

    if (g_pSectorNetConnection_INFERRED != (void *)0x0) {

      (**(code **)(*(int *)g_pSectorNetConnection_INFERRED + 0x18))(0xffffffff,&dwOpcode,0x10,0);

    }

  }

  return;

}
