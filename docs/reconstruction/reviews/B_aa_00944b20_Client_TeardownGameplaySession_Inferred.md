# Review B (skeptical / adversarial): `aa_00944b20` Client_TeardownGameplaySession_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00944b20` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00944b20_Client_TeardownGameplaySession_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is Auth logout wire send | No net send of logout opcode; auth return-to-login is a **caller**; body is local teardown | **Falsified** as `AuthClient_SendLogout` |
| 2 | Standard MSVC `__thiscall` (ECX) | Prologue `MOV ESI,EAX`; sites load **EAX** with `0x00d1a840` | **Falsified** ECX-this; **survives** as EAX-this |
| 3 | Always full deep wipe | Large block gated on `param_1`; always-block is smaller | **Survives** split |
| 4 | `RecvAccountKicked` passes 0 | Site rewrites `[ESP+4]=1` and **JMP**s (tail) | **Falsified** zero-arg claim; flag forced 1 |
| 5 | Only five COM releases | Many named callees after; wipe of `+0x31f0` etc. | **Survives** as multi-stage orchestrator |
| 6 | `operator_delete[]` on `+0xf44` only when full | Outside full gate — always | **Survives** always-path |

---

## 2. Live ≡ raw

Live decompile matches raw scaffold body structure. Callee list from `get_function_callees` matches annotated set. Call-site pattern `MOV EAX,0x00d1a840` + `PUSH 1` confirmed via `read_memory` at login/auth xrefs.

---

## 3. Surviving contract

```
// EAX = client main (typ. 0x00d1a840)
// stack char fullTeardown; RET 4
// fullTeardown: 5× UI Release + audio/mission/map helpers + buffer wipe
// always: delete[] +0xf44; clear flags; optional leave / session gates
```

**Gaps kept:** nested product names; widget RTTI; true zero-flag live path existence.

**Verdict:** **accept-with-gaps**.
