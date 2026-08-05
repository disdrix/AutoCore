# Review A (reconstruction fidelity): `aa_005c6880` CLoadNode_initAI

| Field | Value |
|---|---|
| **Stable ID** | `aa_005c6880` |
| **VA** | `0x005c6880` |
| **Canonical name** | `CLoadNode_initAI` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005c6880_CLoadNode_initAI.md` |
| **System** | `client-load` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

CLoadNode stage **`_initAI`** (docs/NPC: create/attach HBAI). Clears flag **+0x64**. Resolves AI host via vtbl **+0x1d8**; if null → done. Creature check vtbl **+0x1dc**: if creature, force `param=1`; else if TFID words `pi[0x8a]&pi[0x8b] != -1` or char `pi[0x8c]` → param=1 else 0. Calls host vtbl **+0xc0**(param, -1) to create/attach HBAI. Returns **0**.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005c6880_*.md` |
| Annotated | `docs/reconstruction/raw/aa_005c6880_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CLoadNode_initAI.cpp` |
| Function record | `docs/reconstruction/functions/aa_005c6880_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Clears +0x64; vtbl+0xc0 attaches HBAI | High | Body + NPC.md |
| Creature path forces enable | High | Body |
| TFID/-1 and +0x8c gate for non-creature | High | Body |
| Returns 0 always after SEH | High | Body |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| +0x64=0 → resolve host → gate → vtbl+0xc0 → 0 | Yes |

---

## 5. Gaps / open

1. Confirm vtbl+0xc0 = HBAI factory attach.
2. Document pi[0x8a/0x8b/0x8c] field names.

**Verdict:** **accept-with-gaps**
