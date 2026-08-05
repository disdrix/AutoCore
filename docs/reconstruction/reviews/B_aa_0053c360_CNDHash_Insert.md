# Review B (skeptical / adversarial): `aa_0053c360` CNDHash_Insert

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053c360` |
| **VA** | `0x0053c360` |
| **Canonical name** | `CNDHash_Insert` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0053c360_CNDHash_Insert.md` |
| **System** | container / missions-progression |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | `allowDuplicate` means multi-value / multi-node same key | Soft path returns 1 **without** linking a second node; hard path fails on hit | **Falsified** multi-insert — soft-skip only |
| 2 | Locked traversal aborts insert | Body logs then falls through | **Falsified** hard abort — warn-only |
| 3 | Double GiveMission call is same-hash accidental double | Residual asm: second site ECX=`char+0x544`, not `+0x540`; end-quest removes both | **Falsified** accidental double — **paired hashes** |
| 4 | This VA is the only CNDHash insert | Twins `0053c660` / `0053c560` same CF, different vtbl | **Falsified** exclusivity |
| 5 | Same vtbl as continent unlock insert | This body writes `PTR_LAB_009cf024`; `0053c560` uses `009cefd4` | **Falsified** shared vtbl |
| 6 | Same vtbl as state-blob insert | `0053c660` uses `PTR_FUN_009cefe4` | **Falsified** |
| 7 | `FUN_0053ada0()` is parameterless global malloc | Freelist/slab carve 0x1c; ECX elided | **Attack partial** — role High; ECX Open |
| 8 | `FUN_00537d30` is rehash / grow | Walks bucket chain marking touch; integrity | **Falsified** grow |
| 9 | List links are bucket links | Bucket `+0x0c`; list `+0x14/+0x18` | **Attack fails** — dual linkage sealed |
| 10 | GiveMission always inserts both +0x540 and +0x544 | Secondary insert gated (mode + def fields) | **Attack partial** — first insert High; second conditional High |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Insert role + HRESULT returns | **Confirmed** | Wrong null/dup handling |
| Soft vs hard duplicate policy | **High** | Port multi-insert bug |
| Hash fields +8/+c/+10/+14/+18/+1d | **High** | Corrupt wrong offsets |
| Node layout 0x1c + vtbl 009cf024 | **High** | Wrong dtor / ownership |
| Bucket head-insert sentinel+4 | **High** | Break Lookup |
| Paired +0x540/+0x544 call sites | **High** | Drop sibling hash on grant |
| Twin insert VAs separate | **High** | Merge mission vs blob node types |
| Freelist this-offset | **Open** | Wrong allocator context |
| Runtime | **Open** | No live insert capture |

---

## 3. Cross-check against raw / live / twins

```
raw/clean scaffold CF ≡ live decompile (2026-07-29).

HRESULT:
  null value  → 0x80004003 (E_POINTER)
  hard dup    → 0x80004005 (E_FAIL)
  soft hit    → 1
  success     → 0

Xrefs (6):
  00532915 / 0053294d  CVOGReaction_GiveMission  (+0x540 / +0x544)
  005346dc             CVOGReaction_CompleteObjective
  00535174 / 00535416  CVOGCharacter_ApplyCreateFromPacket
  0060ba84             FUN_0060b870

Strings:
  "HashError:insert, already locked for traversal"
  "VOG_DEBUG_STOP"
  "Duplicate hash insert %u, failing out"

Vtbl family (this VA): PTR_LAB_009cf024
  read_memory[0] = 0x00537cf0 (method 0)
```

### Soft-flag trap

Do **not** implement `allowDuplicate` as “push another node with same key.” Policy is soft-skip return 1. Known GiveMission sites pass soft=`0`.

### Twin / paired-hash traps

- Do **not** redirect `0x0053c660` or `0x0053c560` call sites to this VA (vtbl differs).
- Do **not** treat second GiveMission insert as bug — it targets **`char+0x544`**.
- End-quest (`FUN_005307e0`) removes both +0x540 and +0x544 for same mission id — confirms pair.

### Allocator trap

`FUN_0053ada0` is freelist/slab, not `operator_new`. Plain malloc desyncs the pool (remove pushes to `hash+0x20` freelist).

---

## 4. Surviving contract for AutoCore

```
CNDHash_Insert_0053c360(hash, key, value, softIfExists) -> int
  value==null           -> 0x80004003
  softIfExists && hit   -> 1   (no mutation)
  !soft && hit          -> 0x80004005 (+ log)
  else                  -> alloc node (vtbl 009cf024), bucket head-insert,
                           list append, count++, return 0

// lock +0x1d: log only

Node (0x1c):
  +00 vtbl(009cf024)  +04 touch  +08 value*  +0c bucketNext  +10 key
  +14 listNext  +18 listPrev

Hash (partial):
  +08 mask  +0c count  +10 buckets*  +14 listHead  +18 listTail  +1d lock

GiveMission ownership:
  +0x540 primary active mission hash (this VA)
  +0x544 sibling active hash (this VA, conditional)
  +0x530 state-blob hash uses twin 0053c660 — NOT this VA

AutoCore must NOT:
  - treat allowDuplicate as multi-map insert
  - abort on lock without logging
  - merge twin insert VAs / vtbls
  - collapse +0x540/+0x544 into one map without dual remove
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
| Layout + node 009cf024 | **Agree High** |
| Twin family separate | **Agree High** |
| +0x540/+0x544 paired inserts | **Agree High** |
| Freelist this-offset Open | **Agree** |
| clean ≡ raw ≡ live | **Agree** |
| accept-with-gaps | **Agree** |

Disputes: none on sealed CF. Prefer soft-skip wording over literal “allow duplicate.”

---

## 6. Open questions

1. Freelist header offset for `FUN_0053ada0` ECX (remove seals reclaim at `+0x20` — likely related).
2. Product English for `char+0x544`.
3. Whether any site calls this VA with soft ≠ 0 (static grant sites: hard only).
4. Full method table at `009cf024`.
5. Runtime / bit-exact.

**Verdict:** **accept-with-gaps** — agree with A; block multi-insert misread, twin merge, and single-map collapse of +0x540/+0x544.
