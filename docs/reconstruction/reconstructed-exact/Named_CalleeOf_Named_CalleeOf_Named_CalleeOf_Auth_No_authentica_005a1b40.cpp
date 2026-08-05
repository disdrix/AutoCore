// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Auth_No_authentica_005a1b40
// -----------------------------------------------------------------------------
// Stable ID: aa_005a1b40
// Callee of Named_CalleeOf_Named_CalleeOf_Auth_No_authentication_key
// Address:   0x005a1b40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Auth_No_authentication_key: input/binding helper. Evidence string: "Failed to bind on %s:%d". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "ip:%s:%d"
//   - "tcp:%s:%d"
//   - "Failed to bind on %s:%d"
//   - "Bound to %s"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~155 non-empty decompiler lines.
//  - Control keywords: if×13, return×3, do×2, while×2.
//  - Notable callees: FUN_00783c80×4, FUN_005a14f0×2, FUN_00784700×2, FUN_007a4480×2, _snprintf×2, FUN_004269e0, FUN_0042c2a0, FUN_0042c360.
//  - Strings: "%s:%s:%d"; "ip:%s:%d"; "tcp:%s:%d"; "Failed to bind on %s:%d".
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Auth_No_authentication_key
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Auth_No_authentica_005a1b40(int param_1)



