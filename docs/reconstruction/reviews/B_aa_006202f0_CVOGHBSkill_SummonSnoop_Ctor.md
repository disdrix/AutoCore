# Review B (skeptical / adversarial): `aa_006202f0` CVOGHBSkill_SummonSnoop_Ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_006202f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (R11-016) |
| **Counterpart** | `reviews/A_aa_006202f0_CVOGHBSkill_SummonSnoop_Ctor.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` + xrefs/callers. No `disassemble_bytes`. No Launcher.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Ghidra `undefined` return / empty prototype means void or no formals | **Falsified** — body returns this in EAX; `ret 0x18` seals six stack args |
| 2 | Base is still anonymous `FUN_005788d0` without identity | **Falsified as identity** — plate/RTTI: `CVOGHBSkillBase_ctor` / `.?AVCVOGHBSkillBase@@` (parent dual residual) |
| 3 | This function *is* the spawn/template execute logic | **Falsified** — body only base+vtbl; spawn/template is caller `Skill_SpawnTemplateAndStartHB` |
| 4 | Object size unknown / differs from base skill HB | **Falsified** — sole caller `operator_new(0x6c0)` |
| 5 | Auto-name via “invalid template” string is product class name | **Falsified as product name** — string lives in caller error log; class is RTTI `CVOGHBSkill_SummonSnoop` |
| 6 | Multiple independent callers construct this class | **Falsified count** — only `0x006208f4` CALL xref |
| 7 | Subclass adds fields like SpawnEntities/Virus | **Falsified** — no post-vtbl stores; pure base+vtbl |
| 8 | Product class cannot be sealed without PDB | **Falsified** — MSVC RTTI demangle `.?AVCVOGHBSkill_SummonSnoop@@` via COL |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Base→vtbl CF | **High** | Wrong HB subclass init order |
| `ret 0x18` / 6 stack args | **High** | Stack corruption if ported as ret 0 |
| RTTI class identity | **Confirmed** | Mis-name sibling skill HBs |
| Object size `0x6c0` | **High** | Wrong heap size on port |
| Design English “Snoop” | Low / open | Naming polish only |
| OnHB peer meaning | Open | Tick path mis-bound if assumed |

---

## 3. Cross-check against raw + bytes

```
mov esi, ecx                       ; this
; push param_7 .. param_2 (six dwords)
call CVOGHBSkillBase_ctor          ; E8 … → 005788d0
mov dword [esi], 009d156c          ; subclass vtbl
mov eax, esi
ret 0x18
```

Clean must **not** invent spawn loop, terrain cast, template lookup, Enqueue, or ApplyEffects — those are in `Skill_SpawnTemplateAndStartHB`, not this ctor.

RTTI chain sealed:

```
vtbl 009d156c
  [-4] COL 00aae154
    → type_info 00afed18
      → ".?AVCVOGHBSkill_SummonSnoop@@"
```

---

## 4. Surviving contract for AutoCore

```csharp
// Port shape (client skill HB action)
var hb = new CVOGHBSkill_SummonSnoop(); // size 0x6c0 retail
// base CVOGHBSkillBase fields filled from source + skill blob + target
// vtbl = SummonSnoop subclass (PTR_FUN_009d156c)
// then Enqueue(worldCtx+0xe4ec) + Start from Skill_SpawnTemplateAndStartHB
// destroy via scalar dtor if AttachOwner rejected (pOwner == null)
```

Server ports that only need summon *behavior* may not need this exact ctor; preserve **subclass vtbl** if reusing client-side HB list semantics.

---

## 5. Open questions

1. Product design / UI English for SummonSnoop.
2. Consumers of OnHB `FUN_00620340` after Start.
3. Whether any other DATA-only path constructs this class without CALL xref (none found).

**Verdict:** **accept**
