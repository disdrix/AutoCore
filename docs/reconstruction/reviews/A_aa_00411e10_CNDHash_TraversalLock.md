# Review A (reconstruction fidelity): `aa_00411e10` CNDHash_TraversalLock

| Field | Value |
|---|---|
| **Stable ID** | `aa_00411e10` |
| **VA** | `0x00411e10` |
| **Canonical name** | `CNDHash_TraversalLock` |
| **Prior alias** | `FUN_00411e10` |
| **Rejected scaffold** | `Named_VOG_DEBUG_STOP_00411e10` |
| **Review date** | `2026-08-05` (OWN-ONLY dual A/B — MEGA-113) |
| **Reviewer role** | Independent reconstruction review (Path A fidelity) |
| **Counterpart** | `reviews/B_aa_00411e10_CNDHash_TraversalLock.md` |
| **System** | interaction-activation / shared CNDHash |
| **Live tools** | Ghidra HTTP `127.0.0.1:8089`: `decompile_function`, `force_decompile`, `analyze_function_complete`, `disassemble_function`, `read_memory`, callers/xrefs/callees, `search_strings`, `inspect_memory_content` |
| **Partition** | `WAVE_2026-08-05_mega_residual_partition_map.md` → **MEGA-113** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Acquire CNDHash **traversal ownership** by setting the TraversalLock flag:

```text
// custom ESI = CNDHash* hash; bare ret
if (*(char*)(hash + 0x1d) != 0):
    log("HashError:TraversalLock, already locked for traversal")
    log("VOG_DEBUG_STOP")
// ALWAYS:
*(uint8_t*)(hash + 0x1d) = 1
```

No critical section. No bucket walk. No freelist. No throw. Unlock is **caller-owned** (`*(hash+0x1d)=0` inline).

**Not** `List_TraversalLock` (different object, CS @+4, flag @+0x28, early-return on re-lock).  
**Not** a VOG_DEBUG_STOP product entry (that string is the error path only).

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `decompile_function` / `force_decompile` @ `0x00411e10` ≡ 2026-07-23 raw CF |
| Body bytes | `read_memory` — `80 7E 1D 00 74 1B … C6 46 1D 01 C3` |
| Disassembly | `disassemble_function` — 11 instructions, body end `00411e35` |
| Function bounds | `get_function_by_address` — `00411e10`–`00411e35` |
| Strings | `inspect_memory_content` @ `0x00a27cd0`, `0x00a15844` |
| Callers | `get_function_callers` — 9 named; `get_xrefs_to` — **16** UNCONDITIONAL_CALL |
| Callees | `FUN_007a4480` only |
| Call-site ESI | `disassemble_function` on `Client_UpdateNpcInteractIcons`; mem samples on `+0x4c0` / `+0x538` sites |
| Clean | `reconstructed-exact/CNDHash_TraversalLock.cpp` |
| Scaffold retired | `Named_VOG_DEBUG_STOP_00411e10` rejected as product identity |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden, parent ledger edits.

---

## 3. ABI (SEALED)

| Slot | Role | Evidence |
|------|------|----------|
| **ESI** | hash* | body `[ESI+0x1d]` only; no `mov esi,ecx`; callers preload ESI |
| stack | none | bare `RET` (`C3`) |
| return | void | no EAX write |
| ECX | unused | not thiscall |

### Call-site ESI seal (samples)

| Site | Setup |
|---|---|
| `0x0091b94d` | `MOV ESI, [client+0xe8f4]` then `CALL` |
| `0x00790fd4` | `MOV ESI, [obj+0x4c0]` then `CALL` |
| `0x0088c374` | `MOV ESI, [char+0x538]` then `CALL` |
| `0x0091be5e` | `MOV ESI, [char+0x6f0]` then `CALL` |

---

## 4. Control flow: clean ≡ live ≡ raw

| Stage | Match |
|---|---|
| `CMP [ESI+0x1d],0` / `JZ` skip logs | **Yes** |
| Log HashError then VOG_DEBUG_STOP (`ADD ESP,0x10`) | **Yes** |
| Fallthrough `MOV [ESI+0x1d],1` always | **Yes** |
| Bare `RET` | **Yes** |
| `force_decompile` ≡ raw | **Yes** |

### Instruction seal

```text
00411e10  80 7E 1D 00     CMP  byte ptr [ESI+0x1d], 0
00411e14  74 1B           JZ   00411e31
00411e16  68 D0 7C A2 00  PUSH 00a27cd0
00411e1b  6A 00           PUSH 0
00411e1d  E8 …            CALL FUN_007a4480
00411e22  68 44 58 A1 00  PUSH 00a15844
00411e27  6A 00           PUSH 0
00411e29  E8 …            CALL FUN_007a4480
00411e2e  83 C4 10        ADD  ESP, 10h
00411e31  C6 46 1D 01     MOV  byte ptr [ESI+0x1d], 1
00411e35  C3              RET
; pad CC ×10 → next FUN_00411e40
```

---

## 5. Confidence

| Claim | Confidence |
|---|---|
| Role = CNDHash TraversalLock set | **High** (string + CF + callers) |
| ESI custom ABI / bare ret | **High** |
| Flag offset `+0x1d` | **High** (bytes + peer TraverseToNext) |
| Soft double-lock (log then still set) | **High** |
| Distinct from List_TraversalLock | **High** |
| Reject Named_VOG_DEBUG_STOP product name | **High** |
| Product C++ class / stamp family English | **Open** |
| Runtime / bit-exact / differential | **Open** |

**Verdict:** **accept-with-gaps** — CF/ABI/strings/callers sealed; class product English + runtime open.
