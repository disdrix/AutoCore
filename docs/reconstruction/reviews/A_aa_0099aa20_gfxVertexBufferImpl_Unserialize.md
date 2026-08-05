# Review A (reconstruction fidelity): `aa_0099aa20` gfxVertexBufferImpl_Unserialize

| Field | Value |
|---|---|
| **Stable ID** | `aa_0099aa20` |
| **VA** | `0x0099aa20` |
| **Canonical name** | `gfxVertexBufferImpl_Unserialize` |
| **System** | `graphics / gfx` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0099aa20_gfxVertexBufferImpl_Unserialize.md` |
| **Verdict** | **accept-with-gaps** |
| **Evidence** | Ghidra MCP `batch_decompile` 2026-07-29; raw/annotated/clean three-rep present |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_0099aa20_gfxVertexBufferImpl_Unserialize.md` |
| Raw | `docs/reconstruction/raw/aa_0099aa20_gfxVertexBufferImpl_Unserialize.md` |
| Annotated | `docs/reconstruction/raw/aa_0099aa20_gfxVertexBufferImpl_Unserialize.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/gfxVertexBufferImpl_Unserialize.cpp` |

---

## 2. Purpose (from unit)

Unserialize **VERT** (`0x56455254` / TREV). Accepts versions **1–3**:

| Ver | Path (from decompile + plate) |
|---|---|
| **1** | Legacy: build decl container; per-element loop on 8-byte D3DVERTEXELEMENT9-style records (usage @ **+6**); usages **2/10** byte reads, others float arrays; ends at sentinel (end−8) |
| **2** | DECL then count + bulk data (shared with v3 tail after version gate) |
| **3** | Id helpers (`FUN_00734690` / `FUN_0044c370` / `FUN_0044c340`); fail → **−2**; then DECL + lock + `FUN_00769990` bulk read |

Early outs: wrong tag → **−1**; `FUN_00767120` non-zero → **0** (soft skip). Create path `FUN_0099a8e0`. Device lock vtbl **`+0x2c`**, flags **`0x800`**. Success path returns **0** after cleanup when reader residual status ≥ 0.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Tag gate VERT / TREV | **High** | Literal |
| Versions 1 / 2 / 3 only; else invalid-version log | **High** | CF |
| v3 id mismatch → −2 | **High** | Explicit return |
| FUN_00767120 soft-success return 0 | **High** | Distinct from −1 |
| v1 element usage switch (2,10 vs floats) | **High** | Switch cases |
| Device lock +0x2c / 0x800 | **High** | Same pattern as IB |
| Clean ≡ raw CF | **High** | Large but scaffold-aligned |
| Stride 32/56/24 layout table (plate) | **Medium** | Prior art / not re-sampled here |
| Runtime | **Open** | Deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| EnterChunkScope; tag check | **Yes** |
| Soft-skip FUN_00767120 → 0 | **Yes** |
| v1: decl container + per-element read loop + cleanup | **Yes** |
| v2/v3: version gates; v3 id path; shared DECL + lock + bulk | **Yes** |
| Fail paths −1 / create-fail return code; success 0 | **Yes** |
| Leave scope FUN_00769e40 when local_30 | **Yes** |

---

## 5. Gaps

1. Name soft-skip `FUN_00767120` and create `FUN_0099a8e0`.
2. Exact v1 element type table vs D3DDECLUSAGE enum values.
3. Confirm common strides (24/32/56) against Autocore mesh set.

**Verdict:** **accept-with-gaps**
