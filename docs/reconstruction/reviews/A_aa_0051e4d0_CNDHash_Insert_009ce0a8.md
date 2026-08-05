# Review A (reconstruction fidelity): `aa_0051e4d0` CNDHash_Insert_009ce0a8

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051e4d0` |
| **VA** | `0x0051e4d0`–`0x0051e5c5` (**~0xf6** bytes; `ret 0x0C`) |
| **Canonical name** | `CNDHash_Insert_009ce0a8` (node vtbl stamp; leave registry if name collides) |
| **Ghidra name** | `FUN_0051e4d0` |
| **Prior alias** | `Named_VOG_DEBUG_STOP_0051e4d0` (lock-warn only) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_0051e4d0_CNDHash_Insert_009ce0a8.md` |
| **System** | missions-progression (medal def table) |
| **Live tools** | `batch_decompile`, full `disassemble_function`, `read_memory` vtbl/bytes, xrefs |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** |

---

## 1. Purpose

**CNDHash insert(key, value)** specialized by **node vtbl** `PTR_FUN_009ce0a8` — same control flow as sealed skill twin `FUN_0051e6d0` (`009cb968`) and mission `CNDHash_Insert` family; **must not merge** call sites.

```c
// __thiscall  ret 0x0C
int CNDHash_Insert_009ce0a8(CNDHash *this, uint key, void *value, char softIfExists);
```

1. `value == NULL` → **`0x80004003`** (`E_POINTER`).
2. If `this+0x1d` lock set → log `"HashError:insert, already locked for traversal"` + `"VOG_DEBUG_STOP"`; **continue**.
3. If `softIfExists != 0` and `CNDHash_LookupByKey(this, key)` hits → **return 1** (no insert).
4. Else if lookup hits → log `"Duplicate hash insert %u, failing out"` → **`0x80004005`**.
5. Alloc node: `LEA ECX,[this+0x20]; call FUN_0053ada0` (freelist at **`this+0x20`**).
6. Init node: vtbl **`0x009ce0a8`**, touch `+4=0`, value `+8`, key `+0x10`, list links 0; bucket head-insert at `buckets[key & mask]+4`; `FUN_00537d30` integrity.
7. Append ordered list head `+0x14` / tail `+0x18`; `count++` at `+0xc`; return **0**.

Sole static caller: `FUN_00519660` medal ensure @ `0x00519774`:

```
PUSH 0                 ; softIfExists = 0
PUSH MedalDef*         ; value
PUSH [MedalDef]        ; key = id at def+0
MOV ECX, 0x00b042e0
CALL FUN_0051e4d0
```

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ raw / clean CF |
| Live listing | every exit `RET 0x0C`; freelist `8D 4F 20`; vtbl imm `C7 06 A8 E0 9C 00` |
| Lookup | `CNDHash_LookupByKey` `0x005b0920` |
| Alloc / repair | `FUN_0053ada0` / `FUN_00537d30` |
| Sibling dual | `A_aa_0051e6d0_FUN_0051e6d0.md` (same CF, vtbl `009cb968`) |
| Parent | `FUN_00519660` medal table load |
| Lookup consumer | `MedalDef_LookupById` `aa_0051a0e0` |

---

## 3. Sealed HRESULTs / exits (machine)

| Exit | EAX | Evidence |
|---|---|---|
| null value | `0x80004003` | `B8 03 40 00 80` |
| soft hit | `1` | `B8 01 00 00 00` |
| hard dup | `0x80004005` | `B8 05 40 00 80` |
| success | `0` | `XOR EAX,EAX` |

---

## 4. Layout

### Hash (this variant)

| Off | Field |
|---|---|
| `+0x08` | mask |
| `+0x0c` | count |
| `+0x10` | buckets* |
| `+0x14` / `+0x18` | list head / tail |
| `+0x1d` | traversal lock |
| `+0x20` | freelist header (`LEA ECX,[this+0x20]`) |

### Node 0x1c (vtbl `009ce0a8`)

| Off | Field |
|---|---|
| `+0x00` | vtbl |
| `+0x04` | touch byte |
| `+0x08` | value* (MedalDef*) |
| `+0x0c` | bucket next |
| `+0x10` | key (medal id) |
| `+0x14` / `+0x18` | list next / prev |

---

## 5. Confidence

| Claim | Level |
|---|---|
| CF A≡B ≡ raw ≡ live | **Confirmed** |
| `ret 0x0C` + HRESULTs | **Confirmed** |
| Freelist `this+0x20` | **Confirmed** |
| Node vtbl `009ce0a8` | **Confirmed** |
| Twin ≠ skill/mission inserts | **High** |
| Medal table sole static caller | **Confirmed** |
| Node vtbl method bodies | **Open** |
| Runtime multi-insert stress | **Open** |

**Verdict:** **accept-with-gaps.**
