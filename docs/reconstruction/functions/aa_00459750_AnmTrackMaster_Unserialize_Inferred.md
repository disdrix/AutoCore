# Function record: AnmTrackMaster_Unserialize_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00459750` |
| **Canonical name** | `AnmTrackMaster_Unserialize_Inferred` |
| **Ghidra name** | `FUN_00459750` |
| **Address** | `0x00459750`–`0x00459a5a` (**779 B** / `0x30B`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | palantir/animation — `anmTrackMaster_inl` chunk unserialize |
| **Wave** | W36-M OWN-ONLY dual 2026-07-29 |
| **Verdict** | **accept-with-gaps** |
| **Dual A/B** | `reviews/A_aa_00459750_AnmTrackMaster_Unserialize_Inferred.md`, `reviews/B_aa_00459750_AnmTrackMaster_Unserialize_Inferred.md` |

## Purpose

Unserialize a **PBAM** / **TRAK** animation track-master chunk into `this`. Dual I/O via `ctx+0x4044`. Writes type fourCC (**EFCT**/**SKEL**), string hashes, ints; resizes the **Pod28** vector at **`this+0x1C`** via sealed `StdVector_Resize_Pod28`; optional element fill via `FUN_0045dd60`.

## Signature

```c
// ECX=this, stack ctx*; RET 4
// returns 0 success, 0xFFFFFFFE mid-error, 0xFFFFFFFF fail
uint32_t __thiscall AnmTrackMaster_Unserialize_Inferred(void* self, void* ctx);
```

## Layout (sealed offsets)

| Off | Field |
|---|---|
| `this+0x10` | type fourCC (`EFCT` `0x45464354` or `SKEL` `0x534B454C`) |
| `this+0x14` | string hash 1 (`FUN_00989e00`) |
| `this+0x18` | string hash 2 (version &gt; 0) |
| `this+0x1C` | `StdVectorPod28` base (triad +4/+8/+C → begin/end/capEnd) |
| `this+0x2C` | int field (dual int-read) |
| `ctx+0x4044` | dual I/O flag (0 → `FUN_004*` path; else `FUN_007*`) |

## Related duals

| Unit | VA | Relation |
|---|---|---|
| `StdVector_Resize_Pod28` | `0x0045c4b0` | sealed resize callee (W35-M) |
| `FUN_0045dd60` | `0x0045dd60` | element load (unowned) |
| `stoChunkReader_EnterChunkScope` | (symbol) | chunk enter |
| DATA slot | `0x00aa3d54` | sole xref (fn-ptr / vtable) |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00459750_FUN_00459750.md` |
| Annotated | `docs/reconstruction/raw/aa_00459750_FUN_00459750.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AnmTrackMaster_Unserialize_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00459750.cpp` |
| Function FUN | `docs/reconstruction/functions/aa_00459750_FUN_00459750.md` |
| Dual report | `docs/agents/task-dual-ab-00459750-0046a260-w36m-report.md` |

## Confidence

| Claim | Level |
|---|---|
| thiscall + RET 4 + return codes | **High** |
| PBAM/TRAK gate + path string | **High** |
| Pod28 resize at this+0x1C | **High** |
| EFCT/SKEL type select | **High** |
| Full object map / product demangle | **Open** |
| Nested duals (I/O, hash, element load) | **Open** (unowned) |
| Runtime / bit-exact | **Open** |
