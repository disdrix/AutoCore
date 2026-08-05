# Function record: CNDHash_Ctor_009cb450

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bce90` |
| **Canonical name** | `CNDHash_Ctor_009cb450` |
| **Ghidra name** | `FUN_004bce90` |
| **Address** | `0x004bce90`–`0x004bcf01` (**114 B / `0x72`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | container / CNDHash (COList nested tableC) |
| **Completion status** | **Dual A/B sealed (W28-J)** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

Ghidra `FUN_004bce90`. Stamp-qualified CNDHash constructor for object vtbl `PTR_FUN_009cb450`. Prior scaffold alias `Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance_004bce90` superseded.

## Purpose

Construct a **0x34**-byte CNDHash host for COList fixed third table (+0x18): install vtbl `009cb450`, zero fields, set provisional bucket count `N = 1<<log2` at +0x08 and log2 at +0x1C, then hand off to `FUN_004bc7a0` (AllocBucketTable twin) which builds the bucket array and converts +0x08 to mask `N-1`. Production always passes **log2 = 5** (`N = 32` → mask `31`). Returns `this`.

## Signature (sealed)

```c
void *__thiscall CNDHash_Ctor_009cb450(void *thisHash, uint8_t log2);
// ECX=this; stack log2 (4-byte slot); ret 4; EAX=this
```

## Layout (ctor-written)

Identical offsets to `CNDHash_Ctor_009cb45c`; only vtbl stamp and Alloc callee differ.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004bce90_FUN_004bce90.md`
- Annotated: `docs/reconstruction/raw/aa_004bce90_FUN_004bce90.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/CNDHash_Ctor_009cb450.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_004bce90.cpp`
- Function scaffold: `docs/reconstruction/functions/aa_004bce90_FUN_004bce90.md`
- Review A: `docs/reconstruction/reviews/A_aa_004bce90_CNDHash_Ctor_009cb450.md`
- Review B: `docs/reconstruction/reviews/B_aa_004bce90_CNDHash_Ctor_009cb450.md`

## Callers / callees

| Direction | Detail |
|---|---|
| **Callers** | `FUN_004bbfb0` COList_Constructor only (`0x004bc0b0`, fixed arg 5) |
| **Callees** | `FUN_004bc7a0` (AllocBucketTable for this stamp) |
| **Twin** | `CNDHash_Ctor_009cb45c` `0x004bcf90` |

## Confidence

| Claim | Level |
|---|---|
| ABI / CF / field init / vtbl imm / ret 4 | **High** |
| Distinct from `009cb45c` stamp (must not merge) | **High** |
| CNDHash family | **High** |
| Product / PDB English class name | **Inferred** (stamp-qualified) |
| Runtime / bit-exact | **Open** |
