# Review A (reconstruction fidelity): `aa_0067b070` Net_SockaddrIn_InitZero

| Field | Value |
|---|---|
| **Stable ID** | `aa_0067b070` |
| **VA** | `0x0067b070` |
| **Body span** | `0067b070`–`0067b094` (37 B through plain `ret`) |
| **Canonical name** | `Net_SockaddrIn_InitZero` (structural / **Inferred**) |
| **Ghidra name** | `FUN_0067b070` |
| **Review date** | `2026-07-29` (OWN-ONLY dual W25-O) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0067b070_Net_SockaddrIn_InitZero.md` |
| **System** | `network` / sockaddr fill |
| **Live tools** | Ghidra `decompile_function` + `read_memory` + callers/callees (no `disassemble_bytes`) |
| **Verdict** | **accept** |

---

## 1. Purpose

**Zero-initialize a 16-byte IPv4 `sockaddr_in`-shaped buffer** and return it:

1. Zero all 16 bytes (four dwords).
2. Set family word **0**.
3. Set addr dword **0**.
4. `htons(0)` → port at `+2`.
5. Return `param_1` (this / out buffer).

Near-clone of sealed `Net_SockaddrIn_Init` (`0x0067b0a0`) without AF_INET/addr/port args.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0067b070_FUN_0067b070.md` (+ W25-O append) |
| Annotated | `docs/reconstruction/raw/aa_0067b070_FUN_0067b070.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Net_SockaddrIn_InitZero.cpp` |
| Scaffold clean | `reconstructed-exact/FUN_0067b070.cpp` |
| Function record | `docs/reconstruction/functions/aa_0067b070_FUN_0067b070.md` |
| Live decompile | Ghidra @ `0x0067b070` |
| Bytes | `read_memory` 64 B @ `0x0067b070` |
| Xrefs | 13 call sites / 12 symbols |
| Sibling context | `Net_SockaddrIn_Init` dual (`aa_0067b0a0`); `InitInvalid` (`aa_0046e280`) |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Assembly-sealed body (`read_memory` @ `0x0067b070`)

```text
0067b070  33C0            xor  eax, eax
0067b072  56              push esi
0067b073  8BF1            mov  esi, ecx            ; this = out
0067b075  8901            mov  [ecx], eax          ; zero 16 B
0067b077  894104          mov  [ecx+4], eax
0067b07a  894108          mov  [ecx+8], eax
0067b07d  89410C          mov  [ecx+0xC], eax
0067b080  50              push eax                 ; htons(0)
0067b081  668906          mov  word ptr [esi], 0   ; family
0067b084  894604          mov  [esi+4], eax        ; addr 0
0067b087  FF1530689C00    call [0x009c6830]        ; htons
0067b08d  66894602        mov  [esi+2], ax         ; port
0067b091  8BC6            mov  eax, esi
0067b093  5E              pop  esi
0067b094  C3              ret
```

Hex (body through `ret`):

```
33c0568bf1890189410489410889410c50668906894604ff1530689c00668946028bc65ec3
```

| Claim | Evidence | Conf |
|---|---|---|
| Body **37 bytes** through plain `ret` | `read_memory` + `CC` pad | **Confirmed** |
| thiscall/fastcall ECX out | `mov esi, ecx` | **Confirmed** |
| Family **0** (not AF_INET) | `66 89 06` after xor | **Confirmed** |
| Port via htons IAT | `FF 15 30 68 9C 00` | **Confirmed** |
| No htonl | no call | **Confirmed** |
| Return = this | `mov eax, esi` | **Confirmed** |
| Live decompile ≡ raw | side-by-side | **Confirmed** |
| Clean ≡ raw CF | three-rep | **High** |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Role = zero sockaddr_in buffer | **Confirmed** | layout + htons(0) + callers |
| 16-byte out-buffer | **Confirmed** | four dword zeros |
| Sibling of Init @ `0067b0a0` | **High** | near-identical skeleton |
| Product type name | **Open** | structural name sealed |
| Prior VOGChat alias | **Falsified** as semantics | pure fill |

---

## 5. Call graph (this unit)

**Callees:** `htons` (Winsock IAT `0x009c6830`)

**Callers (sample / all 12):** net object ctors, `FUN_0067b9a0` (getsockname), `FUN_0067ba30` (getpeername), login/UI net helpers.

---

## 6. Gaps

1. Product English / TNL type name for the 16-byte object.
2. OWN dual of several callers remains outside W25-O.
3. Runtime / bit-exact deferred.

**Verdict:** **accept** — OWN CF Confirmed; residual is naming only.
