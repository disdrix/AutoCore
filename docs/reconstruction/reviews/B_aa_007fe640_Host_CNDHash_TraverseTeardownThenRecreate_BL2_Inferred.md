# Review B (skeptical / adversarial): `aa_007fe640` Host_CNDHash_TraverseTeardownThenRecreate_BL2_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fe640` |
| **VA** | `0x007fe640` |
| **Canonical name** | `Host_CNDHash_TraverseTeardownThenRecreate_BL2_Inferred` |
| **Review date** | `2026-08-04` (WQ9I-D dual) |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_007fe640_Host_CNDHash_TraverseTeardownThenRecreate_BL2_Inferred.md` |
| **Live tools** | Independent `batch_decompile` + `read_memory` + caller `get_assembly_context` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Hard-abort / throw / early return on lock errors | **Falsified** — logs then continues (set lock / keep walking) |
| 2 | Recreate is thiscall ECX + stack log2 / RET 4 (skill shape) | **Falsified** — `MOV EAX,hash; MOV BL,2; CALL 004195d0` bare-ret family |
| 3 | BL log2 is not 2 / taken from host field | **Falsified** — imm `B3 02` (`MOV BL,2`) |
| 4 | Decompiler `FUN_004195d0()` has no formals → no ABI | **Falsified** — bytes seal EAX/BL; dualed recreate confirms |
| 5 | Hash field is not +0x3084 / wrong stamp family | **Falsified** — `MOV ESI,[EBP+0x3084]`; sole recreate parent of `00a2c2e4` dual |
| 6 | Identity is `Named_VOG_DEBUG_STOP_*` | **Falsified** — assert string only; role is traverse+teardown+recreate |
| 7 | thiscall on owner (ECX=this) | **Falsified** — stack owner; `RET 4` |
| 8 | Runtime Confirmed / bit-exact | **Fails** — open; no Launcher |

---

## 2. Decisive machine dataflow

```text
PUSH EBP
MOV EBP, [ESP+8]          // owner
PUSH ESI
MOV ESI, [EBP+0x3084]     // hash
…
// loop: lock check strings; head/next/payload; vtbl 0x3d8/0x440; +0x2b0→0xb0
…
MOV ECX, [EBP+0x3084]
PUSH EBX
MOV byte [ECX+0x1d], 0    // unlock
MOV EAX, [EBP+0x3084]
MOV BL, 2
CALL 0x004195d0           // CNDHash_Recreate_00a2c2e4
POP EBX
POP EDI / ESI / EBP
RET 4
```

Callers:

```text
009348bc  PUSH EBX ; CALL 007fe640   // host rebuild
009349d4  PUSH EDI ; CALL 007fe640   // host teardown (+0xf40 gate)
```

A ≡ B on live decompile CF + recreate handoff bytes.

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Traverse + teardown CF | **High** | Wrong host clear semantics |
| Unlock-then-recreate order | **High** | Wrong lock protocol |
| EAX/BL recreate ABI | **High** | Wrong port of nested dual |
| Host field +0x3084 | **High** | Wrong object layout |
| Product English | **Open** | Naming only |
| Runtime | **Open** | — |

---

## 4. Surviving contract

```text
Host_CNDHash_TraverseTeardownThenRecreate_BL2_Inferred:
  stdcall owner*; RET 4
  hash = *(owner+0x3084); if null return
  lock soft-assert; ordered walk + object vtbl teardown
  unlock; Recreate(EAX=hash, BL=2)
```

**Verdict:** **accept-with-gaps**
