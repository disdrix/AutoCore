# Review A (reconstruction fidelity): `aa_005b3420` CVOGEnvironmentReflect_InitBufferedViewChild_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b3420` |
| **VA** | `0x005b3420`–`0x005b3519` (**249 B**) |
| **Canonical name** | `CVOGEnvironmentReflect_InitBufferedViewChild_Inferred` |
| **Ghidra name** | `FUN_005b3420` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W37-M) |
| **Counterpart** | `reviews/B_aa_005b3420_CVOGEnvironmentReflect_InitBufferedViewChild_Inferred.md` |
| **System** | client / CVOGEnvironmentReflect / gfxBufferedView |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (full 249 B) + `analyze_function_complete` + RTTI chain + sole caller W33-T; **no** `disassemble_bytes` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Alloc/bind Reflect’s **gfxBufferedView** child:

1. `new(0x198)` + `FUN_00968a50` (gfxBufferedView ctor) → `host+0x158`
2. Parent backlink `child+4 = host`
3. Near **0.5f**, resource `DAT_00afdf08`, far **100000.0f**, dirties
4. vtbl+`0x18` with **(0x100, 0x100)**; flags `+0x108=0`, `+0x190=1`

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W37-M append) | `docs/reconstruction/raw/aa_005b3420_FUN_005b3420.md` |
| Annotated | `docs/reconstruction/raw/aa_005b3420_FUN_005b3420.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGEnvironmentReflect_InitBufferedViewChild_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005b3420.cpp` |
| Function records | `functions/aa_005b3420_FUN_005b3420.md`, named twin |
| Related | W33-T Enable; W32-T Reflect ctor; W34-N fluid-bump same 0x198 ctor; W31-O SetNear |
| Live | body bounds; `MOV ESI,ECX`; `PUSH 0x198`; imm `0x3f000000` / `0x47c35000`; RTTI string `.?AVgfxBufferedView@@` |

---

## 3. Signature (sealed)

```c
// ECX=reflect*; 0 stack formals; void; plain RET (SEH + ADD ESP,0x18)
void __fastcall CVOGEnvironmentReflect_InitBufferedViewChild_Inferred(void *self);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX (`MOV ESI,ECX`) | **High** |
| stack formals | none (`C3` not `C2 xx 00`) | **High** |
| return | void | **High** |

---

## 4. Control flow (clean ≡ raw ≡ live)

```
child = new(0x198) ? FUN_00968a50 : 0
self+0x158 = child; child+4 = self
SetNear(0.5); FUN_0075bf40(DAT_00afdf08); +0x180=0; FUN_0075b450
SetFar(1e5); +0xec=0; flags +0x48/+0xcc
vtbl+0x18(&{0x100,0x100}); +0x108=0; +0x190=1
```

| Stage | Match | Conf |
|---|---|---|
| Body size / SEH / RET | **Yes** | **High** |
| ECX this | **Yes** | **High** |
| Child RTTI gfxBufferedView | **Yes** | **High** |
| Slot +0x158 / size 0x198 | **Yes** | **High** |
| Sole Enable caller | **Yes** | **High** |

---

## 5. Gaps

- Product English for `FUN_0075bf40` / `FUN_0075b450` / vtbl+`0x18` beyond structural roles.
- Identity of `DAT_00afdf08` (live dword `0xFFFF0000`) as asset vs color vs handle.
- OOM path when `new` fails then `child+4` write (raw does not null-check after assign — same as decompile).
- Runtime / bit-exact / differential.

---

## 6. Verdict

Reconstruction fidelity sealed for ABI, body bounds, child RTTI/size/slot, near/far constants, sole Enable wiring. Nested helper English residual → **accept-with-gaps**.
