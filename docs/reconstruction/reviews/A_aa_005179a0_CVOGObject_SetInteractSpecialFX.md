# Review A (reconstruction fidelity): `aa_005179a0` CVOGObject_SetInteractSpecialFX

| Field | Value |
|---|---|
| **Stable ID** | `aa_005179a0` |
| **VA** | `0x005179a0` |
| **Canonical name** | `CVOGObject_SetInteractSpecialFX` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005179a0_CVOGObject_SetInteractSpecialFX.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept** |

---

## 1. Purpose

Replace interact special-FX pointer @ object **+0x130**: tear down old via FUN_00517250, attach new via vtbl **+0xF8**(fx,1,0), store pointer (nullable).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005179a0_CVOGObject_SetInteractSpecialFX.md` |
| Annotated | `docs/reconstruction/raw/aa_005179a0_CVOGObject_SetInteractSpecialFX.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGObject_SetInteractSpecialFX.cpp` |
| Function record | `docs/reconstruction/functions/aa_005179a0_CVOGObject_SetInteractSpecialFX.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Slot +0x130 holds current FX*` | **High** | Load/store |
| `Non-null old → FUN_00517250 teardown` | **High** | Before replace |
| `Non-null new → vtbl+0xF8 attach (1,0)` | **High** | Call order before store |
| `Null new allowed (clear FX)` | **High** | Store null after teardown |
| `Mission interact icon path related` | **Probable** | Plate / NDSpecialFX names |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Teardown + attach + store | **Yes** |
| Null-safe both sides | **Yes** |

---

## 5. Gaps / open

1. FUN_00517250 exact destructor semantics.
2. Attach vfunc identity beyond +0xF8.
3. All writers of interact_* script FX.

**Verdict:** **accept**
