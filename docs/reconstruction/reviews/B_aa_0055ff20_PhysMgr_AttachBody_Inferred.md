# Review B (skeptical / adversarial): `aa_0055ff20` PhysMgr_AttachBody_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0055ff20` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W29-R) |
| **Counterpart** | `reviews/A_aa_0055ff20_PhysMgr_AttachBody_Inferred.md` |
| **Scratch** | `tmp/a_0055ff20.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is WorldObj_BindLinks | **Falsified** — BindLinks is `0055fa40` (object gate + scale); this registers a body onto manager vector |
| 2 | This is detach | **Falsified** — detach is twin `00560020` (refcount--, remove from vector, SortedDiffWalk empty-left) |
| 3 | No return value | **Falsified** — `MOV EAX,EDI` before ret |
| 4 | Plain ret / no stack formal | **Falsified** — `C2 04 00`; body at `[EBP+8]` |
| 5 | SortedDiffWalk this = d0+8 | **Falsified** — machine ECX=`*(mgr+0x138)`; d0+8 stack formal |
| 6 | Cap compare ignores high bit | **Falsified** — bytes `AND EDX,0x7FFFFFFF` before compare |
| 7 | Product name is retail PDB | **Overstated** — `_Inferred` only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Attach role | **High** | Wrong lifecycle vs detach |
| thiscall + ret 4 + return body | **High** | ABI break |
| Serial / refcount / vector | **High** | Body bookkeeping bugs |
| Grow mask 0x7fffffff | **High** | Premature/missed grow |
| Product types | **Medium** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
frame+align; EDI=body; ESI=manager; body[+8]=mgr
FUN_0062d960(*(mgr+0x234)); body vtbl+0x18; mgr vtbl+4
serial stamp; if count: CanonAndSort + SortedDiffWalk(new,empty)
short[+6]++; grow if full; push; FUN_0062a4d0; FUN_0055f4c0; EAX=body; RET 4
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 CF. Pad `CC` after body.

---

## 4. Surviving contract for AutoCore

```
// Register body with manager (not BindLinks):
body = PhysMgr_AttachBody_Inferred(manager, body);
// Must preserve: owner stamp, serial, worklist+SortedDiffWalk attach (empty right),
// short ref++, vector grow with 0x7fffffff mask, notify, release, ret 4.
// Pair with detach twin FUN_00560020 — do not invert sides of SortedDiffWalk.
```

---

## 5. Verdict

Adversarial pass **confirms** A: CF/ABI/role sealed; twin relationship noted → **accept**.
