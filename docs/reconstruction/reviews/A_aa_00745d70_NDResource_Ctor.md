# Review A (reconstruction fidelity): `aa_00745d70` NDResource_Ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00745d70` |
| **VA** | `0x00745d70`–`0x00745dec` |
| **Canonical name (Ghidra)** | `FUN_00745d70` |
| **Proposed name** | `NDResource_Ctor` (**High** role; product spelling Probable) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra W19-R) |
| **Reviewer role** | Reconstruction fidelity (in-place resource ctor) |
| **Counterpart** | `reviews/B_aa_00745d70_NDResource_Ctor.md` |
| **System** | ndresource / ND resource object base |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**In-place construct a 0x3c-byte NDResource-family object:** base vtbl, name key, type token, critical section, ready flag; optional payload from `src->vtbl+4()`.

### Primary use

`NDResourceCache_LookupOrCreate` default miss path: `operator_new(0x3c)` → this ctor → patch vtbl to `PTR_FUN_00a9e850`. Also other factory helpers (`FUN_0043b910`, etc.).

**Not** a heap allocator itself; **not** the dtor (`FUN_00745ff0`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00745d70_FUN_00745d70.md` (+ v2026-07-29 append) |
| Annotated | `docs/reconstruction/raw/aa_00745d70_FUN_00745d70.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NDResource_Ctor.cpp` |
| Function record | `docs/reconstruction/functions/aa_00745d70_NDResource_Ctor.md` |
| Live Ghidra | `decompile_function` `0x00745d70`; `analyze_function_complete`; `read_memory` body; call-sites `0x0075de10`, `0x0043b940` |
| Related | `NDResourceCache_LookupOrCreate` dual; dtor `FUN_00745ff0` decompile |

**Not performed:** Launcher, runtime, bit-exact, parent ledger edits, `disassemble_bytes`.

---

## 3. Signature

```c
// EDX = typeToken; stack this, nameKey*, optionalSrc*; RET 0xC; returns this
void * __fastcall NDResource_Ctor(
    void *ecx_unused,
    uint32_t typeToken,
    void *self,
    uint32_t *nameKey,
    void *optionalSrc);
```

| Item | Evidence |
|---|---|
| Stack arity 3 | `RET 0xC` @ body end |
| EDX type token | `mov [esi+0xc], edx` in bytes; call-sites `mov edx, type` before CALL |
| this on stack | `mov esi, [esp+…]` then all stores via ESI; LookupOrCreate `push esi` (new obj) |
| nameKey* | `mov eax, nameKey; mov ecx, [eax]; mov [esi+4], ecx` |
| optionalSrc | EBP from stack arg3; null check; `call [vtbl+4]` |
| return this | `mov eax, esi` |

**Decompiler trap:** signature lists unused `param_1`; `__fastcall` display is partial — sealed ABI is EDX + 3 stack + RET 0xC.

---

## 4. Control flow: clean ≡ raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| SEH + install `PTR_FUN_00aa1d40` | **Yes** |
| Field inits + CS @ `+0x20` + flag `@+0x38=1` | **Yes** |
| optionalSrc null skip | **Yes** |
| optionalSrc `vtbl+4` → `+0x14` | **Yes** |
| return this / `RET 0xC` | **Yes** |

**Body hex (125 B):**  
`6aff64a10000000068f8b79a00508b4424146489250000000053558b6c2420568b74241c57c706401daa008b08894e0433db8d7e2057895e0889560c895e10895e14c74618ffffffffff15ec619c00c64718013beb895c2418740b8b45008bcdff50048946148b4c24105f8bc65e5d64890d000000005b83c40cc20c00`

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| In-place ctor of 0x3c resource | **High** | callers + layout |
| ABI EDX + RET 0xC | **High** | bytes + sites |
| CS + ready flag | **High** | InitCS + `C6 … 01` |
| Base vtbl `00aa1d40` | **High** | body store |
| Default patch `00a9e850` | **High** | caller after return |
| Class name NDResource | **Probable** | family naming |
| optionalSrc `vtbl+4` English | **Tentative** | |

---

## 6. Gaps / open

1. Exact product C++ class / base vs derived vtbl names.
2. Semantics of optional `vtbl+4` (clone vs wrap).
3. Runtime / bit-exact not run.

**Verdict:** **accept-with-gaps** — CF/ABI/layout High; product spelling + optionalSrc semantics open.
