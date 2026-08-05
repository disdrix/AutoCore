# Review B (skeptical / adversarial): `aa_0067b070` Net_SockaddrIn_InitZero

| Field | Value |
|---|---|
| **Stable ID** | `aa_0067b070` |
| **VA** | `0x0067b070` |
| **Canonical name** | `Net_SockaddrIn_InitZero` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W25-O) |
| **Counterpart** | `reviews/A_aa_0067b070_Net_SockaddrIn_InitZero.md` |
| **Scratch** | `tmp/a_0067b070.md` |
| **System** | `network` |
| **Live tools** | Ghidra `decompile_function` + `read_memory` only |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Same as `Net_SockaddrIn_Init` (AF_INET) | Family store is 0, not imm 2; no stack addr/port; plain `ret` not `ret 8` | **Falsified** identity |
| 2 | Leaves buffer uncleared | Four dword zeros after `xor eax,eax` | **Falsified** partial-clear |
| 3 | Applies `htonl` to addr | Only raw `mov [esi+4], eax` with 0 | **Falsified** |
| 4 | Chat / VOGChat helper | Body is zero-fill + htons only | **Falsified** |
| 5 | cdecl with stack out-buffer | `mov esi, ecx` | **Falsified** pure cdecl |
| 6 | Sets AF_INET then zeros | Family written 0 after zero block | **Falsified** AF_INET |
| 7 | Product name proven | Structural only | **Agree Open** |
| 8 | Scaffold invents CF | Live ≡ raw; bytes seal | **Attack fails** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Zero + family0 + addr0 + htons(0) + return this | **Confirmed** | Wrong default endpoint |
| ECX out buffer, plain ret | **Confirmed** | Stack imbalance if ported as ret 8 |
| Distinct from Init AF_INET | **Confirmed** | Wrong bind/connect defaults |
| Product type name | **Open** | Naming only |

---

## 3. Cross-check against raw / live / bytes

Decompiler:

```
*param_1 = 0; … param_1[3] = 0;
*(u16*)param_1 = 0;
param_1[1] = 0;
*(u16*)(param_1+2) = htons(0);
return param_1;
```

Bytes confirm order and IAT `htons` at `0x009c6830`. Sibling Init uses `66 C7 06 02 00` (AF_INET) + `ret 8` — **do not** merge the two leaves.

### Family / port traps

| Helper | family | port | addr |
|---|---|---|---|
| **InitZero** (this) | `0` | `htons(0)` | `0` |
| Init | `2` AF_INET | `htons(hostPort)` | raw dword |
| InitInvalid | AF_INET via Init | `0xFFFF` | `0xFFFFFFFF` |

---

## 4. Surviving contract for AutoCore

```
Net_SockaddrIn_InitZero(sa):
  memset(sa, 0, 16)
  sa.family = 0
  sa.addr   = 0
  sa.port   = htons(0)
  return sa

AutoCore must NOT:
  - force AF_INET here
  - use ret 8 (no stack args)
  - htonl(addr)
  - treat as chat/VOG logic
  - alias to Net_SockaddrIn_Init body
```

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| Zero sockaddr + return ptr | **Agree Confirmed** |
| 37 B / plain ret / htons IAT | **Agree Confirmed** |
| accept (naming residual) | **Agree** |
| Structural name InitZero | **Agree** as structural; product English **Open** |

---

## 6. Open questions

1. Product/TNL type name (shared with Init family).
2. Whether any path depends on family remaining 0 until overwritten.
3. Runtime golden for htons(0).

**Verdict:** **accept** — adversarial pass; no CF contradictions.
