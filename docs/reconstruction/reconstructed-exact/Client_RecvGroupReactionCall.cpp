// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×8, goto×2, for×1, do×1, while×1, return×1.
//  - Notable callees: Client_RecvGroupReactionCall×2, TFID_NotEquals×2, CVOGMap_SetVariable, FUN_004bb160, Object_ResolveFromTFID, object.
//  - Return sites: 1.

// =============================================================================
// Client_RecvGroupReactionCall
// -----------------------------------------------------------------------------
// Stable ID: aa_008092a0
// Address:   0x008092a0  (autoassault.exe, image base 0x400000)
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

/* Client_RecvGroupReactionCall  (opcode 0x206C)

   

   Apply packed LogicStateChange entries: fire reaction on resolved object (vtable+0x2c0)

   or CVOGMap_SetVariable for variable entries.

   Server soft-pedals this packet ~500ms after dialog turn-in to avoid stacking UI/FX loads. */



void Client_RecvGroupReactionCall(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  void *pvVar4;

  byte bVar5;

  

  bVar5 = 0;

  if (*(char *)(param_2 + 4) != '\0') {

    do {

      iVar1 = param_2 + (uint)bVar5 * 0x28;

      if (*(char *)(param_2 + 0xc + (uint)bVar5 * 0x28) == '\0') {

        if (*(char *)(iVar1 + 0x28) == '\0') {

LAB_0080934b:

          piVar3 = (int *)FUN_004bb160(0,*(uint32_t /* width from decompiler */ *)(iVar1 + 0x10),*(uint32_t /* width from decompiler */ *)(iVar1 + 0x14)

                                      );

          if (piVar3 != (int *)0x0) {

            pvVar4 = Object_ResolveFromTFID((TFID_16 *)(iVar1 + 0x18));

            (**(code **)(*piVar3 + 0x2c0))(pvVar4);

          }

        }

        else if (*(int *)(param_1 + 0xe98) != 0) {

          iVar2 = *(int *)(*(int *)(param_1 + 0xe98) + 0x250);

          if (iVar2 == 0) {

            pvVar4 = (void *)(*(int *)(*(int *)(*(int *)(param_1 + 0xe98) + 4) + 4) + 0x164 +

                             *(int *)(param_1 + 0xe98));

          }

          else {

            iVar2 = TFID_NotEquals((void *)(iVar1 + 0x18),

                                   (void *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 0x164 + iVar2));

            if ((char)iVar2 == '\0') goto LAB_0080934b;

            pvVar4 = (void *)(*(int *)(*(int *)(*(int *)(param_1 + 0xe98) + 4) + 4) + 0x164 +

                             *(int *)(param_1 + 0xe98));

          }

          iVar2 = TFID_NotEquals((void *)(iVar1 + 0x18),pvVar4);

          if ((char)iVar2 == '\0') goto LAB_0080934b;

        }

      }

      else {

        CVOGMap_SetVariable(*(uint32_t /* width from decompiler */ *)(iVar1 + 0x10),*(uint32_t /* width from decompiler */ *)(iVar1 + 0x14),0);

      }

      bVar5 = bVar5 + 1;

    } while (bVar5 < *(byte *)(param_2 + 4));

  }

  return;

}
