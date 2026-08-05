# Raw capture: FUN_0052dff0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052dff0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0052dff0` |
| **Canonical name** | `FUN_0052dff0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int __fastcall FUN_0052dff0(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int local_214;
  int local_210;
  int local_20c;
  undefined4 local_208 [9];
  short local_1e2;
  
  iVar1 = *(int *)(param_1 + 0x594);
  local_214 = iVar1;
  piVar2 = (int *)FUN_00538ab0(&local_20c,&local_214);
  if (*piVar2 == DAT_00b045b4) {
    return 0;
  }
  puVar4 = (undefined4 *)(*piVar2 + 0x10);
  puVar5 = local_208;
  for (iVar3 = 0x7f; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  local_214 = iVar1;
  FUN_00418b80(&local_210,&local_214);
  local_20c = *(int *)(param_1 + 0x588);
  if (local_210 == local_20c) {
    local_214 = 0;
  }
  else {
    local_214 = *(int *)(local_210 + 0x14);
  }
  iVar3 = FUN_0052d0b0();
  iVar3 = iVar3 + local_214;
  local_210 = iVar1;
  FUN_00418b80(&local_214,&local_210);
  if ((local_214 != local_20c) && (0 < *(int *)(local_214 + 0x14))) {
    return (iVar3 + local_1e2 * 2) * 10;
  }
  return 100;
}
```
