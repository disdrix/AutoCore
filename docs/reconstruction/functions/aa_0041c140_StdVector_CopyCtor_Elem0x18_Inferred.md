# Function record: StdVector_CopyCtor_Elem0x18_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0041c140` |
| **Canonical name** | `StdVector_CopyCtor_Elem0x18_Inferred` |
| **Ghidra symbol** | `FUN_0041c140` |
| **Address** | `0x0041c140`–`0x0041c1c9` inclusive (**138 B** / `0x8A`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities (partition inventory only) |
| **Completion status** | **Dual sealed (R13-022)** — accept-with-gaps; Terminal **false** |
| **Bit-for-bit / runtime / diff** | Open — **never Runtime Confirmed** this dual |
| **Dual A/B** | A **accept-with-gaps** / B **accept-with-gaps** |
| **Parent dual** | `0x0041ba30` StdTree_InsertAndRebalance_CharKey_Isnil21_Inferred |
| **Dual start** | 2686 |
| **Partition** | R13-022 |

## Purpose

MSVC-style **`std::vector` copy constructor** for elements of size **0x18**:

1. `count = (src.begin == 0) ? 0 : (src.end - src.begin) / 0x18`
2. `FUN_0041c250(dest, count)` — zero begin/end/cap; allocate `count*0x18` or return 0 if empty
3. If bought: `dest.end = FUN_00422580(src.begin, src.end, dest.begin, …)` (POD 6-dword Ucopy)
4. Return `dest` (EAX = ECX)

Primary sealed caller: char-key tree **buynode** `FUN_0041d860` constructs value vector at **node+0x10** after char key @ **+0x0C**.

## Signature

```c
// __thiscall; ret 0x4 (C2 04 00); EAX = dest
struct VecShell_Elem0x18 {
  uint32_t unused0;     // +0x0
  void* begin;          // +0x4
  void* end;            // +0x8
  void* capacity_end;   // +0xC
};

VecShell_Elem0x18 * __thiscall StdVector_CopyCtor_Elem0x18_Inferred(
    VecShell_Elem0x18 * dest /*ECX*/,
    const VecShell_Elem0x18 * src /*stack*/);
```

## Artifacts

| Kind | Path |
|---|---|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0041c140_FUN_0041c140.md` |
| Annotated | `docs/reconstruction/raw/aa_0041c140_FUN_0041c140.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/StdVector_CopyCtor_Elem0x18_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0041c140.cpp` |
| Scaffold function | `docs/reconstruction/functions/aa_0041c140_FUN_0041c140.md` |
| Review A | `docs/reconstruction/reviews/A_aa_0041c140_StdVector_CopyCtor_Elem0x18_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0041c140_StdVector_CopyCtor_Elem0x18_Inferred.md` |
| Report | `docs/agents/task-dual-ab-0041c140-r13-report.md` |

## Call graph (OWN unit only)

```text
FUN_0041d860  char-key buynode node0x24  [undualed]
  └─ StdVector_CopyCtor_Elem0x18_Inferred (0x0041c140)  [OWN R13-022]
       ├─ FUN_0041c250  buy/zero+alloc elem0x18  [undualed]
       └─ FUN_00422580  POD Ucopy 6-dword / 0x18  [undualed]

FUN_0059a940 / FUN_007eaf20  value/pair construct sites  [undualed]
  └─ same (2 + 4 call sites)

Parent always-insert (dualed R12-011):
  StdTree_InsertAndRebalance_CharKey_Isnil21_Inferred (0x0041ba30)
    └─ FUN_0041d860 → this unit
```

## Confidence

| Claim | Level |
|---|---|
| Body bounds + `RET 4` + thiscall | **High** |
| Stride 0x18 + copy-ctor CF | **High** |
| Layout begin/end/cap @ +4/+8/+0xC | **High** |
| Map-value placement node+0x10 | **High** |
| Element product English | **Open** (`_Inferred`) |
| Runtime / differential | **Open** (not Confirmed) |

## Retired names

- `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_0041c140` — chain-of-caller scaffold only; not a product role.
- Bare `FUN_0041c140` retained as Ghidra twin only.
