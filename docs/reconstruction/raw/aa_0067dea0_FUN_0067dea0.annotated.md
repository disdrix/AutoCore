# Annotated low-level: FUN_0067dea0

| Field | Value |
|---|---|
| Stable ID | `aa_0067dea0` |
| VA | `0x0067dea0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0067dea0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
int __thiscall FUN_0067dea0(int param_1,int *param_2,uint *param_3)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  int local_4;
  
  piVar4 = param_2;
  *param_3 = 0;
  local_4 = 0;
  if (*(int *)(param_1 + 0x2a24) != 0) {
    do {
      if ((*(int *)(param_1 + 0x2968) == 0) ||
         (param_2 = (int *)(*(int *)(param_1 + 0x296c) - *(int *)(param_1 + 0x2968) >> 2),
         param_2 == (int *)0x0)) {
        FUN_0067de40();
      }
      puVar1 = *(undefined4 **)(param_1 + 0x2968);
      if (puVar1 == (undefined4 *)0x0) {
        return local_4;
      }
      if (*(int *)(param_1 + 0x296c) - (int)puVar1 >> 2 == 0) {
        return local_4;
      }
      piVar2 = (int *)*puVar1;
      iVar6 = (-(uint)(local_4 != 0) & 0xfffffffc) + 0x10;
      if (*piVar2 != 0) {
        iVar6 = iVar6 + *(int *)(*piVar2 + 0xc);
      }
      param_2 = piVar2;
      if (*(uint *)(param_1 + 0x2a28) < *param_3 + iVar6) {
        if (local_4 != 0) {
          return local_4;
        }
        uVar5 = FUN_0076cec0(&param_3,
                             "Session %lu: Packet on front of send queue is too large to send (%lu / %lu data, max %lu)"
                             ,*(undefined4 *)(param_1 + 0x2a20),iVar6,*(undefined4 *)(*piVar2 + 0xc)
                             ,*(undefined4 *)(param_1 + 0x2a28));
        vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netSession.cpp"
                       ,0x83f,3,uVar5);
        FUN_0067c430();
        return 0;
      }
      memmove(puVar1,puVar1 + 1,(*(int *)(param_1 + 0x296c) - (int)(puVar1 + 1) >> 2) * 4);
      *(int *)(param_1 + 0x296c) = *(int *)(param_1 + 0x296c) + -4;
      iVar3 = piVar4[1];
      if ((iVar3 == 0) || ((uint)(piVar4[3] - iVar3 >> 2) <= (uint)(piVar4[2] - iVar3 >> 2))) {
        FUN_0067f930(piVar4[2],1,&param_2);
      }
      else {
        puVar1 = (undefined4 *)piVar4[2];
        *puVar1 = piVar2;
        piVar4[2] = (int)(puVar1 + 1);
      }
      if (local_4 == 1) {
        *param_3 = *param_3 + 0xc;
      }
      *param_3 = *param_3 + iVar6;
      local_4 = local_4 + 1;
    } while (*param_3 < *(uint *)(param_1 + 0x2a24));
  }
  return local_4;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
