# Review B (skeptical / adversarial): `aa_004195d0` CNDHash_Recreate_00a2c2e4

| Field | Value |
|---|---|
| **Stable ID** | `aa_004195d0` |
| **VA** | `0x004195d0` |
| **Canonical name** | `CNDHash_Recreate_00a2c2e4` |
| **Review date** | `2026-08-04` (WQ9H-E dual) |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_004195d0_CNDHash_Recreate_00a2c2e4.md` |
| **Live tools** | Independent `batch_decompile` + `read_memory` + caller `get_assembly_context` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Lock is hard-abort / early return | **Falsified** — logs then falls into destroy |
| 2 | Thiscall ECX + stack log2 / `ret 4` (skill shape) | **Falsified** — `mov esi,eax`; bare `ret`; BL log2 |
| 3 | Same helper VAs as inventory `004138d0` | **Falsified** — uses `00406fc0`/`00406f20` not `00413e20`/`00413d80` |
| 4 | Throws on locked recreate | **Falsified** — soft log only |
| 5 | Stack arg for log2 | **Falsified** — BL only; sole caller imm `2` |
| 6 | Product class English sealed without stamp | **Fails** — stamp suffix only |
| 7 | Runtime Confirmed / bit-exact | **Fails** — open; no Launcher |

---

## 2. Decisive machine dataflow

```text
// entry
PUSH ESI
MOV ESI, EAX              // hash
CMP byte [ESI+0x1d], 0
JZ  skip_log
  push "HashError:Recreate..."
  call FUN_007a4480
  push "VOG_DEBUG_STOP"
  call FUN_007a4480
  add esp, 0x10
skip_log:
MOV EAX, ESI
CALL 0x00406fc0           // destroy (EAX ABI)
MOV CL, BL
MOV EAX, 1
SHL EAX, CL
MOV [ESI+0x1c], BL
MOV [ESI+8], EAX          // COUNT = 1<<log2
XOR EAX, EAX
MOV [ESI+0x18], EAX
MOV [ESI+0x14], EAX
CALL 0x00406f20           // alloc (ESI ABI)
POP ESI
RET
```

Caller `FUN_007fe640` @ `0x007fe707`:

```text
MOV byte [hash+0x1d], 0   // unlock after traverse
MOV EAX, hash             // *(owner+0x3084)
MOV BL, 2
CALL 0x004195d0
```

A ≡ B on live decompile + entry/exit/seed bytes.

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Recreate CF + lock continue | **High** | Wrong fatal handling |
| EAX/BL vs thiscall | **High** | Wrong port ABI |
| Nested stamp helpers | **High** | Cross-family merge |
| Product English | **Open** | Naming only |
| Runtime | **Open** | — |

---

## 4. Surviving contract

```text
CNDHash_Recreate_00a2c2e4:
  EAX = hash*; BL = log2
  if locked@+0x1d: log Recreate + VOG_DEBUG_STOP; continue
  destroy 00406fc0; seed log2/count/heads; alloc 00406f20
  bare ret
```

**Verdict:** **accept-with-gaps**
