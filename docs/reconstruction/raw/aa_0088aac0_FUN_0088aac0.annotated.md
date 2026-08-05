# Annotated low-level: FUN_0088aac0

| Field | Value |
|---|---|
| Stable ID | `aa_0088aac0` |
| VA | `0x0088aac0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0088aac0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_0088aac0(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  FUN_00792600();
  (**(code **)(*param_1 + 0x404))(param_1 + 0x14f,"i_d_sc_2d_wnd_frame.xml",0xffffffff);
  piVar2 = param_1 + 0x150;
  (**(code **)(*param_1 + 0x40c))(piVar2,"i_d_sc_2d_btn_ai_state_1.xml",0x9c41,0x9c42);
  (**(code **)(*param_1 + 0x40c))(param_1 + 0x151,"i_d_sc_2d_btn_ai_state_2.xml",0x9c41,0x9c43);
  (**(code **)(*param_1 + 0x40c))(param_1 + 0x152,"i_d_sc_2d_btn_ai_state_3.xml",0x9c41,0x9c44);
  iVar1 = 3;
  do {
    if (*piVar2 != 0) {
      (**(code **)(*(int *)*piVar2 + 0x3b4))(1);
    }
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  piVar2 = param_1 + 0x153;
  (**(code **)(*param_1 + 0x408))(piVar2,"i_d_sc_2d_btn_ai_distance_1.xml",0x9c45);
  (**(code **)(*param_1 + 0x408))(param_1 + 0x154,"i_d_sc_2d_btn_ai_distance_2.xml",0x9c46);
  (**(code **)(*param_1 + 0x408))(param_1 + 0x155,"i_d_sc_2d_btn_ai_distance_3.xml",0x9c47);
  iVar1 = 3;
  do {
    if (*piVar2 != 0) {
      (**(code **)(*(int *)*piVar2 + 0x3b4))(1);
    }
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  (**(code **)(*param_1 + 0x448))();
                    /* WARNING: Could not recover jumptable at 0x0088abe0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x34c))();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
