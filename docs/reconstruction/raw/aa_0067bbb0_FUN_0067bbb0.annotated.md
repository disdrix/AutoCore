# Annotated low-level: FUN_0067bbb0

| Field | Value |
|---|---|
| Stable ID | `aa_0067bbb0` |
| VA | `0x0067bbb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0067bbb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

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

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
