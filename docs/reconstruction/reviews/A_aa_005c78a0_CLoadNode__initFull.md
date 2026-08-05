# Review A (reconstruction fidelity): `aa_005c78a0` CLoadNode__initFull

| Field | Value |
|---|---|
| **Stable ID** | `aa_005c78a0` |
| **VA** | `0x005c78a0` |
| **Canonical name** | `CLoadNode__initFull` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005c78a0_CLoadNode__initFull.md` |
| **System** | `client-load` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

CLoadNode stage **`_initFull`**. Wait/mark on clonebase **+0x160**. Clears **+0x63**. Resolves object vtbl **+0x1c8**; if not type **0xE** or flag **+0x69**, calls `FUN_00516be0`. If **+0x6a**, vtbl **+0x100**. If vtbl **+0x1d0** object non-null, calls its vtbl **+0x44**. Return 0|3.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005c78a0_*.md` |
| Annotated | `docs/reconstruction/raw/aa_005c78a0_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CLoadNode__initFull.cpp` |
| Function record | `docs/reconstruction/functions/aa_005c78a0_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Wait key clonebase +0x160 | High | Body |
| FUN_00516be0 when not player-full path | High | Body |
| Optional vtbl +0x100 / +0x44 finalize | High | Body |
| Clears +0x63 stage flag | High | Body |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| wait/mark → clear +0x63 → resolve → conditional helpers → 0 | Yes |

---

## 5. Gaps / open

1. Name FUN_00516be0 full-init helper.
2. Document +0x6a gate meaning.

**Verdict:** **accept-with-gaps**
