# Function record: GfxBufferedViewList_ClearField184_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00968680` |
| **Canonical name** | `GfxBufferedViewList_ClearField184_Inferred` (**Inferred** structural) |
| **Ghidra name** | `FUN_00968680` |
| **Address** | `0x00968680` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | graphics / gfxBufferedView global list (Device Reset success) |
| **Completion status** | **Dual sealed (A+B)** — W38-Z 2026-08-04 |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Scaffold seed: `Named_CalleeOf_Named_gfxDevice_00968680` (**reject** as product).
- Ghidra: `FUN_00968680`.

## Purpose

Walk the global **gfxBufferedView** circular list headed at **`DAT_00d1ee30`** and set each non-null payload's dword at **`+0x184` to 0**. Invoked once on the **success arm** of Device Reset after all factory resets complete (before GetDeviceCaps / backbuffer rebind).

Ctor (W37-I `GfxBufferedView_Ctor_Inferred` / `FUN_00968a50`) registers every instance into this list and initializes **`+0x180/+0x184 = 1`**.

## Signature (machine-sealed)

```c
void GfxBufferedViewList_ClearField184_Inferred(void);
// no stack formals; plain RET (c3)
// body 0x00968680–0x009686a7 inclusive (40 B / 0x28)
```

## Node layout (sealed)

| Offset | Role |
|---|---|
| `node+0` | next |
| `node+4` | prev (unused here) |
| `node+8` | payload* (`gfxBufferedView*`) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00968680_FUN_00968680.md`
- Annotated: `docs/reconstruction/raw/aa_00968680_FUN_00968680.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/GfxBufferedViewList_ClearField184_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00968680.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00968680_GfxBufferedViewList_ClearField184_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00968680_GfxBufferedViewList_ClearField184_Inferred.md`
- Report: `docs/agents/task-dual-ab-00966760-00968680-w38z-report.md`

## Callers / callees

| Direction | VA | Name / role |
|---|---|---|
| Caller (1) | `FUN_0075eff0` @ `0x0075f362` | Device Reset success arm (`gfxDevice.cpp`) |
| Global | `DAT_00d1ee30` | circular list sentinel |
| Related | `FUN_00968a50` | `GfxBufferedView_Ctor_Inferred` (W37-I) — register + init `+0x184=1` |
| Sibling (not OWN) | `FUN_009686e0` | pre-Reset list walk with different gate |

## Confidence

| Claim | Level |
|---|---|
| Control flow ≡ live bytes | **Confirmed** |
| Zero `payload+0x184` | **Confirmed** |
| List domain = gfxBufferedView | **High** (ctor W37-I + same sentinel) |
| Field `+0x184` product English | **Open** |
| Runtime / bit-exact | **Open** |
