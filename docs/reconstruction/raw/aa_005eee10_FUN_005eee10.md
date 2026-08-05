# Raw capture: FUN_005eee10

| Field | Value |
|---|---|
| **Stable ID** | `aa_005eee10` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005eee10` |
| **Canonical name** | `FUN_005eee10` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005eee10(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *extraout_ECX;
  float *unaff_ESI;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  
  FUN_005ee970();
  fVar6 = ((0.0 - *extraout_ECX * *unaff_ESI) - extraout_ECX[1] * unaff_ESI[1]) -
          extraout_ECX[2] * unaff_ESI[2];
  fVar5 = g_flOne / unaff_ESI[DAT_00d027fc];
  fVar9 = fVar5 * fVar5;
  fVar7 = fVar9 * fVar5;
  DAT_00d02790 = DAT_00d0278c * fVar5;
  DAT_00d027cc = DAT_00d027bc * fVar5;
  fVar8 = unaff_ESI[DAT_00d027d4] * DAT_00d0278c + DAT_00d027bc * unaff_ESI[DAT_00d027f0];
  fVar10 = DAT_00d027a0 * fVar6;
  _DAT_00d027b8 = DAT_00d027e4 * fVar5;
  _DAT_00d027ec = DAT_00d02794 * fVar5;
  DAT_00d02798 = 0.0 - (fVar10 + fVar8) * fVar9;
  fVar11 = unaff_ESI[DAT_00d027d4] * unaff_ESI[DAT_00d027f0] * DAT_00d027d0 *
           g_flLevelUpUiBase_Inferred;
  _DAT_00d027c0 = DAT_00d027f8 * fVar5;
  DAT_00d0279c = ((fVar8 * g_flLevelUpUiBase_Inferred + fVar10) * fVar6 +
                  DAT_00d02794 * unaff_ESI[DAT_00d027f0] * unaff_ESI[DAT_00d027f0] +
                  DAT_00d027e4 * unaff_ESI[DAT_00d027d4] * unaff_ESI[DAT_00d027d4] + fVar11) * fVar7
  ;
  fVar1 = unaff_ESI[DAT_00d027d4];
  _DAT_00d02814 = DAT_00d027f4 * fVar5;
  fVar2 = unaff_ESI[DAT_00d027d4];
  fVar3 = unaff_ESI[DAT_00d027f0];
  fVar4 = unaff_ESI[DAT_00d027d4];
  DAT_00d027b4 = 0.0 - (((DAT_00d02794 * fVar3 * fVar3 + DAT_00d027e4 * fVar1 * fVar1 + fVar11) *
                         g_flVehicleHpTechCoeff + (fVar8 * g_flVehicleHpTechCoeff + fVar10) * fVar6)
                        * fVar6 + DAT_00d027f4 * fVar3 * fVar3 * fVar3 +
                        DAT_00d027f8 * fVar2 * fVar2 * fVar2 +
                        DAT_00d027c4 * fVar2 * fVar2 * unaff_ESI[DAT_00d027f0] *
                        g_flVehicleHpTechCoeff +
                       fVar1 * DAT_00d02810 * fVar3 * fVar3 * g_flVehicleHpTechCoeff) *
                       fVar7 * fVar5;
  _DAT_00d0280c =
       0.0 - (DAT_00d027f4 * unaff_ESI[DAT_00d027f0] + DAT_00d02794 * fVar6 + fVar1 * DAT_00d02810)
             * fVar9;
  fVar1 = unaff_ESI[DAT_00d027f0];
  _DAT_00d027c8 = DAT_00d027c4 * fVar5;
  DAT_00d027e8 = (((fVar4 * DAT_00d027e4 + DAT_00d027d0 * fVar1) * g_flLevelUpUiBase_Inferred +
                  DAT_00d0278c * fVar6) * fVar6 + DAT_00d02810 * fVar1 * fVar1 +
                  DAT_00d027f8 * fVar4 * fVar4 +
                 unaff_ESI[DAT_00d027d4] * unaff_ESI[DAT_00d027f0] * DAT_00d027c4 *
                 g_flLevelUpUiBase_Inferred) * fVar7;
  return;
}
```
