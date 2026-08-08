# Review B (skeptical / adversarial): `aa_0054cbb0` CVOGHBSkill_PossessCreature_DefaultFactory_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0054cbb0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY R12-023 dual B) |
| **Counterpart** | `reviews/A_aa_0054cbb0_CVOGHBSkill_PossessCreature_DefaultFactory_Inferred.md` |
| **Dual start** | 2646 |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This leaf **is** the full PossessCreature ctor (`0x00626240`) | **Falsified** — no call to `00626240`; no dyn_cast; no `+0x6c*` field clears; bare `RET` vs full ctor `ret 0x18` |
| 2 | Alloc size other than `0x6f0` | **Falsified** — `68 F0 06 00 00` |
| 3 | Always non-null | **Falsified** — null-new path zeros EAX and returns |
| 4 | `__thiscall` factory method (ECX=type object) | **Falsified** — no ECX this at entry; ECX only loaded for base ctor after alloc |
| 5 | `RET 4` / stdcall with arg | **Falsified** — terminal `C3` bare ret |
| 6 | Base init is full skill ctor `0x005788d0` | **Falsified** — rel call seals `0x00578830` DefaultCtor |
| 7 | Vtbl is base `0x009d3fdc` permanently | **Falsified** — body stores `0x009d1ba4` after base returns |
| 8 | Class is Virus / ActivatePlayer / bare SkillBase | **Falsified** — vtbl+size match PossessCreature (0x6f0 / 0x009d1ba4); not 0x6e0/0x2c families |
| 9 | Multiple direct CALL sites | **Falsified for code xrefs** — 0 CALL; 1 DATA ptr only |
| 10 | Runtime Confirmed | **Fails** — Terminal false; no Launcher |
| 11 | Ghidra surface `undefined FUN_*(void)` voids return | **Noise** — body returns EAX pointer |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| new(0x6f0) → default base → vtbl → return | **High** | Wrong lifecycle |
| cdecl / 0 args / bare RET | **High** | Stack imbalance |
| Vtbl `0x009d1ba4` + size `0x6f0` | **High** | Wrong type / OOB |
| Distinct from full ctor `00626240` | **High** | Missing creature bind if merged |
| DATA reachability via `0x009d1bec` | **High** (pointer value) | — |
| Who *invokes* the factory | **Open** | Dead-code risk only |
| Role English "DefaultFactory" | **Inferred** | Naming |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```text
raw/live:
  SEH;
  p = operator_new(0x6f0);
  if (!p) return 0;
  CVOGHBSkillBase_DefaultCtor(p);   // 0x00578830
  *p = 0x009d1ba4;
  return p;                         // bare ret

bytes (abbrev):
  6A FF  68 FB 43 9A 00  … FS:[0] …
  68 F0 06 00 00  E8→operator_new  83 C4 04
  8B F0  33 C0  3B F0  74 0f
  8B CE  E8→00578830
  C7 06 A4 1B 9D 00
  8B C6  …  83 C4 10  C3

DATA @ 009d1bec: B0 CB 54 00 → 0054cbb0
```

Clean **must not**:
- merge with full-arg ctor `00626240`,
- claim creature dyn_cast or `+0x6c*` init,
- claim thiscall / RET 4,
- invent Runtime Confirmed,
- dual non-OWN registry/vtbl methods in this unit,
- claim multi CALL graph.

---

## 4. Surviving contract for AutoCore

```csharp
// Retail aa_0054cbb0 — CVOGHBSkill_PossessCreature_DefaultFactory_Inferred
// cdecl; 0 args; bare ret. Returns object* or null. Size 0x6f0.
unsafe void* DefaultFactory()
{
    var p = OperatorNew(0x6f0);
    if (p == null) return null;
    CVOGHBSkillBase_DefaultCtor(p);          // 0x00578830
    *(uint*)p = 0x009d1ba4u;                 // PossessCreature vtbl
    return p;
}
// Not a substitute for full ctor 0x00626240 (args + creature bind).
```

**Port notes:** Keep distinct from full-arg construction path. Do not shrink below `0x6f0`. Do not merge with ActivatePlayer HB (`0x2c` / `0x009e3168`) or Virus skill (`0x6e0` / `0x009d14bc`).

---

## 5. Verdict

**accept-with-gaps** — adversarial checks leave CF/ABI/size/vtbl/base-ctor intact and keep full-ctor conflation falsified; remaining gaps are factory-dispatcher English, indirect reachability catalog, and runtime confirmation.
