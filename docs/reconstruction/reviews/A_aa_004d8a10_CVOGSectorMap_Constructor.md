# Review A (reconstruction fidelity): `aa_004d8a10` CVOGSectorMap_Constructor

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d8a10` |
| **VA** | `0x004d8a10`–`0x004d938f` |
| **Canonical name** | `CVOGSectorMap_Constructor` |
| **Ghidra name** | `FUN_004d8a10` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W24-F) |
| **Counterpart** | `reviews/B_aa_004d8a10_CVOGSectorMap_Constructor.md` |
| **System** | client / CVOGSectorMap |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory`; caller `Client_InitInstance`; sibling tree duals `aa_004e7450` / `aa_004e7420` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Construct a **CVOGSectorMap** instance in a caller-allocated `0xE920` block: install vtbl, default members, init embedded rb-tree headers and critical-section lock objects, heap-allocate subsystem helpers, publish global `_DAT_00b03600 = this`, return `this`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004d8a10_FUN_004d8a10.md` (+ W24-F append) |
| Annotated | `docs/reconstruction/raw/aa_004d8a10_FUN_004d8a10.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGSectorMap_Constructor.cpp` |
| Clean scaffold | `docs/reconstruction/reconstructed-exact/FUN_004d8a10.cpp` |
| Function record | `docs/reconstruction/functions/aa_004d8a10_CVOGSectorMap_Constructor.md` |
| Live | `decompile_function` `0x004d8a10`; `read_memory` entry+tail+vtbl; `get_function_by_address`; caller string in `Client_InitInstance` |

---

## 3. Signature

```c
// Ghidra: undefined4 * __fastcall FUN_004d8a10(undefined4 *param_1)
// Bytes:  mov esi,ecx … mov eax,esi; pop*; add esp,8; ret
// Return: this* in EAX
CVOGSectorMap* __thiscall CVOGSectorMap_Constructor(CVOGSectorMap* this);
```

| Item | Evidence | Conf |
|---|---|---|
| thiscall ECX=this | `8B F1` | **High** |
| bare ret | `C3` after local `add esp,8` | **High** |
| returns this | `8B C6` | **High** |
| vtbl `0x009cc770` | `C7 06 70 C7 9C 00` | **High** |
| product class | `@@new CVOGSectorMap` + `new(0xE920)` | **High** |

---

## 4. Control flow (sealed)

Straight-line ctor; null-checked `operator_new` sites store 0 on OOM; no HRESULT early-out.

Phases: vtbl+trees+flags → mid zeros → embedded locks/CS → defaults/tick → heap subsystems → global publish → tail bring-up → return this.

| Stage | Match | Conf |
|---|---|---|
| Entry xorps / sub esp 8 / ESI=this | **Yes** | **High** |
| Vtbl store | **Yes** | **High** |
| `FUN_004e7450` / `FUN_004e7420` headers | **Yes** (decomp + sibling duals) | **High** |
| InitCriticalSection pairs | **Yes** | **High** |
| `_DAT_00b03600 = this` | **Yes** | **High** |
| Epilogue return this | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

| Addr | Bytes | Decode |
|---|---|---|
| `0x004d8a10` | `0F 57 C0 83 EC 08 53 55 56 8B F1` | prolog; ESI=this |
| vtbl | `C7 06 70 C7 9C 00` | `*this = 0x009cc770` |
| tail | `8B C6 5E 5D 5B 83 C4 08 C3` | return this; bare ret |

**No `disassemble_bytes` used.**

---

## 6. Call surface

| Caller | VA |
|---|---|
| `Client_InitInstance` / `FUN_0094a6a0` | xref `0x0094a9d7` |

Xrefs: **1**.

Callees: tree inits, many subsystem factories, `operator_new`, `InitializeCriticalSection`, `GetTickCount`, `FUN_004e4620`, `FUN_00418e60` (full list in raw / analyze).

---

## 7. Confidence

| Claim | Level |
|---|---|
| ABI / vtbl / return this / product class | **High** |
| Phase structure + major callees | **High** |
| Full 0xE920 field English | **Partial / Open** |
| Runtime / bit-exact | **Open** |

---

## 8. Gaps

1. Exhaustive product field names for 0xE920 layout.
2. Product names for each `FUN_004e59xx` / lock-wrapper factory.
3. Global lifecycle of `_DAT_00b03600` / `_DAT_00b037e4`.
4. Live construction differential.

**Verdict:** **accept-with-gaps** — ctor ABI, product class, vtbl, and structural phases sealed; field-level English incomplete.
