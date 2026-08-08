# Function record: StdList_Incsize_Max1fffffff

| Field | Value |
|---|---|
| **Stable ID** | `aa_00416010` |
| **Canonical name** | `StdList_Incsize_Max1fffffff` (**Inferred**) |
| **Ghidra name** | `FUN_00416010` |
| **Address** | `0x00416010`–`0x0041607e` |
| **Body size** | **111 B** / `0x6F` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | shared MSVC `std::list` |
| **Completion status** | **Dual sealed** (WQ9I-E 2026-08-04) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred; no Launcher) |
| **Partition** | `WAVE_2026-08-04_wq009_depth6_partition_map.md` → **WQ9I-E** |

## Alias

- Ghidra: `FUN_00416010`
- Prior scaffold: partial auto raw/annotated/clean
- Related twins (not owned here):
  - `StdList_Incsize` @ `0x0043fe60` — same ABI/string; max **`0x3fffffff`**
  - `FUN_00403600` — `__thiscall`; max **`0x6666666`**

## Purpose

MSVC-shaped **`std::list::_Incsize`**: if `_Mysize + count` would exceed max **`0x1fffffff`**, throw with `"list<T> too long"`; else `_Mysize += count` at `list+8`.

## Signature

```c
void __fastcall StdList_Incsize_Max1fffffff(uint32_t count /*ECX*/, StdListHeader *list /*EDX*/);
// plain RET — no stack args
```

## Callers / callees

**Callees:** `basic_string` ctor (`"list<T> too long"` @ `0x00a1581c`), `FUN_00401a40`, `_CxxThrowException` (`DAT_00acc388`).

**Callers (3 / 4 sites):**

| Parent | Site(s) | Notes |
|--------|---------|-------|
| `FUN_00415dd0` | `0x00415deb` | `ECX=1`, list in EDX; after `FUN_00415ed0` (node `0x10`) |
| `FUN_00834700` | `0x00834728` | `ECX=1`, `EDX=EBX` |
| `FUN_008dfc60` | `0x008dfd85`, `0x008dfdc2` | two inserts; UI tree-branch path |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00416010_FUN_00416010.md` (+ WQ9I-E live seal)
- Annotated: `docs/reconstruction/raw/aa_00416010_FUN_00416010.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdList_Incsize_Max1fffffff.cpp`
- Alias clean: `docs/reconstruction/reconstructed-exact/FUN_00416010.cpp`
- Reviews: `reviews/A_aa_00416010_StdList_Incsize_Max1fffffff.md`, `reviews/B_aa_00416010_StdList_Incsize_Max1fffffff.md`
- Scaffold record: `docs/reconstruction/functions/aa_00416010_FUN_00416010.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler ≡ raw ≡ bytes | **High** |
| ECX=count, EDX=list*, `+8` size | **High** |
| Max constant `0x1fffffff` | **High** (imm in body) |
| String `"list<T> too long"` | **High** |
| Role = MSVC `_Incsize` | **High** |
| Distinct from max-`0x3fffffff` twin | **High** |
| Product exception type English | **Open** |
| Runtime / bit-exact | **Open** |
