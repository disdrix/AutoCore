# Annotated low-level: FUN_0080fbb0

| Field | Value |
|---|---|
| Stable ID | `aa_0080fbb0` |
| VA | `0x0080fbb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0080fbb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0080fbb0(int param_1,int param_2)

{
  char cVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char *pcVar5;
  char *pcVar6;
  undefined4 uVar7;
  char local_818 [20];
  int local_804;
  char local_800 [1024];
  char local_400 [1024];
  
  if (*(int *)(param_1 + 0x109c) != 0) {
    FUN_007a69d0();
    local_818[0] = '\0';
    local_818[1] = '\0';
    local_818[2] = '\0';
    local_818[3] = '\0';
    local_818[4] = '\0';
    local_818[5] = '\0';
    local_818[6] = '\0';
    local_818[7] = '\0';
    local_818[8] = '\0';
    local_818[9] = '\0';
    local_818[10] = '\0';
    local_818[0xb] = '\0';
    pcVar6 = (char *)(param_2 + 0x1a);
    local_818[0xc] = '\0';
    local_818[0xd] = '\0';
    local_818[0xe] = '\0';
    local_818[0xf] = '\0';
    local_818[0x10] = 0;
    strncpy(local_818,pcVar6,0x10);
    pcVar5 = (char *)(param_2 + 0x2e);
    pcVar2 = pcVar5;
    do {
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    local_804 = (int)pcVar2 - (param_2 + 0x2f);
    if (local_804 == 0) {
      pcVar2 = (char *)FUN_007a6de0("How can I help you?",0xffffffff);
      pcVar5 = local_800;
      do {
        cVar1 = *pcVar2;
        *pcVar5 = cVar1;
        pcVar2 = pcVar2 + 1;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      pcVar5 = (char *)FUN_007a6de0("How can I help you?",0xffffffff);
      uVar3 = FUN_007a6de0(" says:\n",0xffffffff);
      uVar4 = FUN_007a6de0(&DAT_00a7ec08,0xffffffff);
    }
    else {
      pcVar2 = pcVar5;
      do {
        cVar1 = *pcVar2;
        pcVar2[(int)(local_800 + -(int)pcVar5)] = cVar1;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
      uVar3 = FUN_007a6de0(" says:\n",0xffffffff);
      uVar4 = FUN_007a6de0(&DAT_00a7ec08,0xffffffff);
    }
    sprintf(local_400,"%s%s%s%s",uVar4,pcVar6,uVar3,pcVar5);
    uVar3 = *(undefined4 *)(param_2 + 4);
    uVar7 = 0;
    pcVar6 = local_800;
    pcVar5 = local_818;
    uVar4 = __RTDynamicCast(*(undefined4 *)(param_1 + 0x109c),0,&CVOGDialog::RTTI_Type_Descriptor,
                            &CDlgChatLog::RTTI_Type_Descriptor,0,uVar3,pcVar5,pcVar6,0);
    FUN_008f8200(uVar4,uVar3,pcVar5,pcVar6,uVar7);
    FUN_007fdfb0(param_1,local_400,0xffffffff,0,0);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
