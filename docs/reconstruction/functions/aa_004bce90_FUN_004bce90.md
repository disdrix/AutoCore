# Function record: FUN_004bce90

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bce90` |
| **Canonical name** | `FUN_004bce90` (prefer **`CNDHash_Ctor_009cb450`**) |
| **Address** | `0x004bce90`–`0x004bcf01` (**114 B / `0x72`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | container / CNDHash |
| **Completion status** | **Dual A/B sealed (W28-J)** — see named record |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

Human name: **`CNDHash_Ctor_009cb450`**. Named record: `aa_004bce90_CNDHash_Ctor_009cb450.md`.

## Purpose

CNDHash constructor for object vtbl `009cb450`. Same CF as `FUN_004bcf90` with different vtbl + Alloc callee. Sole caller: COList_Constructor tableC with fixed log2=5.

## Signature (sealed)

```c
void *__thiscall FUN_004bce90(void *thisHash, uint8_t log2);
// ret 4; EAX=this
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004bce90_FUN_004bce90.md`
- Annotated: `docs/reconstruction/raw/aa_004bce90_FUN_004bce90.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_004bce90.cpp`
- Clean named: `docs/reconstruction/reconstructed-exact/CNDHash_Ctor_009cb450.cpp`
- Named record: `docs/reconstruction/functions/aa_004bce90_CNDHash_Ctor_009cb450.md`

## Callers / callees

| Direction | Detail |
|---|---|
| Callers | `FUN_004bbfb0` ×1 (arg 5) |
| Callees | `FUN_004bc7a0` |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + full-body bytes | **High** |
| Distinct stamp from `FUN_004bcf90` | **High** |
| Types / product English | Inferred / open residual |
