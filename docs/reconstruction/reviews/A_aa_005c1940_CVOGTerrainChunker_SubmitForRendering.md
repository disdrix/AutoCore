# Review A (reconstruction fidelity): `aa_005c1940` CVOGTerrainChunker_SubmitForRendering

| Field | Value |
|---|---|
| **Stable ID** | `aa_005c1940` |
| **VA** | `0x005c1940` |
| **Canonical name** | `CVOGTerrainChunker_SubmitForRendering` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005c1940_CVOGTerrainChunker_SubmitForRendering.md` |
| **System** | `terrain` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Per-frame client terrain submit. Scoped string CVOGTerrainChunker::SubmitForRendering then LOD calculations then Submit chunks. Reads camera/view floats from `param_2` scene object; optional alt path if flag `*(cam+0xbc)&1` via `FUN_00972e50`. Computes distance budget from terrain dims `*param_1+0x10/+0x14` × scale `+0x18`, FOV/radius tables `+0xe894/+0xe898`, `param_1[0x1d]`, `DAT_00a0f298`. Nested chunk grid loops set per-chunk hide flag `+0xd4` and LOD step `+0xd8` from distance table `DAT_00af3f98` (6 bands); may `FUN_005c18a0` when max-detail. Second phase iterates submit list `param_1[0xb]/[0xc]` and vcalls mesh/submit (`vtbl+0x80/+0x5c/+0x3c`) via `FUN_0075c960`. Pure client culling/LOD — not sim.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005c1940_CVOGTerrainChunker_SubmitForRendering.md` |
| Annotated | `docs/reconstruction/raw/aa_005c1940_CVOGTerrainChunker_SubmitForRendering.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGTerrainChunker_SubmitForRendering.cpp` |
| Function record | `docs/reconstruction/functions/aa_005c1940_CVOGTerrainChunker_SubmitForRendering.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Scoped SubmitForRendering + LOD calculations + Submit chunks strings` | **High** | FUN_0076cf00 |
| `Camera floats from param_2 chain (+0x30 view)` | **High** | Entry |
| `Optional FUN_00972e50 when cam flag +0xbc bit0` | **High** | Branch |
| `Distance budget from dims*scale + e894/e898 + param_1[0x1d]` | **High** | fVar16 |
| `FUN_0075b390 / FUN_0075b7f0 pre-LOD helpers` | **High** | Calls |
| `Grid loops set chunk +0xd4 hide + +0xd8 LOD` | **High** | Body |
| `LOD bands DAT_00af3f98[i*2] × chunk size (6)` | **High** | Table scan |
| `FUN_005c18a0 on max-detail band` | **High** | Call |
| `Submit list param_1[0xb] stride; vtbl submit path` | **High** | Phase 2 |
| `Client render only` | **High** | No gameplay writes |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| SEH + strings + LOD grid + submit list | **Yes** |
| No invented network/sim | **Yes** |

---

## 5. Gaps / open

1. Full meaning of FUN_0075b390 / FUN_0075b7f0 / FUN_0075c960.
2. Exact LOD distance table values at 0xaf3f98.
3. Chunk object layout (+0xc8 mesh, +0xd4 hide, +0xd8 lod, +0xc5 dirty).
4. Relationship of param_1[6] default LOD step.
5. When BuildVertexBuffer is invoked relative to submit (indirect).

**Verdict:** **accept-with-gaps**
