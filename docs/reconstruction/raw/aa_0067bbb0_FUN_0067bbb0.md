# Raw capture: FUN_0067bbb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0067bbb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0067bbb0` |
| **Canonical name** | `FUN_0067bbb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
uint __thiscall FUN_0067bbb0(SOCKET *param_1,int param_2,uint param_3)

{
  SOCKET SVar1;
  int iVar2;
  uint uVar3;
  int local_210;
  int local_20c;
  fd_set local_208;
  fd_set local_104;
  
  SVar1 = *param_1;
  if (SVar1 == 0xffffffff) {
    return 0xfffffffc;
  }
  if (param_3 == 0) {
    return 0;
  }
  if (param_2 != -1) {
    local_210 = param_2 / 1000;
    local_20c = (param_2 % 1000) * 1000;
  }
  uVar3 = param_3 & 1;
  if (uVar3 != 0) {
    local_208.fd_array[0] = SVar1;
  }
  local_208.fd_count = (u_int)(uVar3 != 0);
  param_3 = param_3 & 2;
  if (param_3 != 0) {
    local_104.fd_array[0] = SVar1;
  }
  local_104.fd_count = (u_int)(param_3 != 0);
  iVar2 = select(0,(fd_set *)(-(uint)(uVar3 != 0) & (uint)&local_208),
                 (fd_set *)(-(uint)(param_3 != 0) & (uint)&local_104),(fd_set *)0x0,
                 (timeval *)(-(uint)(param_2 != -1) & (uint)&local_210));
  if (iVar2 == -1) {
    return 0xfffffffc;
  }
  iVar2 = __WSAFDIsSet(*param_1,&local_208);
  uVar3 = (uint)(iVar2 != 0);
  iVar2 = __WSAFDIsSet(*param_1,&local_104);
  if (iVar2 != 0) {
    uVar3 = uVar3 | 2;
  }
  return uVar3;
}
```
