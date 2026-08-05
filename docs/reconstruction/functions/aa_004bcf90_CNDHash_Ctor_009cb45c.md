# Function record: CNDHash_Ctor_009cb45c

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bcf90` |
| **Canonical name** | `CNDHash_Ctor_009cb45c` |
| **Ghidra name** | `FUN_004bcf90` |
| **Address** | `0x004bcf90`–`0x004bd001` (**114 B / `0x72`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | container / CNDHash (COList nested hashA/hashB) |
| **Completion status** | **Dual A/B sealed (W28-J)** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

Ghidra `FUN_004bcf90`. Stamp-qualified CNDHash constructor for object vtbl `PTR_FUN_009cb45c`. Prior scaffold alias `Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance_004bcf90` superseded.

## Purpose

Construct a **0x34**-byte CNDHash host for COList optional tables (+0x04 / +0x08): install vtbl `009cb45c`, zero fields, set provisional bucket count `N = 1<<log2` at +0x08 and log2 at +0x1C, then hand off to `FUN_004bc840` (AllocBucketTable twin) which builds the bucket array and converts +0x08 to mask `N-1`. Returns `this`.

## Signature (sealed)

```c
void *__thiscall CNDHash_Ctor_009cb45c(void *thisHash, uint8_t log2);
// ECX=this; stack log2 (4-byte slot); ret 4; EAX=this
```

## Layout (ctor-written)

| Off | Field |
|---|---|
| +0x00 | vtbl `009cb45c` |
| +0x04 | 0 |
| +0x08 | N then mask (post-Alloc) |
| +0x0C | 0 |
| +0x10 | buckets* (post-Alloc) |
| +0x14 | 0 |
| +0x18 | 0 |
| +0x1C | log2 (byte) |
| +0x1D | lock (0) |
| +0x20 | freelist (0) |
| +0x24 | **not written** |
| +0x28..+0x30 | 0 |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004bcf90_FUN_004bcf90.md`
- Annotated: `docs/reconstruction/raw/aa_004bcf90_FUN_004bcf90.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/CNDHash_Ctor_009cb45c.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_004bcf90.cpp`
- Function scaffold: `docs/reconstruction/functions/aa_004bcf90_FUN_004bcf90.md`
- Review A: `docs/reconstruction/reviews/A_aa_004bcf90_CNDHash_Ctor_009cb45c.md`
- Review B: `docs/reconstruction/reviews/B_aa_004bcf90_CNDHash_Ctor_009cb45c.md`

## Callers / callees

| Direction | Detail |
|---|---|
| **Callers** | `FUN_004bbfb0` COList_Constructor only (`0x004bc042`, `0x004bc07b`) |
| **Callees** | `FUN_004bc840` (AllocBucketTable for this stamp) |
| **Twin** | `CNDHash_Ctor_009cb450` `0x004bce90` |

## Confidence

| Claim | Level |
|---|---|
| ABI / CF / field init / vtbl imm / ret 4 | **High** |
| CNDHash family (layout + HashError siblings + parallel ctor stamps) | **High** |
| Product / PDB English class name | **Inferred** (stamp-qualified) |
| Runtime / bit-exact | **Open** |
