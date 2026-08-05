# Annotated low-level: CVOGReaction_ShowScreenText

| Field | Value |
|---|---|
| Stable ID | `aa_0057c4a0` |
| VA | `0x0057c4a0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0057c4a0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall CVOGReaction_ShowScreenText(int param_1,int param_2)

{
  undefined4 local_138 [7];
  undefined4 local_11c;
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 local_104;
  
  local_138[0] = *(undefined4 *)(param_1 + 0x160);
  local_110 = *(undefined4 *)(param_2 + 0x160);
  local_10c = *(undefined4 *)(param_2 + 0x164);
  local_108 = *(undefined4 *)(param_2 + 0x168);
  local_104 = *(undefined4 *)(param_2 + 0x16c);
  local_11c = 0x26;
  Client_SendLogicUiPacket(local_138);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
