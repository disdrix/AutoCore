# Annotated low-level: FUN_008eba20

| Field | Value |
|---|---|
| Stable ID | `aa_008eba20` |
| VA | `0x008eba20` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008eba20`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_008eba20(void)

{
  char cVar1;
  char unaff_BL;
  int *unaff_ESI;
  
  cVar1 = (**(code **)(*unaff_ESI + 0x3d8))();
  if (cVar1 != '\0') {
    if (unaff_ESI[0x19b] != 0) {
      (**(code **)(*(int *)unaff_ESI[0x19b] + 4))();
    }
    if (unaff_ESI[0x19c] != 0) {
      (**(code **)(*(int *)unaff_ESI[0x19c] + 4))();
    }
    if (unaff_ESI[0x19d] != 0) {
      (**(code **)(*(int *)unaff_ESI[0x19d] + 4))(0);
    }
    if (unaff_ESI[0x19e] != 0) {
      (**(code **)(*(int *)unaff_ESI[0x19e] + 4))();
    }
    if (unaff_ESI[0x199] != 0) {
      (**(code **)(*(int *)unaff_ESI[0x199] + 4))();
    }
    if (unaff_ESI[0x165] != 0) {
      (**(code **)(*(int *)unaff_ESI[0x165] + 4))();
    }
    if (unaff_ESI[0x19a] != 0) {
      (**(code **)(*(int *)unaff_ESI[0x19a] + 4))();
    }
    if (unaff_ESI[0x166] != 0) {
      (**(code **)(*(int *)unaff_ESI[0x166] + 4))();
    }
    if (unaff_ESI[0x17f] != 0) {
      (**(code **)(*(int *)unaff_ESI[0x17f] + 4))(unaff_BL == '\0');
    }
    if (unaff_ESI[0x180] != 0) {
      (**(code **)(*(int *)unaff_ESI[0x180] + 4))(unaff_BL == '\0');
    }
    if (unaff_ESI[0x181] != 0) {
      (**(code **)(*(int *)unaff_ESI[0x181] + 4))(unaff_BL == '\0');
    }
    if (unaff_ESI[0x182] != 0) {
      (**(code **)(*(int *)unaff_ESI[0x182] + 4))(unaff_BL == '\0');
    }
    if (unaff_ESI[0x183] != 0) {
      (**(code **)(*(int *)unaff_ESI[0x183] + 4))(unaff_BL == '\0');
    }
    if (unaff_ESI[0x184] != 0) {
      (**(code **)(*(int *)unaff_ESI[0x184] + 4))(unaff_BL == '\0');
    }
    if (unaff_ESI[0x185] != 0) {
      (**(code **)(*(int *)unaff_ESI[0x185] + 4))(unaff_BL == '\0');
    }
    if (unaff_ESI[0x186] != 0) {
      (**(code **)(*(int *)unaff_ESI[0x186] + 4))(unaff_BL == '\0');
    }
    if (unaff_ESI[0x187] != 0) {
      (**(code **)(*(int *)unaff_ESI[0x187] + 4))(unaff_BL == '\0');
    }
    if (unaff_ESI[0x188] != 0) {
      (**(code **)(*(int *)unaff_ESI[0x188] + 4))(unaff_BL == '\0');
    }
    if (unaff_ESI[0x189] != 0) {
      (**(code **)(*(int *)unaff_ESI[0x189] + 4))(unaff_BL == '\0');
    }
    if (unaff_ESI[0x18a] != 0) {
      (**(code **)(*(int *)unaff_ESI[0x18a] + 4))(unaff_BL == '\0');
    }
    if (unaff_ESI[0x18b] != 0) {
      (**(code **)(*(int *)unaff_ESI[0x18b] + 4))(unaff_BL == '\0');
    }
    if (unaff_ESI[0x18c] != 0) {
      (**(code **)(*(int *)unaff_ESI[0x18c] + 4))(unaff_BL == '\0');
    }
    if (unaff_ESI[0x18d] != 0) {
      (**(code **)(*(int *)unaff_ESI[0x18d] + 4))(unaff_BL == '\0');
    }
    if (unaff_ESI[0x18e] != 0) {
      (**(code **)(*(int *)unaff_ESI[0x18e] + 4))(unaff_BL == '\0');
    }
    if (unaff_ESI[399] != 0) {
      (**(code **)(*(int *)unaff_ESI[399] + 4))(unaff_BL == '\0');
    }
    if (unaff_ESI[400] != 0) {
      (**(code **)(*(int *)unaff_ESI[400] + 4))(unaff_BL == '\0');
    }
    if (unaff_ESI[0x191] != 0) {
      (**(code **)(*(int *)unaff_ESI[0x191] + 4))(unaff_BL == '\0');
    }
    if (unaff_ESI[0x192] != 0) {
      (**(code **)(*(int *)unaff_ESI[0x192] + 4))(unaff_BL == '\0');
    }
    if (unaff_ESI[0x193] != 0) {
      (**(code **)(*(int *)unaff_ESI[0x193] + 4))(unaff_BL == '\0');
    }
    if (unaff_ESI[0x194] != 0) {
      (**(code **)(*(int *)unaff_ESI[0x194] + 4))(unaff_BL == '\0');
    }
    if (unaff_ESI[0x195] != 0) {
      (**(code **)(*(int *)unaff_ESI[0x195] + 4))(unaff_BL == '\0');
    }
    if (unaff_ESI[0x196] != 0) {
      (**(code **)(*(int *)unaff_ESI[0x196] + 4))(unaff_BL == '\0');
    }
    if (unaff_ESI[0x197] != 0) {
      (**(code **)(*(int *)unaff_ESI[0x197] + 4))(unaff_BL == '\0');
    }
    if (unaff_ESI[0x198] != 0) {
      (**(code **)(*(int *)unaff_ESI[0x198] + 4))(unaff_BL == '\0');
    }
    if (unaff_ESI[0x163] != 0) {
      (**(code **)(*(int *)unaff_ESI[0x163] + 4))(unaff_BL == '\0');
    }
    if (unaff_ESI[0x164] != 0) {
      (**(code **)(*(int *)unaff_ESI[0x164] + 4))(unaff_BL == '\0');
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
