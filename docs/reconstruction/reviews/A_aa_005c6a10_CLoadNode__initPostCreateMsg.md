# Review A (reconstruction fidelity): `aa_005c6a10` CLoadNode__initPostCreateMsg

| Field | Value |
|---|---|
| **Stable ID** | `aa_005c6a10` |
| **VA** | `0x005c6a10` |
| **Canonical name** | `CLoadNode__initPostCreateMsg` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005c6a10_CLoadNode__initPostCreateMsg.md` |
| **System** | `client-load` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

CLoadNode stage **`_initPostCreateMsg`**. Reads create-msg blob at node **+0x6c**, invokes object vtbl **+0xc8 (200)** with blob fields (*pu, pu[1], bytes…, 1), then **deletes** blob and nulls **+0x6c**. Always returns **0**. Applies deferred create message after object exists.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005c6a10_*.md` |
| Annotated | `docs/reconstruction/raw/aa_005c6a10_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CLoadNode__initPostCreateMsg.cpp` |
| Function record | `docs/reconstruction/functions/aa_005c6a10_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Blob at +0x6c fed to vtbl+0xC8 | High | Body |
| Deletes blob after apply | High | operator_delete |
| Returns 0 | High | Body |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| read +0x6c → vtbl apply → delete → null → 0 | Yes |

---

## 5. Gaps / open

1. Seal create-msg blob layout at +0x6c.
2. Name vtbl+0xC8 applyCreateMsg.

**Verdict:** **accept-with-gaps**
