# Review B (skeptical / adversarial): `aa_0046e280` `Net_SockaddrIn_InitInvalid`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0046e280` |
| **VA** | `0x0046e280` |
| **Canonical name** | `Net_SockaddrIn_InitInvalid` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0046e280_Net_SockaddrIn_InitInvalid.md` |
| **System** | `network` |
| **Live tools** | Ghidra `decompile_function` + `read_memory` only |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Decompiler complete: no `this` into callee | Bytes `mov ecx, esi` before call | **Falsified** pure-cdecl callee model |
| 2 | Zeros buffer without AF_INET | Callee stores family `2` | **Falsified** zero-only |
| 3 | Sets INADDR_ANY (`0`) | Imm addr arg `-1` | **Falsified** ANY |
| 4 | Auth-only helper | ≥20 callers across net helpers | **Falsified** auth-only |
| 5 | Encrypts / prepares credentials | Body only fill+return; encryption in parent | **Falsified** as crypto |
| 6 | `__stdcall` / thiscall leaf | `ret` (`C3`) — cdecl 1-arg | **Falsified** stdcall leaf |
| 7 | Scaffold invents CF | Live ≡ raw; constants sealed | **Attack fails** |
| 8 | Product name proven `Net_SockaddrIn_InitInvalid` | Structural only | **Agree Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Call with (this=sa, −1, −1) + return sa | **Confirmed** | Wrong endpoint init |
| Result AF_INET / NONE / FFFF | **High** (depends on callee) | Mis-bind if callee wrong — callee raw matches |
| cdecl 1-arg | **Confirmed** | Wrong caller cleanup |
| Domain-universal net placeholder | **High** | Over-specializing as auth-only |
| Product type name | **Open** | Naming only |

---

## 3. Cross-check against raw / live / bytes

```
mov  esi, [esp+0xC]     ; after two pushes of save regs
push -1                 ; port
push -1                 ; addr
mov  ecx, esi
call 0x0067b0a0
mov  eax, esi
ret
```

Decompiler form `FUN_0067b0a0(0xffffffff,0xffffffff)` is **incomplete without ECX** — Review A correctly seals `this = param_1`. Clean source must pass the buffer as the thiscall receiver.

### INADDR trap

`0xFFFFFFFF` is **INADDR_NONE**, not INADDR_ANY (`0.0.0.0`). Ports that assume “bind any” from this helper are wrong.

### Crypto trap

Prior alias names this as callee of `Client_EncryptAndPrepareAuthRequest` — true as xref, **false as role**. This leaf does not touch DES/credentials; parent does after address branch.

### Stack hygiene note

`mov [esp+0xC], 0` overwrites the saved-ECX slot after the two `-1` pushes. Does not alter CF of fill; do not elevate to EH-registration without more evidence.

---

## 4. Surviving contract for AutoCore

```
Net_SockaddrIn_InitInvalid(sa):
  FUN_0067b0a0(sa, 0xFFFFFFFF, 0xFFFF)   // thiscall
  return sa
  // sa becomes { AF_INET, port 0xFFFF, addr 0xFFFFFFFF, zeros }

AutoCore must NOT:
  - omit setting ECX = sa when calling the fill helper
  - treat as INADDR_ANY
  - treat as encryption/auth crypto
  - assume auth-only use
```

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| Fill invalid endpoint + return ptr | **Agree Confirmed** |
| ECX = param_1 sealed | **Agree Confirmed** |
| accept-with-gaps | **Agree** (naming + callee dual + port policy) |
| Layout High via callee | **Agree High** — flag residual if callee dual later contradicts (unlikely) |

---

## 6. Open questions

1. Product / TNL type name.
2. Dual of `aa_0067b0a0`.
3. Port `0xFFFF` sentinel policy at connect/bind layers.

**Verdict:** **accept-with-gaps** — agree with A; block decompiler-this omission, INADDR_ANY, and crypto misreads.
