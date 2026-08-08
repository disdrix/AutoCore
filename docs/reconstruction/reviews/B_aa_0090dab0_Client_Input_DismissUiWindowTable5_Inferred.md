# Review B (skeptical / adversarial): `aa_0090dab0` Client_Input_DismissUiWindowTable5_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0090dab0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY MEGA-097) |
| **Counterpart** | `reviews/A_aa_0090dab0_Client_Input_DismissUiWindowTable5_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | True void / no inputs (decompiler signature) | **Falsified as complete** — `MOV EDI,EAX` + call-site `MOV EAX,EBX` seal host in **EAX** |
| 2 | ECX thiscall | **Falsified** — no `MOV reg,ECX`; host is EAX; parent is thiscall but reloads EAX from EBX |
| 3 | Host arg is return of `FUN_0090d390` (window*) | **Falsified** — after TEST EAX, parent does `MOV EAX,EBX` before CALL; window return only gates the branch |
| 4 | `RET 4` / stack host | **Falsified** — bare `C3`; no stack traffic for host |
| 5 | Infinite / unbounded table walk | **Falsified** — exclusive end `0xd09a4c` → exactly 5 dwords |
| 6 | Unit itself implements dismiss vcalls | **Falsified** — only CALL is `FUN_0090d400`; this unit is the walker |
| 7 | Scaffold `Named_CalleeOf_OnKeyDown_*` is product name | **Falsified** — parent-seed rename only; structural name from table+ESC role |
| 8 | Same as `FUN_0090d390` (find active) | **Falsified** — sibling finds first active; this always walks all five and calls dismiss helper |
| 9 | Same as keybind table scan (`DAT_00d1bc18`) | **Falsified** — different table (`d09a38`), ESC path only |
| 10 | Second xref `0x00911893` is a different function | **Not established as different owner** — no function entry at site; bytes are still `MOV EAX,EBX; CALL 0090dab0` (same ABI). Decompile of parent shows one call; second site may be alternate/unreachable layout — does not change ABI/CF of this unit |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ABI EAX-host / bare RET | **High** | Wrong call convention on port |
| 5-slot bounds | **High** | Buffer over/under walk |
| ESC parent role | **High** | Misplace in input pipeline |
| Callee dismiss details | **Med** (evidence only) | Wrong if porting 0090d400 from this plate alone |
| Product window English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

Live 2026-08-05 decompile ≡ raw 2026-07-23 CF (do/while table walk + `FUN_0090d400`). Disasm + `read_memory` seal EAX-host and 38 B body the decompiler under-specified. Parent clean `Client_Input_OnKeyDown_MatchAction` places call under ESC + `+0x50d` + `FUN_0090d390` gate. Table init WRITE xrefs in `FUN_0093e7e0` confirm five UI object pointers.

---

## 4. Surviving contract for AutoCore

```text
// After any DAT_00d09a38[i] reports active (vtbl+0x3d8):
//   host in EAX (custom), then:
Client_Input_DismissUiWindowTable5_Inferred(host);
// walks 5 slots → FUN_0090d400(ESI=slot, EDI=host) each
// Do NOT use ECX thiscall. Do NOT pass the found window* as host.
// Pair with FUN_0090d390 (gate) and FUN_0090d400 (per-slot).
```

---

## 5. Verdict

Adversarial attacks on void-true/ECX/window-as-host/RET4/unbounded/product-scaffold claims fail. Residual product English only → **accept-with-gaps**. Terminal **false**.
