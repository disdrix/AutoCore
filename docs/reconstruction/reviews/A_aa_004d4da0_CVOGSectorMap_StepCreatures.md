# Review A (reconstruction fidelity): `aa_004d4da0` CVOGSectorMap_StepCreatures

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d4da0` |
| **VA** | `0x004d4da0` |
| **Canonical name** | `CVOGSectorMap_StepCreatures` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004d4da0_CVOGSectorMap_StepCreatures.md` |
| **System** | `client-load` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Sector map **creature step** (`StepCreatures`). Iterates creature list `map+0xe720 .. +0xe724`. Per entry: optional autodelete queue `FUN_004e54a0` when stale (`g_dwClientTickMs - +0x14 > 0x77a1`), flags, and faction/vtbl **+0x1dc** mismatch vs `map+0xe8a0`. Steps live creatures `FUN_004c2f40(dt)`. Autodeletes logged `Autodeleting Creature %I64d %d` then `FUN_004d4790`. Critical load/sim tick for combat entities.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004d4da0_*.md` |
| Annotated | `docs/reconstruction/raw/aa_004d4da0_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGSectorMap_StepCreatures.cpp` |
| Function record | `docs/reconstruction/functions/aa_004d4da0_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| List range +0xe720/+0xe724 | High | Body |
| Autodelete threshold 0x77a1 ms | High | Body |
| FUN_004c2f40 per-creature step | High | Body |
| Faction/owner vtbl +0x1dc compare | High | Body |
| map+0x7e gate skips some autodelete logic | High | Body |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| iterate → maybe queue autodelete → step → flush deletes | Yes |

---

## 5. Gaps / open

1. Name FUN_004c2f40 creature tick.
2. Confirm 0x77a1 ≈ 30.625s timeout.

**Verdict:** **accept-with-gaps**
