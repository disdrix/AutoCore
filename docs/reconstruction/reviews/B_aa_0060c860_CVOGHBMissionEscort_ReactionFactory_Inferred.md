# Review B (skeptical / adversarial): `aa_0060c860` CVOGHBMissionEscort_ReactionFactory_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060c860` |
| **VA** | `0x0060c860` |
| **Canonical name** | `CVOGHBMissionEscort_ReactionFactory_Inferred` |
| **Review date** | `2026-08-04` (WQ9H-E dual) |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_0060c860_CVOGHBMissionEscort_ReactionFactory_Inferred.md` |
| **Live tools** | Independent `batch_decompile` + `read_memory` + xrefs + assembly_context |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This function **is** the Escort ctor | **Falsified** — ctor is `0x006507c0`; this only calls it after `new(0x78)` |
| 2 | Outpost / non-Escort class | **Falsified** — ctor installs Escort vtable/RTTI (dualed) |
| 3 | Always spawns HB | **Falsified** — spawn gated on float/flag + `targets+0x14c != -1` |
| 4 | `operator_delete` is noreturn | **Falsified** — cast-fail deletes then returns false; success deletes then returns true |
| 5 | Return is void / pointer | **Falsified** — `xor al,al` / `mov al,1` + `ret 8` |
| 6 | Decompiler `return uVar3 & 0xffffff00` is literal | **Falsified** as machine return — outer fail uses `xor al,al` |
| 7 | Always casts skill | **Falsified** — only if `req+0x20` |
| 8 | Product method English sealed | **Fails** — `_Inferred` |
| 9 | Runtime Confirmed | **Fails** — open |

---

## 2. Decisive machine dataflow

```text
// thiscall ECX=reqHost; [esp+4]=ownerCtx; [esp+8]=scoreFloats
// SEH setup...
ownerObj = *(*(ownerCtx+4)+4 + 0xa8 + ownerCtx)
if !(ownerObj+0x7e) || req+0x40 != ownerObj+0xfc: AL=0; ret 8
targets = ResolveSkillTargets(req+0x10, pack)
if !targets: AL=0; ret 8
if req+0x20:
  if CastSkill(...): delete targets; AL=0; ret 8
scoreFloats[1+req[8]] = g_flOne
if (g_flZero < req+0x1c float || req+0x18) && dword[targets+0x14c] != -1:
  mem = new(0x78)
  action = mem ? CVOGHBMissionEscort_ctor(mem, ownerCtx, reqHost) : 0
  Enqueue(*(ownerObj+0xe4ec), action)
  Start(action)
delete targets
AL=1; ret 8
```

Bytes seal: `push 0x78` before `operator_new`; `cmp dword [ebx+0x14c], -1`; exit `C2 08 00`.

A ≡ B on live decompile + return/size/gate bytes. Ctor dual seals Escort identity.

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Factory path + size 0x78 | **High** | Wrong HB type/size |
| Bool ret 8 thiscall | **High** | Wrong call cleanup |
| Conditional spawn | **High** | Always-on escort spam |
| operator_delete continues | **High** | Wrong exception model |
| Product English / stub owners | **Open** | Naming / call graph |
| Runtime | **Open** | — |

---

## 4. Surviving contract

```text
CVOGHBMissionEscort_ReactionFactory_Inferred:
  __thiscall (ECX=reqHost, ownerCtx, scoreFloats*) ret 8 → bool AL
  gate → resolve → optional cast → score → optional new(0x78)+Escort_ctor+Enqueue+Start
  delete targets on cast-fail (false) or success (true)
```

**Verdict:** **accept-with-gaps**
