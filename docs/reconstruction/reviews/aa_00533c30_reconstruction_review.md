# Reconstruction review: `aa_00533c30` CVOGReaction_AddExperience

| Field | Value |
|---|---|
| **Stable ID** | `aa_00533c30` |
| **VA** | `0x00533c30` |
| **Canonical name** | `CVOGReaction_AddExperience` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review (faithfulness of clean C++ to low-level / raw) |
| **Author of reconstruction** | Not this reviewer |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path | Role / claims reviewed |
|---|---|---|
| Raw capture | `docs/reconstruction/raw/aa_00533c30_CVOGReaction_AddExperience.md` | Authoritative Ghidra decompile |
| Annotated low-level | `docs/reconstruction/raw/aa_00533c30_CVOGReaction_AddExperience.annotated.md` | Scaffold notes; System missions-progression |
| Exact C++ | `docs/reconstruction/reconstructed-exact/CVOGReaction_AddExperience.cpp` | Human-refined rewrite |
| Function record | `docs/reconstruction/functions/aa_00533c30_CVOGReaction_AddExperience.md` | Human-refined status |
| Prior art | `docs/XP.md` | Algorithm narrative / field map |
| Callee unit | `raw/aa_0052c860_Experience_GetCumulativeThreshold.md` | Threshold sentinel `0x7FFFFFFF` |

**Primary claims (clean ≡ low-level):**

1. KillPath spree 5s / clamp 5 + optional weapon table scale
2. `scaled = (int)(amount * personalXpGain)`
3. Max-level soft cap when `maxLevel < level+1` and `specialMode < 1`
4. `scaled == 0` → false; else add to `+0x730`
5. Level loops only when entity flag `+0x7e` set: LevelDown / max clamp / LevelUp guard `0x12d`
6. Returns bool

**Not re-authored.** No live re-decompile.

---

## 2. Evidence used

| Evidence | Source | Use |
|---|---|---|
| Raw pseudocode | Raw | Ground truth |
| Annotated | Annotated | No CF delta |
| Clean | `.cpp` | Fidelity + naming |
| XP.md § Core apply path | Prior art | Cross-check algorithm |
| Threshold unit | Sibling raw | Sentinel + lazy map |

No runtime / CE. DAT_* float payloads not re-read from image this pass.

---

## 3. Confirmed points

### 3.1 Clean ≡ raw

| Stage | Raw | Clean | Match |
|---|---|---|---|
| KillPath spree / reset | Present | Present | **Yes** |
| Weapon bonus table build + clamp index 0..15 | Present | Present (float[16] contiguous model) | **Yes** |
| Personal scalar multiply | Present | Present | **Yes** |
| Max-level soft cap | Present | Present | **Yes** |
| scaled==0 → false | Present | Present | **Yes** |
| totalXp += scaled | Present | Present | **Yes** |
| Flag-gated level loops | Present | Present | **Yes** |
| LevelDown guard 300 | Present | Present | **Yes** |
| LevelUp guard `0x12d` | Present | Present | **Yes** |
| Max-level positive clamp `threshold-1` | Present | Present | **Yes** |
| Return true fallthrough | Present | Present | **Yes** |

### 3.2 Offsets and constants

| Element | Raw | Clean |
|---|---|---|
| Fields `+0x6b4/6c8/730/734/738/c50/c54` | Present | Same |
| Spree window `5000` ms | Present | Same |
| Spree clamp `5` | Present | Same |
| LevelUp notify `true` | Present | Same |
| Sentinel `0x7fffffff` | Present | Same |

### 3.3 Acceptable modeling deltas

| Delta | Assessment |
|---|---|
| `float[16]` vs `float[4]+12 locals` | Stack-contiguous equivalent for `table[nTmp]` |
| `RoundToInt` vs decompiler `ROUND` | Same nearest-int intent; not a CF change |
| Macros for vtable level / flag | Address math matches raw chains |

### 3.4 Function record honesty

Human-refined; runtime open; DAT_* values listed as Probable. No sealed claim.

### 3.5 Absences

No invented personal-scalar defaults, no server authority, no removal of kill path.

---

## 4. Discrepancies or improvements needed

| Item | Severity | Notes |
|---|---|---|
| DAT_* float payloads unread | Expected gap | Addresses preserved |
| `WeaponAllowsKillXpBonus` name | Naming | Inherited; may be mode gate elsewhere |
| Vtable level getter chain | Opaque | Preserved expression |
| `for` fill of slots 4..15 | Cosmetic | Equivalent to 12 local stores of `DAT_00aaa8f0` |

**No revision required** for clean-vs-raw CF fidelity.

---

## 5. Residual uncertainty

1. Exact spree multiplier table values at `DAT_00aaa7b8` / `aaa8f4` / `aaa8f0`.
2. Entity `+0xe818` index meaning (weapon tier? spree mirror?).
3. Whether personal scalar is always 1.0 on retail characters.
4. Server GiveXp parity requirements for AutoCore.
5. LevelDown threshold edge at level 1 / negative XP floor interaction.

---

## 6. Verdict

### **accept-with-gaps**

**Accept because:**

- Clean is a faithful, heavily commented rewrite of raw CF and offsets.
- Matches XP.md high-level algorithm without inventing policy.
- Function record does not overclaim.

**Gaps:**

- DAT_* values and named mode gates unresolved.
- No runtime / bit-for-bit.
- Vtable/flag chains still structural, not fully typed.

**Not needs-revision** for CF fidelity.

---

## Checklist (reviewer)

| Check | Result |
|---|---|
| Clean CF matches raw | **Pass** |
| Offsets / return codes match | **Pass** |
| No invented logic | **Pass** |
| Function record does not overclaim | **Pass** |
| Runtime / DAT table complete | **Open** |
| Verdict | **accept-with-gaps** |
