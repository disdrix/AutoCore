# Review B (skeptical / adversarial): `aa_0055fbf0` WorldObj_UnbindLinks_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0055fbf0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W26-D) |
| **Counterpart** | `reviews/A_aa_0055fbf0_WorldObj_UnbindLinks_Inferred.md` |
| **Scratch** | `tmp/a_0055fbf0.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is the bind helper | **Falsified** — callers do unbind then bind; bind is `FUN_0055fa40` |
| 2 | cdecl / two equal stack args only | **Falsified** — ECX=manager (`MOV ESI,ECX`); `ret 4` |
| 3 | Always runs complex `FUN_006caaa0` path | **Falsified** — `CMP [EBP+0x40],0` / `JE` simple `FUN_006297e0` path |
| 4 | Can skip `FUN_0055f4c0` | **Falsified** — both epilogues call it (decompile: free path + fall-through) |
| 5 | Returns status in EAX | **Falsified** — no EAX setup; void |
| 6 | Product name is retail | **Overstated** — inferred from rebind/remove caller duals |
| 7 | Unreachable growth path changes CF | **Open residual** — warning at `0x0055fcee`; sealed CF from live decompile still holds for observed paths |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Unbind role vs bind twin | **High** | Rebind order bugs |
| thiscall ret 4 void | **High** | ABI break |
| Simple vs complex branch | **High** | Missed clear path |
| Always `FUN_0055f4c0` | **High** | Leak / heap bookkeeping |
| Nested callee semantics | **Medium** | Port incompleteness |
| Product English | **Medium** | Naming only |
| Unreachable block / 005b3300 | **Open** | Edge growth only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
SUB ESP,0x38; push ESI=ECX (mgr); load obj
FUN_0062d960(*(mgr+0x234))
if *(obj+0xc) and query count>0:
  if *(obj+0x40)==0: FUN_006297e0 simple
  else: FUN_006caaa0 complex + loop
FUN_0055f4c0; ADD ESP,0x38; RET 4
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. W24-B rebind dual already required this as unbind first.

---

## 4. Surviving contract for AutoCore

```
// Manager unbind before rebind or remove:
WorldObj_UnbindLinks_Inferred(manager, obj);
// then optionally WorldObj bind (FUN_0055fa40) or destroy path
// Do not skip when porting rebind: order is unbind → bind → flag@*(obj+0x44)+0x28
```

---

## 5. Verdict

Adversarial pass **confirms** A: CF/ABI/role sealed; nested contracts + unreachable residual do not block accept → **accept**.
