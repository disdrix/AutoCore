// READABILITY (auto CF):
//  - Body size: ~125 non-empty decompiler lines.
//  - Control keywords: if×6, return×3, for×2.
//  - Notable callees: block×36, SysFreeString×3, FUN_007a4480×2, FUN_00403450, FUN_004a0630, FUN_004a6d00, FUN_00798bb0, FUN_00799200.
//  - Strings: "duration"; "playSound"; "initiateDamage"; "VOG_DEBUG_STOP".
//  - Return sites: 3.

// =============================================================================
// Named_VOG_DEBUG_STOP_004a0630
// -----------------------------------------------------------------------------
// Stable ID: aa_004a0630
// Address:   0x004a0630  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOG_DEBUG_STOP"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Removing unreachable block (ram,0x004a080a) */

/* WARNING: Removing unreachable block (ram,0x004a0821) */

/* WARNING: Removing unreachable block (ram,0x004a0830) */

/* WARNING: Removing unreachable block (ram,0x004a0848) */

/* WARNING: Removing unreachable block (ram,0x004a0a65) */

/* WARNING: Removing unreachable block (ram,0x004a0852) */

/* WARNING: Removing unreachable block (ram,0x004a08ab) */

/* WARNING: Removing unreachable block (ram,0x004a08e6) */

/* WARNING: Removing unreachable block (ram,0x004a0921) */

/* WARNING: Removing unreachable block (ram,0x004a0969) */

/* WARNING: Removing unreachable block (ram,0x004a09c7) */

/* WARNING: Removing unreachable block (ram,0x004a09da) */

/* WARNING: Removing unreachable block (ram,0x004a097c) */

/* WARNING: Removing unreachable block (ram,0x004a0992) */

/* WARNING: Removing unreachable block (ram,0x004a099d) */

/* WARNING: Removing unreachable block (ram,0x004a09b2) */

/* WARNING: Removing unreachable block (ram,0x004a09b7) */

/* WARNING: Removing unreachable block (ram,0x004a09c5) */

/* WARNING: Removing unreachable block (ram,0x004a09ec) */

/* WARNING: Removing unreachable block (ram,0x004a0934) */

/* WARNING: Removing unreachable block (ram,0x004a094a) */

/* WARNING: Removing unreachable block (ram,0x004a0957) */

/* WARNING: Removing unreachable block (ram,0x004a08f9) */

/* WARNING: Removing unreachable block (ram,0x004a0a5e) */

/* WARNING: Removing unreachable block (ram,0x004a090f) */

/* WARNING: Removing unreachable block (ram,0x004a08be) */

/* WARNING: Removing unreachable block (ram,0x004a0a38) */

/* WARNING: Removing unreachable block (ram,0x004a08d4) */

/* WARNING: Removing unreachable block (ram,0x004a0883) */

/* WARNING: Removing unreachable block (ram,0x004a0899) */

/* WARNING: Removing unreachable block (ram,0x004a09f9) */

/* WARNING: Removing unreachable block (ram,0x004a0a10) */

/* WARNING: Removing unreachable block (ram,0x004a0a17) */

/* WARNING: Removing unreachable block (ram,0x004a0a7a) */

/* WARNING: Removing unreachable block (ram,0x004a0a2a) */

/* WARNING: Removing unreachable block (ram,0x004a0aa4) */



uint32_t /* width from decompiler */ Named_VOG_DEBUG_STOP_004a0630(char param_1,BSTR param_2)



{

  int iVar1;

  void *pvVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ unaff_EBX;

  BSTR unaff_EBP;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  byte bVar6;

  int iStack_2ac;

  uint32_t /* width from decompiler */ auStack_2a8 [2];

  char *pcStack_2a0;

  char acStack_29c [128];

  uint32_t /* width from decompiler */ uStack_21c;

  uint32_t /* width from decompiler */ auStack_218 [127];

  void *pvStack_1c;

  void *pvStack_14;

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  puStack_8 = &LAB_009a0fe6;

  local_c = ExceptionList;

  local_4 = 0;

  if (param_2 == (BSTR)0x0) {

    ExceptionList = &local_c;

    FUN_007a4480();

    SysFreeString((BSTR)0x0);

    ExceptionList = local_c;

    return 0;

  }

  ExceptionList = &local_c;

  iVar1 = (**(code **)(*(int *)param_2 + 0x44))();

  if ((iVar1 == 0) && (iStack_2ac != 0)) {

    if (param_1 == '\0') {

      pvVar2 = operator_new(0x3cc);

      if (pvVar2 == (void *)0x0) {

        puVar4 = (uint32_t /* width from decompiler */ *)0x0;

      }

      else {

        puVar4 = (uint32_t /* width from decompiler */ *)FUN_004a6d00();

      }

    }

    else {

      puVar4 = (uint32_t /* width from decompiler */ *)(local_4 + 0x3bc);

    }

    puVar5 = puVar4;

    for (iVar1 = 0xf3; iVar1 != 0; iVar1 = iVar1 + -1) {

      *puVar5 = 0;

      puVar5 = puVar5 + 1;

    }

    puVar5 = puVar4 + 2;

    puVar4[3] = puVar5;

    *puVar5 = puVar5;

    FUN_00799200(iStack_2ac,L"duration",puVar4,puVar4 + 1,&stack0xfffffd4f);

    bVar6 = (byte)((uint)unaff_EBX >> 0x18);

    *(byte *)(puVar4 + 0x79) =

         *(byte *)(puVar4 + 0x79) ^ (bVar6 << 2 ^ *(byte *)(puVar4 + 0x79)) & 4;

    uStack_21c = 0;

    puVar5 = auStack_218;

    for (iVar1 = 0x81; iVar1 != 0; iVar1 = iVar1 + -1) {

      *puVar5 = 0;

      puVar5 = puVar5 + 1;

    }

    FUN_00798bb0(iStack_2ac,L"playSound",&uStack_21c);

    pcStack_2a0 = acStack_29c;

    uVar3 = (*(code *)PTR_FUN_00af8c9c)();

    FUN_00403450(&uStack_21c,uVar3);

    strncpy((char *)((int)puVar4 + 0x1ea),pcStack_2a0,0x104);

    if (pcStack_2a0 != acStack_29c) {

      free(pcStack_2a0);

    }

    FUN_007996d0(iStack_2ac,L"initiateDamage",&stack0xfffffd4f);

    *(byte *)((int)puVar4 + 0x2ef) =

         *(byte *)((int)puVar4 + 0x2ef) ^ (*(byte *)((int)puVar4 + 0x2ef) ^ bVar6) & 1;

    if (bVar6 != 0) {

      *(uint8_t *)(*(int *)(local_4 + 0x14) + 0xc) = 1;

    }

    auStack_2a8[0] = 0;

    (**(code **)(*(int *)param_2 + 0x30))(param_2,auStack_2a8);

    SysFreeString(param_2);

    ExceptionList = pvStack_1c;

    return 0;

  }

  FUN_007a4480(0,"VOG_DEBUG_STOP");

  SysFreeString(unaff_EBP);

  ExceptionList = pvStack_14;

  return 0;

}
