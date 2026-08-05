# Review A (reconstruction fidelity): `aa_0052b3b0` CVOGCharacter_IsMissionJournalReady

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052b3b0` |
| **VA** | `0x0052b3b0` |
| **Canonical name (proposed)** | `CVOGCharacter_IsMissionJournalReady` |
| **Ghidra name** | `FUN_0052b3b0` |
| **Prior aliases** | `Named_CalleeOf_Named_CalleeOf_Client_UpdateMissionJournal_0052b3b0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0052b3b0_CVOGCharacter_IsMissionJournalReady.md` |
| **Sibling (contrast)** | `aa_0052b420` / `CVOGCharacter_IsMissionTurnInReady` (mode **1** turn-in) |
| **System tag** | `missions-progression` |
| **Verdict** | **accept** on last-obj / active-hash / mode-0 readiness gates; **accept-with-gaps** on product names of callers + `FUN_0052a020` |

---

## 1. Purpose

Client **journal / lightweight mission-ready** predicate: whether the character’s **last** mission objective is active and ready under **mode 0** evaluator checks.

Used by journal / mission-detail UI paths to show **“(Complete)”** chrome (and related refresh helpers). **Not** the turn-in claim gate (`FUN_0052b420`).

Returns **bool** (`AL`). **No stores.** Does not send packets. **No NPC argument.**

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live Ghidra decompile | `FUN_0052b3b0` @ `0x0052b3b0` (≡ raw CF) |
| Image bytes | `read_memory` `0x0052b3b0`–`0x0052b412` (`ret 4`; ECX+0x548; `push 0` before `FUN_0052a020`) |
| Sibling image | `read_memory` `0x0052b420`–`0x0052b4d8` (`ret 8`; `push 1`; NPC type-3 loop) |
| Call-site framing | `read_memory` @ `0x00829c50`, `0x0082a248`, `0x008a2020` |
| Callers decompile | `FUN_00829b20`, `FUN_0082a050`, `FUN_008a2020` |
| Callee | `FUN_0052a020` @ `0x0052a020` (mode 0 → eval `vtbl+0xc`) |
| Raw | `docs/reconstruction/raw/aa_0052b3b0_FUN_0052b3b0.md` |
| Annotated | `docs/reconstruction/raw/aa_0052b3b0_FUN_0052b3b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGCharacter_IsMissionJournalReady.cpp` |
| Function record | `docs/reconstruction/functions/aa_0052b3b0_CVOGCharacter_IsMissionJournalReady.md` |
| Layout | `docs/missionState.md` — char `+0x548` active objectives; mission `+0x130`/`+0x13c`; obj `+0x10` |
| Dual sibling | `A/B_aa_0052b420_CVOGCharacter_IsMissionTurnInReady.md` |
| Mode owner | `A/B_aa_0052a020_CVOGCharacter_IsObjectiveReady.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__thiscall` ECX=`CVOGCharacter*`; one stack arg mission def | **High** | `mov eax,[ecx+0x548]`; epilogue `C2 04 00` (`ret 4`) |
| Last objective = `*(objectives + count*4 - 4)` | **High** | same LEA as turn-in: count `@mission+0x130`, array `@+0x13c` |
| Active hash = `char+0x548`; key = `obj+0x10` | **High** | image + missionState + sibling seal |
| Bucket walk: mask `@hash+8`, buckets `@hash+0x10`, node key `+0x10`, next `+0xc` | **High** | body ≡ turn-in preamble |
| Active payload gate: `node+0x8 != 0` | **High** | early return 0 if null |
| Miss / empty chain → 0 | **High** | |
| Ready gate: `FUN_0052a020(this=char, lastObj, flag=0)` | **High** | image `6A 00 56 E8 …`; mode 0 → vtbl+0xc |
| **No** NPC / evaluator type-3 filter | **High** | body ends after mode-0 call; no `param_3` |
| Body store-free bool only | **High** | |
| Clean ≡ raw ≡ live Ghidra CF | **High** | re-decompile 2026-07-29 |
| Product name `FUN_0052a020` | **Tentative** | dual sealed separately as `IsObjectiveReady` |
| Proposed product name `IsMissionJournalReady` | **Probable** | role from callers “(Complete)” + journal family |
| Full retail symbol | **Open** | |

---

## 4. Sealed readiness gates

```
IsMissionJournalReady(char* this, MissionDef* mission) -> bool
  // G1 — last objective (identical to turn-in)
  lastObj = *(MissionObjective**)( *(mission+0x13c) + (uint8)(mission+0x130)*4 - 4 )

  // G2 — active-objectives hash hit with payload (identical to turn-in)
  node = CNDHash_bucket_walk( *(this+0x548), key=*(lastObj+0x10) )
  if node==0 or *(node+0x8)==0: return false

  // G3 — last objective ready (lightweight / journal mode)
  if !FUN_0052a020(this, lastObj, /*flag*/ 0): return false

  // NO G4 — no NPC type-3 filter
  return true
