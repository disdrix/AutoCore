# Review A (reconstruction fidelity): `aa_0074d750` Class_00aa05cc_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0074d750` |
| **VA** | `0x0074d750`–`0x0074d7ad` inclusive (**94 B** / `0x5E`) |
| **Canonical name** | `Class_00aa05cc_Ctor_Inferred` |
| **Ghidra name** | `FUN_0074d750` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W35-C) |
| **Counterpart** | `reviews/B_aa_0074d750_Class_00aa05cc_Ctor_Inferred.md` |
| **System** | class host / dual NestedHash bags + geo-anm bind path |
| **Evidence pass** | Live Ghidra `batch_decompile` / `decompile_function` + `analyze_function_complete` + `read_memory` (full body + vtbl head) + xrefs/callers + sealed W34-D/E callees. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

ECX thiscall ctor for a **0x5C** host: install vtbl `PTR_FUN_00aa05cc`, zero head, placement-construct NestedHashBag at **+0x0c** and NestedHash (sentinel **0x14**) at **+0x34**. Multi-caller anim/geo bind path (often with `AnimSlot_Ctor` `0x0074ed90`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W35-C append) | `docs/reconstruction/raw/aa_0074d750_FUN_0074d750.md` |
| Annotated | `docs/reconstruction/raw/aa_0074d750_FUN_0074d750.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/Class_00aa05cc_Ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0074d750.cpp` |
| Function records | `functions/aa_0074d750_FUN_0074d750.md`, `functions/aa_0074d750_Class_00aa05cc_Ctor_Inferred.md` |
| Callee duals | W34-D NestedHashBag_Ctor; W34-E NestedHash_Ctor_Sentinel0x14 |
| Live | decompile ≡ raw CF; 94 B hex; `MOV ESI,ECX`; bare `C3`; callers `new(0x5c)` |

---

## 3. Signature (sealed)

```c
// ECX = this; bare RET; EAX = this
Class_00aa05cc* __fastcall Class_00aa05cc_Ctor_Inferred(Class_00aa05cc* self);
```

| Formal | Source | Conf |
|---|---|---|
| `self` | ECX (`MOV ESI,ECX`) | **High** |
| return | EAX = ESI | **High** |
| stack args | none (bare `C3`) | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
SEH prolog LAB_009acbbf
xorps xmm0,xmm0
mov esi, ecx
*esi = PTR_FUN_00aa05cc
*(esi+4) = 0
movss [esi+8], xmm0
push (esi+0x0c); call NestedHashBag_Ctor (0044a0d0)
SEH state = 0
push (esi+0x34); call NestedHash_Ctor_Sentinel0x14 (0043bdf0)
eax = esi; SEH epilog; add esp,0x10; ret
```

| Stage | Match | Conf |
|---|---|---|
| ECX thiscall + bare RET | **Yes** (bytes) | **High** |
| Vtbl + zero +4/+8 | **Yes** | **High** |
| Bags at +0x0c / +0x34 | **Yes** (LEA offsets + callee duals) | **High** |
| Host size 0x5C | **Yes** (all `new(0x5c)` callers) | **High** |
| Product class English | **No claim** — vtbl structural name | **Low** |

---

## 5. Gaps

- Product/PDB demangle for class / vtbl methods.
- Head field meaning beyond zero init.
- Unowned `FUN_0074d420` / full vtbl contracts.
- Runtime / bit-exact / differential.

---

## 6. Verdict

Fidelity pass seals ABI, layout, callees, and host size against full-body bytes and multi-caller alloc pattern. Residual product English + method contracts + runtime → **accept-with-gaps**.
