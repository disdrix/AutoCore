// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_RecvCreateCharacter_004d9f00
// -----------------------------------------------------------------------------
// Stable ID: aa_004d9f00
// Callee of Named_CalleeOf_Client_RecvCreateCharacter
// Address:   0x004d9f00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_RecvCreateCharacter: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~111 non-empty decompiler lines.
//  - Control keywords: if×7, while×2, for×1, do×1, return×1.
//  - Notable callees: FUN_004022a0×2, CONCAT31, FUN_00404bc0, FUN_004294f0, FUN_004bb160, FUN_004d1d00, FUN_004d9f00, FUN_004e5940.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_RecvCreateCharacter
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Client_RecvCreateCharacter_004d9f00(int param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int *unaff_EBX;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  float10 fVar6;

  uint32_t /* width from decompiler */ auStack_a0 [11];

  uint32_t /* width from decompiler */ uStack_74;

  uint32_t /* width from decompiler */ uStack_70;

  uint32_t /* width from decompiler */ *puStack_6c;

  uint32_t /* width from decompiler */ uStack_50;

  float fStack_4c;

  int iStack_48;

  uint32_t /* width from decompiler */ uStack_44;

  uint32_t /* width from decompiler */ local_40 [4];

  float local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  int iStack_24;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  

  local_28 = 0;

  local_2c = 0;

  local_30 = 0.0;

  puVar4 = local_40;

  puVar5 = auStack_a0;

  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar5 = *puVar4;

    puVar4 = puVar4 + 1;

    puVar5 = puVar5 + 1;

  }

  FUN_004e6fb0(0);

  if (*(int *)(param_1 + 0xe8a0) != 0) {

    local_18 = DAT_009cbf68;

    local_14 = DAT_009cbf6c;

    local_28 = 0;

    local_2c = 0;

    local_30 = 0.0;

    local_10 = DAT_009cbf70;

    local_c = DAT_009cbf74;

    iVar3 = FUN_00404bc0();

    iStack_48 = iVar3;

    if (iVar3 != 0) {

      uStack_50 = 0;

      FUN_004294f0();

      puStack_6c = &uStack_50;

      uStack_70 = 0x4d9fc0;

      iVar2 = FUN_004022a0();

      while (iVar2 == 0) {

        iVar2 = (**(code **)(*unaff_EBX + 0x1e8))();

        if (((iVar2 != 0) && (*(char *)(iVar2 + 0xe2) != '\0')) &&

           (puVar4 = *(uint32_t /* width from decompiler */ **)(iVar2 + 0x148), puVar4 != *(uint32_t /* width from decompiler */ **)(iVar2 + 0x14c))) {

          do {

            puStack_6c = (uint32_t /* width from decompiler */ *)*puVar4;

            uStack_70 = 0;

            uStack_74 = 0x4da025;

            iVar3 = FUN_004bb160();

            if ((iVar3 != 0) && (*(char *)(iVar3 + 0x1d1) == '\n')) {

              puVar5 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 0x164 + iVar2);

              uStack_44 = *puVar5;

              local_40[0] = puVar5[1];

              local_40[1] = puVar5[2];

              local_40[2] = puVar5[3];

              (**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) + 0x144))();

              iVar1 = *(int *)(*(int *)(iVar2 + 4) + 4);

              puStack_6c = *(uint32_t /* width from decompiler */ **)(iVar1 + 0x84 + iVar2);

              local_2c = *(uint32_t /* width from decompiler */ *)(iVar1 + iVar2 + 0x8c);

              local_40[3] = puStack_6c;

              if (*(int *)(param_1 + 0xe4e0) == 0) {

                local_30 = 0.0;

              }

              else {

                uStack_70 = 0x4da0b6;

                fVar6 = (float10)FUN_005a58c0();

                local_30 = (float)fVar6;

                fStack_4c = local_30;

              }

              local_28 = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x1fc);

              local_c = CONCAT31(local_c._1_3_,0xff);

              if ((int)*(float *)(iVar3 + 0x260) == 0) {

                iStack_24 = -1;

              }

              else {

                iStack_24 = (int)*(float *)(iVar3 + 0x260) + -10;

              }

              puStack_6c = (uint32_t /* width from decompiler */ *)0x4da107;

              FUN_004e5940();

            }

            puVar4 = puVar4 + 2;

            iVar3 = iStack_48;

          } while (puVar4 != *(uint32_t /* width from decompiler */ **)(iVar2 + 0x14c));

        }

        puStack_6c = &uStack_50;

        uStack_70 = 0x4da12b;

        iVar2 = FUN_004022a0();

      }

      if (*(char *)(iVar3 + 0x28) != '\0') {

        *(uint8_t *)(iVar3 + 0x28) = 0;

        puStack_6c = (uint32_t /* width from decompiler */ *)0x4da147;

        LeaveCriticalSection((LPCRITICAL_SECTION)(iVar3 + 4));

      }

    }

    FUN_004d1d00();

  }

  return;

}
