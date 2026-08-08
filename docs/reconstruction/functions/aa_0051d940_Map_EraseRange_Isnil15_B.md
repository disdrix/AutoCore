# Function record: Map_EraseRange_Isnil15_B

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051d940` |
| **Canonical name** | `Map_EraseRange_Isnil15_B` |
| **Ghidra name** | `FUN_0051d940` |
| **Address** | `0x0051d940`–`0x0051d9f3` inclusive (**180 bytes**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | STL / map-set (WQ-009 depth-3 residual; isnil@+0x15) |
| **Completion status** | **accept-with-gaps** — dual A/B sealed 2026-08-04 (WQ9F-J OWN) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Twin of dualed `Map_EraseRange_Isnil15` (`0x0051d7c0`): MSVC red-black **range erase** `[first, last)` for the **small-node** family (`isnil@+0x15`). Full clear frees via **`FUN_0051bed0`**; partial erase loops through **`FUN_0051ce00`** (shared with twin; STL `"invalid map/set<T> iterator"`). Writes end iterator to `*out_it`.

Distinct from isnil@+0x29 `Map_EraseRange` / `Map_EraseRange_B` and from `StdMap_EraseRange_Inferred` @ `0x004bacf0`.

## Signature (byte-sealed)

```c
void __thiscall Map_EraseRange_Isnil15_B(
    void *map,        // ECX — head @ +4, size @ +8
    void **out_it,    // stack0
    void *first,      // stack1 inclusive
    void *last);      // stack2 exclusive
// RET 0x0C
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0051d940_FUN_0051d940.md`
- Annotated: `docs/reconstruction/raw/aa_0051d940_FUN_0051d940.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/Map_EraseRange_Isnil15_B.cpp`
- Clean FUN_*: `docs/reconstruction/reconstructed-exact/FUN_0051d940.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0051d940_Map_EraseRange_Isnil15_B.md`
- Review B: `docs/reconstruction/reviews/B_aa_0051d940_Map_EraseRange_Isnil15_B.md`
- Alias record: `docs/reconstruction/functions/aa_0051d940_FUN_0051d940.md`

## Callers / callees

| Direction | Target | Notes |
|---|---|---|
| Caller | `FUN_0051e1b0` | map host complete dtor @ `0x0051e1c2` only |
| Callee | `FUN_0051bed0` | full-tree free (isnil@+0x15) — discriminator vs twin |
| Callee | `FUN_0051ce00` | single-node erase (shared with twin) |
| Twin | `Map_EraseRange_Isnil15` @ `0x0051d7c0` | free `FUN_0051be50` |

## Confidence

| Claim | Level |
|---|---|
| STL range-erase role | **Confirmed** |
| ABI thiscall + ret 0x0c + isnil@+0x15 | **Confirmed** |
| Twin free discriminator | **Confirmed** |
| Product/PDB English / K/V | Open (structural name) |
| Runtime / image diff | Open |
