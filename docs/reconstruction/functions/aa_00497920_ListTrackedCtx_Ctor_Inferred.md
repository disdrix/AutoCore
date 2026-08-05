# Function record: ListTrackedCtx_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00497920` |
| **Canonical name** | `ListTrackedCtx_Ctor_Inferred` |
| **Ghidra name** | `FUN_00497920` |
| **Address** | `0x00497920`–`0x0049799c` inclusive (**125 B** / `0x7D`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | Palantir env child / list-tracked ctx |
| **Status** | Dual A/B sealed W32-P 2026-07-29 — **accept-with-gaps** |

## Purpose

Complete MSVC constructor for the **0xC8**-byte list-tracked context. Sole factory: `PalantirEnv_Ctor_Inferred` does `operator_new(0xC8)` + `ListTrackedCtx_Ctor(parent)` → store at env`+0x100`. Publishes process global `DAT_00b035cc`. Parent at `+0xC4` feeds host path used by W31-D scaled clear (`0x00497a30`).

## Signature

```c
uint8_t* __thiscall ListTrackedCtx_Ctor_Inferred(uint8_t* self, void* parent);
```

## Layout (sealed)

| Off | Value |
|---|---|
| +0 | byte 1 (gate/flag) |
| +4, +8, +0x10, +0xB4 | 0 |
| +0xC | 5 (capacity) |
| +0x14 .. +0xB3 | zero (0xA0 via `FUN_00788db0`) |
| +0xB8 .. +0xC3 | zero triple (`FUN_00787520`) |
| +0xC4 | parent |

## Related

| VA / name | Relation |
|-----------|----------|
| `0x00492dd0` PalantirEnv_Ctor_Inferred | Sole caller (W31-P) |
| `0x00497a30` Ctx_ClearListTrackedOwnedAtScaledXY | Sibling worker on same ctx (W31-D) |
| `0x004be7d0` | Global reader of `DAT_00b035cc` |

## Artifacts

See `aa_00497920_FUN_00497920.md`.
