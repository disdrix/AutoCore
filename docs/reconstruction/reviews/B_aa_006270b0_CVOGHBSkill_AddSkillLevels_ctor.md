# Review B (skeptical / adversarial): `aa_006270b0` CVOGHBSkill_AddSkillLevels_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_006270b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (R11-022) |
| **Counterpart** | `reviews/A_aa_006270b0_CVOGHBSkill_AddSkillLevels_ctor.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + xrefs/callers + `read_memory`. **No** `disassemble_bytes`.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Function is still anonymous / scaffold-only with no class identity | **Falsified** — RTTI `.?AVCVOGHBSkill_AddSkillLevels@@` on vtbl `0x009d1c54` |
| 2 | This body *is* the skill level-add execute / apply logic | **Falsified** — body is base+vtbl+empty map+gate only; no level math |
| 3 | Base call is still anonymous `FUN_005788d0` without identity | **Falsified as identity** — plate/RTTI `CVOGHBSkillBase_ctor` |
| 4 | `param_1[0x1b1]` is a skill scalar / budget like Virus `+0x6d0` | **Falsified shape** — stores **node pointer** + self-links + size at `[0x1b2]`; map header, not budget dword |
| 5 | Object size unknown | **Falsified** — sole caller `operator_new(0x6d0)` |
| 6 | Multiple independent factories construct this class | **Falsified count** — single xref `006277ec` in `FUN_00627750` |
| 7 | `AttachOwnerObject(this, null)` always runs | **Falsified** — only when `vtbl+0x210(0)` returns 0 |
| 8 | Decompiler `ExceptionList = param_1` is authoritative | **Falsified** — bytes restore prior FS:[0] then `mov eax,edi` |
| 9 | Product spelling must use `_Inferred` | **Falsified for class** — RTTI demangle Confirmed; ctor suffix structural |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Base → vtbl → empty map → gate CF | **High** | Wrong HB subclass init |
| `ret 0x18` / 6 stack args | **High** | Stack corruption if ported as ret 0 |
| RTTI class name | **Confirmed** | Naming only if wrong (it is not) |
| Map @ `+0x6c4` is empty `_Tree` header | **High** | Mis-port as plain dword |
| Map payload type / level semantics | **Low / open** | Wrong server model if invented |
| `vtbl+0x210` meaning | **Low / open** | Wrong fail-closed policy if over-specified |

---

## 3. Cross-check against raw + bytes

```
call CVOGHBSkillBase_ctor          ; E8 … → 005788d0
mov  dword [edi], 009d1c54         ; subclass vtbl
call FUN_00439770                  ; empty node 0x18
mov  [edi+0x6c4], eax
mov  byte [eax+0x15], 1
self-link node {0,4,8}
mov  dword [edi+0x6c8], 0
call [pTarget->vtbl+0x210](0)
jz   → AttachOwnerObject(this, 0)
mov  eax, edi
ret  0x18
```

Clean must **not** invent level increments, XP tables, or Enqueue — those are outside this ctor.

---

## 4. Surviving contract for AutoCore

```csharp
// Port shape (client skill HB action)
var hb = new CVOGHBSkill_AddSkillLevels(); // size 0x6d0 retail
// base CVOGHBSkillBase fields from skill + target
// vtbl = AddSkillLevels subclass (RTTI)
// empty map header at +0x6c4 (sentinel + size 0)
// if target.Virtual0x210(0) == 0: clear owner → factory will destroy
// Enqueue + Start only from factory when owner non-null
```

Do not invent map value type until a method that inserts into `+0x6c4` is dualled.

---

## 5. Open questions

1. Key/value type of the `+0x6c4` tree (level id → delta? skill id → rank?).  
2. Which vtbl methods on `0x009d1c54` populate or consume the map.  
3. English for object `+0x210` gate (shared across host/mode paths).  
4. Runtime confirmation of fail-closed detach.

**Verdict:** **accept-with-gaps**
