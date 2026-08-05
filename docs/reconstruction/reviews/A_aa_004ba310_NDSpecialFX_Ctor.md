# Review A (reconstruction fidelity): `aa_004ba310` NDSpecialFX_Ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ba310` |
| **VA** | `0x004ba310`–`0x004ba545` |
| **Canonical name (Ghidra)** | `FUN_004ba310` |
| **Proposed name** | `NDSpecialFX_Ctor` (**High** role) |
| **Prior scaffold alias** | `Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004ba310` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra W18-F) |
| **Reviewer role** | Reconstruction fidelity (FX host ctor) |
| **Counterpart** | `reviews/B_aa_004ba310_NDSpecialFX_Ctor.md` |
| **System** | `client-fx` / `NDSpecialFX` |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Default-construct a 0x240-byte `NDSpecialFX` host** (flags, default blocks, nested member, empty child lists, name buffer).

### Primary use

- `NDSpecialFX_ParseXmlEventNode` (`0x004a4fa0`)
- `NDSpecialFX_InstantiateFromTemplate` (`0x004a0b90`)

**Not** teardown (`0x004b99c0`), **not** clone/parse logic itself.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004ba310_FUN_004ba310.md` (+ v2026-07-29 append) |
| Annotated | `docs/reconstruction/raw/aa_004ba310_FUN_004ba310.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NDSpecialFX_Ctor.cpp` |
| Function record | `docs/reconstruction/functions/aa_004ba310_NDSpecialFX_Ctor.md` |
| Live Ghidra | `decompile_function` `0x004ba310`; complete analysis; callers/callees; `read_memory` |
| Sibling duals | `NDSpecialFX_InstantiateFromTemplate`, `NDSpecialFX_ParseXmlEventNode`, `NDSpecialFX_TeardownCore_Inferred` |

**Not performed:** Launcher, runtime, bit-exact, parent ledger edits, `disassemble_bytes`.

---

## 3. Signature

```c
NDSpecialFX * __thiscall NDSpecialFX_Ctor(NDSpecialFX *this, const char *name);
// RET 4; EAX = this
```

| Item | Evidence |
|---|---|
| Stack arity 1 | `RET 4` @ epilogue `C2 04 00` |
| ECX this | prologue `MOV ESI,ECX` |
| Return this | `MOV EAX,ESI` |
| Alloc size | callers `push 0x240` |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Flag clear + byte defaults | **Yes** |
| Three `DAT_009cb2a0` 16 B blocks | **Yes** |
| Nested `FUN_0074ba00` @ +0xa0 | **Yes** |
| Six `FUN_004933f0` empty heads | **Yes** |
| Tree `FUN_00439770` @ +0x228 | **Yes** |
| `g_dwClientTickMs` @ +0xd0 | **Yes** |
| `strncpy(+0xd5, name, 0x104)` | **Yes** |
| Return this | **Yes** |

**Body size:** 565 B.

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Host ctor role | **High** | only two callers; both `new(0x240)` |
| ABI thiscall + RET 4 | **High** | bytes |
| Name buffer +0xd5/0x104 | **High** | |
| Class family NDSpecialFX | **High** | sibling dual naming |
| Nested factory product names | **Tentative** | FUN_* open |

---

## 6. Gaps / open

1. Product/PDB name of nested `FUN_0074ba00` and list factories.
2. Full 0x240 field map beyond ctor-touched slots.
3. Runtime / bit-exact not run.

**Verdict:** **accept-with-gaps**.
