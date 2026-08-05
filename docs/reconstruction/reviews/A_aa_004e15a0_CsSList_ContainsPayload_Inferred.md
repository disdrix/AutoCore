# Review A (reconstruction fidelity): `aa_004e15a0` CsSList_ContainsPayload_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e15a0` |
| **VA** | `0x004e15a0` |
| **Body** | sealed **89** B (exclusive end `0x004e15f9`); Ghidra meta `004e15a0`–`004e15f8` |
| **Canonical name** | `CsSList_ContainsPayload_Inferred` |
| **Prior / alias** | `FUN_004e15a0`; auto-seed RemoveObject-chain name |
| **Review date** | `2026-07-29` (W20-P OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_004e15a0_CsSList_ContainsPayload_Inferred.md` |
| **System** | client containers / deferred-queue membership |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `get_function_by_address`, xrefs / complete analysis / assembly context (no `disassemble_bytes`) |
| **Verdict** | **accept** |

---

## 1. Purpose

Thread-safe **contains** on CS-protected singly-linked payload list: walk head, compare `node+4` to stack payload, follow `node+8`; return **1**/**0**. Twin of Append (`aa_004024d0`).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004e15a0_FUN_004e15a0.md` (+ W20-P append) |
| Annotated | `docs/reconstruction/raw/aa_004e15a0_FUN_004e15a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CsSList_ContainsPayload_Inferred.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_004e15a0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004e15a0_CsSList_ContainsPayload_Inferred.md` |
| Live decompile | ≡ raw (dual CS, walk, 0/1) |
| Live body bytes | `read_memory` @ `0x004e15a0` length 128 |
| Call sites | `get_assembly_context` @ `004d0ea8`, `004d4840` |
| Twin dual | `aa_004024d0` Append (same offsets) |

---

## 3. Byte seal (`read_memory` @ `0x004e15a0`)

```
53                push ebx
55                push ebp
8b 2d bc 61 9c 00 mov ebp, [EnterCS IAT]
56                push esi
57                push edi
8b f1             mov esi, ecx          ; list
8d 7e 28          lea edi, [esi+0x28]   ; outer CS
57                push edi
ff d5             call EnterCriticalSection
8d 5e 10          lea ebx, [esi+0x10]   ; inner CS
53                push ebx
ff d5             call EnterCriticalSection
8b 46 04          mov eax, [esi+4]      ; head
…
39 48 04          cmp [eax+4], ecx      ; payload == ?
…
8b 40 08          mov eax, [eax+8]      ; next
…
32 c0 / b0 01     AL = 0 / 1
c2 04 00          ret 4
```

| Claim | Evidence | Conf |
|---|---|---|
| ECX = list | `mov esi,ecx` + `[esi+…]` | **High** |
| Stack payload | load from stack after prolog; call sites `push esi` obj | **High** |
| CS +0x28 then +0x10 | `8d 7e 28` / `8d 5e 10` | **High** |
| Always both CS | no count test before outer enter | **High** |
| head+4 / payload+4 / next+8 | matching opcodes | **High** |
| ret 4 + AL bool | both exits | **High** |
| Decompile ≡ raw ≡ bytes intent | three-rep match | **High** |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Enter outer then inner CS | **Yes** |
| Null head → leave both → 0 | **Yes** |
| Walk compare payload | **Yes** |
| Hit → leave both → 1 | **Yes** |
| No invent free/append/count++ | **Yes** |
| thiscall + ret 4 | **Yes** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF algorithm | **High** | sealed three-rep |
| Layout twin of Append | **High** | same field map |
| Always-outer-CS vs Append gate | **High** | intentional difference |
| Product class name | **Inferred** | `_Inferred` residual |
| Runtime / bit-exact | **Open** | not run |

---

## 6. Gaps

1. Product/PDB symbol.  
2. Rationale for always-outer CS on Contains.  
3. Runtime / differential — open.

**Verdict: accept** — membership helper sealed for port as list contains, not host API.
