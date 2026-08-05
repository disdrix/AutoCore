// =============================================================================
// FUN_00757050
// -----------------------------------------------------------------------------
// Stable ID: aa_00757050
// Address:   0x00757050  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00757050 @ 0x00757050
// Stable ID: aa_00757050
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~83 non-empty decompiler lines.
//  - Control keywords: if×6, return×3, do×2, while×2.
//  - Notable callees: FUN_004403d0×3, FUN_00440380×2, FUN_00756900, FUN_00756dc0, FUN_00757050.
//  - Return sites: 3.

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

/* WARNING: Type propagation algorithm not settling */



void FUN_00757050(uint param_1,int param_2)



{

  int iVar1;

  uint uVar2;

  int unaff_ESI;

  uint *puVar3;

  int local_4c;

  float local_48;

  uint local_44;

  uint local_40;

  float local_3c [2];

  int local_34;

  uint32_t /* width from decompiler */ local_30;

  float local_2c;

  uint32_t /* width from decompiler */ local_28;

  int local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  iVar1 = param_1;

  if (*(char *)(param_1 + 0x8d) != '\0') {

    uVar2 = FUN_00756900(param_1);

    if (uVar2 == 0xff) {

      return;

    }

    FUN_00440380();

    FUN_00440380();

    local_34 = -*(int *)(param_1 + 0x4c);

    local_24 = -*(int *)(param_1 + 0x48);

    local_3c[1] = g_flOne;

    local_2c = g_flOne;

    local_40 = 4;

    local_3c[0] = 0.0;

    local_30 = 1;

    local_28 = 0;

    local_20 = 2;

    local_1c = DAT_00aaa668;

    local_18 = 0;

    local_14 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x50);

    local_10 = 8;

    local_c = 0;

    local_8 = DAT_00aaa668;

    local_4 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x54);

    if (uVar2 != 0) {

      local_4c = 0;

      puVar3 = (uint *)(local_3c + 1);

      param_1 = uVar2;

      do {

        if ((param_1 & puVar3[-2]) != 0) {

          local_48 = (float)puVar3[-1];

          param_1 = param_1 & ~puVar3[-2];

          local_44 = *puVar3;

          param_2 = FUN_00756dc0(&local_48);

          if (param_2 < 3) {

            return;

          }

        }

        local_4c = local_4c + 1;

        puVar3 = puVar3 + 4;

      } while (local_4c < 4);

    }

  }

  if (1 < param_2 + -1) {

    param_2 = param_2 + -2;

    do {

      FUN_004403d0();

      *(uint32_t /* width from decompiler */ *)(*(int *)(unaff_ESI + 0x18) + -0x10) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x74);

      FUN_004403d0();

      *(uint32_t /* width from decompiler */ *)(*(int *)(unaff_ESI + 0x18) + -0x10) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x74);

      FUN_004403d0();

      *(uint32_t /* width from decompiler */ *)(*(int *)(unaff_ESI + 0x18) + -0x10) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x74);

      *(int *)(unaff_ESI + 4) = *(int *)(unaff_ESI + 4) + 1;

      param_2 = param_2 + -1;

    } while (param_2 != 0);

  }

  return;

}
