# Function record: GfxBufferedView_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00968a50` |
| **Canonical name** | `GfxBufferedView_Ctor_Inferred` |
| **Address** | `0x00968a50`–`0x00968b14` (**197 B** / `0xC5`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | palantir/graphics — `gfxBufferedView.cpp` |
| **Completion status** | **Dual A/B present** — W37-I |
| **Bit-for-bit / runtime / diff** | Open |
| **Verdict** | **accept-with-gaps** |

## Alias

| Name | Notes |
|---|---|
| `FUN_00968a50` | Ghidra |
| `GfxBufferedView_Ctor_Inferred` | Canonical (Inferred method English; class product-sealed) |

## Purpose

Construct a **gfxBufferedView** on a pre-allocated **0x198** block: GfxView base (`0x150`), derived vtbl `PTR_FUN_00aa22a8`, timer subobject at `+0x150` (period 1000 + start), zero derived tail, push onto global list `*DAT_00d1ee30`, return this.

## Signature (sealed)

```c
GfxBufferedView * __fastcall GfxBufferedView_Ctor_Inferred(GfxBufferedView *self);
```

## Layout (ctor-visible)

| Off | Value | Role |
|---:|---|---|
| `+0x00` | `PTR_FUN_00aa22a8` | derived vtbl |
| `+0x00`…`+0x14F` | GfxView | base ctor `FUN_0075ceb0` |
| `+0x150` | timer | `FUN_0076c500` / `FUN_0076c4d0` |
| `+0x180` | `1` | dword |
| `+0x184` | `1` | dword |
| `+0x188` | `0.0f` | float |
| `+0x18c` | `0.0f` | float |
| `+0x190` | `0` | byte |
| `+0x191` | `0` | byte |
| `+0x194` | `0` | dword |
| size | **`0x198`** | |

## Artifacts

- Raw / annotated / clean / dual A/B — see `aa_00968a50_FUN_00968a50.md`
- Agent report: `docs/agents/task-dual-ab-00968a50-0099c1c0-w37i-report.md`

## Related

- Base: `GfxView_Ctor_Inferred` (`0x0075ceb0`, W31-O)
- Sibling method: `FUN_00968720` (ReCreate / gfxBufferedView plates)
- Scalar dtor-path vtbl set: `FUN_009686b0`
- List helper: `StdList_Incsize` (`0x0043fe60`, W23-E)
