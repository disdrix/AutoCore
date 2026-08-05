# Annotated low-level: FUN_0067baf0

| Field | Value |
|---|---|
| Stable ID | `aa_0067baf0` |
| VA | `0x0067baf0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0067baf0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Type propagation algorithm not settling */

void __thiscall FUN_0067baf0(undefined4 *param_1,char param_2)

{
  undefined4 uVar1;
  int iVar2;
  _OSVERSIONINFOA *p_Var3;
  uint local_ac [2];
  undefined1 local_a4 [4];
  _OSVERSIONINFOA local_a0;
  
  p_Var3 = &local_a0;
  for (iVar2 = 0x25; iVar2 != 0; iVar2 = iVar2 + -1) {
    p_Var3->dwOSVersionInfoSize = 0;
    p_Var3 = (_OSVERSIONINFOA *)&p_Var3->dwMajorVersion;
  }
  local_a0.dwMinorVersion = 0;
  local_a0.dwOSVersionInfoSize = 0x94;
  local_a0.dwMajorVersion = 5;
  GetVersionExA(&local_a0);
  if ((5 < local_a0.dwMajorVersion) || (local_a0.dwMajorVersion == 5)) {
    local_ac[0] = (uint)(param_2 != '\0');
    local_ac[1] = 0;
    iVar2 = WSAIoctl(*param_1,0x9800000c,local_ac,4,0,0,local_ac + 1,0,0);
    if (iVar2 == -1) {
      iVar2 = WSAGetLastError();
      if (iVar2 != 0x2733) {
        uVar1 = FUN_0076cec0(local_a4,"WSAIoctl(SIO_UDP_CONNRESET) error: %lu",iVar2);
        vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netSocket.cpp"
                       ,0x290,2,uVar1);
      }
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
