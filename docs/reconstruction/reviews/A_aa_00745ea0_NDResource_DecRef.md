# Review A (reconstruction fidelity): `aa_00745ea0` NDResource_DecRef

| Field | Value |
|---|---|
| **Stable ID** | `aa_00745ea0` |
| **VA** | `0x00745ea0`–`0x00745ed9` |
| **Canonical name** | `NDResource_DecRef` |
| **Prior scaffold** | `FUN_00745ea0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00745ea0_NDResource_DecRef.md` |
| **System** | client resource / NDResource shell |
| **Agent** | W21-N OWN-ONLY |
| **Verdict** | **accept** |

---

## 1. Purpose

**Soft-decrement NDResource shell refcount** (`this+0x10`) under optional CS (`this+0x20` when flag `this+0x38 != 0`).

Returns:

| EAX | Meaning |
|---|---|
| `0` | refcount was > 0 and was decremented |
| `0xffffffff` | refcount was already 0; **not** decremented |

Does **not** free the shell, call `vtbl+8`, or clear inner `+0x8`. Sibling **`NDResource_AcquireInnerObject`** (`0x00745ee0`) bumps the same counter.

**Calling convention:** MSVC `__thiscall` — shell in `ECX`; **no stack args**; plain `ret` (`C3`). Ghidra may label `__fastcall` with one ECX param — equivalent here.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00745ea0_FUN_00745ea0.md` (+ v2026-07-29) |
| Annotated | `docs/reconstruction/raw/aa_00745ea0_FUN_00745ea0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NDResource_DecRef.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_00745ea0.cpp` |
| Function record | `docs/reconstruction/functions/aa_00745ea0_FUN_00745ea0.md` |
| Live decompile | Ghidra `0x00745ea0` (2026-07-29) — ≡ 2026-07-23 raw |
| Machine | `read_memory` full body; ends `C3`; pad `CC` |
| Meta | `analyze_function_complete` + `get_function_by_address` body `00745ea0`–`00745ed9` |
| Sibling dual | `A\|B_aa_00745ee0_NDResource_AcquireInnerObject` |

**Not performed:** `disassemble_bytes`, Launcher, runtime, parent ledgers.

---

## 3. Signature / layout

```c
uint32_t __thiscall NDResource_DecRef(void *self /* ECX */);
```

| Offset | Role |
|---|---|
| `+0x10` | refcount (i32) |
| `+0x20` | `CRITICAL_SECTION` |
| `+0x38` | use-CS flag (u8); leave path reads as `[CS+0x18]` |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Soft decref role | **Confirmed** | bytes + sibling layout |
| ABI thiscall + plain `ret` | **Confirmed** | epilogue `C3` |
| Offsets `+10/+20/+38` | **Confirmed** | body + acquire dual |
| Return 0 / -1 contract | **Confirmed** | `xor edi,edi` vs `or edi,-1` |
| No free / no vtbl | **Confirmed** | no call targets except Enter/Leave |
| Clean ≡ decompile ≡ bytes | **Confirmed** | |
| Product English name | **Open** | role name sealed |
| Runtime / bit-exact | **Open** | |

---

## 5. Control flow: clean ≡ decompile ≡ bytes

| Stage | Match |
|---|---|
| `this` → ESI | **Yes** — `mov esi,ecx` |
| Gate lock on `+0x38` | **Yes** |
| EnterCS via IAT `0x009c61bc` | **Yes** |
| Default result `-1` | **Yes** — `or edi,-1` |
| Dec only if count ≠ 0 | **Yes** — `test eax; jbe skip` (TEST→JBE ≡ JZ) |
| LeaveCS via IAT `0x009c61b8` | **Yes** — flag via `[ebx+0x18]` |
| Return EDI in EAX; plain ret | **Yes** |

### Decompiler noise — sealed as artifact

| Noise | Reality |
|---|---|
| `__fastcall` label | **thiscall** ECX; no stack params |
| Leave check shown as `param_1+0x38` | bytes use `[CS+0x18]` — **same byte** as `this+0x38` |

---

## 6. Gaps

- Product method spelling (`DecRef` / `ReleaseRef` / internal).
- Caller policy when EAX is `-1` (ignore vs diagnostic).
- Runtime golden.
