# Review A (reconstruction fidelity): `aa_00921580` UI_UpdateOverheatTip

| Field | Value |
|---|---|
| **Stable ID** | `aa_00921580` |
| **VA** | `0x00921580` |
| **Canonical name** | `UI_UpdateOverheatTip` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00921580_UI_UpdateOverheatTip.md` |
| **System** | `combat` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

UI/combat **overheat tip updater** (`Weapons Overheated!`). Requires UI host `DAT_00d1b968`, first-time flag slot clear, local char `DAT_00d1b6d8` + vehicle **+0x250**. Compares vehicle heat **+0x150** vs max **+0x244** (half-max branch for first-time tip `0x1d`). On overheat path: floater via `FUN_007fde80`, stamps UI slots `[0x146]=-2`, `[0x147]=-1`, optional LED FX `LED_FX_overheat_xml`. Uses same heat offsets as `Weapon_CanFireHeatCheck`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00921580_*.md` |
| Annotated | `docs/reconstruction/raw/aa_00921580_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_UpdateOverheatTip.cpp` |
| Function record | `docs/reconstruction/functions/aa_00921580_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Heat +0x150 vs max +0x244 on vehicle | High | Body |
| String Weapons Overheated! floater | High | Body |
| First-time tip path Client_MaybeShowFirstTimeTip | High | Callee |
| Does not modify heat pools | High | Read-only tip |
| Half-max tip threshold exact | Medium | Decompiler line glue |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| gates → heat compare → tip/floater/LED | Yes |

---

## 5. Gaps / open

1. Seal half-max vs full overheat branches bit-exact.
2. UI slot indices 0x146..0x149 semantics.

**Verdict:** **accept-with-gaps**
