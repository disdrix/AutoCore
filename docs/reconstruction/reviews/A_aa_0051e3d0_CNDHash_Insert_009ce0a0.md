# Review A (reconstruction fidelity): `aa_0051e3d0` CNDHash_Insert_009ce0a0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051e3d0` |
| **VA** | `0x0051e3d0` |
| **Body** | `0x0051e3d0`–`0x0051e4c7` exclusive (**247** B / `0xF7`) |
| **Canonical name** | `CNDHash_Insert_009ce0a0` (node vtbl stamp) |
| **Ghidra symbol** | `FUN_0051e3d0` |
| **Prior / alias** | `Named_VOG_DEBUG_STOP_0051e3d0` (misleading lock-warn seed) |
| **Review date** | `2026-07-29` (W21-D OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_0051e3d0_CNDHash_Insert_009ce0a0.md` |
| **System** | container / CNDHash insert family |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `get_function_by_address`, xrefs / complete analysis (**no** `disassemble_bytes`) |
| **Verdict** | **accept** |

---

## 1. Purpose

**CNDHash insert(key, value)** specialized by **node vtbl** `PTR_FUN_009ce0a0` — same control flow as sealed twins `CNDHash_Insert` (`0x0053c560`) and `CNDHash_Insert_009ce0a8` (`0x0051e4d0`); **must not merge** call sites.

```c
// __thiscall  ret 0xC
uint32_t CNDHash_Insert_009ce0a0(CNDHash *this, uint key, void *value, char softIfExists);
```

1. `value == NULL` → **`0x80004003`** (`E_POINTER`).
2. If `this+0x1d` lock set → log `"HashError:insert, already locked for traversal"` + `"VOG_DEBUG_STOP"`; **continue**.
3. If `softIfExists != 0` and `CNDHash_LookupByKey(this, key)` hits → **return 1** (no insert).
4. Else if lookup hits → log `"Duplicate hash insert %u, failing out"` → **`0x80004005`**.
5. Alloc node: `LEA ECX,[this+0x20]; call FUN_0053ada0`.
6. Init node: vtbl **`0x009ce0a0`**, touch `+4=0`, value `+8`, key `+0x10`; bucket head-insert; `FUN_00537d30`.
7. Append ordered list; `count++`; return **0**.

Sole static caller: `FUN_00519a30` (3 sites @ `0x00519b03`, `0x00519bbf`, `0x00519c81`) with `softIfExists = 0`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0051e3d0_FUN_0051e3d0.md` (+ W21-D append) |
| Annotated | `docs/reconstruction/raw/aa_0051e3d0_FUN_0051e3d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDHash_Insert_009ce0a0.cpp` |
| Scaffold | `reconstructed-exact/FUN_0051e3d0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0051e3d0_CNDHash_Insert_009ce0a0.md` |
| Live decompile | ≡ raw |
| Live body bytes | `read_memory` @ `0x0051e3d0` length 247+ |
| Strings | `read_memory` @ `0x00a64c18`, `0x00a15844`, `0x00a64bf0` |
| Sibling duals | `aa_0051e4d0` (vtbl `009ce0a8`), `aa_0053c560` (vtbl `009cefd4`) |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Sealed HRESULTs / exits (machine)

| Exit | EAX | Evidence |
|---|---|---|
| null value | `0x80004003` | `B8 03 40 00 80` |
| soft hit | `1` | `B8 01 00 00 00` |
| hard dup | `0x80004005` | `B8 05 40 00 80` |
| success | `0` | `XOR EAX,EAX` |

All exits: **`c2 0c 00`**.

---

## 4. Layout

### Hash

| Off | Field |
|---|---|
| `+0x08` | mask |
| `+0x0c` | count |
| `+0x10` | buckets* |
| `+0x14` / `+0x18` | list head / tail |
| `+0x1d` | traversal lock |
| `+0x20` | freelist header (`LEA ECX,[this+0x20]`) |

### Node 0x1c (vtbl `009ce0a0`)

| Off | Field |
|---|---|
| `+0x00` | vtbl |
| `+0x04` | touch byte |
| `+0x08` | value* |
| `+0x0c` | bucket next |
| `+0x10` | key |
| `+0x14` / `+0x18` | list next / prev |

Hex key stamps: freelist `8D 4F 20`; vtbl `C7 06 A0 E0 9C 00`.

---

## 5. Confidence

| Claim | Evidence | Conf |
|---|---|---|
| Body **247** B / `ret 0xC` | meta end `0051e4c7` + hex | **High** |
| Soft flag semantics | early return 1 path | **High** |
| Lock log-only | no early ret after VOG_DEBUG_STOP | **High** |
| Vtbl `009ce0a0` ≠ twin `009ce0a8` | imm in body | **High** |
| Decompile ≡ raw ≡ bytes | three-rep | **High** |
| Product specialty name | structural stamp only | Open |

---

## 6. Gaps / open

1. Product English for this vtbl specialty / hosted value type at `FUN_00519a30` sites.
2. Full freelist + integrity dual units.
3. Runtime / bit-exact / differential not run.

**Verdict:** **accept** — CF, ABI, HRESULTs, vtbl, freelist offset sealed High.
