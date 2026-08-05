# Review A (reconstruction fidelity): `aa_004e24d0` Mem_MoveDwordRange_ToExclusiveEnd

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e24d0` |
| **VA** | `0x004e24d0` |
| **Body** | `0x004e24d0`–`0x004e24f3` exclusive (**35** B) |
| **Canonical name** | `Mem_MoveDwordRange_ToExclusiveEnd` |
| **Prior / alias** | `FUN_004e24d0`; misleading auto-seed `Named_CalleeOf_…_CVOGSectorMap_AddCharacter_004e24d0` |
| **Review date** | `2026-07-29` (W20-H OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_004e24d0_Mem_MoveDwordRange_ToExclusiveEnd.md` |
| **System** | stl-helpers / vector relocate |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `get_function_by_address`, xrefs / complete analysis (no `disassemble_bytes`) |
| **Verdict** | **accept** |

---

## 1. Purpose

**Dword-range memmove ending at exclusive pointer:**

```c
count = (srcEnd - srcBegin) >> 2;
memmove(destEndExcl - count*4, srcBegin, count*4);
```

Generic POD tail relocate for vector insert in-place growth (open hole at insert point by shifting `[first,last)` right so it ends at new exclusive end).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004e24d0_FUN_004e24d0.md` (+ W20-H append) |
| Annotated | `docs/reconstruction/raw/aa_004e24d0_FUN_004e24d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Mem_MoveDwordRange_ToExclusiveEnd.cpp` |
| Scaffold | `reconstructed-exact/FUN_004e24d0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004e24d0_Mem_MoveDwordRange_ToExclusiveEnd.md` |
| Live decompile | ≡ raw |
| Live body bytes | `read_memory` @ `0x004e24d0` length 64 |
| Sibling dual | `aa_004e2e80` Mem_MoveDwordRange_ReturnEnd (forward dest, ret end, stdcall) |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte seal (`read_memory` @ `0x004e24d0`)

```
8b 4c 24 04       mov ecx, [esp+4]      ; srcBegin
8b 44 24 08       mov eax, [esp+8]      ; srcEnd
2b c1             sub eax, ecx
c1 f8 02          sar eax, 2            ; count dwords
03 c0 03 c0       size = count * 4
50 51             push size, src
8b 4c 24 14       mov ecx, [esp+14h]    ; exclusiveEnd
2b c8             sub ecx, eax          ; dest = end - size
51                push dest
ff 15 2c 65 9c 00 call [memmove IAT]
83 c4 0c          add esp, 0Ch
c3                ret                   ; bare
```

Hex (35 B):

```
8b4c24048b4424082bc1c1f80203c003c050518b4c24142bc851ff152c659c0083c40cc3
```

| Claim | Evidence | Conf |
|---|---|---|
| Body **35** B through bare `ret` | meta end `004e24f3` + `c3` + `cc` pad | **High** |
| cdecl (not stdcall) | final `c3` not `c2 0c 00` | **High** |
| Size `((end-begin)>>2)*4` | `sar 2` + double add | **High** |
| dest = exclusiveEnd − size | `sub ecx, eax` before push | **High** |
| Sole callee memmove | IAT `0x009c652c` | **High** |
| Decompile ≡ raw ≡ bytes | three-rep | **High** |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Count/size math | **Yes** |
| dest = end − size | **Yes** |
| memmove only | **Yes** |
| void bare ret | **Yes** |
| Not confused with 004e2e80 forward-return-end | **Yes** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF algorithm | **High** | sealed three-rep |
| cdecl ABI | **High** | bare `c3` |
| Vector relocate role | **High** | 25 insert/grow callers |
| Product English spelling | **Low–Med** | structural name |
| EAX return unused | **High** | void contract |

---

## 6. Gaps

1. Product/PDB symbol.
2. Exhaustive caller role census (not required for seal).
3. Runtime / bit-exact / differential — open.

**Verdict:** **accept** — ABI, size math, exclusive-end dest, memmove sealed; product name residual only.
