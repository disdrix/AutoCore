# Review B (skeptical / adversarial): `aa_0053c460` CNDHash_Insert

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053c460` |
| **VA** | `0x0053c460` |
| **Canonical name** | `CNDHash_Insert` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0053c460_CNDHash_Insert.md` |
| **System** | container / missions-progression |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is a unique algorithm vs `0053c360` / `0053c760` | Side-by-side decompile: only vtbl imm differs | **Falsified** unique CF — **vtbl twin only** |
| 2 | Can alias / redirect AddActiveObjective sites to `0053c360` | Different node vtbl (`009cf02c` vs `009cf024`) → different methods / ownership | **Falsified** redirect-safe |
| 3 | Same hash as twin `0053c760` state insert | Residual: this VA ECX=`char+0x548`; twin ECX=`char+0x55c` | **Falsified** same-hash |
| 4 | Inserts objective **state node** | Residual: push ESI=objDef into value; state node uses `0053c760` | **Falsified** state payload |
| 5 | `allowDuplicate` multi-insert | Soft return 1 without link | **Falsified** |
| 6 | Lock aborts | Log only | **Falsified** |
| 7 | Only AddActiveObjective uses this VA | Also ApplyCreateFromPacket + two grant helpers (4 xrefs) | **Falsified** exclusivity; **agree** primary plate is AddActiveObjective |
| 8 | Freelist is operator_new | Slab freelist `FUN_0053ada0` | **Falsified** |
| 9 | Same vtbl as mission active insert `0053c360` | Body writes `PTR_LAB_009cf02c`; twin uses `009cf024` | **Falsified** shared vtbl |
| 10 | Scaffold alias `Named_VOG_DEBUG_STOP` is the product name | String is debug stop only; role is CNDHash insert | **Falsified** as identity |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Twin-of-insert CF | **Confirmed** | Invented special logic |
| Vtbl 009cf02c distinct | **Confirmed** | Cross-wire node methods with 009cf024 |
| +0x548 active-objective def role | **High** | Bind state node into def hash |
| HRESULTs / soft policy | **Confirmed** | |
| Hash/node layout | **High** | |
| Secondary caller hash roots | **Open** | Wrong create/grant map |
| Runtime | **Open** | |

---

## 3. Cross-check against raw / live / twins

```
raw/clean scaffold CF ≡ live decompile (2026-07-29).

HRESULT:
  null value  → 0x80004003 (E_POINTER)
  hard dup    → 0x80004005 (E_FAIL)
  soft hit    → 1
  success     → 0

Xrefs (4):
  00531b15  CVOGMission_AddActiveObjective     — char+0x548, objDef
  00535465  CVOGCharacter_ApplyCreateFromPacket
  0060bad8  FUN_0060b870
  0060bd87  FUN_0060bb80

Strings:
  "HashError:insert, already locked for traversal"
  "VOG_DEBUG_STOP"
  "Duplicate hash insert %u, failing out"

Vtbl family (this VA): PTR_LAB_009cf02c
  read_memory[0] = 0x00537d10 (method 0)
≠ 009cf024 first method 0x00537cf0 (mission-def twin)
≠ 009cefec first method 0x00537550 (objective-state twin 0053c760)

CF delta vs 0053c360 / 0053c760:
  *puVar3 = &PTR_LAB_009cf02c;   // ONLY structural difference vs each twin
```

### Soft-flag trap

Do **not** implement `allowDuplicate` as “push another node with same key.” Policy is soft-skip return 1. Known AddActiveObjective site passes soft=`0`.

### Twin / paired-hash traps

- Do **not** redirect `0x0053c760` call sites to this VA (vtbl + hash root differ).
- Do **not** redirect `0x0053c360` GiveMission sites here (mission active +0x540 family vs objective +0x548).
- AddActiveObjective pairs **def** insert (this VA → `+0x548`) with **state** insert (`0053c760` → `+0x55c`).

### Allocator trap

`FUN_0053ada0` is freelist/slab, not `operator_new`. Plain malloc desyncs the pool.

---

## 4. Surviving contract for AutoCore

```
CNDHash_Insert_0053c460(hash, key, value, softIfExists) -> int
  value==null           -> 0x80004003
  softIfExists && hit   -> 1   (no mutation)
  !soft && hit          -> 0x80004005 (+ log)
  else                  -> alloc node (vtbl 009cf02c), bucket head-insert,
                           list append, count++, return 0

// lock +0x1d: log only

Node (0x1c):
  +00 vtbl(009cf02c)  +04 touch  +08 value*  +0c bucketNext  +10 key
  +14 listNext  +18 listPrev

Hash (partial):
  +08 mask  +0c count  +10 buckets*  +14 listHead  +18 listTail  +1d lock

AddActiveObjective ownership:
  +0x548 active objective DEF hash (this VA)
  +0x55c pending objective STATE hash uses twin 0053c760 — NOT this VA

AutoCore must NOT:
  - treat allowDuplicate as multi-map insert
  - abort on lock without logging
  - merge twin insert VAs / vtbls (009cf02c vs 009cefec vs 009cf024)
  - store state node into +0x548 via this VA
  - use operator_new for these nodes
```

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| Signature thiscall key/value/flag → int | **Agree High** |
| HRESULTs E_POINTER / E_FAIL | **Agree Confirmed** |
| Soft-skip semantics | **Agree High** |
| Lock warn-only | **Agree High** |
| Layout + node 009cf02c | **Agree High** |
| Twin family same CF, different vtbl | **Agree Confirmed** |
| +0x548 def insert from AddActiveObjective | **Agree High** |
| Freelist this-offset Open | **Agree** |
| clean ≡ raw ≡ live | **Agree** |
| accept-with-gaps | **Agree** |

Disputes: none on sealed CF. Prefer soft-skip wording over literal “allow duplicate.”

---

## 6. Open questions

1. Freelist header offset for `FUN_0053ada0` ECX (remove seals reclaim at `+0x20` — likely related).
2. Product English for `char+0x548` / full objective lifecycle.
3. Whether any site calls this VA with soft ≠ 0 (static AddActiveObjective: hard only).
4. Full method table at `009cf02c` beyond method0.
5. Exact `this` offsets at ApplyCreateFromPacket / grant helpers.
6. Runtime / bit-exact.

**Verdict:** **accept-with-gaps** — agree with A; **block twin merge, def-vs-state payload confusion, and multi-insert misread**.
