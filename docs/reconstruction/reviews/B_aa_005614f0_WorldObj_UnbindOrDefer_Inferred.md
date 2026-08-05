# Review B (skeptical / adversarial): `aa_005614f0` WorldObj_UnbindOrDefer_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005614f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W30-J) |
| **Counterpart** | `reviews/A_aa_005614f0_WorldObj_UnbindOrDefer_Inferred.md` |
| **Scratch** | `tmp/a_005614f0.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This **is** RemoveOrDefer (`00561450`) | **Falsified** — adjacent but different body; no `0062a490`/`005ffff0`/ref--/destroy; adds `0055f0b0` |
| 2 | Always hard-unbinds | **Overstated** — defers when `manager+0x12c==1` |
| 3 | ECX is the world object | **Falsified** — call site `MOV ECX, manager`; obj is stack |
| 4 | Immediate path destroys object | **Falsified** — no vtbl[0](1); object survives for rehome |
| 5 | Same unbind quartet as RemoveOrDefer | **Falsified** — this path: `0055fbf0` + `0055f0b0` + `0055fd80` only |
| 6 | Plain `ret` / one stack arg | **Falsified** — `C2 08 00` (two stack args) |
| 7 | Product name is retail | **Overstated** — `_Inferred` structural only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Unbind-or-defer role | **High** | Mode-7 leave destroys objects that must rebind |
| thiscall + ret 8 | **High** | ABI break |
| Defer queue +0xf0 family | **High** | Nested enroll reentrancy hazard |
| Distinct from RemoveOrDefer | **High** | Wrong lifecycle (destroy vs keep) |
| Nested helper English | **Medium** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
PUSH ESI; MOV ESI, ECX
CMP byte [ESI+0x12c], 1
JZ defer_queue_push_refinc_out0_ret8
CMP dword [ESI+0x24], 0
JLE skip_flush
  CALL 00561320
PUSH obj; MOV ECX,ESI; CALL 0055fbf0
MOV ECX,obj; CALL 0055f0b0
PUSH obj; MOV ECX,ESI; CALL 0055fd80
*out=1; RET 8
```

Live 2026-07-29 ≡ raw 2026-07-23. Callers: SnapshotHostRefsAndUnbind + `00561580` only (2 CODE xrefs) — not the broad remove graph of `00561450`.

---

## 4. Surviving contract for AutoCore

```
// After snapshot/compact of host-list entries referencing obj (mode-7 leave):
WorldObj_UnbindOrDefer_Inferred(manager, &outDone, obj);
// Must preserve: defer when flag+0x12c==1 (queue +0xf0, ref6++);
// immediate: optional flush pairs, unbind links, compact obj list,
// clear stamp/host cleanup; outDone polarity; ret 8.
// Do NOT substitute WorldObj_RemoveOrDefer (00561450) — that destroys.
```

---

## 5. Verdict

Adversarial pass **confirms** A: unbind-or-defer ≠ remove-or-destroy; ABI/CF sealed → **accept**.
