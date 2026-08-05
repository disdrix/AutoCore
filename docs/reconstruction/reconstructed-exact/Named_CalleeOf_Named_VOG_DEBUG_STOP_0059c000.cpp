// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_0059c000
// -----------------------------------------------------------------------------
// Stable ID: aa_0059c000
// Callee of Named_VOG_DEBUG_STOP (+1 other named callers)
// Address:   0x0059c000  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_VOG_DEBUG_STOP (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~205 non-empty decompiler lines.
//  - Control keywords: if×14, return×3, goto×1, switch×1, do×1, while×1.
//  - Notable callees: FUN_00403450×2, FUN_00540850, FUN_0059a1b0, FUN_0059b110, FUN_0059b620, FUN_0059c000, FUN_0059c620, FUN_0059c660.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP (+1 other named callers)
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

/* WARNING: Removing unreachable block (ram,0x0059c147) */



int Named_CalleeOf_Named_VOG_DEBUG_STOP_0059c000(int param_1)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ uVar4;

  char *pcVar5;

  void *pvVar6;

  char acStack_110 [128];

  char *local_90;

  char local_8c [128];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a5c7c;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  if (DAT_00b04694 != '\0') {

    ExceptionList = &local_c;

    iVar2 = FUN_00540850(*(uint32_t /* width from decompiler */ *)(param_1 + 0x34));

    *(int *)(param_1 + 0x3c) = iVar2;

    if ((DAT_00b04694 != '\0') && (iVar2 != 0)) goto LAB_0059c0aa;

  }

  switch(*(uint32_t /* width from decompiler */ *)(param_1 + 0x38)) {

  case 1:

  case 3:

  case 4:

  case 6:

  case 0x16:

  case 0x1e:

  case 0x20:

  case 0x22:

  case 0x30:

  case 0x36:

  case 0x38:

  case 0x3a:

  case 0x3c:

  case 0x3e:

  case 0x42:

  case 0x48:

    puVar3 = operator_new(0x4c0);

    if (puVar3 == (uint32_t /* width from decompiler */ *)0x0) {

      puVar3 = (uint32_t /* width from decompiler */ *)0x0;

    }

    else {

      *puVar3 = &PTR_FUN_009d55fc;

    }

    *(uint32_t /* width from decompiler */ **)(param_1 + 0x3c) = puVar3;

    puVar3[1] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x34);

    iVar2 = FUN_007e59d0(*(int *)(param_1 + 0x3c) + 4,*(int *)(param_1 + 0x3c) + 0x3b8);

    break;

  default:

    ExceptionList = local_c;

    return -0x7fffbffb;

  case 8:

    pvVar6 = operator_new(0x4c8);

    if (pvVar6 == (void *)0x0) {

      iVar2 = 0;

    }

    else {

      iVar2 = FUN_0059c680();

    }

    *(int *)(param_1 + 0x3c) = iVar2;

    *(uint32_t /* width from decompiler */ *)(iVar2 + 4) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x34);

    iVar2 = *(int *)(param_1 + 0x3c);

    iVar2 = FUN_007edf30(iVar2 + 4,iVar2 + 0x3b8,iVar2 + 0x4c0);

    break;

  case 10:

    pvVar6 = operator_new(0x4cc);

    if (pvVar6 == (void *)0x0) {

      iVar2 = 0;

    }

    else {

      iVar2 = FUN_0059c6c0();

    }

    *(int *)(param_1 + 0x3c) = iVar2;

    *(uint32_t /* width from decompiler */ *)(iVar2 + 4) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x34);

    iVar2 = DB_ReadPowerPlantSpecific

                      (DAT_00b0469c,(char *)(*(int *)(param_1 + 0x3c) + 4),

                       (SPowerPlant_Specific *)(*(int *)(param_1 + 0x3c) + 0x3b8));

    break;

  case 0xc:

  case 0x18:

    pvVar6 = operator_new(0x544);

    if (pvVar6 == (void *)0x0) {

      iVar2 = 0;

    }

    else {

      iVar2 = FUN_0059c660();

    }

    *(int *)(param_1 + 0x3c) = iVar2;

    *(uint32_t /* width from decompiler */ *)(iVar2 + 4) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x34);

    iVar2 = *(int *)(param_1 + 0x3c);

    iVar2 = FUN_007ee340(iVar2 + 4,iVar2 + 0x3b8,iVar2 + 0x4c0);

    break;

  case 0xe:

    pvVar6 = operator_new(0x744);

    if (pvVar6 == (void *)0x0) {

      iVar2 = 0;

    }

    else {

      iVar2 = FUN_0059a1b0();

    }

    *(int *)(param_1 + 0x3c) = iVar2;

    *(uint32_t /* width from decompiler */ *)(iVar2 + 4) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x34);

    iVar2 = *(int *)(param_1 + 0x3c);

    iVar2 = VehicleDb_LoadCloneBase(iVar2 + 4,iVar2 + 0x3b8,iVar2 + 0x4c0);

    break;

  case 0x10:

    pvVar6 = operator_new(0x5d4);

    if (pvVar6 == (void *)0x0) {

      iVar2 = 0;

    }

    else {

      iVar2 = FUN_0059c6e0();

    }

    *(int *)(param_1 + 0x3c) = iVar2;

    *(uint32_t /* width from decompiler */ *)(iVar2 + 4) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x34);

    iVar2 = *(int *)(param_1 + 0x3c);

    iVar2 = FUN_007ed3b0(iVar2 + 4,iVar2 + 0x3b8,iVar2 + 0x4c0);

    break;

  case 0x12:

    pvVar6 = operator_new(0x528);

    local_4 = 0;

    if (pvVar6 == (void *)0x0) {

      iVar2 = 0;

    }

    else {

      iVar2 = FUN_0059b110();

    }

    *(int *)(param_1 + 0x3c) = iVar2;

    *(uint32_t /* width from decompiler */ *)(iVar2 + 4) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x34);

    iVar2 = *(int *)(param_1 + 0x3c);

    local_4 = 0xffffffff;

    iVar2 = FUN_007eaf20(iVar2 + 4,iVar2 + 0x3b8,iVar2 + 0x4c0);

    break;

  case 0x14:

    iVar2 = FUN_0059b620(param_1);

    break;

  case 0x1a:

    pvVar6 = operator_new(0x4e8);

    if (pvVar6 == (void *)0x0) {

      iVar2 = 0;

    }

    else {

      iVar2 = FUN_0059c620();

    }

    *(int *)(param_1 + 0x3c) = iVar2;

    *(uint32_t /* width from decompiler */ *)(iVar2 + 4) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x34);

    iVar2 = *(int *)(param_1 + 0x3c);

    iVar2 = FUN_007ef3f0(iVar2 + 4,iVar2 + 0x3b8,iVar2 + 0x4c0);

    break;

  case 0x1c:

    pvVar6 = operator_new(0x4d4);

    if (pvVar6 == (void *)0x0) {

      iVar2 = 0;

    }

    else {

      iVar2 = FUN_0059c700();

    }

    *(int *)(param_1 + 0x3c) = iVar2;

    *(uint32_t /* width from decompiler */ *)(iVar2 + 4) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x34);

    iVar2 = *(int *)(param_1 + 0x3c);

    iVar2 = FUN_007ec7e0(iVar2 + 4,iVar2 + 0x3b8,iVar2 + 0x4c0);

    break;

  case 0x32:

    pvVar6 = operator_new(0x4c8);

    if (pvVar6 == (void *)0x0) {

      iVar2 = 0;

    }

    else {

      iVar2 = FUN_0059c6a0();

    }

    *(int *)(param_1 + 0x3c) = iVar2;

    *(uint32_t /* width from decompiler */ *)(iVar2 + 4) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x34);

    iVar2 = *(int *)(param_1 + 0x3c);

    iVar2 = FUN_007edb20(iVar2 + 4,iVar2 + 0x3b8,iVar2 + 0x4c0);

  }

  if (iVar2 != 0) {

    ExceptionList = local_c;

    return iVar2;

  }

LAB_0059c0aa:

  iVar2 = *(int *)(param_1 + 0x3c);

  local_90 = local_8c;

  uVar4 = (*(code *)PTR_FUN_00af8c9c)();

  FUN_00403450(iVar2 + 0x10,uVar4);

  pcVar5 = local_90;

  do {

    cVar1 = *pcVar5;

    pcVar5[(param_1 + 0x40) - (int)local_90] = cVar1;

    pcVar5 = pcVar5 + 1;

  } while (cVar1 != '\0');

  if (local_90 != local_8c) {

    free(local_90);

  }

  iVar2 = *(int *)(param_1 + 0x3c);

  uVar4 = (*(code *)PTR_FUN_00af8c9c)();

  FUN_00403450(iVar2 + 0x10,uVar4);

  strncpy((char *)(param_1 + 0x188),acStack_110,0x41);

  ExceptionList = local_c;

  return 0;

}
