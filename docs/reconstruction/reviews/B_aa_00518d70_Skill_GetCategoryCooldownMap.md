# Review B (skeptical / adversarial): `aa_00518d70` Skill_GetCategoryCooldownMap

| Field | Value |
|---|---|
| **Stable ID** | `aa_00518d70` |
| **VA** | `0x00518d70` |
| **Review type** | Skeptical / adversarial residual strengthen |
| **Date** | `2026-07-29` (prior scaffold `2026-07-23`) |
| **Counterpart** | `reviews/A_aa_00518d70_Skill_GetCategoryCooldownMap.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept** on CF; **owner class name** residual; do not overclaim singleton / skill-as-host |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Computes remaining category CD | Body returns map pointer only | **Falsified** |
| 2 | Always preallocated at object construct | Null-check + lazy `operator_new` | **Falsified** |
| 3 | Global singleton map | Storage is **`this+0x6c`** | **Falsified / overstated** |
| 4 | Map lives on **skill runtime** (`skill+0x6c`) | Cast-again dual: ECX=**owner** (EDI); status-effect uses character this-adjust | **Falsified as general rule** — host is cast-owner / character slot |
| 5 | This function inserts category entries | Insert is `Skill_CategoryCooldownMap_Insert` / `Skill_InsertCategoryCooldown` | **Falsified** |
| 6 | Twin `FUN_00518c20` proves same node type | Same 0xC shell; **different** factory (`0x1c` vs `0x30`, flag `+0x19` vs `+0x29`) | **Structure twin only** — not same map type |
| 7 | Name needs leave-FUN / demote | Plate + symbol already `Skill_GetCategoryCooldownMap`; consumers are category CD | **Reject demote** — name holds |
| 8 | `FUN_005ae2b0` is full map ctor with comparator | Only allocates/zeros **0x1c** sentinel; parent links head | **Overstated if called “map construct”** — **head factory** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| `+0x6c` slot | **Confirmed** | Wrong field / crash / silent wrong map |
| Lazy 0xC header + empty tree | **Confirmed** | Null deref on first CD op |
| Head factory `FUN_005ae2b0` → 0x1c, flag +0x19 | **Confirmed** | Wrong node size vs insert/remaining |
| No CD arithmetic here | **Confirmed** | Mis-place remaining/insert logic |
| Host = owner/character-side object (not skill) | **High** | Server/client map on wrong object |
| Product class of host | **Tentative / Open** | Wrong AutoCore field ownership |
| Exact `std::map` template spelling | **Medium** | Type-system overfit |
| All 8 xrefs category-CD related | **High** | Hidden non-CD use (none observed) |

---

## 3. Xref challenge (must not collapse)

**8** call sites / **4** functions:

| Function | Sites | Role |
|---|---|---|
| `Skill_InsertCategoryCooldown` | 1 | high-level insert API |
| `Skill_GetCategoryCooldownRemaining` | 3 | query + expire erase |
| `CVOGHBOKToCastAgain_ctor` | 1 | arm category on cast-again start |
| `Client_RecvSkillStatusEffect` | 3 | abort/erase on error; item-skill map touch |

Any narrative that this is “only cast-again” or “only InsertCategoryCooldown” is **wrong**. Any narrative that LocalCastValidate owns this map is **wrong** (that’s the **`+0x68`** twin).

---

## 4. Cross-check against raw / bytes

```
if *(owner+0x6c)==0:
  hdr = new(0xc) or null
  if hdr: head=FUN_005ae2b0(); hdr+4=head; head+0x19=1; self-link; hdr+8=0
  *(owner+0x6c)=hdr
return *(owner+0x6c)
```

- Clean scaffold ≡ raw ≡ live decompile ≡ `read_memory` CF.
- SEH-only globals — no string rename pressure / no demotion pressure.
- `mov ecx,esi` before `FUN_005ae2b0`: factory decompile does **not** use ECX; treat as dead/thiscall noise, not a second formal on the getter.

---

## 5. What is safe vs unsafe for AutoCore

| Safe | Unsafe |
|---|---|
| One category-CD map pointer per map-owner at **`+0x6c`** | Claiming skill object hosts the map |
| Lazy create; never invent CD rows in this helper | Pre-create map in character ctor without proving it |
| Pair Insert / Remaining / cast-again / status abort on same getter | Sharing this map with active-cast bindings (`+0x68`) |
| Node value: key +0xc, start +0x10, duration +0x14 (from consumers) | Sealing product name of `FUN_005ae2b0` without string/RTTI |
| Name `Skill_GetCategoryCooldownMap` retained | Renaming twin `FUN_00518c20` by analogy alone |

### Surviving contract

```
GetCategoryCooldownMap(owner):
  lazy std::map-like shell at owner+0x6c
  empty head via FUN_005ae2b0 (0x1c); size 0
  return map*
AutoCore: category CD map lives on cast-owner (+0x6c), not on skill runtime;
          twin slot +0x68 is a different map (active-cast bindings; leave-FUN)
```

---

## 6. CF challenge of Review A

| A claim | B |
|---|---|
| Lazy null-check / alloc / return | **Agree Confirmed** |
| Header +4 head / +8 size | **Agree Confirmed** |
| `FUN_005ae2b0` head 0x1c / +0x19 | **Agree Confirmed** |
| Accessor-only (no CD math) | **Agree Confirmed** |
| Twin of `FUN_00518c20` structure | **Agree High** — **not** same node layout |
| Host is owner not skill | **Agree High** from cast-again dual + status-effect this-adjust; **not** a sealed product class name |
| accept name as-is | **Agree** |
| Gaps: owner class, factory name | **Agree Open** |

---

## 7. Residual risks

1. **Owner product class** still open — AutoCore must not invent a field name beyond “cast-owner / character-side object +0x6c” without RTTI/string.
2. Ghidra still decompiles some call sites as `GetCategoryCooldownMap(skill)` — **do not** let that override asm duals that prove owner.
3. OOM path stores **null** at `+0x6c` and returns null — callers must tolerate (retail likely assumes alloc succeeds).
4. Header `+0` unwritten — do not invent allocator fields without further RE.
5. Runtime verification not run this pass.

**Verdict:** **accept** on CF and layout. **Owner class name** + **`FUN_005ae2b0` product name** residual. Name **kept**. Do not merge with `+0x68` active-cast map.
