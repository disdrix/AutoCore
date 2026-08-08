# Function record: PodCopyBlock_0x40_Thiscall_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005eb040` |
| **Canonical name** | `PodCopyBlock_0x40_Thiscall_Inferred` |
| **Ghidra name** | `FUN_005eb040` |
| **Address** | `0x005eb040`–`0x005eb0a6` (103 B / `0x67`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | interaction-activation |
| **Partition parent** | `0x005eb210` `VOGPhysics_QueryObject_BaseCtor_Inferred` |
| **Completion status** | **Dual sealed (R12-036)** — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Signature

```c
uint32_t * __thiscall PodCopyBlock_0x40_Thiscall_Inferred(
    uint32_t *dest /* ECX */,
    const uint32_t *src /* stack */);
// RET 4; EAX = dest
// Fixed size: 16 dwords / 0x40 bytes
```

## Semantics (sealed)

```text
PodCopyBlock_0x40(dest, src):
  // leaf; no null check
  for i in 0..15:
    dest[i] = src[i]
  return dest
```

## Naming rationale

- Role: **POD block copy** of fixed **0x40** (16 dwords), not a typed ctor or vector element leaf.
- ABI tag: **Thiscall** (ECX=dest, stack=src, `RET 4`) distinguishes from EAX/ECX register PodCopy family.
- `_Inferred`: product English for the blob type open (used as generic 0x40 utility across callers).
- Scaffold `Named_CalleeOf_*VOG_DEBUG_STOP*005eb040` **retired**.

## Callers / callees

| Kind | Value |
|---|---|
| Callees | none (leaf) |
| Xrefs | 29 UNCONDITIONAL_CALL |
| Named callers | `FUN_005eb0b0`, `FUN_005eb0e0`, `FUN_005eb210`, `FUN_005f0210`, `FUN_005f1ec0`, `FUN_0063aa40`, `FUN_0065ebe0`, `FUN_00661110`, `FUN_00662510`, `FUN_00668d30`, `FUN_00668ea0`, `FUN_006ef0d0`, `FUN_006ef400` |
| Parent dual use | `FUN_005eb210`: `dest=self+0x80`, `src=params+0x20` |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005eb040_FUN_005eb040.md` |
| Annotated | `docs/reconstruction/raw/aa_005eb040_FUN_005eb040.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/PodCopyBlock_0x40_Thiscall_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005eb040.cpp` |
| FUN record | `docs/reconstruction/functions/aa_005eb040_FUN_005eb040.md` |
| Dual A | `docs/reconstruction/reviews/A_aa_005eb040_PodCopyBlock_0x40_Thiscall_Inferred.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_005eb040_PodCopyBlock_0x40_Thiscall_Inferred.md` |
| Report | `docs/agents/task-dual-ab-005eb040-r12-report.md` |

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / RET 4 / 16-dword size | **High** |
| Leaf shared utility | **High** |
| EAX = dest return | **High** |
| Product blob English | **Open** |
| Runtime | **Open** |
