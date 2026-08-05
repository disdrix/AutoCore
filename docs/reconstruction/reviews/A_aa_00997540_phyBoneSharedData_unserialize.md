# Review A (reconstruction fidelity): `aa_00997540` phyBoneSharedData_unserialize

| Field | Value |
|---|---|
| **Stable ID** | `aa_00997540` |
| **VA** | `0x00997540` |
| **Canonical name** | `phyBoneSharedData_unserialize` |
| **System** | `physics / phy` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00997540_phyBoneSharedData_unserialize.md` |
| **Verdict** | **accept-with-gaps** |
| **Evidence** | Ghidra MCP `batch_decompile` 2026-07-29; raw/annotated/clean three-rep present |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_00997540_phyBoneSharedData_unserialize.md` |
| Raw | `docs/reconstruction/raw/aa_00997540_phyBoneSharedData_unserialize.md` |
| Annotated | `docs/reconstruction/raw/aa_00997540_phyBoneSharedData_unserialize.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/phyBoneSharedData_unserialize.cpp` |

---

## 2. Purpose (from unit)

Unserialize **BDAT** chunk (file fourCC **`TADB`** = `0x42444154`) for bone shared data. Nested **inside NOBP / PBON**, not a GBOD sibling (plate). Flow:

1. `stoChunkReader_EnterChunkScope` on reader (`param_1` in decompiler thiscall residual).
2. Tag must be `0x42444154` else log (string still says "phyBoneMaster") + −1.
3. **Version 1:** bone name string → hash to `out+0x8` → **two** `stoChunkReader_readF32Array` (rot quat 4 + translation 3) → bind matrix `FUN_0043edb0` → optional nested factory `FUN_0076a900` / `FUN_00467690` stored at `out+0x80` → **force scale** `out+0x28..+0x30 = g_flOne`.
4. **Version 2:** same but **three** f32 arrays (adds scale) — no forced ones.
5. Other versions: formatted log "Invalid chunk version (%i) unserializing phyBoneSharedData" + −1.
6. Destroy temp string; leave scope; return nested status (`param_2` / out status).

Apply order (plate): `v' = translation + rotation * (scale * v)` (hkQsTransform). Trailing 4×4 bind matrix is **not** the live transform.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Tag `0x42444154` BDAT/TADB | **High** | Literal |
| v1: 2 f32-array reads + scale forced to 1 | **High** | CF + g_flOne stores |
| v2: 3 f32-array reads | **High** | Extra readF32Array |
| Name hash/store at out+0x8 | **High** | FUN_00989e00 result |
| Nested object pointer out+0x80 | **High** | Store of factory product |
| Bind matrix via FUN_0043edb0 | **High** | Call both versions |
| Decompiler thiscall param order (reader vs out) | **Medium** | Residual / plate clarifies out object |
| hkQsTransform float counts | **Medium** | Plate; arrays opaque in decomp |
| Runtime | **Open** | Deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| Enter scope; tag gate | **Yes** |
| v1 path with forced unit scale | **Yes** |
| v2 path with third f32 array | **Yes** |
| else invalid version | **Yes** |
| string dtor + leave + return status | **Yes** |

---

## 5. Gaps

1. Seal float array lengths (4+3[+3]) via `stoChunkReader_readF32Array` dual or memory.
2. Clarify decompiler thiscall: reader is first arg in EnterChunkScope despite `__thiscall` on out object — likely MSVC this=out, reader=stack.
3. Nested factory type at +0x80 (bounding volume?).

**Verdict:** **accept-with-gaps**
