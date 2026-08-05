// =============================================================================
// FUN_00941d50
// -----------------------------------------------------------------------------
// Stable ID: aa_00941d50
// Address:   0x00941d50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00941d50 @ 0x00941d50
// Stable ID: aa_00941d50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~74 non-empty decompiler lines.
//  - Control keywords: if×8, return×5.
//  - Notable callees: Client_SendSectorPacket, Client_Skill_ResolveCastTarget, FUN_00514390, FUN_00941b20, FUN_00941d50, TFID_EqualsObjectId.
//  - Return sites: 5.

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

uint32_t /* width from decompiler */ FUN_00941d50(uint32_t /* width from decompiler */ param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  char cVar4;

  uint32_t /* width from decompiler */ uVar5;

  int iVar6;

  int iVar7;

  uint32_t /* width from decompiler */ *puVar8;

  void *unaff_ESI;

  int *unaff_EDI;

  uint32_t /* width from decompiler */ local_3c [4];

  uint32_t /* width from decompiler */ auStack_2c [2];

  int iStack_24;

  int iStack_20;

  uint32_t /* width from decompiler */ uStack_1c;

  uint32_t /* width from decompiler */ uStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  uint32_t /* width from decompiler */ uStack_10;

  uint8_t uStack_c;

  

  iVar6 = *(int *)((int)unaff_ESI + 0xe98);

  if ((((iVar6 != 0) && (*(int *)(iVar6 + 0x250) != 0)) && (unaff_EDI != (int *)0x0)) &&

     ((((uint)unaff_EDI[0x5f] >> 0x13 & 1) == 0 && (*(int *)(unaff_EDI[0x2a] + 0x38) != 0xe)))) {

    local_3c[0] = *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar6 + 4) + 4) + iVar6 + 0x170);

    if ((*(byte *)(*(int *)(unaff_EDI[0x2a] + 0x3c) + 0x3f2) & 0x80) == 0) {

      uVar5 = FUN_00941b20(unaff_EDI,param_1,1);

      return uVar5;

    }

    if (*(char *)(*(int *)((int)unaff_ESI + 0xe04) + 0xf6) == '\0') {

      cVar4 = FUN_00514390(iVar6,1);

      if (cVar4 != '\0') {

        iVar6 = *(int *)((int)unaff_ESI + 0xe98);

        if (*(int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 0xa4 + iVar6) != 0) {

          local_3c[0] = *(uint32_t /* width from decompiler */ *)

                         (*(int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 0xa4 + iVar6) + 0x16c);

        }

        iVar6 = (**(code **)(*unaff_EDI + 0x234))

                          (*(uint32_t /* width from decompiler */ *)(*(int *)(unaff_EDI[0x2a] + 0x3c) + 0x3bc));

        if (iVar6 != 0) {

          iVar7 = Skill_LocalCastValidate

                            ((void *)(*(int *)(*(int *)(*(int *)((int)unaff_ESI + 0xe98) + 4) + 4) +

                                      4 + *(int *)((int)unaff_ESI + 0xe98)),(void *)0x1,(char)iVar6,

                             (void *)0x0);

          if (iVar7 == 0) {

            puVar8 = (uint32_t /* width from decompiler */ *)

                     Client_Skill_ResolveCastTarget(local_3c,iVar6,&stack0xffffffb4,&DAT_00d1a630,1)

            ;

            uVar5 = *puVar8;

            uVar1 = puVar8[1];

            uVar2 = puVar8[2];

            uVar3 = puVar8[3];

            iVar6 = TFID_EqualsObjectId(&stack0xffffffb4,g_abTfidInvalid_A15870);

            if ((char)iVar6 != '\0') {

              return 0;

            }

            iStack_20 = unaff_EDI[0x59];

            iStack_24 = unaff_EDI[0x58];

            auStack_2c[0] = 0x2045;

            uStack_c = 0;

            uStack_1c = uVar5;

            uStack_18 = uVar1;

            uStack_14 = uVar2;

            uStack_10 = uVar3;

            Client_SendSectorPacket(unaff_ESI,0x28,auStack_2c);

            return 1;

          }

        }

      }

    }

    return 0;

  }

  return 0;

}
