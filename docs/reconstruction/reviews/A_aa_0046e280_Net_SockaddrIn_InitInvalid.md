# Review A (reconstruction fidelity): `aa_0046e280` `Net_SockaddrIn_InitInvalid`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0046e280` |
| **VA** | `0x0046e280` |
| **Body span** | `0046e280`–`0046e29d` |
| **Canonical name** | `Net_SockaddrIn_InitInvalid` (structural) |
| **Ghidra name** | `FUN_0046e280` |
| **Prior alias** | `Named_CalleeOf_Client_EncryptAndPrepareAuthRequest_0046e280` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual W16-P) |
| **Counterpart** | `reviews/B_aa_0046e280_Net_SockaddrIn_InitInvalid.md` |
| **System** | `network` / sockaddr fill |
| **Live tools** | Ghidra `decompile_function` + `read_memory` + `get_function_callers` (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Initialize invalid IPv4 endpoint in place** and return the buffer pointer:

1. `FUN_0067b0a0(this=param_1, addr=0xFFFFFFFF, port=0xFFFF)`.
2. Return `param_1`.

Resulting 16-byte layout (via callee):

| Off | Field | Value |
|---|---|---|
| +0 | family (u16) | `2` (AF_INET) |
| +2 | port (u16) | `htons(0xFFFF) = 0xFFFF` |
| +4 | addr (u32) | `0xFFFFFFFF` (INADDR_NONE) |
| +8..+F | zero | `0` |

Shared “no address” placeholder for auth-client login prep and many net helpers.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0046e280_FUN_0046e280.md` (+ 2026-07-29 live append) |
| Annotated | `docs/reconstruction/raw/aa_0046e280_FUN_0046e280.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0046e280.cpp` |
| Named alias | `reconstructed-exact/Named_CalleeOf_Client_EncryptAndPrepareAuthRequest_0046e280.cpp` |
| Function record | `docs/reconstruction/functions/aa_0046e280_FUN_0046e280.md` |
| Callee raw (context) | `raw/aa_0067b0a0_FUN_0067b0a0.md` |
| Live decompile | Ghidra @ `0x0046e280` + callee @ `0x0067b0a0` |
| Bytes | `read_memory` 48 B @ `0x0046e280`; 64 B @ `0x0067b0a0` |
| Callers | `get_function_callers` — `Client_EncryptAndPrepareAuthRequest` + ~20 net helpers |

**Not performed:** `disassemble_bytes`, Launcher, runtime bind/connect golden; dual of callee `aa_0067b0a0` (out of OWN).

---

## 3. Assembly-sealed body (`read_memory` @ `0x0046e280`)

```text
0046e280  51              push ecx
0046e281  56              push esi
0046e282  8B74240C        mov  esi, [esp+0xC]      ; param_1
0046e286  6AFF            push -1                  ; port = 0xFFFFFFFF
0046e288  6AFF            push -1                  ; addr = 0xFFFFFFFF
0046e28a  8BCE            mov  ecx, esi            ; this = param_1
0046e28c  C744240C00000000 mov dword ptr [esp+0xC], 0  ; clear saved-ecx slot
0046e294  E807CE2000      call FUN_0067b0a0        ; → 0x0067b0a0
0046e299  8BC6            mov  eax, esi            ; return param_1
0046e29b  5E              pop  esi
0046e29c  59              pop  ecx
0046e29d  C3              ret                      ; cdecl, 1 arg
; CC pad
```

Hex (body through `ret`):

```
51568b74240c6aff6aff8bcec744240c00000000e807ce20008bc65e59c3
```

| Claim | Evidence | Conf |
|---|---|---|
| Body size **30 bytes** | `read_memory` + `CC` | **Confirmed** |
| One stack formal; cdecl `ret` | `C3` | **Confirmed** |
| Both args `0xFFFFFFFF` | `6A FF` ×2 | **Confirmed** |
| ECX = param_1 (thiscall into callee) | `8B CE` | **Confirmed** |
| Return = param_1 | `8B C6` | **Confirmed** |
| Callee @ `0x0067b0a0` | rel32 from `0046e294` | **Confirmed** |
| Decompiler missed ECX | raw shows no this; bytes seal | **Confirmed** gap closed |
| Clean ≡ raw CF + sealed this | three-rep + bytes | **High** |

### Callee layout seal (context, not OWN dual)

`FUN_0067b0a0` bytes: zero 16 B; `mov word [esi], 2`; `[esi+4]=addr`; `htons(port)` → `[esi+2]`; `ret 8`.

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Role = fill invalid AF_INET endpoint | **High** | constants + callee |
| param_1 is 16-byte sockaddr-like out-buffer | **High** | callers pass locals; callee size |
| Product type name (`Address` / TNL / …) | **Open** | structural name sealed |
| Port 0xFFFF is intentional sentinel | **High** as constant; **Open** as product policy |
| Auth-client null-addr path uses this | **Confirmed** | decompile of `0x00728e50` |
| Shared multi-caller leaf | **Confirmed** | `get_function_callers` |

---

## 5. Call graph (this unit)

**Callees:** `FUN_0067b0a0` @ `0x0067b0a0` (sockaddr fill + `htons`)

**Callers (sample):**

| Symbol | VA |
|---|---|
| `Client_EncryptAndPrepareAuthRequest` | `0x00728e50` |
| `FUN_0067c060` / `FUN_0067c120` | `0x0067c060` / `0x0067c120` |
| `FUN_00727c90` … `FUN_00729200` | many auth/net helpers |

---

## 6. Gaps

1. Product English / TNL type name for the 16-byte object.
2. OWN dual of `aa_0067b0a0` (shared helper — layout High but not dual-sealed here).
3. Higher-layer meaning of port `0xFFFF` vs. real port 65535.
4. Runtime / bit-exact deferred.

**Verdict:** **accept-with-gaps** — OWN CF Confirmed; residual is naming + callee dual + product sentinel policy.
