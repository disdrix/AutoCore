# Review A (reconstruction fidelity): `aa_00435f30` stoChunkStream_ReadBytes_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00435f30` |
| **VA** | `0x00435f30`–`0x00435fdd` |
| **Canonical name** | `stoChunkStream_ReadBytes_Inferred` |
| **Prior scaffold** | `FUN_00435f30` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00435f30_stoChunkStream_ReadBytes_Inferred.md` |
| **System** | `sto-chunk` / asset serialize |
| **Agent** | W18-Q OWN-ONLY |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Buffered **byte-span read** for the stoChunk **stream shell**. Copies from the internal window at `this+0x18+cursor`, advances cursor, and either:

1. **Hits in buffer** (`cursor + n <= avail`) → bulk copy, return `0`.
2. **Request ≤ maxChunk (`+0x10`) but window short** → `FUN_00435df0(base+cursor)` refill; fail → `-1`; success → bulk copy.
3. **Request > maxChunk** → drain residual window into dest, call interface **vtbl+4(base+cursor, 0)** then **vtbl+0x14(dest_advanced, rem)**, bump cursor, return `0`.

Used as the bulk path of `stoChunkReader_readF32Array` (`this = reader+0x14`, `n = count*4`) and other chunk readers (8 xrefs).

**Not** a float parser, not the text/token path (`FUN_00767fd0`), not the refill itself.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00435f30_FUN_00435f30.md` (+ v2026-07-29) |
| Annotated | `docs/reconstruction/raw/aa_00435f30_FUN_00435f30.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/stoChunkStream_ReadBytes_Inferred.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_00435f30.cpp` |
| Function record | `docs/reconstruction/functions/aa_00435f30_FUN_00435f30.md` |
| Live decompile | Ghidra `0x00435f30` (2026-07-29) — **≡ scaffold CF** |
| Machine | `read_memory` full body; ends `C2 08 00` |
| Parent dual | `A\|B_aa_00436090_stoChunkReader_readF32Array` (caller shape) |

**Not performed:** `disassemble_bytes`, Launcher, runtime capture, binary diff; **no ownership** of `FUN_00435df0` / vtbl targets.

---

## 3. Signature / layout

```c
// __thiscall; ret 8
uint32_t __thiscall stoChunkStream_ReadBytes_Inferred(
    StreamShell *stream, // this
    void *dest,
    uint32_t byteCount);
```

| Offset | Role |
|---|---|
| `+0` | interface* → vtbl |
| `+4` | cursor |
| `+8` | base (refill / vtbl arg) |
| `+0xC` | available end |
| `+0x10` | max in-buffer chunk |
| `+0x18` | payload window |

Host map when `stream = reader+0x14`: cursor host `+0x18`, avail `+0x20`, window `+0x2c` (sealed on parent dual).

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Bulk byte read role | **Confirmed** | CF + callers |
| ABI thiscall `ret 8` | **Confirmed** | three epilogues |
| Return 0 / -1 | **Confirmed** | `xor eax,eax` / `or eax,-1` |
| Window at `+0x18`, cursor `+4`, avail `+0xC` | **Confirmed** | |
| maxChunk gate `+0x10` → direct IO | **Confirmed** | |
| Refill via `FUN_00435df0` | **Confirmed** | sole E8 callee |
| vtbl `+4` then `+0x14` on direct path | **Confirmed** | `FF 50 04` / `FF 50 14` |
| Direct second arg is dest (not unaff_EBX) | **Confirmed (bytes)** | decompiler residual |
| Clean ≡ raw ≡ live CF | **Confirmed** | |
| Product names / vtbl English | **Open** | `_Inferred` |
| Runtime / bit-exact | **Open** | |

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| In-buffer bulk copy + cursor+=n → 0 | **Yes** |
| maxChunk overflow → drain + vtbl +0 | **Yes** |
| Else refill; fail → -1 | **Yes** |
| Post-refill bulk copy | **Yes** |
| No invent of float/text semantics | **Yes** |

---

## 6. Gaps

- Product type name of stream interface and vtbl slot roles.
- Full semantics of `FUN_00435df0` (owned elsewhere).
- Runtime golden / bit-exact image diff.
