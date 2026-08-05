# Function record: FUN_004bcf90

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bcf90` |
| **Canonical name** | `FUN_004bcf90` (prefer **`CNDHash_Ctor_009cb45c`**) |
| **Address** | `0x004bcf90`–`0x004bd001` (**114 B / `0x72`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | container / CNDHash |
| **Completion status** | **Dual A/B sealed (W28-J)** — see named record |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

Human name: **`CNDHash_Ctor_009cb45c`**. Named record: `aa_004bcf90_CNDHash_Ctor_009cb45c.md`.

## Purpose

CNDHash constructor for object vtbl `009cb45c`. Installs vtbl, zeros fields, sets `+0x08 = 1<<log2`, calls `FUN_004bc840` AllocBucketTable, returns this. Sole caller: COList_Constructor (hashA/hashB).

## Signature (sealed)

```c
void *__thiscall FUN_004bcf90(void *thisHash, uint8_t log2);
// ret 4; EAX=this
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004bcf90_FUN_004bcf90.md`
- Annotated: `docs/reconstruction/raw/aa_004bcf90_FUN_004bcf90.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_004bcf90.cpp`
- Clean named: `docs/reconstruction/reconstructed-exact/CNDHash_Ctor_009cb45c.cpp`
- Named record: `docs/reconstruction/functions/aa_004bcf90_CNDHash_Ctor_009cb45c.md`

## Callers / callees

| Direction | Detail |
|---|---|
| Callers | `FUN_004bbfb0` ×2 |
| Callees | `FUN_004bc840` |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + full-body bytes | **High** |
| Parameter: log2 bucket exponent | **High** |
| Types / product English | Inferred / open residual |
