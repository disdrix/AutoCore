# Review B (skeptical / adversarial): `aa_0083abf0` ShopVehList_BindSlotFromListIndexIfMismatch_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0083abf0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY WQ9L-J) |
| **Counterpart** | `reviews/A_aa_0083abf0_ShopVehList_BindSlotFromListIndexIfMismatch_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Thiscall ECX=host | **Falsified** — host is stack (`MOV EBP,[ESP+8]`); ECX is slot index then later slot_obj for ab90 |
| 2 | Always rebinds | **Falsified** — equal bound id short-circuits (`CMP EDI,EAX; JZ epilogue`) |
| 3 | Slot count other than 5 | **Falsified** — `CMP ECX,5; JGE exit` matches parent five-slot window |
| 4 | List container is host+0x508 | **Falsified** — container is `*(host+0x508)+0x2c` (`LEA EDI,[EAX+0x2c]`) |
| 5 | Is the bind implementation | **Falsified** — **caller** of residual `FUN_0083ab90`; this unit is mismatch gate + list lookup |
| 6 | Decompiler `FUN_0083ab90(host)` is full ABI | **Partial fail of decompiler** — assembly `PUSH host; MOV ECX,slot_obj; CALL` with **EAX**=entity id from vtbl. Annotated/clean correct |
| 7 | Product name sealed from RTTI here | **Fails** — shopveh English from parent reindex dual → `_Inferred` |
| 8 | Runtime Confirmed | **Fails** — open (no Launcher) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX slot + EDX list_i + stack host + RET 4 | **High** | Wrong ABI / stack smash |
| Gates + slots[5] at host+0x50c | **High** | Wrong bind target |
| List container nested+0x2c | **High** | Wrong list lookup |
| Mismatch via slot+0x508 / +0x50c vs vtbl+0x1d4 | **High** | Spurious rebinds / missed binds |
| ab90 / 427d20 helper English | **Med** (not OWN) | Bind edge cases |
| Shopveh English | **Med** (parent dual) | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check

```text
// Parent reindex call sites (assembly authority) — all three identical ABI:
//   PUSH EBP          // host
//   MOV ECX,ESI       // slot index
//   MOV EDX,EDI       // list_i
//   CALL 0x0083abf0
// Sites: 0083ad5a, 0083adb7, 0083add0 (FUN_0083ac90 only).
// Bind tail:
//   CALL [vtbl+0x1d4]  // entity id → EAX
//   PUSH EBP           // host
//   MOV ECX,EBX        // slot_obj
//   CALL 0x0083ab90
// Body ends RET 4; pad CC×6 then parent 0083ac90.
```

A ≡ B on live decompile + full disasm + xref assembly_context.

---

## 4. Surviving contract for AutoCore

```text
// Port as conditional bind from list index:
// - inputs: slot (ECX), list_i (EDX), host* (stack), RET 4
// - gate: list_i>=0, host+0x508, slot∈[0,5), slots[slot], *(nested+0x50)
// - lookup entity via FUN_00427d20 on container (nested+0x2c)
// - if unbound or bound id != entity->GetId-like(vtbl+0x1d4): FUN_0083ab90(slot_obj, host, entity_id)
// - if already matching: no-op
// Do not treat as thiscall on host; do not always rebind; do not invent RTTI name.
```

---

## 5. Verdict

Adversarial pass confirms A's ABI, gates, list-container offset, mismatch condition, and sole parent call sites. Rejects thiscall-on-host / always-rebind / wrong-container overclaims. Residual product English + helper duals → **accept-with-gaps**.
