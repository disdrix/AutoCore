# Raw capture: Client_RecvLoginCallback_3

| Field | Value |
|---|---|
| **Stable ID** | `aa_008227f0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008227f0` |
| **Canonical name** | `Client_RecvLoginCallback_3` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void Client_RecvLoginCallback_3(undefined4 param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  int *piVar4;
  
  if (((DAT_00d1b77c != 0) && (DAT_00d1b780 != (int *)0x0)) && (*DAT_00d1b780 == DAT_00d1b77c)) {
    OutputDebugStringA("RecvBlockedAccount\n");
    uVar3 = FUN_0076cec0(&param_1,"Blocked Account: code()",param_1);
    vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\appClient\\NDAuthClient.cpp",0xb8,3,uVar3);
    FUN_00944b20(1);
    piVar1 = *(int **)(DAT_00d1b77c + 0xa74);
    if (piVar1 != (int *)0x0) {
      piVar2 = (int *)piVar1[0x164];
      if (piVar2 != (int *)0x0) {
        *(undefined1 *)((int)piVar2 + 0x489) = 0;
        piVar4 = (int *)(**(code **)(*piVar2 + 0x170))(3);
        piVar2[0x8b] = *piVar4;
        piVar2 = (int *)piVar1[0x165];
        *(undefined1 *)((int)piVar2 + 0x489) = 0;
        piVar4 = (int *)(**(code **)(*piVar2 + 0x170))(3);
        piVar2[0x8b] = *piVar4;
        (**(code **)(*(int *)piVar1[0x159] + 0xd4))(1);
        (**(code **)(*(int *)piVar1[0x15b] + 0xd4))(1);
        FUN_007fdfb0(&DAT_00d1a840,
                     "The server is currently unavailable or this account is blocked. If your login attempt falls within the scheduled play times, please contact customer service for more information."
                     ,0x4e24,1,0);
      }
      (**(code **)(*piVar1 + 0x34c))();
    }
  }
  return;
}
```
