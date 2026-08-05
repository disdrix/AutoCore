# Review B (skeptical / adversarial): `aa_00509940` GetModifierSkillID

| Field | Value |
|---|---|
| **Stable ID** | `aa_00509940` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W23-P) |
| **Counterpart** | `reviews/A_aa_00509940_GetModifierSkillID.md` |
| **Verdict** | **accept-with-gaps** on sealed CF; reject listed false claims |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This **is** `CVOGLootGenerator::GetTypeFromIDPrefix` | Shared miss string | **Falsified** — default path string is **`GetModifierSkillID()…`**; GetTypeFromIDPrefix string only on map miss |
| 2 | Free function, no `this` | Decomp signature | **Falsified** — `mov edi,ecx`; helpers called with `mov ecx,edi` |
| 3 | `__cdecl` / no stack cleanup | Signature noise | **Falsified** — **`ret 4`** |
| 4 | Miss on matched type returns immediately 0 | Natural expectation | **Falsified** — **fallthrough** to later case helpers before default `-1` |
| 5 | Returns entry pointer | Table helper return | **Falsified** — returns **`*(entry+0x9c)`** skill id |
| 6 | Same as HandlerTable58 alone | Nested dual confusion | **Falsified** — dispatcher over six tables + map |
| 7 | Type codes equal equip subtypes 0xa/0xb | Equip dual numbers | **Not sealed** — here types include 0x44/0x46/0x1C…; equip dual maps **helpers** to subtypes, not these case values |
| 8 | Bit-exact / runtime verified | Static dual only | **Fail** if claimed |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Product name GetModifierSkillID | **High** | Wrong API surface |
| thiscall registry + ret 4 | **High** | Stack imbalance |
| Map node+0x10 type; entry+0x9c skill | **High** | Wrong field port |
| Fallthrough-on-miss | **High** | Over-strict port returns -1 too early |
| Type English taxonomy | **Low** | Doc only |
| Intentional multi-table failover | **Med** | Behavior change if broken |

---

## 3. Cross-check against raw / bytes

```text
// decompiler switch cases 0xC, 0x1C, 0xA, 0xE, 0x46, 0x44 + default -1
// prologue: push ecx/esi; mov esi,[esp+0xC]; push edi; mov edi,ecx
// map: mov ecx, 0x00b041dc; call Map_LowerBoundFindByIntKey
// helpers: push esi; mov ecx,edi; call FUN_00508*
// success: mov eax,[eax+0x9c]; pop edi/esi/ecx; ret 4
// default: log GetModifierSkillID; or eax,-1; ret 4
// MATCH raw; ABI residual only.
```

**Attack on “this is GetTypeFromIDPrefix”:** **Fails** — product default string names GetModifierSkillID; map-miss string is shared plate reuse.

**Attack on “strict switch with break on miss”:** **Fails** — empty miss path falls into next case body.

---

## 4. Surviving contract for AutoCore

```
GetModifierSkillID(registry, idPrefix) -> int32:
  it = map_lower_bound(g_map_b041dc, idPrefix)
  if it == end:
    if idPrefix != 0: log GetTypeFromIDPrefix-miss plate
    type = 0
  else:
    type = it.node.type_at_0x10

  // fallthrough-on-miss across:
  //   0xC→00508ac0, 0x1C→00508b10, 0xA→00508b60,
  //   0xE→00508bb0, 0x46→00508c00, 0x44→00508c50
  for each applicable case body in layout order starting at type:
    entry = HandlerTableFind(registry, idPrefix)
    if entry: return entry.skill_at_0x9c

  log "GetModifierSkillID() passed an invalid IDPrefix: %i\n"
  return -1
```

**Port tests:**

* Return `-1` (not 0) on total failure.  
* Map miss with prefix 0 skips miss log but still fails default.  
* Success field is **`+0x9c`**, not `+0x6c` (id) or entry pointer.  
* Preserve fallthrough: a type-0xC miss may still hit a later table.  
* Registry `this` required — not a free function.

---

## 5. Open questions

1. Registry class name / vtbl.  
2. Type code taxonomy vs loot/equip domains.  
3. Whether fallthrough failover is design or accidental empty-case codegen (observable either way).  
4. Runtime corpus of prefix→skill pairs.
