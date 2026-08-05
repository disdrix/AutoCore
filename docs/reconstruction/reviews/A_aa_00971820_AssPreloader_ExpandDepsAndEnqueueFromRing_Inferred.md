# Review A (reconstruction fidelity): `aa_00971820` AssPreloader_ExpandDepsAndEnqueueFromRing_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00971820` |
| **VA** | `0x00971820`–`0x009718fd` (**222 B**) |
| **Canonical name** | `AssPreloader_ExpandDepsAndEnqueueFromRing_Inferred` |
| **Ghidra name** | `FUN_00971820` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W32-K) |
| **Counterpart** | `reviews/B_aa_00971820_AssPreloader_ExpandDepsAndEnqueueFromRing_Inferred.md` |
| **System** | assPreloader / asset preload pipeline |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (full 222 B) + `analyze_function_complete` + `get_function_by_address` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Walk a caller-owned GuardedVector ring of asset keys; for each key expand dependencies into a local ring and enqueue eligible keys into AssPreloader pending via `AssPreloader_EnqueueEligibleFromRing_Inferred`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00971820_FUN_00971820.md` (+ W32-K append) |
| Annotated | `docs/reconstruction/raw/aa_00971820_FUN_00971820.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssPreloader_ExpandDepsAndEnqueueFromRing_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00971820.cpp` |
| Function record | `docs/reconstruction/functions/aa_00971820_FUN_00971820.md` |
| Named record | `docs/reconstruction/functions/aa_00971820_AssPreloader_ExpandDepsAndEnqueueFromRing_Inferred.md` |
| Live | decompile ≡ raw CF; full body hex; `MOV EBP,ECX`; `RET 4`; EAX=0 |

---

## 3. Signature (sealed)

```c
// ECX=host; stdcall 1 (source*); RET 4; returns 0
uint32_t AssPreloader_ExpandDepsAndEnqueueFromRing_Inferred(
    void* host /*ECX*/,
    GuardedVectorHeader* source /*stack*/);
```

| Slot | Source | Conf |
|---|---|---|
| host | **ECX** (`MOV EBP,ECX`) | **High** |
| source ring | Stack (`MOV EBX,[ESP+…]`) | **High** |
| cleanup | **`RET 4`** | **High** |
| return | **EAX = 0** | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
local = empty GuardedVector
for idx in [source.begin, source.begin+source.size):
  if local.size != 0: erase local full range (FUN_0043df90)
  key* = slot(source, idx)
  PushBack(local, key)                 // FUN_0043d670
  ExpandDeps(key, local)               // FUN_00744360 (ECX=*(cache+0x64))
  EnqueueEligible(host, local)         // FUN_00971640 ESI=local
FUN_005b2ba0(local)
return 0
```

| Stage | Match | Conf |
|---|---|---|
| Source ring page wrap | **Yes** | **High** |
| Clear-before-reuse local | **Yes** | **High** |
| Push key + expand deps | **Yes** | **High** |
| Enqueue via sealed sibling | **Yes** | **High** |
| Destroy local + return 0 | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Entry / host:

```
6A FF 68 27 FE 9A 00   ; SEH
...
8B E9                  ; mov ebp, ecx   ; host
...
8B 5C 24 3C            ; mov ebx, [esp+0x3c]  ; source
8B 7B 0C               ; mov edi, [ebx+0xc]   ; begin
```

Epilogue:

```
33 C0                  ; xor eax, eax
...
83 C4 28 C2 04 00      ; add esp,0x28; ret 4
```

Body length **222 B**. Full hex in raw W32-K append.

---

## 6. Gaps

- Product/PDB method English (family sealed via enqueue sibling + worker `assPreloader.cpp`).
- Nested `FUN_00744360` / `FUN_0043df90` product plates (W32-L / residual).
- Runtime / bit-exact / differential.

---

## 7. Verdict

Fidelity pass seals ABI, expand-then-enqueue CF, return 0. Nested dep-walk product English open → **accept-with-gaps**.
