# Review B (skeptical / adversarial): `aa_00621700` CVOGHBSkill_OnDoHit_Execute_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00621700` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (R11-018) |
| **Counterpart** | `reviews/A_aa_00621700_CVOGHBSkill_OnDoHit_Execute_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `disassemble_function` + `read_memory` + xrefs/callees. No `disassemble_bytes`. No Launcher.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Ghidra `undefined FUN_00621700(void)` means zero formals / void return | **Falsified** — `ret 0x18`, six stack loads, `mov eax,1` |
| 2 | This unit is the OnDoHit **constructor** | **Falsified** — ctor is `FUN_00621350` (base+vtbl only); this is multi-target loop + list arming |
| 3 | Class is still anonymous `FUN_*` | **Falsified as identity** — RTTI `.?AVCVOGHBSkill_OnDoHit@@` on COL before vtbl |
| 4 | Direct call graph (many code xrefs) | **Falsified count** — sole xref is DATA `@009d15f0` (vtbl dispatch) |
| 5 | Returns 0 on empty / failed resolve | **Falsified** — only exit is sentinel with **1**; miss paths continue |
| 6 | Uses instance `this` fields | **Falsified** — ECX never consumed; all state from stack args |
| 7 | Alloc size unknown / 0x6d0 like SpawnEntities peer | **Falsified** — `push 0x6c0` (OnDoHit size; peer `00621f50` is 0x6d0 different class) |
| 8 | Enqueue list offset equals resolve ctx offset | **Falsified** — resolve `+0xe4e8`, list `+0xe4ec` |
| 9 | Product method name is sealed English "Execute" | **Survives only as INFERRED** — slot role family; demangle open → gaps |
| 10 | `operator_new` null path is safe | **Survives as image hazard** — null ESI then `[esi+0x18]` would fault; retail new throws / never null; decompiler path only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Loop / sentinel / resolve CF | **High** | Wrong multi-target skill apply |
| `ret 0x18` + return 1 | **High** | Stack corruption / wrong success code |
| Class vtbl + RTTI | **High** | Bind wrong skill subclass |
| Base ctor arg mapping | **High** (via sealed base) | Bad source/target/blob wiring |
| Method English "Execute" | Medium / open | Naming only |
| char index wrap behavior | Low / open | Pathological huge tables |

---

## 3. Cross-check against raw + bytes

```
push 0x6c0
call operator_new
mov ecx, esi
call CVOGHBSkillBase_ctor          ; 005788d0
mov dword [esi], 009d15c4          ; OnDoHit vtbl
cmp dword [esi+0x18], 0
jz  dtor_path
mov ecx, [ebp+0xe4ec]
push esi
call CVOGHBList_Enqueue
mov ecx, esi
call CVOGHBBase_Start
...
mov eax, 1
ret 0x18
```

Clean must **not** claim terrain spawn, template lookup, or string `"invalid template"` — those belong to `Skill_SpawnTemplateAndStartHB` (`00620480`), not this unit.

Do **not** merge with `FUN_00621f50` (size `0x6d0`, vtbl `009d1624`, calls `FUN_00621350` then overwrites vtbl).

---

## 4. Surviving contract for AutoCore

```csharp
// Port shape — OnDoHit multi-target arm (client skill HB)
foreach (var tfid in targetTableUntilSentinel) {
    var target = ResolveObjectTarget(world.ResolveCtx /* +0xe4e8 */, tfid);
    if (target == null) continue;
    var hb = new CVOGHBSkill_OnDoHit(); // retail size 0x6c0
    // CVOGHBSkillBase_ctor(source, skillBlob, worldAsArg4, target, tfid16, arg7)
    // install OnDoHit vtbl
    if (hb.Owner != null) world.HbList /* +0xe4ec */.Enqueue(hb).Start();
    else hb.Delete();
}
return 1; // always on sentinel
```

Preserve **return 1** even when zero targets resolved. Preserve separate resolve vs list offsets.

---

## 5. Open questions

1. Product method name at vtbl+0x2C.
2. Who dispatches this slot (skill HB tick / reaction / cast pipeline) — not OWN.
3. Whether `param_3` as base ctor arg4 (`this+0x688`) is world ctx by design (matches sealed base store).
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
