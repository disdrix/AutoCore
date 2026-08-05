// =============================================================================
// FUN_0079a750
// -----------------------------------------------------------------------------
// Stable ID: aa_0079a750
// Address:   0x0079a750  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0079a750 @ 0x0079a750
// Stable ID: aa_0079a750
// Embedded strings (evidence for future rename):
//   - "%d\t%06d\t%04d\t%06.0f\t%04.0f\t%05d\t%03d\t%06d\t%03d\t%05d\t%03d\n"
//   - "0\t%06d\t%04d\t%06.0f\t%04.0f\t%05d\t%03d\t%06d\t%03d\t%05d\t%03d\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~101 non-empty decompiler lines.
//  - Control keywords: do×4, while×4, if×4, return×1.
//  - Notable callees: fwrite×2, sprintf×2, FUN_0079a750, fflush.
//  - Strings: "%d\t%06d\t%04d\t%06.0f\t%04.0f\t%05d\t%03d\t%06d\t%03d\t%05d\t%03d\n"; "0\t%06d\t%04d\t%06.0f\t%04.0f\t%05d\t%03d\t%06d\t%03d\t%05d\t%03d\n".
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

void FUN_0079a750(int param_1)



{

  int iVar1;

  char cVar2;

  int iVar3;

  uint uVar4;

  uint uVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ *puVar7;

  char *pcVar8;

  int iVar9;

  float local_430;

  int local_42c;

  int local_428;

  int local_424;

  int local_420;

  int local_41c;

  int local_418;

  int local_414;

  float local_410;

  int local_40c;

  int local_408;

  char local_400 [1024];

  

  uVar6 = DAT_00aaa66c;

  puVar7 = (uint32_t /* width from decompiler */ *)(param_1 + 0xd8);

  iVar9 = 0xe;

  do {

    puVar7[-0xe] = 0;

    *puVar7 = 0;

    puVar7[0xe] = uVar6;

    puVar7 = puVar7 + 1;

    iVar9 = iVar9 + -1;

  } while (iVar9 != 0);

  iVar9 = 0;

  local_420 = 0;

  local_428 = 0;

  local_430 = 0.0;

  local_410 = 0.0;

  local_41c = 0;

  local_418 = 0;

  local_424 = 0;

  local_414 = 0;

  local_42c = 0;

  local_40c = 0;

  if (0 < *(int *)(param_1 + 0x1c)) {

    local_408 = 0;

    do {

      if (*(int *)(param_1 + 0x23c) != 0) {

        iVar3 = *(int *)(local_408 + 0xc + *(int *)(param_1 + 0x18));

        iVar1 = local_408 + *(int *)(param_1 + 0x18);

        if ((iVar3 != 0) || (*(float *)(iVar1 + 0x1c) != 0.0)) {

          local_418 = local_418 + *(int *)(iVar1 + 8);

          local_420 = local_420 + iVar3;

          local_424 = local_424 + *(int *)(iVar1 + 0x14);

          local_414 = local_414 + *(int *)(iVar1 + 0x18);

          uVar4 = *(uint *)(iVar1 + 0x24);

          local_41c = local_41c + *(int *)(iVar1 + 4);

          local_428 = local_428 + *(int *)(iVar1 + 0x10);

          local_42c = local_42c + (~-(uint)(999999 < uVar4) & uVar4);

          uVar5 = *(uint *)(iVar1 + 0x28);

          iVar9 = iVar9 + (~-(uint)(999999 < uVar5) & uVar5);

          local_430 = local_430 + *(float *)(iVar1 + 0x1c);

          local_410 = local_410 + *(float *)(iVar1 + 0x20);

          sprintf(local_400,"%d\t%06d\t%04d\t%06.0f\t%04.0f\t%05d\t%03d\t%06d\t%03d\t%05d\t%03d\n",

                  local_40c,iVar3,*(int *)(iVar1 + 0x10),(double)*(float *)(iVar1 + 0x1c),

                  (double)*(float *)(iVar1 + 0x20),*(int *)(iVar1 + 4),*(uint32_t /* width from decompiler */ *)(iVar1 + 8),

                  *(uint32_t /* width from decompiler */ *)(iVar1 + 0x14),*(uint32_t /* width from decompiler */ *)(iVar1 + 0x18),

                  ~-(uint)(999999 < uVar4) & uVar4,~-(uint)(999999 < uVar5) & uVar5);

          pcVar8 = local_400;

          do {

            cVar2 = *pcVar8;

            pcVar8 = pcVar8 + 1;

          } while (cVar2 != '\0');

          fwrite(local_400,1,(int)pcVar8 - (int)(local_400 + 1),*(FILE **)(param_1 + 0x23c));

        }

      }

      *(uint32_t /* width from decompiler */ *)(local_408 + 0xc + *(int *)(param_1 + 0x18)) = 0;

      *(uint32_t /* width from decompiler */ *)(local_408 + 0x10 + *(int *)(param_1 + 0x18)) = 0;

      *(uint32_t /* width from decompiler */ *)(local_408 + 0x18 + *(int *)(param_1 + 0x18)) = 0;

      *(uint32_t /* width from decompiler */ *)(local_408 + 0x28 + *(int *)(param_1 + 0x18)) = 9999999;

      *(uint32_t /* width from decompiler */ *)(local_408 + 0x14 + *(int *)(param_1 + 0x18)) = 0;

      *(uint32_t /* width from decompiler */ *)(local_408 + 0x24 + *(int *)(param_1 + 0x18)) = 9999999;

      local_40c = local_40c + 1;

      local_408 = local_408 + 0x2c;

    } while (local_40c < *(int *)(param_1 + 0x1c));

  }

  if (*(int *)(param_1 + 0x23c) != 0) {

    sprintf(local_400,"0\t%06d\t%04d\t%06.0f\t%04.0f\t%05d\t%03d\t%06d\t%03d\t%05d\t%03d\n",

            local_420,local_428,(double)local_430,(double)local_410,local_41c,local_418,local_424,

            local_414,local_42c,iVar9);

    pcVar8 = local_400;

    do {

      cVar2 = *pcVar8;

      pcVar8 = pcVar8 + 1;

    } while (cVar2 != '\0');

    fwrite(local_400,1,(int)pcVar8 - (int)(local_400 + 1),*(FILE **)(param_1 + 0x23c));

    fflush(*(FILE **)(param_1 + 0x23c));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

  return;

}
