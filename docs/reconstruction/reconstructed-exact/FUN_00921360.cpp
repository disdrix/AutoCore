// =============================================================================
// FUN_00921360
// -----------------------------------------------------------------------------
// Stable ID: aa_00921360
// Address:   0x00921360  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00921360 @ 0x00921360
// Stable ID: aa_00921360
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~67 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: GetTickCount×2, CVOGTerrain_SampleExploredAreaId, Client_MaybeShowFirstTimeTip, FUN_00402d50, FUN_0040c5c0, FUN_004d3740, FUN_00921360, free.
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

void FUN_00921360(void)



{

  int iVar1;

  uchar uVar2;

  char cVar3;

  DWORD DVar4;

  float *pfVar5;

  uint32_t /* width from decompiler */ *puVar6;

  int unaff_ESI;

  char acStack_1b0 [128];

  uint32_t /* width from decompiler */ uStack_130;

  float fStack_12c;

  float fStack_128;

  uint32_t /* width from decompiler */ uStack_124;

  uint32_t /* width from decompiler */ uStack_120;

  uint32_t /* width from decompiler */ uStack_11c;

  uint8_t *puStack_114;

  uint8_t auStack_110 [128];

  uint8_t auStack_90 [2];

  uint8_t auStack_8e [114];

  void *local_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  

  uStack_14 = 0xffffffff;

  puStack_18 = &LAB_009bacf7;

  local_1c = ExceptionList;

  if (((DAT_00d1b6d8 != 0) && (DAT_00d1b644 != 0)) && (*(char *)(DAT_00d1b6d8 + 0x4f1) == '\0')) {

    iVar1 = *(int *)(unaff_ESI + 0xa8c);

    ExceptionList = &local_1c;

    DVar4 = GetTickCount();

    if (iVar1 + 5000U < DVar4) {

      pfVar5 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 +

                                             DAT_00d1b6d8) + 0x1a0))();

      uVar2 = CVOGTerrain_SampleExploredAreaId(*(void **)(DAT_00d1b644 + 0xe4f8),*pfVar5,pfVar5[2]);

      if (uVar2 != *(uchar *)(unaff_ESI + 0xa88)) {

        cVar3 = FUN_004d3740(uVar2,auStack_90);

        if (cVar3 != '\0') {

          uStack_130 = 0xffffffff;

          acStack_1b0[0] = '\0';

          puVar6 = (uint32_t /* width from decompiler */ *)FUN_00402d50(auStack_8e);

          uStack_14 = 0;

          strncpy(acStack_1b0,(char *)*puVar6,0x80);

          uStack_14 = 0xffffffff;

          if (puStack_114 != auStack_110) {

            free(puStack_114);

          }

          fStack_12c = g_flVehicleHpTechCoeff;

          uStack_124 = 3;

          fStack_128 = g_flLevelUpUiBase_Inferred;

          uStack_130 = 0xff14ff14;

          uStack_120 = 0xffffffff;

          uStack_11c = 0xffffffff;

          FUN_0040c5c0(acStack_1b0);

          if (((*(char *)(unaff_ESI + 0xa88) != -1) && (DAT_00d1b644 != 0)) &&

             (*(char *)(DAT_00d1b644 + 0x100) != '\0')) {

            Client_MaybeShowFirstTimeTip(0x26);

          }

          *(uchar *)(unaff_ESI + 0xa88) = uVar2;

          DVar4 = GetTickCount();

          *(DWORD *)(unaff_ESI + 0xa8c) = DVar4;

        }

      }

    }

  }

  ExceptionList = local_1c;

  return;

}
