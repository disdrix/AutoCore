# Review B (skeptical / adversarial): `aa_0083ac90` ShopVehList_ReindexFiveSlotWindowAroundSelect_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0083ac90` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY WQ9K-H) |
| **Counterpart** | `reviews/A_aa_0083ac90_ShopVehList_ReindexFiveSlotWindowAroundSelect_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Thiscall ECX=host | **Falsified** — host is stack; ECX used for slot objects / helpers |
| 2 | Select index is a stack arg | **Falsified** — live in **EAX** (`TEST EAX` first; callers MOV EAX then PUSH host) |
| 3 | Full list rebuild / recreate all rows | **Falsified** — only five-slot window + id reassign + optional swap |
| 4 | Always calls swap | **Falsified** — swap only on mismatch + donor found |
| 5 | Is the swap implementation | **Falsified** — **caller** of dualed `00833160` |
| 6 | Window size other than 5 | **Falsified** — `CMP ESI,5` / five-element scan / clear to 5 |
| 7 | Id base is 0 | **Falsified** — `±0x9ca4` in get/set paths |
| 8 | Clears free the slot objects | **Falsified** — set id `-1` + optional `00833d50`; no `operator_delete` on host/slots |
| 9 | Product name sealed from RTTI here | **Fails** — name from call-graph + prior shopveh duals → `_Inferred` |
| 10 | Runtime Confirmed | **Fails** — open |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EAX select + stack host + RET 4 | **High** | Wrong ABI / stack smash |
| +0x4fc / +0x500 / +0x50c[5] | **High** | Window corruption |
| 0x9ca4 id encoding | **High** | Wrong control binding |
| Sole CALL of 00833160 | **High** | Mis-attribute swap ownership |
| Shopveh English | **Med** (caller graph + prior dual) | Naming only |
| Helper semantics (a860/a880/abf0) | **Med** (not OWN) | Refresh edge cases |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check

```text
// Swap site (assembly authority):
//   0083ad64  MOV EDI, [EBP+ESI*4+0x50c]   // target slot
//   0083ad6b  MOV ESI, [EBP+EBX*4+0x50c]   // donor slot
//   0083ad72  CALL 0x00833160              // sole caller
// Matches WQ9J-D dual note: ESI/EDI register-pair swap.
// Callers push host, leave select in EAX (0083b30a MOV EAX,[ESI+0x558]; PUSH EDI; CALL).
```

A ≡ B on live decompile + full disasm + xref assembly_context.

---

## 4. Surviving contract for AutoCore

```text
// Port as list-window reindex (not full rebuild):
// - inputs: select_index (register EAX), host* (stack), RET 4
// - write host+0x500 = select
// - for each of 5 window cells: ensure control id == list_i + 0x9ca4
// - on occupancy conflict: swap two slot objects then fix ids
// - clear leading/trailing unused slots to id -1
// Do not treat as thiscall; do not free host; do not invent RTTI name.
```

---

## 5. Verdict

Adversarial pass confirms A's ABI, window math, id base, and sole-swap-caller facts. Rejects thiscall/full-rebuild/always-swap/free overclaims. Residual product English + helper duals → **accept-with-gaps**.
