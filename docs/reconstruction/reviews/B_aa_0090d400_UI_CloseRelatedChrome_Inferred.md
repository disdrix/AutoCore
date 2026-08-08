# Review B (adversarial): `aa_0090d400` UI_CloseRelatedChrome_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0090d400` |
| **VA** | `0x0090d400`–`0x0090d465` inclusive (**102 B**) |
| **Canonical name** | `UI_CloseRelatedChrome_Inferred` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Adversarial / reject-oriented (Path B) |
| **Counterpart** | `reviews/A_aa_0090d400_UI_CloseRelatedChrome_Inferred.md` |
| **Agent** | OWN-ONLY dual **MEGA-086** |
| **Live tools** | same as Path A (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** — adversarial alternates falsified; residual product English only |

---

## 1. Attack surface (claims to falsify)

| # | Adversarial claim | Result |
|---|---|---|
| 1 | ECX-thiscall entry / `ret 4` stack formal | **Falsified** — entry `TEST ESI,ESI`; epilogue bare `C3` |
| 2 | Leaf empty / no-op / pure return | **Falsified** — 7 vcalls; multi-branch CF |
| 3 | OnKeyDown / input-binding helper (scaffold name) | **Falsified** — no input edges; parent is interaction-menu populate + chrome table flush |
| 4 | Static callees `FUN_*` graph | **Falsified** — analyze callees empty; all virtual |
| 5 | ESI always host and EDI always chrome | **Falsified as universal** — table flush inverts assignment; body is role-by-register not role-by-class |
| 6 | ESI always chrome and EDI always host | **Falsified as universal** — menu family puts host in ESI and chrome in EDI |
| 7 | Closes only `DAT_00d1b978` | **Falsified** — global is optional re-bind target, not primary |
| 8 | Same as `Client_DismissProgressBar` / modal dismiss | **Falsified** — different ABI (client ESI+field vs dual ESI/EDI objects); shared vtbl vocabulary only |
| 9 | Product demangle sealed without `_Inferred` | **Falsified** — no RTTI/string on VA; name remains `_Inferred` |
| 10 | Runtime Confirmed / Terminal true | **Falsified** — no Launcher; Terminal false |

---

## 2. Evidence that closes attacks

### ABI

```text
0090d400  TEST ESI,ESI     ; not MOV ESI,ECX / not stack load
...
0090d465  RET              ; C3, not C2 04 00
```

`read_memory` head `85 F6 74 61 … C3` seals null-gate + bare return.

### Scaffold misname

Parent dual WQ9E-D sealed `FUN_0082fe20` → `FUN_0090d400` as **optional close** when `host+0x2B0 != 0`. OnKeyDown Named_CalleeOf chain has **no** support at this VA.

### Dual call-site families

| Site | Setup | Implication |
|---|---|---|
| `0082fe3f` | `MOV EDI,[ESI+0x2B0]` (ESI=host) | menu: close host, notify chrome |
| `008300d7` | `MOV EDI,[EBP+0x2B0]` / `MOV ESI,EBP` | same family |
| `0090dab3` | `MOV EDI,EAX` / `MOV ESI,[table]` | table: close chrome, notify host |

Body is **register-role** (primary/secondary), not fixed host/chrome mapping. Any claim that freezes one mapping for all callers is wrong.

### Vtbl vocabulary (shared, not identity)

`+0x3d8` visibility and `+0x440` close/flush appear in dualed dismiss/flush paths; does **not** merge this unit into those functions (different object wiring and secondary notify/`+0x3f4(-1)` tail).

---

## 3. Residual risks (do not block accept-with-gaps)

1. Product English for classes and six vtbl slots.
2. Whether menu-family “close host” is intentional product design or historical register convention — static evidence supports intentional dual use; runtime still open.
3. `DAT_00d1b978` identity (Tell/chat indicated via `0x11176` peer only).
4. No runtime / bit-exact / differential.

---

## 4. Verdict

**accept-with-gaps.** CF, ABI, offsets, xref fan-out, and dual call-site families are sealed. Scaffold OnKeyDown name rejected. Product demangle and runtime remain open — `_Inferred` retained; Terminal **false**.
