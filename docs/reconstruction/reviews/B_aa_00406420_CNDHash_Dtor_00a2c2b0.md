# Review B (skeptical / adversarial): `aa_00406420` CNDHash_Dtor_00a2c2b0

| Field | Value |
|---|---|
| **Stable ID** | `aa_00406420` |
| **VA** | `0x00406420` |
| **Canonical name** | `CNDHash_Dtor_00a2c2b0` |
| **Review date** | `2026-08-04` (WQ9H-D dual) |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_00406420_CNDHash_Dtor_00a2c2b0.md` |
| **Live tools** | Independent `batch_decompile` + `read_memory` + `disassemble_function` + caller context |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Lock path **throws** or **skips** destroy | **Falsified** — logs only; fall-through to destroy |
| 2 | Identity is “VOG_DEBUG_STOP helper” (scaffold name) | **Falsified** — full dtor CF; string is soft assert only |
| 3 | Same ABI as ctor (CL/stack ret 4) | **Falsified** — thiscall ECX / bare ret |
| 4 | Destroy uses ECX thiscall | **Falsified** — `MOV EAX,ESI; CALL 00406fc0` (EAX ABI) |
| 5 | Freelist at +0x08 (literal decompiler `param_1+8` as byte offset) | **Falsified** — dword index → **+0x20**; LEA confirms |
| 6 | Merge with SkillCNDHash complete dtor `0x0051de80` | **Falsified** — different VA / stamp / freelist helper |
| 7 | Product English sealed | **Fails** — stamp suffix only |
| 8 | Runtime Confirmed / bit-exact | **Fails** — open; no Launcher |

---

## 2. Decisive machine dataflow

```text
// entry
ESI = ECX                         // thiscall
[ESI] = 0x00a2c2b0
if [ESI+0x1d] != 0:
  log HashError:Destructor...
  log VOG_DEBUG_STOP
  // no throw
EAX = ESI
CALL 0x00406fc0                   // DestroyBucketTable (EAX ABI)
// SEH state → -1
LEA EAX, [ESI+0x20]
PUSH EAX
CALL 0x00416e80                   // freelist vector dtor
bare ret
```

Caller scalar deleting (`00406520`):

```text
ESI = ECX
CALL 0x00406420
if flags&1: operator_delete(ESI)
ret 4
```

A ≡ B on live decompile CF + string imms + destroy/freelist order.

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Dtor CF + soft lock | **High** | Port throws when retail continues |
| EAX destroy ABI | **High** | Wrong nested call |
| Freelist at +0x20 | **High** | Wrong subobject teardown |
| Product English | **Open** | Naming only |
| FUN_00416e80 dual | **Open** | Nested residual |

---

## 4. Surviving contract

```text
CNDHash_Dtor_00a2c2b0:
  ECX = hash*; bare ret
  re-stamp 00a2c2b0
  if locked: log HashError+VOG_DEBUG_STOP (continue)
  DestroyBucketTable_00a2c2e4 (EAX)
  freelist vector dtor at +0x20
```

**Verdict:** **accept-with-gaps**
