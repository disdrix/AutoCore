# Function record: FUN_004bcae0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bcae0` |
| **Canonical name** | `CNDHash_ReclaimToFreelist_009cb450` (preferred) / `FUN_004bcae0` |
| **Address** | `0x004bcae0`–`0x004bcb3e` inclusive (**95 B** / `0x5F`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | container / CNDHash (family `009cb450` / tableC) |
| **Completion status** | Dual A/B sealed W37-G 2026-08-04 — **accept** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- **Accept:** `CNDHash_ReclaimToFreelist_009cb450`
- **Reject:** scaffold `Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004bcae0`
- **Do not** substitute twin `FUN_004e2bd0` (family `009cb45c`, W37-J)

## Purpose

Owning reclaim for `CNDHash_FreeBuckets_009cb450`: walk all bucket chains, stamp nodes `009cb358`, virtual-delete values at `node+0x08`, push nodes to freelist `hash+0x20`, clear heads. Does **not** free freelist storage or the bucket table (parent FreeBuckets does).

## Signature

```c
// ECX=hash*  bare RET  void
void CNDHash_ReclaimToFreelist_009cb450(void *hash /*ECX*/);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004bcae0_FUN_004bcae0.md`
- Annotated: `docs/reconstruction/raw/aa_004bcae0_FUN_004bcae0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CNDHash_ReclaimToFreelist_009cb450.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_004bcae0.cpp`
- Function named: `docs/reconstruction/functions/aa_004bcae0_CNDHash_ReclaimToFreelist_009cb450.md`
- A: `docs/reconstruction/reviews/A_aa_004bcae0_CNDHash_ReclaimToFreelist_009cb450.md`
- B: `docs/reconstruction/reviews/B_aa_004bcae0_CNDHash_ReclaimToFreelist_009cb450.md`
- Report: `docs/agents/task-dual-ab-004c1800-004bcae0-w37g-report.md`

## Callers / callees

| Role | Detail |
|---|---|
| Caller (1) | `FUN_004bcc60` / `CNDHash_FreeBuckets_009cb450` @ `0x004bcc6a` |
| Callees | none static (virtual value dtor only) |

## Confidence

| Claim | Level |
|---|---|
| Body 95 B / bare RET / ECX this | **High** |
| Loop `0…mask` incl. / freelist `+0x20` | **High** |
| Value @ `+0x08` / next @ `+0x0C` / stamp `009cb358` | **High** |
| Twin slot/stamp split vs `004e2bd0` | **High** |
| Product value-type English | **Open** |
