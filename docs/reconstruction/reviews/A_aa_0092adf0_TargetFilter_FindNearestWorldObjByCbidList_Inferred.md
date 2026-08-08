# Review A (reconstruction fidelity): `aa_0092adf0` TargetFilter_FindNearestWorldObjByCbidList_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092adf0` |
| **VA** | `0x0092adf0` |
| **Canonical name** | `TargetFilter_FindNearestWorldObjByCbidList_Inferred` |
| **Review date** | `2026-08-04` (WQ8R-I dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0092adf0_TargetFilter_FindNearestWorldObjByCbidList_Inferred.md` |
| **System** | skills-abilities / inventory-adjacent |
| **Scratch** | `tmp/a_0092adf0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

CBID-whitelist nearest world-object scan for a multi-arm target filter. Inventory adjacency: skips objects whose COID is already present in the character **locker** grid via `InventoryGrid_FindItemByCoid`.

WQ-008 residual: skill-adjacent inventory consumer.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | Ghidra `decompile_function` / `batch_decompile` `0x0092adf0` |
| Image entry / epilogue | `read_memory` @`0x0092adf0` (200B) + @`0x0092af60` → **`ret 0x0C`**, `mov al,1` |
| Body range | `get_function_by_address` → `0092adf0`–`0092af7a` |
| Callers | sole `FUN_0092af80`; grandcaller `FUN_0092bf60` |
| Callees | TraversalLock, IterateNext, FindItemByCoid, LeaveCriticalSection |
| Sibling decompiles | `0092abc0`, `0092a980`, `0092af80` for ctx layout |
| Sealed grid plate | DropResponse / Collect duals: `char+0xCBC` = locker type-3 |
| Raw / clean / record | updated WQ8R-I |

**Not performed:** `disassemble_bytes`; Launcher runtime.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body + `ret 0x0C` + return 1 | **High** | image epilogue |
| EDI = filter ctx; `*EDI` client | **High** | entry `mov eax,[edi]`; `+0xE98` path |
| Stack origin / bestOut / bestDistSq | **High** | decompiler + `ret 0x0C` |
| Self-exclude `+0x250` adjust vs `obj+0xAC` | **High** | mid-body bytes |
| Find ECX = `*(char+0xCBC)` | **High** | `mov ecx,[ecx+0xCBC]` |
| Continue only if Find returns NULL | **High** | `test eax; jnz skip` |
| CBID count `+0x28`, array `+0x2C` | **High** | matches caller gate `ctx+0x28` |
| Match `*(clonebase+0x34)` | **High** | standard CBID plate |
| Squared distance on `+0x80..+0x88` | **High** | decompiler + vtbl+0x144 first |
| Product class name of ctx | **Tentative** | `_Inferred` |
| Runtime / bit-exact | **Open** | |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Lock + iterate world list | **Yes** |
| Self-exclude + Find absence gate | **Yes** (bytes seal ECX) |
| CBID whitelist loop | **Yes** |
| Dist update bestOut/bestDistSq | **Yes** |
| Unlock CS + return 1 | **Yes** |

---

## 5. Gaps

1. Product/PDB name of filter context / owning system (skill vs reaction vs interact).
2. Why locker (`+0xCBC`) instead of cargo (`+0x2B0`) for the absence test.
3. vtbl `+0x144` product English.
4. Runtime observation of nearest-pick behavior.

**Verdict:** **accept-with-gaps** — ABI, list walk, CBID match, inventory Find gate, nearest update **sealed**.
