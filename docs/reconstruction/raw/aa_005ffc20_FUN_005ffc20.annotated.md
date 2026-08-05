# Annotated low-level: CVOGHBToken_OnEnd

| Field | Value |
|---|---|
| Stable ID | `aa_005ffc20` |
| VA | `0x005ffc20` |
| Ghidra | `FUN_005ffc20` |
| Canonical | `CVOGHBToken_OnEnd` (**RTTI Confirmed**) |
| System | heartbeat / CVOGHBToken |
| Date | 2026-07-29 (W17-K dual seal) |

## Machine-level notes

- **Class:** `CVOGHBToken` — RTTI `.?AVCVOGHBToken@@` at type_info `0x00af4660`.
- **Slot:** vtbl `+0x14` OnEnd at DATA `0x009dde40` (vtable base `0x009dde2c` with dtor `0x005d6c40` at `+0`).
- **ABI:** `__thiscall` ECX = `CVOGHBToken* this` (no stack args). Sole dispatch is virtual (no direct CALL xrefs).
- **Related object:** `this+0x18` — if non-null, vcall `+0x1d4` resolves a world/object host.
- **Counter gate:** `this+0x10 < 1` required to set character flag (signed compare / `jg` skip).
- **Character path:** MI-adjust host then `vtbl+0x210(0)` → character*; `Character_SetFlagByte_plus529_WithNetDirty(char*, 1)`.
- **Epilogue:** tail-jmp empty stub `FUN_005081f0` (shared nop vfunc) — same OnEnd shape as `CVOGHBOKToCastAgain_OnEnd`.
- Adjacent vtbl slots match HB base family: `StampLastFireTime`, `TryFire`, `RescheduleAfterFire`, `005083f0` (helper that vcalls OnEnd when flag nonzero).

## Pseudocode (annotated)

```c
// ECX = CVOGHBToken* this   // vtbl+0x14 OnEnd
void __thiscall CVOGHBToken_OnEnd(CVOGHBToken *this)
{
  int *related = *(int **)((char *)this + 0x18);
  if (related != NULL) {
    // related->vtbl[+0x1d4]()
    int host = (**(code **)(*related + 0x1d4))();
    if (host != 0 && *(int *)((char *)this + 0x10) < 1) {
      // MI-adjusted this + vtbl[+0x210](0) → character*
      // framing: push 1 (flag); push 0 (vcall arg); call; ECX=eax; SetFlag(1)
      void *character =
        (**(code **)(*(int *)(*(int *)(*(int *)(host + 4) + 4) + 4 + host) + 0x210))(0);
      Character_SetFlagByte_plus529_WithNetDirty(character, 1);  // FUN_005208e0
    }
  }
  CVOGHBBase_EmptyVFunc_ret();  // FUN_005081f0 — nop ret
}
```

## Layout (this)

| Offset | Role | Conf |
|-------:|------|------|
| +0x10 | signed counter / remaining; must be `< 1` to set flag | **High** (gate) |
| +0x18 | related object* (cleared by base helper `005083f0` on some paths) | **High** |

## Open questions

- Product English for `+0x10` (token count vs state enum).
- Semantic of character `+0x529` / ghost mask `0x100` (see `aa_005208e0` residual).
- Identity of related `+0x1d4` resolver (shared with ghost unpack host path).
