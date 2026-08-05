# Review A (reconstruction fidelity): `aa_00424830` Rng_Mt19937_Extract

| Field | Value |
|---|---|
| **Stable ID** | `aa_00424830` |
| **VA** | `0x00424830` |
| **Body** | `0x00424830`–`0x00424882` exclusive (**82** B) |
| **Canonical name** | `Rng_Mt19937_Extract` |
| **Prior / alias** | `FUN_00424830` |
| **Review date** | `2026-07-29` (W20-C OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00424830_Rng_Mt19937_Extract.md` |
| **System** | RNG / MT19937 |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `analyze_function_complete`, `get_function_by_address` (no `disassemble_bytes`) |
| **Verdict** | **accept** |

---

## 1. Purpose

**MT19937 extract-one**: pull the next tempered `uint32` from a 624-word state buffer with cursor/remaining countdown. When remaining hits 0, call sibling **twist** to regenerate the buffer.

Used widely (34 xrefs) for client-side rolls (UI, sound pick, humor messages, table consumers).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00424830_FUN_00424830.md` (+ W20-C re-seal) |
| Annotated | `docs/reconstruction/raw/aa_00424830_FUN_00424830.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Rng_Mt19937_Extract.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_00424830.cpp` |
| Function record | `docs/reconstruction/functions/aa_00424830_Rng_Mt19937_Extract.md` |
| Live decompile | ≡ frozen raw CF |
| Live bytes | `read_memory` @ `0x00424830` length 128 |
| Meta | body 82 B; 34 xrefs; callee twist only |
| Context (not owned) | twist `0x004248c0`, seed `0x00424890` (dualed earlier) |

---

## 3. Byte seal (summary)

```
push esi
mov  esi, eax                 ; EAX → ESI state
cmp  dword [esi+0x9c4], 0
jnz  extract
call 0x004248c0               ; twist
mov  eax, [esi+0x9c0]
add  dword [esi+0x9c4], -1
mov  ecx, [eax]               ; *cursor
add  eax, 4
mov  [esi+0x9c0], eax
; temper 11 / (mask<<7) / (mask<<15) / 18
pop  esi
ret                           ; c3
```

| Claim | Evidence | Conf |
|---|---|---|
| EAX state entry | `56 8B F0` | **High** |
| remaining +0x9c4 | `83 BE C4 09 00 00 00` | **High** |
| call twist | rel e8 → `004248c0` | **High** |
| cursor +0x9c0 advance +4 | `8B 86 C0 09…` / `83 C0 04` | **High** |
| masks `0xff3a58ad` / `0xffffdf8c` | immediates in body | **High** |
| shifts 11,7,15,18 | `c1 e8 0b` / `c1 e2 07` / `c1 e0 0f` / `c1 e8 12` | **High** |
| near ret | ends `C3` | **High** |

---

## 4. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| remaining==0 → twist | **Yes** |
| --remaining; *cursor++ | **Yes** |
| temper cascade order | **Yes** |
| return EAX | **Yes** |
| No invent seed / twist body | **Yes** (siblings) |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Is MT19937 extract | **Confirmed** | layout + temper + twist link |
| EAX ABI + u32 return | **Confirmed** | |
| Temper ≡ classic masks | **Confirmed** | rewrite form sealed |
| Product name | **Inferred** | Extract / genrand_int32 |
| Runtime vectors | Open | |

---

## 6. Gaps / open

1. Product/PDB symbol spelling.
2. Per-caller which state instance (global vs local).
3. Runtime / bit-exact vs known MT outputs after retail seed.
4. Exhaustive DATA xref census (N/A for pure code leaf beyond 34 CALLs).

**Verdict:** **accept**
