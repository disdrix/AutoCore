# Review B (skeptical / adversarial): `aa_0053c660` CNDHash_Insert

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053c660` |
| **VA** | `0x0053c660` |
| **Canonical name** | `CNDHash_Insert` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0053c660_CNDHash_Insert.md` |
| **System** | container / missions-progression |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is a unique algorithm vs `0053c360` | Side-by-side decompile: only vtbl imm differs | **Falsified** unique CF — **vtbl twin only** |
| 2 | Can alias / redirect GiveMission sites to `0053c360` | Different node vtbl → different methods / ownership | **Falsified** redirect-safe |
| 3 | Inserts mission **def** like +0x540 path | Residual: payload is 0x30 blob from `operator_new` + `FUN_004111f0` | **Falsified** def payload |
| 4 | Targets same hash as active mission | GiveMission ECX = `char+0x530`, not +0x540/+0x544 | **Falsified** same-hash |
| 5 | `allowDuplicate` multi-insert | Soft return 1 without link | **Falsified** |
| 6 | Lock aborts | Log only | **Falsified** |
| 7 | Only GiveMission uses this VA | Also ApplyCreateFromPacket xref | **Falsified** exclusivity; **agree** rare (2 xrefs) |
| 8 | Freelist is operator_new | Slab freelist | **Falsified** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Twin-of-insert CF | **Confirmed** | Invented special logic |
| Vtbl 009cefe4 distinct | **Confirmed** | Cross-wire node methods |
| +0x530 state-blob role | **High** | Bind wrong object into active hash |
| HRESULTs / soft policy | **Confirmed** | |
| Hash/node layout | **High** | |
| Blob field meanings | **Open** | Wrong 0x30 layout on port |
| Runtime | **Open** | |

---

## 3. Cross-check

```
raw/clean ≡ live (2026-07-29).

CF delta vs 0053c360:
  *puVar3 = &PTR_FUN_009cefe4;   // ONLY structural difference

Xrefs (2):
  005329e2  CVOGReaction_GiveMission          — char+0x530, 0x30 blob
  005354e6  CVOGCharacter_ApplyCreateFromPacket

Vtbl 009cefe4 first methods:
  0x00537510, 0x00aad100, 0x00537550, 0x00aad148
≠ 009cf024 first methods:
  0x00537cf0, 0x00aad338, 0x00537d10, ...
```

### Critical traps

1. **Do not** implement one shared `CNDHash_Insert` that stamps a single hard-coded vtbl for all call sites — mission active vs state-blob need different node types.
2. **Do not** store mission def pointer into `+0x530` using this path’s callers — blob is separate 0x30 init.
3. Soft-flag is still soft-skip, not multi-map.

---

## 4. Surviving contract for AutoCore

```
CNDHash_Insert_0053c660(hash, key, value, softIfExists) -> int
  // identical policy to 0053c360 / 0053c560
  // node vtbl MUST be 009cefe4

GiveMission:
  hash = char+0x530
  key  = *missionDef
  value = allocated 0x30 state blob (FUN_004111f0 init)
  soft = 0

AutoCore must NOT:
  - redirect this VA to 0053c360/0053c560
  - put mission def into +0x530 via this insert family without matching blob shape
  - treat CF differences beyond vtbl as real
```

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| Identical CF except vtbl | **Agree Confirmed** |
| Signature + HRESULTs + soft | **Agree** |
| +0x530 / 0x30 blob | **Agree High** |
| Layout shared with twin | **Agree** |
| accept-with-gaps | **Agree** |

Disputes: none.

---

## 6. Open questions

1. Semantics of each `009cefe4` method (dtor / serialize).
2. Exact 0x30 blob field map beyond residual init pattern.
3. ApplyCreateFromPacket hash root offset (likely +0x530 or sibling).
4. Runtime / bit-exact.

**Verdict:** **accept-with-gaps** — agree with A; **block twin merge and def-vs-blob payload confusion**.
