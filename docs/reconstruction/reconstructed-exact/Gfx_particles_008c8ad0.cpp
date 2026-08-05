// =============================================================================
// Gfx_particles_008c8ad0
// -----------------------------------------------------------------------------
// Stable ID: aa_008c8ad0
// Address:   0x008c8ad0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Gfx_particles_008c8ad0 @ 0x008c8ad0
// Stable ID: aa_008c8ad0
// Embedded strings (evidence for future rename):
//   - "i_d_g.xml"
//   - "i_d_g_2d_wnd_particles.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~110 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0087b890, FUN_008c51b0, Gfx_particles_008c8ad0, FUN_0097c720, NDUIWindow_ReloadInterface.
//  - Strings: "i_d_g.xml"; "i_d_g_2d_wnd_particles.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_g_2d_wnd_particles.xml"
 * Domain alias of FUN_008c8ad0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int * Gfx_particles_008c8ad0(int *param_1)



{

  char cVar1;

  void *pvVar2;

  int *piVar3;

  uint8_t extraout_DL;

  void *unaff_EBX;

  int iVar4;

  void *pvStack_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b6bee;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_0087b890(param_1,0);

  local_4 = 0;

  *param_1 = (int)&PTR_FUN_00a42dec;

  *(uint8_t *)((int)param_1 + 0x522) = 0xff;

  *(uint8_t *)((int)param_1 + 0x521) = 0xff;

  *(uint8_t *)(param_1 + 0x148) = 0xff;

  *(uint8_t *)((int)param_1 + 0x523) = 0xff;

  iVar4 = 0;

  *(uint8_t *)((int)param_1 + 0x526) = 0xff;

  *(uint8_t *)((int)param_1 + 0x525) = 0xff;

  *(uint8_t *)(param_1 + 0x149) = 0xff;

  *(uint8_t *)((int)param_1 + 0x527) = 0xff;

  *(uint8_t *)((int)param_1 + 0x52a) = 0xff;

  *(uint8_t *)((int)param_1 + 0x529) = 0xff;

  *(uint8_t *)(param_1 + 0x14a) = 0xff;

  *(uint8_t *)((int)param_1 + 0x52b) = 0xff;

  *(uint8_t *)((int)param_1 + 0x52e) = 0xff;

  *(uint8_t *)((int)param_1 + 0x52d) = 0xff;

  *(uint8_t *)(param_1 + 0x14b) = 0xff;

  *(uint8_t *)((int)param_1 + 0x52f) = 0xff;

  *(uint8_t *)((int)param_1 + 0x532) = 0xff;

  *(uint8_t *)((int)param_1 + 0x531) = 0xff;

  *(uint8_t *)(param_1 + 0x14c) = 0xff;

  *(uint8_t *)((int)param_1 + 0x533) = 0xff;

  *(uint8_t *)((int)param_1 + 0x536) = 0xff;

  *(uint8_t *)((int)param_1 + 0x535) = 0xff;

  *(uint8_t *)(param_1 + 0x14d) = 0xff;

  *(uint8_t *)((int)param_1 + 0x537) = 0xff;

  *(uint8_t *)((int)param_1 + 0x53a) = 0xff;

  *(uint8_t *)((int)param_1 + 0x539) = 0xff;

  *(uint8_t *)(param_1 + 0x14e) = 0xff;

  *(uint8_t *)((int)param_1 + 0x53b) = 0xff;

  param_1[0x13f] = 10;

  param_1[0x140] = 2;

  param_1[0x146] = 1;

  param_1[0x145] = 0;

  FUN_008c51b0();

  param_1[0x143] = iVar4;

  iVar4 = DAT_00a10e78;

  *(uint8_t *)(param_1 + 0x124) = 0;

  *(uint8_t *)(param_1 + 0x147) = 0;

  *(uint8_t *)((int)param_1 + 0x51d) = 0;

  param_1[0x144] = iVar4;

  *(uint8_t *)((int)param_1 + 0x522) = extraout_DL;

  *(uint8_t *)((int)param_1 + 0x521) = extraout_DL;

  *(uint8_t *)(param_1 + 0x148) = extraout_DL;

  *(uint8_t *)((int)param_1 + 0x523) = extraout_DL;

  *(uint8_t *)((int)param_1 + 0x526) = extraout_DL;

  *(uint8_t *)((int)param_1 + 0x525) = extraout_DL;

  *(uint8_t *)(param_1 + 0x149) = extraout_DL;

  *(uint8_t *)((int)param_1 + 0x527) = extraout_DL;

  *(uint8_t *)((int)param_1 + 0x52a) = extraout_DL;

  *(uint8_t *)((int)param_1 + 0x529) = extraout_DL;

  *(uint8_t *)(param_1 + 0x14a) = extraout_DL;

  *(uint8_t *)((int)param_1 + 0x52b) = extraout_DL;

  *(uint8_t *)((int)param_1 + 0x52e) = extraout_DL;

  *(uint8_t *)((int)param_1 + 0x52d) = extraout_DL;

  *(uint8_t *)(param_1 + 0x14b) = extraout_DL;

  *(uint8_t *)((int)param_1 + 0x52f) = extraout_DL;

  *(uint8_t *)((int)param_1 + 0x532) = extraout_DL;

  *(uint8_t *)((int)param_1 + 0x531) = extraout_DL;

  *(uint8_t *)(param_1 + 0x14c) = extraout_DL;

  *(uint8_t *)((int)param_1 + 0x533) = extraout_DL;

  *(uint8_t *)((int)param_1 + 0x536) = extraout_DL;

  *(uint8_t *)((int)param_1 + 0x535) = extraout_DL;

  *(uint8_t *)(param_1 + 0x14d) = extraout_DL;

  *(uint8_t *)((int)param_1 + 0x537) = extraout_DL;

  *(uint8_t *)((int)param_1 + 0x53a) = extraout_DL;

  *(uint8_t *)((int)param_1 + 0x539) = extraout_DL;

  *(uint8_t *)(param_1 + 0x14e) = extraout_DL;

  *(uint8_t *)((int)param_1 + 0x53b) = extraout_DL;

  NDUIWindow_ReloadInterface("i_d_g.xml");

  *(uint8_t *)(param_1 + 0x147) = 0;

  cVar1 = (**(code **)(*param_1 + 0x3d8))();

  if (cVar1 != '\0') {

    (**(code **)(*param_1 + 0x458))();

    (**(code **)(*param_1 + 0x448))();

  }

  (**(code **)(*param_1 + 0x34c))();

  pvVar2 = operator_new(0x560);

  local_4._0_1_ = 1;

  if (pvVar2 == (void *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    piVar3 = (int *)FUN_0097c720(pvVar2);

  }

  local_4 = (uint)local_4._1_3_ << 8;

  param_1[0x165] = (int)piVar3;

  (**(code **)(*piVar3 + 0x28))("i_d_g_2d_wnd_particles.xml");

  (**(code **)(*(int *)param_1[0x165] + 0xcc))(0);

  *(uint8_t *)(param_1 + 0x17a) = 0;

  ExceptionList = unaff_EBX;

  return param_1;

}
