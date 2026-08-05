# Review A (reconstruction fidelity): `aa_004044c0` CombatFloater_UninitializedCopy_0x38_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004044c0` |
| **VA** | `0x004044c0` |
| **Canonical name** | `CombatFloater_UninitializedCopy_0x38_Inferred` |
| **Prior scaffold** | `FUN_004044c0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004044c0_CombatFloater_UninitializedCopy_0x38_Inferred.md` |
| **System** | `missions-progression` / combat floater UI |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Thin **relocate / uninitialized_copy** shim for combat-floater POD elements (**stride 0x38**).

Body only reorders stack args and calls `FUN_00404730`, which walks `[srcBegin, srcEnd)` stepping **+0x38**, `CombatFloater_PodCopyElement_0x38` (`FUN_004046f0`) each element into the destination cursor (also +0x38), and returns the advanced dest end.

Sole caller: `CombatFloaterVector_InsertN_0x38_Inferred` (`0x00403680`) on the realloc/relocate path. **Not** construct-from-template fill (`0x00402ea0` / `0x004044e0`); **not** the pod copy leaf.

ABI (bytes): **`ret 0x0C`** (3 stack args) after `call FUN_00404730` + `add esp, 0x14` (cdecl 5-push decompiler print is artifactual; callee takes 3 formals).

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x004044c0`, `0x00404730`, `0x004046f0` |
| Bytes | `read_memory` 48 B @ `0x004044c0` — `C2 0C 00` |
| Callers | `get_function_callers` → only `FUN_00403680` |
| Raw / clean / record | `docs/reconstruction/raw|reconstructed-exact|functions` `aa_004044c0_*` |
| Parent dual | `A_aa_00403680_CombatFloaterVector_InsertN_0x38_Inferred` |

**Not performed:** Launcher, runtime, bit-exact, ledgers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Sole callee `FUN_00404730` | **Confirmed** | decompile + bytes call |
| Element stride **0x38** in real worker | **Confirmed** | `param_1 += 0x38` loop |
| Worker = pod copy via `FUN_004046f0` (14 dwords) | **Confirmed** | sibling dual `CombatFloater_PodCopyElement_0x38` |
| Role = range copy src→dst (relocate) | **High** | parent insert uses as relocate helper |
| `ret 12` / 3 stack args | **Confirmed** | `C2 0C 00` |
| Decompiler 4/5 formal names are unreliable | **Confirmed** | arg shuffle trampoline |
| Product / RTTI name | **Open** | INFERRED |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Only call `FUN_00404730` then return | Yes |
| No local loops / no alloc | Yes |
| Worker: for each src elt → pod-copy → dst+=0x38 | Yes (callee) |

```c
// inferred — thiscall trampoline; exact stack map open beyond ret 12
// FUN_00404730(srcBegin, srcEnd, dstBegin):
//   for (p = srcBegin; p != srcEnd; p += 0x38) {
//     PodCopy0x38(dst, p); dst += 0x38;
//   }
//   return dst;
```

---

## 5. Gaps / open

1. Exact stack-arg order at this VA vs parent insert sites (decompiler thiscall noise).
2. Product name (keep INFERRED).
3. Whether worker is ever used outside floater insert (xrefs only parent).

**Verdict:** **accept-with-gaps**
