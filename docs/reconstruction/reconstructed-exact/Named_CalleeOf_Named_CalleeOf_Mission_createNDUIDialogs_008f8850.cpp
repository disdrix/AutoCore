// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Mission_createNDUIDialogs_008f8850
// -----------------------------------------------------------------------------
// Stable ID: aa_008f8850
// Callee of Named_CalleeOf_Mission_createNDUIDialogs
// Address:   0x008f8850  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Mission_createNDUIDialogs: mission/objective helper. Evidence string: "i_d_chatlog.xml". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "i_d_chatlog.xml"
//   - "i_d_chatlog_sub.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~175 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, return×1.
//  - Notable callees: FUN_0087b890, FUN_008f6990, FUN_008f6b70, FUN_008f6f60, FUN_008f7040, FUN_008f8140, FUN_008f8850, NDUIWindow_ReloadInterface.
//  - Strings: "i_d_chatlog.xml"; "i_d_chatlog_sub.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Mission_createNDUIDialogs
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

int * Named_CalleeOf_Named_CalleeOf_Mission_createNDUIDialogs_008f8850(int *param_1)



{

  char cVar1;

  int iVar2;

  int *piVar3;

  int *piVar4;

  void *local_14 [2];

  void *pvStack_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b7a0a;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_0087b890(param_1,0);

  local_4 = 0;

  *param_1 = (int)&PTR_FUN_00a36234;

  param_1[0x140] = 2;

  param_1[0x144] = 0;

  param_1[0x145] = 0;

  param_1[0x146] = 0;

  param_1[0x147] = 0;

  param_1[0x148] = 0;

  param_1[0x149] = 0;

  param_1[0x14a] = 0;

  param_1[300] = DAT_00aaa668;

  param_1[0x13f] = 1;

  param_1[0x143] = 1;

  piVar4 = param_1 + 0x150;

  *piVar4 = 0;

  param_1[0x151] = 0;

  param_1[0x12e] = 0;

  param_1[0x12f] = 0;

  param_1[0x12d] = 0;

  param_1[0x141] = 0;

  param_1[0x142] = 0;

  param_1[0x14b] = 0;

  param_1[0x14c] = 0;

  param_1[0x14d] = 0;

  *(uint8_t *)(param_1 + 0x14e) = 0;

  param_1[0x14f] = 0;

  *(uint16_t *)(param_1 + 0x153) = 0;

  param_1[0x152] = 0;

  DAT_00d1e4b2 = 0x66;

  DAT_00d1e4ce = 0x66;

  DAT_00d1e4a2 = 0;

  DAT_00d1e4a1 = 0;

  DAT_00d1e4a0 = 0;

  DAT_00d1e4a3 = 0;

  DAT_00d1e4a6 = 0xff;

  DAT_00d1e4a5 = 0x99;

  DAT_00d1e4a4 = 0x33;

  DAT_00d1e4a7 = 0xff;

  DAT_00d1e4aa = 0xd7;

  DAT_00d1e4a9 = 0x73;

  DAT_00d1e4a8 = 0xd7;

  DAT_00d1e4ab = 0xff;

  DAT_00d1e4ae = 0;

  DAT_00d1e4ad = 0xff;

  DAT_00d1e4ac = 100;

  DAT_00d1e4af = 0xff;

  DAT_00d1e4b1 = 0xff;

  DAT_00d1e4b0 = 0xff;

  DAT_00d1e4b3 = 0xff;

  DAT_00d1e4cd = 0xff;

  DAT_00d1e4cc = 0xf5;

  DAT_00d1e4cf = 0xff;

  DAT_00d1e4b6 = 0xff;

  DAT_00d1e4b5 = 0xd7;

  DAT_00d1e4b4 = 0x87;

  DAT_00d1e4b7 = 0xff;

  DAT_00d1e4ba = 0xf7;

  DAT_00d1e4b9 = 0xff;

  DAT_00d1e4b8 = 0;

  DAT_00d1e4bb = 0xff;

  DAT_00d1e4be = 0xd7;

  DAT_00d1e4bd = 0x73;

  DAT_00d1e4bc = 0xd7;

  DAT_00d1e4c1 = 0xd7;

  DAT_00d1e4c5 = 0xd7;

  DAT_00d1e4d5 = 0xd7;

  DAT_00d1e4d9 = 0xd7;

  DAT_00d1e4dd = 0xd7;

  DAT_00d1e4ee = 0x46;

  DAT_00d1e4ec = 0x46;

  DAT_00d1e4f5 = 200;

  DAT_00d1e4f9 = 200;

  DAT_00d1e4c0 = 0x87;

  DAT_00d1e4c4 = 0x87;

  DAT_00d1e4d4 = 0x87;

  DAT_00d1e4d8 = 0x87;

  DAT_00d1e4dc = 0x87;

  DAT_00d1e4fd = 0xdc;

  DAT_00d1e502 = 0xdc;

  DAT_00d1e501 = 0xdc;

  DAT_00d1e4bf = 0xff;

  DAT_00d1e4c2 = 0xff;

  DAT_00d1e4c3 = 0xff;

  DAT_00d1e4c6 = 0xff;

  DAT_00d1e4c7 = 0xff;

  DAT_00d1e4d6 = 0xff;

  DAT_00d1e4d7 = 0xff;

  DAT_00d1e4da = 0xff;

  DAT_00d1e4db = 0xff;

  DAT_00d1e4de = 0xff;

  DAT_00d1e4df = 0xff;

  DAT_00d1e4ca = 0xff;

  DAT_00d1e4c9 = 0xff;

  DAT_00d1e4c8 = 0xff;

  DAT_00d1e4cb = 0xff;

  DAT_00d1e4e2 = 0xff;

  DAT_00d1e4e1 = 0x32;

  DAT_00d1e4e0 = 0;

  DAT_00d1e4e3 = 0xff;

  DAT_00d1e4e6 = 0xff;

  DAT_00d1e4e5 = 0xff;

  DAT_00d1e4e4 = 0xff;

  DAT_00d1e4e7 = 0xff;

  DAT_00d1e4ea = 0xff;

  DAT_00d1e4e9 = 0xff;

  DAT_00d1e4e8 = 0;

  DAT_00d1e4eb = 0xff;

  DAT_00d1e4ed = 0xcc;

  DAT_00d1e4ef = 0xff;

  DAT_00d1e4f2 = 0xbb;

  DAT_00d1e4f1 = 100;

  DAT_00d1e4f0 = 0xf9;

  DAT_00d1e4f3 = 0xff;

  DAT_00d1e4f6 = 0xff;

  DAT_00d1e4f4 = 0x33;

  DAT_00d1e4f7 = 0xff;

  DAT_00d1e4fa = 100;

  DAT_00d1e4f8 = 0xff;

  DAT_00d1e4fb = 0xff;

  DAT_00d1e4fe = 0x28;

  DAT_00d1e4fc = 0x40;

  DAT_00d1e4ff = 0xff;

  DAT_00d1e500 = 0x28;

  DAT_00d1e503 = 0xff;

  NDUIWindow_ReloadInterface("i_d_chatlog.xml");

  cVar1 = (**(code **)(*param_1 + 0x3d8))();

  if (cVar1 != '\0') {

    if ((int *)param_1[0x14d] != (int *)0x0) {

      if (DAT_00af9214 == -1) {

        iVar2 = (**(code **)(*(int *)param_1[0x14d] + 0x124))(local_14);

        DAT_00af9214 = (int)*(float *)(iVar2 + 4);

      }

      FUN_008f6990();

    }

    FUN_008f7040();

    FUN_008f6f60();

    FUN_008f6b70(param_1);

    (**(code **)(*param_1 + 0x450))();

  }

  (**(code **)(*param_1 + 0x34c))();

  iVar2 = 0;

  do {

    local_14[0] = operator_new(0x10f8);

    local_4._0_1_ = 1;

    if (local_14[0] == (void *)0x0) {

      piVar3 = (int *)0x0;

    }

    else {

      piVar3 = (int *)FUN_008f8140(local_14[0]);

    }

    local_4 = (uint)local_4._1_3_ << 8;

    *piVar4 = (int)piVar3;

    (**(code **)(*piVar3 + 0x28))("i_d_chatlog_sub.xml");

    *(int *)(*piVar4 + 0x4fc) = iVar2;

    iVar2 = iVar2 + 1;

    piVar4 = piVar4 + 1;

  } while (iVar2 < 2);

  ExceptionList = pvStack_c;

  return param_1;

}
