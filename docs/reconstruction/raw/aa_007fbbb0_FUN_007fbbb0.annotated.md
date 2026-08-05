# Annotated low-level: FUN_007fbbb0

| Field | Value |
|---|---|
| Stable ID | `aa_007fbbb0` |
| VA | `0x007fbbb0`–`0x007fbc6a` |
| System | `inventory-transfer` (Grab pre-helper / shared held clear) |
| Date | 2026-07-29 (wave8 dual strengthen; raw body unchanged) |

## Machine-level notes

- Source: raw capture for `aa_007fbbb0`; live `force_decompile` 2026-07-29 ≡ raw.
- **ESI** = client host* (`register:0x18`). Grab sites often `MOV ESI, DAT_00d1a840` before CALL; other sites pass host in EBX then `MOV ESI,EBX`.
- No stack parameters consumed by body; no DAT_* global stores; no packet opcode.
- All work is **CALLIND** through object vtables — no named direct callees.
- Prefer assembly when decompiler conflicts (none observed this pass).
- Offsets verified in body bytes via `read_memory`: `0x113c`, `0xf40`, `0xd0`, `0x2b0`, `0xb0`, `0x1c8`, `0x3c0`, `0x514`→`0x498`, `0x518`→`0x49c`.

## Layout (host ESI)

| Offset | Shape | Use |
|---|---|---|
| `+0x113c` | `object*` | Held / cursor inventory object |
| `+0xf40` | `T**` | Double-indirect UI root (`**(host+0xf40)`) |

## Control flow (annotated)

```c
void FUN_007fbbb0(void)  /* ESI = client host* */
{
  int iVar1;
  char cVar2;
  int unaff_ESI;

  /* Gate 1: held object present */
  if (*(int *)(unaff_ESI + 0x113c) != 0) {
    /* Gate 2: held.vtbl+0xd0() bool/char */
    cVar2 = (**(code **)(**(int **)(unaff_ESI + 0x113c) + 0xd0))();
    /* Gate 3: held+0x2b0 non-null */
    if ((cVar2 != '\0') && (*(int *)(*(int *)(unaff_ESI + 0x113c) + 0x2b0) != 0)) {
      /* UI root detach/notify with held as arg */
      (**(code **)(*(int *)**(undefined4 **)(unaff_ESI + 0xf40) + 0xb0))
                (*(int *)(unaff_ESI + 0x113c));
      /* held release / dtor-style(0) */
      (**(code **)(**(int **)(unaff_ESI + 0x113c) + 4))(0);
      /* UI clears */
      (**(code **)(*(int *)**(undefined4 **)(unaff_ESI + 0xf40) + 0x1c8))(0);
      (**(code **)(*(int *)**(undefined4 **)(unaff_ESI + 0xf40) + 0x3c0))(0);
      /* optional field pair sync if positive */
      if (0 < *(int *)(**(int **)(unaff_ESI + 0xf40) + 0x514)) {
        iVar1 = **(int **)(unaff_ESI + 0xf40);
        *(undefined4 *)(iVar1 + 0x498) = *(undefined4 *)(iVar1 + 0x514);
      }
      if (0 < *(int *)(**(int **)(unaff_ESI + 0xf40) + 0x518)) {
        iVar1 = **(int **)(unaff_ESI + 0xf40);
        *(undefined4 *)(iVar1 + 0x49c) = *(undefined4 *)(iVar1 + 0x518);
      }
    }
  }
  return;
}
```

## Call placement (Grab)

- `Client_SendInventoryGrab_FromGrid` @ call `0x00860e66` — before busy gate / pack `0x2034`.
- `Client_SendInventoryGrab_Hardpoint` @ call `0x00862d99` — first work in body.
- Additional non-Grab fan-in (11 total xrefs) — shared clearer, not packer-exclusive.

## Open questions

- Concrete vtable targets for `+0xd0` / `+0xb0` / `+0x1c8` / `+0x3c0` / `+4`.
- Semantics of `0x514/0x498` and `0x518/0x49c` integer pairs.
- Who nulls `host+0x113c` after release (not this body).
- Official rename beyond parent-seed alias.
