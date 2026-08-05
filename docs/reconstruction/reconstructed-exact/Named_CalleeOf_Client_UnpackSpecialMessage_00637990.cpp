// =============================================================================
// Named_CalleeOf_Client_UnpackSpecialMessage_00637990
// -----------------------------------------------------------------------------
// Stable ID: aa_00637990
// Callee of Client_UnpackSpecialMessage
// Address:   0x00637990  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_UnpackSpecialMessage: event/notify helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~114 non-empty decompiler lines.
//  - Control keywords: if×4, for×2, do×1, while×1, return×1.
//  - Notable callees: BitStream_readBits×10, CONCAT31, FUN_0042b250, FUN_0042b270, FUN_0042b3a0, FUN_00637990, free, malloc.
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



uint32_t /* width from decompiler */ * Named_CalleeOf_Client_UnpackSpecialMessage_00637990(uint32_t /* width from decompiler */ *param_1,int *param_2)



{

  int *piVar1;

  uint uVar2;

  uint32_t /* width from decompiler */ *puVar3;

  void *pvVar4;

  int iVar5;

  uint8_t *puVar6;

  uint32_t /* width from decompiler */ *puVar7;

  uint32_t /* width from decompiler */ *puVar8;

  uint32_t /* width from decompiler */ *local_ca08;

  uint32_t /* width from decompiler */ local_ca04;

  uint32_t /* width from decompiler */ local_ca00;

  undefined **local_c9fc;

  void *local_c9f0;

  char local_c9e8;

  uint32_t /* width from decompiler */ local_c8c4 [2];

  uint8_t local_c8bc [120];

  uint32_t /* width from decompiler */ *local_c844;

  uint32_t /* width from decompiler */ *local_c840;

  uint32_t /* width from decompiler */ *local_c83c;

  uint32_t /* width from decompiler */ *local_c838;

  uint8_t local_c834 [2072];

  ushort local_c01c;

  uint32_t /* width from decompiler */ *local_c014;

  uint32_t /* width from decompiler */ local_c010;

  uint8_t local_c00c [49148];

  uint32_t /* width from decompiler */ uStack_10;

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  puStack_8 = &LAB_009a8de8;

  local_c = ExceptionList;

  uStack_10 = 0x6379af;

  local_ca00 = 0;

  local_c83c = (uint32_t /* width from decompiler */ *)0x0;

  local_c840 = (uint32_t /* width from decompiler */ *)0x0;

  local_c844 = (uint32_t /* width from decompiler */ *)0x0;

  local_c8c4[0] = 0x2005;

  local_4 = 1;

  ExceptionList = &local_c;

  FUN_0042b3a0(param_2[3],param_2[4]);

  local_4 = CONCAT31(local_4._1_3_,2);

  BitStream_readBits(0x3c0,local_c8bc);

  BitStream_readBits(0x20,&local_ca08);

  local_c838 = local_ca08;

  BitStream_readBits(0x40,&local_ca08);

  local_c014 = local_ca08;

  local_c010 = local_ca04;

  BitStream_readBits(0x10,&local_ca08);

  local_c01c = (ushort)local_ca08;

  uVar2 = (uint)local_ca08 & 0xffff;

  if (uVar2 != 0) {

    puVar6 = local_c00c;

    do {

      BitStream_readBits(0xc0,puVar6);

      puVar6 = puVar6 + 0x18;

      uVar2 = uVar2 - 1;

    } while (uVar2 != 0);

  }

  BitStream_readBits(0x20,&local_ca08);

  local_c844 = local_ca08;

  BitStream_readBits(0x20,&local_ca08);

  local_c840 = local_ca08;

  BitStream_readBits(0x20,&local_ca08);

  local_c83c = local_ca08;

  BitStream_readBits(0x10,&local_ca08);

  BitStream_readBits(((uint)local_ca08 & 0xffff) * 8,local_c834);

  uVar2 = (local_c01c + 0x5d) * 0x18;

  puVar3 = operator_new(0x18);

  local_4._0_1_ = 3;

  local_ca08 = puVar3;

  if (puVar3 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar3 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    FUN_0042b250();

    *puVar3 = &PTR_LAB_009d7b00;

    puVar3[4] = uVar2;

    pvVar4 = malloc(uVar2);

    puVar3[3] = pvVar4;

    *(uint8_t *)(puVar3 + 5) = 1;

  }

  puVar7 = local_c8c4;

  puVar8 = (uint32_t /* width from decompiler */ *)puVar3[3];

  for (uVar2 = uVar2 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {

    *puVar8 = *puVar7;

    puVar7 = puVar7 + 1;

    puVar8 = puVar8 + 1;

  }

  for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {

    *(uint8_t *)puVar8 = *(uint8_t *)puVar7;

    puVar7 = (uint32_t /* width from decompiler */ *)((int)puVar7 + 1);

    puVar8 = (uint32_t /* width from decompiler */ *)((int)puVar8 + 1);

  }

  *param_1 = puVar3;

  puVar3[2] = puVar3[2] + 1;

  local_ca00 = 1;

  local_4._0_1_ = 1;

  local_c9fc = &PTR_LAB_009d7b00;

  if (local_c9e8 != '\0') {

    free(local_c9f0);

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
