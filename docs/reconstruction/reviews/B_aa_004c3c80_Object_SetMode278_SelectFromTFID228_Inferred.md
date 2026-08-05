# Review B (skeptical / adversarial): `aa_004c3c80` Object_SetMode278_SelectFromTFID228_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c3c80` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W28-L) |
| **Counterpart** | `reviews/A_aa_004c3c80_Object_SetMode278_SelectFromTFID228_Inferred.md` |
| **Scratch** | `tmp/a_004c3c80.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | cdecl / no ECX this | **Falsified** — `MOV ESI,ECX`; MI uses `ESI` as base |
| 2 | Always resolves TFID | **Falsified** — only when mode==1 (`CMP AL,1` / `JNE`) |
| 3 | Sets selected target to resolved object | **Falsified** — candidate is `resolved+0xA0`, not resolved itself |
| 4 | SetSelectedTarget is 3-arg as decompile shows | **Falsified** — single `PUSH` + dual-sealed `ret 4` callee |
| 5 | Leaf / no callees | **Falsified** — two direct CALLs + virtual |
| 6 | `RET` without stack cleanup | **Falsified** — `RET 4` |
| 7 | Product death-state English sealed | **Overstated** — write site sealed; enum names residual (2/3 used elsewhere) |
| 8 | Resolve needs only TFID pointer | **Incomplete** — bytes load manager into ECX first |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall RET 4 | **High** | ABI break |
| mode==1 gate | **High** | Spurious resolve |
| Candidate = +0xA0 | **High** | Wrong target entity |
| Callee VAs | **High** | Port to wrong helper |
| Product mode English | **Medium** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
thiscall Object_SetMode278_SelectFromTFID228_Inferred(this, mode)
this+0x278 = mode
if mode != 1: return
resolved = Object_ResolveFromTFID(manager, this+0x228)
candidate = resolved ? resolved+0xA0 : 0
if candidate && mi->vtbl[+0x298](candidate):
  Object_SetSelectedTarget(mi, candidate)
```

Live decompile 2026-07-29 ≡ scaffold raw CF (2026-07-23) with renamed callees. Callers: clear with 0 (ProfileType4 / resolve-fail); set 1 on skill spawn path.

---

## 4. Surviving contract for AutoCore

```
// AI tick start often: Object_SetMode278_SelectFromTFID228_Inferred(owner, 0);
// One-shot promote: Object_SetMode278_SelectFromTFID228_Inferred(owner, 1);
// Port must: preserve ret-4; use resolved+0xA0 not resolved*; honor vtbl+0x298 gate;
// supply resolve manager ctx (not naked TFID-only call).
```

---

## 5. Verdict

Adversarial pass **confirms** A: CF/ABI/gates/callees sealed; product English residual only → **accept**.
