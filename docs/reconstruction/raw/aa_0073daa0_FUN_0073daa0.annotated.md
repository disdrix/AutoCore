# Annotated low-level: FUN_0073daa0

| Field | Value |
|---|---|
| Stable ID | `aa_0073daa0` |
| VA | `0x0073daa0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0073daa0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0073daa0(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  bool bVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [28];
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &DAT_009ad726;
  local_c = ExceptionList;
  iVar7 = *(int *)(param_1 + 4);
  if (((iVar7 != 0) && (iVar1 = *(int *)(param_1 + 8), (iVar1 - iVar7) / 0x14 != 0)) &&
     (bVar4 = false, iVar7 != iVar1)) {
    piVar8 = (int *)(iVar7 + 0xc);
    ExceptionList = &local_c;
    do {
      piVar2 = (int *)*piVar8;
      for (piVar9 = (int *)piVar8[-1]; piVar9 != piVar2; piVar9 = piVar9 + 1) {
        iVar3 = *piVar9;
        if (0 < *(int *)(iVar3 + 4)) {
          if (!bVar4) {
            if (*(int *)(param_1 + 4) == 0) {
              iVar5 = 0;
            }
            else {
              iVar5 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x14;
            }
            uVar6 = FUN_0076cec0(&param_1,"Effects (%d) still allocated at shutdown!",iVar5);
            vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effEffectFactory.cpp"
                           ,0xb0,2,uVar6);
            bVar4 = true;
          }
          iVar5 = FUN_0096a630(local_28);
          local_4 = 0;
          if (*(uint *)(iVar5 + 0x18) < 0x10) {
            iVar5 = iVar5 + 4;
          }
          else {
            iVar5 = *(int *)(iVar5 + 4);
          }
          uVar6 = FUN_0076cec0(&param_1,"\t%d Instances of effect :%s",*(undefined4 *)(iVar3 + 4),
                               iVar5);
          vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effEffectFactory.cpp"
                         ,0xb4,1,uVar6);
          local_4 = 0xffffffff;
          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
          ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);
        }
      }
      iVar7 = iVar7 + 0x14;
      piVar8 = piVar8 + 5;
    } while (iVar7 != iVar1);
  }
  ExceptionList = local_c;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
