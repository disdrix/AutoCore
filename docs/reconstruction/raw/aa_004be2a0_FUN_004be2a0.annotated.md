# Annotated low-level: FUN_004be2a0 / ListTrackedObj_CompleteDtor

| Field | Value |
|---|---|
| Stable ID | `aa_004be2a0` |
| VA | `0x004be2a0` |
| Structural name | `ListTrackedObj_CompleteDtor` (**Inferred**) |
| System | large owned object complete dtor (list-tracked + global counts) |
| Date | 2026-07-29 (W30-P) |

## Machine-level notes

- Complete destructor only — never `operator_delete(this)`. Callers pair with `operator_delete(owned)` (e.g. `Elem0x28_CompleteDtor` W29-F).
- Intrusive doubly-linked list at `+0/+4`; global counters `DAT_00b03734` / `DAT_00b0373c`; optional global `DAT_00b03730`.
- End-of-body dual base vtbl install `PTR_LAB_009cb5cc` @ `+0x10` and `+0x20` (derived complete dtor → base).
- Reject scaffold plate `Named_CalleeOf_Named_VOG_DEBUG_STOP_*` — role is complete dtor of list-tracked owned objects, not debug stop.
- Nested `FUN_00763f60` is a non-trivial member complete dtor (OWN residual); `FUN_0074b580` is empty.

## Call-site roles (external, not owned)

| Caller | Role |
|---|---|
| `FUN_005b8000` | destroy owned@`elem+0x24` then free |
| `FUN_00494530` / `FUN_00497a30` | grid/cell owned@`+0x24` of 0x28-stride elements |
| `FUN_00494700` | related teardown |
| self | when `DAT_00b0373c` hits 0, destroy global `DAT_00b03730` |

## Open questions

- Product/MSVC demangle for class (base vtbl `009cb5cc` only seals base install, not product name).
- Semantics of flag@`+0x5D0` and nested blob type under flag path.
- Full meaning of dual global counters.
- Runtime / bit-exact / differential.
