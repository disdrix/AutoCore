# Function record: Map_EraseRange_Isnil15

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051d7c0` |
| **Canonical name** | `Map_EraseRange_Isnil15` |
| **Ghidra name** | `FUN_0051d7c0` |
| **Address** | `0x0051d7c0`–`0x0051d873` inclusive (**180 bytes**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | STL / map-set (WQ-009 depth-2 residual; isnil@+0x15) |
| **Completion status** | **accept-with-gaps** — dual A/B sealed 2026-08-04 (WQ9E-J OWN) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

MSVC red-black **range erase** `[first, last)` for the **small-node** family (`isnil@+0x15`). Full clear frees via `FUN_0051be50`; partial erase loops through `FUN_0051ce00` (STL single-erase with `"invalid map/set<T> iterator"`). Writes end iterator to `*out_it`.

Distinct from dualed `Map_EraseRange` / `Map_EraseRange_B` (`isnil@+0x29`) and from `StdMap_EraseRange_Inferred` @ `0x004bacf0` (same isnil offset; different free/erase callees).

## Signature (byte-sealed)

```c
void __thiscall Map_EraseRange_Isnil15(
    void *map,        // ECX — head @ +4, size @ +8
    void **out_it,    // stack0
    void *first,      // stack1 inclusive
    void *last);      // stack2 exclusive
// RET 0x0C
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0051d7c0_FUN_0051d7c0.md`
- Annotated: `docs/reconstruction/raw/aa_0051d7c0_FUN_0051d7c0.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/Map_EraseRange_Isnil15.cpp`
- Clean FUN_*: `docs/reconstruction/reconstructed-exact/FUN_0051d7c0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0051d7c0_Map_EraseRange_Isnil15.md`
- Review B: `docs/reconstruction/reviews/B_aa_0051d7c0_Map_EraseRange_Isnil15.md`
- Alias record: `docs/reconstruction/functions/aa_0051d7c0_FUN_0051d7c0.md`

## Callers / callees

| Direction | Target | Notes |
|---|---|---|
| Caller | `FUN_0051e150` | map tidy peer @ `0x0051e162` |
| Caller | `FUN_0052f260` | large host dtor @ `0x0052f533` (map @ `this-300`) |
| Callee | `FUN_0051be50` | full-tree free (isnil@+0x15) |
| Callee | `FUN_0051ce00` | single-node erase (STL throw string) |

## Confidence

| Claim | Level |
|---|---|
| STL range-erase role | **Confirmed** |
| ABI thiscall + ret 0x0c + isnil@+0x15 | **Confirmed** |
| Distinct from Map_EraseRange (+0x29) | **Confirmed** |
| Product/PDB English / K/V | Open (`Map_EraseRange_Isnil15` structural) |
| Runtime / image diff | Open |
