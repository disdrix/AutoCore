# Review A (reconstruction fidelity): `aa_0053a820` StdVector_PushBackDword_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053a820` |
| **VA** | `0x0053a820` |
| **Canonical name** | `StdVector_PushBackDword_Inferred` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0053a820_StdVector_PushBackDword_Inferred.md` |
| **System** | `missions-progression` / LevelUp residual |
| **Verdict** | **accept** |

---

## 1. Purpose

`vector<uint32_t>`-style push_back (`thiscall`):

- Layout: `+4 begin`, `+8 end`, `+0xc capacity` (pointer triad).
- Fast path: if `size < capacity` (`(end-begin)>>2 < (cap-begin)>>2`), store `*src` at `*end`, `end += 4`.
- Slow path: `FUN_00539810(end, 1, src)` grow/insert one dword.

Callee of `CVOGCharacter_LevelUp` (records an id/level token into a dword vector — exact semantic list open).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Ghidra decompile | `0x0053a820` |
| Raw | `docs/reconstruction/raw/aa_0053a820_FUN_0053a820.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0053a820.cpp` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Dword element (`>>2`) | **High** | Size/cap math |
| Fast construct-in-place | **High** | Body |
| Grow via `FUN_00539810(...,1,src)` | **High** | Else branch |
| Not XP formula | **High** | Container |

---

## 4. Gaps

1. Which LevelUp vector (mission refresh ids vs other).
2. Dual for grow helper `0x00539810` if still missing.

**Verdict:** **accept**
