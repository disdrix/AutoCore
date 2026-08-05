# Review B (skeptical / adversarial): `aa_00541aa0` Client_LoadSkillsFX

| Field | Value |
|---|---|
| **Stable ID** | `aa_00541aa0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W23-F) |
| **Counterpart** | `reviews/A_aa_00541aa0_Client_LoadSkillsFX.md` |
| **Scratch** | `tmp/a_00541aa0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | No-arg free function (decompiler) | **Falsified** — `mov ebp,ecx`; host+0xF0C used |
| 2 | Loads **all** skills unconditionally | **Falsified** — empty string@+0x5B6 skips |
| 3 | Inserts into SkillDefMap itself | **Falsified** — reads SkillDefMap; writes **CNDHash** host+0xF0C |
| 4 | `FUN_004a1620` constructs whole 0xC block | **Falsified** — ctor on **entry+4** only (8 B catalog) |
| 5 | String test is equality to empty via strcmp | **Overstated** — pointer end ≠ start+1 (strlen>0) |
| 6 | Multiple callers | **Falsified** — sole xref `FUN_00541e70` |
| 7 | Name is inventable without parent | **Risk** mitigated — parent log `"LoadSkillsFX"` seals |
| 8 | Hash flag 0 means “overwrite” | **Falsified** by `FUN_00545890` body — flag 0 still rejects duplicates |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| LoadSkillsFX role | **High** | Wrong content-load phase model |
| thiscall host / +0xF0C | **High** | Wrong hash target |
| SkillDef walk + string gate | **High** | Miss FX bindings |
| Entry layout 0xC | **High** | Corrupt catalog |
| Product string@+0x5B6 meaning | **Medium** | Wrong asset key interpretation |
| Full SkillDef layout | **Open** | Future consumers |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
this = ECX (host)
map = SkillDefMap_GetGlobal()
for node in inorder(map) with isnil@+0x641:
  if strlen(node+0x5B6) > 0:
    e = new(0xC)
    if e: FxMasterCatalog_Ctor(e+4)
    e->skillId = node->key@+0xC
    CNDHash_Insert(*(host+0xF0C), skillId, e, flag=0)
plain ret + SEH
```

Parent sequence:
```
"before LoadSkillsFX and SpecialFXMaster"
FUN_00541aa0()   // this unit
FUN_004a6790()   // SpecialFX master (not OWN)
"after LoadSkillsFX and SpecialFXMaster"
```

Live decompile ≡ raw CF; ABI corrected from bytes.

---

## 4. Surviving contract for AutoCore

```
// Client content load — skills FX hash population
Client_LoadSkillsFX(host):
  for each SkillDef with non-empty string@+0x5B6:
    bind skillId → new SkillFxEntry{id, FxMasterCatalog}

// Do not call as free function — requires host with CNDHash* @ +0xF0C.
// Do not treat as SkillDefMap mutator.
// Empty FX string skills are intentionally skipped.
```

---

## 5. Verdict

Adversarial pass **confirms** A on CF/ABI/role; open product field names and nested hash dual → **accept-with-gaps**.
