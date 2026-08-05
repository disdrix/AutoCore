# Review A (reconstruction fidelity): `aa_0067b0a0` `Net_SockaddrIn_Init`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0067b0a0` |
| **VA** | `0x0067b0a0` |
| **Body span** | `0067b0a0`–`0067b0ce` (49 B through `ret 8`) |
| **Canonical name** | `Net_SockaddrIn_Init` (structural) |
| **Ghidra name** | `FUN_0067b0a0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual W17-C) |
| **Counterpart** | `reviews/B_aa_0067b0a0_Net_SockaddrIn_Init.md` |
| **System** | `network` / sockaddr fill |
| **Live tools** | Ghidra `decompile_function` + `read_memory` + `get_function_xrefs` (no `disassemble_bytes`) |
| **Verdict** | **accept** |

---

## 1. Purpose

**Initialize an IPv4 `sockaddr_in`-shaped 16-byte buffer in place** and return it:

1. Zero all 16 bytes.
2. Set family **`2` (AF_INET)**.
3. Store **`param_2`** at `+4` as IPv4 address dword (**no `htonl`**).
4. `htons(param_3)` → store at `+2`.
5. Return `param_1` (this / out buffer).

Shared leaf used by invalid-endpoint wrapper and at least one other net helper.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0067b0a0_FUN_0067b0a0.md` (+ 2026-07-29 live append) |
| Annotated | `docs/reconstruction/raw/aa_0067b0a0_FUN_0067b0a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Net_SockaddrIn_Init.cpp` |
| Scaffold clean | `reconstructed-exact/FUN_0067b0a0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0067b0a0_Net_SockaddrIn_Init.md` |
| Live decompile | Ghidra @ `0x0067b0a0` |
| Bytes | `read_memory` 64 B @ `0x0067b0a0` |
| Xrefs | `get_function_xrefs` — 2 callers |
| Sibling context | `Net_SockaddrIn_InitInvalid` dual (`aa_0046e280`) |

**Not performed:** `disassemble_bytes`, Launcher, runtime bind/connect golden.

---

## 3. Assembly-sealed body (`read_memory` @ `0x0067b0a0`)

```text
0067b0a0  8B542404        mov  edx, [esp+4]        ; addr
0067b0a4  33C0            xor  eax, eax
0067b0a6  56              push esi
0067b0a7  8BF1            mov  esi, ecx            ; this = out
0067b0a9  8901            mov  [ecx], eax          ; zero 16 B
0067b0ab  894104          mov  [ecx+4], eax
0067b0ae  894108          mov  [ecx+8], eax
0067b0b1  89410C          mov  [ecx+0xC], eax
0067b0b4  8B44240C        mov  eax, [esp+0xC]      ; port (post push)
0067b0b8  50              push eax
0067b0b9  66C7060200      mov  word ptr [esi], 2   ; AF_INET
0067b0be  895604          mov  [esi+4], edx        ; addr raw
0067b0c1  FF1530689C00    call [0x009c6830]        ; htons
0067b0c7  66894602        mov  [esi+2], ax         ; port net order
0067b0cb  8BC6            mov  eax, esi
0067b0cd  5E              pop  esi
0067b0ce  C20800          ret  8
```

Hex (body through `ret 8`):

```
8b54240433c0568bf1890189410489410889410c8b44240c5066c7060200895604ff1530689c00668946028bc65ec20800
```

| Claim | Evidence | Conf |
|---|---|---|
| Body **49 bytes** through `ret 8` | `read_memory` + `CC` pad | **Confirmed** |
| thiscall + 2 stack args | `ECX` this; `C2 08 00` | **Confirmed** |
| Family imm **2** | `66 C7 06 02 00` | **Confirmed** |
| Addr no htonl | `mov [esi+4], edx` only | **Confirmed** |
| Port via htons IAT | `FF 15 30 68 9C 00` | **Confirmed** |
| Return = this | `mov eax, esi` | **Confirmed** |
| Live decompile ≡ raw | side-by-side | **Confirmed** |
| Clean ≡ raw CF | three-rep | **High** |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Role = fill AF_INET endpoint | **Confirmed** | constants + htons |
| 16-byte out-buffer | **Confirmed** | four dword zeros |
| Product type name | **Open** | structural name sealed |
| Direct callers = 2 | **Confirmed** | xrefs |
| Used by InitInvalid (−1, −1) | **Confirmed** | sibling dual + call site |
| Addr byte-order product policy | **Open** | static: no htonl |

---

## 5. Call graph (this unit)

**Callees:** `htons` (Winsock IAT)

**Callers:**

| Symbol | VA |
|---|---|
| `Net_SockaddrIn_InitInvalid` | `0x0046e280` |
| `FUN_00681950` | `0x00681950` |

---

## 6. Gaps

1. Product English / TNL type name for the 16-byte object.
2. OWN dual of `FUN_00681950` (addr=0 fill path) — out of OWN.
3. Runtime / bit-exact deferred.

**Verdict:** **accept** — OWN CF Confirmed end-to-end; residual is naming only.
