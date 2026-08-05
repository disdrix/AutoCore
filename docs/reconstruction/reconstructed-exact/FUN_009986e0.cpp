// =============================================================================
// FUN_009986e0
// -----------------------------------------------------------------------------
// Stable ID: aa_009986e0
// Address:   0x009986e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009986e0 @ 0x009986e0
// Stable ID: aa_009986e0
// Embedded strings (evidence for future rename):
//   - "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceVB.cpp"
//   - "Call to gfxDeviceVB::Unlock more times than locked! Bad mojo..."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~119 non-empty decompiler lines.
//  - Control keywords: if×12, for×1, do×1, while×1, return×1.
//  - Notable callees: FUN_00412d80, FUN_00414b60, FUN_00414bc0, FUN_00414c20, FUN_00464d80, FUN_00746520, FUN_0074b510, FUN_0074ba50.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceVB.cpp".
//  - Return sites: 1.

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

void __fastcall FUN_009986e0(int *param_1)



{

  int *piVar1;

  int *piVar2;

  int *piVar3;

  int *piVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ uVar7;

  int iVar8;

  uint uVar9;

  uint32_t /* width from decompiler */ *puVar10;

  void *pvVar11;

  uint uStack_8c;

  void *pvStack_88;

  void *pvStack_84;

  undefined **ppuStack_80;

  int *piStack_7c;

  uint32_t /* width from decompiler */ auStack_60 [17];

  void *local_1c;

  uint8_t *puStack_18;

  int iStack_14;

  

  iStack_14 = 0xffffffff;

  puStack_18 = &LAB_009b204d;

  local_1c = ExceptionList;

  if ((*(byte *)(param_1 + 0x2f) & 1) != 0) {

    ExceptionList = &local_1c;

    (**(code **)(*param_1 + 0x80))();

    FUN_00464d80();

    piStack_7c = (int *)0x0;

    ppuStack_80 = &PTR_FUN_00a9db18;

    iStack_14 = 0;

    uVar5 = FUN_00414bc0(0x12);

    iStack_14._0_1_ = 1;

    if (param_1[5] == 0) {

      uVar7 = 0;

    }

    else {

      uVar7 = *(uint32_t /* width from decompiler */ *)(param_1[5] + 0x18);

    }

    FUN_00414c20(uVar7,uVar5,8,0);

    iStack_14 = (uint)iStack_14._1_3_ << 8;

    FUN_00414b60();

    if (param_1[0x40] == 0) {

      uStack_8c = 0;

      pvStack_88 = (void *)0x0;

    }

    else {

      uStack_8c = param_1[0x41] - param_1[0x40] >> 2;

      if (uStack_8c == 0) {

        pvStack_88 = (void *)0x0;

      }

      else {

        pvStack_88 = _aligned_malloc(uStack_8c << 6,0x10);

      }

    }

    pvStack_84 = pvStack_88;

    if (((param_1[0x16] != 0) && (param_1[0x17] != 0)) &&

       (*(int *)(param_1[0x17] + 0x1c) != param_1[0x18])) {

      (**(code **)(*param_1 + 0x80))();

    }

    if ((*(uint *)(param_1[0x19] + 0xbc) >> 1 & 1) == 0) {

      puVar6 = (uint32_t /* width from decompiler */ *)(param_1[0x19] + 0x40);

    }

    else {

      puVar6 = (uint32_t /* width from decompiler */ *)FUN_009730e0();

    }

    puVar10 = auStack_60;

    for (iVar8 = 0x10; iVar8 != 0; iVar8 = iVar8 + -1) {

      *puVar10 = *puVar6;

      puVar6 = puVar6 + 1;

      puVar10 = puVar10 + 1;

    }

    uVar9 = 0;

    pvVar11 = pvStack_88;

    if (uStack_8c != 0) {

      do {

        FUN_00412d80(pvVar11,*(uint32_t /* width from decompiler */ *)(param_1[0x40] + uVar9 * 4),auStack_60);

        uVar9 = uVar9 + 1;

        pvVar11 = (void *)((int)pvVar11 + 0x40);

      } while (uVar9 < uStack_8c);

    }

    FUN_00997b90(param_1 + 4,&pvStack_84,&ppuStack_80);

    _aligned_free(pvStack_88);

    FUN_0074b510();

    piVar4 = piStack_7c;

    if ((piStack_7c[4] != 0) && (iVar8 = FUN_00746520(piStack_7c[5],piStack_7c[6],4), iVar8 != 0)) {

      if (piVar4[4] == 0) {

        uVar5 = 0;

      }

      else {

        uVar5 = *(uint32_t /* width from decompiler */ *)(piVar4[4] + 8);

      }

      FUN_0074ba50(iVar8,uVar5,piVar4[6]);

    }

    piVar2 = (int *)piVar4[4];

    if ((piVar2 != (int *)0x0) && (piVar3 = (int *)*piVar2, piVar3 != (int *)0x0)) {

      piVar1 = piVar2 + 4;

      *piVar1 = *piVar1 + -1;

      if (*piVar1 < 0) {

        vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceVB.cpp",0xd3,1,

                       "Call to gfxDeviceVB::Unlock more times than locked! Bad mojo...");

        piVar2[4] = 0;

      }

      else {

        (**(code **)(*piVar3 + 0x30))(piVar3);

      }

    }

    param_1[0x2f] = param_1[0x2f] & 0xfffffffe;

    iStack_14 = 0xffffffff;

    piVar2 = piVar4 + 1;

    *piVar2 = *piVar2 + -1;

    if (*piVar2 == 0) {

      (**(code **)(*piVar4 + 8))();

    }

  }

  ExceptionList = local_1c;

  return;

}
