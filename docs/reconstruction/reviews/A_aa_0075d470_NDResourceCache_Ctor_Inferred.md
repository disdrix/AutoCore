# Review A (reconstruction fidelity): `aa_0075d470` NDResourceCache_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0075d470` |
| **VA** | `0x0075d470`–`0x0075d506` inclusive (**151 B** / `0x97`) |
| **Canonical name** | `NDResourceCache_Ctor_Inferred` |
| **Ghidra name** | `FUN_0075d470` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W35-B) |
| **Counterpart** | `reviews/B_aa_0075d470_NDResourceCache_Ctor_Inferred.md` |
| **System** | NDResourceCache host (`DAT_00d1f050`); AssManager embed |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` (full body) + xrefs + outer `FUN_007543b0` decompile. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Placement constructor for the resource host published at **`DAT_00d1f050`**: NestedHash bag, critical section, std tree head, and AssPreloader ensure. Embedded at AssManager client **`outer+0x0c`** (`FUN_007543b0` / `DAT_00d1f058`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W35-B append) | `docs/reconstruction/raw/aa_0075d470_FUN_0075d470.md` |
| Annotated | `docs/reconstruction/raw/aa_0075d470_FUN_0075d470.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/NDResourceCache_Ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0075d470.cpp` |
| Function records | `functions/aa_0075d470_FUN_0075d470.md`, named twin |
| Nested duals | W34-E NestedHash 0x14; W16-G StdTree_AllocNode 0x1c; W33-O EnsureAssPreloader |
| Live | decompile ≡ raw CF; `C2 04 00`; full 151 B hex; single caller site |

---

## 3. Signature (sealed — bytes win)

```c
// stack(self*); RET 4; return self; SEH LAB_009acd33
NDResourceCache* __stdcall NDResourceCache_Ctor_Inferred(NDResourceCache* self);
```

| Formal | Source | Conf |
|---|---|---|
| self* | stack @ entry (`[esp+0x18]` after prolog → ESI) | **High** |
| RET 4 | `C2 04 00` | **High** |
| return self | `mov eax,esi` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
SEH prolog LAB_009acd33
DAT_00d1f050 = self
FUN_0043bdf0(self)                    // NestedHash @ +0
zero +0x2c, +0x30, +0x34, +0x38
InitializeCriticalSection(self+0x3c)
*(u8*)(self+0x54) = 1
head = FUN_005ae2b0()
self[+0x5c] = head
head[+0x19] = 1; head L/P/R = head
self[+0x60] = 0
self[+0x64] = 0; self[+0x68] = 0; self[+0x6c] = 0
FUN_0075d3c0(self)                    // EnsureAssPreloader
SEH epilog; mov eax,self; ret 4
```

| Stage | Match | Conf |
|---|---|---|
| Global publish DAT_00d1f050 | **Yes** | **High** |
| NestedHash / CS / tree / ensure order | **Yes** | **High** |
| Tree head self-link + isnil | **Yes** (StdTree head pattern) | **High** |
| Embed outer+0x0c | **Yes** (`FUN_007543b0`) | **High** |
| Host span ≥ 0x70 | **Yes** (last write +0x6c) | **High** |

---

## 5. Gaps

- Product/PDB English for host type plate (NDResourceCache vs AssManager subobject).
- Meaning of zeroed `+0x2c..+0x38` and fields `+0x64/+0x68`.
- Unwritten `+0x28..+0x2b` between NestedHash and aux zeros.
- Nested free of NestedHash/tree/preloader full product contracts (owned elsewhere).
- Runtime / bit-exact / differential.

---

## 6. Verdict

Fidelity pass seals placement ABI, global publish, member layout/order, tree head pattern, preloader ensure tail, and AssManager embed. Residual product English + aux fields → **accept-with-gaps**.
