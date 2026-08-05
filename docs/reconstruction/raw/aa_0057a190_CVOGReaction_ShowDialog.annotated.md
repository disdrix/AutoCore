# Annotated low-level: CVOGReaction_ShowDialog

| Field | Value |
|---|---|
| Stable ID | `aa_0057a190` |
| VA | `0x0057a190` |
| System | missions-progression |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0057a190`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall CVOGReaction_ShowDialog(int param_1,int param_2)

{
  undefined4 *puVar1;
  char *pcVar2;
  undefined4 *puVar3;
  
  if (param_2 != 0) {
    *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_2 + 0x160);
    *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(param_2 + 0x164);
    puVar1 = *(undefined4 **)(param_1 + 0x10);
    puVar3 = *(undefined4 **)(param_1 + 0xc);
    *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(param_2 + 0x168);
    *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(param_2 + 0x16c);
    for (; puVar3 != puVar1; puVar3 = puVar3 + 1) {
      pcVar2 = (char *)*puVar3;
      if (*pcVar2 == '\0') {
        CVOGMap_LookupVariable(*(undefined4 *)(pcVar2 + 4),pcVar2 + 8,param_2);
      }
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
