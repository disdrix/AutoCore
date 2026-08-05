# Annotated low-level: FUN_008cc5a0

| Field | Value |
|---|---|
| Stable ID | `aa_008cc5a0` |
| VA | `0x008cc5a0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008cc5a0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_008cc5a0(void)

{
  char cVar1;
  int *unaff_ESI;
  char *unaff_EDI;
  
  if (unaff_ESI[0x195] != 0) {
    (**(code **)(*(int *)unaff_ESI[0x195] + 0x268))();
    FUN_008aab00(unaff_ESI[0x195]);
    (**(code **)(*(int *)unaff_ESI[0x195] + 0x34c))();
  }
  cVar1 = (**(code **)(*unaff_ESI + 0x3d8))();
  if (cVar1 != '\0') {
    cVar1 = (**(code **)(*unaff_ESI + 0xd0))();
    if (cVar1 != '\0') {
      if ((unaff_EDI == (char *)0x0) || (*unaff_EDI == '\0')) {
        if (unaff_ESI[400] != 0) {
          (**(code **)(*(int *)unaff_ESI[400] + 4))(0);
        }
        if (unaff_ESI[0x191] != 0) {
          (**(code **)(*(int *)unaff_ESI[0x191] + 4))(0);
        }
        if (unaff_ESI[0x192] != 0) {
          (**(code **)(*(int *)unaff_ESI[0x192] + 4))(0);
        }
        if (unaff_ESI[0x193] != 0) {
          (**(code **)(*(int *)unaff_ESI[0x193] + 4))(0);
        }
        if (unaff_ESI[0x194] != 0) {
          (**(code **)(*(int *)unaff_ESI[0x194] + 4))(0);
        }
        if (unaff_ESI[0x195] != 0) {
          (**(code **)(*(int *)unaff_ESI[0x195] + 4))(0);
        }
      }
      else {
        if (unaff_ESI[400] != 0) {
          (**(code **)(*(int *)unaff_ESI[400] + 0xfc))(1,0x3f000000);
        }
        if (unaff_ESI[0x191] != 0) {
          (**(code **)(*(int *)unaff_ESI[0x191] + 0xfc))(1,0x3f000000);
        }
        if (unaff_ESI[0x192] != 0) {
          (**(code **)(*(int *)unaff_ESI[0x192] + 0xfc))(1,0x3f000000);
        }
        if (unaff_ESI[0x193] != 0) {
          (**(code **)(*(int *)unaff_ESI[0x193] + 0xfc))(1,0x3f000000);
        }
        if (unaff_ESI[0x194] != 0) {
          (**(code **)(*(int *)unaff_ESI[0x194] + 0xfc))(1,0x3f000000);
        }
        if (unaff_ESI[0x195] != 0) {
          (**(code **)(*(int *)unaff_ESI[0x195] + 0xfc))(1,0x3f000000);
          return;
        }
      }
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