```

**Caller contracts (framing sealed):**

| Caller | ECX (this) | mission | Uses result for |
|---|---|---|---|
| `FUN_008a2020` @ `0x008a2032` | `DAT_00d1b6d8` (null → return 0) | stack arg | thin char-null-safe wrapper for detail panel |
| `FUN_0082a050` @ `0x0082a25f` | `DAT_00d1b6d8` | mission from selection (`+0x14c` path) | UI label `"(Complete)"` vs empty |
| `FUN_00829b20` @ `0x00829c5c` | `DAT_00d1b6d8` | mission (EDI / selection) | journal list refresh helper (`FUN_00829ac0` after) |

---

## 5. Contrast vs mode-1 turn-in `FUN_0052b420`

| Dimension | Journal `0x0052b3b0` | Turn-in `0x0052b420` |
|---|---|---|
| Stack arity / epilogue | **1** arg; `ret 4` | **2** args; `ret 8` |
| NPC parameter | **absent** | optional `npcOpt` |
| Last-obj formula | same | same |
| Active hash `+0x548` + `node+8` | same | same |
| `FUN_0052a020` flag | **`0`** (eval `vtbl+0xc`, no pending args) | **`1`** (eval `vtbl+8(char, pending)`) |
| Type-3 NPC target filter | **none** | if npc≠0: every type-3 must match NPC clonebase |
| Primary consumer | journal / “(Complete)” chrome | `ShowNpcMissionDialogUI` claim chrome `+0x64c` |
| Shared false if last obj inactive or payload null | yes | yes |

**Do not conflate:** journal ready (mode 0, no NPC) ≠ turn-in ready (mode 1 + optional NPC filter). A mission can pass journal ready while failing turn-in at the wrong NPC or under pending-aware evaluators.

---

## 6. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Last-obj LEA | **Yes** |
| Hash bucket + chain + key match | **Yes** |
| `node+8` payload gate | **Yes** |
| `FUN_0052a020(...,0)` | **Yes** |
| Five return-0 / one success path | **Yes** |
| Invented NPC filter / stores | **None** |

---

## 7. Gaps / open questions

1. Retail product symbol for this VA (proposed `IsMissionJournalReady`).
2. Product names for callers `FUN_00829b20` / `FUN_0082a050` / `FUN_008a2020` (owned as journal UI; out of scope except contracts).
3. Product name residual on `FUN_0052a020` / mode-0 vtbl+0xc English.
4. Whether any path intentionally treats journal-ready as sufficient for claim (evidence: claim path uses `0052b420` only).
5. Runtime / bit-diff vs retail EXE.

**Verdict:** Last-objective + active-hash + mode-0 readiness **sealed High**. Sibling contrast with turn-in **sealed**. Overall **accept** on CF; **accept-with-gaps** for product naming only.
