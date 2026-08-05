# Review A (reconstruction fidelity): `aa_00632a20` CVOGTacArc_SetStateColor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00632a20` |
| **VA** | `0x00632a20` |
| **Canonical name** | `CVOGTacArc_SetStateColor` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00632a20_CVOGTacArc_SetStateColor.md` |
| **System** | `client-ui` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Store combat/UI state enum at `this+0x24` and write hard-coded RGBA packs into color bytes **+0x30..+0x37** (+ fixed `+0x33=0x66`). States: **0 / 1 / 2 / else** each distinct RGB pair (fill + outline). If material object `this+0x1c` non-null, push outline color via `FUN_009733d0(this+0x34)` and `FUN_009700f0("MatZFailColor", ...)`. Visual feedback only.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00632a20_CVOGTacArc_SetStateColor.md` |
| Annotated | `docs/reconstruction/raw/aa_00632a20_CVOGTacArc_SetStateColor.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGTacArc_SetStateColor.cpp` |
| Function record | `docs/reconstruction/functions/aa_00632a20_CVOGTacArc_SetStateColor.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `this+0x24 = state` | **High** | Store |
| `State 0/1/2/else hard-coded RGB tables` | **High** | Four branches |
| `+0x33 always 0x66 alpha-ish` | **High** | All paths |
| `Material +0x1c gate for MatZFailColor` | **High** | if non-null |
| `FUN_009733d0 + FUN_009700f0 shader params` | **High** | Calls |
| `No mesh rebuild` | **High** | Color only |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| State store + 4 color tables + optional mat | **Yes** |
| No invented states | **Yes** |

---

## 5. Gaps / open

1. Semantic names for state 0/1/2 (friendly/hostile/overheat?).
2. Exact RGBA channel order in +0x30 pack.
3. Whether UpdateMesh reads same slots.

**Verdict:** **accept-with-gaps**
