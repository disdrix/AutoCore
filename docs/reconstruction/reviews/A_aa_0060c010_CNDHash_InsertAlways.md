# Review A (reconstruction fidelity): `aa_0060c010` CNDHash_InsertAlways

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060c010` |
| **VA** | `0x0060c010` |
| **Body** | `0x0060c010`–`0x0060c0a5` (`ret 8` inclusive) |
| **Canonical name** | `CNDHash_InsertAlways` |
| **Prior / alias** | `FUN_0060c010` |
| **Review date** | `2026-07-29` (W18-K OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_0060c010_CNDHash_InsertAlways.md` |
| **System** | shared CNDHash container / missions-progression secondary indexes |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `analyze_function_complete`, `get_function_by_address` (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Always-insert** CNDHash path used by region-mission secondary indexes:

1. Null `value` → **`0x80004003`** (`E_POINTER`).
2. Allocate node from freelist at **`this+0x20`** via `FUN_0053ada0`.
3. Init node vtbl **`PTR_LAB_009cf024`**, value, key, clear touch/list links.
4. Bucket index = `key & mask(+0x08)`; head-insert at `bucketHdr+4`.
5. `FUN_00537d30(bucketHdr)` chain integrity.
6. Tail-append global list (`+0x14`/`+0x18`); `count(+0x0c)++`; return **0**.

Unlike `CNDHash_Insert` (`0x0053c560` / twin `0x0053c360`): **no** lock log, **no** lookup, **no** soft/hard duplicate policy — multi-key insert is allowed.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0060c010_FUN_0060c010.md` (+ W18-K re-seal) |
| Annotated | `docs/reconstruction/raw/aa_0060c010_CNDHash_InsertAlways.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDHash_InsertAlways.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_0060c010.cpp` |
| Function record | `docs/reconstruction/functions/aa_0060c010_CNDHash_InsertAlways.md` |
| Live decompile | ≡ frozen raw CF |
| Live bytes | `read_memory` @ `0x0060c010` length 160 |
| Meta | body `0060c010`–`0060c0a5`; 2 xrefs; callees `FUN_0053ada0`, `FUN_00537d30` |
| Sibling | `CNDHash_Insert` `0x0053c560` (lock+dup); twin `0x0053c360` (same vtbl + full policy) |
| Caller dual | `A_aa_0060b870_CVOGRegionMissions_ctor` — sealed ECX=`this[2]`/`this[3]` |

---

## 3. Byte seal (summary)

```
push ebx / push ebp
mov  ebp, [esp+0x10]          ; value
xor  ebx, ebx
cmp  ebp, ebx
push edi
mov  edi, ecx                 ; this
jnz  body
pop  edi / pop ebp
mov  eax, 0x80004003
pop  ebx
ret  8

body:
push esi
lea  ecx, [edi+0x20]          ; freelist
call FUN_0053ada0
mov  esi, eax                 ; node
... init vtbl 0x009cf024, value, key ...
and  index = mask & key
head-insert at [bucketHdr+4]
call FUN_00537d30             ; ECX = bucketHdr
list append / count++
xor  eax, eax
ret  8
```

| Claim | Evidence | Conf |
|---|---|---|
| `__thiscall` + `ret 8` | ECX this; `C2 08 00` ×3 | **High** |
| E_POINTER `0x80004003` | `B8 03 40 00 80` | **High** |
| Freelist `this+0x20` | `8D 4F 20` | **High** |
| Vtbl `0x009cf024` | `C7 06 24 F0 9C 00` | **High** |
| No Lookup / no lock load | no calls to `005b0920`; no `+0x1d` | **High** |
| Success `0` | `33 C0` before ret | **High** |

---

## 4. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| Null reject | **Yes** |
| Alloc + node init + bucket prepend | **Yes** |
| Integrity call | **Yes** |
| List append both arms + count++ | **Yes** |
| No invent allowDuplicate / lock | **Yes** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Always-insert multi-key allowed | **Confirmed** | no lookup in body |
| Same node/hash offsets as Insert family | **High** | cross-check Lookup/Insert |
| Node vtbl family = mission twin `0053c360` | **High** | same immediate |
| Product name `CNDHash_InsertAlways` | **Inferred** | behavior High; no RTTI |
| Keys `def+0x88` / `+0x86` English | **Open** | caller residual |
| Runtime / bit-exact | **Open** | |

---

## 6. Gaps / open

1. Product / PDB symbol string.
2. Whether multi-key is intentional for secondary indexes (probable) vs omitted check.
3. Full freelist shell layout beyond `+0x20` handoff (owned by `FUN_0053ada0`).
4. Dual of twin full-policy insert `0x0053c360` (not owned here).
5. Runtime verification.

**Verdict:** **accept-with-gaps**
