# Review A (reconstruction fidelity): `aa_005380d0` Staging map node construct

| Field | Value |
|---|---|
| **Stable ID** | `aa_005380d0` |
| **VA** | `0x005380d0` |
| **Canonical name** | `FUN_005380d0` (product English open) |
| **Inferred role** | Mission-staging RB-tree **node construct** (`new(0x50)` + link + value copy) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw + bytes) |
| **Counterpart** | `reviews/B_aa_005380d0_StagingMapNode_Construct.md` |
| **System** | `missions-progression` |
| **Dual status** | **Present — sealed 2026-07-29** |
| **Verdict** | **accept-with-gaps** |
| **Scratch** | `reviews/a_005380d0.md` |

---

## 1. Purpose

Freestanding (non-member) allocator/initializer for one **StagingMapNode** used exclusively by the mission-staging map insert+rebalance helper `FUN_00538ea0` (which is driven by `FUN_00539cb0` / parent store `FUN_0052c700`).

1. `operator_new(0x50)`.
2. On success: write left/parent/right pointers; **`REP MOVSD` 0xE dwords** from value-pair into `node+0x10`; set **color** from arg; force **isnil = 0**.
3. Return node pointer in **EAX** (null if alloc failed — init skipped).

Does **not** link into the tree, rebalance, or bump map size — that is `FUN_00538ea0`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005380d0_FUN_005380d0.md` |
| Annotated | `docs/reconstruction/raw/aa_005380d0_FUN_005380d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_005380d0.cpp` |
| Function record | `docs/reconstruction/functions/aa_005380d0_FUN_005380d0.md` |
| Fresh decompile | Ghidra `decompile_function` @ `0x005380d0` (2026-07-29) — CF ≡ raw 2026-07-23 |
| Body image | Ghidra `read_memory` @ `0x005380d0` length 96 — ends `C2 14 00`; `push 0x50`; `F3 A5` with `ECX=0xE`; color `[eax+0x48]`; isnil `[eax+0x49]=0` |
| Sole callee | `operator_new` @ `0x00489892` |
| Sole caller | `FUN_00538ea0` @ `0x00538ea0` (xref `0x00538f32`); caller uses return: `mov ecx,eax` |
| Parent dual | `A/B_aa_00539cb0_MissionStagingMap_Insert` — seals key `+0x10`, payload `+0x18`×12, map @ `Character+0x508` |
| Callers | Ghidra `get_function_callers` / `get_xrefs_to`: **only** `FUN_00538ea0` |

**Not performed:** `disassemble_bytes`, Launcher, runtime capture, binary diff.

---

## 3. Evidence table

| Claim | Evidence | Confidence |
|---|---|---|
| Stack args **5× dword** + **`RET 0x14`** | Epilogue `C2 14 00` | **High** |
| Not `__thiscall` (no `this` in ECX) | Body never uses ECX as object base; freestanding stdcall-style | **High** |
| Returns **node\*** in **EAX** | Alloc result kept in EAX; caller `FUN_00538ea0` does `mov ecx,eax` after call; decomp `void` is **wrong** | **High** |
| Alloc size **0x50** | `6A 50` / `operator_new(0x50)` | **High** |
| Null alloc → skip init, return null | `test eax; jz` over init block | **High** |
| `+0x00` left\* = param_1 | `mov [eax], ecx` from `[esp+4]` | **High** |
| `+0x04` parent\* = param_2 | `mov [eax+4], edx` from `[esp+8]` | **High** |
| `+0x08` right\* = param_3 | `mov [eax+8], ecx` from stack param_3 | **High** |
| `+0x0C` **not written** by ctor | No store to `[eax+0xC]` in body | **High** |
| Value block **14 dwords** @ `+0x10` | `lea edi,[eax+0x10]` / `mov ecx,0xE` / `rep movsd` | **High** |
| Color `u8` @ `+0x48` = param_5 | `mov [eax+0x48], dl` | **High** |
| isnil `u8` @ `+0x49` = **0** (always) | `mov byte [eax+0x49], 0` | **High** |
| `+0x4A..+0x4F` uninitialized pad | Size 0x50; no stores past `+0x49` | **High** |
| Caller passes color **0** (new red) | `FUN_00538ea0`: last arg literal `0` | **High** |
| Caller left=right=**head** (`map+4`), parent=**where** | Decomp + push pattern at `0x00538f32` | **High** |
| Sole static caller `FUN_00538ea0` | xrefs | **High** |
| Product English / MSVC `_Tree_node` typedef name | No string/RTTI this pass | **Open** |
| Runtime / bit-exact | Not run | **Open** |

---

## 4. Sealed layouts

```
// ABI (image-sealed)
//   StagingMapNode* FUN_005380d0(
//       StagingMapNode* left,      // stack +4
//       StagingMapNode* parent,    // stack +8
//       StagingMapNode* right,     // stack +C
//       const uint32_t* valuePair, // stack +10 — 14 dwords
//       uint8_t color);            // stack +14 (byte in dword slot)
//   RET 0x14; result in EAX (0 if new failed)

StagingMapNode  // size 0x50
  +0x00  left*          // param_1
  +0x04  parent*        // param_2
  +0x08  right*         // param_3
  +0x0C  (uninitialized by this ctor; not used by insert walk/compare)
  +0x10  key (int / mission id)           // valuePair[0]
  +0x14  pad dword (pair mid)             // valuePair[1]
  +0x18  MissionStagingPayload[12]        // valuePair[2..13]; 0x30 bytes
  +0x48  color (u8)     // param_5; caller always passes 0 on insert
  +0x49  isnil (u8)     // forced 0 (real node, not head sentinel)
  +0x4A  pad to 0x50    // uninitialized by this ctor
```

Value-pair geometry matches parent dual: **1 key + 1 pad + 12 payload = 14 dwords**.

---

## 5. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| `push 0x50` / `operator_new` / `add esp,4` | **Yes** |
| Null → skip stores | **Yes** |
| left / right / parent order (right written before parent in asm; same final state) | **Yes** |
| `REP MOVSD` ECX=0xE from value\* → `+0x10` | **Yes** |
| color `+0x48`, isnil `+0x49=0` | **Yes** |
| `RET 0x14` | **Yes** |
| No tree link / size++ / rebalance in this unit | **Yes** |
| Decomp `void` vs return EAX | **Bytes win** — returns node\* |

---

## 6. Callers (OWN boundary)

| VA | Name | Role re this unit |
|---|---|---|
| `0x00538ea0` | Mission staging map insert+rebalance | Sole caller: `new` node with left=right=head, parent=where, color=0, then size++, link, rebalance |

Higher insert (`0x00539cb0`) and store (`0x0052c700`) own map walk / payload fill — **not** this unit.

---

## 7. Gaps / open questions

1. Product English / MSVC template node typedef for this map type.
2. Semantic of pad dword at `node+0x14` (alignment vs reserved) — layout effect sealed.
3. Whether `+0x0C` is ever written later by other helpers (not by this ctor; walk/compare duals do not use it).
4. Runtime / bit-exact / image diff.
5. Formal Ghidra rename (`StagingMapNode_Construct` / `MissionStagingMap_Node_Ctor`) — **role High**.

---

## 8. Verdict

### **accept-with-gaps**

**Accept because:** Fresh decompile matches raw CF; body bytes seal alloc size `0x50`, five stack args + `RET 0x14`, link triple, 14-dword value copy @ `+0x10`, color `+0x48`, isnil `+0x49=0`, return in EAX; sole caller is staging insert+rebalance with color 0. Product name and pad English remain open.
