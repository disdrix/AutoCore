# Raw capture: hkAngularVelocityDamper_update

| Field | Value |
|---|---|
| **Stable ID** | `aa_0064d810` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0064d810` |
| **Canonical name** | `hkAngularVelocityDamper_update` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall hkAngularVelocityDamper_update(int param_1,float *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  undefined1 local_21;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  
  iVar1 = *(int *)(param_3 + 0x30);
  iVar2 = *(int *)(iVar1 + 0x3c);
  local_1c = *(float *)(iVar2 + 0x54);
  local_18 = *(float *)(iVar2 + 0x58);
  local_20 = *(float *)(iVar2 + 0x50);
  if (local_18 * local_18 + local_1c * local_1c + local_20 * local_20 <=
      *(float *)(param_1 + 0x10) * *(float *)(param_1 + 0x10)) {
    local_14 = *(float *)(param_1 + 8) * *param_2;
  }
  else {
    local_14 = *(float *)(param_1 + 0xc) * *param_2;
  }
  local_14 = g_flOne - local_14;
  if (local_14 < 0.0) {
    local_14 = 0.0;
  }
  local_20 = local_20 * local_14;
  local_1c = local_1c * local_14;
  local_18 = local_18 * local_14;
  local_14 = *(float *)(iVar2 + 0x5c) * local_14;
  pcVar3 = (char *)FUN_005070b0(&local_21);
  if ((*pcVar3 == '\0') && (*(int *)(iVar1 + 0x44) != 0)) {
    FUN_005070d0();
  }
  (**(code **)(**(int **)(iVar1 + 0x3c) + 0x54))(&local_20);
  return;
}
```
