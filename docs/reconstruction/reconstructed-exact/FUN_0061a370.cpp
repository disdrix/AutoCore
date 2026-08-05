// =============================================================================
// FUN_0061a370
// -----------------------------------------------------------------------------
// Stable ID: aa_0061a370
// Address:   0x0061a370  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0061a370 @ 0x0061a370
// Stable ID: aa_0061a370
// Embedded strings (evidence for future rename):
//   - "heat] (additive)\n"
//   - "heat] (percent)\n"
//   - "boost] (percent)\n"
//   - "taunt] (additive)\n"
//   - "turns_caster_invis)\n"
//   - "analyzes)\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~289 non-empty decompiler lines.
//  - Control keywords: if×72, goto×9, do×7, while×7, return×1.
//  - Notable callees: FUN_005781b0×35, FUN_00578190, FUN_0058b640, FUN_0058b6d0, FUN_0061a370.
//  - Strings: "heat] (additive)\n"; "heat] (percent)\n"; "boost] (percent)\n"; "taunt] (additive)\n".
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

void FUN_0061a370(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  float fVar1;

  short *psVar2;

  float *pfVar3;

  int iVar4;

  bool bVar5;

  char *pcVar6;

  

  if (*(float *)(param_1 + 0xf0) != g_flZero) {

    if (g_flOne < *(float *)(param_1 + 0xf0) || *(float *)(param_1 + 0xf0) < DAT_00aaa668) {

      pcVar6 = "heat] (additive)\n";

    }

    else {

      pcVar6 = "heat] (percent)\n";

    }

    FUN_005781b0(param_3,param_2,pcVar6,1);

  }

  if (*(float *)(param_1 + 0xf4) != g_flZero) {

    FUN_005781b0(param_3,param_2,"boost] (percent)\n",1);

  }

  if (*(short *)(param_1 + 0x50) != 0) {

    FUN_005781b0(param_3,param_2,"taunt] (additive)\n",1);

  }

  if (*(char *)(param_1 + 0x20) != '\0') {

    FUN_005781b0(param_3,param_2,"turns_caster_invis)\n",0);

  }

  if (*(char *)(param_1 + 0x21) != '\0') {

    FUN_005781b0(param_3,param_2,"analyzes)\n",0);

  }

  if (*(float *)(param_1 + 0xe8) != g_flZero) {

    FUN_005781b0(param_3,param_2,"driving_improvement] (percent)\n",1);

  }

  if (*(float *)(param_1 + 300) != g_flZero) {

    FUN_005781b0(param_3,param_2,"aggro_radius] (percent)\n",1);

  }

  if (*(float *)(param_1 + 0x130) != g_flZero) {

    FUN_005781b0(param_3,param_2,"refire_rate] (percent)\n",1);

  }

  if ((*(byte *)(param_1 + 0x624) & 2) != 0) {

    if ((g_flOne < *(float *)(param_1 + 0x3c)) || (*(float *)(param_1 + 0x3c) < DAT_00aaa668)) {

      pcVar6 = "heal] (additive)\n";

    }

    else {

      pcVar6 = "heal] (percent)\n";

    }

    FUN_005781b0(param_3,param_2,pcVar6,1);

  }

  if (*(float *)(param_1 + 0x120) != g_flZero) {

    if ((g_flOne < *(float *)(param_1 + 0x120)) || (*(float *)(param_1 + 0x120) < DAT_00aaa668)) {

      pcVar6 = "shields] (additive)\n";

    }

    else {

      pcVar6 = "shields] (percent)\n";

    }

    FUN_005781b0(param_3,param_2,pcVar6,1);

  }

  if ((*(byte *)(param_1 + 0x625) & 0x80) != 0) {

    if ((g_flOne < *(float *)(param_1 + 0x40)) || (*(float *)(param_1 + 0x40) < DAT_00aaa668)) {

      pcVar6 = "power] (additive)\n";

    }

    else {

      pcVar6 = "power] (percent)\n";

    }

    FUN_005781b0(param_3,param_2,pcVar6,1);

  }

  if ((*(byte *)(param_1 + 0x624) & 1) != 0) {

    iVar4 = 0;

    do {

      if (*(short *)(param_1 + 0x60 + iVar4 * 2) != 0) {

        if (iVar4 == 0) {

          pcVar6 = "dmg_physical]\n";

        }

        else if (iVar4 == 1) {

          pcVar6 = "dmg_fire]\n";

        }

        else if (iVar4 == 3) {

          pcVar6 = "dmg_corrosive]\n";

        }

        else if (iVar4 == 4) {

          pcVar6 = "dmg_contamination]\n";

        }

        else {

          if (iVar4 != 5) goto LAB_0061a5f6;

          pcVar6 = "dmg_energy]\n";

        }

        FUN_005781b0(param_3,param_2,pcVar6,1);

      }

LAB_0061a5f6:

      iVar4 = iVar4 + 1;

    } while (iVar4 < 6);

  }

  if ((*(byte *)(param_1 + 0x624) & 4) != 0) {

    if ((*(byte *)(param_1 + 0x620) & 2) != 0) {

      FUN_005781b0(param_3,param_2,"status_stun)\n",0);

    }

    if ((*(byte *)(param_1 + 0x620) & 4) != 0) {

      FUN_005781b0(param_3,param_2,"status_lockdown)\n",0);

    }

    if ((*(byte *)(param_1 + 0x620) & 8) != 0) {

      FUN_005781b0(param_3,param_2,"status_silence)\n",0);

    }

    if ((*(byte *)(param_1 + 0x620) & 0x10) != 0) {

      FUN_005781b0(param_3,param_2,"status_nofire)\n",0);

    }

    if ((*(byte *)(param_1 + 0x620) & 0x40) != 0) {

      FUN_005781b0(param_3,param_2,"status_fear)\n",0);

    }

    if ((*(byte *)(param_1 + 0x620) & 0x80) != 0) {

      FUN_005781b0(param_3,param_2,"status_confused)\n",0);

    }

    if ((*(byte *)(param_1 + 0x621) & 2) != 0) {

      FUN_005781b0(param_3,param_2,"status_blind)\n",0);

    }

    if ((*(byte *)(param_1 + 0x621) & 0x20) != 0) {

      FUN_005781b0(param_3,param_2,"status_nodeath)\n",0);

    }

    if ((*(byte *)(param_1 + 0x621) & 0x10) != 0) {

      FUN_005781b0(param_3,param_2,"status_slow)\n",0);

    }

    if ((*(byte *)(param_1 + 0x621) & 0x40) != 0) {

      FUN_005781b0(param_3,param_2,"status_speed)\n",0);

    }

    if ((*(byte *)(param_1 + 0x622) & 1) != 0) {

      FUN_005781b0(param_3,param_2,"status_zombie)\n",0);

    }

    if ((*(byte *)(param_1 + 0x620) & 1) != 0) {

      FUN_005781b0(param_3,param_2,"status_gmfrozen)\n",0);

    }

    if ((*(byte *)(param_1 + 0x620) & 0x20) != 0) {

      FUN_005781b0(param_3,param_2,"status_gmchatban)\n",0);

    }

  }

  if ((*(byte *)(param_1 + 0x624) & 8) != 0) {

    iVar4 = 1;

    psVar2 = (short *)(param_1 + 0x6e);

    do {

      if ((iVar4 != 2) && (*psVar2 != *(short *)(param_1 + 0x6c))) {

        iVar4 = 0;

        goto LAB_0061a7b0;

      }

      iVar4 = iVar4 + 1;

      psVar2 = psVar2 + 1;

    } while (iVar4 < 6);

    FUN_005781b0(param_3,param_2,"resist_all]\n",1);

  }

  goto LAB_0061a80c;

LAB_0061a890:

  do {

    if (*(float *)(param_1 + 0xa8 + iVar4 * 4) != g_flZero) {

      if (iVar4 == 0) {

        pcVar6 = "accuracy_physical]\n";

      }

      else if (iVar4 == 1) {

        pcVar6 = "accuracy_fire]\n";

      }

      else if (iVar4 == 3) {

        pcVar6 = "accuracy_corrosive]\n";

      }

      else if (iVar4 == 4) {

        pcVar6 = "accuracy_contamination]\n";

      }

      else {

        if (iVar4 != 5) goto LAB_0061a8f2;

        pcVar6 = "accuracy_energy]\n";

      }

      FUN_005781b0(param_3,param_2,pcVar6,1);

    }

LAB_0061a8f2:

    iVar4 = iVar4 + 1;

  } while (iVar4 < 6);

  goto LAB_0061a8fa;

LAB_0061a7b0:

  do {

    if (*(short *)(param_1 + 0x6c + iVar4 * 2) != 0) {

      if (iVar4 == 0) {

        pcVar6 = "resist_physical]\n";

      }

      else if (iVar4 == 1) {

        pcVar6 = "resist_fire]\n";

      }

      else if (iVar4 == 3) {

        pcVar6 = "resist_corrosive]\n";

      }

      else if (iVar4 == 4) {

        pcVar6 = "resist_contamination]\n";

      }

      else {

        if (iVar4 != 5) goto LAB_0061a804;

        pcVar6 = "resist_energy]\n";

      }

      FUN_005781b0(param_3,param_2,pcVar6,1);

    }

LAB_0061a804:

    iVar4 = iVar4 + 1;

  } while (iVar4 < 6);

LAB_0061a80c:

  if ((*(byte *)(param_1 + 0x624) & 0x40) != 0) {

    FUN_0058b640(param_1,param_2,param_3);

  }

  if ((*(byte *)(param_1 + 0x625) & 4) != 0) {

    FUN_0058b6d0(param_1,param_2,param_3);

  }

  if ((*(byte *)(param_1 + 0x624) & 0x80) != 0) {

    iVar4 = 1;

    pfVar3 = (float *)(param_1 + 0xac);

    do {

      if ((iVar4 != 2) && (*pfVar3 != *(float *)(param_1 + 0xa8))) {

        iVar4 = 0;

        goto LAB_0061a890;

      }

      iVar4 = iVar4 + 1;

      pfVar3 = pfVar3 + 1;

    } while (iVar4 < 6);

    FUN_005781b0(param_3,param_2,"accuracy_all] (percent)\n",1);

  }

LAB_0061a8fa:

  if ((*(byte *)(param_1 + 0x625) & 1) != 0) {

    iVar4 = 0;

    do {

      if ((*(short *)(param_1 + 0x90 + iVar4 * 2) != 0) ||

         (*(short *)(param_1 + 0x78 + iVar4 * 2) != 0)) {

        if (iVar4 == 0) {

          pcVar6 = "dmgadd_physical]\n";

        }

        else if (iVar4 == 1) {

          pcVar6 = "dmgadd_fire]\n";

        }

        else if (iVar4 == 3) {

          pcVar6 = "dmgadd_corrosive]\n";

        }

        else if (iVar4 == 4) {

          pcVar6 = "dmgadd_contamination]\n";

        }

        else {

          if (iVar4 != 5) goto LAB_0061a964;

          pcVar6 = "dmgadd_energy]\n";

        }

        FUN_005781b0(param_3,param_2,pcVar6,1);

      }

LAB_0061a964:

      iVar4 = iVar4 + 1;

    } while (iVar4 < 6);

  }

  if ((*(byte *)(param_1 + 0x625) & 2) != 0) {

    iVar4 = 0;

    do {

      if ((*(short *)(param_1 + 0x9c + iVar4 * 2) != 0) ||

         (*(short *)(param_1 + 0x84 + iVar4 * 2) != 0)) {

        if (iVar4 == 0) {

          pcVar6 = "dmgadd_equip_physical]\n";

        }

        else if (iVar4 == 1) {

          pcVar6 = "dmgadd_equip_fire]\n";

        }

        else if (iVar4 == 3) {

          pcVar6 = "dmgadd_equip_corrosive]\n";

        }

        else if (iVar4 == 4) {

          pcVar6 = "dmgadd_equip_contamination]\n";

        }

        else {

          if (iVar4 != 5) goto LAB_0061a9e2;

          pcVar6 = "dmgadd_equip_energy]\n";

        }

        FUN_005781b0(param_3,param_2,pcVar6,1);

      }

LAB_0061a9e2:

      iVar4 = iVar4 + 1;

    } while (iVar4 < 6);

  }

  bVar5 = (*(uint *)(param_1 + 0x624) & 0x20000) == 0;

  if (!bVar5) {

    fVar1 = *(float *)(param_1 + 0x128);

    if (g_flZero <= *(float *)(param_1 + 0x124)) {

      FUN_005781b0(param_3,param_2,"power2hp]\n",1);

    }

    if (g_flZero <= fVar1) {

      FUN_005781b0(param_3,param_2,"power2heat]\n",1);

    }

    bVar5 = (*(uint *)(param_1 + 0x624) & 0x20000) == 0;

  }

  if (((!bVar5) && (*(int *)(param_1 + 0x134) != -1)) && (*(float *)(param_1 + 0x138) != g_flZero))

  {

    FUN_005781b0(param_3,param_2,"cooldown_amount] (percent)\n",1);

    FUN_005781b0(param_3,param_2,"cooldown_category] (string)\n",1);

  }

  FUN_00578190(param_1,param_2,param_3);

  return;

}
