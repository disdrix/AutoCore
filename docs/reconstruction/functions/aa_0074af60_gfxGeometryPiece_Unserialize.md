# Function record: gfxGeometryPiece_Unserialize

| Field | Value |
|---|---|
| **Stable ID** | `aa_0074af60` |
| **Canonical name** | `gfxGeometryPiece_Unserialize` |
| **Address** | `0x0074af60` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `graphics / gfx` (asset I/O — GPCE chunk) |
| **Completion status** | **Three-rep + dual A/B** — accept-with-gaps; runtime open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual reviews** | `reviews/A_aa_0074af60_gfxGeometryPiece_Unserialize.md`, `reviews/B_aa_0074af60_gfxGeometryPiece_Unserialize.md` |
| **Dual date** | `2026-07-29` |

## Purpose

Unserialize one **GPCE** (`0x47504345` / file **ECPG**) geometry-piece chunk from a `stoChunkReader`. Accepts chunk versions **8, 9, 10**. Modern write path (`gfxGeometryPiece_Serialize`) emits **v10** only.

High-level order (v10): EnterChunkScope → tag/version gates → flags → `effEffect_Unserialize` at `this+0x1c` → index at `+4` → vertex at `+0xc` → post hooks → three string/hash fields → map reader status to 0/−1.

## Signature (decompiler-derived)

```c
/* gfxGeometryPiece::Unserialize  [palantir\graphics\gfxGeometryPiece.cpp:0xd6/0x164] */
int __thiscall gfxGeometryPiece_Unserialize(int this_plus4, int stoChunkReader);
```

- **this**: Ghidra `param_1` is **Serialize(this)+4** (vptr at `param_1-4`).
- **Returns**: `−1` hard fail; `0` success or soft-skip (`FUN_00767120`); success path also returns `−1` if `*(reader+0x402c) < 0`.

## Key offsets (`param_1` / this+4)

| Offset | Role | Conf |
|---|---|---|
| `−4` | vptr (`+0x78`, `+100` virtuals) | High |
| `+4` | index buffer unserialize target | High |
| `+0xc` | vertex buffer unserialize target | High |
| `+0x1c` | effect (`effEffect_Unserialize`) | High |
| `+0x50` | char gate for flag path | High CF |
| `+0x54`, `+0x8c`, `+0x90` | string/hash dwords | High store |
| `+0x70` | post-string dword (`FUN_00436900` / EBX residual) | Probable |
| `+0xb8` | flags `|= 1` when `+0x50` non-zero | High |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0074af60_gfxGeometryPiece_Unserialize.md`
- Annotated: `docs/reconstruction/raw/aa_0074af60_gfxGeometryPiece_Unserialize.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/gfxGeometryPiece_Unserialize.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0074af60_gfxGeometryPiece_Unserialize.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0074af60_gfxGeometryPiece_Unserialize.md`
- Serialize twin: `aa_0074ac40` / `0x0074ac40`

## Callers / callees

**Callers (Ghidra xrefs, 3):**

| Address | Function |
|---|---|
| `0x00739d5f`, `0x00739e3e` | `FUN_00739c80` (Named_gfxGeometryPieceMorphed) |
| `0x0099927e` | `FUN_009991b0` (Named_gfxGeometryPieceSkinned) |

**Primary callees:** `stoChunkReader_EnterChunkScope`, `FUN_00767120`, `FUN_00439a50`, `FUN_00437990`, `effEffect_Unserialize`, `FUN_009a00d0` (index), `FUN_009a0000` (vertex), `FUN_00439a20` / `FUN_00439a00` / `FUN_00436900`, `FUN_00989e00`, `FUN_007496c0`, `FUN_0074ce60`, `vog_LogMessage`, `FUN_00769e40`, plus v8/v9 dual-temp helpers (`FUN_004451c0`, `FUN_00746c10`, `FUN_00747390`, `FUN_00414c20`, `FUN_0044bbc0`, …).

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler (tag, versions, branches) | **High** |
| GPCE tag imm `0x47504345` (`read_memory` @ CMP) | **High** |
| Effect / index / vertex offset map | **High** |
| this+4 vs Serialize layout | **High** |
| Soft-skip / string-slot / vtbl English names | **Probable / Tentative** |
| Parameter product names beyond reader/piece | **Probable** |
| Types | **Tentative** |
| Runtime / bit-exact | **Open** |
