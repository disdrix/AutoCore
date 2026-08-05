# Review A (reconstruction fidelity): `aa_0046c6c0` StdTree_Buynode_Val12_EsiValue

| Field | Value |
|---|---|
| **Stable ID** | `aa_0046c6c0` |
| **VA** | `0x0046c6c0` |
| **Body** | `0x0046c6c0`–`0x0046c702` exclusive (**66** B) |
| **Canonical name** | `StdTree_Buynode_Val12_EsiValue` (inferred) |
| **Ghidra symbol** | `FUN_0046c6c0` |
| **Prior / alias** | `Named_CalleeOf_…_effDeviceEff_0046c6c0` (narrow) |
| **Review date** | `2026-07-29` (W28-T OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_0046c6c0_StdTree_Buynode_Val12_EsiValue.md` |
| **System** | std map/set tree node buy |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, meta/xrefs (**no** `disassemble_bytes`) |
| **Verdict** | **accept** |

---

## 1. Purpose

Allocate a **0x1c** red-black tree node and initialize:

1. left / parent / right from three stack pointer args  
2. 12-byte value (3 dwords) from **`*ESI`**  
3. color byte from stack arg4; **isnil = 0**  
4. return node* or null (`operator_new` fail)

ESI-value ABI twin of `StdTree_Buynode_Val12` (`0x005ae220`).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0046c6c0_FUN_0046c6c0.md` (+ W28-T append) |
| Annotated | `docs/reconstruction/raw/aa_0046c6c0_FUN_0046c6c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Buynode_Val12_EsiValue.cpp` |
| Scaffold | `reconstructed-exact/FUN_0046c6c0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0046c6c0_StdTree_Buynode_Val12_EsiValue.md` |
| Live decompile | ≡ raw |
| Live body bytes | `read_memory` @ `0x0046c6c0` length 66+ |
| Consumer | `FUN_0044a8c0` insert+rebalance (W27-P ESI buy path) |
| Twin | `FUN_005ae220` stack value* / `ret 0x14` |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte seal (`read_memory` @ `0x0046c6c0`)

```
push 0x1c / call operator_new / add esp,4
test eax / jz ret
store left@0, parent@4, right@8 from stack
copy [esi]+0/+4/+8 → node+0x0c
color → +0x18; isnil=0 @ +0x19
ret 0x10
```

Hex (66 B):

```
6a1ce8cbd1010083c40485c074328b4c24048b54240889088b4c240c8950048948088b0e8d500c890a8b4e04894a048b4e08894a088a542410885018c6401900c21000
```

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Body size exclusive end `0046c702` | **pass** |
| `ret 0x10` (not 0x14) | **pass** |
| Null path returns EAX=0 | **pass** |
| Value from ESI (`8b 0e` …) | **pass** |
| isnil forced 0 | **pass** |
| No extra ctor / vtbl stamp | **pass** |
| Decompiler void vs EAX return | **corrected** |
| Distinct from `005ae220` | **pass** |

---

## 5. Gaps

1. Full MSVC demangle for each instantiating map type.  
2. Runtime OOM path.  
3. Bit-exact / differential — open.

**Verdict:** **accept**
