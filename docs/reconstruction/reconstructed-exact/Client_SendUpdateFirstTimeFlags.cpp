// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: Client_SendUpdateFirstTimeFlags, EMSG_Sector_UpdateFirstTimeFlags_Request, FirstTimeFlags, dwords.
//  - Return sites: 1.

// =============================================================================
// Client_SendUpdateFirstTimeFlags
// -----------------------------------------------------------------------------
// Stable ID: aa_0092c6d0
// Address:   0x0092c6d0  (autoassault.exe, image base 0x400000)
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

/* Send EMSG_Sector_UpdateFirstTimeFlags_Request (0x20B1).

   Payload: opcode + 4x uint32 FirstTimeFlags (size 0x14).

   ESI = game state; EDX = pointer to 4 dwords (char+0xD30 or copy).

   Copies flags into local player char+0xD30 then sends via connection vtable+0x18.

   AutoCore: UpdateFirstTimeFlagsRequestPacket / HandleUpdateFirstTimeFlagsRequest. */



void __fastcall Client_SendUpdateFirstTimeFlags(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ *param_2)



{

  int iVar1;

  byte bVar2;

  int unaff_ESI;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  if ((*(int *)(unaff_ESI + 0xe98) != 0) && (param_2 != (uint32_t /* width from decompiler */ *)0x0)) {

    bVar2 = 0;

    iVar1 = 0xd30;

    do {

      *(uint32_t /* width from decompiler */ *)(iVar1 + *(int *)(unaff_ESI + 0xe98)) =

           *(uint32_t /* width from decompiler */ *)((int)param_2 + iVar1 + -0xd30);

      bVar2 = bVar2 + 1;

      iVar1 = iVar1 + 4;

    } while (bVar2 < 4);

    local_10 = *param_2;

    local_c = param_2[1];

    local_8 = param_2[2];

    local_4 = param_2[3];

    local_14 = 0x20b1;

    if (*(int *)(unaff_ESI + 0xc78) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0xc78) + 0x18))(0xffffffff,&local_14,0x14,0);

    }

  }

  return;

}
