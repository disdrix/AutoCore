# Review A (reconstruction fidelity): `aa_00632900` CVOGTacArc_dtor_helper

| Field | Value |
|---|---|
| **Stable ID** | `aa_00632900` |
| **VA** | `0x00632900` |
| **Canonical name** | `CVOGTacArc_dtor_helper` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00632900_CVOGTacArc_dtor_helper.md` |
| **System** | `client-ui` |
| **Verdict** | **accept** |

---

## 1. Purpose

Tear down TacArc without optional free: reinstall vtbl; `operator_delete__` mesh buffer at `param_1[0xb]` if non-null; virtual dtor (`*vtbl)(1)` on object at `param_1[6]` if non-null; clear both; `FUN_0096f510` then dual `FUN_0096efd0` matching ctor sub-object teardown. Called from `CVOGTacArc_vdtor`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00632900_CVOGTacArc_dtor_helper.md` |
| Annotated | `docs/reconstruction/raw/aa_00632900_CVOGTacArc_dtor_helper.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGTacArc_dtor_helper.cpp` |
| Function record | `docs/reconstruction/functions/aa_00632900_CVOGTacArc_dtor_helper.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Reinstalls TacArc vdtor vtbl` | **High** | Store |
| `delete__ param_1[0xb] mesh buffer` | **High** | if non-null |
| `Virtual dtor(1) on param_1[6]` | **High** | if non-null |
| `FUN_0096f510 + FUN_0096efd0 x2 teardown` | **High** | Mirrors ctor |
| `No operator_delete of this` | **High** | vdtor owns free flag |
| `Clears [0xb] and [6] after free` | **High** | Body |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Vtbl + free mesh + free embed + FUN teardown | **Yes** |
| No invented branches | **Yes** |

---

## 5. Gaps / open

1. Identity of object at [6] vs [0xb].
2. Whether FUN_0096efd0 is exact pair of FUN_0096ef70.

**Verdict:** **accept**
