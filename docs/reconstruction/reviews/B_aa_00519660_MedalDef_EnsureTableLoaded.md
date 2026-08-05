# Review B (skeptical / adversarial): `aa_00519660` MedalDef_EnsureTableLoaded

| Field | Value |
|---|---|
| **Stable ID** | `aa_00519660` |
| **VA** | `0x00519660` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00519660_MedalDef_EnsureTableLoaded.md` |
| **System** | `missions-progression` (medal / achievement def table) |
| **Verdict** | **accept-with-gaps** on CF/ABI; **needs-more-evidence** on Medal vs Achievement product name + re-entry safety |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Pure “ensure if empty” (no-op when loaded) | Body always `Recreate(4)` first | **Falsified pure ensure** — **destructive reload** if called when warm |
| 2 | thiscall on hash table | Free function; ECX set **inside** to `0xb042e0` | **Falsified thiscall** |
| 3 | Load failure aborts inserts | `VOG_DEBUG_STOP` log then falls through; empty vector early-outs | **Survives as non-fatal log** |
| 4 | Def size is 0x3d4 | 0x3d4 is **file/DB row**; runtime def is **0x1c** | **Falsified conflation** |
| 5 | Table is definitely “medals” only | Loader XPath `//tAchievement/row`; toast says Medal | **Survives dual English** — neither sealed alone |
| 6 | Insert is `CNDHash_Lookup` family without count side effect | Insert increments `hash+0xc` (`DAT_00b042ec`) | **Falsified no-count** |
| 7 | Soft/duplicate-tolerant insert | soft flag **0**; duplicate → error path in `FUN_0051e4d0` | **Falsified soft** |
| 8 | Only lookup calls this | CompleteObjective double-call; `FUN_0094a6a0` | **Falsified sole-caller** |
| 9 | Clean invents stride | `ADD ESI,0x3d4` + magic multiply | **Survives** |
| 10 | Prior alias `Named_VOG_DEBUG_STOP` is purpose | String only on load HRESULT fail | **Falsified as purpose name** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Hash root `0x00b042e0` + count `0x00b042ec` | **High** | Wrong global table |
| Recreate then insert loop | **High** | Partial load state |
| Row 0x3d4 / def 0x1c split | **High** | Buffer overruns in port |
| Free 0-arg ABI | **High** | Stack bugs |
| Medal English | **Probable** | Misnamed UI |
| Achievement product table | **Probable** | Wrong DB mirror |
| Safe to call anytime | **Low** | Wipes table on re-entry |

---

## 3. Cross-check

`MedalDef_LookupById` dual already named this unit as lazy loader with body open — this dual closes body CF. CompleteObjective:

```text
if (DAT_00b042ec < 1) { Ensure(); if (still < 1) Ensure(); }
```

Double-call only when count stays 0 — does **not** prove idempotent success path. If first call recreate+empty load leaves count 0, second call recreates again (still empty). If first call somehow left garbage with count>0, second is skipped — good. If a future caller invokes ensure while warm, **recreate wipes**.

---

## 4. Surviving contract for AutoCore

```
// Port as cold-start table fill for g_MedalOrAchievementHash.
// Guard with count<1 at call sites (match client) OR make load truly idempotent.
// Do not treat VOG_DEBUG_STOP as fatal process kill without checking FUN_007a4480.
// Keep def objects 0x1c; do not store 0x3d4 rows in the hash.
// Award/toast paths depend on this hash — empty table ⇒ null lookup ⇒ no medal toast.
```

## 5. What would overturn

1. Second hash root for “true medals” separate from achievements.
2. Proof recreate is skipped when `DAT_00b042ec > 0` via a prologue not present in this image.
3. PDB name forcing Achievement* over Medal* (rename only; CF stands).
