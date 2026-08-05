# Review B (skeptical / adversarial): `aa_005408f0` `FxCache_EnsureMasterAndResolve`

| Field | Value |
|---|---|
| **Stable ID** | `aa_005408f0` |
| **VA** | `0x005408f0` |
| **Canonical name** | `FxCache_EnsureMasterAndResolve` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005408f0_FxCache_EnsureMasterAndResolve.md` |
| **System** | `client-fx` / skills-abilities |
| **Live tools** | Ghidra `decompile_function` + `read_memory` only |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Is pure hash lookup leaf | Body loads master + calls 004a16d0 | **Falsified** pure-lookup |
| 2 | `CNDHash_LookupByKey` call | Inline walk only (no call) | **Agree** — inlined |
| 3 | GetGlobal takes map/key args | Leaf dual: pure ret; fake decompiler args | **Falsified** as real args |
| 4 | FUN_004a16d0 this = eventA (param_3) | Exit: `lea ecx,[esi+4]` after ESI=value | **Falsified** decompiler this |
| 5 | Always LoadMaster | Only when `value[+0x0a]==0` and map hit | **Falsified** always-load |
| 6 | Same as 00542790 apply path | No vtbl attach, no SEH, no `_nfx` append here | **Falsified** equivalence |
| 7 | Product name proven | Structural from callees only | **Agree Open** |
| 8 | Scaffold invents CF | Live ≡ raw 2026-07-23 | **Attack fails** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Inline hash + miss→0 | **Confirmed** | Wrong cache root → silent FX miss |
| Master gate + SkillDef→XML | **Confirmed** | Double-load / never-load masters |
| `ret 0x0c` ABI | **Confirmed** | Stack imbalance if treated as 4-arg cdecl |
| 004a16d0 this = value+4 | **Confirmed** | Wrong FxMaster object |
| English / event semantics | **Open** | Naming / server port docs only |
| LoadMaster failure ignored | **High** (body) | Continues to resolve even if XML fail |

---

## 3. Cross-check against raw / live / bytes

Decompiler CF matches live. Key byte corrections vs naive decompiler read:

```
// NOT: FUN_004a16d0(this=eventA, ...)
// YES: ECX = hash_value + 4; stack (eventA, eventB, -1)
```

SkillDefMap pattern (same as RecvSkillStatusEffect / dual GetGlobal):

```
map = SkillDefMap_GetGlobal();
ExactFind(out, &key);
if (out != *(map+4))  // not end
    materialize + LoadMaster
```

Parent `FUN_00512d10` uses this when `param_9==null` and **not** on the “live resource subsystem” branch that calls `00542790` — complementary paths, not duplicates.

---

## 4. Surviving contract for AutoCore

```
FxCache_EnsureMasterAndResolve(host, key, eventA, eventB):
  value = hash_find(*(host+0xf0c), key)   // inline CNDHash
  if !value: return 0
  if value.masterLoadedFlag == 0:
      def = SkillDefMap.exactFind(key)
      if def:
          name = materialize(def)
          FxMaster_LoadMasterFromXML(name)  // may append _nfx.xml itself
  return FxResolve(value+4, eventA, eventB, -1)  // FUN_004a16d0

AutoCore must NOT:
  - invent a call to CNDHash_LookupByKey here (inlined)
  - treat GetGlobal as thiscall with key
  - pass eventA as FUN_004a16d0 this
  - assume LoadMaster failure aborts (body does not)
  - conflate with FxCache_ApplyWithNfxEnsure attach path
```

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| ensure master + resolve | **Agree High** |
| 193 B / ret 0x0c / +0xf0c hash | **Agree Confirmed** |
| value+4 this for 004a16d0 | **Agree Confirmed** (bytes beat decompiler) |
| accept-with-gaps | **Agree** |
| structural name | **Agree** INFERRED; product **Open** |

---

## 6. Gaps (B list)

1. Product English.
2. Whether `value+0x0a` is set by LoadMaster or by resolve (not proven in-body).
3. Runtime golden.
4. Dual completeness of `FUN_004a16d0`.

**Verdict:** **accept-with-gaps** — adversarial checks reinforce ABI/this corrections; no CF rewrite needed.
