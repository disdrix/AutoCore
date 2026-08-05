# Function record: gfxGeometryPiece_Serialize

| Field | Value |
|---|---|
| **Stable ID** | `aa_0074ac40` |
| **Canonical name** | `gfxGeometryPiece_Serialize` |
| **Address** | `0x0074ac40` |
| **Body** | `0x0074ac40`–`0x0074af5a` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `graphics / gfx` (asset I/O) |
| **Source plate** | `palantir\graphics\gfxGeometryPiece.cpp` |
| **Completion status** | **partial** — three-rep present; dual A/B **accept-with-gaps** (2026-07-29); runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Serialize one mesh section as a **GPCE** (`ECPG` / `0x47504345`) chunk **version 10**. Children: has-effect byte → **EFCT** (`this+0x20`) → optional **INDX** (`this+0x0c`) → **VERT** plain (`this+0x14`) or morph path (`this+0x1c`) → optional `vtbl+0x5c` → **BBOX** → name strings (`+0x58/+0x90/+0x94`) + scalar helpers → **USDA** (`[+0x9c,+0xa0)`) → EndChunk. Returns OR of writer status bits.

## Signature (decompiler-derived)

```c
uint __thiscall gfxGeometryPiece_Serialize(int *this, undefined4 *writer);
```

## Key constants / offsets

| Item | Value | Confidence |
|---|---|---|
| BeginChunk tag | `0x47504345` (GPCE/ECPG) | High (entry bytes) |
| Version | `10` | High |
| Effect | `this+0x20` → EFCT `0x45464354` v3 | High |
| Index / vertex / morph | `+0x0c` / `+0x14` / `+0x1c` | High |
| Strings | `+0x58`, `+0x90`, `+0x94` | High |
| USDA range | `+0x9c` / `+0xa0` | High (callee) |
| Flags dword | `+0xbc` — bit0 vfunc; `(>>6)&1` has-effect | High |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0074ac40_gfxGeometryPiece_Serialize.md`
- Annotated: `docs/reconstruction/raw/aa_0074ac40_gfxGeometryPiece_Serialize.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/gfxGeometryPiece_Serialize.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0074ac40_gfxGeometryPiece_Serialize.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0074ac40_gfxGeometryPiece_Serialize.md`

## Callers / callees

**Callers (xrefs):** `FUN_00739a60` (`0x00739a9f`), `FUN_00999040` (`0x0099907b`); data/vtbl refs at `0x00a9db9c`, `0x009d9c54`, …

**Callees (notable):** `stoChunkWriter_BeginChunk` / `EndChunk`; `FUN_004399a0` (u8); `FUN_0096f890` (EFCT); `gfxIndexBufferImpl_Serialize`; `gfxVertexBufferImpl_Serialize`; morph helpers; `FUN_0074bda0` (BBOX); string writers `FUN_00436f80` / `FUN_00767160`; `FUN_00748800` (USDA); `FUN_00439810` / `FUN_00439870` (u32/f32).

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + entry bytes | High |
| Chunk tags GPCE/EFCT/BBOX/USDA | High |
| Parameter semantic names (`writer`, piece fields) | Probable |
| Morph helper internals / EAX scalar sources | Tentative |
| Runtime golden | Open |
