# Raw capture: Client_RecvLoginCallback_7

| Field | Value |
|---|---|
| **Stable ID** | `aa_008226f0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008226f0` |
| **Canonical name** | `Client_RecvLoginCallback_7` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void Client_RecvLoginCallback_7(void)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  
  OutputDebugStringA("RecvPlayFail\n");
  if (DAT_00d1b780 == (int *)0x0) {
    return;
  }
  if (*DAT_00d1b780 != DAT_00d1b77c) {
    return;
  }
  FUN_00944b20(1);
  piVar1 = *(int **)(DAT_00d1b77c + 0xa74);
  if (piVar1 == (int *)0x0) {
    return;
  }
  piVar2 = (int *)piVar1[0x164];
  if (piVar2 == (int *)0x0) {
LAB_008227cf:
    if (DAT_00d1b1e4 == '\0') goto LAB_008227df;
  }
  else if (DAT_00d1b1e4 == '\0') {
    *(undefined1 *)((int)piVar2 + 0x489) = 0;
    piVar3 = (int *)(**(code **)(*piVar2 + 0x170))(3);
    piVar2[0x8b] = *piVar3;
    piVar2 = (int *)piVar1[0x165];
    *(undefined1 *)((int)piVar2 + 0x489) = 0;
    piVar3 = (int *)(**(code **)(*piVar2 + 0x170))(3);
    piVar2[0x8b] = *piVar3;
    (**(code **)(*(int *)piVar1[0x159] + 0xd4))(1);
    (**(code **)(*(int *)piVar1[0x15b] + 0xd4))(1);
    FUN_007fdfb0(&DAT_00d1a840,"Failed to login!  Please try again in a moment.",0x4e24,1,0);
    goto LAB_008227cf;
  }
  DAT_00d1b1e4 = '\0';
LAB_008227df:
  (**(code **)(*piVar1 + 0x34c))();
  return;
}
```
