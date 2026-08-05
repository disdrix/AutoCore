# Annotated low-level: NDAssetImage_FlipVertical

| Field | Value |
|---|---|
| Stable ID | `aa_004332e0` |
| VA | `0x004332e0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004332e0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* Vertical flip of NDAssetImage pixel buffer (top-origin TGA normalize). After flip y=0 is bottom
   of image. */

undefined4 NDAssetImage_FlipVertical(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  int unaff_EBX;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int local_8;
  
  if (*(int *)(unaff_EBX + 0x1b0) == 0) {
    return 0;
  }
  puVar1 = malloc(*(int *)(unaff_EBX + 0xc) * *(int *)(unaff_EBX + 0x10));
  if (puVar1 != (undefined4 *)0x0) {
    uVar4 = *(uint *)(unaff_EBX + 0xc);
    puVar2 = (undefined4 *)((*(int *)(unaff_EBX + 0x10) + -1) * uVar4 + *(int *)(unaff_EBX + 0x1b0))
    ;
    local_8 = 0;
    puVar5 = puVar1;
    if (0 < *(int *)(unaff_EBX + 0x10)) {
      do {
        puVar6 = puVar2;
        puVar7 = puVar5;
        for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
          *puVar7 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar7 = puVar7 + 1;
        }
        for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
          *(undefined1 *)puVar7 = *(undefined1 *)puVar6;
          puVar6 = (undefined4 *)((int)puVar6 + 1);
          puVar7 = (undefined4 *)((int)puVar7 + 1);
        }
        uVar4 = *(uint *)(unaff_EBX + 0xc);
        local_8 = local_8 + 1;
        puVar2 = (undefined4 *)((int)puVar2 - uVar4);
        puVar5 = (undefined4 *)((int)puVar5 + uVar4);
      } while (local_8 < *(int *)(unaff_EBX + 0x10));
    }
    free(*(void **)(unaff_EBX + 0x1b0));
    *(undefined4 **)(unaff_EBX + 0x1b0) = puVar1;
    return 1;
  }
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
