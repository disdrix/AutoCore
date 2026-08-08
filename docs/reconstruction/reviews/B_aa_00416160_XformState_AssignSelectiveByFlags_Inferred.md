# Review B (skeptical / adversarial): `aa_00416160` XformState_AssignSelectiveByFlags_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00416160` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (WQ9I-G) |
| **Counterpart** | `reviews/A_aa_00416160_XformState_AssignSelectiveByFlags_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` + `disassemble_function` + callers/xrefs. **No** `disassemble_bytes`.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Decompiler `param_1[i]` indices wrong vs bytes | **Falsified** — dword index ×4 matches LEA bases `+0x80/+0x90/+0x9c/+0xa8/+0xb4/+0xb8/+0xbc` |
| 2 | Always full blind memcpy of whole object | **Falsified** — three skip gates; gen is dest++ not src copy |
| 3 | Flags tested from **dest** before write | **Falsified** — body loads **src** flags, stores to dest, then tests (same value) |
| 4 | Bit set means “copy this block” | **Falsified** — `test; jnz skip`; set → skip |
| 5 | thiscall wrong / stdcall both on stack | **Falsified** — `mov eax,ecx` at entry; `ret 4` for one stack arg |
| 6 | phySkeleton-private helper only | **Falsified** — 16 call sites across env/vehicle/UI/physics; adjustor +0x10 MI |
| 7 | Same object as `Class_00a9bbe8` dtor | **Falsified** — no vptr install; matrix overwrite @+0 would clobber vptr |
| 8 | Runtime Confirmed | **Not claimed** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX dest / stack src / ret 4 | **High** | Wrong call sites |
| Flag skip policy | **High** | Silent partial assigns |
| Offset map | **High** | Wrong port layout |
| Two 4×4 matrices | High (size) | English only |
| Product name | Low | Naming only |
| Runtime | Open | — |

---

## 3. Cross-check against raw + bytes

```
mov edx, [esp+4]       ; src
mov eax, ecx           ; dest
; copy 4 dwords @+0x80, 3 @+0x90, 3 @+0x9c
mov cl, [edx+0xb8]; mov [eax+0xb8], cl
mov ecx, [edx+0xbc]
test cl, 1
mov [eax+0xbc], ecx
jnz skip0
mov ecx, 0x10; mov esi, edx; mov edi, eax; rep movsd
; bit1 @+0x40 similarly; bit2 @+0xa8 three dwords
add dword ptr [eax+0xb4], 1
pop edi; pop esi
ret 4
```

`FUN_00416240`: `mov [esi+0xbc], 0; push src; call 00416160` → forces full matrix copy.

Do **not** port as unconditional memcpy. Do **not** skip generation bump. Do **not** treat as phySkeleton-only.

---

## 4. Surviving contract for AutoCore

```csharp
// void Assign(ref XformState dest, in XformState src)
// ECX=dest, stack=src*, ret 4
// always mid+byte+flags; skip matrix0/1/tail per src.flags bits 0/1/2; dest.gen++
```

Pair with full-assign wrapper `FUN_00416240` and MI adjustor `+0x10` when dualed.

---

## 5. Verdict

**accept-with-gaps** — adversarial checks confirm selective flag-gated transform assign. Residual: product English, runtime. Not reject.
