# Review B (skeptical / adversarial): `aa_00560e90` WorldObj_RebindActivate_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00560e90` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W24-B) |
| **Counterpart** | `reviews/A_aa_00560e90_WorldObj_RebindActivate_Inferred.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Decompiler signature `void FUN_00560e90(int param_1)` is complete ABI | **Falsified** — ECX is manager; `ret 8` implies two stack formals |
| 2 | This is a full enroll (counters / refcount) | **Falsified** — no `+0x12c` / `+0x130` / refcount math; those are `00560ec0` |
| 3 | Call order is bind then unbind | **Falsified** — `0055fbf0` first, then `0055fa40` |
| 4 | Flag is written on the manager | **Falsified** — uses **object** EDI: `[edi+0x44]` then `+0x28` |
| 5 | Second stack arg is required product input to this body | **Partially falsified** — cleaned by `ret 8` but **never read**; callers may stage `1` |
| 6 | SkyBoxParticles auto-name is product role | **Falsified as product name** — call graph noise; real callers are phys/recreate/airlift |
| 7 | Function returns status in EAX | **Falsified** — void; no post-call status idiom in body |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Unbind→rebind→flag CF | **High** | Wrong lifecycle port |
| Manager thiscall | **High** | Wrong ECX at call sites |
| `ret 8` / staged 2nd arg | **High** residual | Stack bugs if ported as ret 4 with 1 push only without matching caller frame |
| Flag offset path | **High** | Soft-state desync |
| Product class names | Medium | Naming only |
| Helper internals | Out of scope | Must not invent spatial index rules here |

---

## 3. Cross-check against raw + bytes

```
mov edi, [esp+0xc]   ; obj
mov esi, ecx         ; manager
push edi; call 0055fbf0
push edi; mov ecx,esi; call 0055fa40
mov eax, [edi+0x44]
mov byte [eax+0x28], 1
ret 8
```

Clean must **not** invent enroll counters, refcount++, or remove/defer queues.

Call-site note: many sites only `push obj` once; second formal is a **pre-staged** stack slot (`mov byte [esp],1` pattern at recreate/airlift). Port must preserve `ret 8` cleanup or match caller frames.

---

## 4. Surviving contract for AutoCore

```csharp
// Port shape (world/phys manager)
void WorldObj_RebindActivate(Manager mgr, WorldObj obj)
{
    UnbindLinks(mgr, obj);   // FUN_0055fbf0
    BindLinks(mgr, obj);     // FUN_0055fa40
    obj.SubAt0x44.FlagAt0x28 = 1;
}
// Use after phys body mode restore / HB recreate — not as full spawn enroll.
```

---

## 5. Open questions

1. Whether server ghost/phys code needs the same unbind/rebind pair after soft recreate.
2. Flag interaction with soft-not-ready / body-type paths in `CVOGHBRecreateObject`.
3. Dual seal of unbind/bind helpers when scheduled.

**Verdict:** **accept**
