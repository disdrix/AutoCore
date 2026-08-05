# Function record: LinkPair_CanonAndSort_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_006cad30` |
| **Canonical name** | `LinkPair_CanonAndSort_Inferred` |
| **Ghidra name** | `FUN_006cad30` |
| **Address** | `0x006cad30` |
| **Body range** | `0x006cad30`–`0x006cad7f` exclusive (**79** B / `0x4F`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | phys / bind link-pair list prep |
| **Completion status** | **partial** — dual A/B **accept**; CF + ABI + pair layout sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_006cad30_LinkPair_CanonAndSort_Inferred.md`, `reviews/B_aa_006cad30_LinkPair_CanonAndSort_Inferred.md` (2026-07-29 W28-Q) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_006cad30`
- `Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_006cad30` (legacy scaffold — **narrow**)

## Purpose

Canonicalize each 8-byte object pair so `a->key4 ≤ b->key4` (unsigned, key at object +4), then quicksort the array via `FUN_006cac60` on dual key `(a+4, b+4)`. Prep for sorted pair merge / bind-unbind commit.

## Signature

```c
void LinkPair_CanonAndSort_Inferred(LinkPair8* array, int count);  // __cdecl
```

## Algorithm

1. If count==0 return.
2. For each pair: if `b.key4 < a.key4` swap pointers.
3. Zero low byte of stack count (`count & 0xffffff00`); unused 4th arg.
4. If count>1: `FUN_006cac60(array, 0, count-1, unused)`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_006cad30_FUN_006cad30.md`
- Annotated: `docs/reconstruction/raw/aa_006cad30_FUN_006cad30.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/LinkPair_CanonAndSort_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_006cad30.cpp`
- Function FUN_*: `docs/reconstruction/functions/aa_006cad30_FUN_006cad30.md`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-0053a8e0-006cad30-w28q-report.md`
- Scratch: `docs/reconstruction/tmp/a_006cad30.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_006cac60` (pair quicksort) |
| **Callers** | `FUN_006297e0` ×2, `FUN_00634450` ×2, `FUN_0055ff20`, `FUN_00560020` (6 xrefs) |

## Confidence

| Claim | Level |
|---|---|
| Control flow + live ≡ raw | **High** |
| cdecl + plain ret | **High** |
| 8-byte pairs + key@+4 | **High** |
| Role: prep for LinkPair_SortedDiffWalk / commit | **High** (caller context W27-M/N) |
| Product object type | **Inferred** |
| Nested qsort dual | Open (not OWN) |
| Runtime / differential | Open |

## Related

- Qsort: `FUN_006cac60` (nested)
- Merge: `aa_006caaa0` LinkPair_SortedDiffWalk_Inferred (W27-N)
- Commit: `aa_006297e0` Phys_CommitPairListStorage_Inferred (W27-M)
