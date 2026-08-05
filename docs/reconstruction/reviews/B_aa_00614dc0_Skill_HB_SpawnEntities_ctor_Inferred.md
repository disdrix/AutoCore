# Review B (skeptical / adversarial): `aa_00614dc0` Skill_HB_SpawnEntities_ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00614dc0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W25-N) |
| **Counterpart** | `reviews/A_aa_00614dc0_Skill_HB_SpawnEntities_ctor_Inferred.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Ghidra signature with 6 formals + this is wrong / incomplete | **Survives** — `ret 0x18` + stack pushes match 6 formals; ECX is this |
| 2 | Base call is still anonymous `FUN_005788d0` without RTTI | **Falsified as identity** — plate/RTTI: `CVOGHBSkillBase_ctor` / `.?AVCVOGHBSkillBase@@` |
| 3 | This function *is* the spawn execute logic | **Falsified** — body only base+vtbl+ushort; execute is vtbl+0x2c @ `00615020` |
| 4 | Object size is unknown | **Falsified** — sole caller `operator_new(0x6d0)` |
| 5 | Auto-name via “invalid creature” string is product class name | **Falsified as product name** — string is in execute path logs, not this ctor |
| 6 | Field `param_1[0x1b1]` is a dword | **Falsified width** — `66 89 86` stores **AX** (uint16) at `+0x6c4` |
| 7 | Multiple independent callers construct this class | **Falsified count** — only `00615b97` xref |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Base→vtbl→ushort CF | **High** | Wrong HB subclass init order |
| `ret 0x18` / 6 stack args | **High** | Stack corruption if ported as ret 0 |
| Vtbl identity for spawn peers | **High** | Mis-bind precheck/execute |
| Product class English | Medium | Naming only |
| vfunc+0x27c meaning | Low / open | Cached field misused in ports |

---

## 3. Cross-check against raw + bytes

```
call CVOGHBSkillBase_ctor          ; E8 … → 005788d0
mov dword [esi], 009d0ec4          ; subclass vtbl
call [edx+0x27c]                   ; skill object virtual
mov [esi+0x6c4], ax                ; uint16 only
mov eax, esi
ret 0x18
```

Clean must **not** invent spawn loop, terrain, creature create, or Enqueue — those are in execute, not here.

---

## 4. Surviving contract for AutoCore

```csharp
// Port shape (client skill HB action)
HB SpawnHb = new SpawnEntitiesSkillHb(); // size 0x6d0 retail
// base CVOGHBSkillBase fields filled from skill + target
// vtbl = spawn-entities subclass
// ushort cache = skill.Virtual0x27c()
// then Enqueue + Start from execute site
```

Server ports that only need spawn *behavior* may not need this exact ctor; preserve **subclass vtbl** if reusing client-side HB list semantics.

---

## 5. Open questions

1. RTTI demangle for subclass beyond base `CVOGHBSkillBase`.
2. Consumers of `this+0x6c4` after Start.
3. Whether template vs creature branch changes ctor args (caller always same formals).

**Verdict:** **accept**
