# Review A (reconstruction fidelity): `aa_006334e0` CVOGTacArc_Initialize

| Field | Value |
|---|---|
| **Stable ID** | `aa_006334e0` |
| **VA** | `0x006334e0` |
| **Canonical name** | `CVOGTacArc_Initialize` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_006334e0_CVOGTacArc_Initialize.md` |
| **System** | `client-ui` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Bind TacArc to owner/vehicle object: null `param_2` → return **-1**. Store owner at `this+0x20`; `SetStateColor(param_3)`; `InitializeMesh()`; on success if mesh at `+0x18` non-null, build AABB from owner float `+0xe8` (radius-like) and call mesh vtbl **+0x4c** + `FUN_0074b8f0`; finally `UpdateMesh(0)`. Returns mesh/init status.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_006334e0_CVOGTacArc_Initialize.md` |
| Annotated | `docs/reconstruction/raw/aa_006334e0_CVOGTacArc_Initialize.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGTacArc_Initialize.cpp` |
| Function record | `docs/reconstruction/functions/aa_006334e0_CVOGTacArc_Initialize.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `param_2==0 → -1` | **High** | Early |
| `this+0x20 = owner` | **High** | Store |
| `SetStateColor(param_3)` | **High** | Call |
| `InitializeMesh gate (-1 fail)` | **High** | iVar1 |
| `Mesh +0x18 vtbl+0x4c bounds from owner+0xe8` | **High** | ±radius XYZ |
| `UpdateMesh(0) on success path` | **High** | Tail |
| `FUN_0074b8f0 after bounds` | **High** | Helper |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Null check + color + mesh + bounds + update | **Yes** |
| No invented combat | **Yes** |

---

## 5. Gaps / open

1. Owner type (vehicle vs weapon hardpoint).
2. Meaning of owner+0xe8 (half-extent / range).
3. FUN_0074b8f0 role.

**Verdict:** **accept-with-gaps**
