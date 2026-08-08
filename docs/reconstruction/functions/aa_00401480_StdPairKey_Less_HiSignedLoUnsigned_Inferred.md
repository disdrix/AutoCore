# Function record: StdPairKey_Less_HiSignedLoUnsigned_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00401480` |
| **Canonical name** | `StdPairKey_Less_HiSignedLoUnsigned_Inferred` |
| **Ghidra symbol** | `FUN_00401480` |
| **Address** | `0x00401480` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body** | `0x00401480`–`0x004014a5` exclusive (37 B / `0x25`) |
| **System** | std 2-dword pair-key less-than (insert-hint) |
| **Wave** | WQ9G-B OWN-ONLY dual 2026-08-04 |
| **Completion status** | **accept-with-gaps** (dual A/B) |
| **Bit-for-bit / runtime / diff** | Open |
| **Terminal** | false |

## Naming rationale

Structural name from sealed algebra (pair key less-than; hi signed primary; lo unsigned secondary). Used as insert-hint comparator by dualed `StdTree_InsertHint_Isnil29_Inferred`. No product/PDB plate → `_Inferred`. Scaffold VOG_DEBUG Named_CalleeOf **rejected**.

## Purpose

```
less(a,b) = (a.hi <s b.hi) || (a.hi == b.hi && a.lo <u b.lo)
```

Returns 1 if true else 0. Two stack args; RET 8.

## Signature

```c
uint32_t __stdcall StdPairKey_Less_HiSignedLoUnsigned_Inferred(
    const uint32_t* a, const uint32_t* b);
```

## Related dualed units

| VA | Name | Relation |
|---|---|---|
| `0x004cc220` | `StdTree_InsertHint_Isnil29_Inferred` | primary caller (5 sites) |
| `0x004cbee0` | `StdMap_InsertOrFind_PairKey_Isnil29_Inferred` | same compare order (inlined) |
| `0x004cb4f0` | `StdTree_Predecessor_Isnil29_Inferred` | sibling residual sealed same wave |

## Artifacts

- Raw / annotated / clean / dual A/B / FUN record: see `aa_00401480_FUN_00401480.md`
- Report: `docs/agents/task-dual-ab-004cb4f0-00401480-wq9gb-report.md`

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / signedness order | **High** |
| Name structural | **Inferred** |
| Runtime | Open |
