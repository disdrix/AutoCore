# Review A (reconstruction fidelity): `aa_005c67b0` CLoadNode__recalculateInitAI

| Field | Value |
|---|---|
| **Stable ID** | `aa_005c67b0` |
| **VA** | `0x005c67b0` |
| **Canonical name** | `CLoadNode__recalculateInitAI` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005c67b0_CLoadNode__recalculateInitAI.md` |
| **System** | `client-load` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Recomputes whether AI init should run: only if create-msg **(+0x6c)+4 == 2**. Looks up object via `FUN_004bb070(node+0x18)`. If found and TFID words `param_2+0xf8 & +0xfc == -1`, compares float at clonebase path `…+0x3c → +0x4c0` to `DAT_00aaa668`; sets node **+0x64** to 0 if equal else 1. Non -1 TFID forces **+0x64=0**. Void return.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005c67b0_*.md` |
| Annotated | `docs/reconstruction/raw/aa_005c67b0_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CLoadNode__recalculateInitAI.cpp` |
| Function record | `docs/reconstruction/functions/aa_005c67b0_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Only when (+0x6c)+4 == 2 | High | Body |
| Sets +0x64 AI-needed flag | High | Body |
| TFID -1 + float compare gate | High | Body |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| type==2 → lookup → TFID/float → +0x64 | Yes |

---

## 5. Gaps / open

1. read_memory DAT_00aaa668.
2. Name FUN_004bb070.

**Verdict:** **accept-with-gaps**
