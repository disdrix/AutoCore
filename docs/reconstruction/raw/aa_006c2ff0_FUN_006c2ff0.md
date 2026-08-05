# Raw capture: FUN_006c2ff0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006c2ff0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006c2ff0` |
| **Canonical name** | `FUN_006c2ff0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_006c2ff0(int param_1,int param_2,int *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  undefined4 *puVar8;
  
  fVar1 = *(float *)(param_1 + 0x18);
  fVar2 = *(float *)(param_2 + 0x14);
  fVar3 = *(float *)(param_1 + 0x10);
  fVar4 = *(float *)(param_2 + 8);
  iVar7 = *param_3;
  fVar5 = *(float *)(param_1 + 0x14);
  fVar6 = *(float *)(param_2 + 8);
  puVar8 = (undefined4 *)param_3[1];
  puVar8[3] = *(undefined4 *)(param_1 + 0x1c);
  puVar8[1] = fVar3 * fVar4;
  *puVar8 = 0x41004;
  puVar8[2] = fVar5 * fVar6;
  *param_3 = iVar7 + 0x20;
  param_3[1] = (int)(puVar8 + 4);
  *(float *)(iVar7 + 0x1c) = fVar1 * fVar2;
  return;
}
```
