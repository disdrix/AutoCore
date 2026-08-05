# Review A (reconstruction fidelity): `aa_009864e0` GfxVertexBufferFactory_PreResetReleaseAll_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_009864e0` |
| **VA** | `0x009864e0`–`0x00986560` inclusive (**129 B** / `0x81`) |
| **Canonical name** | `GfxVertexBufferFactory_PreResetReleaseAll_Inferred` |
| **Ghidra name** | `FUN_009864e0` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W38-AD) |
| **Counterpart** | `reviews/B_aa_009864e0_GfxVertexBufferFactory_PreResetReleaseAll_Inferred.md` |
| **System** | client / gfxVertexBufferFactory + gfxDeviceVB |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `get_function_by_address` + `read_memory` (full 129 B + pad) + xrefs/callers + callee `FUN_007465c0` + sole-caller `FUN_0075eff0` + PostRestore sibling `FUN_00986570` (context). **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Device Reset **pre-shutdown** release of all live vertex buffers: walk factory map tree (sentinel `@+0x14`); for nodes without flag bits `0x28` at `node+0xE`, for each **0x20**-byte slot in `[node+0x14, node+0x18)`, load VB* and call `FUN_007465c0` (gfxDeviceVB unlock-all + COM Release + stats).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W38-AD) | `docs/reconstruction/raw/aa_009864e0_FUN_009864e0.md` |
| Annotated | `docs/reconstruction/raw/aa_009864e0_FUN_009864e0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/GfxVertexBufferFactory_PreResetReleaseAll_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_009864e0.cpp` |
| Function records | `functions/aa_009864e0_FUN_009864e0.md`, named twin |
| Related | GfxDevice `+0x74C` ctor slot; IB twin `FUN_00985580`; PostRestore `FUN_00986570` |
| Live | body 129 B; epilogue `5E 5D 5B 5F 59 C3`; sole xref `0x0075f0e7` |

---

## 3. Signature (sealed)

```c
// EAX = factory*; no stack formals; bare C3; void
// Per slot: ESI = *(dword*)slot before FUN_007465c0
void GfxVertexBufferFactory_PreResetReleaseAll_Inferred(/* EAX */);
```

| Formal | Source | Conf |
|---|---|---|
| factory* | **EAX** (caller `MOV EAX,[device+0x74C]`) | **High** |
| ESI (callee) | `MOV ESI,[slot]` per iteration | **High** |
| RET | bare `C3` | **High** |
| return | void | **High** |

---

## 4. Control flow (clean ≡ bytes; ESI fix)

```
sentinel = *(EAX+0x14); node = *sentinel
while node != sentinel:
  if (node[+0xE] & 0x28) == 0:
    for slot in [node+0x14, node+0x18) step 0x20:
      ESI = *slot; FUN_007465c0()
  tree_successor(node) via isnil@+0x21, left/parent/right
```

| Stage | Match | Conf |
|---|---|---|
| Body 129 B / pad CC | **Yes** | **High** |
| Tree sentinel +0x14 / isnil+0x21 | **Yes** | **High** |
| Flag TEST [node+0xE],0x28 | **Yes** (`F6 47 0E 28`) | **High** |
| Stride 0x20 | **Yes** (`83 C3 20`) | **High** |
| ESI load omitted by decompiler | **Yes** — bytes `8B 33` | **High** |
| Callee gfxDeviceVB path | **Yes** (string + COM Release) | **High** |
| Sole Device Reset site | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (129 B) — raw W38-AD append.

Entry: `51 8B 48 14 57 8B 39 3B F9`.  
Flag: `F6 47 0E 28`.  
Release loop: `8B 33 E8 … 83 C3 20`.  
Epilogue: `5E 5D 5B 5F 59 C3` @ `0x00986560`.  
Pad `CC`×15 then `FUN_00986570`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker (factory pre-reset release-all) |
| Callers | **1** — `FUN_0075eff0` @ `0x0075f0e7` |
| Callees | `FUN_007465c0` |
| Twin family | IB pre-reset `FUN_00985580` → `FUN_00743c50`; VB PostRestore `FUN_00986570` |

---

## 7. Gaps

1. Product English for flag bits `0x28` on `node+0xE`.
2. Full 0x20 slot field plate beyond +0 VB* (PostRestore uses +8 callback tree).
3. Runtime / bit-exact / differential.

---

## 8. Verdict

Fidelity pass seals EAX factory, tree walk, flag skip, 0x20 slots, ESI→FUN_007465c0, sole Device Reset wiring to `+0x74C`. Residual flag/slot English → **accept-with-gaps**.
