# Review A (reconstruction fidelity): `aa_00404510` UiToast_UninitializedCopy_0x98

| Field | Value |
|---|---|
| **Stable ID** | `aa_00404510` |
| **VA** | `0x00404510` |
| **Body** | `0x00404510`–`0x0040452f` (32 bytes) |
| **Canonical name** | `UiToast_UninitializedCopy_0x98` |
| **Prior scaffold** | `FUN_00404510` |
| **Review date** | `2026-07-29` (W22-G dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00404510_UiToast_UninitializedCopy_0x98.md` |
| **System** | `missions-progression` / shared UI toast vector helpers |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Thin **relocate / uninitialized_copy** shim for UI-toast POD elements (**stride 0x98**).

Body only reorders stack args and calls `FUN_004047a0`, which walks `[srcBegin, srcEnd)` stepping **+0x98**, `UiToast_PodCopyElement_0x98` (`FUN_00404710`, **0x26 dwords**) each element into the destination cursor (also +0x98), and returns the advanced dest end.

Sole caller: `UiToastVector_InsertN` (`0x00403980`) on realloc relocate and in-place shift paths (four xrefs). **Not** construct-from-template fill (`0x00404130` / `0x00404670`); **not** the pod copy leaf.

ABI (bytes): **`ret 0x0C`** (3 stack args) after `call FUN_004047a0` + `add esp, 0x14` (cdecl 5-push decompiler print is artifactual; worker takes 3 formals). Twin of floater `CombatFloater_UninitializedCopy_0x38_Inferred` @ `0x004044c0`.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x00404510`, `0x004047a0`, `0x00404710` |
| Bytes | `read_memory` 64 B @ `0x00404510` — hex ends `83c414c20c00` |
| Bounds | `get_function_by_address` body `00404510`–`0040452f` |
| Callers | only `FUN_00403980` (`get_function_callers` / xrefs ×4) |
| Callee | `FUN_004047a0` only |
| Pod leaf dual | `A_aa_00404710_UiToast_PodCopyElement_0x98` |
| Parent dual | `A_aa_00403980_UiToastVector_InsertN` |
| Twin dual | `A_aa_004044c0_CombatFloater_UninitializedCopy_0x38_Inferred` |
| Fill-n sibling | `A_aa_00404130_UiToast_UninitializedFillN_0x98` |
| Raw / clean | `aa_00404510_*`, `UiToast_UninitializedCopy_0x98.cpp` |

**Not performed:** Launcher, runtime, bit-exact, dual of worker `004047a0`, parent ledgers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Sole callee `FUN_004047a0` | **Confirmed** | decompile + bytes call |
| Element stride **0x98** in worker | **Confirmed** | `param_1 += 0x98` loop |
| Worker = pod copy via `FUN_00404710` (0x26 dwords) | **Confirmed** | sealed pod-leaf dual |
| Role = range copy src→dst (relocate) | **High** | parent insert uses as relocate helper |
| `ret 12` / 3 stack args | **Confirmed** | `C2 0C 00` |
| Body **32 bytes** | **Confirmed** | bounds + hex length |
| Decompiler 4/5 formal names unreliable | **Confirmed** | arg shuffle trampoline |
| Product / RTTI name | **Open** | role sealed; symbol not product |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Only call `FUN_004047a0` then return | Yes |
| No local loops / no alloc | Yes |
| Worker: for each src elt → pod-copy → dst+=0x98 | Yes (callee) |
| ret 0x0C | Yes |

```c
// UiToast_UninitializedCopy_0x98(srcBegin, srcEnd, dst):
//   return FUN_004047a0(srcBegin, srcEnd, dst);
// FUN_004047a0:
//   for (p = srcBegin; p != srcEnd; p += 0x98) {
//     PodCopy0x98(dst, p); dst += 0x98;
//   }
//   return dst;
```

---

## 5. Gaps / open

1. Exact stack-arg order at this VA vs parent insert sites (decompiler thiscall noise; bytes map 3 stack args → worker `(a1,a2,a3)`).
2. Product name (keep structural; no PDB).
3. Optional dual on `FUN_004047a0` if still scaffold-only (residual, not OWN this wave).
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