{

  char *pcVar1;

  char cVar2;

  void *pvVar3;

  uint uVar4;

  uint32_t /* width from decompiler */ uVar5;

  int iVar6;

  undefined *puVar7;

  char *pcVar8;

  uint32_t /* width from decompiler */ *puVar9;

  uint32_t /* width from decompiler */ uVar10;

  uint uVar11;

  byte bVar12;

  uint32_t /* width from decompiler */ local_174;

  uint32_t /* width from decompiler */ local_170;

  uint32_t /* width from decompiler */ local_16c;

  uint32_t /* width from decompiler */ local_168;

  uint32_t /* width from decompiler */ local_164;

  uint8_t local_160 [20];

  uint8_t auStack_14c [60];

  char local_110 [259];

  char local_d;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a6251;

  local_c = ExceptionList;

  if (*(char *)(param_1 + 0xc) == '\0') {

    ExceptionList = &local_c;

    pvVar3 = operator_new(200);

    local_4 = 0;

    if (pvVar3 == (void *)0x0) {

      iVar6 = 0;

    }

    else {

      uVar4 = (uint)*(byte *)(param_1 + 0xa8);

      uVar10 = *(uint32_t /* width from decompiler */ *)(param_1 + 0xa4);

      uVar11 = (uint)*(byte *)(param_1 + 0xb4);

      uVar5 = FUN_00783c80(*(byte *)(param_1 + 0xa8) != 0,3,0);

      iVar6 = FUN_005a14f0(*(uint32_t /* width from decompiler */ *)(param_1 + 8),uVar5,uVar11,uVar10,uVar4);

    }

    *(int *)(param_1 + 0xb0) = iVar6;

    local_4 = 0xffffffff;

    *(uint8_t *)(iVar6 + 0x90) = 0;

    FUN_00783c80(0,3,0);

    local_d = 0;

    puVar7 = &DAT_009d8094;

    if (*(char *)(param_1 + 0xa8) == '\0') {

      puVar7 = &DAT_009d8090;

    }

    _snprintf(local_110,0x103,"%s:%s:%d",puVar7,param_1 + 0x14,*(uint32_t /* width from decompiler */ *)(param_1 + 0x10));

    FUN_00784700(local_110);

    pvVar3 = operator_new(0x2a0);

    local_4 = 1;

    if (pvVar3 == (void *)0x0) {

      iVar6 = 0;

    }

    else {

      iVar6 = FUN_005a1940();

    }

    local_4 = 0xffffffff;

    if (*(char *)(param_1 + 0xa8) != '\0') {

      *(uint16_t *)(*(int *)(param_1 + 0xb0) + 0xac) = 0x1e1;

      *(uint32_t /* width from decompiler */ *)(iVar6 + 0xb0) = 10;

      *(uint32_t /* width from decompiler */ *)(iVar6 + 0xac) = 3000;

    }

    *(uint *)(iVar6 + 0xb4) = *(uint *)(iVar6 + 0xb4) | 1;

    *(uint32_t /* width from decompiler */ *)(iVar6 + 0x250) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xa0);

    *(uint32_t /* width from decompiler */ *)(iVar6 + 600) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x98);

    *(uint32_t /* width from decompiler */ *)(iVar6 + 0x25c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x9c);

    FUN_004269e0(*(uint32_t /* width from decompiler */ *)(param_1 + 0xb0),local_160,0,0);

    ExceptionList = local_c;

    return;

  }

  uVar4 = 0;

  pcVar1 = (char *)(param_1 + 0x14);

  ExceptionList = &local_c;

  do {

    bVar12 = (byte)uVar4;

    FUN_00783c80(0,3,0);

    pcVar8 = pcVar1;

    do {

      cVar2 = *pcVar8;

      pcVar8 = pcVar8 + 1;

    } while (cVar2 != '\0');

    if (pcVar8 == (char *)(param_1 + 0x15)) {

      puVar9 = (uint32_t /* width from decompiler */ *)

               FUN_00783c80(*(char *)(param_1 + 0xa8) != '\0',3,

                            (ushort)bVar12 + *(short *)(param_1 + 0x10));

      local_174 = *puVar9;

      local_170 = puVar9[1];

      local_16c = puVar9[2];

      local_168 = puVar9[3];

      local_164 = puVar9[4];

    }

    else {

      if (*(char *)(param_1 + 0xa8) == '\0') {

        iVar6 = *(int *)(param_1 + 0x10);

        pcVar8 = "ip:%s:%d";

      }

      else {

        iVar6 = *(int *)(param_1 + 0x10);

        pcVar8 = "tcp:%s:%d";

      }

      local_d = cVar2;

      _snprintf(local_110,0x103,pcVar8,pcVar1,uVar4 + iVar6);

      FUN_00784700(local_110);

    }

    pvVar3 = operator_new(200);

    local_4 = 2;

    if (pvVar3 == (void *)0x0) {

      uVar10 = 0;

    }

    else {

      uVar10 = FUN_005a14f0(*(uint32_t /* width from decompiler */ *)(param_1 + 8),&local_174,*(uint8_t *)(param_1 + 0xb4),

                            *(uint32_t /* width from decompiler */ *)(param_1 + 0xa4),*(uint8_t *)(param_1 + 0xa8));

    }

    local_4 = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xb0) = uVar10;

    cVar2 = FUN_00783d60();

    if (cVar2 != '\0') break;

    if (*(int **)(param_1 + 0xb0) != (int *)0x0) {

      (**(code **)(**(int **)(param_1 + 0xb0) + 4))(1);

    }

    bVar12 = bVar12 + 1;

    uVar4 = (uint)bVar12;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xb0) = 0;

  } while (bVar12 < 0xfe);

  if (0xfd < bVar12) {

    FUN_007a4480(1,"Failed to bind on %s:%d",pcVar1,*(uint32_t /* width from decompiler */ *)(param_1 + 0x10));

    ExceptionList = local_c;

    return;

  }

  if (*(char *)(param_1 + 0xa8) != '\0') {

    *(uint16_t *)(*(int *)(param_1 + 0xb0) + 0xac) = 0x1e1;

  }

  FUN_0042c2a0(auStack_14c);

  uVar10 = FUN_007845c0();

  FUN_007a4480(0xffffffff,"Bound to %s",uVar10);

  pvVar3 = operator_new(0x24);

  local_4 = 3;

  if (pvVar3 == (void *)0x0) {

    uVar10 = 0;

  }

  else {

    uVar10 = FUN_0098ba20(0x20);

  }

  local_4 = 0xffffffff;

  FUN_0042c360(uVar10);

  *(uint8_t *)(*(int *)(param_1 + 0xb0) + 0x7c) = 1;

  ExceptionList = local_c;

  return;

}
