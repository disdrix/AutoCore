# Function record: MeshWeightDebugOverlay_Update

| Field | Value |
|---|---|
| **Stable ID** | `aa_00965ab0` |
| **Canonical name** | `MeshWeightDebugOverlay_Update` (**Inferred** domain) |
| **Ghidra name** | `FUN_00965ab0` |
| **Address** | `0x00965ab0`–`0x0096650A` exclusive (**2650 B** / `0xA5A`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | Client gfx mesh-weight debug overlay |
| **Completion status** | **Dual sealed** W36-N — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Tick/update mesh weight debug overlay owned by gfx device (`device+0x7A0`):

- Advance clamped fade progress with ±0.005f rates.
- When visible/dirty, rebuild RC-elem28 UI line list (resize + push_back) from mesh entries showing names, max weights/vertex, TM/RM modes.
- Draw/measure/layout text; clear dirty.

## Signature

```c
// stdcall; RET 4; body EDI=self
void MeshWeightDebugOverlay_Update(MeshWeightDebugOverlay* self);
```

## Related

| VA | Role |
|---|---|
| `0x0075fb90` | gfx BeginScene parent (unowned) |
| `0x004611e0` | `StdVector_Resize_RcElem28` (W35-Q) — clear/rebuild lines |
| `0x00461720` | erase-range under resize shrink (this dual) |
| `0x00460f90` | push_back RC line elems (unowned) |
| `0x00aaa6a4` | `g_flHardKillInterpolate` = 0.005f |
| `0x00aaa9f4` | fade-out rate = −0.005f |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00965ab0_FUN_00965ab0.md` |
| Annotated | `docs/reconstruction/raw/aa_00965ab0_FUN_00965ab0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/MeshWeightDebugOverlay_Update.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00965ab0.cpp` |
| A/B | `docs/reconstruction/reviews/A_aa_00965ab0_MeshWeightDebugOverlay_Update.md`, `B_…` |
| Dual report | `docs/agents/task-dual-ab-00461720-00965ab0-w36n-report.md` |
