# Annotated low-level: CVOGCharacter_AddAttributePoints

| Field | Value |
|---|---|
| Stable ID | `aa_00531250` |
| VA | `0x00531250` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00531250`.
- Prefer assembly when decompiler conflicts (not re-checked in scaffold pass).
- Integer widths: trust decompiler until spot-checked; document corrections here.
- Side-effect order: preserve call and store order from raw pseudocode.
- Uncertainty: parameter meanings and object types often Probable/Tentative until cross-function validation.

## Pseudocode (annotated copy of raw)

```c
/* CVOGCharacter_AddAttributePoints — add short attribute points to character pool (mission

   advance/complete).

   

   Parameters: attrib delta

   Called from CVOGReaction_CompleteObjective on both advance and final branches. */



void __thiscall CVOGCharacter_AddAttributePoints(int param_1,short param_2)



{

  int iVar1;

  undefined1 local_138 [28];

  undefined4 local_11c;

  undefined4 local_118;

  undefined4 local_114;

  

  if (*(short *)(param_1 + 0x6cc) < param_2) {

    iVar1 = *(int *)(*(int *)(param_1 + 4) + 4);

    local_118 = *(undefined4 *)(iVar1 + 0x164 + param_1);

    local_114 = *(undefined4 *)(iVar1 + param_1 + 0x168);

    local_11c = 0x23;

    Client_SendLogicUiPacket(local_138);

  }

  *(uint *)(param_1 + 0x634) = *(uint *)(param_1 + 0x634) | 0x40;

  *(short *)(param_1 + 0x6cc) = param_2;

  return;

}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
- Map DAT_* globals and FUN_* callees.
