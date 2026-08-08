# Review B (skeptical / adversarial): `aa_00405920` CsSList_RemoveFirstByPredicate_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00405920` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY MEGA-042) |
| **Counterpart** | `reviews/A_aa_00405920_CsSList_RemoveFirstByPredicate_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | SendInventoryAddItem / inventory-transfer-only helper | **Falsified** — body is generic pred walk; callers are Object_QueueDelete + object teardown; no inventory strings |
| 2 | Same as Contains (`004e15a0`) | **Falsified** — Contains only tests membership; this unlinks, dtors node, decrements count |
| 3 | Same as Append (`004024d0`) | **Falsified** — Append allocates/links; this removes; Append gates outer CS on count≤3, this always dual-CS |
| 4 | Remove-all matching nodes | **Falsified** — after first match goes to leave label; loop does not continue |
| 5 | `__cdecl` / no stack cleanup / RET 4 | **Falsified** — epilogue **`RET 8`** (`C2 08 00`); ECX this |
| 6 | Predicate is stdcall / thiscall | **Clarify** — live stubs use **`RET 8`** with stack payload+cookie (cdecl-style cleanup by callee); CALL via function pointer |
| 7 | ECX = node / payload | **Falsified** — `MOV EDI,ECX` then `LEA [EDI+0x28]` list CS; node is ESI from head walk |
| 8 | Count gate like Append (outer CS only if count≤3) | **Falsified** — always Enter both CS (Contains twin pattern) |
| 9 | Uses operator_delete directly | **Falsified** — `PUSH 1; CALL [vtbl]` scalar deleting dtor |
| 10 | Runtime Confirmed | **Fails** — open (no Launcher) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall + RET 8 | **Confirmed** | Stack imbalance in ports |
| Dual CS +0x28/+0x10 order | **Confirmed** | Deadlock / unlock mismatch |
| First-match only unlink | **Confirmed** | Wrong multi-remove semantics |
| Family layout with Append/Contains | **Confirmed** | Broken shared host struct |
| Product inventory name | **Low** | Misleading system tags if over-claimed |
| Node vtbl English | **Low** | Doc only |
| Runtime | **Open** | Behavioral drift |

---

## 3. Cross-check against raw / bytes

```text
raw 2026-07-23 ≡ live decompile 2026-08-05 ≡ clean CsSList_RemoveFirstByPredicate_Inferred.cpp

83 EC 08          SUB ESP,8
… MOV EDI,ECX …
LEA EAX,[EDI+0x28]; CALL EnterCS
LEA EAX,[EDI+0x10]; CALL EnterCS
MOV ESI,[EDI+4]   ; head
…
CALL [pred](payload,cookie); TEST AL,AL
… unlink …
PUSH 1; MOV ECX,ESI; CALL [EDX]   ; vtbl dtor
InterlockedDecrement([EDI+0xC] via ADD EDI,0xC then push)
…
C2 08 00          RET 8

Pred stubs 0x4cd580 / 0x92d8e0:
  MOV EAX,[ESP+4]; CMP EAX,[ESP+8]; SETE AL; RET 8
```

Reject ports that:

- Name this as inventory-add / SendInventoryAddItem product API.
- Implement remove-all or head-only without predicate.
- Use single CS or Append's count≤3 outer gate.
- Free node with bare `operator_delete` without vtbl(1).
- Use cdecl without popping **two** stack args (pred + cookie).

---

## 4. Surviving contract for AutoCore

```csharp
// Retail: dual-CS singly-linked list remove-first-if(pred, cookie)
// Managed port sketch (behavior-preserving):

sealed class CsSList /* Inferred */
{
    // head @+4, tail @+8, count @+0xC, CS @+0x10 and +0x28
    public void RemoveFirstByPredicate(Func<object?, object?, bool> pred, object? cookie)
    {
        lock (Outer) lock (Inner)
        {
            Node? prev = null;
            for (var n = Head; n != null; prev = n, n = n.Next)
            {
                if (!pred(n.Payload, cookie)) continue;
                // unlink, clear payload, dispose node, Interlocked.Decrement(ref Count)
                return; // first only
            }
        }
    }
}

// Live retail sites typically pass pointer-equality pred + object* cookie.
```

---

## 5. Verdict

Adversarial path falsifies inventory-only / remove-all / wrong-ABI / Append-merge claims. CF/ABI/family sealed; product English open → **accept-with-gaps**. Terminal **false**.
