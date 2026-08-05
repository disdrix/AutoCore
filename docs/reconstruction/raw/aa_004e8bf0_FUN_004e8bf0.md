# Raw capture: FUN_004e8bf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e8bf0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004e8bf0` |
| **Canonical name** | `FUN_004e8bf0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_004e8bf0(float *param_1,float *param_2,float *param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  
  fVar6 = g_flLevelUpUiBase_Inferred;
  fVar5 = g_flOne;
  fVar1 = param_2[1];
  fVar2 = param_2[2];
  fVar3 = param_2[3];
  fVar4 = *param_2;
  fVar7 = (fVar2 * fVar3 + *param_2 * fVar1) * g_flLevelUpUiBase_Inferred;
  *param_4 = *param_3 * (g_flOne - (fVar2 * fVar2 + fVar1 * fVar1) * g_flLevelUpUiBase_Inferred) +
             *param_1;
  param_4[1] = *param_3 * fVar7 + param_1[1];
  param_4[2] = *param_3 * (fVar2 * fVar4 - fVar3 * fVar1) * fVar6 + param_1[2];
  fVar1 = param_2[2];
  fVar2 = *param_2;
  fVar3 = param_2[1];
  fVar4 = param_2[3];
  *param_4 = (fVar3 * fVar2 - fVar1 * param_2[3]) * fVar6 * param_3[1] + *param_4;
  param_4[1] = (fVar5 - (fVar1 * fVar1 + fVar2 * fVar2) * fVar6) * param_3[1] + param_4[1];
  param_4[2] = (fVar1 * fVar3 + fVar2 * fVar4) * fVar6 * param_3[1] + param_4[2];
  fVar1 = param_2[1];
  fVar2 = param_2[2];
  fVar3 = *param_2;
  fVar4 = param_2[3];
  *param_4 = param_3[2] * (fVar2 * fVar3 + fVar1 * fVar4) * fVar6 + *param_4;
  param_4[1] = param_3[2] * (fVar2 * fVar1 - fVar3 * fVar4) * fVar6 + param_4[1];
  param_4[2] = param_3[2] * (fVar5 - (fVar1 * fVar1 + fVar3 * fVar3) * fVar6) + param_4[2];
  return;
}
```

---

## Re-verify append — 2026-07-29 (OWN-ONLY dual A/B)

| Field | Value |
|---|---|
| Tool | Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` |
| Body vs original raw | **Identical CF** (live decompile matches capture) |
| Span | `004e8bf0`–`004e8db8` (`5E 8B E5 5D C3`) |
| Constants | `g_flOne@a0f2a0` = 1.0 (`0000803f`); `g_flLevelUpUiBase_Inferred@a10e74` = 2.0 (`00000040`) |
| Xrefs | 16 sites / 13 callers (leaf) |
| Dual | `reviews/A_aa_004e8bf0_Math_QuatTransformPoint_Inferred.md` + `B_…` |
| Role seal | `out.xyz = pos + R(quat)·vec`; W unwritten; reject skybox-only alias |
