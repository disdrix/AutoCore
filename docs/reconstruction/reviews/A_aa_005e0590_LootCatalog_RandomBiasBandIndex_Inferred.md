# Review A (reconstruction fidelity): `aa_005e0590` LootCatalog_RandomBiasBandIndex_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005e0590` |
| **VA** | `0x005e0590` |
| **Canonical name (Ghidra)** | `FUN_005e0590` |
| **Proposed name** | `LootCatalog_RandomBiasBandIndex_Inferred` (**High** CF; ESI semantic residual) |
| **Prior scaffold alias** | `Named_CalleeOf…Nam_005e0590` (chain-of-callers only) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra W16-C) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live + memory) |
| **Counterpart** | `reviews/B_aa_005e0590_LootCatalog_RandomBiasBandIndex_Inferred.md` |
| **System** | `inventory` / loot catalog banded fill |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Random downward bias of a band/quality index** using the global reaction RNG U16 table:

1. `rng = CVOGReaction_RandomUnitScalar()` → `&DAT_00d20c1c` (object, **not** a float).
2. Wrap cursor at `rng+0xc` when `>= 0x100000`; load `u16` from `*(rng+8)[index]`; bump index.
3. `f = (float)u16 * DAT_00aaa638` (~**1/65536**).
4. With input **`n` in ESI**:
   - `n <= 1` → return `n`
   - `n == 2` → return **2** if `f < 0.5`, else **1**
   - `n > 2` → if `f < ~1/3` keep `n`; elif `f < ~2/3` return `n-1`; else `n-2`

Never increases `n`. Sole caller `FUN_005e0cd0` adds result to `typeRow * 0x32` for band-table indexing.

**Not** the ID pick, not the fill walker, not an upward upgrade roller.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x005e0590` |
| Live bytes | `read_memory` @ `0x005e0590` len 160 — confirms ESI, thresholds, bare `ret` |
| Constants | `read_memory` `DAT_00aaa638`, `DAT_00a0f298`, `DAT_009dbf08`, `DAT_009dbf04` |
| RNG getter dual | `A_aa_007a4330_CVOGReaction_RandomUnitScalar` |
| Sole caller | `get_function_callers` → `FUN_005e0cd0` only |
| Consumer dual | `A\|B_aa_005e0cd0_LootCatalog_FillCandidateIds_QualityTypeBand_Inferred` |
| Raw / annotated / clean | `aa_005e0590_*` / `FUN_005e0590.cpp` |
| Function record | `docs/reconstruction/functions/aa_005e0590_FUN_005e0590.md` |

**This pass:** live decompile + memory + callers. **Not performed:** Launcher, runtime distribution sampling, parent ledger edits.

---

## 3. Constants (`read_memory`)

| Symbol | Bytes (LE) | Float | Role |
|---|---|---|---|
| `DAT_00aaa638` | `80 00 80 37` | **~1.5259e-5** (≈1/65536) | unit scale |
| `DAT_00a0f298` | `00 00 00 3f` | **0.5** | n==2 split |
| `DAT_009dbf08` | `9f aa aa 3e` | **~0.333333** | n>2 keep/drop |
| `DAT_009dbf04` | `9f aa 2a 3f` | **~0.666666** | n>2 drop-2 |

---

## 4. Signature

```c
// ESI = maxBand (register param; decompiler unaff_ESI)
// return EAX = biased band index; bare ret
int FUN_005e0590(void);
// proposed: int LootCatalog_RandomBiasBandIndex_Inferred(/* ESI */ int maxBand);
```

---

## 5. Callers / callees

| Direction | Symbol | Role |
|---|---|---|
| Caller | `FUN_005e0cd0` | sole — band linear index = bias + typeRow×50 |
| Callee | `CVOGReaction_RandomUnitScalar` `0x007a4330` | RNG object getter |

---

## 6. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| RNG get + wrap + U16 load + index++ | **Yes** |
| Scale by `DAT_00aaa638` | **Yes** |
| n≤1 passthrough | **Yes** (`jge` after `cmp esi,2` path) |
| n==2 half split vs 0.5 | **Yes** (`comiss` / `jbe`) |
| n>2 thirds vs ~1/3,~2/3 | **Yes** |
| Clean ≡ raw CF | **Yes** |

Assembly note: decompiler `0xfffff < index` ≡ machine `cmp index, 0x100000` / reset when **≥**.

---

## 7. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Decision table (keep / −1 / −2) | **High** | live + asm |
| Constants decoded | **High** | `read_memory` |
| ESI is input max band | **High** | asm uses ESI; no stack read |
| Never upgrades index | **High** | only −0/−1/−2 |
| Sole caller `005e0cd0` | **High** | callers query |
| What ESI holds at call site (level vs quality max vs rank) | **Tentative** | residual in consumer dual |
| Exact product name | **Tentative** | `_Inferred` |
| Runtime | **Open** | deferred |

---

## 8. Gaps / open

1. **ESI provenance** at `005e0cd0` call — decompiler shows zero-arg call; value may be live from outer `005e1150` / intermediate.
2. RNG table fill algorithm (`FUN_007a42d0`) — out of own VA scope.
3. Whether floats were authored as exact 1/3 and 2/3 (binary approx).

**Verdict:** **accept-with-gaps** — CF and constants **High**; ESI semantic English residual.
