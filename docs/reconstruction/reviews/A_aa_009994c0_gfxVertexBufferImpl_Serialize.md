# Review A (reconstruction fidelity): `aa_009994c0` gfxVertexBufferImpl_Serialize

| Field | Value |
|---|---|
| **Stable ID** | `aa_009994c0` |
| **VA** | `0x009994c0` |
| **Canonical name** | `gfxVertexBufferImpl_Serialize` |
| **System** | `graphics / gfx` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_009994c0_gfxVertexBufferImpl_Serialize.md` |
| **Verdict** | **accept-with-gaps** |
| **Evidence** | Ghidra MCP `batch_decompile` 2026-07-29; raw/annotated/clean three-rep present |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_009994c0_gfxVertexBufferImpl_Serialize.md` |
| Raw | `docs/reconstruction/raw/aa_009994c0_gfxVertexBufferImpl_Serialize.md` |
| Annotated | `docs/reconstruction/raw/aa_009994c0_gfxVertexBufferImpl_Serialize.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/gfxVertexBufferImpl_Serialize.cpp` |

---

## 2. Purpose (from unit)

Serialize a **VERT** chunk (file **`TREV`** = `0x56455254`) at **version 3**. Plate body: `u32 id + u16 stride + u16 count + nested DECL (LCED) + u32 count2 + interleaved vertex data`. Decompile shows:

- `stoChunkWriter_BeginChunk(0x56455254, 3)`
- Optional device lock path when `this+0x10` non-null: `FUN_00746520(stride@+0x14, count@+0x18, 4)` then `FUN_00734640`
- Nested DECL serialize `FUN_00746d40(this+0x24)` and raw write `FUN_00767ab0(0, count@+0x18)`
- On raw write failure: log at gfxVertexBufferImpl.cpp:**0x319**, return **−1**
- Always EndChunk; returns status from DECL/write path

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Tag VERT / TREV `0x56455254`, version **3** | **High** | BeginChunk literals |
| Device at +0x10; stride +0x14; count +0x18; decl state +0x24 | **High** | Field uses |
| Nested DECL via FUN_00746d40 | **High** | Call with this+0x24 |
| Fail → log + EndChunk + −1 | **High** | Explicit path |
| Decompiler `unaff_EDI` is implicit `this` | **Medium** | Calling-convention residual |
| Unreachable block warning @ 0x00999615 | **Medium** | Decompiler note only |
| Clean ≡ raw CF | **High** | Scaffold |
| Full DECL element encoding | **Medium** | Nested helper / plate |
| Runtime | **Open** | Deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| BeginChunk(VERT, 3) | **Yes** |
| Optional lock+header write if device present | **Yes** |
| FUN_0044c9e0; FUN_00746f90 (DECL path status) | **Yes** |
| if status < 0: FUN_00414aa0 else write body + DECL + raw | **Yes** |
| raw fail → log, FUN_00405ef0, EndChunk, −1 | **Yes** |
| EndChunk; return status | **Yes** |

---

## 5. Gaps

1. Recover true register/`this` (unaff_EDI) via force decompile / callers.
2. Name FUN_00746f90 / FUN_00767ab0 / FUN_00746520.
3. Round-trip with Unserialize `0x0099aa20` and geo-format.md DECL layout.

**Verdict:** **accept-with-gaps**
