# Review A (reconstruction fidelity): `aa_005c76f0` CLoadNode__initPhysics

| Field | Value |
|---|---|
| **Stable ID** | `aa_005c76f0` |
| **VA** | `0x005c76f0` |
| **Canonical name** | `CLoadNode__initPhysics` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005c76f0_CLoadNode__initPhysics.md` |
| **System** | `client-load` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

CLoadNode stage **`_initPhysics`**. Optional wait `FUN_005c6ad0` on clonebase **+0x14c** when `param_3==0` (return **3** if wait code 3); else `FUN_005c7290` mark. Clears node flag **+0x67**. Resolves phys object via vtbl **+0x1c8**. Player vehicle type **0xE**: special path `FUN_00404c60(+0x30)` / `FUN_00404c30(+0x40)` / `FUN_0053e0d0`; else vtbl init. Then `FUN_0053d430` or `FUN_0053dd40` if **+0x69**. May set **+0x52=1** for certain non-player types with phys flag **+0x40**. Returns **0** success.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005c76f0_*.md` |
| Annotated | `docs/reconstruction/raw/aa_005c76f0_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CLoadNode__initPhysics.cpp` |
| Function record | `docs/reconstruction/functions/aa_005c76f0_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Wait/mark on clonebase +0x14c | High | Body |
| Type 0xE special phys path | High | Body branch |
| Flag +0x67 clear; optional +0x52 | High | Body |
| Return 3 = wait incomplete | High | Early out |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| wait/mark → clear +0x67 → resolve phys → type branch → helpers → 0 | Yes |

---

## 5. Gaps / open

1. Name FUN_0053d430 / 0053dd40 / 0053e0d0.
2. Confirm +0x14c is physics asset ref on clonebase.

**Verdict:** **accept-with-gaps**
