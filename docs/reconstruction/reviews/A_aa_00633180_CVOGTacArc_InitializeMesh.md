# Review A (reconstruction fidelity): `aa_00633180` CVOGTacArc_InitializeMesh

| Field | Value |
|---|---|
| **Stable ID** | `aa_00633180` |
| **VA** | `0x00633180` |
| **Canonical name** | `CVOGTacArc_InitializeMesh` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00633180_CVOGTacArc_InitializeMesh.md` |
| **System** | `client-ui` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Build TacArc render resources: loads effect **`NDTacArc.fx`**, textures **`veh_tacarc.dds`** / **`veh_tacarc_effect.dds`**, material name **`TacArcTextureBase`**. Allocates/configures mesh object stored near `this+0x18` / material `+0x1c`; multi-stage FUN_009* / FUN_007* D3D helpers (`FUN_00989e00`, `FUN_00970140`, `FUN_00748960`, `FUN_00764030`, `FUN_00414c20`, …). Returns **int** status (≥0 success for Initialize gate). Large client-graphics body.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00633180_CVOGTacArc_InitializeMesh.md` |
| Annotated | `docs/reconstruction/raw/aa_00633180_CVOGTacArc_InitializeMesh.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGTacArc_InitializeMesh.cpp` |
| Function record | `docs/reconstruction/functions/aa_00633180_CVOGTacArc_InitializeMesh.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Strings NDTacArc.fx + veh_tacarc*.dds + TacArcTextureBase` | **High** | Plate/strings |
| `Creates mesh/material objects` | **High** | Alloc + stores |
| `Multiple D3D/helper callees FUN_009*/007*` | **High** | Body |
| `Status int return for Initialize` | **High** | Caller gate |
| `Client-only assets` | **High** | fx/dds paths |
| `Full GPU resource layout residual` | **Probable** | Many FUN_* |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Asset load + resource create + status | **Yes** |
| No invented combat math | **Yes** |

---

## 5. Gaps / open

1. Full ordered callee map and failure paths.
2. Exact offsets of mesh/material/effect pointers.
3. Device-lost / reload behavior.

**Verdict:** **accept-with-gaps**
