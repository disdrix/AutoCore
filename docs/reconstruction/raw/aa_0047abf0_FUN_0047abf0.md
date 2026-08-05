# Raw capture: FUN_0047abf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0047abf0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0047abf0` |
| **Canonical name** | `FUN_0047abf0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_0047abf0(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint in_EAX;
  undefined1 *puVar3;
  ushort uVar4;
  undefined1 local_30c;
  undefined1 local_30b;
  undefined1 local_30a;
  int local_308;
  undefined1 local_300 [2];
  undefined1 local_2fe [766];
  
  uVar1 = *(uint *)(param_1 + 0x68);
  if ((uVar1 & 1) == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_00476cc0(param_1);
  }
  if ((uVar1 & 4) != 0) {
    FUN_00476d60();
    FUN_0047a480();
    return;
  }
  if ((uVar1 & 2) != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_00476cc0(param_1);
  }
  *(uint *)(param_1 + 0x68) = uVar1 | 2;
  if ((*(byte *)(param_1 + 0x126) & 2) != 0) {
    if ((in_EAX < 0x301) && (in_EAX % 3 == 0)) {
      iVar2 = (int)in_EAX / 3;
      if (0 < iVar2) {
        puVar3 = local_2fe;
        local_308 = iVar2;
        do {
          FUN_0047a420();
          puVar3[-2] = local_30c;
          puVar3[-1] = local_30b;
          *puVar3 = local_30a;
          puVar3 = puVar3 + 3;
          local_308 = local_308 + -1;
        } while (local_308 != 0);
      }
      FUN_0047a480();
      FUN_004704a0(param_2,local_300,iVar2);
      if (((*(char *)(param_1 + 0x126) == '\x03') && (param_2 != 0)) &&
         ((*(byte *)(param_2 + 8) & 0x10) != 0)) {
        uVar4 = (ushort)iVar2;
        if (uVar4 < *(ushort *)(param_1 + 0x11a)) {
          FUN_00476d60();
          *(ushort *)(param_1 + 0x11a) = uVar4;
        }
        if (uVar4 < *(ushort *)(param_2 + 0x16)) {
          FUN_00476d60();
          *(ushort *)(param_2 + 0x16) = uVar4;
        }
      }
      return;
    }
    if (*(byte *)(param_1 + 0x126) == 3) {
                    /* WARNING: Subroutine does not return */
      FUN_00476cc0(param_1);
    }
    FUN_00476d60();
    FUN_0047a480();
    return;
  }
  FUN_00476d60();
  FUN_0047a480();
  return;
}
```
