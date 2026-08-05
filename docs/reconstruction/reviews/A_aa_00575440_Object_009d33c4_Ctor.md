# Review A (reconstruction fidelity): `aa_00575440` Object_009d33c4_Ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00575440` |
| **VA** | `0x00575440`–`0x00575528` exclusive (**232 B** / `0xE8`) |
| **Canonical name** | `Object_009d33c4_Ctor` |
| **Ghidra name** | `FUN_00575440` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W29-H) |
| **Counterpart** | `reviews/B_aa_00575440_Object_009d33c4_Ctor.md` |
| **System** | object / derived complete-object constructor |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (full body). **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC **complete-object constructor** for derived object family `PTR_FUN_009d33c4`:

1. SEH install (`LAB_009a5096`).
2. `Object_SharedBase_Ctor` (`FUN_00518940`).
3. Install derived vtbl.
4. StdList init at **`this+0x1DC`**: sentinel from `FUN_00457c60` → `+0x1E0`; size 0 → `+0x1E4`.
5. Zero/init derived owned/buffer/flags and four 0x10 id-pair slots.

Dtor twin `Object_009d33c4_CompleteDtor` (`FUN_00575350`, W28-M) tears down the same region and tail-jumps base dtor. Scalar deleting wrapper is **vtbl[0]** `FUN_00575c00`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W29-H) | `docs/reconstruction/raw/aa_00575440_FUN_00575440.md` |
| Annotated | `docs/reconstruction/raw/aa_00575440_FUN_00575440.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/Object_009d33c4_Ctor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00575440.cpp` |
| Function records | `functions/aa_00575440_FUN_00575440.md`, `functions/aa_00575440_Object_009d33c4_Ctor.md` |
| Base | `Object_SharedBase_Ctor` `aa_00518940` (W22-B) |
| List peer | `StdList_Destroy_FreeHead` layout `aa_00497360` (+4 head, +8 size); sentinel alloc `FUN_00457c60` |
| Live | decompile; 232 B hex; vtbl; 2 code xrefs |

---

## 3. Signature (sealed)

```c
// __thiscall; ECX=this; returns this; bare RET
void *__thiscall Object_009d33c4_Ctor(void *self);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX (`8B F1`) | **High** |
| return | EAX = this (`8B C6`) | **High** |
| cleanup | bare `C3` after SEH restore | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
SEH LAB_009a5096; state=-1
call Object_SharedBase_Ctor(this)
EH state=0
*this = PTR_FUN_009d33c4
lea list, [this+0x1DC]
list+4 = FUN_00457c60()   // 0x18 circular sentinel
list+8 = 0
init derived fields (+0x190=1, id-pairs -1, owned/buffer/flags 0)
SEH restore; return this
```

| Stage | Match | Conf |
|---|---|---|
| Base ctor + vtbl | **Yes** | **High** |
| List @ +0x1DC (LEA) | **Yes** (bytes) | **High** |
| Field offset map | **Yes** | **High** |
| Returns this | **Yes** | **High** |
| Object_SharedBase parent | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

| Region | Note |
|---|---|
| Entry | `6A FF 68 96 50 9A 00` … `8B F1` |
| Base | `E8 DC 34 FA FF` → `call 0x00518940` |
| Vtbl | `C7 06 C4 33 9D 00` |
| List | `8D BE DC 01 00 00` … `call 0x00457c60` … `89 47 04 89 5F 08` |
| Epilogue | `8B C6` … `83 C4 10 C3` |
| Size | **232 B** exclusive end `0x00575528` |

**No `disassemble_bytes` used.**

---

## 6. Gaps

- Product / MSVC demangled derived type name.
- Semantics of four 0x10 id-pair slots and `+0x190`/`+0x1E8`.
- Runtime / bit-exact / differential — open.

---

## 7. Verdict

CF, ABI, base chain, list LEA, and derived init sealed → **accept-with-gaps**.
