# Function record: CNDUIDialog_TeardownChildHash_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007917c0` |
| **Canonical name** | `CNDUIDialog_TeardownChildHash_Inferred` |
| **Ghidra name** | `FUN_007917c0` |
| **Address** | `0x007917c0`–`0x007918e1` inclusive (**290 B** / `0x122`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | CNDUIDialog complete-dtor leaf / child hash teardown |
| **Completion status** | **Dual-reviewed** WQ9L-I — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Partition** | `WAVE_2026-08-05_wq009_depth9_partition_map.md` → **WQ9L-I** |

## Purpose

CNDUIDialog child-hash teardown leaf: if `this+0x4c0` non-null, clear selection, release helper `+0x4b8`, walk hash under traversal lock, tear down each child, erase from dialog vector, unlock, clear list shell `+0x4dc`, recreate empty hash (BL=5), set flag `+0x4c4=1`. Does **not** free hash* or `this` — parent complete dtor scalar-deletes `+0x4c0` after return.

## Signature

```c
// ECX = this; bare RET; void
void __fastcall CNDUIDialog_TeardownChildHash_Inferred(void *self);
```

## Offsets / constants

| Offset | Role | Conf |
|---|---|---|
| `self+0x4b8` | optional helper; vtbl `+0x318` then zero | **High** |
| `self+0x4c0` | child hash object* | **High** |
| `self+0x4c4` | teardown-done flag ← 1 | **High** |
| `self+0x4dc` | list shell (ESI into `FUN_004133c0`) | **High** |
| hash `+0x1d` | traversal lock | **High** |
| hash `+0x14` | chain head / next | **High** |
| node `+8` | value* (child) | **High** |
| child `+0x2b0` | cleared before remove | **High** |

## Callers / callees

| Direction | Targets |
|---|---|
| Sole CALL | `FUN_00792c20` (`CNDUIDialog_CompleteDtor`) @ `0x00792c4d` |
| DATA | 100+ dialog vtbl slots |
| Callees | `FUN_007a4480`, `FUN_00756be0`, `FUN_004133c0`, `FUN_004281d0`, vtbls |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_007917c0_FUN_007917c0.md`
- Annotated: `docs/reconstruction/raw/aa_007917c0_FUN_007917c0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CNDUIDialog_TeardownChildHash_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_007917c0.cpp`
- Scaffold (retired): `docs/reconstruction/reconstructed-exact/Named_VOG_DEBUG_STOP_007917c0.cpp`
- Review A: `reviews/A_aa_007917c0_CNDUIDialog_TeardownChildHash_Inferred.md`
- Review B: `reviews/B_aa_007917c0_CNDUIDialog_TeardownChildHash_Inferred.md`
- FUN record: `functions/aa_007917c0_FUN_007917c0.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow (bytes / disasm) | **High** |
| ABI ECX=this bare RET | **High** |
| Hash lock / walk / Recreate not free | **High** |
| Sole CALL from complete dtor | **High** |
| Product demangle | **Open** (`_Inferred`) |
| Runtime | **Open** |
