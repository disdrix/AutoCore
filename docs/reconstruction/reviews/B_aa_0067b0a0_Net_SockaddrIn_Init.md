# Review B (skeptical / adversarial): `aa_0067b0a0` `Net_SockaddrIn_Init`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0067b0a0` |
| **VA** | `0x0067b0a0` |
| **Canonical name** | `Net_SockaddrIn_Init` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0067b0a0_Net_SockaddrIn_Init.md` |
| **System** | `network` |
| **Live tools** | Ghidra `decompile_function` + `read_memory` only |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Leaves buffer uncleared / partial | Four dword stores after `xor eax,eax` | **Falsified** partial-clear |
| 2 | Sets family after addr would clobber port | Order: zero → family → addr → htons → port | **Attack fails** |
| 3 | Applies `htonl` to addr | No `htonl` call; only raw `mov [esi+4], edx` | **Falsified** htonl claim if asserted |
| 4 | cdecl / no this | `mov esi, ecx`; `ret 8` | **Falsified** pure cdecl |
| 5 | stdcall without ECX this | `ECX` is out buffer throughout | **Falsified** |
| 6 | Auth/crypto helper | Body is only fill + htons | **Falsified** as crypto |
| 7 | Many direct callers (confusion with InitInvalid) | xrefs show **2** direct call sites | **Falsified** multi-caller-on-leaf (wrapper has many) |
| 8 | Scaffold invents CF | Live ≡ raw; bytes seal | **Attack fails** |
| 9 | Product name proven | Structural only | **Agree Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Zero + AF_INET + addr + htons(port) + return this | **Confirmed** | Wrong endpoint fill |
| thiscall `ret 8` | **Confirmed** | Stack imbalance in callers |
| No htonl | **Confirmed** | Wrong wire endian if AutoCore adds htonl blindly |
| Product type name | **Open** | Naming only |
| Exactly two direct callers | **Confirmed** static xrefs | Missed dynamic/vtbl — none found |

---

## 3. Cross-check against raw / live / bytes

Decompiler:

```
*param_1 = 0; … param_1[3] = 0;
*(u16*)param_1 = 2;
param_1[1] = param_2;
*(u16*)(param_1+2) = htons(param_3);
return param_1;
```

Bytes confirm the same order and the **IAT** `htons` at `0x009c6830`. Decompiler correctly shows thiscall; sibling `FUN_00681950` decompile may omit ECX — **do not** trust incomplete parent decompiles for this leaf’s ABI.

### INADDR / port traps (for callers)

| Call pattern | Result family | port | addr |
|---|---|---|---|
| InitInvalid (−1, −1) | AF_INET | `0xFFFF` | `0xFFFFFFFF` (NONE) |
| `FUN_00681950` (0, port) | AF_INET | htons(port) | `0` (ANY as dword) |

`0xFFFFFFFF` is **INADDR_NONE**, not ANY. Zero addr is ANY as a 32-bit value only if interpreted as `0.0.0.0`.

### Auth-name trap

Prior alias chains through `Client_EncryptAndPrepareAuthRequest` via **InitInvalid**, not this leaf’s role. This unit does not encrypt.

---

## 4. Surviving contract for AutoCore

```
Net_SockaddrIn_Init(sa, addr, hostPort):
  memset(sa, 0, 16)
  sa.family = AF_INET (2)
  sa.addr   = addr          // raw; do NOT htonl here
  sa.port   = htons(hostPort)
  return sa

AutoCore must NOT:
  - omit ECX = sa (thiscall)
  - forget callee cleans 8 stack bytes
  - silently htonl(addr) inside this helper
  - treat as encryption
```

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| Fill AF_INET endpoint + return ptr | **Agree Confirmed** |
| 49 B / ret 8 / no htonl | **Agree Confirmed** |
| accept (naming residual only) | **Agree** |
| Structural name `Net_SockaddrIn_Init` | **Agree** as structural; product English **Open** |

---

## 6. Open questions

1. Product/TNL type name.
2. Whether any non-static call path exists (unlikely; no DATA xrefs on entry).
3. Runtime golden for htons edge ports (0, 0xFFFF).

**Verdict:** **accept** — adversarial pass; no CF contradictions.
