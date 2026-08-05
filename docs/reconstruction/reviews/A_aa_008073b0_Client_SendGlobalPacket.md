# Review A (reconstruction fidelity): `aa_008073b0` Client_SendGlobalPacket

| Field | Value |
|---|---|
| **Stable ID** | `aa_008073b0` |
| **VA** | `0x008073b0`–`0x008073ee` |
| **Canonical name** | `Client_SendGlobalPacket` |
| **Ghidra name** | `FUN_008073b0` |
| **Review date** | `2026-07-29` (OWN-ONLY dual W18-B) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_008073b0_Client_SendGlobalPacket.md` |
| **System** | network-global |
| **Live tools** | Ghidra `decompile_function` + `read_memory` only (`autoassault.exe`) |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** |

---

## 1. Purpose

Generic C2S **global** transport: if `client+0xc7c` connection is non-null and `vtbl+0x08` ready-check passes, call `vtbl+0x18(0xFFFFFFFF, buffer, (int)size, 0)` and return **0**; else **`E_FAIL` (`0x80004005`)**.

Sibling of **`Client_SendSectorPacket`** (`aa_00807460`, `client+0xc78`).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live decompile | `decompile_function` @ `0x008073b0` — ≡ 2026-07-23 raw |
| Sibling dual | `Client_SendSectorPacket` reviews/function @ `0x00807460` |
| Raw | `docs/reconstruction/raw/aa_008073b0_FUN_008073b0.md` (+ residual seal) |
| Annotated | `docs/reconstruction/raw/aa_008073b0_FUN_008073b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_SendGlobalPacket.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_008073b0.cpp` |
| Function record | `docs/reconstruction/functions/aa_008073b0_Client_SendGlobalPacket.md` |
| Live bytes | `read_memory` 64 B @ `0x008073b0` — full body to `ret 8` + `CC` |
| Parent duals | chat `aa_00941fb0` (global `0x8000`); dismiss modal `aa_007fc360` (`0x8006`) |

**Not performed:** `disassemble_bytes`, Launcher, exhaustive 50+ ESI census, runtime wire.

---

## 3. Byte seal (full body)

```
83 BE 7C 0C 00 00 00     cmp  [esi+0xc7c], 0
74 0F                     jz   E_FAIL
8B 8E 7C 0C 00 00         mov  ecx, [esi+0xc7c]
8B 01 FF 50 08            call [vtbl+8]
84 C0 75 08               test al; jnz send
B8 05 40 00 80            mov  eax, 0x80004005
C2 08 00                  ret  8
0F BF 44 24 04            movsx eax, word [esp+4]   ; size
... push 0, size, buffer, -1; call [vtbl+0x18]
33 C0 C2 08 00            xor eax,eax; ret 8
```

| Claim | Confidence | Evidence |
|---|---|---|
| Client in **ESI** (not ECX) | **High** | all `[esi+0xc7c]` |
| Conn at **`+0xc7c`** | **High** | imm `7C 0C 00 00` |
| Ready = **vtbl+0x08** | **High** | `FF 50 08` |
| Send = **vtbl+0x18** | **High** | `FF 52 18` |
| Args: mask **-1**, buf, **(int)size**, flags **0** | **High** | push order |
| Size is **signed short** | **High** | `0F BF` movsx |
| Fail **`0x80004005`**, success **0** | **High** | imm + xor |
| **`ret 8`** (2 stack args) | **High** | both paths |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Null conn → E_FAIL | **Yes** |
| Ready false → E_FAIL | **Yes** |
| Send + return 0 | **Yes** |
| Flags hardcode 0 (no EAX algebra) | **Yes** |
| No modernization | **Yes** |

---

## 5. Sibling contrast (sealed)

| | Global (this) | Sector `0x00807460` |
|---|---|---|
| Register | ESI | ECX thiscall |
| Slot | +0xc7c | +0xc78 |
| Ready | vtbl+8 | none |
| Null | E_FAIL | silent 0 |
| Flags | 0 fixed | `~(EAX>>2)&2` |

---

## 6. Gaps

1. Product connection class / vtbl method names.
2. Exhaustive proof every caller leaves client in ESI (chat/modal paths High via parents; not 100% of 50+).
3. Why global fails hard vs sector silent-drop.
4. Runtime / bit-exact / wire capture.

**Verdict:** CF + ABI + offsets + E_FAIL sealed. **accept-with-gaps.**
