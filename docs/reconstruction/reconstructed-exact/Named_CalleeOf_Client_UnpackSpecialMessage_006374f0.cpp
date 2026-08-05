// =============================================================================
// Named_CalleeOf_Client_UnpackSpecialMessage_006374f0
// -----------------------------------------------------------------------------
// Stable ID: aa_006374f0
// Callee of Client_UnpackSpecialMessage
// Address:   0x006374f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_UnpackSpecialMessage: event/notify helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~132 non-empty decompiler lines.
//  - Control keywords: if×7, for×2, do×1, while×1, return×1.
//  - Notable callees: BitStream_readBits×5, BitStream_readInt, CONCAT31, FUN_0042b250, FUN_0042b270, FUN_0042b3a0, FUN_006374f0, free.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_UnpackSpecialMessage
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

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



uint32_t /* width from decompiler */ * Named_CalleeOf_Client_UnpackSpecialMessage_006374f0(uint32_t /* width from decompiler */ *param_1,int *param_2)



{

  int *piVar1;

  uint32_t /* width from decompiler */ *puVar2;

  void *pvVar3;

  bool bVar4;

  uint uVar5;

  uint uVar6;

  uint *puVar7;

  uint32_t /* width from decompiler */ *puVar8;

  uint32_t /* width from decompiler */ *puVar9;

  byte local_293d;

  ushort local_293c [2];

  uint32_t /* width from decompiler */ *local_2938;

  uint local_2934;

  uint32_t /* width from decompiler */ local_2930;

  uint local_292c;

  uint local_2928;

  undefined **local_2924;

  void *local_2918;

  char local_2910;

  uint local_290c;

  uint8_t local_2908;

  uint local_28f8;

  uint32_t /* width from decompiler */ local_27ec;

  byte local_27e8;

  uint local_27dc [2547];

  uint32_t /* width from decompiler */ uStack_10;

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  puStack_8 = &LAB_009a8d54;

  local_c = ExceptionList;

  uStack_10 = 0x63750f;

  local_2930 = 0;

  local_4 = 1;

  local_27ec = 0x206c;

  ExceptionList = &local_c;

  FUN_0042b3a0(param_2[3],param_2[4]);

  local_4 = CONCAT31(local_4._1_3_,2);

  BitStream_readBits(8,&local_293d);

  local_27e8 = local_293d;

  if (local_293d != 0) {

    local_2934 = (uint)local_293d;

    puVar7 = local_27dc;

    do {

      BitStream_readBits(8,&local_293d);

      *(byte *)(puVar7 + -1) = local_293d;

      if (local_293d == 1) {

        BitStream_readBits(0x10,local_293c);

        *puVar7 = (uint)local_293c[0];

        BitStream_readBits(0x20,&local_2938);

        puVar7[1] = (uint)local_2938;

      }

      else {

        uVar6 = BitStream_readInt(0x13);

        *puVar7 = uVar6;

        puVar7[1] = 0;

        BitStream_readBits(0x40,&local_292c);

        puVar7[2] = local_292c;

        puVar7[3] = local_2928;

        if (local_28f8 < local_290c) {

          local_2908 = 1;

          bVar4 = false;

        }

        else {

          bVar4 = (*(byte *)((local_290c >> 3) + (int)local_2918) &

                  (byte)(1 << ((byte)local_290c & 7))) != 0;

          local_290c = local_290c + 1;

        }

        *(bool *)(puVar7 + 4) = bVar4;

        if (local_28f8 < local_290c) {

          local_2908 = 1;

          bVar4 = false;

        }

        else {

          bVar4 = (*(byte *)((local_290c >> 3) + (int)local_2918) &

                  (byte)(1 << ((byte)local_290c & 7))) != 0;

          local_290c = local_290c + 1;

        }

        *(bool *)(puVar7 + 6) = bVar4;

      }

      puVar7 = puVar7 + 10;

      local_2934 = local_2934 - 1;

    } while (local_2934 != 0);

  }

  uVar6 = (uint)local_27e8 * 0x28 + 1;

  puVar2 = operator_new(0x18);

  local_4._0_1_ = 3;

  local_2938 = puVar2;

  if (puVar2 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar2 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    FUN_0042b250();

    *puVar2 = &PTR_LAB_009d7b00;

    puVar2[4] = uVar6;

    pvVar3 = malloc(uVar6);

    puVar2[3] = pvVar3;

    *(uint8_t *)(puVar2 + 5) = 1;

  }

  puVar8 = &local_27ec;

  puVar9 = (uint32_t /* width from decompiler */ *)puVar2[3];

  for (uVar5 = uVar6 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

    *puVar9 = *puVar8;

    puVar8 = puVar8 + 1;

    puVar9 = puVar9 + 1;

  }

  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {

    *(uint8_t *)puVar9 = *(uint8_t *)puVar8;

    puVar8 = (uint32_t /* width from decompiler */ *)((int)puVar8 + 1);

    puVar9 = (uint32_t /* width from decompiler */ *)((int)puVar9 + 1);

  }

  *param_1 = puVar2;

  puVar2[2] = puVar2[2] + 1;

  local_2930 = 1;

  local_4._0_1_ = 1;

  local_2924 = &PTR_LAB_009d7b00;

  if (local_2910 != '\0') {

    free(local_2918);

  }

  FUN_0042b270();

  piVar1 = param_2 + 2;

  *piVar1 = *piVar1 + -1;

  local_4 = (uint)local_4._1_3_ << 8;

  if (*piVar1 == 0) {

    (**(code **)(*param_2 + 8))();

  }

  ExceptionList = local_c;

  return param_1;

}
