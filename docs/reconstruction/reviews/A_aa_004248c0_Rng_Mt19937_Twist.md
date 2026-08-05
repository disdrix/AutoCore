# Review A (reconstruction fidelity): `aa_004248c0` Rng_Mt19937_Twist

| Field | Value |
|---|---|
| **Stable ID** | `aa_004248c0` |
| **VA** | `0x004248c0` |
| **Body** | `0x004248c0`–`0x00424965` (`ret` inclusive) |
| **Canonical name** | `Rng_Mt19937_Twist` |
| **Prior / alias** | `FUN_004248c0` |
| **Review date** | `2026-07-29` (W18-K OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_004248c0_Rng_Mt19937_Twist.md` |
| **System** | RNG / MT19937 |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `analyze_function_complete`, `get_function_by_address` (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**MT19937 state twist** (full 624-word regeneration) for the game's Mersenne Twister objects.

- State object in **ESI**.
- Classic constants: N=624, M=397, MATRIX_A=`0x9908b0df`.
- Two main loops (227 + 396) plus final wrap with `mt[0]`.
- Post-condition: **remaining** `+0x9c4 = 624`, **cursor** `+0x9c0 = &mt[0]`.

Used whenever the extract path drains the buffer (`FUN_00424830` when remaining==0), and at seed/init sites that force a fresh twist.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004248c0_FUN_004248c0.md` (+ W18-K re-seal) |
| Annotated | `docs/reconstruction/raw/aa_004248c0_Rng_Mt19937_Twist.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Rng_Mt19937_Twist.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_004248c0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004248c0_Rng_Mt19937_Twist.md` |
| Live decompile | ≡ frozen raw CF |
| Live bytes | `read_memory` @ `0x004248c0` length 200 |
| Meta | body `004248c0`–`00424965`; 22 xrefs; **0** callees |
| Context (not owned) | extract `0x00424830`, seed `0x00424890`, table fill `0x007a4200` |
| Prior RNG dual | `A_aa_0058ab60_Rng_CloneSeededTable_Inferred` cites this as twist helper |

---

## 3. Byte seal (summary)

```
mov  eax, esi                 ; state base
mov  edx, 0xe3                ; 227
push edi
... twist loop1 (MATRIX_A 0x9908b0df, lag +0x18d dwords = +0x634 bytes) ...
mov  edx, 0x18c               ; 396
... twist loop2 (lag -0xe3 dwords) ...
... last element with mt[0] ...
pop  edi
mov  [eax], result            ; final store
mov  dword [esi+0x9c4], 0x270
mov  [esi+0x9c0], esi
ret
```

| Claim | Evidence | Conf |
|---|---|---|
| ESI state base | `8B C6` entry; extract caller `MOV ESI,EAX` before call | **High** |
| Loop counts 0xe3 / 0x18c | immediates in bytes | **High** |
| MATRIX_A `0x9908b0df` | `81 E1 DF B0 08 99` pattern | **High** |
| remaining `+0x9c4 = 0x270` | `C7 86 C4 09 00 00 70 02 00 00` | **High** |
| cursor `+0x9c0 = esi` | `89 B6 C0 09 00 00` | **High** |
| Leaf near ret | ends `C3`; 0 callees | **High** |

---

## 4. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| Loop1 N−M with lag +M | **Yes** |
| Loop2 M−1 with lag −(N−M) | **Yes** |
| Final wrap with mt[0] | **Yes** |
| Cursor + remaining reset | **Yes** |
| No invent temper / seed | **Yes** (those are siblings) |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Is MT19937 twist | **Confirmed** | constants + structure |
| ABI ESI + void | **Confirmed** | |
| Layout cursor/remaining | **Confirmed** | extract sibling agrees |
| Product name | **Inferred** | no string on unit |
| Exact last-element pointer aliasing | **High** | index form `mt[623]=f(mt[623],mt[0],mt[396])` sealed |

---

## 6. Gaps / open

1. Product / PDB symbol.
2. Full dual of extract `FUN_00424830` / seed `FUN_00424890` (context only here).
3. Temper masks used by extract are **non-textbook-looking** in decompiler (`0xff3a58ad` etc.) — **out of this unit**; do not fold into twist.
4. Runtime / bit-exact vs known MT vectors.

**Verdict:** **accept-with-gaps**
