# Dual A/B report — W21-K OWN (`aa_005a2410`, `aa_006380a0`)

**Date:** 2026-07-29  
**Agent:** W21-K OWN-ONLY  
**Scope:** OWN ONLY VAs `0x005a2410`, `0x006380a0`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` (+ xrefs / callees). No `disassemble_bytes`.  
**Programs open:** `autoassault.exe` (image base `0x400000`).  
**Dual A/B:** fidelity (A) vs adversarial (B) reviews — not two programs.

---

## Verdicts

| Unit | Canonical name | Verdict |
|------|----------------|---------|
| `aa_005a2410` / `0x005a2410` | `TNL_NetClassRepInstance_Ctor` | **accept** |
| `aa_006380a0` / `0x006380a0` | `Mem_CopyBytes` | **accept** |

---

## Sealed facts — `0x005a2410` TNL_NetClassRepInstance_Ctor

1. **ABI:** MSVC **`__thiscall`** — **ECX = this**, stack **className, classGroupMask, classType, classVersion**, epilogue **`ret 0x10`**. Body **`0x005a2410`–`0x005a2466`** (**87 B**).

2. **Base init:** `FUN_0042aea0` (base ClassRep vtbl `PTR_LAB_009d7af4` + zero counters).

3. **Derived vtbl:** `*this = PTR_FUN_009d7bf4` @ `0x009d7bf4` (NetClassRepInstance).

4. **Name:** `_strdup(className)` → `this+0x20` (IAT `0x009c6474`).

5. **Fields:** `+0x04=groupMask`, `+0x08=version`, `+0x0C=type`, `+0x10..+0x1C=classId[4]=0`, `+0x34=next`.

6. **ClassList:** prepend via global head **`DAT_00d179a4`** (`this->next = head; head = this`).

7. **CRT caller:** `0x009c0eb0` builds GuaranteedOrdered RPC ClassRep at `DAT_00b04f40` with name `RPC_TNLConnection_rpcMsgGuaranteedOrdered` @ `0x009d80cc`, group=`1`, type=`2` (Event), version=`0`.

8. **Sibling dtor:** `FUN_005a2470` frees name, restores base vtbl.

9. **Name:** `TNL_NetClassRepInstance_Ctor` — RTTI + CRT + TNL.NET ctor shape. Former `FUN_005a2410`.

10. **Three-rep:** raw 2026-07-23 CF ≡ live decompile ≡ body bytes / CRT seal.

### Gaps (`005a2410`)

1. Sibling ClassRep ctor variants sharing the same list head (other VAs).  
2. Base-only field product names (`FUN_0042aea0` slots).  
3. Runtime ClassList / Initialize golden — open.

---

## Sealed facts — `0x006380a0` Mem_CopyBytes

1. **ABI:** **`__cdecl`** — stack **dst, src, n**, bare **`ret`**. Body **`0x006380a0`–`0x006380be`** (**31 B**).

2. **Algorithm:** `rep movsd` for `n >> 2` dwords, then `rep movsb` for `n & 3` bytes (ESI=src, EDI=dst).

3. **Semantics:** forward-only **memcpy** (not memmove); **void** return; leaf.

4. **Callers:** 40+ including `FUN_005b3300`, `FUN_005b3370` (grow copy `count * elemSize`).

5. **Name:** `Mem_CopyBytes` — structural (product/PDB open). Former `FUN_006380a0` / multi-callee alias.

6. **Three-rep:** raw 2026-07-23 CF ≡ live decompile ≡ body bytes.

### Gaps (`006380a0`)

1. Product English symbol.  
2. Runtime / bit-exact differential — open.  
3. Overlap-using callers (none observed; grow uses new heap dest).

---

## Dual A/B

| VA | Review A | Review B | Verdict |
|---|---|---|---|
| `0x005a2410` | `reviews/A_aa_005a2410_TNL_NetClassRepInstance_Ctor.md` | `reviews/B_aa_005a2410_TNL_NetClassRepInstance_Ctor.md` | **accept** |
| `0x006380a0` | `reviews/A_aa_006380a0_Mem_CopyBytes.md` | `reviews/B_aa_006380a0_Mem_CopyBytes.md` | **accept** |

---

## Files

### `aa_005a2410` / `TNL_NetClassRepInstance_Ctor`

| Kind | Absolute path |
|------|----------------|
| Review A | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\A_aa_005a2410_TNL_NetClassRepInstance_Ctor.md` |
| Review B | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\B_aa_005a2410_TNL_NetClassRepInstance_Ctor.md` |
| Function record | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\functions\aa_005a2410_TNL_NetClassRepInstance_Ctor.md` |
| Function alias | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\functions\aa_005a2410_FUN_005a2410.md` |
| Clean named | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reconstructed-exact\TNL_NetClassRepInstance_Ctor.cpp` |
| Clean FUN_* | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reconstructed-exact\FUN_005a2410.cpp` |
| Raw (+ re-verify append) | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_005a2410_FUN_005a2410.md` |
| Annotated | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_005a2410_FUN_005a2410.annotated.md` |

### `aa_006380a0` / `Mem_CopyBytes`

| Kind | Absolute path |
|------|----------------|
| Review A | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\A_aa_006380a0_Mem_CopyBytes.md` |
| Review B | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\B_aa_006380a0_Mem_CopyBytes.md` |
| Function record | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\functions\aa_006380a0_Mem_CopyBytes.md` |
| Function alias | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\functions\aa_006380a0_FUN_006380a0.md` |
| Clean named | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reconstructed-exact\Mem_CopyBytes.cpp` |
| Clean FUN_* | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reconstructed-exact\FUN_006380a0.cpp` |
| Raw (+ re-verify append) | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_006380a0_FUN_006380a0.md` |
| Annotated | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_006380a0_FUN_006380a0.annotated.md` |

### This report

`C:\Users\josh\Documents\GitHub\AutoCore\docs\agents\task-dual-ab-own-w21k-005a2410-006380a0-report.md`

---

## Sibling context (not owned)

| VA | Role |
|---|---|
| `0x0042aea0` | Base ClassRep init (callee of ctor) |
| `0x005a2470` | NetClassRepInstance dtor (free name; restore base vtbl) |
| `0x0059e1c0` | `RPC_rpcMsgGuaranteedOrdered_Method1` getClassRep → `DAT_00b04f40` |
| `0x00b04f40` | Static ClassRep storage (span 0x38) for GuaranteedOrdered RPC |
| `0x00d179a4` | Global ClassList head |
| `0x005b3300` / `0x005b3370` | HB / GrowableArray grow (call Mem_CopyBytes) |
| `0x004e2e80` | `Mem_MoveDwordRange_ReturnEnd` (different mem helper; IAT memmove) |

---

## AutoCore impact

- **ClassRep registry:** construct static NetClassRepInstance rows with owned name strings and a global ClassList prepend; dtor must free name. Align with existing `TNL.NET` `NetClassRep` / `NetClassRepInstance` rather than a second registry.  
- **Buffer grow:** after alloc of `newCap * elemSize`, copy old payload with **byte-count** `Mem_CopyBytes(new, old, count * stride)` — forward-only; dest is new heap.
