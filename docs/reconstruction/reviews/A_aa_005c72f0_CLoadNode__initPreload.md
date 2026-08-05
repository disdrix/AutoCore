# Review A (reconstruction fidelity): `aa_005c72f0` CLoadNode__initPreload

| Field | Value |
|---|---|
| **Stable ID** | `aa_005c72f0` |
| **VA** | `0x005c72f0` |
| **Canonical name** | `CLoadNode__initPreload` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005c72f0_CLoadNode__initPreload.md` |
| **System** | `client-load` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

CLoadNode stage **`_initPreload`**. Wait/mark clonebase **+0x174**. Clears **+0x66**. Calls `FUN_004eb3b0` (physics preload family); if clonebase **+0x134==0**, `FUN_004f2540`. Stores vtbl **+0xc** result into node **+0x58**. Return 0|3.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005c72f0_*.md` |
| Annotated | `docs/reconstruction/raw/aa_005c72f0_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CLoadNode__initPreload.cpp` |
| Function record | `docs/reconstruction/functions/aa_005c72f0_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Wait key +0x174 | High | Body |
| FUN_004eb3b0 preload | High | Shared with CollectAllPhysicsPreloads |
| Stores +0x58 from vtbl+0xc | High | Body |
| Optional FUN_004f2540 if +0x134==0 | High | Body |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| wait/mark → +0x66=0 → eb3b0 → maybe f2540 → +0x58 → 0 | Yes |

---

## 5. Gaps / open

1. Name FUN_004f2540.
2. Relate +0x58 to later stages.

**Verdict:** **accept-with-gaps**
