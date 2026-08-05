# Review A (reconstruction fidelity): `aa_00944b20` Client_TeardownGameplaySession_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00944b20` |
| **VA** | `0x00944b20`–`0x00944d03` |
| **Canonical name (Ghidra)** | `FUN_00944b20` |
| **Proposed name** | `Client_TeardownGameplaySession_Inferred` (**Probable** role; product name absent) |
| **Prior scaffold alias** | `Named_CalleeOf_Client_RecvLoginCallback_3_00944b20` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra W17-T) |
| **Reviewer role** | Reconstruction fidelity (session teardown orchestrator) |
| **Counterpart** | `reviews/B_aa_00944b20_Client_TeardownGameplaySession_Inferred.md` |
| **System** | client-session / login / return-to-login |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Gameplay / UI session teardown** on the client main object. Used when leaving a failed or kicked session and when returning to login:

| Caller | Context |
|---|---|
| `Client_RecvLoginCallback_7` | `RecvPlayFail` → full teardown then fail UI |
| `Client_RecvLoginCallback_3` | login-fail family |
| `Client_RecvLoginCallback_9` | `RecvAccountKicked` (tail-JMP; forces flag=1) |
| `FUN_00812de0` | Auth accept / connection-terminated return-to-login |
| `FUN_009463b0` | reinitPhysics missing-content → message + teardown |

Typical site: `PUSH 1; MOV EAX, 0x00d1a840; CALL 0x00944b20`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00944b20_FUN_00944b20.md` (+ v2026-07-29 append) |
| Annotated | `docs/reconstruction/raw/aa_00944b20_FUN_00944b20.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_TeardownGameplaySession_Inferred.cpp` |
| Function record | `docs/reconstruction/functions/aa_00944b20_Client_TeardownGameplaySession_Inferred.md` |
| Live Ghidra | `decompile_function` `0x00944b20`; `analyze_function_complete`; callers/callees; `read_memory` 500 B; call-site bytes at login/auth |
| Parent context | `Client_RecvLoginCallback_7/9`, Auth return-to-login cleans |

**Not performed:** Launcher, runtime, bit-exact, parent ledger edits, `disassemble_bytes`. Nested callee bodies **not** owned.

---

## 3. Signature

```c
// this in EAX (not ECX); stack char fullTeardown; RET 4
void Client_TeardownGameplaySession_Inferred(void *self /*EAX*/, char fullTeardown);
```

| Item | Evidence |
|---|---|
| EAX this | Prologue `MOV ESI,EAX`; call sites `MOV EAX,0x00d1a840` |
| Stack char | `CMP [ESP+0xC],BL` after two pushes; `RET 4` |
| Body range | Entry `00944b20`, last `00944d03` (`get_function_by_address`) |

---

## 4. Control flow (sealed structure)

```
if (fullTeardown) {
  // 5× (flag pair + optional COM Release vtbl+4(0))
  // slots: +0x309c, +0x30a8, +0x30a4, +0x30ac, +0x30b0
  // helpers: 007fc970, 007fc360, GetMissionCompleteAudioTable, 007246d0,
  //          optional 005742a0, zero +0x31f0[0x82 dwords] then *buf=-1,
  //          00943db0, 0079e7d0(+0xde8), 00943b80(0), 00442fa0 zeros, 00410420 zeros
}
// always:
delete[] +0xf44; +0xf44=0; FUN_008076c0(); +0x113=0; +0x134=0;
if (fullTeardown) FUN_00801c50(self);
if (+0xf40 non-null && **+0xf40 == *+0xf38) {
  if (fullTeardown) FUN_009302b0();
  FUN_00937560(self);
}
if (DAT_00d1b77c) {
  if (fullTeardown) FUN_0048f370();
  FUN_009133a0(0);
}
```

| Stage | Match clean≡raw≡live |
|---|---|
| Full vs always split | **Yes** |
| Five COM slots + flag pairs | **Yes** |
| `0x82` dword wipe + `-1` | **Yes** |
| `+0xf44` delete always | **Yes** |
| `DAT_00d1b77c` gate | **Yes** |
| Callee set (17) | **Yes** (`get_function_callees`) |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| ABI EAX-this + stack char + RET 4 | **High** | prologue/epilogue + sites |
| Full/partial branch semantics | **High** | decompile + bytes |
| Offset table for five widgets | **High** | repeated pattern |
| Role = session/gameplay teardown | **High** | caller strings (PlayFail, AccountKicked, return-to-login) |
| Unit product English name | **Probable** | `_Inferred` |
| Nested callee product names | **Tentative** | not owned |
| Widget type identity | **Tentative** | COM* + Release-like only |

---

## 6. Gaps / open

1. Product names for five UI objects and most nested helpers.
2. Whether any path truly passes `fullTeardown=0` (kicked forces 1).
3. Exact type of `+0x31f0` buffer and `+0xf40`/`+0xf38` pair.
4. Runtime / bit-exact not run.

**Verdict:** **accept-with-gaps** — orchestration CF/ABI High; nested product names open.
