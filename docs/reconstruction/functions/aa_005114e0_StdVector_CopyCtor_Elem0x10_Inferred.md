# Function record: StdVector_CopyCtor_Elem0x10_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005114e0` |
| **Canonical name** | `StdVector_CopyCtor_Elem0x10_Inferred` |
| **Ghidra name** | `FUN_005114e0` |
| **Address** | `0x005114e0`–`0x00511583` inclusive (164 B / `0xA4`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities (partition R13-029; parent dual `0x00511950` Node24 insert) |
| **Dual status** | **Present** — A/B accept-with-gaps (2026-08-05; dual start **2686**) |
| **Terminal** | **false** |
| **Bit-for-bit / runtime / diff** | Open — **never Runtime Confirmed** |

## Purpose

Port-facing name for MSVC `std::vector<T>` **copy constructor** where `sizeof(T) == 0x10`. Constructs dest triad from source range via POD uninitialized copy. Embeds as Node24 value payload vector at `node+0x10` (after int key `@+0x0C`).

## Signature

```c
// thiscall; RET 4; returns this
StdVector_Elem0x10* __thiscall StdVector_CopyCtor_Elem0x10_Inferred(
    StdVector_Elem0x10* this,           // ECX; +4 begin, +8 end, +0xC capEnd
    const StdVector_Elem0x10* src);     // stack
```

## Contract (port notes)

1. `n = (src.end - src.begin) >> 4` (0 if begin null).
2. Zero dest begin/end/capEnd.
3. Empty → return this.
4. `n > 0x0FFFFFFF` → throw length_error (`FUN_004540b0` noreturn).
5. `new(n * 0x10)`; plant triad; `FUN_005dd920` range-copy; set end.
6. **Not** copy-assign (no free of prior buffer). **Not** InsertN/PushBack.

## Disambiguation

| Do not merge with | Why |
|---|---|
| `StdVector_InsertN_Elem0x10_Inferred` (`00408640`) | insert-N + growth; different ABI |
| `StdVector_PodCopyElement_0x10_Inferred` (`00409f70`) | single-element leaf |
| `StdTree_InsertAndRebalance_Node24_Isnil21_Inferred` (`00511950`) | tree insert parent |
| `FUN_005118b0` buynode | caller that embeds this vector |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005114e0_FUN_005114e0.md` |
| Annotated | `docs/reconstruction/raw/aa_005114e0_FUN_005114e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_CopyCtor_Elem0x10_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_005114e0.cpp` |
| Ghidra record | `docs/reconstruction/functions/aa_005114e0_FUN_005114e0.md` |
| Dual A | `docs/reconstruction/reviews/A_aa_005114e0_StdVector_CopyCtor_Elem0x10_Inferred.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_005114e0_StdVector_CopyCtor_Elem0x10_Inferred.md` |
| Report | `docs/agents/task-dual-ab-005114e0-r13-report.md` |

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / stride / role | **High** |
| Node24 payload linkage | **High** (buynode site + parent dual) |
| Product `T` English | **Open** — keep `_Inferred` |
| Runtime Confirmed | **Not claimed** |
