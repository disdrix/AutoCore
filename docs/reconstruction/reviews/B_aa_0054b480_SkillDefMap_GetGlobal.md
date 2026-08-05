# Review B (skeptical / adversarial): `aa_0054b480` `SkillDefMap_GetGlobal`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0054b480` |
| **VA** | `0x0054b480` |
| **Canonical name** | `SkillDefMap_GetGlobal` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0054b480_SkillDefMap_GetGlobal.md` |
| **System** | `skills-abilities` |
| **Live tools** | Ghidra `decompile_function` + `read_memory` only |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Is `Skill_GetCategoryCooldownMap` | Category map is per-entity `owner+0x6c` lazy shell; this returns fixed `&DAT_00b04734` | **Falsified** alias |
| 2 | thiscall / ECX map | No ECX use; pure `ret`; callers use return in EAX | **Falsified** thiscall |
| 3 | Returns map contents / node | Returns **header address**, not first node | **Attack fails** if claimed value-return |
| 4 | Always calls init | `jne` skips when flag ≠ 0 | **Falsified** always-init |
| 5 | Flag is skill-id / count | Single byte cmp-to-zero gate; init sets `DAT_00b04724 = 1` | **Falsified** |
| 6 | Scaffold invents CF | Live ≡ raw; 20 B bytes seal | **Attack fails** |
| 7 | Product name proven | Structural from SkillDefMap consumer family only | **Agree Open** |
| 8 | Many callees | Only optional `FUN_0054b2c0` | **Confirmed** single callee |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Lazy get `&DAT_00b04734` | **Confirmed** | Wrong skill def root → bad find/materialize |
| Leaf ABI pure `ret` | **Confirmed** | Stack imbalance if treated as thiscall |
| ≠ category cooldown map | **Confirmed** | Double-map confusion in AutoCore ports |
| Product type name | **Open** | Naming only |
| Init completeness | **Open** (callee) | Cold start missing defs if init dual wrong later |

---

## 3. Cross-check against raw / live / bytes

Decompiler:

```
if (DAT_00b04724 == 0) FUN_0054b2c0();
return &DAT_00b04734;
```

Bytes: `cmp [00b04724],0` / `jne` / `call 0054b2c0` / `mov eax,00b04734` / `ret`.

Parent usage pattern (RecvSkillStatusEffect / `FUN_005408f0`):

```
map = FUN_0054b480();
FUN_00418890(out, &skillId);   // SkillDefMap_ExactFindByIntKey with this=map
if (*out != *(map+4)) hit...
```

End sentinel is `*(header+4)` (often tied to `DAT_00b04738` family in init), **not** a "cached skill pointer" return from this leaf.

### Category-map trap (for callers)

| Helper | Root | Scope |
|--------|------|-------|
| **This unit** | `DAT_00b04734` | Global skill **definitions** |
| `Skill_GetCategoryCooldownMap` | `owner+0x6c` | Per-entity category CD map |

CHANGE_LOG already notes residual surface: `FUN_0054b480` global map **≠** GetCategoryCooldownMap — dual **confirms**.

---

## 4. Surviving contract for AutoCore

```
SkillDefMap_GetGlobal():
  if (!g_skillDefMapInited):   // DAT_00b04724
      SkillDefMap_InitLoad()   // FUN_0054b2c0
  return &g_skillDefMap        // DAT_00b04734

AutoCore must NOT:
  - treat return as a skill* node
  - conflate with entity category-cooldown map
  - invent thiscall / stack args
  - skip lazy init on cold client
```

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| Lazy get global SkillDefMap header | **Agree Confirmed** |
| 20 B / pure ret / flag gate | **Agree Confirmed** |
| accept (naming residual only) | **Agree** |
| Structural name `SkillDefMap_GetGlobal` | **Agree** structural; product English **Open** |

---

## 6. Open questions

1. Product/STL name of header type.
2. Whether any path zeroes `DAT_00b04724` after first init (reload).
3. Runtime golden.

**Verdict:** **accept** — adversarial pass; no CF contradictions.
