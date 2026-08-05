// =============================================================================
// FUN_004dd940
// -----------------------------------------------------------------------------
// Stable ID: aa_004dd940
// Address:   0x004dd940  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004dd940 @ 0x004dd940
// Stable ID: aa_004dd940
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~150 non-empty decompiler lines.
//  - Control keywords: if×15, goto×4, while×3, return×3, for×2, switch×1, do×1.
//  - Notable callees: FUN_004db740×5, FUN_004bae00×2, FUN_004bb160×2, FUN_004e5810×2, CVOGReaction_ResolveObjectTarget, FUN_004bb1c0, FUN_004dbef0, FUN_004dd940.
//  - Return sites: 3.

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

void FUN_004dd940(void)



{

  short sVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  int iVar4;

  uint uVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint32_t /* width from decompiler */ uVar8;

  uint32_t /* width from decompiler */ uVar9;

  byte local_29;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint8_t local_20 [4];

  void *local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  uint8_t local_10 [4];

  void *local_c;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_24 = 0;

  iVar3 = FUN_004bae00(0,&local_24);

  while (iVar3 != 0) {

    if ((*(int *)(*(int *)(iVar3 + 0xa8) + 0x38) == 0x38) &&

       (iVar4 = __RTDynamicCast(iVar3,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,

                                &CVOGTrigger::RTTI_Type_Descriptor,0), iVar4 != 0)) {

      puVar2 = *(uint32_t /* width from decompiler */ **)(iVar4 + 0x14c);

      for (puVar6 = *(uint32_t /* width from decompiler */ **)(iVar4 + 0x148); puVar6 != puVar2; puVar6 = puVar6 + 2) {

        iVar4 = FUN_004bb160(0,*puVar6,puVar6[1]);

        if ((iVar4 != 0) && (*(int *)(*(int *)(iVar4 + 0xa8) + 0x38) == 0x3a)) {

          if (*(char *)(iVar4 + 0x1d1) == '\n') {

            uVar9 = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x164);

            uVar8 = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x160);

            uVar7 = 8;

          }

          else {

            if (*(char *)(iVar4 + 0x1d1) != '\x1d') goto LAB_004dda0e;

            uVar9 = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x164);

            uVar8 = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x160);

            uVar7 = 10;

          }

          FUN_004db740(iVar3,uVar7,uVar8,uVar9);

        }

LAB_004dda0e:

      }

    }

    if (((*(uint *)(iVar3 + 0x38) & *(uint *)(iVar3 + 0x3c)) != 0xffffffff) &&

       (*(int *)(*(int *)(iVar3 + 0xa8) + 0x38) != 0x36)) {

      FUN_004dbef0(iVar3,0,*(uint *)(iVar3 + 0x38),*(uint *)(iVar3 + 0x3c),0xffffffff);

    }

    iVar4 = FUN_004bb1c0(0,*(uint32_t /* width from decompiler */ *)(iVar3 + 0x38),*(uint32_t /* width from decompiler */ *)(iVar3 + 0x3c));

    if ((iVar4 != 0) &&

       (*(int *)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 0xac + iVar4) + 0x38) == 0x38)) {

      puVar2 = *(uint32_t /* width from decompiler */ **)(iVar4 + 0x14c);

      for (puVar6 = *(uint32_t /* width from decompiler */ **)(iVar4 + 0x148); puVar6 != puVar2; puVar6 = puVar6 + 2) {

        iVar4 = FUN_004bb160(0,*puVar6,puVar6[1]);

        if ((iVar4 != 0) && (*(int *)(*(int *)(iVar4 + 0xa8) + 0x38) == 0x3a)) {

          switch(*(uint8_t *)(iVar4 + 0x1d1)) {

          case 0x28:

            local_28 = 5;

            break;

          case 0x29:

            local_28 = 4;

            break;

          case 0x2a:

            local_28 = 6;

            break;

          default:

            goto switchD_004ddace_caseD_2b;

          case 0x34:

            local_28 = 3;

            break;

          case 0x3a:

            local_28 = 0xb;

            break;

          case 0x3b:

            local_28 = 0xc;

            break;

          case 0x47:

            local_28 = 0xd;

            break;

          case 0x50:

            local_28 = 0x11;

            break;

          case 0x56:

            local_28 = 0x12;

            break;

          case 0x57:

            local_28 = 0x13;

          }

          FUN_004db740(iVar3,local_28,*(uint32_t /* width from decompiler */ *)(iVar4 + 0x160),*(uint32_t /* width from decompiler */ *)(iVar4 + 0x164))

          ;

        }

switchD_004ddace_caseD_2b:

      }

    }

    iVar3 = FUN_004bae00(0,&local_24);

  }

  local_29 = 0;

  do {

    while( true ) {

      iVar3 = FUN_004e5810(local_20);

      if (*(int *)(iVar3 + 4) == 0) {

        uVar5 = 0;

      }

      else {

        uVar5 = *(int *)(iVar3 + 8) - *(int *)(iVar3 + 4) >> 3;

      }

      if (local_1c != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(local_1c);

      }

      local_1c = (void *)0x0;

      local_18 = 0;

      local_14 = 0;

      if (uVar5 <= local_29) {

        return;

      }

      iVar3 = FUN_004e5810(local_10);

      puVar6 = (uint32_t /* width from decompiler */ *)(*(int *)(iVar3 + 4) + (uint)local_29 * 8);

      iVar3 = CVOGReaction_ResolveObjectTarget(0,*puVar6,puVar6[1]);

      if (local_c != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(local_c);

      }

      local_c = (void *)0x0;

      local_8 = 0;

      local_4 = 0;

      if (iVar3 != 0) break;

LAB_004ddc4f:

      local_29 = local_29 + 1;

    }

    sVar1 = *(short *)(*(int *)(*(int *)(iVar3 + 0xa8) + 0x3c) + 0x3f4);

    if (sVar1 == 0xd) {

      FUN_004db740(iVar3,0xf,0,0);

      goto LAB_004ddc4f;

    }

    if (sVar1 == 0xe) {

      FUN_004db740(iVar3,0xe,0,0);

      local_29 = local_29 + 1;

    }

    else {

      if (sVar1 != 0xf) goto LAB_004ddc4f;

      FUN_004db740(iVar3,0x10,0,0);

      local_29 = local_29 + 1;

    }

  } while( true );

}
