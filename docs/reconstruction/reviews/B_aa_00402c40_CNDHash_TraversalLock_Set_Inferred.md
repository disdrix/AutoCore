# Review B (skeptical / adversarial): `aa_00402c40` CNDHash_TraversalLock_Set_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00402c40` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (MEGA-110 OWN-ONLY dual B) |
| **Counterpart** | `reviews/A_aa_00402c40_CNDHash_TraversalLock_Set_Inferred.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Identity is `Named_VOG_DEBUG_STOP_*` | Scaffold alias from string | **Falsified** — string is assert-only; function always sets flag |
| 2 | Hard-abort / throw / `__debugbreak` on re-lock | VOG_DEBUG_STOP name | **Falsified** — soft `FUN_007a4480` logs; falls through to force lock |
| 3 | Is `List_TraversalLock` (`0x004294f0`) | Shared “TraversalLock” word | **Falsified** — list uses flag `+0x28` + EnterCS; this is `+0x1d` only |
| 4 | Is unlock / clear flag | Symmetric naming guess | **Falsified** — always writes **1**; unlock is inline `=0` at callers |
| 5 | Is `CNDHash_TraverseToNext` | Walk conflation | **Falsified** — no cursor; leaf log+set only |
| 6 | stdcall / stack hash* / RET 4 | Decompiler void signature noise | **Falsified** — `MOV ESI,ECX`; bare `RET`; call sites load ECX |
| 7 | thiscall on client/owner object | Parent `Client_UpdateNpcInteractIcons` skim | **Falsified** — ECX is hash (`client+0x548`), not client |
| 8 | Interaction-only helper | Partition system tag | **Falsified** — 30 xrefs across missions/UI/quickbar/inventory paths |
| 9 | Already-locked path skips set | Optimistic early-out | **Falsified** — set is after the if; always executed |
| 10 | Runtime Confirmed | Wave seal claim | **Fails (open)** — no Launcher; dual CF seal only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Soft force-lock contract | **High** | Double-lock would hard-fail ports incorrectly |
| Flag offset `+0x1d` | **High** | Corrupt adjacent hash fields |
| ECX=hash ABI | **High** | Wrong this at every call site |
| CNDHash family role | **High** | Confuse with List CS lock |
| Product method English | **Low–Med** | Doc only (`_Inferred`) |
| Runtime | **Open** | Not claimed |

---

## 3. Cross-check against raw ≡ live

```text
if (*(hash+0x1d) != 0) {
  log("HashError:TraversalLock, already locked for traversal");
  log("VOG_DEBUG_STOP");
}
*(hash+0x1d) = 1;   // always
return;             // bare RET
```

Sibling contrast (evidence only; not OWN dual):

* `CNDHash_TraverseToNext` (`0x00411900`): requires lock; walks ordered next; soft “not locked” HashError.
* `List_TraversalLock` (`0x004294f0`): CS Enter + flag `+0x28`.
* Inline unlock at `FUN_004bae00`: `MOV byte ptr [hash+0x1d], 0` after walk — inverse of this set.

Bytes seal (read_memory):

```text
56 8B F1 80 7E 1D 00 74 1B ... C6 46 1D 01 5E C3 CC...
PUSH ESI; MOV ESI,ECX; CMP [ESI+1d],0; JZ set; logs; MOV [ESI+1d],1; POP ESI; RET; INT3 pad
```

---

## 4. Surviving contract for AutoCore

```
CNDHash_TraversalLock_Set_Inferred(hash):
  if hash.traversalFlag (+0x1d):
      DebugLog(0, "HashError:TraversalLock, already locked for traversal")
      DebugLog(0, "VOG_DEBUG_STOP")
  hash.traversalFlag = 1
  // never throw; never EnterCS; never walk
```

**Port tests:**

* Unlocked → flag becomes 1; no log.
* Already locked → logs fire **and** flag remains/forces 1.
* No stack cleanup beyond callee cdecl; bare RET.
* Do **not** merge with List_TraversalLock or VOG_DEBUG_STOP stubs.

**Verdict:** **accept** — adversarial hard-abort / List-merge / unlock / stack-ABI / owner-this / VOG identity claims **all falsified**. Runtime remains open (terminal false).
