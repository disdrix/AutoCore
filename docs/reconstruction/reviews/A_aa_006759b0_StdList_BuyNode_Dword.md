# Review A (reconstruction fidelity): `aa_006759b0` StdList_BuyNode_Dword

| Field | Value |
|---|---|
| **Stable ID** | `aa_006759b0` |
| **VA** | `0x006759b0` |
| **Body** | `0x006759b0`–`0x006759d6` (**39** B) |
| **Canonical name** | `StdList_BuyNode_Dword` (**Inferred**) |
| **Prior / alias** | `FUN_006759b0`; parent-seed `Named_CalleeOf_Auth_AuthServer_006759b0` (**misleading domain**) |
| **Review date** | `2026-07-29` (W20-M OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_006759b0_StdList_BuyNode_Dword.md` |
| **System** | shared MSVC `std::list` node helper |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `get_function_by_address`, `get_xrefs_to` (no `disassemble_bytes`) |
| **Verdict** | **accept** |

---

## 1. Purpose

**Buy (allocate + init) a 12-byte list node** for dword/pointer-sized `std::list` elements:

1. `operator_new(0xC)`
2. If non-null: store `link0` @ +0, `link1` @ +4, `*pValue` @ +8
3. Return node pointer in **EAX** (0 on failure)

This is a shared CRT/STL-shaped leaf. Auth, audio queue (`StdList_PushPayloadNode`), map UI, and many other systems call it; the Auth parent-seed name is **not** the purpose.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_006759b0_FUN_006759b0.md` (+ W20-M live append) |
| Annotated | `docs/reconstruction/raw/aa_006759b0_FUN_006759b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdList_BuyNode_Dword.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_006759b0.cpp` |
| Function record | `docs/reconstruction/functions/aa_006759b0_StdList_BuyNode_Dword.md` |
| Live decompile | `decompile_function` @ `0x006759b0` → new/fill/return |
| Live bytes | `read_memory` length 39 → hex seal below |
| Function bounds | `get_function_by_address` → `006759b0`–`006759d6` |

---

## 3. Byte seal (`read_memory` @ `0x006759b0`)

```
6a 0c                push 0xC
e8 .. .. .. ..       call operator_new
83 c4 04             add  esp, 4
85 c0                test eax, eax
74 16                jz   fail
8b 4c 24 04          mov  ecx, [esp+4]     ; link0
8b 54 24 08          mov  edx, [esp+8]     ; link1
89 08                mov  [eax], ecx
8b 4c 24 0c          mov  ecx, [esp+0xC]   ; pValue
89 50 04             mov  [eax+4], edx
8b 11                mov  edx, [ecx]
89 50 08             mov  [eax+8], edx
c2 0c 00             ret  0xC
```

| Claim | Evidence | Conf |
|---|---|---|
| Alloc size **0xC** | `push 0xC` | **High** |
| Null gate before stores | `test eax` / `jz` | **High** |
| Three dword writes | movs to `[eax]`, `[eax+4]`, `[eax+8]` | **High** |
| Value is **dereferenced** pointer | `mov edx,[ecx]` then store | **High** |
| `__stdcall` 12-byte cleanup | `ret 0xC` | **High** |
| Return in EAX | no xor; callers assign | **High** |
| Decompile ≡ raw ≡ bytes | all match CF | **High** |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| `operator_new(0xC)` | **Yes** |
| Null check | **Yes** |
| `node[0]=link0; node[1]=link1; node[2]=*pValue` | **Yes** |
| No size++ / no relink | **Yes** (callers do that) |
| No invented freelist | **Yes** |

Clean plate documents return type correctly (decompiler `void` corrected).

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Shared list `_Buynode` leaf | **High** | 40+ xrefs; uniform insert pattern |
| Node = 3 dwords | **High** | bytes + size |
| Not Auth-specific | **High** | xrefs span domains |
| Product symbol string | **Open** | no body strings |
| Runtime / bit-exact | **Open** | deferred |

---

## 6. Gaps / open

1. PDB / MSVC exact template symbol.
2. Exhaustive caller catalog (not required for CF seal).
3. Whether any path relies on undefined EAX when new fails beyond returning 0.

**Verdict:** **accept**
