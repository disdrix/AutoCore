// =============================================================================
// FUN_00678f80
// -----------------------------------------------------------------------------
// Stable ID: aa_00678f80
// Address:   0x00678f80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00678f80 @ 0x00678f80
// Stable ID: aa_00678f80
// Embedded strings (evidence for future rename):
//   - "nothing"
//   - "priority needed"
//   - "invalid param"
//   - "invalid call"
//   - "buffer lost"
//   - "Failed to lock playback buffer size: %d offset: %d length: %d (%s)\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~80 non-empty decompiler lines.
//  - Control keywords: if×7, for×4, return×2.
//  - Notable callees: block×15, FUN_00678f80, FUN_0076cec0, d, vog_LogMessage.
//  - Strings: "nothing"; "priority needed"; "invalid param"; "invalid call".
//  - Return sites: 2.

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

/* WARNING: Removing unreachable block (ram,0x00678fcf) */

/* WARNING: Removing unreachable block (ram,0x00678fda) */

/* WARNING: Removing unreachable block (ram,0x00678fdc) */

/* WARNING: Removing unreachable block (ram,0x00678fe1) */

/* WARNING: Removing unreachable block (ram,0x00678fe3) */

/* WARNING: Removing unreachable block (ram,0x00678ff7) */

/* WARNING: Removing unreachable block (ram,0x00678ff9) */

/* WARNING: Removing unreachable block (ram,0x00678ffe) */

/* WARNING: Removing unreachable block (ram,0x00679000) */

/* WARNING: Removing unreachable block (ram,0x00679017) */

/* WARNING: Removing unreachable block (ram,0x00679019) */

/* WARNING: Removing unreachable block (ram,0x0067901e) */

/* WARNING: Removing unreachable block (ram,0x00679020) */

/* WARNING: Removing unreachable block (ram,0x00679036) */

/* WARNING: Removing unreachable block (ram,0x00679038) */



uint32_t /* width from decompiler */ __thiscall FUN_00678f80(int *param_1,uint32_t /* width from decompiler */ param_2,uint param_3)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint uVar3;

  char *pcVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ local_10 [2];

  uint8_t local_8 [4];

  uint8_t local_4 [4];

  

  if ((char)param_1[0x1e] != '\0') {

    iVar1 = (**(code **)(*(int *)param_1[4] + 0x2c))((int *)param_1[4],param_1[6]);

    if (-1 < iVar1) {

      puVar5 = (uint32_t /* width from decompiler */ *)0x0;

      puVar6 = local_10;

      for (uVar3 = param_3 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {

        *puVar6 = *puVar5;

        puVar5 = puVar5 + 1;

        puVar6 = puVar6 + 1;

      }

      for (uVar3 = param_3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

        *(uint8_t *)puVar6 = *(uint8_t *)puVar5;

        puVar5 = (uint32_t /* width from decompiler */ *)((int)puVar5 + 1);

        puVar6 = (uint32_t /* width from decompiler */ *)((int)puVar6 + 1);

      }

      puVar5 = (uint32_t /* width from decompiler */ *)0x0;

      puVar6 = (uint32_t /* width from decompiler */ *)((uint)param_1[6] % (uint)param_1[7] + *param_1);

      for (uVar3 = param_3 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {

        *puVar6 = *puVar5;

        puVar5 = puVar5 + 1;

        puVar6 = puVar6 + 1;

      }

      for (uVar3 = param_3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

        *(uint8_t *)puVar6 = *(uint8_t *)puVar5;

        puVar5 = (uint32_t /* width from decompiler */ *)((int)puVar5 + 1);

        puVar6 = (uint32_t /* width from decompiler */ *)((int)puVar6 + 1);

      }

      (**(code **)(*(int *)param_1[4] + 0x4c))((int *)param_1[4],local_10,param_3,local_4,local_8);

      param_1[6] = (param_1[6] + param_3) % (uint)param_1[7];

      return 0;

    }

    pcVar4 = "nothing";

    if (iVar1 < -0x7787ffb9) {

      if (iVar1 == -0x7787ffba) {

        pcVar4 = "priority needed";

      }

      else if (iVar1 == -0x7ff8ffa9) {

        pcVar4 = "invalid param";

      }

      else if (iVar1 == -0x7787ffce) {

        pcVar4 = "invalid call";

      }

    }

    else if (iVar1 == -0x7787ff6a) {

      pcVar4 = "buffer lost";

    }

    uVar2 = FUN_0076cec0(&stack0xffffffe8,

                         "Failed to lock playback buffer size: %d offset: %d length: %d (%s)\n",

                         param_1[7],param_1[6],param_3,pcVar4);

    vog_LogMessage("C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\AudioOutStream.cpp"

                   ,0x179,1,uVar2);

  }

  return 0;

}
