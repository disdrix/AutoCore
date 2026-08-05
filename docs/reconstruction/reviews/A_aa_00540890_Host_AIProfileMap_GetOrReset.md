# Review A (reconstruction fidelity): `aa_00540890` Host_AIProfileMap_GetOrReset

| Field | Value |
|---|---|
| **Stable ID** | `aa_00540890` |
| **VA** | `0x00540890`–`0x005408e9` |
| **Canonical name** | `Host_AIProfileMap_GetOrReset` |
| **Ghidra name** | `FUN_00540890` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W26-N) |
| **Counterpart** | `reviews/B_aa_00540890_Host_AIProfileMap_GetOrReset.md` |
| **System** | npc-ai / host tables / profile map |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + xrefs/callers; HBAI duals W25-J |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Host helper: return the AI-profile map container at `host+0xF00`. If `size==0` or `forceReset!=0`, clear the MSVC-like red-black tree (free nodes, re-link sentinel, size=0) and call `FUN_007c3b80(map)`. Always returns the map base for subsequent `FUN_004cbd50` lower_bound.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00540890_FUN_00540890.md` (+ W26-N append) |
| Annotated | `docs/reconstruction/raw/aa_00540890_FUN_00540890.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/Host_AIProfileMap_GetOrReset.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00540890.cpp` |
| Function | `docs/reconstruction/functions/aa_00540890_Host_AIProfileMap_GetOrReset.md` |
| Live | decompile ≡ raw; `read_memory` 90 B |

---

## 3. Signature

```c
// Ghidra: int __thiscall FUN_00540890(int param_1, char param_2)
// Bytes: MOV EDI,ECX … LEA EAX,[EDI+0xF00]; POP EDI; RET 4
uint32_t __thiscall Host_AIProfileMap_GetOrReset(void *host, char forceReset);
```

| Item | Evidence | Conf |
|---|---|---|
| thiscall ECX=host | `8B F9` | **High** |
| `ret 4` | `C2 04 00` | **High** |
| EAX = host+0xF00 | `8D 87 00 0F 00 00` | **High** |
| Call sites use `DAT_00b041fc` | HBAI duals | **High** |

---

## 4. Control flow (sealed)

```
if size==0 || forceReset:
  FUN_005436c0(head->parent)
  head->parent = head->left = head->right = head
  size = 0
  FUN_007c3b80(map)   // ECX=DAT_00b0469c at call
return map  // host+0xF00
```

| Stage | Match | Conf |
|---|---|---|
| Dual gate size/force | **Yes** | **High** |
| MSVC sentinel re-link | **Yes** | **High** |
| Always return map base | **Yes** | **High** |
| Leaf-of-HBAI profile lookup | **Yes** (caller duals) | **High** |

---

## 5. Machine bytes (`read_memory`)

| Addr | Bytes | Decode |
|---|---|---|
| `0x00540890` | `57 8B F9 83 BF 08 0F 00 00 00` | EDI=this; CMP size |
| force test | `80 7C 24 08 00 74 3D` | CMP forceReset; JE skip |
| ECX global | `8B 0D 9C 46 B0 00` | MOV ECX,`DAT_00b0469c` before `FUN_007c3b80` |
| tail | `8D 87 00 0F 00 00 5F C2 04 00` | LEA EAX,[EDI+0xF00]; RET 4 |

**No `disassemble_bytes` used.**

---

## 6. Call surface

| Caller | Sites | Pattern |
|---|---|---|
| `CVOGHBAIDriver_DoLogic` | ×2 | get → lower_bound → get for end-it |
| `CVOGHBAICreatureBase_DoLogic` | ×2 | same |
| `FUN_004c9430` / `FUN_004c9120` / `FUN_005d7ca0` | ×2 each | same family |

Callees: `FUN_005436c0`, `FUN_007c3b80` (not OWN this partition).

---

## 7. Confidence

| Claim | Level |
|---|---|
| ABI + map layout + clear CF | **High** |
| Role as AI profile map accessor | **High** |
| Product host/map C++ names | **Probable / Open** |
| `FUN_007c3b80` semantics | **Partial** (out of OWN) |
| Runtime / bit-exact | **Open** |

---

## 8. Gaps

1. Product English for host type and map `value_type`.
2. Full meaning of `FUN_007c3b80` post-clear.
3. Nested free helper `FUN_005436c0` details (owned elsewhere).
4. Runtime / bit-exact.

**Verdict:** **accept-with-gaps** — ABI/CF/layout sealed; product English open.
