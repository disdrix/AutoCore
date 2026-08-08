# Review A (reconstruction fidelity): `aa_004c8780` Object_TFIDMap_FindFirstLive_EraseDead_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c8780` |
| **VA** | `0x004c8780`–`0x004c8963` exclusive (**483 B** / `0x1E3`) |
| **Canonical name** | `Object_TFIDMap_FindFirstLive_EraseDead_Inferred` |
| **Ghidra symbol** | `FUN_004c8780` |
| **Review date** | `2026-08-04` (WQ9F-C OWN-ONLY dual) |
| **Reviewer role** | Reconstruction fidelity (Path A) |
| **Counterpart** | `reviews/B_aa_004c8780_Object_TFIDMap_FindFirstLive_EraseDead_Inferred.md` |
| **System** | creature/object TFID map + resolve scrub |
| **Live tools** | Ghidra `batch_decompile` / `decompile_function`, `read_memory`, `analyze_function_complete`, xrefs/assembly_context (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Walk host TFID map (`shell this+0x154`, `head +0x158`): erase dead resolved entries (and clear selected target if matched); return first live object that passes `vtbl+0x210(0)` or related-resolve gate; else null.

```c
void * __thiscall Object_TFIDMap_FindFirstLive_EraseDead_Inferred(void *self);
// bare ret; object* or 0
```

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004c8780_FUN_004c8780.md` |
| Annotated | `docs/reconstruction/raw/aa_004c8780_FUN_004c8780.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_TFIDMap_FindFirstLive_EraseDead_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_004c8780.cpp` |
| Function record | `docs/reconstruction/functions/aa_004c8780_Object_TFIDMap_FindFirstLive_EraseDead_Inferred.md` |
| Live decompile | ≡ raw CF |
| Erase dual | WQ9E-E `StdTree_EraseAndRebalance_Isnil29_Inferred` |
| Resolve duals | `Object_ResolveFromTFID`; `Object_ResolveTfIdVtbl1dc_Inferred` |
| Map peer | `Object_TFIDMapLookupOrRelatedMatch_Inferred` (`+0x154/+0x158`) |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Entry | `83 EC 24 53 55 8B E9` (`mov ebp,ecx` thiscall) |
| Map erase thiscall | `LEA ECX,[EBP+0x154]; CALL 0x004cb740` @ `0x004c893e` |
| Null return | `XOR EAX,EAX; POP…; ADD ESP,0x24; RET` @ `0x004c894f` |
| Object return | `MOV EAX,EBX; … ADD ESP,0x24; RET` |
| Null TFID | `DAT_009cb8c0` = `ff…ff / 00 / 00` (`read_memory`) |
| isnil | successor `+0x29` immediates |
| Body exclusive end | `0x004c8963` (pad `CC`) |

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw CF | **pass** |
| Body / bare ret / frame 0x24 | **pass** |
| Map shell `+0x154` for erase ECX | **pass** (assembly_context) |
| Dead erase + live return gates | **pass** |
| Uses dualed isnil29 erase | **pass** |
| Clean meaningful names | **pass** |
| Product method English | **gap** |
| Static callers | **gap** (0 xrefs) |
| vtbl slot English | **gap** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI bare ret | **High** | live ≡ raw; bytes |
| Map @ +0x154 / head +0x158 | **High** | peer + erase lea |
| Dead scrub + erase | **High** | call 004cb740 |
| First-live return role | **High** | early returns |
| Name `…_Inferred` | **Inferred** | structural; no PDB |
| Call graph reachability | Low–Med | 0 xrefs |
| Runtime | Open | |

---

## 6. Gaps

1. Product/PDB method + host class English.  
2. vtbl+0x210 / +0x214 / +0x258 product names.  
3. Zero static callers (vtable scan).  
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
