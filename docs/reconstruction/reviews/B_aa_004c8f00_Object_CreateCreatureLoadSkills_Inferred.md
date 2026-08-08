# Review B (skeptical / adversarial): `aa_004c8f00` Object_CreateCreatureLoadSkills_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c8f00` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY WQ9E-H) |
| **Counterpart** | `reviews/A_aa_004c8f00_Object_CreateCreatureLoadSkills_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Ghidra `__fastcall` free function | **Falsified** — `MOV EDI,ECX`; entry only via this-adjust JMP thunks |
| 2 | Sole recreate site of skill hash | **Falsified** — second site; primary is `Object_CreateOrRecreateSkillHash` |
| 3 | Recreate log2 is skill-id / dynamic | **Falsified** — imm **`PUSH 2`** @ `0x004c902a` |
| 4 | TraversalLock aborts recreate/walk | **Falsified** — logs then **continues** (same soft-lock family as recreate dual) |
| 5 | This function IS the CBID factory | **Falsified** — factory is callee `0x0051b230`; this casts + loads skills |
| 6 | Product name from RTTI string alone | **Overstated** — RTTI proves type, not method English; keep `_Inferred` |
| 7 | Alias Mission_CVOGClonedObjectBase_RTTI_* | **Reject** — domain_fun rename noise |
| 8 | Dest hash at owner+0x70 | **Holds** — `[EDX+ESI+0x74]` ≡ primary_adj+0x70 (WQ9D sealed) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall + creature return | **High** | Wrong port ABI |
| log2=2 recreate | **High** | Wrong dest skill table size |
| Soft lock on traverse | **High** | Wrong abort semantics |
| Skill field offsets 0x5fc / 0x5f6 | **High** | Wrong skill identity load |
| Product method English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against recreate dual + factory dual

```
Object_CreateCreatureLoadSkills_Inferred (this)
  └─ Object_CreateFromEmbeddedCbid_Inferred (source MI -0x4fc)
  └─ __RTDynamicCast → CVOGCreature*
  └─ SkillCNDHash_Recreate_Inferred(destHash, log2=2)   // second CODE site
  └─ lock source hash @+0x1d; ordered walk +0x14; Skill_EnsureLoadedInTree
```

ADV_wq9d_spotcheck already accepted second recreate caller with imm 2 — matches live `6A 02; E8 … 004cbdc0`.

---

## 4. Surviving contract for AutoCore

```
// Port as creature clone virtual (not bare free function):
creature = Object_CreateCreatureLoadSkills_Inferred(sourceThis);
// Must: factory via embedded CBID, dynamic_cast to creature, copy combat fields,
// always SkillCNDHash_Recreate(dest+0x70, 2), then traverse source+0x70 with
// TraversalLock soft-fail semantics, Skill_EnsureLoadedInTree per skill payload.
// Do not merge with Object_CreateOrRecreateSkillHash (different host/path).
// Reject inventory CNDHash ABI.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/recreate site/lock semantics. Product English residual → **accept-with-gaps**.
